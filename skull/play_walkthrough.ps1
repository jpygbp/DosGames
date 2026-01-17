# Automatic Walkthrough Script for Skull Game
# Runs the game with predefined commands and captures output

param(
    [string]$WalkthroughFile = "walkthrough.txt",
    [int]$DelayMs = 1000,
    [switch]$ShowOutput = $true,
    [switch]$SaveLog = $true
)

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "Skull Game - Automatic Walkthrough" -ForegroundColor Green
Write-Host "========================================`n" -ForegroundColor Cyan

# Check if game executable exists
if (-not (Test-Path "skull.exe")) {
    Write-Host "ERROR: skull.exe not found!" -ForegroundColor Red
    Write-Host "Please run this script from the skull directory." -ForegroundColor Yellow
    exit 1
}

# Check if walkthrough file exists
if (-not (Test-Path $WalkthroughFile)) {
    Write-Host "ERROR: Walkthrough file '$WalkthroughFile' not found!" -ForegroundColor Red
    exit 1
}

# Read commands from walkthrough file
$commands = Get-Content $WalkthroughFile

Write-Host "Walkthrough Configuration:" -ForegroundColor Yellow
Write-Host "  File: $WalkthroughFile" -ForegroundColor White
Write-Host "  Commands: $($commands.Count)" -ForegroundColor White
Write-Host "  Delay: ${DelayMs}ms between commands" -ForegroundColor White
Write-Host "  Output: $(if ($ShowOutput) { 'Shown' } else { 'Hidden' })" -ForegroundColor White
Write-Host "  Log: $(if ($SaveLog) { 'Saved' } else { 'Not saved' })`n" -ForegroundColor White

Write-Host "Commands to execute:" -ForegroundColor Yellow
foreach ($cmd in $commands) {
    Write-Host "  > $cmd" -ForegroundColor Cyan
}
Write-Host ""

Write-Host "Press any key to start walkthrough..." -ForegroundColor Yellow
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
Write-Host ""

# Prepare log file if requested
$logFile = "walkthrough_$(Get-Date -Format 'yyyyMMdd_HHmmss').log"

Write-Host "Starting walkthrough...`n" -ForegroundColor Green

# Run the game with commands
try {
    if ($SaveLog) {
        Write-Host "Running game and saving output to $logFile..." -ForegroundColor Yellow
        $commands -join "`n" | .\skull.exe 2>&1 | Tee-Object -FilePath $logFile
    } else {
        Write-Host "Running game..." -ForegroundColor Yellow
        $commands -join "`n" | .\skull.exe 2>&1
    }
    
    $exitCode = $LASTEXITCODE
    
    Write-Host "`n========================================" -ForegroundColor Cyan
    if ($exitCode -eq 0) {
        Write-Host "Walkthrough Completed Successfully!" -ForegroundColor Green
    } else {
        Write-Host "Walkthrough Completed (Exit Code: $exitCode)" -ForegroundColor Yellow
    }
    Write-Host "========================================`n" -ForegroundColor Cyan
    
    if ($SaveLog) {
        Write-Host "Log saved to: $logFile" -ForegroundColor Green
        Write-Host "File size: $((Get-Item $logFile).Length) bytes`n" -ForegroundColor White
    }
    
} catch {
    Write-Host "`nERROR: Walkthrough failed!" -ForegroundColor Red
    Write-Host $_.Exception.Message -ForegroundColor Red
    exit 1
}

Write-Host "Press any key to exit..." -ForegroundColor Yellow
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
