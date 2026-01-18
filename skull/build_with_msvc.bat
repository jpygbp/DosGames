@echo off
REM Build script that sets up MSVC environment and compiles

echo Setting up MSVC environment...
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"

if %ERRORLEVEL% NEQ 0 (
    echo Failed to set up MSVC environment
    exit /b 1
)

echo.
echo Compiling Skull Game...
echo.

cl /W3 /O2 /MD /Fe:skull.exe dos_compat.c main.c skull_ported.c function_stubs.c display_adapter.c game_window.c simple_game_engine.c /wd4244 /wd4312 /wd4013 /wd4311 /wd4101 /wd4142 /wd4047 /wd4024 /wd4018 /wd4146 /wd4554 /wd4700 /wd4996 /link kernel32.lib user32.lib gdi32.lib > build_output.txt 2>&1
type build_output.txt

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo BUILD SUCCESSFUL!
    echo ========================================
    echo Executable: skull.exe
    if exist skull.exe (
        echo File size: 
        dir skull.exe | find "skull.exe"
    )
    
    REM Backup disabled - uncomment below to enable automatic backups
    REM call :create_backup skull.exe
    REM if %ERRORLEVEL% EQU 0 (
    REM     echo Backup created successfully.
    REM )
) else (
    echo.
    echo ========================================
    echo BUILD FAILED
    echo ========================================
    echo Check build_output.txt for details
    echo.
    echo First 50 lines of errors:
    type build_output.txt | findstr /C:"error" | more
)

pause
exit /b 0

:create_backup
REM Backup function - creates timestamped backup of executable
REM Usage: call :create_backup <filepath>
if "%~1"=="" exit /b 1

REM Check if file exists
if not exist "%~1" (
    echo Warning: File %~1 does not exist, skipping backup.
    exit /b 1
)

REM Create backups directory if it doesn't exist
if not exist backups mkdir backups

REM Generate timestamp (YYYYMMDD_HHMMSS)
for /f "tokens=2 delims==" %%I in ('wmic os get localdatetime /value') do set datetime=%%I
set timestamp=%datetime:~0,8%_%datetime:~8,6%

REM Get filename without path
for %%F in ("%~1") do set filename=%%~nxF
set backupname=backups\%~n1_%timestamp%%~x1

REM Copy file to backup location
copy /Y "%~1" "%backupname%" >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo Backup saved: %backupname%
    exit /b 0
) else (
    echo Warning: Failed to create backup.
    exit /b 1
)
exit /b 0

