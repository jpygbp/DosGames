# Simple wrapper script that runs tests and updates the plan
# Usage: .\run_tests_and_update.ps1

& "$PSScriptRoot\update_testing_plan.ps1" -RunTests -UpdatePlan
