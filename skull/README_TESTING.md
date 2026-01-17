# Automated Testing and Plan Updates

This directory contains automated scripts to run tests and keep the `TESTING_PLAN.md` file up to date.

## Quick Start

To run tests and automatically update the testing plan (fully automatic, keeps all changes):

```batch
.\run_tests_and_update.bat
```

Or from PowerShell:

```powershell
.\run_tests_and_update.ps1
```

Or manually:

```powershell
.\update_testing_plan.ps1 -RunTests -UpdatePlan -Force
```

**Note:** The script runs in "keep all changes" mode - all updates are automatically applied without prompts or confirmations. Backups are created automatically for safety.

## Scripts

### `update_testing_plan.ps1`

Main script that:
- Runs `test_functions.exe` (builds it first if needed)
- Parses test output to extract pass/fail counts per set
- Updates `TESTING_PLAN.md` with:
  - Overall pass/fail statistics
  - Per-set pass/fail counts and percentages
  - "Last Test" dates
  - Status icons (✅ for 100% passing, ⚠️ for partial)

**Usage:**
```powershell
.\update_testing_plan.ps1 [-RunTests] [-UpdatePlan]
```

**Parameters:**
- `-RunTests` (default: true): Run the test suite
- `-UpdatePlan` (default: true): Update TESTING_PLAN.md after tests

**Examples:**
```powershell
# Run tests and update plan (default)
.\update_testing_plan.ps1

# Only run tests, don't update plan
.\update_testing_plan.ps1 -UpdatePlan:$false

# Only update plan (if you already ran tests manually)
.\update_testing_plan.ps1 -RunTests:$false
```

### `run_tests_and_update.ps1` / `run_tests_and_update.bat`

Simple wrapper scripts that call `update_testing_plan.ps1` with default settings.

## How It Works

1. **Build Check**: Checks if `test_functions.exe` exists and is up to date. Rebuilds if needed using `build_test.bat`.

2. **Test Execution**: Runs `test_functions.exe` and captures all output.

3. **Output Parsing**: Parses the test output to identify:
   - Test set boundaries (`[TEST] Testing Set N`)
   - Pass/fail results (`PASS: function_name()` / `FAIL: function_name()`)
   - Function names and status

4. **Plan Updates**: Updates `TESTING_PLAN.md` by:
   - Replacing overall statistics (total pass/fail counts)
   - Updating set-specific status lines with current counts
   - Updating "Last Test" dates
   - Setting appropriate status icons

## Output Format

The script expects test output in this format:
```
[TEST] Testing Set 2: Display and Video Functions...
  PASS: function_name()
  FAIL: another_function()
  ...
```

## Notes

- **Auto-Keep Mode**: The script runs in fully automatic mode with no prompts. All changes are kept automatically.
- **Safety Features**: Automatic backups are created before updates. If an update fails, the backup is restored.
- The script preserves UTF-8 encoding without BOM when saving the plan file
- Status icons are automatically set: ✅ for 100% passing sets, ⚠️ for sets with failures
- The script is idempotent - running it multiple times will update dates but won't duplicate information
- The script handles various test output formats including combined sets (e.g., "Sets 12-17")
- No user interaction required - completely automatic execution

## Troubleshooting

**Script fails to find TESTING_PLAN.md:**
- Ensure you're running from the `skull` directory
- Check that `TESTING_PLAN.md` exists

**Tests don't run:**
- Check that `build_test.bat` exists and works
- Ensure `test_functions.c` compiles successfully

**Plan updates don't match test results:**
- Check the regex patterns in the script match your test output format
- Review the parsed set results in the script output
