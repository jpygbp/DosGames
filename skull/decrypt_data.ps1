# Skull Game Data File Decryptor (PowerShell)
# Decrypts SKULL.M, SKULL.X, SKULL.T, and other game data files
# Uses XOR 0xFF encryption (bit inversion)

function Decrypt-Byte {
    param([byte]$byte)
    return $byte -bxor 0xFF
}

function Decrypt-File {
    param(
        [string]$InputFile,
        [string]$OutputFile
    )
    
    try {
        # Read encrypted file
        $encrypted = [System.IO.File]::ReadAllBytes($InputFile)
        
        # Decrypt each byte
        $decrypted = New-Object byte[] $encrypted.Length
        for ($i = 0; $i -lt $encrypted.Length; $i++) {
            $decrypted[$i] = Decrypt-Byte $encrypted[$i]
        }
        
        # Write decrypted file
        [System.IO.File]::WriteAllBytes($OutputFile, $decrypted)
        
        Write-Host "✓ Decrypted $InputFile -> $OutputFile" -ForegroundColor Green
        Write-Host "  Size: $($encrypted.Length) bytes" -ForegroundColor Gray
        return $true
    }
    catch {
        Write-Host "✗ Error decrypting ${InputFile}: $_" -ForegroundColor Red
        return $false
    }
}

function Decrypt-String {
    param([byte[]]$EncryptedBytes)
    
    $decrypted = New-Object byte[] $EncryptedBytes.Length
    for ($i = 0; $i -lt $EncryptedBytes.Length; $i++) {
        $decrypted[$i] = Decrypt-Byte $EncryptedBytes[$i]
    }
    
    try {
        return [System.Text.Encoding]::ASCII.GetString($decrypted)
    }
    catch {
        return [BitConverter]::ToString($decrypted).Replace('-', '')
    }
}

function Test-PrintableText {
    param([string]$Text)
    
    if ([string]::IsNullOrEmpty($Text)) {
        return $false
    }
    
    $printableCount = 0
    foreach ($char in $Text.ToCharArray()) {
        $code = [int][char]$char
        if (($code -ge 32 -and $code -lt 127) -or $code -in @(9, 10, 13)) {
            $printableCount++
        }
    }
    
    return ($printableCount / $Text.Length) -gt 0.8
}

function Analyze-File {
    param([string]$Filename)
    
    try {
        $data = [System.IO.File]::ReadAllBytes($Filename)
    }
    catch {
        Write-Host "✗ Error reading ${Filename}: $_" -ForegroundColor Red
        return
    }
    
    Write-Host "`n$('='*60)" -ForegroundColor Cyan
    Write-Host "Analyzing: $Filename" -ForegroundColor Yellow
    Write-Host "$('='*60)" -ForegroundColor Cyan
    Write-Host "File size: $($data.Length) bytes`n" -ForegroundColor White
    
    $pos = 0
    $stringCount = 0
    $validStrings = @()
    
    while ($pos -lt $data.Length - 2) {
        # Read length prefix (2 bytes, little-endian)
        $length = $data[$pos] -bor ($data[$pos + 1] -shl 8)
        
        if ($length -gt 0 -and $length -lt 1000 -and ($pos + 2 + $length) -le $data.Length) {
            # Extract and decrypt string
            $encrypted = $data[($pos + 2)..($pos + 2 + $length - 2)]
            $decrypted = Decrypt-String $encrypted
            
            if (Test-PrintableText $decrypted) {
                $validStrings += [PSCustomObject]@{
                    Offset = $pos
                    Length = $length
                    Content = $decrypted
                }
                $stringCount++
            }
            
            $pos += 2 + $length
        }
        else {
            $pos++
        }
    }
    
    Write-Host "Found $stringCount potential strings`n" -ForegroundColor Green
    
    # Display first 20 strings
    $displayCount = [Math]::Min(20, $validStrings.Count)
    for ($i = 0; $i -lt $displayCount; $i++) {
        $s = $validStrings[$i]
        Write-Host "String $i at offset 0x$($s.Offset.ToString('X4')) (length $($s.Length)):" -ForegroundColor Cyan
        
        $content = $s.Content
        if ($content.Length -gt 100) {
            $content = $content.Substring(0, 100) + "..."
        }
        
        Write-Host "  $content" -ForegroundColor White
        Write-Host ""
    }
    
    if ($validStrings.Count -gt 20) {
        Write-Host "... and $($validStrings.Count - 20) more strings" -ForegroundColor Gray
    }
    
    return $validStrings
}

function Extract-AllStrings {
    param(
        [string]$InputFile,
        [string]$OutputFile
    )
    
    try {
        $data = [System.IO.File]::ReadAllBytes($InputFile)
    }
    catch {
        Write-Host "✗ Error reading ${InputFile}: $_" -ForegroundColor Red
        return
    }
    
    Write-Host "`nExtracting strings from $InputFile..." -ForegroundColor Yellow
    
    $pos = 0
    $stringCount = 0
    $output = @()
    
    $output += "Strings extracted from $InputFile"
    $output += "=" * 60
    $output += ""
    
    while ($pos -lt $data.Length - 2) {
        $length = $data[$pos] -bor ($data[$pos + 1] -shl 8)
        
        if ($length -gt 0 -and $length -lt 1000 -and ($pos + 2 + $length) -le $data.Length) {
            $encrypted = $data[($pos + 2)..($pos + 2 + $length - 2)]
            $decrypted = Decrypt-String $encrypted
            
            if (Test-PrintableText $decrypted) {
                $output += "[$stringCount] Offset 0x$($pos.ToString('X4')), Length $length"
                $output += $decrypted
                $output += "-" * 60
                $output += ""
                $stringCount++
            }
            
            $pos += 2 + $length
        }
        else {
            $pos++
        }
    }
    
    $output | Out-File -FilePath $OutputFile -Encoding UTF8
    Write-Host "✓ Extracted $stringCount strings to $OutputFile" -ForegroundColor Green
}

function Decrypt-AllGameFiles {
    $files = @('SKULL.M', 'SKULL.X', 'SKULL.T', 'SKULL.V', 'SKULL.MM', 'SKULL.MO')
    
    Write-Host "`nDecrypting all game data files..." -ForegroundColor Yellow
    Write-Host "$('='*60)`n" -ForegroundColor Cyan
    
    $successCount = 0
    foreach ($file in $files) {
        if (Test-Path $file) {
            $output = "$file.decrypted"
            if (Decrypt-File $file $output) {
                $successCount++
            }
        }
        else {
            Write-Host "⊗ File not found: $file" -ForegroundColor DarkGray
        }
    }
    
    Write-Host "`n$('='*60)" -ForegroundColor Cyan
    Write-Host "Decrypted $successCount/$($files.Count) files" -ForegroundColor Green
    Write-Host "$('='*60)`n" -ForegroundColor Cyan
}

function Show-Usage {
    Write-Host @"

Skull Game Data File Decryptor (PowerShell)
============================================

Usage:
  .\decrypt_data.ps1 <command> [arguments]

Commands:
  decrypt <input> [output]    Decrypt a single file
  analyze <file>              Analyze file structure and show strings
  extract <input> <output>    Extract all strings to text file
  all                         Decrypt all standard game files
  help                        Show this help message

Examples:
  .\decrypt_data.ps1 decrypt SKULL.M SKULL.M.txt
  .\decrypt_data.ps1 analyze SKULL.M
  .\decrypt_data.ps1 extract SKULL.M strings.txt
  .\decrypt_data.ps1 all

Notes:
  - Encryption uses XOR 0xFF (bit inversion)
  - Same operation encrypts and decrypts
  - Files contain length-prefixed strings
  - Standard files: SKULL.M, SKULL.X, SKULL.T, SKULL.V, SKULL.MM, SKULL.MO

"@ -ForegroundColor White
}

# Main script
if ($args.Length -lt 1) {
    Show-Usage
    exit 1
}

$command = $args[0].ToLower()

switch ($command) {
    'decrypt' {
        if ($args.Length -lt 2) {
            Write-Host "Error: decrypt requires input file" -ForegroundColor Red
            Show-Usage
            exit 1
        }
        
        $inputFile = $args[1]
        $outputFile = if ($args.Length -gt 2) { $args[2] } else { "$inputFile.decrypted" }
        Decrypt-File $inputFile $outputFile
    }
    
    'analyze' {
        if ($args.Length -lt 2) {
            Write-Host "Error: analyze requires input file" -ForegroundColor Red
            Show-Usage
            exit 1
        }
        
        Analyze-File $args[1]
    }
    
    'extract' {
        if ($args.Length -lt 3) {
            Write-Host "Error: extract requires input and output files" -ForegroundColor Red
            Show-Usage
            exit 1
        }
        
        Extract-AllStrings $args[1] $args[2]
    }
    
    'all' {
        Decrypt-AllGameFiles
    }
    
    default {
        if ($command -in @('help', '-h', '--help', '/?')) {
            Show-Usage
        }
        else {
            Write-Host "Error: Unknown command '$command'" -ForegroundColor Red
            Show-Usage
            exit 1
        }
    }
}
