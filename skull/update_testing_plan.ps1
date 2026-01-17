# Automated Testing Plan Update Script
# Runs tests and automatically updates TESTING_PLAN.md with current results
# This script is designed to run automatically without user interaction
# All changes are applied automatically (keep all changes mode)

param(
    [switch]$RunTests = $true,
    [switch]$UpdatePlan = $true,
    [switch]$Force = $false  # Force update even if file seems unchanged
)

$ErrorActionPreference = "Continue"
$ConfirmPreference = "None"  # Disable all confirmation prompts

function Update-TestingPlan {
    param(
        [string]$TestOutput,
        [string]$PlanFile = "TESTING_PLAN.md"
    )
    
    Write-Host "`nUpdating TESTING_PLAN.md with test results..."
    
    if (-not (Test-Path $PlanFile)) {
        Write-Error "TESTING_PLAN.md not found!"
        return $false
    }
    
    $planContent = Get-Content $PlanFile -Raw
    $currentDate = Get-Date -Format "yyyy-MM-dd"
    
    # Parse test output into structured data
    $testLines = $TestOutput -split "`n"
    $setResults = @{}
    $currentSet = $null
    
    foreach ($line in $testLines) {
        # Detect set boundaries
        if ($line -match "\[TEST\] Testing Set (\d+)") {
            $currentSet = "Set $($matches[1])"
            if (-not $setResults.ContainsKey($currentSet)) {
                $setResults[$currentSet] = @{Pass=0; Fail=0; Functions=@()}
            }
        }
        elseif ($line -match "\[TEST\] Testing Sets (\d+)-(\d+)") {
            # Combined sets like "Sets 12-17"
            $startSet = [int]$matches[1]
            $endSet = [int]$matches[2]
            for ($i = $startSet; $i -le $endSet; $i++) {
                $currentSet = "Set $i"
                if (-not $setResults.ContainsKey($currentSet)) {
                    $setResults[$currentSet] = @{Pass=0; Fail=0; Functions=@()}
                }
            }
        }
        elseif ($line -match "\[TEST\] Testing (.*)\.\.\.") {
            # Generic test markers (Set 1 uses this format)
            if ($line -match "InitGameState|memory operations|find_interrupt|call_interrupt|flush_file|display|video mode|display setup|cursor|memory allocation|text color|utility") {
                if (-not $setResults.ContainsKey("Set 1")) {
                    $setResults["Set 1"] = @{Pass=0; Fail=0; Functions=@()}
                }
                $currentSet = "Set 1"
            }
        }
        
        # Count pass/fail
        if ($line -match "  PASS: ([^(]+)") {
            $funcName = $matches[1].Trim()
            if ($currentSet -and $setResults.ContainsKey($currentSet)) {
                $setResults[$currentSet].Pass++
                $setResults[$currentSet].Functions += @{Name=$funcName; Status="PASS"}
            }
        }
        elseif ($line -match "  FAIL: ([^(]+)") {
            $funcName = $matches[1].Trim()
            if ($currentSet -and $setResults.ContainsKey($currentSet)) {
                $setResults[$currentSet].Fail++
                $setResults[$currentSet].Functions += @{Name=$funcName; Status="FAIL"}
            }
        }
    }
    
    # Calculate totals
    $totalPass = ($setResults.Values | Measure-Object -Property Pass -Sum).Sum
    $totalFail = ($setResults.Values | Measure-Object -Property Fail -Sum).Sum
    $totalTests = $totalPass + $totalFail
    
    Write-Host "  Found $totalPass passing and $totalFail failing tests across $($setResults.Keys.Count) sets"
    
    # Update overall statistics
    if ($totalTests -gt 0) {
        $passRate = [math]::Round($totalPass/$totalTests*100, 1)
        $failRate = [math]::Round($totalFail/$totalTests*100, 1)
        $planContent = $planContent -replace "- \*\*Total Tests Passing\*\*: \d+/\d+ \([0-9.]+%\)", "- **Total Tests Passing**: $totalPass/$totalTests ($passRate%)"
        $planContent = $planContent -replace "- \*\*Total Tests Failing\*\*: \d+/\d+ \([0-9.]+%\)", "- **Total Tests Failing**: $totalFail/$totalTests ($failRate%)"
    }
    
    $planContent = $planContent -replace "- \*\*Last Updated\*\*: [0-9-]+.*", "- **Last Updated**: $currentDate - Auto-updated after test run"
    
    # Update Set-specific results
    $setMappings = @{
        "Set 1" = "Set 1"
        "Set 2" = "Set 2"
        "Set 3" = "Set 3"
        "Set 4" = "Set 4"
        "Set 5" = "Set 5"
        "Set 6" = "Set 6"
        "Set 7" = "Set 7"
        "Set 8" = "Set 8"
        "Set 9" = "Set 9"
        "Set 10" = "Set 10"
        "Set 11" = "Set 11"
        "Set 16" = "Set 16"
        "Set 17" = "Set 17"
    }
    
    foreach ($setKey in $setResults.Keys) {
        if ($setMappings.ContainsKey($setKey)) {
            $setName = $setMappings[$setKey]
            $result = $setResults[$setKey]
            $setTotal = $result.Pass + $result.Fail
            
            if ($setTotal -gt 0) {
                $passRate = [math]::Round($result.Pass/$setTotal*100, 1)
                $statusIcon = if ($result.Fail -eq 0) { "✅" } else { "⚠️" }
                
                # Update status line - handle various formats with emojis
                $pattern = "## $setName: [^\n]*\([0-9/]+ passing[^)]*\)"
                $replacement = "## $setName: $statusIcon ($($result.Pass)/$setTotal passing - $passRate%)"
                $planContent = $planContent -replace $pattern, $replacement
                
                # Update "Last Test" date
                $planContent = $planContent -replace "(\*\*Last Test\*\*: )[0-9-]+", "`${1}$currentDate"
                
                Write-Host "  Updated $setName: $($result.Pass)/$setTotal passing ($passRate%)"
            }
        }
    }
    
    # Update "Last Test" dates in all set sections (fallback - but be careful not to overwrite ones we already updated)
    # Only update if the date format is old (YYYY-MM-DD)
    $planContent = $planContent -replace "(\*\*Last Test\*\*: )[0-9]{4}-[0-9]{2}-[0-9]{2}([^\n]*)", "`${1}$currentDate`${2}"
    
    # Create backup before updating (for safety)
    $backupFile = "$PlanFile.backup"
    if (Test-Path $PlanFile) {
        Copy-Item -Path $PlanFile -Destination $backupFile -Force -ErrorAction SilentlyContinue
    }
    
    # Save updated plan (automatically, no prompts)
    try {
        $utf8NoBom = New-Object System.Text.UTF8Encoding $false
        $fullPath = (Resolve-Path $PlanFile).Path
        [System.IO.File]::WriteAllText($fullPath, $planContent, $utf8NoBom)
        Write-Host "✓ TESTING_PLAN.md updated successfully!"
        
        # Clean up backup if update succeeded (keep only latest backup)
        if (Test-Path $backupFile) {
            $oldBackup = "$PlanFile.backup.old"
            if (Test-Path $oldBackup) {
                Remove-Item $oldBackup -Force -ErrorAction SilentlyContinue
            }
            Rename-Item -Path $backupFile -NewName $oldBackup -Force -ErrorAction SilentlyContinue
        }
        
        return $true
    }
    catch {
        Write-Error "Failed to update TESTING_PLAN.md: $_"
        # Restore from backup if update failed
        if (Test-Path $backupFile) {
            Copy-Item -Path $backupFile -Destination $PlanFile -Force -ErrorAction SilentlyContinue
            Write-Host "  Restored from backup"
        }
        return $false
    }
}

# Main execution
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Push-Location $scriptDir

try {
    if ($RunTests) {
        Write-Host "Running tests..."
        Write-Host "===================="
        
        # Build if needed (automatically, no prompts)
        if (-not (Test-Path "test_functions.exe") -or 
            (Test-Path "test_functions.c") -and (Get-Item "test_functions.exe").LastWriteTime -lt (Get-Item "test_functions.c").LastWriteTime) {
            Write-Host "Building test_functions.exe..."
            $buildResult = & .\build_test.bat 2>&1
            if ($LASTEXITCODE -ne 0) {
                Write-Warning "Build may have failed (exit code: $LASTEXITCODE), but continuing..."
            }
        }
        
        # Run tests and capture output
        Write-Host "Running test_functions.exe..."
        $testOutput = & .\test_functions.exe 2>&1 | Out-String
        
        # Display summary
        $passCount = ([regex]::Matches($testOutput, "  PASS:")).Count
        $failCount = ([regex]::Matches($testOutput, "  FAIL:")).Count
        Write-Host "`n===================="
        Write-Host "Test Results: PASS=$passCount, FAIL=$failCount"
        Write-Host "===================="
        
        if ($UpdatePlan) {
            Write-Host ""
            Update-TestingPlan -TestOutput $testOutput
        } else {
            Write-Host $testOutput
        }
    } else {
        Write-Host "Skipping test execution (use -RunTests to enable)"
    }
} finally {
    Pop-Location
}

Write-Host "`nDone!"
