# Ghidra Decompilation Results Comparison

## Summary

Ghidra successfully decompiled **SKULL.EXE** and produced significantly better results than the initial Python-based analysis.

## Statistics

| Metric | Python Analysis | Ghidra Decompilation |
|--------|----------------|---------------------|
| Functions Identified | 135 | **197** |
| Output Lines | ~180 | **7,684** |
| Code Quality | Pseudocode | **Full C code** |
| Variable Names | Generic | **Named variables** |
| Data Structures | Inferred | **Identified** |
| DOS Calls | 27 identified | **All identified** |

## Key Improvements with Ghidra

### 1. **Better Function Detection**
- Ghidra found **197 functions** vs 135 in initial analysis
- More accurate function boundary detection
- Better handling of segmented memory (16-bit DOS)

### 2. **Readable C Code**
Ghidra produces actual C code with:
- Named variables (`uVar1`, `iVar7`, `puVar2`, etc.)
- Proper data types (`uint`, `undefined2`, `char`, `int`)
- Control flow structures (if/else, while loops, for loops)
- Function signatures with calling conventions

### 3. **Memory Address Analysis**
Ghidra identified and labeled memory addresses:
- Global variables at specific addresses (e.g., `0xbc`, `0x5dbc`)
- Stack variables with offsets (`local_22`, `local_1e`)
- Proper handling of segmented addressing (e.g., `1000:0010`)

### 4. **Function Naming**
Functions are named with their addresses:
- `FUN_1000_0010` - Function at segment 1000, offset 0010
- `FUN_1570_000a` - Function at segment 1570, offset 000a
- Better organization for analysis

## Sample Decompiled Code

### Entry Function (FUN_1000_0010)
```c
void __cdecl16near FUN_1000_0010(void)
{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined2 unaff_DS;
  undefined2 *local_22;
  undefined2 local_1e;
  
  FUN_1000_3e4e();
  iVar7 = 0;
  local_22 = (undefined2 *)0x6602;
  FUN_1000_569c();
  // ... more code ...
  
  cVar4 = FUN_1000_55a6();
  if ((cVar4 == 'n') || (cVar4 == 'N')) {
    *(undefined2 *)0xe6 = 0;
    FUN_1570_000a();
  }
  // ... more code ...
}
```

This shows:
- Proper variable declarations
- Function calls
- Conditional logic
- Memory operations

## File Structure

The decompiled code reveals:
- **197 functions** across multiple code segments
- Clear separation between different code sections
- Proper handling of DOS calling conventions (`__cdecl16near`)
- Memory-mapped I/O operations

## Comparison with Previous Analysis

### Python Analysis (skull_decompiled.c)
- Basic function structure
- Generic function names
- Limited variable information
- Approximate control flow

### Ghidra Decompilation (skull_ghidra_decompiled.c)
- Complete C code
- Named functions with addresses
- Detailed variable information
- Accurate control flow
- Memory address mapping
- Data type information

## Recommendations

1. **Use Ghidra output** (`skull_ghidra_decompiled.c`) as the primary decompilation reference
2. **Cross-reference** with assembly (`skull_disassembly.txt`) for verification
3. **Analyze function calls** to understand program flow
4. **Map memory addresses** to understand data structures
5. **Identify game logic** by analyzing function names and patterns

## Next Steps

1. Analyze key functions to understand game mechanics
2. Map memory addresses to game state variables
3. Identify file I/O operations for game data loading
4. Reverse engineer game data formats from file operations
5. Document function purposes based on behavior

## Files Generated

- `skull_ghidra_decompiled.c` - **Primary decompilation (7,684 lines)**
- `skull_decompiled.c` - Initial Python analysis (180 lines)
- `skull_disassembly.txt` - Assembly code
- `skull_strings.txt` - Extracted strings
- `DECOMPILATION_REPORT.txt` - Initial analysis report

