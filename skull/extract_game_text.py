#!/usr/bin/env python3
"""
Extract game text from SKULL data files
Uses multiple extraction methods to find all readable text
"""

import sys
import os
import re

def decrypt_xor(data):
    """Decrypt data using XOR 0xFF"""
    return bytes([b ^ 0xFF for b in data])

def extract_null_terminated_strings(data, min_length=10):
    """Extract null-terminated strings"""
    strings = []
    pos = 0
    
    while pos < len(data):
        # Find start of potential string
        if data[pos] == 0:
            pos += 1
            continue
        
        # Extract until null byte or non-printable
        end_pos = pos
        while end_pos < len(data) and data[end_pos] != 0:
            if not (9 <= data[end_pos] <= 13 or 32 <= data[end_pos] <= 126):
                break
            end_pos += 1
        
        # Check if we found a string
        if end_pos - pos >= min_length:
            try:
                text = data[pos:end_pos].decode('ascii', errors='ignore')
                # Filter out garbage
                if len(text.strip()) >= min_length and is_likely_text(text):
                    strings.append({
                        'offset': pos,
                        'text': text.strip()
                    })
            except:
                pass
        
        pos = end_pos + 1
    
    return strings

def extract_pascal_strings(data, min_length=10):
    """Extract Pascal-style length-prefixed strings"""
    strings = []
    pos = 0
    
    while pos < len(data) - 2:
        # Try single-byte length
        length = data[pos]
        if 10 <= length <= 255 and pos + 1 + length <= len(data):
            try:
                text = data[pos+1:pos+1+length].decode('ascii', errors='ignore')
                if len(text) >= min_length and is_likely_text(text):
                    strings.append({
                        'offset': pos,
                        'length': length,
                        'text': text.strip()
                    })
                    pos += 1 + length
                    continue
            except:
                pass
        
        # Try 16-bit little-endian length (DOS format)
        if pos < len(data) - 3:
            length = data[pos] | (data[pos+1] << 8)
            if 10 <= length <= 500 and pos + 2 + length <= len(data):
                try:
                    text = data[pos+2:pos+2+length].decode('ascii', errors='ignore')
                    if len(text) >= min_length and is_likely_text(text):
                        strings.append({
                            'offset': pos,
                            'length': length,
                            'text': text.strip()
                        })
                        pos += 2 + length
                        continue
                except:
                    pass
        
        pos += 1
    
    return strings

def extract_continuous_ascii(data, min_length=15):
    """Extract continuous ASCII sequences"""
    strings = []
    start = None
    
    for i, byte in enumerate(data):
        if 32 <= byte <= 126 or byte in (9, 10, 13):  # Printable or whitespace
            if start is None:
                start = i
        else:
            if start is not None and i - start >= min_length:
                try:
                    text = data[start:i].decode('ascii', errors='ignore')
                    if is_likely_text(text):
                        strings.append({
                            'offset': start,
                            'text': text.strip()
                        })
                except:
                    pass
            start = None
    
    return strings

def is_likely_text(text):
    """Check if text looks like actual game content"""
    if not text or len(text) < 10:
        return False
    
    # Count letters and spaces
    letter_count = sum(1 for c in text if c.isalpha())
    space_count = text.count(' ')
    
    # Must have decent letter content
    if letter_count < len(text) * 0.5:
        return False
    
    # Should have some spaces (words)
    if space_count == 0 and len(text) > 20:
        return False
    
    # Check for common game words
    game_words = ['you', 'the', 'door', 'room', 'tunnel', 'forest', 'mansion',
                  'lamp', 'treasure', 'ghost', 'skull', 'passage', 'dark',
                  'enter', 'exit', 'north', 'south', 'east', 'west']
    
    text_lower = text.lower()
    has_game_word = any(word in text_lower for word in game_words)
    
    # Reject if too many non-alpha characters
    non_alpha = sum(1 for c in text if not c.isalnum() and c not in ' .,!?-\'"')
    if non_alpha > len(text) * 0.3:
        return False
    
    return True

def extract_all_from_file(filename, output_file):
    """Extract all text using multiple methods"""
    print(f"\nProcessing: {filename}")
    print("=" * 70)
    
    # Read and decrypt
    with open(filename, 'rb') as f:
        encrypted = f.read()
    
    decrypted = decrypt_xor(encrypted)
    
    print(f"File size: {len(decrypted)} bytes")
    
    # Try all extraction methods
    print("\n[1] Extracting null-terminated strings...")
    null_strings = extract_null_terminated_strings(decrypted, min_length=10)
    print(f"    Found {len(null_strings)} strings")
    
    print("[2] Extracting length-prefixed strings...")
    pascal_strings = extract_pascal_strings(decrypted, min_length=10)
    print(f"    Found {len(pascal_strings)} strings")
    
    print("[3] Extracting continuous ASCII...")
    ascii_strings = extract_continuous_ascii(decrypted, min_length=15)
    print(f"    Found {len(ascii_strings)} strings")
    
    # Combine and deduplicate
    all_strings = []
    seen = set()
    
    for s in null_strings + pascal_strings + ascii_strings:
        text = s['text']
        if text and text not in seen and len(text.strip()) > 0:
            seen.add(text)
            all_strings.append(s)
    
    # Sort by offset
    all_strings.sort(key=lambda x: x['offset'])
    
    print(f"\n[TOTAL] {len(all_strings)} unique strings found\n")
    
    # Write to output
    with open(output_file, 'w', encoding='utf-8') as out:
        out.write(f"Game Text Extracted from {filename}\n")
        out.write("=" * 70 + "\n\n")
        out.write(f"Total strings found: {len(all_strings)}\n")
        out.write("=" * 70 + "\n\n")
        
        for i, s in enumerate(all_strings, 1):
            out.write(f"[{i}] Offset: 0x{s['offset']:04X}\n")
            out.write(f"{s['text']}\n")
            out.write("-" * 70 + "\n\n")
    
    print(f"[OK] Output written to: {output_file}\n")
    return all_strings

def main():
    """Main entry point"""
    if len(sys.argv) < 2:
        print("""
Usage: python extract_game_text.py <file> [output]

Examples:
  python extract_game_text.py SKULL.T skull_text.txt
  python extract_game_text.py SKULL.M skull_map.txt
  python extract_game_text.py SKULL.V skull_vocab.txt
""")
        sys.exit(1)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2] if len(sys.argv) > 2 else input_file + '_extracted.txt'
    
    if not os.path.exists(input_file):
        print(f"Error: File not found: {input_file}")
        sys.exit(1)
    
    strings = extract_all_from_file(input_file, output_file)
    
    # Show preview of first few strings
    if strings:
        print("\nPreview of extracted text:")
        print("=" * 70)
        for s in strings[:10]:
            text = s['text'][:100]
            if len(s['text']) > 100:
                text += "..."
            print(f"  {text}")
        if len(strings) > 10:
            print(f"  ... and {len(strings) - 10} more")
        print()

if __name__ == "__main__":
    main()
