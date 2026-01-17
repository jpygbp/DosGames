#!/usr/bin/env python3
"""
Advanced decompilation attempt for SKULL.EXE
Tries to reconstruct C-like pseudocode from assembly
"""

try:
    from capstone import *
except ImportError:
    import subprocess
    subprocess.check_call(['pip', 'install', 'capstone', '--quiet'])
    from capstone import *

import struct
import re
from pathlib import Path

def read_binary_file(filename):
    """Read binary file"""
    with open(filename, 'rb') as f:
        return f.read()

def identify_dos_functions(data):
    """Identify DOS function calls by INT 21h with AH register"""
    md = Cs(CS_ARCH_X86, CS_MODE_16)
    md.detail = True
    
    functions = []
    
    # Find all INT 21h calls
    for i in range(len(data) - 10):
        if data[i:i+2] == b'\xCD\x21':
            # Try to disassemble backwards to find AH value
            context_start = max(0, i - 20)
            context = data[context_start:i+2]
            
            for inst in md.disasm(context, context_start):
                if inst.address == i - 2 or inst.address == i - 3:
                    # Check if previous instruction sets AH
                    if inst.mnemonic == 'mov' and 'ah' in inst.op_str.lower():
                        # Extract AH value
                        ah_match = re.search(r'0x([0-9a-f]+)', inst.op_str, re.I)
                        if ah_match:
                            ah_value = int(ah_match.group(1), 16)
                            dos_function = get_dos_function_name(ah_value)
                            functions.append({
                                'address': i,
                                'ah': ah_value,
                                'function': dos_function,
                                'context': inst.op_str
                            })
    
    return functions

def get_dos_function_name(ah):
    """Map DOS INT 21h function numbers to names"""
    dos_functions = {
        0x00: 'Terminate Program',
        0x01: 'Read Character from STDIN',
        0x02: 'Write Character to STDOUT',
        0x09: 'Write String to STDOUT',
        0x0A: 'Buffered Input',
        0x0E: 'Select Default Drive',
        0x19: 'Get Current Default Drive',
        0x1A: 'Set DTA (Disk Transfer Address)',
        0x21: 'Open File',
        0x22: 'Close File',
        0x23: 'Find First File',
        0x24: 'Find Next File',
        0x25: 'Set Interrupt Vector',
        0x26: 'Create New PSP',
        0x2A: 'Get Date',
        0x2B: 'Set Date',
        0x2C: 'Get Time',
        0x2D: 'Set Time',
        0x30: 'Get DOS Version',
        0x35: 'Get Interrupt Vector',
        0x3C: 'Create File',
        0x3D: 'Open File',
        0x3E: 'Close File',
        0x3F: 'Read File',
        0x40: 'Write File',
        0x41: 'Delete File',
        0x42: 'Move File Pointer',
        0x43: 'Get/Set File Attributes',
        0x4A: 'Resize Memory Block',
        0x4B: 'Load/Execute Program',
        0x4C: 'Terminate Program with Return Code',
    }
    return dos_functions.get(ah, f'Unknown DOS Function (AH=0x{ah:02X})')

def decompile_function(data, start_addr, max_size=500):
    """Attempt to decompile a function to C-like pseudocode"""
    md = Cs(CS_ARCH_X86, CS_MODE_16)
    md.detail = True
    
    if start_addr >= len(data) or start_addr + max_size > len(data):
        return None
    
    code = data[start_addr:start_addr + max_size]
    instructions = list(md.disasm(code, start_addr))
    
    if not instructions:
        return None
    
    pseudocode = []
    pseudocode.append(f"// Function at 0x{start_addr:04X}")
    
    # Check for function prologue
    if len(instructions) > 2:
        if instructions[0].mnemonic == 'push' and 'bp' in instructions[0].op_str:
            if instructions[1].mnemonic == 'mov' and 'bp' in instructions[1].op_str and 'sp' in instructions[1].op_str:
                pseudocode.append("void function_%04X() {" % start_addr)
                pseudocode.append("    // Function prologue: push bp; mov bp, sp")
                
                # Try to identify local variables (sub sp, imm)
                for i, inst in enumerate(instructions[2:10], 2):
                    if inst.mnemonic == 'sub' and 'sp' in inst.op_str:
                        imm_match = re.search(r'0x([0-9a-f]+)', inst.op_str, re.I)
                        if imm_match:
                            local_size = int(imm_match.group(1), 16)
                            pseudocode.append(f"    // Local variables: {local_size} bytes")
                            break
    
    # Analyze instructions
    i = 0
    while i < len(instructions) and i < 50:  # Limit to first 50 instructions
        inst = instructions[i]
        
        # Skip prologue
        if i < 3 and (inst.mnemonic in ['push', 'mov'] and 'bp' in inst.op_str):
            i += 1
            continue
        
        # DOS calls
        if inst.mnemonic == 'int' and '0x21' in inst.op_str:
            # Look for AH register value
            if i > 0:
                prev = instructions[i-1]
                if prev.mnemonic == 'mov' and 'ah' in prev.op_str.lower():
                    ah_match = re.search(r'0x([0-9a-f]+)', prev.op_str, re.I)
                    if ah_match:
                        ah = int(ah_match.group(1), 16)
                        func_name = get_dos_function_name(ah)
                        pseudocode.append(f"    // DOS call: {func_name}")
        
        # Function calls
        if inst.mnemonic == 'call':
            target_match = re.search(r'0x([0-9a-f]+)', inst.op_str, re.I)
            if target_match:
                target = int(target_match.group(1), 16)
                pseudocode.append(f"    function_%04X();" % target)
        
        # Returns
        if inst.mnemonic == 'ret':
            pseudocode.append("    return;")
            break
        
        # Conditional jumps
        if inst.mnemonic.startswith('j'):
            target_match = re.search(r'0x([0-9a-f]+)', inst.op_str, re.I)
            if target_match:
                target = int(target_match.group(1), 16)
                jump_type = inst.mnemonic
                pseudocode.append(f"    if ({jump_type}) goto label_%04X;" % target)
        
        i += 1
    
    if pseudocode[-1] != "}":
        pseudocode.append("}")
    
    return "\n".join(pseudocode)

def find_all_functions(data):
    """Find all function entry points"""
    functions = []
    
    # Look for function prologues: push bp; mov bp, sp
    for i in range(len(data) - 10):
        if data[i:i+3] == b'\x55\x8B\xEC':  # push bp; mov bp, sp (32-bit)
            functions.append(i)
        elif i + 2 < len(data) and data[i] == 0x55:  # push bp (16-bit)
            # Check if next instruction is mov bp, sp
            if i + 3 < len(data):
                # mov bp, sp in 16-bit is typically 8B EC or 89 E5
                if data[i+1:i+3] in [b'\x8B\xEC', b'\x89\xE5']:
                    functions.append(i)
    
    return sorted(set(functions))

def main():
    exe_file = 'SKULL.EXE'
    
    if not Path(exe_file).exists():
        print(f"Error: {exe_file} not found")
        return
    
    print(f"Decompiling {exe_file}...")
    print("=" * 80)
    
    data = read_binary_file(exe_file)
    
    # Identify DOS functions
    print("Identifying DOS function calls...")
    print("-" * 80)
    dos_functions = identify_dos_functions(data)
    
    print(f"Found {len(dos_functions)} DOS function calls:\n")
    for func in dos_functions[:20]:  # First 20
        print(f"  0x{func['address']:04X}: {func['function']} (AH=0x{func['ah']:02X})")
    
    # Find all functions
    print("\nFinding function entry points...")
    print("-" * 80)
    functions = find_all_functions(data)
    print(f"Found {len(functions)} potential functions")
    
    # Decompile some functions
    print("\nDecompiling sample functions...")
    print("-" * 80)
    
    decompiled = []
    for func_addr in functions[:10]:  # First 10 functions
        pseudocode = decompile_function(data, func_addr)
        if pseudocode:
            decompiled.append(pseudocode)
            print(f"\n{pseudocode}\n")
    
    # Save decompiled code
    with open('skull_decompiled.c', 'w') as f:
        f.write("/* Decompiled pseudocode from SKULL.EXE */\n")
        f.write("/* This is an approximation - not exact source code */\n\n")
        f.write("#include <dos.h>\n\n")
        
        f.write("/* DOS Function Calls Found: */\n")
        for func in dos_functions:
            f.write(f"// 0x{func['address']:04X}: {func['function']}\n")
        
        f.write("\n/* Decompiled Functions: */\n\n")
        for code in decompiled:
            f.write(code)
            f.write("\n\n")
    
    print(f"\nDecompiled code saved to skull_decompiled.c")
    print("=" * 80)
    print("Decompilation complete!")

if __name__ == '__main__':
    main()

