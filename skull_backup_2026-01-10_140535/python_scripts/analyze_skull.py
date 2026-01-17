#!/usr/bin/env python3
"""
Analyze SKULL.EXE - DOS executable decompilation attempt
"""

import struct
import sys
import re
from pathlib import Path

def read_binary_file(filename):
    """Read binary file"""
    with open(filename, 'rb') as f:
        return f.read()

def analyze_dos_header(data):
    """Analyze DOS MZ header"""
    if len(data) < 64:
        return None
    
    # Check for DOS MZ signature
    if data[0:2] != b'MZ':
        return None
    
    # Parse DOS header
    e_magic = struct.unpack('<H', data[0:2])[0]
    e_cblp = struct.unpack('<H', data[2:4])[0]
    e_cp = struct.unpack('<H', data[4:6])[0]
    e_crlc = struct.unpack('<H', data[6:8])[0]
    e_cparhdr = struct.unpack('<H', data[8:10])[0]
    e_minalloc = struct.unpack('<H', data[10:12])[0]
    e_maxalloc = struct.unpack('<H', data[12:14])[0]
    e_ss = struct.unpack('<H', data[14:16])[0]
    e_sp = struct.unpack('<H', data[16:18])[0]
    e_csum = struct.unpack('<H', data[18:20])[0]
    e_ip = struct.unpack('<H', data[20:22])[0]
    e_cs = struct.unpack('<H', data[22:24])[0]
    e_lfarlc = struct.unpack('<H', data[24:26])[0]
    e_ovno = struct.unpack('<H', data[26:28])[0]
    
    # PE header offset (if it's a PE file)
    e_lfanew = struct.unpack('<I', data[60:64])[0] if len(data) >= 64 else 0
    
    return {
        'type': 'DOS MZ Executable',
        'magic': hex(e_magic),
        'initial_cs': hex(e_cs),
        'initial_ip': hex(e_ip),
        'initial_ss': hex(e_ss),
        'initial_sp': hex(e_sp),
        'pe_offset': e_lfanew if e_lfanew < len(data) else None,
        'size': len(data)
    }

def extract_strings(data, min_length=4):
    """Extract ASCII strings from binary"""
    strings = []
    current_string = b''
    
    for byte in data:
        if 32 <= byte <= 126:  # Printable ASCII
            current_string += bytes([byte])
        else:
            if len(current_string) >= min_length:
                try:
                    strings.append(current_string.decode('ascii', errors='ignore'))
                except:
                    pass
            current_string = b''
    
    # Don't forget the last string
    if len(current_string) >= min_length:
        try:
            strings.append(current_string.decode('ascii', errors='ignore'))
        except:
            pass
    
    return strings

def find_code_patterns(data):
    """Try to identify code patterns"""
    patterns = {
        'function_prologue': [],  # push bp; mov bp, sp
        'int_21h': [],  # DOS interrupts
        'call_patterns': [],
        'jump_patterns': []
    }
    
    # Look for common x86 patterns
    for i in range(len(data) - 10):
        # Function prologue: 55 8B EC (push bp; mov bp, sp)
        if data[i:i+3] == b'\x55\x8B\xEC':
            patterns['function_prologue'].append(i)
        
        # INT 21h (CD 21) - DOS interrupt
        if data[i:i+2] == b'\xCD\x21':
            patterns['int_21h'].append(i)
        
        # CALL near (E8)
        if data[i] == 0xE8 and i + 4 < len(data):
            offset = struct.unpack('<i', data[i+1:i+5])[0]
            patterns['call_patterns'].append((i, offset))
        
        # JMP short (EB)
        if data[i] == 0xEB and i + 1 < len(data):
            offset = data[i+1]
            patterns['jump_patterns'].append((i, offset))
    
    return patterns

def analyze_sections(data, dos_header):
    """Try to identify code and data sections"""
    sections = []
    
    # For DOS executables, code typically starts after the header
    header_size = dos_header.get('pe_offset', 512) if dos_header else 512
    
    if header_size and header_size < len(data):
        # Check if it's a PE file
        if header_size < len(data) - 4:
            pe_sig = data[header_size:header_size+2]
            if pe_sig == b'PE':
                sections.append({
                    'name': 'PE Header',
                    'offset': header_size,
                    'type': 'header'
                })
    
    # Try to find code sections (look for common instruction patterns)
    code_start = 512  # Typical DOS executable code start
    if code_start < len(data):
        sections.append({
            'name': 'Code Section',
            'offset': code_start,
            'type': 'code',
            'size': min(0x10000, len(data) - code_start)
        })
    
    return sections

def main():
    exe_file = 'SKULL.EXE'
    
    if not Path(exe_file).exists():
        print(f"Error: {exe_file} not found")
        return
    
    print(f"Analyzing {exe_file}...")
    print("=" * 80)
    
    # Read binary
    data = read_binary_file(exe_file)
    print(f"File size: {len(data)} bytes ({len(data)/1024:.2f} KB)")
    print()
    
    # Analyze DOS header
    print("DOS Header Analysis:")
    print("-" * 80)
    dos_header = analyze_dos_header(data)
    if dos_header:
        for key, value in dos_header.items():
            print(f"  {key}: {value}")
    else:
        print("  Not a DOS MZ executable")
    print()
    
    # Extract strings
    print("Extracting strings (min length 4)...")
    print("-" * 80)
    strings = extract_strings(data, min_length=4)
    
    # Filter and display interesting strings
    interesting_strings = []
    for s in strings:
        # Filter out pure numbers and very common patterns
        if len(s) > 6 and not s.isdigit() and not all(c in '0123456789ABCDEFabcdef' for c in s[:10]):
            interesting_strings.append(s)
    
    print(f"Found {len(interesting_strings)} interesting strings")
    print("\nSample strings:")
    for i, s in enumerate(interesting_strings[:50]):  # Show first 50
        print(f"  {i+1:3d}: {repr(s)}")
    
    if len(interesting_strings) > 50:
        print(f"  ... and {len(interesting_strings) - 50} more")
    
    # Save all strings to file
    with open('skull_strings.txt', 'w', encoding='utf-8') as f:
        for s in interesting_strings:
            f.write(s + '\n')
    print(f"\nAll strings saved to skull_strings.txt")
    print()
    
    # Find code patterns
    print("Analyzing code patterns...")
    print("-" * 80)
    patterns = find_code_patterns(data)
    print(f"  Function prologues found: {len(patterns['function_prologue'])}")
    print(f"  INT 21h (DOS calls) found: {len(patterns['int_21h'])}")
    print(f"  CALL instructions found: {len(patterns['call_patterns'])}")
    print(f"  JMP instructions found: {len(patterns['jump_patterns'])}")
    
    if patterns['int_21h']:
        print(f"\n  First 10 DOS interrupt locations:")
        for addr in patterns['int_21h'][:10]:
            print(f"    Offset 0x{addr:04X}")
    print()
    
    # Analyze sections
    print("Section Analysis:")
    print("-" * 80)
    sections = analyze_sections(data, dos_header)
    for section in sections:
        print(f"  {section['name']}: offset 0x{section['offset']:04X}, size {section.get('size', 'unknown')}")
    print()
    
    # Try to identify data structures
    print("Attempting to identify data structures...")
    print("-" * 80)
    
    # Look for potential string tables or data arrays
    # This is a simple heuristic - look for repeated patterns
    print("  Analysis complete. Check skull_strings.txt for extracted strings.")
    print()
    
    print("=" * 80)
    print("Analysis complete!")

if __name__ == '__main__':
    main()

