@echo off
REM Simple test build script
REM Run this from Visual Studio Developer Command Prompt

echo Testing compilation...
echo.

cl /W3 /O2 /MD /Fe:skull.exe dos_compat.c main.c skull_ported.c function_stubs.c /link kernel32.lib user32.lib /wd4244 /wd4312 /wd4013 2>&1 | tee build_output.txt

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo BUILD SUCCESSFUL!
    echo ========================================
    echo Executable: skull.exe
) else (
    echo.
    echo ========================================
    echo BUILD FAILED - Check build_output.txt
    echo ========================================
)

pause


