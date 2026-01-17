# DOS Code Flow Fixes Summary

**Date:** 2026-01-08  
**Status:** Improvements Applied

## DOS Code Flow Issues Identified

### 1. Interrupt Handler NULL Checks
**Problem:** Many `swi()` calls return NULL on Windows but code was calling them directly  
**Fix:** Added NULL checks before calling interrupt handlers

### 2. File Handle Processing Loop
**Problem:** `process_file_handles_setup()` and other file handle loops access memory without bounds checking  
**Fix:** Added bounds validation for `file_index + MEM_POINTER_STORAGE` before accessing

### 3. Stack Pointer Validation
**Problem:** `stack_ptr_5 - 2` access without validation  
**Fix:** Added validation to ensure stack pointer is within memory pool

### 4. Uninitialized Register Values
**Problem:** `extraout_DX` used after interrupt handler without initialization  
**Fix:** Initialize `extraout_DX` to safe value (0) since interrupt handlers don't set it on Windows

## Functions Modified

1. **`process_file_handles_setup()`**
   - Added bounds checking for flags_offset
   - Added NULL check for interrupt_handler
   - Initialize extraout_DX to 0

2. **File handle loop in `setup_function_context()` (around line 5001)**
   - Added bounds checking for flags_offset
   - Added NULL check for interrupt_handler (already had it)
   - Initialize extraout_DX

3. **Stack pointer access**
   - Added validation for `stack_ptr_5 - 2` access

## Patterns Applied

### Interrupt Handler Pattern
```c
interrupt_handler = (code *)swi(DOS_INT_21H);
/* On Windows, swi returns NULL, so skip the call */
if (interrupt_handler != NULL) {
  (*interrupt_handler)();
}
```

### File Handle Bounds Check Pattern
```c
uint32_t flags_offset = file_index + MEM_POINTER_STORAGE;
if (flags_offset + sizeof(byte) <= g_gameState->memory_pool_size) {
  flags_byte_ptr = (byte *)(g_gameState->memory_pool + flags_offset);
  // ... use flags_byte_ptr ...
} else {
  log_warning("flags_offset (0x%x) out of bounds", flags_offset);
}
```

## Notes

- DOS interrupt handlers (`swi()`) return NULL on Windows - all calls must check for NULL
- File handle indices need bounds validation before memory access
- Stack pointers from DOS segment:offset addressing need validation
- Register values set by DOS interrupts need initialization defaults for Windows
