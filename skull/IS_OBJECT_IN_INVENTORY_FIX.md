# Fix for is_object_in_inventory() Function
**Date:** 2026-01-16  
**Issue:** Function returned false for objects that ARE in inventory  
**Status:** ✅ **FIXED** - All 6 tests now passing (100%)

## Problem Description

The `is_object_in_inventory()` function was failing for objects that were actually in the inventory (location 255). It correctly returned `false` for objects NOT in inventory, but incorrectly returned `false` for objects that WERE in inventory.

### Test Results Before Fix
- ❌ Test 1: is_object_in_inventory(5) = false (expected true) - object 5 in inventory
- ❌ Test 2: is_object_in_inventory(6) = false (expected true) - object 6 in inventory  
- ❌ Test 3: is_object_in_inventory(7) = false (expected true) - object 7 in inventory
- ✅ Test 4: is_object_in_inventory(0) = false - object 0 not in inventory
- ✅ Test 5: is_object_in_inventory(8) = false - object 8 not in inventory
- ✅ Test 6: is_object_in_inventory(99) = false - invalid object 99 not in inventory

**Pass Rate:** 50% (3/6 tests passing)

## Root Cause Analysis

### Issue 1: Missing Linked List Setup
The test initialization was creating objects at location 255 (inventory) but wasn't setting up the linked list structure. Each object has a `next_object` field (at offset +0) that should point to the next object in the list.

**Problem:** All objects had `next_object = 0`, so the list ended immediately after the first object.

### Issue 2: MEM_LOCATION_BUFFER Not Initialized
The function reads from `MEM_LOCATION_BUFFER` to get the first object in the inventory, but this was initialized to 0 instead of pointing to the first inventory object (object 5).

### Issue 3: Incorrect Pointer Arithmetic
The original code at line 6044 of `skull_ported.c`:
```c
next_object_id = *(byte *)(current_object_id * SIZE_OBJECT_ENTRY + MEM_READ32(MEM_BASE_POINTER));
```

This treated the calculated offset as an absolute memory address instead of an offset into `g_gameState->memory_pool`. This caused ACCESS_VIOLATION exceptions when traversing the linked list.

## Solutions Applied

### Fix 1: Set Up Linked List in Test Initialization
Added code to `initialize_set_13_memory_for_testing()` in `test_functions.c` to create a proper linked list for inventory objects:

```c
/* Set up linked lists for objects at each location */
/* Objects 5-7 are in inventory (location 255) - create linked list: 5 -> 6 -> 7 -> 0 */
uint32_t obj5_offset = base_ptr + (5 * SIZE_OBJECT_ENTRY);
uint32_t obj6_offset = base_ptr + (6 * SIZE_OBJECT_ENTRY);
uint32_t obj7_offset = base_ptr + (7 * SIZE_OBJECT_ENTRY);
if (obj5_offset < g_gameState->memory_pool_size && 
    obj6_offset < g_gameState->memory_pool_size &&
    obj7_offset < g_gameState->memory_pool_size) {
    g_gameState->memory_pool[obj5_offset + 0] = 6; /* Object 5 points to object 6 */
    g_gameState->memory_pool[obj6_offset + 0] = 7; /* Object 6 points to object 7 */
    g_gameState->memory_pool[obj7_offset + 0] = 0; /* Object 7 is end of list */
}
```

### Fix 2: Initialize MEM_LOCATION_BUFFER
Added code to set `MEM_LOCATION_BUFFER` to point to the first inventory object:

```c
/* Set MEM_LOCATION_BUFFER to point to first object in inventory (object 5) */
if (MEM_LOCATION_BUFFER + 4 <= g_gameState->memory_pool_size) {
    MEM_WRITE32(MEM_LOCATION_BUFFER, 5); /* First object in inventory is object 5 */
}
```

### Fix 3: Correct Pointer Arithmetic
Fixed the pointer arithmetic in `is_object_in_inventory()` in `skull_ported.c` to use the memory pool:

**Before:**
```c
while ((current_object_id = (uint)next_object_id, current_object_id != 0 && (not_found = current_object_id != object_id, not_found))) {
    next_object_id = *(byte *)(current_object_id * SIZE_OBJECT_ENTRY + MEM_READ32(MEM_BASE_POINTER));
}
```

**After:**
```c
while ((current_object_id = (uint)next_object_id, current_object_id != 0 && (not_found = current_object_id != object_id, not_found))) {
    /* Fixed: Use memory pool instead of absolute address */
    uint32_t object_offset = current_object_id * SIZE_OBJECT_ENTRY + MEM_READ32(MEM_BASE_POINTER);
    if (object_offset < g_gameState->memory_pool_size) {
      next_object_id = g_gameState->memory_pool[object_offset];
    } else {
      next_object_id = 0; /* End of list if out of bounds */
    }
}
```

## Test Results After Fix

✅ **All 6 tests now passing (100%)**

- ✅ Test 1: is_object_in_inventory(5) = true - object 5 in inventory (location 255)
- ✅ Test 2: is_object_in_inventory(6) = true - object 6 in inventory (location 255)
- ✅ Test 3: is_object_in_inventory(7) = true - object 7 in inventory (location 255)
- ✅ Test 4: is_object_in_inventory(0) = false - object 0 not in inventory (at location 0)
- ✅ Test 5: is_object_in_inventory(8) = false - object 8 not in inventory (at location 1)
- ✅ Test 6: is_object_in_inventory(99) = false - invalid object 99 not in inventory

**Pass Rate:** 100% (6/6 tests passing) ✅

## Impact on Set 13

### Before Fix
- **Set 13 Pass Rate:** 15.7% (8/51 tests)
- **is_object_in_inventory:** 50% (3/6 tests)

### After Fix
- **Set 13 Pass Rate:** 21.6% (11/51 tests) - **+5.9% improvement**
- **is_object_in_inventory:** 100% (6/6 tests) ✅ **COMPLETE!**

## Files Modified

1. **`skull/test_functions.c`**
   - Added linked list setup for inventory objects (objects 5-7)
   - Initialized `MEM_LOCATION_BUFFER` to point to first inventory object
   - Changes in `initialize_set_13_memory_for_testing()` function

2. **`skull/skull_ported.c`**
   - Fixed pointer arithmetic in `is_object_in_inventory()` function
   - Changed from absolute address to memory pool offset
   - Added bounds checking for safety

## Lessons Learned

1. **Linked Lists Need Explicit Setup:** Object linked lists must be explicitly initialized with proper `next_object` pointers, not just location assignments.

2. **Memory Pool vs Absolute Addresses:** Ported DOS code often treats offsets as absolute addresses. These must be converted to use `g_gameState->memory_pool` on Windows.

3. **Bounds Checking is Essential:** Always add bounds checking when accessing memory pool to prevent ACCESS_VIOLATION exceptions.

4. **Test Initialization Matters:** Comprehensive test initialization (including linked list structures) is crucial for testing functions that traverse data structures.

## Related Issues

This fix may help with other Set 13 functions that also traverse object linked lists:
- `take_object()` - Uses similar linked list traversal
- `drop_object()` - Uses similar linked list traversal
- `add_object_to_list()` - Modifies linked lists
- `move_object_between_locations()` - Moves objects between lists

These functions may benefit from similar pointer arithmetic fixes.

## Conclusion

The `is_object_in_inventory()` function is now fully working with 100% test pass rate. The fix involved three components:
1. Proper linked list initialization in tests
2. Correct initialization of `MEM_LOCATION_BUFFER`
3. Fixed pointer arithmetic to use memory pool instead of absolute addresses

This demonstrates the importance of both correct test setup and proper memory access patterns in ported DOS code.
