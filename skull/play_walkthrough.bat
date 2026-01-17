@echo off
REM Automatic walkthrough/demo mode for Skull Game
REM Plays through a predefined sequence of commands

echo ========================================
echo Skull Game - Automatic Walkthrough
echo ========================================
echo.
echo This will run the game with a predefined
echo sequence of commands for testing/demo.
echo.
echo Press any key to start...
pause >nul

echo.
echo Starting walkthrough...
echo.

REM Run the game with commands from walkthrough.txt
type walkthrough.txt | skull.exe

echo.
echo ========================================
echo Walkthrough Complete!
echo ========================================
echo.
pause
