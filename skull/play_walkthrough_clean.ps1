#!/usr/bin/env pwsh
<#
.SYNOPSIS
    Runs the Skullduggery walkthrough with clean player-focused output
    
.DESCRIPTION
    This script runs the ultimate walkthrough and separates:
    - Player view (stdout): Commands and game responses only
    - Debug log (stderr): All technical/debug information
    
.EXAMPLE
    .\play_walkthrough_clean.ps1
#>

param(
    [string]$WalkthroughFile = "ultimate_walkthrough_commands.txt",
    [string]$CleanOutputFile = "walkthrough_player_view.txt",
    [string]$DebugLogFile = "walkthrough_debug.log"
)

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "  🏴‍☠️ SKULLDUGGERY - CLEAN WALKTHROUGH 🏴‍☠️" -ForegroundColor Green
Write-Host "========================================`n" -ForegroundColor Cyan

Write-Host "Walkthrough File: $WalkthroughFile" -ForegroundColor White
Write-Host "Player View Output: $CleanOutputFile" -ForegroundColor Green
Write-Host "Debug Log: $DebugLogFile" -ForegroundColor Yellow
Write-Host ""

# Check if walkthrough file exists
if (-not (Test-Path $WalkthroughFile)) {
    Write-Host "ERROR: Walkthrough file not found: $WalkthroughFile" -ForegroundColor Red
    exit 1
}

# Check if game executable exists
if (-not (Test-Path "skull.exe")) {
    Write-Host "ERROR: skull.exe not found. Please build the game first." -ForegroundColor Red
    exit 1
}

Write-Host "Running walkthrough..." -ForegroundColor Yellow
$startTime = Get-Date

# Run the game with:
# - stdin from walkthrough file
# - stdout to clean output file (player view)
# - stderr to debug log file (technical info)
Get-Content $WalkthroughFile | .\skull.exe > $CleanOutputFile 2> $DebugLogFile

$endTime = Get-Date
$duration = $endTime - $startTime

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "  WALKTHROUGH COMPLETE!" -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Cyan

Write-Host "Duration: $([math]::Round($duration.TotalSeconds, 2)) seconds" -ForegroundColor Yellow

# Analyze output
if (Test-Path $CleanOutputFile) {
    $playerLines = Get-Content $CleanOutputFile
    $totalLines = $playerLines.Count
    $commands = ($playerLines | Select-String -Pattern "^> ").Count
    $responses = ($playerLines | Select-String -Pattern "^[^>]" | Where-Object { $_.Line -match "\w" }).Count
    
    Write-Host "`nPlayer View:" -ForegroundColor Cyan
    Write-Host "  Total Lines: $totalLines" -ForegroundColor White
    Write-Host "  Commands: $commands" -ForegroundColor Green
    Write-Host "  Game Responses: $responses" -ForegroundColor Green
    
    Write-Host "`nFirst 20 lines of player view:" -ForegroundColor Cyan
    Get-Content $CleanOutputFile -Head 20 | ForEach-Object {
        if ($_ -match "^> ") {
            Write-Host $_ -ForegroundColor Yellow
        } else {
            Write-Host $_ -ForegroundColor White
        }
    }
    
    Write-Host "`n..." -ForegroundColor Gray
    
    Write-Host "`nLast 20 lines of player view:" -ForegroundColor Cyan
    Get-Content $CleanOutputFile -Tail 20 | ForEach-Object {
        if ($_ -match "^> ") {
            Write-Host $_ -ForegroundColor Yellow
        } else {
            Write-Host $_ -ForegroundColor White
        }
    }
}

if (Test-Path $DebugLogFile) {
    $debugLines = Get-Content $DebugLogFile
    Write-Host "`nDebug Log:" -ForegroundColor Cyan
    Write-Host "  Total Lines: $($debugLines.Count)" -ForegroundColor White
    Write-Host "  Errors: $(($debugLines | Select-String -Pattern "ERROR:").Count)" -ForegroundColor $(if ((($debugLines | Select-String -Pattern "ERROR:").Count) -gt 0) {"Red"} else {"Green"})
}

Write-Host "`nOutput files created:" -ForegroundColor Green
Write-Host "  Player View: $CleanOutputFile" -ForegroundColor White
Write-Host "  Debug Log: $DebugLogFile" -ForegroundColor White
Write-Host ""
