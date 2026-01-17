# Script to verify Bitdefender exclusions
# This script helps verify Cursor paths exist

Write-Host "=== Verifying Cursor Installation ===" -ForegroundColor Cyan
Write-Host ""

$cursorPaths = @(
    "C:\Program Files\cursor\Cursor.exe",
    "C:\Program Files\cursor\resources\app",
    "$env:APPDATA\Cursor"
)

$allFound = $true
foreach ($path in $cursorPaths) {
    if (Test-Path $path) {
        Write-Host "Found: $path" -ForegroundColor Green
    } else {
        Write-Host "Missing: $path" -ForegroundColor Red
        $allFound = $false
    }
}

Write-Host ""
if ($allFound) {
    Write-Host "All Cursor paths exist. Ready to add to Bitdefender exclusions." -ForegroundColor Green
} else {
    Write-Host "Some paths are missing. Check your Cursor installation." -ForegroundColor Yellow
}

Write-Host ""
Write-Host "=== Next Steps ===" -ForegroundColor Cyan
Write-Host "1. Open Bitdefender (look for icon in system tray)" -ForegroundColor White
Write-Host "2. Go to: Protection -> Antivirus -> Exclusions" -ForegroundColor White
Write-Host "3. Add the paths listed above" -ForegroundColor White
Write-Host "4. See STEP1_BITDEFENDER_EXCLUSIONS.md for detailed instructions" -ForegroundColor White
Write-Host ""

# Check if Bitdefender processes are running
Write-Host "=== Bitdefender Status ===" -ForegroundColor Cyan
$bdProcesses = Get-Process | Where-Object {$_.Path -like "*bitdefender*"} | Select-Object ProcessName
if ($bdProcesses) {
    Write-Host "Bitdefender processes running:" -ForegroundColor Green
    $bdProcesses | ForEach-Object { Write-Host "  - $($_.ProcessName)" -ForegroundColor White }
} else {
    Write-Host "No Bitdefender processes found (may be running as service)" -ForegroundColor Yellow
}

Write-Host ""
Write-Host "To open Bitdefender:" -ForegroundColor Cyan
Write-Host "  - Look for Bitdefender icon in system tray" -ForegroundColor White
Write-Host "  - Right-click and select Open Bitdefender" -ForegroundColor White
Write-Host "  - OR search Bitdefender in Windows Start menu" -ForegroundColor White
Write-Host ""
