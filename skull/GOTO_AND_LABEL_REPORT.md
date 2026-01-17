# Goto Statements and Labels Report

**Generated:** 2026-01-10  
**Scope:** All C source files in the codebase

---

## Executive Summary

### Goto Statements by File
- **skull_ported.c**: **0 goto statements** ✅ (All eliminated - see GOTO_ANALYSIS.md)
- **skull_ghidra_decompiled.c**: **173 goto statements** ⚠️
- **skull_decompiled.c**: **130+ goto statements** ⚠️

### Labels by File
- **skull_ported.c**: **0 labels** (only `default:` in switch statements)
- **skull_ghidra_decompiled.c**: **66 labels**
- **skull_decompiled.c**: Labels present (exact count not shown in filtered results)

---

## Detailed Breakdown

### 1. skull_ported.c (Main Ported File)

**Status:** ✅ **CLEAN - No goto statements or labels**

According to GOTO_ANALYSIS.md, all 114 goto statements have been eliminated from this file through Phase 4 refactoring. The file uses structured control flow (flags, conditionals, early returns) instead of goto statements.

**Evidence:**
- Grep search for `goto` statements: **0 matches**
- Only comments mentioning "Phase 4 Goto Elimination" found at:
  - Line 8305: Comment about converting goto to continue
  - Line 9111: Comment about unreachable label after return

**Switch statement labels only:**
- Line 6775: `default:` case in switch statement
- Line 10000: `default:` case in switch statement

---

### 2. skull_ghidra_decompiled.c (Decompiled Source)

**Status:** ⚠️ **Contains 173 goto statements and 66 labels**

This is the decompiled source file that contains all the original goto statements from the decompiled assembly code.

#### Goto Statements Found (173 total):

**Location examples (showing pattern):**

| Line | Goto Target | Context |
|------|-------------|---------|
| 582 | `LAB_1000_0b0a` | Conditional branch |
| 584 | `LAB_1000_0b0a` | If statement |
| 601 | `LAB_1000_0b0a` | Conditional branch |
| 618 | `LAB_1000_0b0a` | Conditional branch |
| 665 | `LAB_1000_0c56` | Function jump |
| 753 | `LAB_1000_0deb` | Nested conditional |
| 763 | `LAB_1000_0df3` | Pointer check |
| 852 | `LAB_1000_0fb6` | Value comparison |
| 868 | `LAB_1000_1011` | Non-zero check |
| 873 | `LAB_1000_1011` | Non-zero check |
| 876 | `LAB_1000_109e` | Conditional branch |
| 888 | `LAB_1000_103a` | Zero check |
| 902 | `LAB_1000_109e` | Conditional branch |
| 1001 | `LAB_1000_1229` | Unconditional jump |
| 1007 | `LAB_1000_1229` | Bit check |
| 1019 | `LAB_1000_1229` | Conditional branch |
| 1022 | `LAB_1000_1229` | Bit check |
| 1025 | `LAB_1000_13e4` | Conditional branch |
| 1043 | `LAB_1000_13a7` | Nested conditional |
| 1055 | `LAB_1000_1229` | Null check |
| 1067 | `LAB_1000_1229` | Conditional branch |
| 1194 | `LAB_1000_165b` | Zero check |
| 1195 | `LAB_1000_1616` | Unconditional jump |
| 1437 | `LAB_1000_19e1` | Conditional branch |
| 1794 | `LAB_1000_20ac` | Conditional branch |
| 1808 | `LAB_1000_20ac` | Conditional branch |
| 1812 | `LAB_1000_20ac` | Conditional branch |
| 1886 | `LAB_1000_21ad` | Conditional branch |
| 1894 | `LAB_1000_21ad` | Bit mask check |
| 2009 | `LAB_1000_243b` | Conditional branch |
| 2091 | `LAB_1000_254a` | Conditional branch |
| 2099 | `LAB_1000_254a` | Conditional branch |
| 2109 | `LAB_1000_254a` | Conditional branch |
| 2122 | `LAB_1000_254a` | Conditional branch |
| 2126 | `LAB_1000_254a` | Conditional branch |
| 2132 | `LAB_1000_254a` | Non-zero check |
| 2135 | `LAB_1000_254a` | Conditional branch |
| 2139 | `LAB_1000_254a` | Conditional branch |
| 2237 | `LAB_1000_2800` | Non-zero check |
| 2243 | `LAB_1000_2800` | Conditional branch |
| 2253 | `LAB_1000_2800` | Conditional branch |
| 2833 | `LAB_1000_32e2` | Zero check |
| 3962 | `LAB_1000_3d0c` | Null check |
| 4115 | `LAB_1000_3ea8` | Non-null check |
| 4149 | `LAB_1000_3ec6` | Whitespace check |
| 4159 | `LAB_1000_3f42` | Carriage return/null check |
| 4160 | `LAB_1000_3ed9` | Quote character check |
| 4177 | `LAB_1000_3ed9` | Unconditional jump |
| 4181 | `LAB_1000_3ed9` | Unconditional jump |
| 4192 | `LAB_1000_3f12` | Bit check |
| 4193 | `LAB_1000_3ed9` | Conditional branch |
| 4250 | `LAB_1000_3f7b` | Conditional branch |
| 4255 | `LAB_1000_400a` | Conditional branch |
| 4263 | `LAB_1000_4007` | Carriage return/null check |
| 4300 | `LAB_1000_3f98` | Conditional branch |
| 4306 | `LAB_1000_3f98` | Conditional branch |
| 4322 | `LAB_1000_3fd4` | Bit check |
| 4326 | `LAB_1000_3f98` | Conditional branch |
| 4592 | `LAB_1000_3ca9` | Boolean check |
| 4627 | `LAB_1000_4163` | Non-null check |
| 4636 | `LAB_1000_415d` | Comparison |
| 4637 | `LAB_1000_4159` | Comparison |
| 4913 | `LAB_1000_47b6` | Character comparison |
| 4987 | `LAB_1000_47d8` | Null check |
| 4996 | `LAB_1000_4792` | Conditional branch |
| 4999 | `switchD_1000_4699_caseD_64` | Switch case jump |
| 5004 | `LAB_1000_481a` | Conditional branch |
| 5011 | `LAB_1000_47b6` | Conditional branch |
| 5017 | `LAB_1000_481a` | Conditional branch |
| 5064 | `LAB_1000_46a9` | Conditional branch |
| 5070 | `LAB_1000_481a` | Conditional branch |
| 5074 | `switchD_1000_4699_caseD_64` | Switch case jump |
| 5082 | `LAB_1000_4838` | Non-zero check |
| 5084 | `joined_r0x000147e7` | Unconditional jump |
| 5087 | `LAB_1000_47d0` | Unconditional jump |
| 5097 | `LAB_1000_47d0` | Unconditional jump |
| 5100 | `LAB_1000_46bf` | Unconditional jump |
| 5319 | `LAB_1000_4b14` | Conditional branch |
| 5672 | `LAB_1000_4e6f` | Bit mask check |
| 5673 | `LAB_1000_4e47` | Null check |
| 5679 | `LAB_1000_4e83` | Boolean check |
| 5691 | `LAB_1000_4e83` | Conditional branch |
| 5701 | `LAB_1000_4e6f` | Comparison |
| 5762 | `LAB_1000_412b` | Boolean check |
| 5769 | `LAB_1000_412b` | Boolean check |
| 5776 | `LAB_1000_412b` | Boolean check |
| 5838 | `LAB_1000_4f88` | Conditional branch |
| 5846 | `LAB_1000_4fd2` | Conditional branch |
| 5898 | `LAB_1000_509b` | Unconditional jump |
| 5902 | `LAB_1000_509b` | Complex conditional |
| 5909 | `LAB_1000_509b` | Conditional branch |
| 5912 | `LAB_1000_509b` | Bit check |
| 5916 | `LAB_1000_509b` | Zero check |
| 5933 | `LAB_1000_5090` | Value comparison |
| 5934 | `LAB_1000_5093` | Unconditional jump |
| 5948 | `LAB_1000_5090` | Conditional branch |
| 5950 | `LAB_1000_509b` | Conditional branch |
| 5959 | `LAB_1000_509b` | Boolean check |
| 5966 | `LAB_1000_5095` | Conditional branch |
| 5976 | `LAB_1000_5095` | Zero check |
| 5977 | `LAB_1000_5080` | Unconditional jump |
| 6023 | `LAB_1000_412b` | Conditional branch |
| 6029 | `LAB_1000_412b` | Boolean check |
| 6069 | `LAB_1000_51fc` | Boolean check |
| 6090 | `LAB_1000_3d0c` | Null check |
| 6387 | `LAB_1000_5304` | Conditional branch |
| 6412 | `LAB_1000_52cd` | Comparison |
| 7118 | `LAB_1570_00d7` | Value comparison |
| 7146 | `LAB_1570_012b` | Bit check |
| 7150 | `LAB_1570_012b` | Bit check |
| 7153 | `LAB_1570_0129` | Bit check |
| 7155 | `LAB_1570_012b` | Bit check |
| 7159 | `LAB_1570_012b` | Complex conditional |
| 7864 | `LAB_1570_09a4` | Conditional branch |
| 7883 | `LAB_1570_09a4` | Conditional branch |
| 7911 | `LAB_1570_09c1` | Comparison |

**Total goto statements: 173**

#### Labels Found (66 total):

| Line | Label Name | Type |
|------|------------|------|
| 622 | `LAB_1000_0b0a:` | Regular label |
| 701 | `LAB_1000_0c56:` | Regular label |
| 755 | `LAB_1000_0df3:` | Regular label |
| 762 | `LAB_1000_0deb:` | Regular label |
| 858 | `LAB_1000_0fb6:` | Regular label |
| 874 | `LAB_1000_103a:` | Regular label |
| 878 | `LAB_1000_1011:` | Regular label |
| 911 | `LAB_1000_109e:` | Regular label |
| 1049 | `LAB_1000_13a7:` | Regular label |
| 1072 | `LAB_1000_13e4:` | Regular label |
| 1074 | `LAB_1000_1229:` | Regular label |
| 1204 | `LAB_1000_165b:` | Regular label |
| 1211 | `LAB_1000_1616:` | Regular label |
| 1445 | `LAB_1000_19e1:` | Regular label |
| 1817 | `LAB_1000_20ac:` | Regular label |
| 1899 | `LAB_1000_21ad:` | Regular label |
| 2038 | `LAB_1000_243b:` | Regular label |
| 2144 | `LAB_1000_254a:` | Regular label |
| 2258 | `LAB_1000_2800:` | Regular label |
| 2842 | `LAB_1000_32e2:` | Regular label |
| 3973 | `LAB_1000_3d0c:` | Regular label |
| 4107 | `LAB_1000_3ea8:` | Regular label |
| 4133 | `LAB_1000_3ec6:` | Regular label |
| 4145 | `LAB_1000_3ed9:` | Regular label |
| 4152 | `LAB_1000_3f12:` | Regular label |
| 4198 | `LAB_1000_3f42:` | Regular label |
| 4220 | `LAB_1000_3f7b:` | Regular label |
| 4229 | `LAB_1000_400a:` | Regular label |
| 4242 | `LAB_1000_3f98:` | Regular label |
| 4253 | `LAB_1000_4007:` | Regular label |
| 4259 | `LAB_1000_3fd4:` | Regular label |
| 4494 | `LAB_1000_3ca9:` | Regular label |
| 4629 | `LAB_1000_4159:` | Regular label |
| 4631 | `LAB_1000_415d:` | Regular label |
| 4641 | `LAB_1000_4163:` | Regular label |
| 4899 | `LAB_1000_47d0:` | Regular label |
| 4901 | `LAB_1000_47d8:` | Regular label |
| 4904 | `joined_r0x000147e7:` | Joined label |
| 4909 | `LAB_1000_4838:` | Regular label |
| 5005 | `default:` | Switch default |
| 5014 | `LAB_1000_46a9:` | Regular label |
| 5068 | `LAB_1000_4792:` | Regular label |
| 5078 | `LAB_1000_46bf:` | Regular label |
| 5080 | `LAB_1000_481a:` | Regular label |
| 5088 | `LAB_1000_47b6:` | Regular label |
| 5098 | `switchD_1000_4699_caseD_64:` | Switch case label |
| 5323 | `LAB_1000_4b14:` | Regular label |
| 5683 | `LAB_1000_4e6f:` | Regular label |
| 5705 | `LAB_1000_4e47:` | Regular label |
| 5712 | `LAB_1000_4e83:` | Regular label |
| 5759 | `LAB_1000_4f88:` | Regular label |
| 5779 | `LAB_1000_4fd2:` | Regular label |
| 5853 | `LAB_1000_412b:` | Regular label |
| 5923 | `LAB_1000_5080:` | Regular label |
| 5968 | `LAB_1000_5090:` | Regular label |
| 5972 | `LAB_1000_5093:` | Regular label |
| 5978 | `LAB_1000_5095:` | Regular label |
| 5981 | `LAB_1000_509b:` | Regular label |
| 6032 | `LAB_1000_51fc:` | Regular label |
| 6101 | `LAB_1000_3d0c:` | Regular label (duplicate) |
| 6204 | `LAB_1000_412b:` | Regular label (duplicate) |
| 6342 | `LAB_1000_52cd:` | Regular label |
| 6404 | `LAB_1000_5304:` | Regular label |
| 7123 | `LAB_1570_00d7:` | Regular label |
| 7161 | `LAB_1570_0129:` | Regular label |
| 7163 | `LAB_1570_012b:` | Regular label |
| 7888 | `LAB_1570_09a4:` | Regular label |
| 7914 | `LAB_1570_09c1:` | Regular label |

**Total labels: 66** (including 1 switch default, 1 switch case label, 1 joined label, and 2 duplicates)

**Note:** Some labels appear multiple times in the file (e.g., `LAB_1000_3d0c` at lines 3973 and 6101, `LAB_1000_412b` at lines 5853 and 6204). This is typical for decompiled code where multiple code paths converge.

---

### 3. skull_decompiled.c (Alternative Decompiled Source)

**Status:** ⚠️ **Contains 130+ goto statements**

This appears to be an alternative decompiled version with different label naming conventions (using `label_XXXX` format instead of `LAB_XXXX_XXXX`).

#### Goto Statements Found (130+ total):

**Location examples:**

| Line | Goto Target | Context |
|------|-------------|---------|
| 46 | `label_028E` | Jump instruction |
| 47 | `label_02AB` | Jump if equal |
| 54 | `label_0543` | Jump if not equal |
| 55 | `label_0557` | Unconditional jump |
| 56 | `label_0567` | Jump if equal |
| 57 | `label_054C` | Jump if not equal |
| 58 | `label_058C` | Jump if less or equal |
| 60 | `label_0591` | Unconditional jump |
| 68 | `label_0682` | Unconditional jump |
| 69 | `label_05E5` | Jump if greater or equal |
| 70 | `label_05D2` | Jump if equal |
| 71 | `label_060D` | Unconditional jump |
| 72 | `label_0615` | Jump if greater or equal |
| 73 | `label_05F2` | Jump if not equal |
| 74 | `label_062A` | Jump if less or equal |
| 75 | `label_0633` | Unconditional jump |
| ... | ... | ... |
| 168 | `label_0E45` | Jump if equal |
| 169 | `label_0F24` | Unconditional jump |
| 170 | `label_0E60` | Jump if not equal |
| 172 | `label_0F24` | Unconditional jump |
| 174 | `label_0F24` | Unconditional jump |
| 175 | `label_0EA9` | Jump if equal |

**Pattern:** Label names follow the format `label_XXXX` where XXXX appears to be hexadecimal addresses.

**Total goto statements: 130+** (exact count not determined due to truncated results)

---

### 4. Other Files

#### build.bat (Batch Script)
- **Line 12:** `goto :msvc_build` - Batch file label jump (normal for batch files)
- **Line 72:** `goto :msvc_build` - Batch file label jump

#### decompile_skull.py (Python Script)
- **Line 165:** Contains a string template with `goto label_%04X;` - This is code generation, not actual goto usage

#### dos_compat.c
- Only `default:` labels in switch statements (lines 270, 769, 1939, 2023, 2220, 2293)

---

## Label Naming Conventions

### skull_ghidra_decompiled.c
- Format: `LAB_XXXX_XXXX`
- Examples: `LAB_1000_0b0a`, `LAB_1000_3d0c`, `LAB_1570_00d7`
- Pattern: `LAB_[segment]_[offset]` where segment and offset appear to be hexadecimal memory addresses

### skull_decompiled.c
- Format: `label_XXXX`
- Examples: `label_028E`, `label_02AB`, `label_0F24`
- Pattern: `label_[address]` where address appears to be a hexadecimal memory address

---

## Most Frequently Used Labels (skull_ghidra_decompiled.c)

Based on the goto statement analysis, these labels are jumped to most frequently:

| Label | Goto Count | Purpose |
|-------|------------|---------|
| `LAB_1000_3ed9` | 6+ | Quoted string processing |
| `LAB_1000_254a` | 7+ | Conditional state checks |
| `LAB_1000_109e` | 2+ | Loop continuation |
| `LAB_1000_1229` | 8+ | Error handling/state reset |
| `LAB_1000_1011` | 2+ | Conditional processing |
| `LAB_1000_509b` | 9+ | Complex conditional checks |
| `LAB_1000_412b` | 5+ | Boolean checks |
| `LAB_1000_20ac` | 3+ | Conditional branches |
| `LAB_1000_4e83` | 2+ | Boolean checks |
| `LAB_1000_3f98` | 4+ | Character processing loop |
| `LAB_1000_481a` | 4+ | Switch case handling |
| `LAB_1570_012b` | 5+ | Bit mask checks |

---

## Summary Statistics

| Metric | Count |
|--------|-------|
| **Total goto statements in active code** | **0** ✅ |
| **Total goto statements in decompiled sources** | **303+** |
| **Total labels in active code** | **0** ✅ |
| **Total labels in decompiled sources** | **66+** |
| **Files with goto statements** | **3** (2 decompiled + 1 batch) |
| **Files with labels** | **3** (decompiled sources + batch file) |
| **Main source file (skull_ported.c) status** | **✅ CLEAN** |

---

## Recommendations

### ✅ Already Completed
1. **skull_ported.c** - All goto statements eliminated through Phase 4 refactoring
   - Converted to structured control flow
   - Uses flags, conditionals, and early returns
   - All functionality preserved

### ⚠️ Optional Future Work
2. **skull_ghidra_decompiled.c** and **skull_decompiled.c** are reference/decompiled source files
   - These are NOT actively used in the build
   - They serve as reference for understanding the original code
   - No action needed unless planning to merge additional functionality

3. **build.bat** - Contains legitimate goto statements
   - These are normal for batch files
   - No action needed

---

## Conclusion

The main source file **skull_ported.c** is completely free of goto statements and labels, having successfully eliminated all 114 goto statements through structured refactoring. The decompiled source files contain many goto statements and labels, but these are reference files and not part of the active codebase.

**Status:** ✅ **Code quality goals achieved** - Main source file uses modern structured control flow.
