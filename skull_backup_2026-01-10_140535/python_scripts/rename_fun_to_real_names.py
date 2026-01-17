#!/usr/bin/env python3
"""
Script to verify and document function name mappings
Since functions are already renamed in skull_ported.c, this script
just documents the mappings and cleans up function_stubs.c
"""

import re
from pathlib import Path

# Function name mappings (FUN_* -> real name)
FUNCTION_MAPPINGS = {
    'FUN_1000_05b6': 'lookup_command',
    'FUN_1000_0d36': 'find_matching_objects',
    'FUN_1000_4d44': 'parse_format_number',
    'FUN_1000_4dec': 'file_close',
    'FUN_1000_529d': 'allocate_memory_chunk',
    'FUN_1000_21ee': 'handle_direction_move',
    'FUN_1000_2e28': 'check_game_state',
    'FUN_1000_2e70': 'find_objects_in_location',
    'FUN_1000_2f64': 'remove_object_from_list',
    'FUN_1000_3024': 'add_object_to_list',
    'FUN_1000_325c': 'display_object_info',
    'FUN_1000_358c': 'load_and_display_message',
    'FUN_1000_36ae': 'format_text_line',
    'FUN_1000_3908': 'load_string_from_file',
    'FUN_1000_39d0': 'load_string_from_secondary_file',
    'FUN_1000_3a98': 'read_file_exact',
    'FUN_1000_3aee': 'file_read_word',
    'FUN_1000_3b24': 'file_open',
    'FUN_1000_3e64': 'verify_game_data',
}

# Functions that are truly missing (need stubs)
MISSING_FUNCTIONS = [
    'FUN_1000_55a6',
    'FUN_1000_5592',
    'FUN_1000_550e',
    'FUN_1000_56ae',
    'FUN_1000_4e86',
    'FUN_1000_4e0c',
    'FUN_1000_5108',
    'FUN_1000_502a',
    'FUN_1000_54f2',
]

def check_function_usage(file_path):
    """Check if FUN_* names are used in the file"""
    content = file_path.read_text(encoding='utf-8', errors='ignore')
    found = {}
    for fun_name in FUNCTION_MAPPINGS.keys():
        # Look for function calls (FUN_xxx(...))
        pattern = rf'\b{re.escape(fun_name)}\s*\('
        matches = re.findall(pattern, content)
        if matches:
            found[fun_name] = len(matches)
    return found

def main():
    print("Checking for FUN_* function calls in codebase...")
    print("=" * 60)
    
    skull_ported = Path('skull_ported.c')
    if skull_ported.exists():
        found = check_function_usage(skull_ported)
        if found:
            print(f"\nWARNING: Found {len(found)} FUN_* calls in skull_ported.c:")
            for fun_name, count in found.items():
                print(f"  - {fun_name}: {count} calls")
        else:
            print("\nOK: No FUN_* calls found in skull_ported.c")
            print("   Functions are already using real names!")
    
    print("\n" + "=" * 60)
    print("Function Name Mappings:")
    print("=" * 60)
    for fun_name, real_name in sorted(FUNCTION_MAPPINGS.items()):
        print(f"  {fun_name:20} -> {real_name}")
    
    print("\n" + "=" * 60)
    print("Truly Missing Functions (need stubs):")
    print("=" * 60)
    for fun_name in MISSING_FUNCTIONS:
        print(f"  - {fun_name}")
    
    print("\n" + "=" * 60)
    print("Recommendation:")
    print("=" * 60)
    print("Since functions are already renamed in skull_ported.c,")
    print("we can remove the wrapper functions from function_stubs.c")
    print("and keep only the stubs for truly missing functions.")

if __name__ == '__main__':
    main()

