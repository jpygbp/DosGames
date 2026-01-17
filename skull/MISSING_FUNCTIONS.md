# Missing Functions Analysis

**Generated**: Current Session  
**Purpose**: Identify functions that are called but not implemented

---

## Summary

Based on build output analysis, there are **29 functions** that are called but not defined, plus **6 helper macros** that need to be implemented.

---

## Functions That Need Implementation

### FUN_1000_* Functions (26 functions)

**Note**: Some functions have been renamed to more meaningful names. Check the mapping below.

These functions are called but not defined in `skull_ported.c`:

1. **FUN_1000_0d36** - Called in `dos_compat.c(306)` and `skull_ported.c(796)`
2. **FUN_1000_4dec** - Called in `skull_ported.c(147)`
3. **FUN_1000_55a6** - Called in `skull_ported.c(192)`
4. **FUN_1000_5592** - Called in `skull_ported.c(226)`
5. **FUN_1000_05b6** - Called in `skull_ported.c(316)`
6. **FUN_1000_550e** - Called in `skull_ported.c(421)`
7. **FUN_1000_2e28** - Called in `skull_ported.c(953)`
8. **FUN_1000_56ae** - Called in `skull_ported.c(1062)`
9. **FUN_1000_2e70** - Called in `skull_ported.c(1098)`
10. **FUN_1000_2f64** - Called in `skull_ported.c(1465)`
11. **FUN_1000_325c** - Called in `skull_ported.c(1621)`
12. **FUN_1000_358c** - Called in `skull_ported.c(1951)`
13. **FUN_1000_21ee** - Called in `skull_ported.c(2021)`
14. **FUN_1000_3908** - Called in `skull_ported.c(2840)`
15. **FUN_1000_54f2** - Called in `skull_ported.c(3031)`
16. **FUN_1000_39d0** - Called in `skull_ported.c(3078)`
17. **FUN_1000_36ae** - Called in `skull_ported.c(3177)`
18. **FUN_1000_4e86** - Called in `skull_ported.c(3325)`
19. **FUN_1000_3aee** - Called in `skull_ported.c(3330)`
20. **FUN_1000_3a98** - Called in `skull_ported.c(3354)`
21. **FUN_1000_3b24** - Called in `skull_ported.c(3360)`
22. **FUN_1000_4e0c** - Called in `skull_ported.c(3388)`
23. **FUN_1000_5108** - Called in `skull_ported.c(3448)`
24. **FUN_1000_502a** - Called in `skull_ported.c(3469)`
25. **FUN_1000_3e64** - Called in `skull_ported.c(3913)`
26. **FUN_1000_4d44** - Called in `skull_ported.c(5090)`

### Renamed Functions (Found in skull_ported.c)

Some functions have been renamed but calls still use old names:

1. **FUN_1000_4d44** → **`parse_format_number`** (line 5722)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

2. **FUN_1000_4dec** → **`file_close`** (line 5783)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

3. **FUN_1000_529d** → **`allocate_memory_chunk`** (line 6490)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

4. **FUN_1000_0d36** → **`find_matching_objects`** (line 841)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

5. **FUN_1000_21ee** → **`handle_direction_move`** (line 2043)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

6. **FUN_1000_2e28** → **`check_game_state`** (line 2733)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

7. **FUN_1000_2e70** → **`find_objects_in_location`** (line 2750)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

8. **FUN_1000_2f64** → **`remove_object_from_list`** (line 2784)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

9. **FUN_1000_3024** → **`add_object_to_list`** (line 2817)
   - Status: ✅ Defined but calls use old name
   - Action: Update calls or add alias

10. **FUN_1000_325c** → **`display_object_info`** (line 2935)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

11. **FUN_1000_358c** → **`load_and_display_message`** (line 3147)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

12. **FUN_1000_36ae** → **`format_text_line`** (line 3237)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

13. **FUN_1000_3908** → **`load_string_from_file`** (line 3384)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

14. **FUN_1000_39d0** → **`load_string_from_secondary_file`** (line 3419)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

15. **FUN_1000_3a98** → **`read_file_exact`** (line 3454)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

16. **FUN_1000_3aee** → **`file_read_word`** (line 3476)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

17. **FUN_1000_3b24** → **`file_open`** (line 3493)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

18. **FUN_1000_3e64** → **`verify_game_data`** (line 4187)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

19. **FUN_1000_4e0c** → **`allocate_memory_chunk`** (line 6490) - Same as 529d?
    - Status: ⚠️ Need to verify if this is a different function

20. **FUN_1000_4e86** → Need to search
    - Status: ⚠️ Need to find definition

21. **FUN_1000_502a** → Need to search
    - Status: ⚠️ Need to find definition

22. **FUN_1000_5108** → Need to search
    - Status: ⚠️ Need to find definition

23. **FUN_1000_54f2** → Need to search
    - Status: ⚠️ Need to find definition

24. **FUN_1000_55a6** → Need to search
    - Status: ⚠️ Need to find definition

25. **FUN_1000_5592** → Need to search
    - Status: ⚠️ Need to find definition

26. **FUN_1000_550e** → Need to search
    - Status: ⚠️ Need to find definition

27. **FUN_1000_56ae** → Need to search
    - Status: ⚠️ Need to find definition

28. **FUN_1000_05b6** → **`lookup_command`** (line 418)
    - Status: ✅ Defined but calls use old name
    - Action: Update calls or add alias

---

## Helper Macros/Functions That Need Implementation

These are used throughout the code but not defined:

1. **CONCAT11** - Concatenates two 8-bit values into a 16-bit value
   - Used in: `skull_ported.c` (multiple locations)
   - Example: `CONCAT11(0xd0, cVar6)` - combines two bytes into a word

2. **CONCAT22** - Concatenates two 16-bit values into a 32-bit value
   - Used in: `skull_ported.c` (multiple locations)
   - Example: `CONCAT22(uVar6, local_a)` - combines two words into a dword

3. **CARRY2** - Checks for carry flag in 16-bit addition
   - Used in: `skull_ported.c` (multiple locations)
   - Example: `CARRY2(in_AX, *puVar2)` - checks if addition would carry

4. **SBORROW2** - Checks for signed borrow in 16-bit subtraction
   - Used in: `skull_ported.c(8298)`
   - Example: `SBORROW2(uVar3, *puVar2)` - checks if subtraction would borrow

5. **POPCOUNT** - Population count (number of set bits)
   - Used in: `skull_ported.c(8302)`
   - Example: `POPCOUNT(uVar3 & 0xff)` - counts set bits in byte

6. **ZEXT24** - Zero-extend to 24 bits
   - Used in: `skull_ported.c(5755)`
   - Example: `ZEXT24(param_2)` - extends value to 24 bits

---

## Recommended Implementation

### Step 1: Add Helper Macros to `dos_compat.h` ⚠️ CRITICAL

**This is the highest priority** - These macros are used extensively and must be defined.

These are low-level bit manipulation functions that should be defined as macros:

```c
/* Bit manipulation macros for decompiled code */
#define CONCAT11(high, low) ((uint16_t)(((uint8_t)(high) << 8) | (uint8_t)(low)))
#define CONCAT22(high, low) ((uint32_t)(((uint16_t)(high) << 16) | (uint16_t)(low)))
#define CARRY2(a, b) (((uint32_t)(a) + (uint32_t)(b)) > 0xFFFF)
#define SBORROW2(a, b) ((int16_t)(a) < (int16_t)(b))
#define POPCOUNT(x) (__builtin_popcount(x))  /* GCC/Clang, or implement manually */
#define ZEXT24(x) ((uint32_t)(x) & 0xFFFFFF)
```

### Step 2: Search for Function Definitions

Check if these functions are defined later in `skull_ported.c` with different names or signatures. They may have been:
- Renamed to more meaningful names
- Defined with different signatures
- Split into multiple functions

### Step 3: Create Stub Implementations

For functions that are truly missing, create minimal stub implementations in `function_stubs.c`:

```c
/* Stub implementations - return safe defaults */
undefined2 FUN_1000_0d36(void) { return 0; }
undefined2 FUN_1000_4dec(void) { return 0; }
/* ... etc ... */
```

### Step 4: Runtime Testing

After adding stubs, test the executable to see which functions are actually called and need real implementations.

---

## Action Items

1. ✅ **Add helper macros** to `dos_compat.h` - These are critical for compilation
2. ⚠️ **Search for function definitions** - Verify if functions exist with different names
3. ⚠️ **Create stub implementations** - Add to `function_stubs.c` for missing functions
4. ⚠️ **Runtime testing** - Identify which stubs need real implementations

---

## Priority

**High Priority** (Blocks compilation correctness):
- Helper macros (CONCAT11, CONCAT22, CARRY2, etc.) - Used extensively

**Medium Priority** (May cause runtime issues):
- Functions that are called during initialization
- Functions that are called frequently

**Low Priority** (May not be called):
- Functions that are only called in error paths
- Functions that may be dead code

---

## Notes

- The build currently succeeds because MSVC assumes these functions return `int` and are defined elsewhere
- Runtime testing will reveal which functions are actually called
- Some functions may be defined in `skull_ported.c` but with forward declarations that don't match
- The helper macros are essential - without them, the code may not work correctly even if it compiles

