# Simple build script using MSBuild
$ErrorActionPreference = "Stop"

Write-Host "`nBuilding Skull Game with Piped Input Fix..." -ForegroundColor Cyan

# Find MSBuild
$msbuildPath = "C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\amd64\MSBuild.exe"

if (-not (Test-Path $msbuildPath)) {
    Write-Host "ERROR: MSBuild not found at $msbuildPath" -ForegroundColor Red
    exit 1
}

# Find cl.exe
$clPath = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\bin\Hostx64\x64\cl.exe"

if (-not (Test-Path $clPath)) {
    Write-Host "ERROR: cl.exe not found" -ForegroundColor Red
    exit 1
}

# Set environment
$env:PATH = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\bin\Hostx64\x64;$env:PATH"
$env:INCLUDE = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\include;C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\ucrt;C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\shared;C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\um;C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\winrt"
$env:LIB = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.42.34433\lib\x64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\um\x64"

Write-Host "Compiling..." -ForegroundColor Yellow

& $clPath /nologo /W3 /O2 /D_WIN32 /DNDEBUG skull_ported.c dos_compat.c /Fe:skull.exe /link /SUBSYSTEM:CONSOLE

if ($LASTEXITCODE -eq 0) {
    Write-Host "`nBuild successful!" -ForegroundColor Green
    Write-Host "Executable: skull.exe" -ForegroundColor White
    if (Test-Path skull.exe) {
        Write-Host "Size: $((Get-Item skull.exe).Length) bytes" -ForegroundColor White
    }
} else {
    Write-Host "`nBuild failed!" -ForegroundColor Red
    exit 1
}
