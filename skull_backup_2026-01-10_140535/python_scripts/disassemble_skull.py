#!/usr/bin/env python3
"""
Disassemble SKULL.EXE using Capstone
"""

try:
    from capstone import *
except ImportError:
    print("Capstone not installed. Installing...")
    import subprocess
    subprocess.check_call(['pip', 'install', 'capstone', '--quiet'])
    from capstone import *

import struct
from pathlib import Path

def read_binary_file(filename):
    """Read binary file"""
    with open(filename, 'rb') as f:
        return f.read()

def disassemble_code(data, start_offset=0x200, max_bytes=0x1000):
    """Disassemble code section"""
    # Initialize Capstone for 16-bit x86 (8086/8088)
    md = Cs(CS_ARCH_X86, CS_MODE_16)
    md.detail = True
    
    code_section = data[start_offset:start_offset + max_bytes]
    
    instructions = []
    for instruction in md.disasm(code_section, start_offset):
        instructions.append({
            'address': instruction.address,
            'mnemonic': instruction.mnemonic,
            'op_str': instruction.op_str,
            'bytes': instruction.bytes.hex(),
            'size': instruction.size
        })
    
    return instructions

def analyze_functions(data, patterns):
    """Try to identify function boundaries"""
    functions = []
    
    # Function prologues typically start with: push bp; mov bp, sp
    # In 16-bit: 55 (push bp), 8B EC (mov bp, sp)
    for addr in patterns.get('function_prologue', []):
        if addr + 10 < len(data):
            # Try to disassemble from this point
            func_data = data[addr:addr+200]  # First 200 bytes of function
            functions.append({
                'address': addr,
                'data': func_data
            })
    
    return functions

def main():
    exe_file = 'SKULL.EXE'
    
    if not Path(exe_file).exists():
        print(f"Error: {exe_file} not found")
        return
    
    print(f"Disassembling {exe_file}...")
    print("=" * 80)
    
    # Read binary
    data = read_binary_file(exe_file)
    
    # DOS header info
    initial_ip = struct.unpack('<H', data[20:22])[0]
    initial_cs = struct.unpack('<H', data[22:24])[0]
    
    # Calculate entry point
    # In DOS, entry point is typically at offset 0x100 or after header
    entry_point = 0x100  # Standard DOS entry point
    
    print(f"Entry point: 0x{entry_point:04X}")
    print(f"Initial CS:IP: {initial_cs:04X}:{initial_ip:04X}")
    print()
    
    # Disassemble entry point area
    print("Disassembling entry point area (first 512 bytes):")
    print("-" * 80)
    
    try:
        instructions = disassemble_code(data, entry_point, 512)
        
        output_lines = []
        for inst in instructions[:100]:  # First 100 instructions
            addr_str = f"0x{inst['address']:04X}"
            bytes_str = inst['bytes']
            mnemonic = inst['mnemonic']
            op_str = inst['op_str']
            
            line = f"{addr_str:8s}  {bytes_str:20s}  {mnemonic:8s}  {op_str}"
            output_lines.append(line)
            print(line)
        
        # Save to file
        with open('skull_disassembly.txt', 'w') as f:
            f.write("SKULL.EXE Disassembly\n")
            f.write("=" * 80 + "\n\n")
            f.write(f"Entry point: 0x{entry_point:04X}\n\n")
            for line in output_lines:
                f.write(line + "\n")
        
        print(f"\nDisassembly saved to skull_disassembly.txt")
        
    except Exception as e:
        print(f"Error during disassembly: {e}")
        import traceback
        traceback.print_exc()
    
    # Try to disassemble around DOS interrupt calls
    print("\nDisassembling around DOS interrupt calls (INT 21h):")
    print("-" * 80)
    
    int21_locations = []
    for i in range(len(data) - 1):
        if data[i:i+2] == b'\xCD\x21':  # INT 21h
            int21_locations.append(i)
    
    if int21_locations:
        # Disassemble around first few INT 21h calls
        for int_addr in int21_locations[:5]:
            print(f"\nAround INT 21h at 0x{int_addr:04X}:")
            start = max(0, int_addr - 20)
            end = min(len(data), int_addr + 20)
            
            try:
                md = Cs(CS_ARCH_X86, CS_MODE_16)
                code_section = data[start:end]
                
                for instruction in md.disasm(code_section, start):
                    addr_str = f"0x{instruction.address:04X}"
                    bytes_str = instruction.bytes.hex()
                    mnemonic = instruction.mnemonic
                    op_str = instruction.op_str
                    
                    marker = " <-- INT 21h" if instruction.address == int_addr else ""
                    print(f"  {addr_str:8s}  {bytes_str:20s}  {mnemonic:8s}  {op_str}{marker}")
            except Exception as e:
                print(f"  Error: {e}")
    
    print("\n" + "=" * 80)
    print("Disassembly complete!")

if __name__ == '__main__':
    main()

