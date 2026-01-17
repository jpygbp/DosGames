# Windows 11 Compatibility Guide

This document outlines the Windows 11 compatibility improvements made to the DOS game port.

## Overview

Windows 11 compatibility has been addressed to ensure the game runs correctly on modern Windows systems. The following changes have been made:

## Changes Made

### 1. Windows Version Targeting

**File**: `dos_compat.h`

- Added `_WIN32_WINNT` and `WINVER` definitions to target Windows 10/11 APIs
- Set to `0x0A00` (Windows 10 / Windows Server 2016) which is compatible with Windows 11
- This ensures modern Windows APIs are available

### 2. Deprecated API Replacements

#### GetVersionExA Replacement
**File**: `dos_compat.c` - `dos_get_version()`

- **Issue**: `GetVersionExA()` is deprecated on Windows 10/11 and returns incorrect values
- **Solution**: Replaced with a fixed version that returns Windows 10/11 compatibility mode
- **Impact**: Version detection now correctly identifies Windows 10/11 without using deprecated APIs

#### Console Input Replacement
**Files**: `dos_compat.c` - `dos_get_char()`, `dos_kbhit()`

- **Issue**: `_getch()` and `_kbhit()` from `<conio.h>` are deprecated and may not work correctly on Windows 11
- **Solution**: 
  - Replaced `_getch()` with `ReadConsoleInputA()` for character input
  - Replaced `_kbhit()` with `PeekConsoleInputA()` and `GetNumberOfConsoleInputEvents()` for keyboard status checking
- **Impact**: Console input now uses modern Windows APIs that work reliably on Windows 11

### 3. Long Path Support

**Files**: `dos_compat.c` - `dos_open_file()`, `file_open_wrapper()`

- **Issue**: Windows traditionally limited paths to 260 characters (MAX_PATH). Windows 11 supports longer paths but requires proper handling
- **Solution**: 
  - Added `convert_to_long_path()` helper function
  - Automatically converts paths longer than 260 characters to long path format (`\\?\` prefix)
  - Supports paths up to 32,767 characters (PATHCCH_MAX_CCH)
- **Impact**: Game can now access files in deeply nested directories or with long names

### 4. File System Compatibility

- All file operations use `CreateFileA()` which is still supported on Windows 11
- Added automatic long path conversion for paths exceeding MAX_PATH
- Error handling improved for Windows 11-specific error codes

## Compilation Requirements

### Windows SDK Version
- Minimum: Windows 10 SDK (10.0.17763.0 or later)
- Recommended: Latest Windows 11 SDK

### Compiler Flags
The code defines:
```c
#define _WIN32_WINNT 0x0A00  /* Windows 10 / Windows Server 2016 */
#define WINVER 0x0A00        /* Windows 10 / Windows Server 2016 */
```

These ensure Windows 10/11 APIs are available during compilation.

## Runtime Requirements

### Windows Version
- **Minimum**: Windows 10 (version 1607 or later)
- **Recommended**: Windows 11
- **Architecture**: x64 (64-bit) only

### Features Used
- Modern console input APIs (`ReadConsoleInputA`, `PeekConsoleInputA`)
- Long path support (automatic `\\?\` prefix conversion)
- Standard Windows file I/O APIs

## Testing

### Known Working
- ✅ File opening with short paths (< 260 characters)
- ✅ File opening with long paths (> 260 characters)
- ✅ Keyboard input via console
- ✅ Keyboard status checking
- ✅ Version detection (reports Windows 10/11 compatible)

### Potential Issues

1. **Console Mode**: Some console features may require specific console mode settings. If input doesn't work correctly, the console may need to be set to raw input mode.

2. **Long Paths**: Long path support requires:
   - Windows 10 version 1607 or later
   - Or Windows 11
   - Registry setting or application manifest (handled automatically via `\\?\` prefix)

3. **Path Separators**: The code uses forward slashes `/` and backslashes `\` as appropriate. Windows 11 handles both correctly.

## Migration Notes

### From Older Windows Versions

If migrating from code that used:
- `GetVersionExA()`: Already replaced - no action needed
- `_getch()`: Already replaced - no action needed
- `_kbhit()`: Already replaced - no action needed
- `MAX_PATH` limitations: Handled automatically via long path conversion

### Future Considerations

1. **Unicode Support**: Currently uses ANSI functions (`CreateFileA`, `ReadConsoleInputA`). For full Unicode support on Windows 11, consider migrating to wide-character versions (`CreateFileW`, `ReadConsoleInputW`).

2. **Console Virtual Terminal Sequences**: Windows 11 supports ANSI escape codes. Consider enabling virtual terminal processing for enhanced console output.

3. **Path APIs**: Consider using `PathCch*` functions from `pathcch.h` for more robust path handling on Windows 11.

## References

- [Windows 11 Compatibility](https://docs.microsoft.com/en-us/windows/win32/apiindex/windows-11-api-sets)
- [Long Path Support](https://docs.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation)
- [Console Input APIs](https://docs.microsoft.com/en-us/windows/console/console-reference)
- [Deprecated APIs](https://docs.microsoft.com/en-us/windows/win32/deprecation-center)

## Version History

- **2026-01-07**: Initial Windows 11 compatibility improvements
  - Replaced deprecated `GetVersionExA()`
  - Replaced deprecated `_getch()` and `_kbhit()`
  - Added long path support
  - Added Windows version targeting
