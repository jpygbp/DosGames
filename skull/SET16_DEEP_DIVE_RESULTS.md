# Set 16 Deep Dive Test Results
## Interrupt and System Functions
**Date:** 2026-01-16  
**Test Suite:** Deep Dive Comprehensive Testing  
**Total Tests:** 60  
**Tests Passed:** 26  
**Tests Failed:** 34  
**Pass Rate:** 43.3%

---

## Executive Summary

Set 16 (Interrupt and System Functions) achieved a **43.3% pass rate** (26/60 tests) in comprehensive deep dive testing. The results show:

✅ **3 functions working perfectly** (100% pass rate):
- `call_interrupt_handlers()` - 5/5 tests passing
- `call_interrupt_handlers_pair()` - 5/5 tests passing
- `print_string()` - 8/8 tests passing
- `clear_display_line()` - 5/5 tests passing

⚠️ **1 function partially working**:
- `setup_display_window()` - 3/6 tests passing (50% - fails when reset_cursor=1)

❌ **5 functions failing completely** (0% pass rate):
- `display_error()` - 0/8 tests passing
- `handle_dos_interrupt()` - 0/5 tests passing
- `call_dos_interrupt()` - 0/6 tests passing
- `refresh_display()` - 0/5 tests passing
- `update_display_mode()` - 0/7 tests passing

---

## Detailed Results by Category

### Category 1: call_interrupt_handlers() ✅
**Status:** 100% PASSING (5/5 tests)  
**Function:** Call interrupt handlers

All tests passed successfully with various stack pointer initializations.

```
[1/5] PASS: call_interrupt_handlers() - test 1
[2/5] PASS: call_interrupt_handlers() - test 2
[3/5] PASS: call_interrupt_handlers() - test 3
[4/5] PASS: call_interrupt_handlers() - test 4
[5/5] PASS: call_interrupt_handlers() - test 5
```

---

### Category 2: call_interrupt_handlers_pair() ✅
**Status:** 100% PASSING (5/5 tests)  
**Function:** Call interrupt handlers pair

All tests passed successfully with various stack pointer configurations.

```
[1/5] PASS: call_interrupt_handlers_pair() - test 1
[2/5] PASS: call_interrupt_handlers_pair() - test 2
[3/5] PASS: call_interrupt_handlers_pair() - test 3
[4/5] PASS: call_interrupt_handlers_pair() - test 4
[5/5] PASS: call_interrupt_handlers_pair() - test 5
```

---

### Category 3: display_error() ❌
**Status:** 0% PASSING (0/8 tests)  
**Function:** Display error

All tests failed with `ACCESS_VIOLATION` (0xC0000005) exceptions. The function was enhanced on 2026-01-10 with validation helpers and improved exception handling, but the underlying memory access issues persist.

**Root Cause:** The error chain shows:
1. `display_error()` calls `report_error()`
2. `report_error()` calls `format_string_printf()`
3. `format_string_printf()` throws `ACCESS_VIOLATION` at line 10960
4. `setup_function_context()` also fails with `ACCESS_VIOLATION` in `process_file_handles_setup()` at line 8619

```
[1/8] FAIL: display_error(0) - Exception 0xc0000005
[2/8] FAIL: display_error(1) - Exception 0xc0000005
[3/8] FAIL: display_error(5) - Exception 0xc0000005
[4/8] FAIL: display_error(10) - Exception 0xc0000005
[5/8] FAIL: display_error(-1) - Exception 0xc0000005
[6/8] FAIL: display_error(127) - Exception 0xc0000005
[7/8] FAIL: display_error(-128) - Exception 0xc0000005
[8/8] FAIL: display_error(-2) - Exception 0xc0000005
```

**Error Log Sample:**
```
[ERROR] process_file_handles_setup: file handle processing: Exception 0xC0000005 at skull_ported.c:8619
[ERROR] setup_function_context_wrapper: setup_function_context: Exception 0xC0000005 at dos_compat.c:1254
[ERROR] format_string_printf: Exception 0xC0000005 at skull_ported.c:10960
[ERROR] report_error: format_string_printf: Exception 0xC0000005 at skull_ported.c:10114
```

---

### Category 4: handle_dos_interrupt() ❌
**Status:** 0% PASSING (0/5 tests)  
**Function:** Handle DOS interrupt

All tests failed with `ACCESS_VIOLATION` exceptions across various interrupt IDs (0x00, 0x10, 0x21, 0xFC, 0xFF).

```
[1/5] FAIL: handle_dos_interrupt(0x0) - Exception 0xc0000005
[2/5] FAIL: handle_dos_interrupt(0x10) - Exception 0xc0000005
[3/5] FAIL: handle_dos_interrupt(0x21) - Exception 0xc0000005
[4/5] FAIL: handle_dos_interrupt(0xfc) - Exception 0xc0000005
[5/5] FAIL: handle_dos_interrupt(0xff) - Exception 0xc0000005
```

---

### Category 5: call_dos_interrupt() ❌
**Status:** 0% PASSING (0/6 tests)  
**Function:** Call DOS interrupt

All tests failed with `ACCESS_VIOLATION` exceptions, regardless of interrupt ID or register pointer configuration.

```
[1/6] FAIL: call_dos_interrupt() - interrupt 0 with null regs - Exception 0xc0000005
[2/6] FAIL: call_dos_interrupt() - video interrupt with null regs - Exception 0xc0000005
[3/6] FAIL: call_dos_interrupt() - DOS interrupt with null regs - Exception 0xc0000005
[4/6] FAIL: call_dos_interrupt() - interrupt 0 with regs offset - Exception 0xc0000005
[5/6] FAIL: call_dos_interrupt() - video interrupt with regs offset - Exception 0xc0000005
[6/6] FAIL: call_dos_interrupt() - DOS interrupt with regs offset - Exception 0xc0000005
```

---

### Category 6: refresh_display() ❌
**Status:** 0% PASSING (0/5 tests)  
**Function:** Refresh display

All tests failed with `ACCESS_VIOLATION` exceptions. NULL checks were added to all `swi()` interrupt handler calls (4 locations), but the underlying issues remain.

```
[1/5] FAIL: refresh_display(0, 0) - Exception 0xc0000005
[2/5] FAIL: refresh_display(1, 1) - Exception 0xc0000005
[3/5] FAIL: refresh_display(2, 2) - Exception 0xc0000005
[4/5] FAIL: refresh_display(3, 3) - Exception 0xc0000005
[5/5] FAIL: refresh_display(4, 4) - Exception 0xc0000005
```

---

### Category 7: update_display_mode() ❌
**Status:** 0% PASSING (0/7 tests)  
**Function:** Update display mode

All tests failed with `ACCESS_VIOLATION` exceptions across various display modes (0, 1, 2, 3, 7, 0xD, 0x13).

```
[1/7] FAIL: update_display_mode(0) - Exception 0xc0000005
[2/7] FAIL: update_display_mode(1) - Exception 0xc0000005
[3/7] FAIL: update_display_mode(2) - Exception 0xc0000005
[4/7] FAIL: update_display_mode(3) - Exception 0xc0000005
[5/7] FAIL: update_display_mode(7) - Exception 0xc0000005
[6/7] FAIL: update_display_mode(13) - Exception 0xc0000005
[7/7] FAIL: update_display_mode(19) - Exception 0xc0000005
```

---

### Category 8: setup_display_window() ⚠️
**Status:** 50% PASSING (3/6 tests)  
**Function:** Setup display window

**Pattern:** Tests pass when `reset_cursor=0` but fail when `reset_cursor=1`.

```
[1/6] PASS: setup_display_window() - window 0, no reset
[2/6] FAIL: setup_display_window() - window 0, reset cursor - Exception 0xc0000005
[3/6] PASS: setup_display_window() - window 1, no reset
[4/6] FAIL: setup_display_window() - window 1, reset cursor - Exception 0xc0000005
[5/6] PASS: setup_display_window() - window 2, no reset
[6/6] FAIL: setup_display_window() - window 3, reset cursor - Exception 0xc0000005
```

**Analysis:** The cursor reset functionality has memory access issues that need investigation.

---

### Category 9: print_string() ✅
**Status:** 100% PASSING (8/8 tests)  
**Function:** Print string

All tests passed successfully with various string types (normal, empty, special characters, multi-line).

```
[1/8] PASS: print_string(0, "Test")
[2/8] PASS: print_string(0, "Hello")
[3/8] PASS: print_string(0, "A")
[4/8] PASS: print_string(0, "long string")
[5/8] PASS: print_string(0, "")
[6/8] PASS: print_string(0, "123")
[7/8] PASS: print_string(0, "Special: @#$")
[8/8] PASS: print_string(0, "Multi\nLine")
```

**Note:** One warning was logged during testing:
```
[WARN] print_string: text pointer 00000000000004C1 is outside memory pool
```
However, the function handled this gracefully and all tests passed.

---

### Category 10: clear_display_line() ✅
**Status:** 100% PASSING (5/5 tests)  
**Function:** Clear display line

All tests passed successfully across various window IDs (0-4).

```
[1/5] PASS: clear_display_line(0)
[2/5] PASS: clear_display_line(1)
[3/5] PASS: clear_display_line(2)
[4/5] PASS: clear_display_line(3)
[5/5] PASS: clear_display_line(4)
```

---

## Common Failure Patterns

### 1. setup_function_context() Chain Failures
**Frequency:** Appears in almost every failing test  
**Location:** `skull_ported.c:8619` in `process_file_handles_setup()`  
**Exception:** `ACCESS_VIOLATION (0xC0000005)`

This is a recurring issue identified in Set 17's static function testing. The `setup_function_context()` function and its helper `process_file_handles_setup()` have fundamental memory access problems that cascade to many other functions.

**Error Chain:**
```
setup_function_context: Entered function
setup_function_context: Reached LAB_1000_3d0c
setup_function_context: After environment processing, starting file handle loop
[ERROR] process_file_handles_setup: file handle processing: Exception 0xC0000005 at skull_ported.c:8619
[ERROR] setup_function_context_wrapper: setup_function_context: Exception 0xC0000005 at dos_compat.c:1254
```

### 2. format_string_printf() Failures
**Frequency:** Appears in `display_error()` tests  
**Location:** `skull_ported.c:10960`  
**Exception:** `ACCESS_VIOLATION (0xC0000005)`

The string formatting function has memory access issues that prevent error display functionality from working.

### 3. File Handle Issues
**Frequency:** Occasional  
**Errors:**
```
[ERROR] file_open_wrapper: File index 6 out of range
[ERROR] load_game_data_files: Exception 0xC0000005 at skull_ported.c:611
[ERROR] file_open_read: Invalid filename pointer offset 0x0
```

---

## Function Status Summary

| Function | Tests | Passed | Failed | Pass Rate | Status |
|----------|-------|--------|--------|-----------|--------|
| `call_interrupt_handlers()` | 5 | 5 | 0 | 100% | ✅ Working |
| `call_interrupt_handlers_pair()` | 5 | 5 | 0 | 100% | ✅ Working |
| `display_error()` | 8 | 0 | 8 | 0% | ❌ Broken |
| `handle_dos_interrupt()` | 5 | 0 | 5 | 0% | ❌ Broken |
| `call_dos_interrupt()` | 6 | 0 | 6 | 0% | ❌ Broken |
| `refresh_display()` | 5 | 0 | 5 | 0% | ❌ Broken |
| `update_display_mode()` | 7 | 0 | 7 | 0% | ❌ Broken |
| `setup_display_window()` | 6 | 3 | 3 | 50% | ⚠️ Partial |
| `print_string()` | 8 | 8 | 0 | 100% | ✅ Working |
| `clear_display_line()` | 5 | 5 | 0 | 100% | ✅ Working |
| **TOTAL** | **60** | **26** | **34** | **43.3%** | ⚠️ **Needs Work** |

---

## Recommendations

### High Priority Fixes

1. **Fix `setup_function_context()` chain** (Affects 5+ functions)
   - Location: `skull_ported.c:8619` in `process_file_handles_setup()`
   - Impact: Cascading failures across multiple Set 16 functions
   - This is the same issue identified in Set 17's static function testing

2. **Fix `format_string_printf()`** (Affects error display)
   - Location: `skull_ported.c:10960`
   - Impact: Prevents `display_error()` from working
   - Blocks error reporting functionality

3. **Fix `setup_display_window()` cursor reset** (50% working)
   - Issue: Fails when `reset_cursor=1`
   - Impact: Partial functionality loss
   - Should be easier to fix than the above issues

### Medium Priority

4. **Investigate interrupt handling functions**
   - `handle_dos_interrupt()`, `call_dos_interrupt()`, `refresh_display()`, `update_display_mode()`
   - All fail with `ACCESS_VIOLATION` exceptions
   - May depend on fixing `setup_function_context()` first

### Testing Improvements

5. **Add more granular tests** for partially working functions
6. **Create integration tests** for interrupt handling workflows
7. **Add memory validation** before critical operations

---

## Comparison with Previous Testing

**Previous Status (2026-01-09):** 2/10 functions passing (20%)  
**Current Status (2026-01-16):** 4/10 functions passing (40%)  
**Improvement:** +20% function pass rate

However, the comprehensive deep dive testing (60 tests vs. 10 basic tests) reveals:
- More detailed understanding of failure modes
- Identification of partial functionality (e.g., `setup_display_window()`)
- Better characterization of root causes

---

## Next Steps

1. ✅ **Document results** - COMPLETE (this document)
2. ⏳ **Fix `setup_function_context()` chain** - This is the highest priority fix
3. ⏳ **Fix `format_string_printf()`** - Required for error display
4. ⏳ **Fix `setup_display_window()` cursor reset** - Quick win
5. ⏳ **Retest after fixes** - Verify improvements
6. ⏳ **Continue with Set 18** - Move to next untested set

---

## Test Environment

- **Platform:** Windows 11
- **Compiler:** MSVC (Microsoft Visual C++)
- **Exception Handling:** Windows SEH (`__try`/`__except`)
- **Memory Pool:** Initialized with full game context
- **Game State:** Full initialization via `initialize_full_game_context_for_testing()`

---

## Files Modified

- `test_functions.c` - Added `test_set_16_deep_dive()` with 60 comprehensive tests
- `test_functions.c` - Updated `main()` to call Set 16 deep dive tests

---

**Test Execution Time:** ~2 seconds  
**Report Generated:** 2026-01-16  
**Next Review:** After implementing high-priority fixes
