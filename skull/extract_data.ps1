# Game Data Extraction - Run game with automated commands to map locations
$commands = @(
    "look",
    "inventory", 
    "examine room",
    "north",
    "look",
    "south",
    "look",
    "east",
    "look",
    "west",
    "look",
    "quit"
)

$commands | Out-File -FilePath "test_commands.txt" -Encoding ASCII
Write-Host "Commands file created. Running game..." -ForegroundColor Green
