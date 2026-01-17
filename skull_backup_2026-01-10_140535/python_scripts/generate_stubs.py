#!/usr/bin/env python3
"""
Generate stub functions for all FUN_* functions that are called but not defined
"""

import re
from pathlib import Path

def extract_function_signatures(content):
    """Extract all function definitions and calls"""
    # Find function definitions
    func_defs = set()
    func_calls = set()
    
    # Find definitions: void/int FUN_XXXX(...)
    pattern_def = r'(void|int|undefined2|char|uint)\s+FUN_\w+\s*\([^)]*\)'
    for match in re.finditer(pattern_def, content):
        func_name = re.search(r'FUN_\w+', match.group(0))
        if func_name:
            func_defs.add(func_name.group(0))
    
    # Find calls: FUN_XXXX(...)
    pattern_call = r'FUN_\w+\s*\('
    for match in re.finditer(pattern_call, content):
        func_name = match.group(0).rstrip('(')
        func_calls.add(func_name)
    
    return func_defs, func_calls

def generate_stub(func_name, return_type='void'):
    """Generate a stub function"""
    return f'''
/* Stub for {func_name} */
{return_type} {func_name}(void) {{
    /* TODO: Implement this function */
    /* This is a placeholder to allow compilation */
    return;
}}
'''

def main():
    input_file = 'skull_ported.c'
    
    if not Path(input_file).exists():
        print(f"Error: {input_file} not found")
        return
    
    with open(input_file, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    func_defs, func_calls = extract_function_signatures(content)
    
    # Find functions that are called but not defined
    missing_funcs = func_calls - func_defs
    
    print(f"Found {len(func_defs)} function definitions")
    print(f"Found {len(func_calls)} function calls")
    print(f"Missing {len(missing_funcs)} function implementations")
    
    # Generate stubs
    stubs = []
    for func in sorted(missing_funcs):
        # Try to determine return type from usage
        return_type = 'void'
        if re.search(rf'{func}\s*\([^)]*\)\s*=', content):
            return_type = 'int'
        elif re.search(rf'{func}\s*\([^)]*\)\s*;', content):
            # Check if result is used
            if re.search(rf'=\s*{func}\s*\(', content):
                return_type = 'int'
        
        stubs.append(generate_stub(func, return_type))
    
    # Write stubs to file
    stubs_file = 'function_stubs.c'
    with open(stubs_file, 'w') as f:
        f.write('/* Auto-generated function stubs */\n')
        f.write('/* These are placeholders - implement as needed */\n\n')
        f.write('#include "dos_compat.h"\n\n')
        for stub in stubs:
            f.write(stub)
    
    print(f"\nGenerated {len(stubs)} stub functions in {stubs_file}")
    print("\nTo use these stubs, add function_stubs.c to your build.")

if __name__ == '__main__':
    main()

