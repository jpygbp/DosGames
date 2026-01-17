@echo off
REM Build script for Skull Game - 64-bit Windows

echo Building Skull Game for 64-bit Windows...

REM Check for CMake
where cmake >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo CMake not found. Please install CMake or use Visual Studio.
    echo.
    echo Creating simple build with MSVC...
    goto :msvc_build
)

REM Create build directory
if not exist build mkdir build
cd build

REM Configure with CMake
cmake .. -G "Visual Studio 17 2022" -A x64
if %ERRORLEVEL% NEQ 0 (
    echo CMake configuration failed. Trying without generator...
    cmake .. -A x64
)

REM Build
cmake --build . --config Release
if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! Executable is in build\bin\Release\skull.exe
    cd ..
    
    REM Create backup - check multiple possible locations
    set BACKUP_DONE=0
    if exist build\bin\Release\skull.exe (
        call :create_backup build\bin\Release\skull.exe
        set BACKUP_DONE=1
    )
    if exist build\bin\Debug\skull.exe (
        if %BACKUP_DONE% EQU 0 (
            call :create_backup build\bin\Debug\skull.exe
            set BACKUP_DONE=1
        )
    )
    if exist build\bin\skull.exe (
        if %BACKUP_DONE% EQU 0 (
            call :create_backup build\bin\skull.exe
            set BACKUP_DONE=1
        )
    )
    if exist build\Release\skull.exe (
        if %BACKUP_DONE% EQU 0 (
            call :create_backup build\Release\skull.exe
            set BACKUP_DONE=1
        )
    )
    if exist build\Debug\skull.exe (
        if %BACKUP_DONE% EQU 0 (
            call :create_backup build\Debug\skull.exe
            set BACKUP_DONE=1
        )
    )
    if %BACKUP_DONE% EQU 0 (
        echo Warning: Could not find executable to backup.
    )
    
    exit /b 0
)

cd ..
echo CMake build failed, trying direct compilation...
goto :msvc_build

:msvc_build
REM Try to find MSVC compiler
where cl >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo MSVC compiler not found in PATH.
    echo Please run this from a Visual Studio Developer Command Prompt, or
    echo install CMake and a C compiler (MSVC, MinGW, or Clang).
    echo.
    echo For Visual Studio:
    echo   1. Open "Developer Command Prompt for VS"
    echo   2. Navigate to this directory
    echo   3. Run: build.bat
    echo.
    echo For MinGW:
    echo   1. Install MinGW-w64
    echo   2. Add to PATH
    echo   3. Run: gcc -o skull.exe dos_compat.c skull_ported.c -luser32 -lkernel32
    exit /b 1
)

echo Compiling with MSVC...
cl /W3 /O2 /MD /Fe:skull.exe dos_compat.c main.c skull_ported.c function_stubs.c /wd4244 /wd4312 /wd4013 /wd4311 /wd4101 /wd4142 /wd4047 /wd4024 /wd4018 /wd4146 /wd4554 /wd4700 /wd4996 /link kernel32.lib user32.lib
if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! Executable is skull.exe
    
    REM Create backup
    call :create_backup skull.exe
    if %ERRORLEVEL% EQU 0 (
        echo Backup created successfully.
    )
    
    exit /b 0
) else (
    echo.
    echo Compilation failed. Please check the errors above.
    exit /b 1
)

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

