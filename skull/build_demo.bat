@echo off
REM Build script for Window Demo
REM Simple test to verify the window system works

echo Setting up MSVC environment...
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"

if %ERRORLEVEL% NEQ 0 (
    echo Failed to set up MSVC environment
    exit /b 1
)

echo.
echo Compiling Window Demo...
echo.

REM Compile demo
cl /W3 /O2 /MD /Fe:window_demo.exe ^
   test_window_demo.c ^
   game_window.c ^
   /D_WIN32 ^
   /wd4244 /wd4312 /wd4996 ^
   /link kernel32.lib user32.lib gdi32.lib

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo BUILD SUCCESSFUL!
    echo ========================================
    echo Executable: window_demo.exe
    if exist window_demo.exe (
        dir window_demo.exe | find "window_demo.exe"
    )
    echo.
    echo Run: window_demo.exe
) else (
    echo.
    echo ========================================
    echo BUILD FAILED!
    echo ========================================
)

echo.
pause
