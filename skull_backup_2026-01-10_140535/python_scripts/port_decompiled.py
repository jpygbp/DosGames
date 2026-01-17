#!/usr/bin/env python3
"""
Port decompiled DOS code to 64-bit Windows
Converts 16-bit DOS types and conventions to modern Windows equivalents
"""

import re
from pathlib import Path

def port_decompiled_code(input_file, output_file):
    """Port the decompiled code from DOS to Windows"""
    
    with open(input_file, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Replace includes
    content = content.replace('#include <dos.h>', '#include "dos_compat.h"')
    
    # Remove DOS-specific calling conventions
    content = re.sub(r'__cdecl16near\s+', '', content)
    content = re.sub(r'__cdecl16far\s+', '', content)
    content = re.sub(r'__far\s+', '', content)
    content = re.sub(r'__near\s+', '', content)
    
    # Replace absolute memory addresses with structure access
    # Pattern: *(type *)0xXXXX -> MEM_READ32(0xXXXX) or appropriate macro
    def replace_memory_access(match):
        addr = match.group(1)
        type_str = match.group(2)
        var_name = match.group(3)
        
        if 'undefined2' in type_str or 'uint16' in type_str:
            return f'MEM_READ16({addr})'
        elif 'uint' in type_str or 'int' in type_str:
            return f'MEM_READ32({addr})'
        else:
            return f'MEM_READ32({addr})'
    
    # Replace memory writes
    def replace_memory_write(match):
        addr = match.group(1)
        type_str = match.group(2)
        value = match.group(3)
        
        if 'undefined2' in type_str or 'uint16' in type_str:
            return f'MEM_WRITE16({addr}, {value})'
        elif 'uint' in type_str or 'int' in type_str:
            return f'MEM_WRITE32({addr}, {value})'
        else:
            return f'MEM_WRITE32({addr}, {value})'
    
    # Replace *(type *)0xXXXX patterns
    content = re.sub(r'\*\((\w+\s*\*?)\s*\)\s*(0x[0-9a-fA-F]+)', 
                     lambda m: f'MEM_READ32({m.group(2)})', content)
    
    # Replace *(type *)0xXXXX = value patterns
    content = re.sub(r'\*\((\w+\s*\*?)\s*\)\s*(0x[0-9a-fA-F]+)\s*=\s*([^;]+);',
                     lambda m: f'MEM_WRITE32({m.group(2)}, {m.group(3)});', content)
    
    # Replace function pointer casts
    content = re.sub(r'\(undefined2\s*\*\)', '(uint16_t*)', content)
    content = re.sub(r'\(undefined\s*\*\)', '(uint8_t*)', content)
    
    # Add initialization at the start of main
    if 'int main(' in content or 'void main(' in content:
        # Find main function
        main_match = re.search(r'(int|void)\s+main\s*\([^)]*\)\s*\{', content)
        if main_match:
            insert_pos = main_match.end()
            init_code = '\n    InitGameState();\n    atexit(CleanupGameState);\n'
            content = content[:insert_pos] + init_code + content[insert_pos:]
    
    # If no main, add one that calls the entry function
    if 'int main(' not in content and 'void main(' not in content:
        # Find the first function (likely entry point)
        first_func = re.search(r'void\s+FUN_\w+\([^)]*\)', content)
        if first_func:
            # Add main function before the first function
            main_code = '''
int main(int argc, char* argv[]) {
    InitGameState();
    atexit(CleanupGameState);
    
    /* Call the original entry point */
    FUN_1000_0010();
    
    return 0;
}

'''
            content = main_code + content
    
    # Write ported code
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write('/* Ported from DOS to 64-bit Windows */\n')
        f.write('/* This is an automated port - manual review and fixes may be needed */\n\n')
        f.write(content)
    
    print(f"Ported code written to {output_file}")
    print("Note: Manual review and fixes may be needed for:")
    print("  - Function pointer types")
    print("  - Complex memory access patterns")
    print("  - DOS-specific I/O operations")
    print("  - Segmented memory model assumptions")

if __name__ == '__main__':
    input_file = 'skull_ghidra_decompiled.c'
    output_file = 'skull_ported.c'
    
    if not Path(input_file).exists():
        print(f"Error: {input_file} not found")
        print("Trying skull_decompiled.c instead...")
        input_file = 'skull_decompiled.c'
        if not Path(input_file).exists():
            print(f"Error: {input_file} not found either")
            exit(1)
    
    port_decompiled_code(input_file, output_file)

