# Script to help add Cursor to Bitdefender Exclusions
# Note: This script will attempt to open Bitdefender, but you'll need to manually add the exclusions

Write-Host "=== Adding Cursor to Bitdefender Exclusions ===" -ForegroundColor Cyan
Write-Host ""

# Check if Cursor is installed
$cursorPath = "C:\Program Files\cursor\Cursor.exe"
if (-not (Test-Path $cursorPath)) {
    Write-Host "ERROR: Cursor not found at: $cursorPath" -ForegroundColor Red
    Write-Host "Please check your Cursor installation path." -ForegroundColor Yellow
    exit 1
}

Write-Host "✓ Cursor found at: $cursorPath" -ForegroundColor Green
Write-Host ""

# Paths to exclude
$pathsToExclude = @(
    "C:\Program Files\cursor\Cursor.exe",
    "C:\Program Files\cursor\resources\app\**\*",
    "$env:APPDATA\Cursor\**\*"
)

Write-Host "Paths that should be added to Bitdefender exclusions:" -ForegroundColor Yellow
foreach ($path in $pathsToExclude) {
    Write-Host "  - $path" -ForegroundColor White
}
Write-Host ""

# Try to open Bitdefender
Write-Host "Attempting to open Bitdefender..." -ForegroundColor Cyan
$bdPaths = @(
    "C:\Program Files\Bitdefender\Bitdefender Security\bdagent.exe",
    "C:\Program Files\Bitdefender\Bitdefender Security\bdwsc.exe",
    "C:\Program Files (x86)\Bitdefender\Bitdefender Security\bdagent.exe"
)

$opened = $false
foreach ($bdPath in $bdPaths) {
    if (Test-Path $bdPath) {
        try {
            Start-Process $bdPath
            $opened = $true
            Write-Host "✓ Opened Bitdefender at: $bdPath" -ForegroundColor Green
            break
        } catch {
            Write-Host "Could not open: $bdPath" -ForegroundColor Yellow
        }
    }
}

if (-not $opened) {
    Write-Host "Could not automatically open Bitdefender." -ForegroundColor Yellow
    Write-Host "Please open Bitdefender manually." -ForegroundColor Yellow
}

Write-Host ""
Write-Host "=== MANUAL STEPS ===" -ForegroundColor Cyan
Write-Host ""
Write-Host "1. In Bitdefender, go to: Protection → Antivirus → Exclusions" -ForegroundColor White
Write-Host "2. Click 'Add' or 'Add Exception'" -ForegroundColor White
Write-Host "3. Add these paths one by one:" -ForegroundColor White
Write-Host ""
foreach ($path in $pathsToExclude) {
    Write-Host "   • $path" -ForegroundColor Cyan
}
Write-Host ""
Write-Host "4. Make sure to select 'All components' or check:" -ForegroundColor White
Write-Host "   - Real-time Protection" -ForegroundColor Cyan
Write-Host "   - Web Protection" -ForegroundColor Cyan
Write-Host "   - Advanced Threat Defense" -ForegroundColor Cyan
Write-Host ""
Write-Host "5. Click 'Save' or 'Apply'" -ForegroundColor White
Write-Host "6. Restart Cursor after adding exclusions" -ForegroundColor White
Write-Host ""
Write-Host "Press any key to continue after you've added the exclusions..."
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

Write-Host ""
Write-Host "=== Verification ===" -ForegroundColor Cyan
Write-Host "After adding exclusions, test Cursor connectivity:" -ForegroundColor Yellow
Write-Host "  Test-NetConnection -ComputerName cursor.sh -Port 443" -ForegroundColor White
Write-Host ""




