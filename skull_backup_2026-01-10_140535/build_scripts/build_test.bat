@echo off
REM Build script for test_functions.exe

echo Setting up MSVC environment...
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"

if %ERRORLEVEL% NEQ 0 (
    echo Failed to set up MSVC environment
    exit /b 1
)

echo.
echo Compiling Test Program...
echo.

REM Compile test program (exclude main.c to avoid multiple main() definitions)
cl /W3 /O2 /MD /Fe:test_functions.exe test_functions.c dos_compat.c skull_ported.c function_stubs.c /wd4244 /wd4312 /wd4013 /wd4311 /wd4101 /wd4142 /wd4047 /wd4024 /wd4018 /wd4146 /wd4554 /wd4700 /wd4996 /link kernel32.lib user32.lib

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo BUILD SUCCESSFUL!
    echo ========================================
    echo Executable: test_functions.exe
    if exist test_functions.exe (
        dir test_functions.exe | find "test_functions.exe"
    )
) else (
    echo.
    echo ========================================
    echo BUILD FAILED!
    echo ========================================
)

echo.
pause