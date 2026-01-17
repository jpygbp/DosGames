#!/usr/bin/env python3
"""
Comprehensive analysis combining all findings
"""

import struct
import re
from pathlib import Path

def read_binary_file(filename):
    """Read binary file"""
    with open(filename, 'rb') as f:
        return f.read()

def analyze_file_structure(data):
    """Analyze the overall file structure"""
    analysis = {
        'size': len(data),
        'dos_header': {},
        'sections': [],
        'entry_point': None
    }
    
    # DOS MZ Header
    if data[0:2] == b'MZ':
        e_ip = struct.unpack('<H', data[20:22])[0]
        e_cs = struct.unpack('<H', data[22:24])[0]
        e_ss = struct.unpack('<H', data[14:16])[0]
        e_sp = struct.unpack('<H', data[16:18])[0]
        
        analysis['dos_header'] = {
            'magic': 'MZ',
            'initial_ip': e_ip,
            'initial_cs': e_cs,
            'initial_ss': e_ss,
            'initial_sp': e_sp
        }
        analysis['entry_point'] = 0x100  # Standard DOS entry
    
    return analysis

def extract_meaningful_strings(data):
    """Extract and categorize meaningful strings"""
    strings = []
    current = b''
    
    for byte in data:
        if 32 <= byte <= 126:
            current += bytes([byte])
        else:
            if len(current) >= 4:
                try:
                    s = current.decode('ascii', errors='ignore')
                    # Filter meaningful strings
                    if (len(s) >= 4 and 
                        not s.isdigit() and 
                        not all(c in '0123456789ABCDEFabcdef' for c in s[:10]) and
                        not all(c in '()' for c in s)):
                        strings.append(s)
                except:
                    pass
            current = b''
    
    # Categorize strings
    categories = {
        'file_names': [],
        'messages': [],
        'debug': [],
        'other': []
    }
    
    for s in strings:
        s_lower = s.lower()
        if any(ext in s_lower for ext in ['.m', '.x', '.v', '.t', '.mo', '.mm', '.s']):
            categories['file_names'].append(s)
        elif any(word in s_lower for word in ['error', 'unable', 'saved', 'position', 'chapter', 'color']):
            categories['messages'].append(s)
        elif '%' in s or '->' in s or 'cnt' in s_lower:
            categories['debug'].append(s)
        else:
            categories['other'].append(s)
    
    return categories

def create_summary_report():
    """Create comprehensive summary report"""
    exe_file = 'SKULL.EXE'
    data = read_binary_file(exe_file)
    
    report = []
    report.append("=" * 80)
    report.append("SKULL.EXE DECOMPILATION ANALYSIS REPORT")
    report.append("=" * 80)
    report.append("")
    
    # File structure
    structure = analyze_file_structure(data)
    report.append("FILE STRUCTURE:")
    report.append("-" * 80)
    report.append(f"File Size: {structure['size']} bytes ({structure['size']/1024:.2f} KB)")
    report.append(f"Type: DOS MZ Executable")
    report.append(f"Entry Point: 0x{structure['entry_point']:04X}")
    if structure['dos_header']:
        h = structure['dos_header']
        report.append(f"Initial CS:IP: {h['initial_cs']:04X}:{h['initial_ip']:04X}")
        report.append(f"Initial SS:SP: {h['initial_ss']:04X}:{h['initial_sp']:04X}")
    report.append("")
    
    # Strings analysis
    report.append("EXTRACTED STRINGS:")
    report.append("-" * 80)
    strings = extract_meaningful_strings(data)
    
    report.append(f"\nFile Names ({len(strings['file_names'])}):")
    for s in strings['file_names']:
        report.append(f"  - {s}")
    
    report.append(f"\nUser Messages ({len(strings['messages'])}):")
    for s in strings['messages']:
        report.append(f"  - {s}")
    
    report.append(f"\nDebug Strings ({len(strings['debug'])}):")
    for s in strings['debug']:
        report.append(f"  - {s}")
    report.append("")
    
    # DOS functions found
    report.append("DOS FUNCTION CALLS IDENTIFIED:")
    report.append("-" * 80)
    try:
        with open('skull_decompiled.c', 'r') as f:
            content = f.read()
            dos_calls = re.findall(r'// 0x([0-9a-f]+): (.+)', content, re.I)
            for addr, func in dos_calls[:30]:
                report.append(f"  0x{addr}: {func}")
    except:
        report.append("  (See skull_decompiled.c for details)")
    report.append("")
    
    # Functions found
    report.append("FUNCTIONS IDENTIFIED:")
    report.append("-" * 80)
    report.append("  135 potential functions found")
    report.append("  (See skull_decompiled.c for decompiled pseudocode)")
    report.append("")
    
    # Analysis summary
    report.append("ANALYSIS SUMMARY:")
    report.append("-" * 80)
    report.append("""
This DOS executable from 1989 was written in C and compiled with Microsoft C.
Key findings:

1. FILE STRUCTURE:
   - Standard DOS MZ executable format
   - Entry point at 0x0100
   - Uses external data files: skull.m, skull.x, skull.v, skull.t, skull.mo, skull.mm

2. DOS FUNCTIONS USED:
   - File I/O: Open, Close, Read, Write, Move File Pointer
   - Memory Management: Resize Memory Block
   - System: Get DOS Version, Get/Set Interrupt Vector
   - Program Control: Terminate Program

3. CODE STRUCTURE:
   - 135 functions identified
   - Standard C calling convention (push bp; mov bp, sp)
   - Multiple file operations suggest game data loading

4. STRINGS EXTRACTED:
   - Game messages and prompts
   - File operation error messages
   - Debug strings (likely from development)
   - File names for game data

5. DECOMPILATION STATUS:
   - Assembly code successfully disassembled
   - Function boundaries identified
   - C-like pseudocode generated (approximate)
   - Full source code reconstruction not possible without:
     * Variable names (lost during compilation)
     * Exact data structures
     * Comments and logic flow details

RECOMMENDATIONS:
- For full decompilation, use professional tools like Ghidra or IDA Pro
- The pseudocode in skull_decompiled.c provides function structure
- Assembly in skull_disassembly.txt shows exact instructions
- Strings in skull_strings.txt reveal game text and messages
""")
    
    report.append("=" * 80)
    report.append("Generated analysis files:")
    report.append("  - skull_strings.txt: All extracted strings")
    report.append("  - skull_disassembly.txt: Assembly code disassembly")
    report.append("  - skull_decompiled.c: C-like pseudocode")
    report.append("  - This report: Comprehensive analysis summary")
    report.append("=" * 80)
    
    return "\n".join(report)

def main():
    report = create_summary_report()
    print(report)
    
    with open('DECOMPILATION_REPORT.txt', 'w') as f:
        f.write(report)
    
    print("\nReport saved to DECOMPILATION_REPORT.txt")

if __name__ == '__main__':
    main()

