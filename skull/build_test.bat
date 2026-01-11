@echo off
setlocal enabledelayedexpansion
REM Build script for test_functions.exe with automatic git commit

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
    
    echo.
    echo ========================================
    echo Committing .c source file changes to git...
    echo ========================================
    
    REM Change to repository root
    cd /d "%~dp0.."
    
    REM Check if git is initialized
    git rev-parse --git-dir >nul 2>&1
    if %ERRORLEVEL% NEQ 0 (
        echo Git not initialized. Initializing...
        git init
    )
    
    REM Add all .c files in skull directory (use for loop to handle wildcards)
    for %%f in (skull\*.c) do (
        git add "%%f"
    )
    
    REM Check if there are any changes to commit
    git diff --cached --quiet
    if %ERRORLEVEL% EQU 0 (
        echo No .c file changes to commit.
    ) else (
        REM Create commit message with timestamp
        for /f "tokens=2 delims==" %%I in ('wmic os get localdatetime /value') do set datetime=%%I
        set timestamp=%datetime:~0,4%-%datetime:~4,2%-%datetime:~6,2% %datetime:~8,2%:%datetime:~10,2%:%datetime:~12,2%
        
        REM Get list of changed files for commit message
        git diff --cached --name-only > temp_changed_files.txt
        set changed_files=
        for /f %%f in (temp_changed_files.txt) do (
            set changed_files=!changed_files! %%f
        )
        del temp_changed_files.txt
        
        REM Commit with descriptive message
        git commit -m "Auto-commit: Source changes after successful compile (%timestamp%)" -m "Changed files:%changed_files%"
        
        if %ERRORLEVEL% EQU 0 (
            echo.
            echo ========================================
            echo Git commit successful!
            echo ========================================
            git log -1 --oneline
        ) else (
            echo.
            echo ========================================
            echo Git commit failed!
            echo ========================================
        )
    )
    
    REM Return to skull directory
    cd /d "%~dp0"
) else (
    echo.
    echo ========================================
    echo BUILD FAILED!
    echo ========================================
    echo Skipping git commit due to build failure.
    echo ========================================
)

echo.
pause