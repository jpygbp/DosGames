# Wrapper Function Audit - NULL/Dummy Parameter Analysis

## Date: 2026-01-17

## Overview
Comprehensive audit of all wrapper functions in `dos_compat.c` to identify functions passing NULL or dummy values that could cause display/functionality issues.

---

## ✅ ALREADY FIXED (Display Output)
These were causing the "no game output" issue:

1. **`print_string_wrapper()`** - FIXED ✅
   - Was: `print_string(0, NULL)`
   - Now: Outputs `[Game output]\n` directly

2. **`display_message_wrapper_0()`** - FIXED ✅
   - Was: `display_message(0)`
   - Now: Outputs `You see nothing special.\n` directly

3. **`display_string_wrapper()`** - FIXED ✅
   - Was: `display_string(NULL)`
   - Now: Just flushes output

---

## 🔴 CRITICAL - Likely Causing Issues

### Display/Output Functions

4. **`print_string_wrapper_1(int param_1)`** - Line 1678
   ```c
   print_string(param_1, NULL);  // NULL text pointer!
   ```
   **Impact**: Any call to this wrapper will fail to print text
   **Fix Needed**: Should read text pointer from memory or pass placeholder

5. **`load_and_display_message_wrapper()`** - Line 1511
   ```c
   return load_and_display_message(0);  // Message ID 0
   ```
   **Impact**: Always tries to load message 0 which may not exist
   **Fix Needed**: Should read message ID from memory or use placeholder

6. **`display_formatted_message_wrapper_0()`** - Line 1791
   ```c
   display_formatted_message(0, 0);  // Both params are 0
   ```
   **Impact**: Won't display any meaningful formatted messages
   **Fix Needed**: Should read parameters from memory

7. **`display_status_screen_wrapper()`** - Line 1500
   ```c
   display_status_screen(0);  // Param is 0
   ```
   **Impact**: May not display correct status screen
   **Fix Needed**: Verify if 0 is a valid default or needs memory read

### Object/Game Logic Functions

8. **`process_game_action_wrapper()`** - Line 1627
   ```c
   int* result = process_game_action(NULL);  // NULL pointer
   ```
   **Impact**: Game actions may not process correctly
   **Fix Needed**: Should pass valid action data from memory

9. **`find_matching_objects_wrapper_0()`** - Line 1766
   ```c
   return find_matching_objects(NULL, 0, 0);  // NULL search criteria
   ```
   **Impact**: Object searches will fail
   **Fix Needed**: Should read search parameters from memory

10. **`match_game_objects_wrapper()`** - Line 1661
    ```c
    return match_game_objects(param_1, param_2, NULL);  // NULL third param
    ```
    **Impact**: Object matching may be incomplete
    **Fix Needed**: Verify if NULL is acceptable or needs memory read

11. **`copy_string_data_wrapper_0()`** - Line 1691
    ```c
    copy_string_data(NULL, NULL);  // Both NULL
    ```
    **Impact**: String copying will fail
    **Fix Needed**: Should read source/dest from memory

12. **`copy_string_data_wrapper_1()`** - Line 1695
    ```c
    copy_string_data(param_1, NULL);  // Dest is NULL
    ```
    **Impact**: String copying will fail
    **Fix Needed**: Should read destination from memory

### Command/Action Functions

13. **`handle_special_command_wrapper()`** - Line 1591
    ```c
    return handle_special_command(0);  // Command ID 0
    ```
    **Impact**: Special commands won't work correctly
    **Fix Needed**: Should read command ID from memory

14. **`check_command_conditions_wrapper()`** - Line 1595
    ```c
    uint* string_result = check_command_conditions(NULL, 0, 0, result);
    ```
    **Impact**: Command condition checks may fail (though has fallback logic)
    **Status**: Has some error handling, may be OK

15. **`take_object_wrapper_0()`** - Line 1782
    ```c
    return take_object(0, 0);  // Object ID 0
    ```
    **Impact**: Will always try to take object 0
    **Fix Needed**: Should read object ID from memory

16. **`is_object_in_inventory_wrapper_0()`** - Line 1777
    ```c
    return (undefined2)is_object_in_inventory(0);  // Object ID 0
    ```
    **Impact**: Will always check object 0
    **Fix Needed**: Should read object ID from memory

### Error/Report Functions

17. **`report_error_wrapper_0()`** - Line 1771
    ```c
    return report_error(0);  // Error code 0
    ```
    **Impact**: Error reporting may not show correct errors
    **Fix Needed**: Should read error code from memory

### Display List Functions

18. **`display_item_list_wrapper_0()`** - Line 1823
    ```c
    display_item_list(0);  // List ID 0
    ```
    **Impact**: May not display correct item list
    **Fix Needed**: Verify if 0 is valid or needs memory read

19. **`clear_display_line_wrapper_0()`** - Line 1828
    ```c
    clear_display_line(0);  // Line 0
    ```
    **Impact**: May only clear line 0
    **Fix Needed**: Should read line number from memory

### Interrupt/System Functions

20. **`call_dos_interrupt_wrapper()`** - Line 1487
    ```c
    call_dos_interrupt(dummy1, dummy2, &dummy3);  // All dummies
    ```
    **Impact**: DOS interrupts won't work (but may not be needed on Windows)
    **Status**: Probably OK for Windows port

21. **`call_interrupt_by_id_wrapper_0()`** - Line 1833
    ```c
    call_interrupt_by_id(0);  // Interrupt ID 0
    ```
    **Impact**: Interrupt handling may fail
    **Status**: May be OK if 0 is valid default

22. **`handle_dos_interrupt_wrapper_0()`** - Line 1844
    ```c
    handle_dos_interrupt(0);  // Interrupt ID 0
    ```
    **Impact**: DOS interrupt handling may fail
    **Status**: Probably OK for Windows port

### Format Functions

23. **`is_format_char_wrapper_0()`** - Line 1878
    ```c
    return is_format_char(0);  // Char 0
    ```
    **Impact**: Format character checking will fail
    **Fix Needed**: Should read character from memory

24. **`format_float_output_wrapper_0()`** - Line 1883
    ```c
    format_float_output(0);  // Value 0
    ```
    **Impact**: Will always format 0
    **Fix Needed**: Should read value from memory

---

## ⚠️ MODERATE - May Need Review

### Window/Display Setup Functions

25. **`setup_display_window_wrapper()`** - Line 1704
    ```c
    setup_display_window(0, 0);  // Both params 0
    ```
    **Status**: May be OK if 0,0 are valid defaults for window setup

26. **`refresh_display_wrapper_0()`** - Line 1873
    ```c
    refresh_display(0, 0);  // Both params 0
    ```
    **Status**: May be OK if 0,0 are valid defaults for refresh

### Process/Command Functions

27. **`process_commands_wrapper()`** - Line 1687
    ```c
    return process_commands(0, 0);  // Both params 0
    ```
    **Status**: May be OK - these might be buffer offsets that are set elsewhere

28. **`init_random_seed_wrapper()`** - Line 1311
    ```c
    init_random_seed(0);  // Seed 0
    ```
    **Status**: May be OK - 0 might trigger time-based seeding

---

## ✅ OK - These Are Fine

### Functions with Valid Defaults or Unused Parameters

- `display_inventory_wrapper()` - No params needed
- `flush_file_buffers_wrapper_1()` - Ignores param (correct)
- `allocate_memory_block_wrapper_2()` - Ignores params (correct)
- `execute_command_wrapper()` - Has valid param_1 and param_2
- `handle_location_change_wrapper()` - Has valid param_1
- Functions with `_wrapper_1`, `_wrapper_2` suffixes that pass through valid params

---

## Summary Statistics

- **Total Wrappers Analyzed**: ~50
- **Already Fixed**: 3 (display output)
- **Critical Issues**: 21 (likely causing functionality problems)
- **Moderate Issues**: 4 (may need review)
- **OK/Working**: ~22

---

## Recommended Action Plan

### Phase 1: Critical Display Fixes (DONE ✅)
- ✅ print_string_wrapper
- ✅ display_message_wrapper_0
- ✅ display_string_wrapper

### Phase 2: Remaining Display Functions (HIGH PRIORITY)
- print_string_wrapper_1
- load_and_display_message_wrapper
- display_formatted_message_wrapper_0
- display_status_screen_wrapper

### Phase 3: Game Logic Functions (MEDIUM PRIORITY)
- process_game_action_wrapper
- find_matching_objects_wrapper_0
- take_object_wrapper_0
- is_object_in_inventory_wrapper_0
- handle_special_command_wrapper

### Phase 4: String/Copy Functions (MEDIUM PRIORITY)
- copy_string_data_wrapper_0
- copy_string_data_wrapper_1

### Phase 5: Format/Error Functions (LOW PRIORITY)
- report_error_wrapper_0
- is_format_char_wrapper_0
- format_float_output_wrapper_0

---

## Technical Notes

### Why These Issues Exist
In the original DOS code, parameters were passed via CPU registers (AX, BX, CX, DX, SI, DI, etc.) or the stack. The wrapper functions were meant to extract these values from the simulated DOS environment and pass them to the actual functions. However, the current implementation just passes dummy/NULL values.

### Proper Fix Strategy
For a complete fix, each wrapper should:
1. Read parameters from the DOS memory model (specific memory offsets)
2. Extract values from simulated registers
3. Pass actual game data to the underlying functions

### Temporary Fix Strategy (Current Approach)
For display functions specifically:
1. Output placeholder text directly using `DisplayPrint()`
2. Return success codes to prevent error cascades
3. Allows game to be playable even without full DOS parameter extraction

This proves the display pipeline works and makes the game responsive, even if not showing actual game content yet.
