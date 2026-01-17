# Memory Functions Deep Analysis

**Date:** 2026-01-09  
**Status:** In-depth investigation of failing memory management functions

## Overview

Set 8 Memory Management Functions currently has 2/7 passing (28.6%). This document provides a detailed analysis of each failing function and the root causes.

## Function Analysis

### 1. `find_memory_block()` - FAILING

**Exception Location:** Line 9920 (caught in exception handler, actual exception at line 9909)

**Root Cause Analysis:**
- Line 9909: Calls `allocate_memory_with_split()` which then calls `initialize_memory_allocator()` which fails
- The function expects:
  - `di_register` (from MEM_POINTER_STORAGE_253): Valid block pointer (>= 2)
  - `si_register` (from MEM_REGISTER_STORAGE_2): Offset within block
  - `cx_register` (from MEM_REGISTER_STORAGE_1): Block size
  - `MEM_POINTER_STORAGE_254`: Maximum memory size

**Issues Identified:**
1. **Chain of calls causing failure**: `find_memory_block()` → `allocate_memory_with_split()` → `initialize_memory_allocator()` → `resize_memory_block()` → `merge_memory_blocks()` → FAILS
2. **Logic issue at line 9907**: `!CARRY2(block_size + si_register,search_size)` - The calculation might cause issues if values are not properly initialized
3. **search_size initialization**: Starts at `BIT_MASK_32767` (0x7FFF), which is very large. The loop might iterate too many times or with invalid values

**Fix Required:**
- Ensure `search_size` is initialized to a reasonable value (e.g., block_size)
- Add early return if `si_register` is 0 or invalid
- Consider making `allocate_memory_with_split()` not call `initialize_memory_allocator()` if it's already initialized

---

### 2. `allocate_memory_with_split()` - FAILING

**Exception Location:** Line 9988 (caught in exception handler, actual exception likely at line 9955)

**Root Cause Analysis:**
- Line 9955: Calls `initialize_memory_allocator()` FIRST, which fails
- Line 9956: Sets `allocation_result = 0` after the call
- Line 9965: `block_ptr = (int)allocation_result + ...` becomes 0
- Line 9967-9970: Validation checks for `block_ptr >= 2`, which would be false (0 < 2), so it should return early
- However, the exception occurs BEFORE reaching the validation

**Issues Identified:**
1. **Calls initialize_memory_allocator() first**: This is problematic because `initialize_memory_allocator()` calls `resize_memory_block(1, 0, 0)` which may fail
2. **allocation_result initialization**: After calling `initialize_memory_allocator()`, `allocation_result` is set to 0, but it should be set to the result of an actual allocation
3. **zero_flag logic**: `zero_flag` is initialized to 0 (false), so `if (!(bool)zero_flag)` at line 9964 is always true, meaning the code ALWAYS tries to access `block_ptr - 2`

**Fix Required:**
- Don't call `initialize_memory_allocator()` if memory is already initialized (add a flag check)
- Properly initialize `allocation_result` from an actual allocation call
- Fix the `zero_flag` logic - it should check if allocation was successful
- Add validation BEFORE attempting to dereference `block_ptr`

---

### 3. `initialize_memory_allocator()` - FAILING

**Exception Location:** Line 10015 (caught in exception handler, actual exception at line 10011)

**Root Cause Analysis:**
- Line 10011: Calls `resize_memory_block(1, 0, 0)`
- The `1` for `block_ptr` is NOT a pointer - it's a special flag value
- `resize_memory_block()` checks `if (block_ptr == 1)` at line 10047, which is TRUE
- Then calls `merge_memory_blocks()` at line 10048, which FAILS

**Issues Identified:**
1. **Invalid parameters**: `resize_memory_block(1, 0, 0)` - `1` is a flag, not a pointer. This is intentional, but `merge_memory_blocks()` then fails
2. **Circular dependency**: `initialize_memory_allocator()` → `resize_memory_block()` → `merge_memory_blocks()` → FAILS

**Fix Required:**
- Ensure `merge_memory_blocks()` can handle the case where it's called during initialization
- Or, skip calling `merge_memory_blocks()` if memory allocator is not yet initialized
- Add initialization state tracking

---

### 4. `resize_memory_block()` - FAILING

**Exception Location:** Line 10092 (caught in exception handler, actual exception likely at line 10064 or 10075)

**Root Cause Analysis:**
- Line 10055: Reads `memory_offset = MEM_READ32(MEM_POINTER_STORAGE_8)` - should be 0x1000 from our initialization
- Line 10064: `block_header_ptr = (uint16_t*)(memory_offset + 4)` - becomes (uint16_t*)0x1004
- Line 10065: **TYPE MISMATCH BUG**: `if ((block_header_ptr < (uint16_t*)MEM_POINTER_STORAGE_8) && ...)`
  - Compares pointer 0x1004 with constant 0x5e0 (MEM_POINTER_STORAGE_8)
  - This is always false (0x1004 > 0x5e0), so the inner block is skipped
- Line 10074-10075: `if (block_header_ptr != NULL)` then `*block_header_ptr = ...` - but `block_header_ptr` is 0x1004, which might not be validated

**Issues Identified:**
1. **Type mismatch at line 10065**: Comparing pointer with constant - should compare offsets
2. **block_header_ptr validation**: `block_header_ptr` is calculated as `(uint16_t*)(memory_offset + 4)` but should be validated against memory pool
3. **block_header_ptr is NOT NULL**: It's always a valid pointer value (0x1004), but the NULL check at line 10074 will always pass, even if the pointer is invalid

**Fix Required:**
- Fix line 10065: Compare offset instead of pointer: `if ((memory_offset + 4 < MEM_POINTER_STORAGE_8) && ...)`
- Validate `block_header_ptr` is within memory pool bounds before dereferencing
- Convert `block_header_ptr` to use memory pool offset instead of direct pointer

---

### 5. `merge_memory_blocks()` - FAILING

**Exception Location:** Line 10207 (caught in exception handler, actual exception likely at line 10167, 10171, or 10199)

**Root Cause Analysis:**
- Line 10130-10131: Reads `bp_register` and `di_register` from MEM_POINTER_STORAGE_253 - should be 0x1000
- Line 10138: `block_size = *(uint *)(g_gameState->memory_pool + bp_register + SIZE_OBJECT_ENTRY)`
  - `bp_register` = 0x1000
  - `SIZE_OBJECT_ENTRY` = 0x0C (12)
  - Accesses offset 0x100C, which should be valid
- Line 10145: `next_block = (uint *)(g_gameState->memory_pool + di_register)` - should be valid
- Line 10152: `if (next_block[1] != block_size)` - Compares next_block[1] (which is the next pointer) with block_size
- Line 10171: **TYPE MISMATCH BUG**: `if ((next_block != di_register) || ...)`
  - Compares pointer `next_block` (e.g., 0x1000) with integer `di_register` (0x1000)
  - This might work if values match, but is conceptually wrong
  - Should compare: `if ((next_block_offset != di_register) || ...)`
- Line 10172: `should_skip = next_block < di_register;` - **TYPE MISMATCH**: Comparing pointer with integer
- Line 10173: `if (next_block == di_register)` - **TYPE MISMATCH**: Comparing pointer with integer
- Line 10167: `merged_size = dx_register + *current_block;` - **UNINITIALIZED**: `dx_register` is never set! It's initialized to 0 at line 10119, but never read from memory
- Line 10184: `merged_size = extraout_DX;` - **UNINITIALIZED**: `extraout_DX` is never set!

**Issues Identified:**
1. **Multiple type mismatches**: Comparing pointers with integers (lines 10171, 10172, 10173)
2. **Uninitialized variables**: `dx_register` and `extraout_DX` are never initialized
3. **Logic error at line 10152**: Compares `next_block[1]` (next pointer) with `block_size` - this is probably wrong, should compare `*next_block` (block size)
4. **Memory block structure misunderstanding**: The code assumes `next_block[0]` is size and `next_block[1]` is next pointer, but our initialization might not match

**Fix Required:**
- Convert all pointer comparisons to offset comparisons
- Initialize `dx_register` and `extraout_DX` from memory (check what memory locations they should come from)
- Fix line 10152 to compare block sizes correctly
- Ensure memory block structure matches expectations:
  - `block[0]` = size
  - `block[1]` = next pointer
  - `block[-2]` = previous block size (header)

---

## Memory Block Structure Expected Format

Based on code analysis, the DOS memory block structure is:

```
Offset -2 from block start: [previous_block_size] (header)
Offset 0: [block_size_flags] (LSB = 1 if allocated, 0 if free)
Offset 4: [next_block_pointer] (pointer to next block, or 0xFFFF for end)
Offset 8+: [block_data...]
```

**Example:**
```
Memory Pool:
0x0FFE: [0x0100] (previous block size, or header)
0x1000: [0x0100] (block size, LSB=0 = free)
0x1004: [0x1100] (next block pointer, or 0xFFFF)
0x1008: [data...]
```

## Critical Fixes Needed

### Priority 1: Type Mismatches
1. `resize_memory_block()` line 10065: Fix pointer vs constant comparison
2. `merge_memory_blocks()` lines 10171-10173: Convert pointer comparisons to offset comparisons

### Priority 2: Uninitialized Variables
1. `merge_memory_blocks()`: Initialize `dx_register` and `extraout_DX` from appropriate memory locations
2. `allocate_memory_with_split()`: Properly initialize `allocation_result` and `zero_flag`

### Priority 3: Logic Errors
1. `merge_memory_blocks()` line 10152: Fix block size comparison
2. `allocate_memory_with_split()` line 9955: Don't call `initialize_memory_allocator()` if already initialized
3. `find_memory_block()`: Initialize `search_size` to reasonable value

### Priority 4: Memory Block Structure
1. Ensure test initialization matches expected block structure exactly
2. Verify all block header fields are correctly initialized

## Next Steps

1. Fix type mismatches (Priority 1)
2. Initialize missing variables (Priority 2)
3. Fix logic errors (Priority 3)
4. Re-test all functions
5. Update memory initialization if needed (Priority 4)
