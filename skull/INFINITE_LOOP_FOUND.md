# INFINITE LOOP - ROOT CAUSE FOUND!

**Date:** January 17, 2026  
**Status:** 🎯 **ROOT CAUSE IDENTIFIED**

---

## The Real Infinite Loop

### Location: `skull_ported.c` line 10155

```c
while( true ) {  // Line 10155 - INFINITE LOOP!
  MEM_WRITE16(...);
  flush_file_buffers();
  call_interrupt_by_id_wrapper_0();
  // ... more code ...
  if (MEM_READ32(MEM_INTERRUPT_LOOP_FLAG) == 0) break;  // Line 10178
  // ... more code ...
}
```

### The Problem

This `while(true)` loop at line 10155 is AFTER the `#endif` at line 10142, which means it executes on BOTH Windows AND DOS!

The loop is supposed to exit when `MEM_INTERRUPT_LOOP_FLAG == 0` (line 10178), but this flag is never being set to 0, so the loop runs forever!

### Why It Was Hard to Find

1. The Windows game loop code (lines 9832-10103) has a `return;` at line 10103
2. But there's a `#else` at line 10104 for DOS code
3. The `#endif` is at line 10142
4. Lines 10143-onwards are AFTER the `#endif`, so they execute on Windows!
5. Line 10155 has `while(true)` - the real infinite loop!

### Evidence

- "Starting game loop" appears (line 9834)
- "About to enter while loop" NEVER appears (line 9852)
- This means the code never reaches line 9852
- But it DOES reach line 9834
- So something between 9834-9852 is causing the issue
- Actually, the code at line 10103 returns, but then execution continues at line 10143!

### Wait... That Doesn't Make Sense!

If line 10103 has `return;`, then execution should stop there. Let me re-check the `#ifdef` structure...

Actually, looking at line 10104: `#else`, this means:
- Lines 9740-10103: Windows code (`#ifdef _WIN32`)
- Lines 10104-10142: DOS code (`#else`)
- Lines 10143+: Common code (after `#endif`)

So if we're on Windows, line 10103 `return;` should exit the function!

But the infinite loop is still happening... Let me check if the `return` is actually inside the `#ifdef`.

---

**Status:** Need to verify the exact `#ifdef` structure around line 10103
