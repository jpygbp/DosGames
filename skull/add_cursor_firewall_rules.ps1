# Script to add Windows Firewall rules for Cursor
# Requires Administrator privileges

Write-Host "=== Adding Windows Firewall Rules for Cursor ===" -ForegroundColor Cyan
Write-Host ""

# Check if running as Administrator
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)

if (-not $isAdmin) {
    Write-Host "ERROR: This script requires Administrator privileges!" -ForegroundColor Red
    Write-Host "Please run PowerShell as Administrator and try again." -ForegroundColor Yellow
    Write-Host ""
    Write-Host "To run as Administrator:" -ForegroundColor Cyan
    Write-Host "  1. Right-click PowerShell" -ForegroundColor White
    Write-Host "  2. Select 'Run as Administrator'" -ForegroundColor White
    Write-Host "  3. Navigate to this directory" -ForegroundColor White
    Write-Host "  4. Run: .\add_cursor_firewall_rules.ps1" -ForegroundColor White
    exit 1
}

Write-Host "Administrator privileges confirmed." -ForegroundColor Green
Write-Host ""

# Cursor executable path
$cursorPath = "C:\Program Files\cursor\Cursor.exe"

# Check if Cursor exists
if (-not (Test-Path $cursorPath)) {
    Write-Host "WARNING: Cursor not found at: $cursorPath" -ForegroundColor Yellow
    Write-Host "Please verify the path is correct." -ForegroundColor Yellow
    Write-Host ""
    $continue = Read-Host "Continue anyway? (y/n)"
    if ($continue -ne "y" -and $continue -ne "Y") {
        exit 1
    }
} else {
    Write-Host "Found Cursor at: $cursorPath" -ForegroundColor Green
}

Write-Host ""
Write-Host "Creating firewall rules..." -ForegroundColor Cyan

# Remove existing rules if they exist (to avoid duplicates)
Write-Host "Checking for existing rules..." -ForegroundColor Yellow
$existingRules = @(
    "Cursor HTTPS Outbound",
    "Cursor HTTP Outbound",
    "Cursor All Outbound"
)

foreach ($ruleName in $existingRules) {
    $existing = Get-NetFirewallRule -DisplayName $ruleName -ErrorAction SilentlyContinue
    if ($existing) {
        Write-Host "  Removing existing rule: $ruleName" -ForegroundColor Yellow
        Remove-NetFirewallRule -DisplayName $ruleName -ErrorAction SilentlyContinue
    }
}

Write-Host ""

# Rule 1: HTTPS Outbound (Port 443)
try {
    New-NetFirewallRule -DisplayName "Cursor HTTPS Outbound" `
        -Direction Outbound `
        -Program $cursorPath `
        -Action Allow `
        -Protocol TCP `
        -LocalPort Any `
        -RemotePort 443 `
        -Profile Any `
        -Description "Allow Cursor to make HTTPS connections (port 443) for AI features and updates" `
        -ErrorAction Stop
    
    Write-Host "  Created: Cursor HTTPS Outbound (Port 443)" -ForegroundColor Green
} catch {
    Write-Host "  ERROR creating HTTPS rule: $($_.Exception.Message)" -ForegroundColor Red
}

# Rule 2: HTTP Outbound (Port 80) - for fallback/updates
try {
    New-NetFirewallRule -DisplayName "Cursor HTTP Outbound" `
        -Direction Outbound `
        -Program $cursorPath `
        -Action Allow `
        -Protocol TCP `
        -LocalPort Any `
        -RemotePort 80 `
        -Profile Any `
        -Description "Allow Cursor to make HTTP connections (port 80) for updates and fallback" `
        -ErrorAction Stop
    
    Write-Host "  Created: Cursor HTTP Outbound (Port 80)" -ForegroundColor Green
} catch {
    Write-Host "  ERROR creating HTTP rule: $($_.Exception.Message)" -ForegroundColor Red
}

# Rule 3: Allow all outbound (broader rule for any other ports Cursor might need)
try {
    New-NetFirewallRule -DisplayName "Cursor All Outbound" `
        -Direction Outbound `
        -Program $cursorPath `
        -Action Allow `
        -Protocol Any `
        -Profile Any `
        -Description "Allow Cursor all outbound network access" `
        -ErrorAction Stop
    
    Write-Host "  Created: Cursor All Outbound (All protocols)" -ForegroundColor Green
} catch {
    Write-Host "  ERROR creating general outbound rule: $($_.Exception.Message)" -ForegroundColor Red
}

Write-Host ""
Write-Host "=== Verification ===" -ForegroundColor Cyan

# Verify rules were created
$rules = Get-NetFirewallRule -DisplayName "Cursor*" | Where-Object {$_.Enabled -eq $true}
if ($rules) {
    Write-Host "Active Cursor firewall rules:" -ForegroundColor Green
    $rules | ForEach-Object {
        $status = if ($_.Enabled) { "Enabled" } else { "Disabled" }
        Write-Host "  - $($_.DisplayName): $status" -ForegroundColor White
    }
} else {
    Write-Host "WARNING: No Cursor firewall rules found!" -ForegroundColor Yellow
}

Write-Host ""
Write-Host "=== Next Steps ===" -ForegroundColor Cyan
Write-Host "1. Restart Cursor to apply firewall rules" -ForegroundColor White
Write-Host "2. Test Cursor connectivity" -ForegroundColor White
Write-Host "3. If timeouts persist, check:" -ForegroundColor White
Write-Host "   - Bitdefender exclusions (Step 1)" -ForegroundColor Yellow
Write-Host "   - DNS settings (Step 3)" -ForegroundColor Yellow
Write-Host "   - Network proxy settings" -ForegroundColor Yellow
Write-Host ""

# Test connectivity
Write-Host "Testing Cursor connectivity..." -ForegroundColor Cyan
$testResult = Test-NetConnection -ComputerName cursor.sh -Port 443 -WarningAction SilentlyContinue
if ($testResult.TcpTestSucceeded) {
    Write-Host "  Connectivity test: SUCCESS" -ForegroundColor Green
} else {
    Write-Host "  Connectivity test: FAILED" -ForegroundColor Red
    Write-Host "  This may indicate other issues (DNS, Bitdefender, etc.)" -ForegroundColor Yellow
}

Write-Host ""
Write-Host "Firewall rules configuration complete!" -ForegroundColor Green
Write-Host ""




