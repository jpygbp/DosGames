# Ultimate Walkthrough - Automated Playthrough
# Based on ULTIMATE_WALKTHROUGH.md
# Plays through the complete game solution

param(
    [switch]$Verbose,
    [switch]$SaveLog,
    [int]$DelayMs = 100
)

Write-Host "`n╔════════════════════════════════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "║" -ForegroundColor Cyan -NoNewline
Write-Host "        SKULLDUGGERY - Ultimate Automated Walkthrough            " -ForegroundColor Green -NoNewline
Write-Host "║" -ForegroundColor Cyan
Write-Host "╚════════════════════════════════════════════════════════════════╝" -ForegroundColor Cyan
Write-Host ""

# Check if game executable exists
if (-not (Test-Path "skull.exe")) {
    Write-Host "[ERROR] skull.exe not found!" -ForegroundColor Red
    Write-Host "Please run this script from the skull directory." -ForegroundColor Yellow
    exit 1
}

# Check if command file exists
if (-not (Test-Path "ultimate_walkthrough_commands.txt")) {
    Write-Host "[ERROR] ultimate_walkthrough_commands.txt not found!" -ForegroundColor Red
    exit 1
}

# Read commands
$commands = Get-Content "ultimate_walkthrough_commands.txt"
Write-Host "[INFO] Loaded $($commands.Count) commands" -ForegroundColor Cyan
Write-Host ""

# Prepare log file
$timestamp = Get-Date -Format "yyyyMMdd_HHmmss"
$logFile = "ultimate_walkthrough_log_$timestamp.txt"

if ($SaveLog) {
    Write-Host "[INFO] Output will be saved to: $logFile" -ForegroundColor Cyan
    Write-Host ""
}

# Display walkthrough info
Write-Host "WALKTHROUGH PHASES:" -ForegroundColor Yellow
Write-Host "  Phase 1: Getting Started (Underground Tunnel)" -ForegroundColor White
Write-Host "  Phase 2: Exploring the Estate" -ForegroundColor White
Write-Host "  Phase 3: Critical Items Collection" -ForegroundColor White
Write-Host "  Phase 4: The Potion Quest" -ForegroundColor White
Write-Host "  Phase 5: Dealing with Uncle Henri (Vampire)" -ForegroundColor White
Write-Host "  Phase 6: The Mausoleum Puzzle" -ForegroundColor White
Write-Host "  Phase 7: Underground Exploration" -ForegroundColor White
Write-Host "  Phase 8: The Inferno and Altar" -ForegroundColor White
Write-Host "  Phase 9: The Styx River Journey" -ForegroundColor White
Write-Host "  Phase 10: Confronting William's Ghost" -ForegroundColor White
Write-Host "  Phase 11: Finding the Treasure" -ForegroundColor White
Write-Host "  Phase 12: The Ending" -ForegroundColor White
Write-Host ""

Write-Host "ESTIMATED TIME: 5-10 minutes" -ForegroundColor Cyan
Write-Host ""

# Confirm start
Write-Host "Press any key to start the automated walkthrough..." -ForegroundColor Yellow
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
Write-Host ""

Write-Host "╔════════════════════════════════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "║" -ForegroundColor Cyan -NoNewline
Write-Host "                    STARTING WALKTHROUGH...                      " -ForegroundColor Green -NoNewline
Write-Host "║" -ForegroundColor Cyan
Write-Host "╚════════════════════════════════════════════════════════════════╝" -ForegroundColor Cyan
Write-Host ""

# Create process start info
$psi = New-Object System.Diagnostics.ProcessStartInfo
$psi.FileName = "skull.exe"
$psi.UseShellExecute = $false
$psi.RedirectStandardInput = $true
$psi.RedirectStandardOutput = $true
$psi.RedirectStandardError = $true
$psi.CreateNoWindow = $false

# Start the game process
try {
    $process = New-Object System.Diagnostics.Process
    $process.StartInfo = $psi
    
    Write-Host "[INFO] Starting game process..." -ForegroundColor Cyan
    $process.Start() | Out-Null
    
    # Get streams
    $stdin = $process.StandardInput
    $stdout = $process.StandardOutput
    $stderr = $process.StandardError
    
    Write-Host "[INFO] Game started successfully" -ForegroundColor Green
    Write-Host ""
    
    # Wait a moment for game to initialize
    Start-Sleep -Milliseconds 500
    
    # Send commands
    $commandCount = 0
    $phaseMarkers = @{
        0 = "Phase 1: Getting Started"
        10 = "Phase 2: Exploring Estate"
        30 = "Phase 3: Collecting Items"
        50 = "Phase 4: Potion Quest"
        70 = "Phase 5: Uncle Henri"
        90 = "Phase 6: Mausoleum"
        110 = "Phase 7: Underground"
        130 = "Phase 8: Inferno"
        150 = "Phase 9: Styx River"
        170 = "Phase 10: Ghost"
        190 = "Phase 11: Treasure"
        210 = "Phase 12: Ending"
    }
    
    foreach ($command in $commands) {
        $commandCount++
        
        # Check for phase markers
        if ($phaseMarkers.ContainsKey($commandCount)) {
            Write-Host "`n[PHASE] $($phaseMarkers[$commandCount])" -ForegroundColor Yellow
            Write-Host "─" * 60 -ForegroundColor DarkGray
        }
        
        if ($Verbose) {
            Write-Host "[CMD $commandCount/$($commands.Count)] $command" -ForegroundColor Cyan
        } else {
            # Show progress every 10 commands
            if ($commandCount % 10 -eq 0) {
                $percent = [math]::Round(($commandCount / $commands.Count) * 100)
                Write-Host "[PROGRESS] $commandCount/$($commands.Count) commands ($percent%)" -ForegroundColor Cyan
            }
        }
        
        # Send command
        $stdin.WriteLine($command)
        
        # Small delay to let game process
        Start-Sleep -Milliseconds $DelayMs
        
        # Try to read output (non-blocking)
        if ($stdout.Peek() -ge 0) {
            $output = $stdout.ReadLine()
            if ($Verbose -and $output) {
                Write-Host "  $output" -ForegroundColor Gray
            }
            
            if ($SaveLog -and $output) {
                Add-Content -Path $logFile -Value "[$commandCount] $command"
                Add-Content -Path $logFile -Value $output
                Add-Content -Path $logFile -Value ""
            }
        }
    }
    
    Write-Host ""
    Write-Host "╔════════════════════════════════════════════════════════════════╗" -ForegroundColor Cyan
    Write-Host "║" -ForegroundColor Cyan -NoNewline
    Write-Host "              WALKTHROUGH COMMANDS COMPLETED!                    " -ForegroundColor Green -NoNewline
    Write-Host "║" -ForegroundColor Cyan
    Write-Host "╚════════════════════════════════════════════════════════════════╝" -ForegroundColor Cyan
    Write-Host ""
    
    Write-Host "[INFO] Sent all $commandCount commands" -ForegroundColor Green
    Write-Host "[INFO] Waiting for game to finish..." -ForegroundColor Cyan
    
    # Wait for process to exit or timeout
    $timeout = 10000 # 10 seconds
    if ($process.WaitForExit($timeout)) {
        Write-Host "[INFO] Game exited with code: $($process.ExitCode)" -ForegroundColor Cyan
    } else {
        Write-Host "[WARN] Game still running after timeout" -ForegroundColor Yellow
        Write-Host "[INFO] You can close the game window manually" -ForegroundColor Cyan
    }
    
    # Read any remaining output
    if (-not $process.HasExited) {
        Write-Host ""
        Write-Host "[INFO] Reading final output..." -ForegroundColor Cyan
        
        # Try to read remaining output
        $finalOutput = @()
        while ($stdout.Peek() -ge 0) {
            $line = $stdout.ReadLine()
            $finalOutput += $line
            if ($Verbose) {
                Write-Host "  $line" -ForegroundColor Gray
            }
        }
        
        if ($SaveLog -and $finalOutput.Count -gt 0) {
            Add-Content -Path $logFile -Value "`n=== FINAL OUTPUT ==="
            Add-Content -Path $logFile -Value ($finalOutput -join "`n")
        }
    }
    
} catch {
    Write-Host ""
    Write-Host "[ERROR] An error occurred: $_" -ForegroundColor Red
    Write-Host $_.Exception.Message -ForegroundColor Red
    exit 1
} finally {
    # Cleanup
    if ($stdin) { $stdin.Close() }
    if ($stdout) { $stdout.Close() }
    if ($stderr) { $stderr.Close() }
    if ($process -and -not $process.HasExited) {
        Write-Host "[INFO] Closing game process..." -ForegroundColor Cyan
        $process.CloseMainWindow() | Out-Null
        Start-Sleep -Milliseconds 500
        if (-not $process.HasExited) {
            $process.Kill()
        }
    }
    if ($process) { $process.Dispose() }
}

Write-Host ""
Write-Host "╔════════════════════════════════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "║" -ForegroundColor Cyan -NoNewline
Write-Host "           ULTIMATE WALKTHROUGH COMPLETE!                        " -ForegroundColor Green -NoNewline
Write-Host "║" -ForegroundColor Cyan
Write-Host "╚════════════════════════════════════════════════════════════════╝" -ForegroundColor Cyan
Write-Host ""

Write-Host "SUMMARY:" -ForegroundColor Yellow
Write-Host "  Commands sent: $commandCount" -ForegroundColor White
Write-Host "  Delay per command: $DelayMs ms" -ForegroundColor White
if ($SaveLog) {
    Write-Host "  Log file: $logFile" -ForegroundColor White
}
Write-Host ""

Write-Host "NOTES:" -ForegroundColor Yellow
Write-Host "  - This walkthrough follows the complete solution" -ForegroundColor White
Write-Host "  - Some commands may fail if items aren't available" -ForegroundColor White
Write-Host "  - The game may require interactive input at certain points" -ForegroundColor White
Write-Host "  - Check the ULTIMATE_WALKTHROUGH.md for detailed explanations" -ForegroundColor White
Write-Host ""

if ($SaveLog -and (Test-Path $logFile)) {
    Write-Host "[INFO] Log saved to: $logFile" -ForegroundColor Green
    Write-Host "[INFO] Size: $((Get-Item $logFile).Length) bytes" -ForegroundColor Cyan
}

Write-Host ""
Write-Host "Press any key to exit..." -ForegroundColor Yellow
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")
