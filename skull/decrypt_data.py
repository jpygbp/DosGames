#!/usr/bin/env python3
"""
Skull Game Data File Decryptor
Decrypts SKULL.M, SKULL.X, SKULL.T, and other game data files
Uses XOR 0xFF encryption (bit inversion)
"""

import sys
import os

def decrypt_byte(byte):
    """Decrypt a single byte using XOR 0xFF"""
    return byte ^ 0xFF

def decrypt_file(input_file, output_file):
    """Decrypt an entire file"""
    try:
        with open(input_file, 'rb') as f_in:
            encrypted_data = f_in.read()
        
        # Decrypt each byte
        decrypted_data = bytes([decrypt_byte(b) for b in encrypted_data])
        
        with open(output_file, 'wb') as f_out:
            f_out.write(decrypted_data)
        
        print(f"[OK] Decrypted {input_file} -> {output_file}")
        print(f"  Size: {len(encrypted_data)} bytes")
        return True
    except Exception as e:
        print(f"[ERROR] Error decrypting {input_file}: {e}")
        return False

def decrypt_string(encrypted_bytes):
    """Decrypt a byte array to string"""
    decrypted = bytes([decrypt_byte(b) for b in encrypted_bytes])
    try:
        # Try ASCII first
        return decrypted.decode('ascii', errors='replace')
    except:
        # Fall back to hex representation
        return decrypted.hex()

def is_printable_text(text):
    """Check if text contains mostly printable characters"""
    if not text:
        return False
    printable_count = sum(1 for c in text if 32 <= ord(c) < 127 or c in '\t\r\n')
    return printable_count / len(text) > 0.8

def analyze_file(filename):
    """Analyze and display file structure"""
    try:
        with open(filename, 'rb') as f:
            data = f.read()
    except Exception as e:
        print(f"✗ Error reading {filename}: {e}")
        return
    
    print(f"\n{'='*60}")
    print(f"Analyzing: {filename}")
    print(f"{'='*60}")
    print(f"File size: {len(data)} bytes")
    
    # Try to extract strings
    pos = 0
    string_count = 0
    valid_strings = []
    
    while pos < len(data) - 2:
        # Read length prefix (2 bytes, little-endian)
        length = data[pos] | (data[pos + 1] << 8)
        
        # Check if this looks like a valid length
        if 0 < length < 1000 and pos + 2 + length <= len(data):
            # Extract and decrypt string
            encrypted_string = data[pos + 2:pos + 2 + length - 1]  # -1 to skip null terminator
            decrypted_string = decrypt_string(encrypted_string)
            
            # Check if it looks like valid text
            if is_printable_text(decrypted_string):
                valid_strings.append({
                    'offset': pos,
                    'length': length,
                    'content': decrypted_string
                })
                string_count += 1
            
            pos += 2 + length
        else:
            pos += 1
    
    print(f"\nFound {string_count} potential strings\n")
    
    # Display first 20 strings
    for i, s in enumerate(valid_strings[:20]):
        print(f"String {i} at offset 0x{s['offset']:04X} (length {s['length']}):")
        content = s['content'][:100]
        if len(s['content']) > 100:
            content += "..."
        print(f"  {repr(content)}")
        print()
    
    if len(valid_strings) > 20:
        print(f"... and {len(valid_strings) - 20} more strings")
    
    return valid_strings

def extract_all_strings(filename, output_file):
    """Extract all strings to a text file"""
    try:
        with open(filename, 'rb') as f:
            data = f.read()
    except Exception as e:
        print(f"✗ Error reading {filename}: {e}")
        return
    
    print(f"\nExtracting strings from {filename}...")
    
    pos = 0
    string_count = 0
    
    with open(output_file, 'w', encoding='utf-8') as out:
        out.write(f"Strings extracted from {filename}\n")
        out.write(f"{'='*60}\n\n")
        
        while pos < len(data) - 2:
            length = data[pos] | (data[pos + 1] << 8)
            
            if 0 < length < 1000 and pos + 2 + length <= len(data):
                encrypted_string = data[pos + 2:pos + 2 + length - 1]
                decrypted_string = decrypt_string(encrypted_string)
                
                if is_printable_text(decrypted_string):
                    out.write(f"[{string_count}] Offset 0x{pos:04X}, Length {length}\n")
                    out.write(f"{decrypted_string}\n")
                    out.write(f"{'-'*60}\n\n")
                    string_count += 1
                
                pos += 2 + length
            else:
                pos += 1
    
    print(f"[OK] Extracted {string_count} strings to {output_file}")

def decrypt_all_game_files():
    """Decrypt all standard game data files"""
    files = ['SKULL.M', 'SKULL.X', 'SKULL.T', 'SKULL.V', 'SKULL.MM', 'SKULL.MO']
    
    print("\nDecrypting all game data files...")
    print(f"{'='*60}\n")
    
    success_count = 0
    for filename in files:
        if os.path.exists(filename):
            output = filename + '.decrypted'
            if decrypt_file(filename, output):
                success_count += 1
        else:
            print(f"⊗ File not found: {filename}")
    
    print(f"\n{'='*60}")
    print(f"[DONE] Decrypted {success_count}/{len(files)} files")
    print(f"{'='*60}\n")

def show_usage():
    """Display usage information"""
    print("""
Skull Game Data File Decryptor
================================

Usage:
  python decrypt_data.py <command> [arguments]

Commands:
  decrypt <input> [output]    Decrypt a single file
  analyze <file>              Analyze file structure and show strings
  extract <input> <output>    Extract all strings to text file
  all                         Decrypt all standard game files

Examples:
  python decrypt_data.py decrypt SKULL.M SKULL.M.txt
  python decrypt_data.py analyze SKULL.M
  python decrypt_data.py extract SKULL.M strings.txt
  python decrypt_data.py all

Notes:
  - Encryption uses XOR 0xFF (bit inversion)
  - Same operation encrypts and decrypts
  - Files contain length-prefixed strings
  - Standard files: SKULL.M, SKULL.X, SKULL.T, SKULL.V, SKULL.MM, SKULL.MO
""")

def main():
    """Main entry point"""
    if len(sys.argv) < 2:
        show_usage()
        sys.exit(1)
    
    command = sys.argv[1].lower()
    
    if command == 'decrypt':
        if len(sys.argv) < 3:
            print("Error: decrypt requires input file")
            show_usage()
            sys.exit(1)
        
        input_file = sys.argv[2]
        output_file = sys.argv[3] if len(sys.argv) > 3 else input_file + '.decrypted'
        decrypt_file(input_file, output_file)
    
    elif command == 'analyze':
        if len(sys.argv) < 3:
            print("Error: analyze requires input file")
            show_usage()
            sys.exit(1)
        
        analyze_file(sys.argv[2])
    
    elif command == 'extract':
        if len(sys.argv) < 4:
            print("Error: extract requires input and output files")
            show_usage()
            sys.exit(1)
        
        extract_all_strings(sys.argv[2], sys.argv[3])
    
    elif command == 'all':
        decrypt_all_game_files()
    
    elif command in ['help', '-h', '--help', '/?']:
        show_usage()
    
    else:
        print(f"Error: Unknown command '{command}'")
        show_usage()
        sys.exit(1)

if __name__ == "__main__":
    main()
