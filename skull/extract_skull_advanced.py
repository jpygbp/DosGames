#!/usr/bin/env python3
"""
Advanced SKULL.T String Extractor
Reverse engineers the file format based on game code analysis
"""

import struct
import sys

def decrypt_xor_ff(data):
    """Decrypt using XOR 0xFF (from game code: *decrypt_ptr ^ BIT_MASK_LOW_8)"""
    return bytes([b ^ 0xFF for b in data])

def find_string_table(data):
    """
    Find the string table in the file.
    Based on game code: string table contains [ID (4 bytes), Offset (2 bytes)] entries
    """
    # The string table likely starts after a header
    # Try different starting positions
    possible_starts = []
    
    for start in range(0, min(200, len(data) - 6), 2):
        # Check if this looks like a valid table entry
        if start + 6 <= len(data):
            # Read potential ID (4 bytes) and offset (2 bytes)
            entry_id = struct.unpack('<I', data[start:start+4])[0]
            offset = struct.unpack('<H', data[start+4:start+6])[0]
            
            # Validate: ID should be reasonable (0-10000), offset should be within file
            if 0 <= entry_id < 10000 and 0 < offset < len(data):
                possible_starts.append(start)
    
    # Return the most likely start (earliest valid position)
    return possible_starts[0] if possible_starts else 0

def extract_string_table(data, start=0, max_entries=500):
    """
    Extract the string table: array of [ID, Offset] pairs
    Each entry is 6 bytes: 4-byte ID (little-endian) + 2-byte offset (little-endian)
    """
    table = []
    pos = start
    
    for i in range(max_entries):
        if pos + 6 > len(data):
            break
        
        entry_id = struct.unpack('<I', data[pos:pos+4])[0]
        offset = struct.unpack('<H', data[pos+4:pos+6])[0]
        
        # Stop if we hit invalid data (likely end of table)
        if entry_id == 0xFFFFFFFF or offset == 0xFFFF or offset >= len(data):
            break
        
        if entry_id < 10000 and offset > 0:  # Sanity check
            table.append({'id': entry_id, 'offset': offset})
        
        pos += 6
    
    return table

def extract_string_at_offset(data, offset):
    """
    Extract and decrypt a string at the given offset.
    Format: [length (2 bytes)][encrypted_data (length-1 bytes)][null terminator]
    """
    if offset + 2 > len(data):
        return None
    
    # Read length (2 bytes, little-endian)
    length = struct.unpack('<H', data[offset:offset+2])[0]
    
    if length == 0 or length > 1000 or offset + 2 + length > len(data):
        return None
    
    # Read encrypted string data
    encrypted = data[offset+2:offset+2+length-1]  # -1 for null terminator
    
    # Decrypt using XOR 0xFF
    decrypted = decrypt_xor_ff(encrypted)
    
    try:
        # Try to decode as ASCII
        text = decrypted.decode('ascii', errors='ignore')
        # Filter out garbage
        if len(text.strip()) > 0 and is_valid_text(text):
            return text.strip()
    except:
        pass
    
    return None

def is_valid_text(text):
    """Check if text looks like valid game content"""
    if not text or len(text) < 3:
        return False
    
    # Count printable characters
    printable = sum(1 for c in text if 32 <= ord(c) <= 126 or c in '\n\r\t')
    
    # Must be mostly printable
    if printable < len(text) * 0.7:
        return False
    
    # Should have some alphabetic characters
    alpha = sum(1 for c in text if c.isalpha())
    if alpha < len(text) * 0.3:
        return False
    
    return True

def brute_force_extract(data):
    """
    Brute force approach: scan entire file for length-prefixed strings
    """
    strings = []
    
    for offset in range(len(data) - 3):
        # Try to read length
        length = struct.unpack('<H', data[offset:offset+2])[0]
        
        # Check if this looks like a valid length-prefixed string
        if 10 <= length <= 500 and offset + 2 + length <= len(data):
            encrypted = data[offset+2:offset+2+length-1]
            decrypted = decrypt_xor_ff(encrypted)
            
            try:
                text = decrypted.decode('ascii', errors='ignore')
                if is_valid_text(text):
                    strings.append({
                        'offset': offset,
                        'length': length,
                        'text': text.strip()
                    })
            except:
                pass
    
    return strings

def main():
    filename = 'SKULL.T'
    output_file = 'STORY_OPTION3_DIRECT_EXTRACT.txt'
    
    print(f"\n{'='*70}")
    print("OPTION 3: DIRECT SKULL.T STRING EXTRACTION")
    print('='*70)
    
    # Read file
    print(f"\nReading {filename}...")
    with open(filename, 'rb') as f:
        data = f.read()
    
    print(f"File size: {len(data)} bytes")
    
    # Method 1: Try to find and parse string table
    print("\n[Method 1] Searching for string table...")
    table_start = find_string_table(data)
    print(f"  Potential table start: offset 0x{table_start:04X}")
    
    string_table = extract_string_table(data, table_start)
    print(f"  Found {len(string_table)} table entries")
    
    # Extract strings using table
    table_strings = []
    if string_table:
        print("\n[Method 1] Extracting strings using table...")
        for entry in string_table:
            text = extract_string_at_offset(data, entry['offset'])
            if text:
                table_strings.append({
                    'id': entry['id'],
                    'offset': entry['offset'],
                    'text': text
                })
        print(f"  Extracted {len(table_strings)} strings from table")
    
    # Method 2: Brute force scan
    print("\n[Method 2] Brute force scanning entire file...")
    brute_strings = brute_force_extract(data)
    print(f"  Found {len(brute_strings)} strings via brute force")
    
    # Combine and deduplicate
    all_strings = {}
    
    # Add table strings (preferred)
    for s in table_strings:
        all_strings[s['text']] = s
    
    # Add brute force strings (if not already present)
    for s in brute_strings:
        if s['text'] not in all_strings:
            all_strings[s['text']] = {
                'id': 'UNKNOWN',
                'offset': s['offset'],
                'text': s['text']
            }
    
    print(f"\n[TOTAL] {len(all_strings)} unique strings found")
    
    # Write output
    print(f"\nWriting to {output_file}...")
    with open(output_file, 'w', encoding='utf-8') as out:
        out.write("=" * 80 + "\n")
        out.write("SKULLDUGGERY - STORY EXTRACTION OPTION 3: DIRECT FILE PARSING\n")
        out.write("=" * 80 + "\n\n")
        out.write(f"SOURCE: {filename} (direct binary extraction)\n")
        out.write(f"DATE: 2026-01-18\n")
        out.write(f"METHOD: Reverse engineered file format + brute force scanning\n")
        out.write(f"TOTAL STRINGS: {len(all_strings)}\n\n")
        out.write("=" * 80 + "\n")
        out.write("EXTRACTED STRINGS\n")
        out.write("=" * 80 + "\n\n")
        
        # Sort by offset for readability
        sorted_strings = sorted(all_strings.values(), key=lambda x: x['offset'])
        
        for i, s in enumerate(sorted_strings, 1):
            out.write(f"[{i}] STRING ID: {s['id']}\n")
            out.write(f"    Offset: 0x{s['offset']:04X}\n")
            out.write(f"    Text:\n")
            out.write(f"    {s['text']}\n")
            out.write("-" * 80 + "\n\n")
    
    print(f"[SUCCESS] Output written to {output_file}")
    
    # Show preview
    if all_strings:
        print(f"\nPreview of first 5 strings:")
        print("=" * 70)
        for s in list(sorted_strings)[:5]:
            preview = s['text'][:100]
            if len(s['text']) > 100:
                preview += "..."
            print(f"  [{s['id']}] {preview}")
        print()

if __name__ == "__main__":
    main()
