# Porting Summary: SKULL.EXE to 64-bit Windows 11

## Overview

This project ports the 1989 DOS text adventure game "Skullduggery" from 16-bit DOS to 64-bit Windows 11.

## What Was Done

### 1. **DOS Compatibility Layer** (`dos_compat.h` / `dos_compat.c`)
   - Converted 16-bit DOS types to modern equivalents
   - Replaced DOS file I/O with Windows API
   - Created memory pool to simulate DOS memory model
   - Implemented console I/O functions

### 2. **Code Porting** (`skull_ported.c`)
   - Converted from Ghidra decompilation (7,684 lines)
   - Removed DOS-specific calling conventions
   - Replaced absolute memory addresses with structure access
   - Fixed memory read/write operations

### 3. **Build System**
   - CMake configuration for cross-platform building
   - Windows batch script for easy compilation
   - Support for MSVC, MinGW, and Clang

### 4. **Function Stubs** (`function_stubs.c`)
   - Generated stubs for 16 missing functions
   - Allows code to compile without full implementation

## Current Status

✅ **Completed:**
- DOS compatibility layer
- Basic code porting
- Build system setup
- Function stub generation

⚠️ **In Progress / Needs Work:**
- Many functions are stubs and need implementation
- Complex memory access patterns may need fixes
- DOS-specific operations (interrupts, BIOS calls) need Windows equivalents
- Game data file loading needs testing
- Console I/O may need refinement

## Files Created

### Core Files
- `dos_compat.h` - DOS compatibility header
- `dos_compat.c` - DOS compatibility implementation
- `skull_ported.c` - Ported game code (8,685 lines)
- `main.c` - Entry point
- `function_stubs.c` - Stub functions for missing implementations

### Build Files
- `CMakeLists.txt` - CMake build configuration
- `build.bat` - Windows build script
- `BUILD_INSTRUCTIONS.md` - Build instructions

### Documentation
- `PORTING_SUMMARY.md` - This file
- `GHIDRA_COMPARISON.md` - Comparison with Ghidra decompilation

## Known Issues

1. **Incomplete Function Implementations**
   - 16 functions are stubs
   - Many functions call other functions that may not work correctly
   - DOS interrupt calls (INT 10h, INT 21h) need Windows equivalents

2. **Memory Model**
   - Original uses segmented memory (16-bit DOS)
   - Ported code uses flat memory model
   - Some pointer arithmetic may be incorrect

3. **File I/O**
   - DOS file handles converted to Windows handles
   - File paths may need adjustment
   - Game data files must be in same directory

4. **Console Operations**
   - DOS text mode operations need Windows console API
   - Color support needs implementation
   - Screen clearing/positioning needs work

## Next Steps

1. **Test Compilation**
   ```batch
   build.bat
   ```
   Or use CMake:
   ```batch
   mkdir build
   cd build
   cmake .. -G "Visual Studio 17 2022" -A x64
   cmake --build . --config Release
   ```

2. **Fix Compilation Errors**
   - Address any compiler errors
   - Fix type mismatches
   - Resolve undefined references

3. **Implement Missing Functions**
   - Analyze each stub function
   - Determine its purpose from context
   - Implement Windows equivalent

4. **Test Game Logic**
   - Run the executable
   - Test file loading
   - Test console I/O
   - Debug runtime errors

5. **Refine and Polish**
   - Fix memory access issues
   - Improve error handling
   - Add proper logging
   - Optimize performance

## Compilation

### Using Visual Studio
```batch
# Open Developer Command Prompt for VS
cl /W4 /O2 /MD /Fe:skull.exe dos_compat.c main.c skull_ported.c function_stubs.c /link kernel32.lib user32.lib
```

### Using CMake
```batch
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

### Using MinGW
```batch
gcc -o skull.exe dos_compat.c main.c skull_ported.c function_stubs.c -luser32 -lkernel32 -std=c11
```

## Requirements

- C compiler (MSVC, GCC, or Clang)
- CMake (optional, for build system)
- Windows 11 (64-bit)
- Game data files: SKULL.M, SKULL.X, SKULL.V, SKULL.T, SKULL.MO, SKULL.MM

## Notes

- This is an automated port from decompiled code
- Manual review and fixes are needed
- Not all functionality may work correctly
- Some DOS-specific features may be lost
- Performance may differ from original

## Resources

- Original game: Skullduggery (1989) by David Jewett
- Decompiled using: Ghidra 10.1.1
- Ported: 2025

