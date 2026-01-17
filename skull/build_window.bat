@echo off
REM Build script for Skull Game with Window Support
REM Compiles the GUI version with windowed display option

echo Setting up MSVC environment...
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"

if %ERRORLEVEL% NEQ 0 (
    echo Failed to set up MSVC environment
    exit /b 1
)

echo.
echo Compiling Skull Game (Window Version)...
echo.

REM Compile with window support
cl /W3 /O2 /MD /Fe:skull_window.exe ^
   main_window.c ^
   game_window.c ^
   display_adapter.c ^
   dos_compat.c ^
   skull_ported.c ^
   function_stubs.c ^
   /D_WIN32 ^
   /wd4244 /wd4312 /wd4013 /wd4311 /wd4101 /wd4142 /wd4047 /wd4024 /wd4018 /wd4146 /wd4554 /wd4700 /wd4996 ^
   /link kernel32.lib user32.lib gdi32.lib

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo BUILD SUCCESSFUL!
    echo ========================================
    echo Executable: skull_window.exe
    if exist skull_window.exe (
        dir skull_window.exe | find "skull_window.exe"
    )
    echo.
    echo Usage:
    echo   skull_window.exe          - Choose mode at startup
    echo   skull_window.exe --window - Launch in window mode
    echo   skull_window.exe --console - Launch in console mode
    echo   skull_window.exe --help   - Show help
) else (
    echo.
    echo ========================================
    echo BUILD FAILED!
    echo ========================================
)

echo.
pause
