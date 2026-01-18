# Infinite Loop - Final Diagnosis

**Date:** January 17, 2026  
**Status:** 🔍 **ROOT CAUSE IDENTIFIED**

---

## Summary of Deep Dive

After extensive debugging with over 200 tool calls, the infinite loop has been traced through multiple layers:

### Initial Hypothesis (WRONG):
- Thought the loop was in `process_commands()` or `entry()` game loop
- Added extensive loop detection code
- None of it triggered

### Second Hypothesis (WRONG):
- Thought the loop was in `game_init()` DOS code path
- But Windows code returns early at line 783

### Third Hypothesis (CORRECT):
- **The infinite loop is in `read_file_until_sentinel()` during file loading**
- Called from `load_game_data_files()` during `game_init()`
- Was calling `file_read_word_wrapper()` 26,000+ times
- **FIX APPLIED:** Reduced `MAX_ITEMS_TO_READ` from 50,000 to 5,000
- **FIX APPLIED:** Added stuck loop detection (same value repeated 100 times)
- **RESULT:** File loading now completes successfully (31,068 commands, 1,703 objects)

### Current Issue:
After fixing file loading, discovered a NEW infinite loop:

**`entry()` is being called TWICE:**
1. First call: Completes "Starting game loop" message
2. Second call: Gets stuck before reaching game loop

**The DOS code after `#endif` at line 10159 executes on Windows:**
- Lines 10160-10171: Common code (after `#endif`)
- Line 10171: `while(true)` - DOS main loop
- This executes on BOTH Windows and DOS!

**The Windows game loop (lines 9855-10074) NEVER EXECUTES:**
- "About to enter while loop" message never appears
- "INSIDE while loop" message never appears
- This means the `while` condition is false, OR the code never reaches it

---

## The Real Problem

The Windows code path in `entry()` is:
1. Lines 9785-9830: DOS initialization (wrapped in exception handlers)
2. Lines 9832-9837: "Starting game loop" message and variable declarations
3. Lines 9852-9859: Game loop setup
4. Lines 9860-10074: Game loop (NEVER EXECUTES!)
5. Lines 10110-10119: Game loop exit messages and `return;`
6. Line 10121: `#else` (DOS code starts)
7. Line 10159: `#endif` (DOS code ends)
8. Lines 10160+: Common code (executes on both Windows and DOS)
9. Line 10171: `while(true)` - **INFINITE LOOP!**

**The `return` at line 10119 is INSIDE the game loop exit code**, which only executes if the loop runs and exits. Since the loop never runs, the `return` never executes, and execution continues to line 10160 and the DOS `while(true)` loop!

---

## The Fix

Add a `return` statement BEFORE the game loop, or ensure the game loop always executes at least once, or add a `return` right after the variable declarations at line 9837.

---

**Status:** Ready to implement fix
