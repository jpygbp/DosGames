# Building Skull Game for 64-bit Windows 11

This document explains how to compile the ported DOS game for 64-bit Windows 11.

## Prerequisites

You need one of the following:

1. **Visual Studio 2022** (recommended)
   - Install "Desktop development with C++" workload
   - Includes MSVC compiler and CMake

2. **CMake + MinGW-w64**
   - Download CMake from https://cmake.org/
   - Download MinGW-w64 from https://www.mingw-w64.org/

3. **CMake + Clang**
   - Install LLVM/Clang for Windows

## Quick Build

### Option 1: Using the build script
```batch
build.bat
```

### Option 2: Using CMake directly
```batch
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

The executable will be in `build\bin\Release\skull.exe`

### Option 3: Using MSVC directly
Open "Developer Command Prompt for VS 2022" and run:
```batch
cl /W4 /O2 /MD /Fe:skull.exe dos_compat.c skull_ported.c /link kernel32.lib user32.lib
```

### Option 4: Using MinGW
```batch
gcc -o skull.exe dos_compat.c skull_ported.c -luser32 -lkernel32 -std=c11
```

## Project Structure

- `dos_compat.h` / `dos_compat.c` - DOS compatibility layer
- `skull_ported.c` - Ported game code (from Ghidra decompilation)
- `CMakeLists.txt` - CMake build configuration
- `build.bat` - Automated build script

## Known Issues

1. **Incomplete Port**: The automated porting may have issues with:
   - Complex memory access patterns
   - Function pointer types
   - DOS-specific I/O operations
   - Segmented memory model

2. **Missing Functions**: Many functions from the original are not yet implemented.
   You may need to implement stubs for:
   - `FUN_1000_3e4e()`
   - `FUN_1000_569c()`
   - `FUN_1000_3b24()`
   - `FUN_1000_3aee()`
   - `FUN_1000_4dec()`
   - And many others...

3. **Game Data Files**: The game requires these data files in the same directory:
   - SKULL.M
   - SKULL.X
   - SKULL.V
   - SKULL.T
   - SKULL.MO
   - SKULL.MM

## Next Steps

1. **Implement Missing Functions**: Analyze the decompiled code to understand what each function does
2. **Fix Memory Access**: Review and fix complex memory access patterns
3. **Test Game Logic**: Run and test each function individually
4. **Add Error Handling**: Add proper error handling for file I/O and memory operations

## Troubleshooting

### "undefined reference" errors
- Make sure all required functions are implemented or stubbed
- Check that you're linking against kernel32 and user32

### "Cannot open include file"
- Ensure `dos_compat.h` is in the same directory or in include path
- Check that you're compiling from the correct directory

### Runtime errors
- Ensure game data files (SKULL.M, etc.) are in the same directory as the executable
- Check that `InitGameState()` is called before any game functions

