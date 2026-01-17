@echo off
REM Simple batch wrapper to run tests and update TESTING_PLAN.md
REM Usage: run_tests_and_update.bat
REM This script runs automatically with no user prompts (keep all changes mode)

cd /d "%~dp0"
powershell.exe -ExecutionPolicy Bypass -NoProfile -WindowStyle Hidden -File "update_testing_plan.ps1" -RunTests -UpdatePlan -Force
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Script completed with errors (exit code: %ERRORLEVEL%)
    pause
)
