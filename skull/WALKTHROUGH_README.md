# 🎮 Skull Game - Automatic Walkthrough System

## Overview

The automatic walkthrough system allows you to run the game with predefined commands for testing, demonstration, and validation purposes.

---

## 📁 Files

### Walkthrough Command Files

- **`walkthrough.txt`** - Basic walkthrough (13 commands)
- **`walkthrough_full.txt`** - Comprehensive walkthrough (22 commands)

### Execution Scripts

- **`play_walkthrough.bat`** - Simple batch script (Windows)
- **`play_walkthrough.ps1`** - Advanced PowerShell script with logging

---

## 🚀 Quick Start

### Method 1: Batch Script (Simple)

```bash
cd skull
play_walkthrough.bat
```

### Method 2: PowerShell Script (Advanced)

```powershell
cd skull
.\play_walkthrough.ps1
```

### Method 3: Manual Pipe

```bash
cd skull
type walkthrough.txt | skull.exe
```

---

## 🎯 PowerShell Script Options

### Basic Usage

```powershell
.\play_walkthrough.ps1
```

### Use Different Walkthrough File

```powershell
.\play_walkthrough.ps1 -WalkthroughFile "walkthrough_full.txt"
```

### Save Output Log

```powershell
.\play_walkthrough.ps1 -SaveLog
```

### Custom Delay Between Commands

```powershell
.\play_walkthrough.ps1 -DelayMs 2000
```

### Hide Output

```powershell
.\play_walkthrough.ps1 -ShowOutput:$false
```

### Combined Options

```powershell
.\play_walkthrough.ps1 -WalkthroughFile "walkthrough_full.txt" -SaveLog -DelayMs 1500
```

---

## 📝 Creating Custom Walkthroughs

### Format

Create a text file with one command per line:

```text
look
inventory
take sword
north
use sword
quit
```

### Available Commands

- `look` - Look around current location
- `inventory` - Check inventory
- `take [object]` - Take an object
- `take all` - Take all objects in location
- `drop [object]` - Drop an object
- `drop all` - Drop all objects in inventory
- `examine [object]` - Examine an object
- `use [object]` - Use an object
- `north/south/east/west` - Move directions
- `quit` - Exit game

### Tips

1. **Start with `look`** - See where you are
2. **Check inventory** - Know what you have
3. **Test object manipulation** - Take, drop, examine
4. **Test movement** - Move between locations
5. **End with `quit`** - Clean exit

---

## 📊 Walkthrough Files

### walkthrough.txt (Basic)

**Purpose:** Quick smoke test  
**Commands:** 13  
**Tests:**
- Basic display
- Inventory management
- Object manipulation
- Movement
- Clean exit

**Sequence:**
```
look → inventory → north → look → take sword → 
inventory → south → look → examine sword → 
use sword → drop sword → inventory → quit
```

### walkthrough_full.txt (Comprehensive)

**Purpose:** Full feature test  
**Commands:** 22  
**Tests:**
- All basic features
- Take all / drop all
- Multiple objects
- Object examination
- Complex sequences

**Sequence:**
```
look → inventory → examine room → take all → 
inventory → look → north → look → examine → 
drop all → inventory → take sword → take shield → 
inventory → examine sword → examine shield → 
south → look → use sword → drop sword → 
take sword → inventory → quit
```

---

## 🔍 Output Logging

### Automatic Logs

When using `-SaveLog` flag, output is saved to:

```
walkthrough_YYYYMMDD_HHMMSS.log
```

Example: `walkthrough_20260117_143022.log`

### Log Contents

- All game output
- Command echoes
- Error messages
- Status updates

### Viewing Logs

```powershell
# View log
Get-Content walkthrough_20260117_143022.log

# Search for errors
Select-String -Path "walkthrough_*.log" -Pattern "error|fail"

# Count commands
(Get-Content walkthrough_20260117_143022.log | Measure-Object -Line).Lines
```

---

## 🧪 Testing Use Cases

### 1. Smoke Test

**Purpose:** Quick validation after changes

```powershell
.\play_walkthrough.ps1
```

**Expected:** Clean execution, no errors

### 2. Regression Test

**Purpose:** Verify no functionality broken

```powershell
.\play_walkthrough.ps1 -WalkthroughFile "walkthrough_full.txt" -SaveLog
```

**Expected:** All commands work, log shows success

### 3. Performance Test

**Purpose:** Check response times

```powershell
Measure-Command { .\play_walkthrough.ps1 -ShowOutput:$false }
```

**Expected:** Completes in reasonable time

### 4. Demo Mode

**Purpose:** Show game features

```powershell
.\play_walkthrough.ps1 -DelayMs 2000
```

**Expected:** Visible command execution

---

## 🛠️ Troubleshooting

### Game Not Found

**Error:** `skull.exe not found`

**Solution:**
```powershell
cd skull
.\play_walkthrough.ps1
```

### Walkthrough File Missing

**Error:** `Walkthrough file not found`

**Solution:**
```powershell
# Check files exist
dir walkthrough*.txt

# Create if missing
"look`ninventory`nquit" | Out-File walkthrough.txt
```

### Commands Not Executing

**Issue:** Commands seem ignored

**Solution:**
- Check file encoding (should be UTF-8 or ASCII)
- Verify one command per line
- Check for extra spaces/characters

### Game Hangs

**Issue:** Game doesn't exit

**Solution:**
- Ensure walkthrough ends with `quit`
- Check for commands waiting for input
- Use Ctrl+C to force exit

---

## 📈 Advanced Usage

### Parallel Testing

Test multiple walkthroughs:

```powershell
$walkthroughs = @("walkthrough.txt", "walkthrough_full.txt")
foreach ($wt in $walkthroughs) {
    Write-Host "Testing $wt..."
    .\play_walkthrough.ps1 -WalkthroughFile $wt -SaveLog
}
```

### Automated Validation

Check for errors in output:

```powershell
.\play_walkthrough.ps1 -SaveLog
$log = Get-Content walkthrough_*.log -Raw
if ($log -match "error|fail|crash") {
    Write-Host "FAILED: Errors detected" -ForegroundColor Red
} else {
    Write-Host "PASSED: No errors" -ForegroundColor Green
}
```

### Performance Benchmarking

```powershell
$times = 1..10 | ForEach-Object {
    (Measure-Command { 
        .\play_walkthrough.ps1 -ShowOutput:$false 
    }).TotalSeconds
}
$avg = ($times | Measure-Object -Average).Average
Write-Host "Average execution time: $avg seconds"
```

---

## 📋 Creating Test Scenarios

### Scenario 1: Object Management

```text
look
take all
inventory
drop all
inventory
quit
```

### Scenario 2: Navigation

```text
look
north
look
east
look
south
look
west
look
quit
```

### Scenario 3: Object Interaction

```text
take sword
examine sword
use sword
drop sword
take sword
quit
```

### Scenario 4: Error Handling

```text
take nonexistent
drop nothing
use invalid
examine missing
quit
```

---

## 🎯 Best Practices

1. **Always end with `quit`** - Ensures clean exit
2. **Test incrementally** - Start small, expand
3. **Save logs** - Track results over time
4. **Use descriptive names** - `walkthrough_inventory_test.txt`
5. **Document purpose** - Add comments in README
6. **Version control** - Commit walkthrough files
7. **Regular testing** - Run after each change

---

## 📊 Example Output

```
========================================
Skull Game - Automatic Walkthrough
========================================

Walkthrough Configuration:
  File: walkthrough.txt
  Commands: 13
  Delay: 1000ms between commands
  Output: Shown
  Log: Saved

Commands to execute:
  > look
  > inventory
  > north
  > look
  > take sword
  > inventory
  > south
  > look
  > examine sword
  > use sword
  > drop sword
  > inventory
  > quit

Starting walkthrough...

[Game output appears here...]

========================================
Walkthrough Completed Successfully!
========================================

Log saved to: walkthrough_20260117_143022.log
File size: 4523 bytes
```

---

## 🔄 Integration with CI/CD

### GitHub Actions Example

```yaml
- name: Run Walkthrough Test
  run: |
    cd skull
    powershell -File play_walkthrough.ps1 -SaveLog
    if ($LASTEXITCODE -ne 0) { exit 1 }
```

### Jenkins Example

```groovy
stage('Walkthrough Test') {
    steps {
        dir('skull') {
            powershell './play_walkthrough.ps1 -SaveLog'
        }
    }
}
```

---

## 📚 Related Documentation

- `PROJECT_MASTER_TRACKER.md` - Overall project status
- `TESTING_PLAN.md` - Comprehensive testing strategy
- `TEST_RESULTS_SUMMARY.md` - Test execution results

---

## ✅ Success Criteria

A successful walkthrough should:

1. ✅ Execute all commands without crashes
2. ✅ Display appropriate responses
3. ✅ Handle objects correctly
4. ✅ Navigate between locations
5. ✅ Exit cleanly with quit command
6. ✅ Complete in reasonable time (<5 seconds)
7. ✅ Show no error messages (unless testing errors)

---

## 🎊 Summary

The automatic walkthrough system provides:

- **Quick Testing** - Validate changes rapidly
- **Demonstration** - Show game features
- **Regression Prevention** - Catch breaking changes
- **Documentation** - Log game behavior
- **Automation** - Integrate with CI/CD

**Ready to use!** Run `play_walkthrough.bat` or `.\play_walkthrough.ps1` to start!

---

**Created:** 2026-01-17  
**Version:** 1.0  
**Status:** ✅ Ready for Use
