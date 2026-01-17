@echo off
REM Test Progress Tracker for Skull Game Function Testing
REM This script helps track which function sets have been tested

echo ========================================
echo Skull Game Function Testing Progress
echo ========================================
echo.

REM Read the testing plan and extract status
findstr /C:"Status:" TESTING_PLAN.md | findstr /C:"COMPLETED" >nul
if %ERRORLEVEL% EQU 0 (
    echo Found completed sets in TESTING_PLAN.md
) else (
    echo No completed sets found
)

echo.
echo Current Test Status:
echo.

REM Count completed sets
findstr /C:"COMPLETED" TESTING_PLAN.md | find /C "COMPLETED" > temp_count.txt
set /p COMPLETED_COUNT=<temp_count.txt
del temp_count.txt

REM Count pending sets
findstr /C:"PENDING" TESTING_PLAN.md | find /C "PENDING" > temp_count.txt
set /p PENDING_COUNT=<temp_count.txt
del temp_count.txt

echo Completed Sets: %COMPLETED_COUNT%
echo Pending Sets: %PENDING_COUNT%
echo.

echo To view full details, open TESTING_PLAN.md
echo.
echo To run tests:
echo   cd skull
echo   .\build_test.bat
echo   .\test_functions.exe
echo.

pause
