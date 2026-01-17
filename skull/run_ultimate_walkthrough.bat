@echo off
REM Ultimate Walkthrough - Automated Playthrough
REM Based on ULTIMATE_WALKTHROUGH.md

echo.
echo ================================================================
echo     SKULLDUGGERY - Ultimate Automated Walkthrough
echo ================================================================
echo.

if not exist skull.exe (
    echo [ERROR] skull.exe not found!
    echo Please run this script from the skull directory.
    pause
    exit /b 1
)

if not exist ultimate_walkthrough_commands.txt (
    echo [ERROR] ultimate_walkthrough_commands.txt not found!
    pause
    exit /b 1
)

echo [INFO] Running automated walkthrough...
echo [INFO] This will pipe commands from ultimate_walkthrough_commands.txt
echo.
echo WALKTHROUGH PHASES:
echo   Phase 1: Getting Started (Underground Tunnel)
echo   Phase 2: Exploring the Estate
echo   Phase 3: Critical Items Collection
echo   Phase 4: The Potion Quest
echo   Phase 5: Dealing with Uncle Henri (Vampire)
echo   Phase 6: The Mausoleum Puzzle
echo   Phase 7: Underground Exploration
echo   Phase 8: The Inferno and Altar
echo   Phase 9: The Styx River Journey
echo   Phase 10: Confronting William's Ghost
echo   Phase 11: Finding the Treasure
echo   Phase 12: The Ending
echo.
echo ESTIMATED TIME: 5-10 minutes
echo.
echo Press any key to start...
pause >nul

echo.
echo ================================================================
echo                    STARTING WALKTHROUGH...
echo ================================================================
echo.

REM Run the game with piped input
skull.exe < ultimate_walkthrough_commands.txt

echo.
echo ================================================================
echo           ULTIMATE WALKTHROUGH COMPLETE!
echo ================================================================
echo.

echo [INFO] Walkthrough finished
echo [INFO] Check the output above for results
echo.
echo NOTE: The game may have exited early if it encountered an error
echo       or if certain conditions weren't met.
echo.
echo For detailed explanations of each step, see:
echo   ULTIMATE_WALKTHROUGH.md
echo.

pause
