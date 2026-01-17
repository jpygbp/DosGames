# Deep Dive Testing Plan for `save_display_state()`

## Function Overview

`save_display_state()` is a display management function that:
1. Saves display buffer state to memory
2. Handles video buffer pixel operations
3. Manages stack pointer operations for display context switching

## Memory Locations Required

### Primary Memory Accesses

1. **MEM_POINTER_STORAGE_245** (line 12381)
   - Used to initialize `stack_value`
   - Needs: Valid uint16_t value

2. **MEM_BUFFER_STORAGE** (lines 12384, 12446)
   - Condition: `< 3` for first path
   - Condition: `< 3` for final stack_ptr write
   - Needs: Valid uint32_t value (0, 1, 2, or >= 3)

3. **MEM_DISPLAY_STRING_7** (lines 12386, 12392)
   - Read as offset for stack pointer initialization
   - Written with `MEM_POINTER_STORAGE_258` value
   - Needs: Valid offset within memory pool bounds

4. **MEM_DISPLAY_STRING_2** (lines 12389, 12393)
   - Read as value for stack_value
   - Written with `unaff_DS` value
   - Needs: Valid uint32_t value

5. **MEM_POINTER_STORAGE_258** (line 12392)
   - Written to `MEM_DISPLAY_STRING_7`
   - Needs: Valid offset within memory pool bounds

6. **MEM_POINTER_STORAGE_20** (line 12399)
   - Condition: `== OFFSET_PARAM_13`
   - Needs: Valid uint32_t value (0x0D or OFFSET_PARAM_13)

7. **MEM_FUNCTION_PTR_3** (line 12402)
   - Function pointer that may be called
   - Needs: NULL (safe) or valid function pointer

8. **MEM_POINTER_STORAGE_119** (line 12407)
   - Used as `xor_value` for pixel operations
   - Needs: Valid byte value (0-255)

9. **MEM_SPECIAL_ADDR_2** (line 12408)
   - Used as `buffer_address` for pixel buffer operations
   - Needs: Valid offset within memory pool, large enough for 8 * 160 * sizeof(uint) bytes

10. **stack_ptr** (lines 12391, 12449-12451)
    - Pointer derived from `MEM_DISPLAY_STRING_7` offset
    - Needs: Valid pointer within memory pool bounds
    - Must have at least 2 * sizeof(undefined2) bytes available

11. **unaff_ES** and **in_stack_00000000** (lines 12450-12451)
    - Values written to stack_ptr[0] and stack_ptr[1]
    - Needs: Valid undefined2 values

### Secondary Memory Accesses (via call_video_bios)

12. **call_video_bios()** (line 12382)
    - May access additional memory locations
    - Currently returns early on Windows (no-op)

### Pixel Buffer Operations (if buffer_address is valid)

13. **Buffer at buffer_address** (lines 12416-12436)
    - Size needed: `8 * 160 * sizeof(uint)` = 5120 bytes (if uint is 4 bytes)
    - Access pattern: 8 outer loops, 4 inner loops, then advance by VALUE_157
    - Needs: Large contiguous buffer within memory pool

## Test Categories for Deep Dive

### Category 1: Basic Functionality Tests
- Test with minimal initialization (only required memory)
- Test with `MEM_BUFFER_STORAGE = 0` (first path)
- Test with `MEM_BUFFER_STORAGE = 1` (first path)
- Test with `MEM_BUFFER_STORAGE = 2` (first path)
- Test with `MEM_BUFFER_STORAGE = 3` (second path, no stack_ptr)
- Test with `MEM_BUFFER_STORAGE >= 3` and `MEM_POINTER_STORAGE_20 == OFFSET_PARAM_13` (pixel operations path)

### Category 2: MEM_BUFFER_STORAGE Boundary Tests
- Test all values: 0, 1, 2, 3, 4, 5, 255, 256, 0xFFFFFFFF
- Verify correct code path is taken for each value

### Category 3: MEM_DISPLAY_STRING_7 Offset Tests
- Test with valid offsets within bounds
- Test with offset = 0
- Test with offset near memory pool boundary
- Test with invalid offsets (>= memory_pool_size)
- Test with offset that leaves insufficient space for stack operations

### Category 4: stack_ptr Initialization Tests
- Test when `MEM_DISPLAY_STRING_7` contains valid offset
- Test when `MEM_DISPLAY_STRING_7` contains invalid offset
- Test when `MEM_DISPLAY_STRING_7` offset + sizeof(uint16_t) exceeds bounds
- Verify stack_ptr is NULL when initialization fails

### Category 5: Pixel Buffer Operations Tests (buffer_address path)
- Test with valid buffer_address (large enough buffer)
- Test with buffer_address = 0 (should exit early)
- Test with buffer_address >= memory_pool_size (should exit early)
- Test with buffer_address that doesn't have enough space for operations
- Test with various xor_value values
- Test buffer operations don't exceed bounds when advancing by VALUE_157

### Category 6: stack_ptr Write Tests (final check)
- Test when `MEM_BUFFER_STORAGE < 3` and stack_ptr is valid
- Test when `MEM_BUFFER_STORAGE < 3` and stack_ptr is NULL
- Test when `MEM_BUFFER_STORAGE >= 3` (should skip stack_ptr write)
- Test bounds checking for stack_ptr[0] and stack_ptr[1] writes

### Category 7: MEM_POINTER_STORAGE_20 Condition Tests
- Test when `MEM_POINTER_STORAGE_20 == OFFSET_PARAM_13` (pixel operations)
- Test when `MEM_POINTER_STORAGE_20 != OFFSET_PARAM_13` (skip pixel operations)
- Test with various values to ensure condition works correctly

### Category 8: Function Pointer Tests
- Test when `MEM_FUNCTION_PTR_3` is NULL (safe, should skip call)
- Test when `MEM_FUNCTION_PTR_3` points to valid function (if possible)
- Test bounds checking for function pointer access

### Category 9: Edge Case Tests
- Test with all memory locations set to 0
- Test with all memory locations set to maximum values
- Test with mixed valid/invalid memory states
- Test rapid successive calls to save_display_state

### Category 10: Integration Tests
- Test save_display_state called from display_end()
- Test save_display_state called from other display functions
- Test interaction with call_video_bios()

## Required Initialization Function

### `initialize_save_display_state_memory_for_testing()`

Must initialize:

```c
static void initialize_save_display_state_memory_for_testing(void) {
    if (g_gameState == NULL || g_gameState->memory_pool == NULL) {
        return;
    }
    
    /* Initialize MEM_BUFFER_STORAGE - controls code path */
    if (MEM_BUFFER_STORAGE + 4 <= g_gameState->memory_pool_size) {
        MEM_WRITE32(MEM_BUFFER_STORAGE, 0); /* Default: first path */
    }
    
    /* Initialize MEM_POINTER_STORAGE_245 for stack_value */
    if (MEM_POINTER_STORAGE_245 + 2 <= g_gameState->memory_pool_size) {
        MEM_WRITE16(MEM_POINTER_STORAGE_245, 0);
    }
    
    /* Initialize MEM_DISPLAY_STRING_7 with valid offset */
    if (MEM_DISPLAY_STRING_7 + 4 <= g_gameState->memory_pool_size) {
        uint32_t stack_buffer_offset = 0x5000; /* Safe offset */
        if (stack_buffer_offset + 16 <= g_gameState->memory_pool_size) {
            MEM_WRITE32(MEM_DISPLAY_STRING_7, stack_buffer_offset);
            /* Initialize stack buffer area */
            memset(g_gameState->memory_pool + stack_buffer_offset, 0, 16);
        }
    }
    
    /* Initialize MEM_DISPLAY_STRING_2 */
    if (MEM_DISPLAY_STRING_2 + 4 <= g_gameState->memory_pool_size) {
        MEM_WRITE32(MEM_DISPLAY_STRING_2, 0);
    }
    
    /* Initialize MEM_POINTER_STORAGE_258 */
    if (MEM_POINTER_STORAGE_258 + 4 <= g_gameState->memory_pool_size) {
        uint32_t alternate_stack_offset = 0x5100; /* Safe alternate offset */
        if (alternate_stack_offset + 16 <= g_gameState->memory_pool_size) {
            MEM_WRITE32(MEM_POINTER_STORAGE_258, alternate_stack_offset);
            memset(g_gameState->memory_pool + alternate_stack_offset, 0, 16);
        }
    }
    
    /* Initialize MEM_POINTER_STORAGE_20 */
    if (MEM_POINTER_STORAGE_20 + 4 <= g_gameState->memory_pool_size) {
        MEM_WRITE32(MEM_POINTER_STORAGE_20, 0); /* Not equal to OFFSET_PARAM_13 */
    }
    
    /* Initialize MEM_FUNCTION_PTR_3 to NULL (safe) */
    if (MEM_FUNCTION_PTR_3 + 4 <= g_gameState->memory_pool_size) {
        *(void **)(g_gameState->memory_pool + MEM_FUNCTION_PTR_3) = NULL;
    }
    
    /* Initialize MEM_POINTER_STORAGE_119 for xor_value */
    if (MEM_POINTER_STORAGE_119 + 1 <= g_gameState->memory_pool_size) {
        *(uint8_t *)(g_gameState->memory_pool + MEM_POINTER_STORAGE_119) = 0xAA; /* Example xor value */
    }
    
    /* Initialize MEM_SPECIAL_ADDR_2 with large buffer for pixel operations */
    if (MEM_SPECIAL_ADDR_2 + 4 <= g_gameState->memory_pool_size) {
        uint32_t pixel_buffer_offset = 0x6000; /* Large buffer area */
        uint32_t pixel_buffer_size = 8 * 160 * sizeof(uint); /* 5120 bytes */
        if (pixel_buffer_offset + pixel_buffer_size <= g_gameState->memory_pool_size) {
            MEM_WRITE32(MEM_SPECIAL_ADDR_2, pixel_buffer_offset);
            /* Initialize pixel buffer with test pattern */
            memset(g_gameState->memory_pool + pixel_buffer_offset, 0, pixel_buffer_size);
        } else {
            MEM_WRITE32(MEM_SPECIAL_ADDR_2, 0); /* Invalid - will skip pixel operations */
        }
    }
}
```

## Test Structure

Similar to Set 7 and Set 8 deep dive tests, create:

1. `test_save_display_state_deep_dive()` function
2. 10 test categories covering all scenarios
3. Each test wrapped in `__try/__except` for exception handling
4. Detailed logging of test results
5. Summary of pass/fail counts

## Expected Issues to Find

1. **Invalid buffer_address**: When `MEM_SPECIAL_ADDR_2` contains invalid offset
2. **Out of bounds stack_ptr**: When `MEM_DISPLAY_STRING_7` offset is invalid
3. **Buffer size insufficient**: When pixel buffer isn't large enough
4. **Uninitialized values**: When required memory locations aren't set
5. **Pointer arithmetic errors**: When advancing by VALUE_157 exceeds bounds

## Success Criteria

- All test categories execute without crashes
- Proper exception handling for invalid memory states
- Functions gracefully handle edge cases
- All memory accesses are bounds-checked
- No ACCESS_VIOLATION exceptions in properly initialized states
