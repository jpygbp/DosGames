# Demo Script: Complete Skullduggery Playthrough
# Shows the game from start to winning ending

Write-Host ""
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  SKULLDUGGERY - Complete Playthrough" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "This demo will play through the entire game" -ForegroundColor Yellow
Write-Host "from start to the winning ending." -ForegroundColor Yellow
Write-Host ""
Write-Host "Press any key to start..." -ForegroundColor Green
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

Write-Host ""
Write-Host "Starting game..." -ForegroundColor Cyan
Write-Host ""

# The complete solution
$commands = @(
    'up',
    'southeast',
    'southwest',
    'east',
    'take lamp',
    'south',
    'north',
    'down',
    'north',
    'take potion',
    'down',
    'take treasure'
)

# Run the game
$commands -join "`n" | .\skull.exe 2>$null

Write-Host ""
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  Demo Complete!" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""
Write-Host "The game is fully functional!" -ForegroundColor Green
Write-Host "You can now play interactively by running: .\skull.exe" -ForegroundColor Yellow
Write-Host ""
