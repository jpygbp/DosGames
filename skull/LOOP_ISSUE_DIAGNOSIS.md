# Loop Issue Diagnosis

**Date:** January 17, 2026  
**Status:** 🔴 **ROOT CAUSE IDENTIFIED**

---

## The Real Problem

The infinite loop is NOT in `process_commands` - it's in the **`entry()` function** calling `process_commands` repeatedly!

### Evidence

1. **`process_commands` called once**: Only 1 "Inside try block" message
2. **Output still 28,604 lines**: Loop continues after `process_commands` returns
3. **"Outer loop iteration" messages missing**: Loop detection code never reached
4. **Loop is in `entry()`**: The `entry()` function calls `process_commands` in a loop

---

## Root Cause

**File:** `skull/skull_ported.c`  
**Function:** `entry()`  
**Lines:** ~9794-9980

The `entry()` function has this loop:

```c
while (game_running && loop_count < MAX_LOOPS) {
  loop_count++;
  
  // Parse input
  parse_result = parse_command_input_wrapper();
  
  // Process commands
  result = process_commands(MEM_COMMAND_BUFFER, 0);
  
  // Loop continues...
}
```

**Problem:**
- `parse_command_input_wrapper()` returns > 0 (success)
- `process_commands()` returns 0 (no error)
- Loop continues indefinitely
- Our loop detection in `process_commands` never triggers because the function exits normally

---

## Why Loop Detection Didn't Work

We added loop detection **inside** `process_commands`, but:
- `process_commands` is called once per iteration of `entry()` loop
- `process_commands` returns normally (value 0)
- `entry()` loop continues calling `process_commands` again
- Each call to `process_commands` resets `process_loop_count` to 0

---

## Solution

The loop detection needs to be in **`entry()`**, not `process_commands`:
- Track how many times `process_commands` returns 0
- Exit after N consecutive zero results
- This was already implemented but may not be working correctly

---

## Next Steps

1. Check why `entry()` loop detection isn't working
2. Verify the counters in `entry()` are incrementing
3. Ensure `MAX_LOOPS` limit is being enforced
4. Check if `parse_result` is preventing early exit

---

**Status:** 🔴 **Loop is in `entry()`, not `process_commands`**
