# 🔐 Skull Game Data File Encryption Analysis

**Date:** 2026-01-17  
**Purpose:** Document the game's data file encryption system  
**Status:** Complete analysis

---

## 📋 Overview

The Skull Game uses a simple XOR-based encryption to protect its game data files (SKULL.M, SKULL.X, SKULL.T, etc.). This document explains how the encryption works and how to decrypt the data.

---

## 🔑 Encryption Method

### Simple XOR Cipher

The game uses **XOR encryption** with a single-byte key:

```c
// Decryption code from skull_ported.c (line 8894)
*decrypt_ptr = *decrypt_ptr ^ BIT_MASK_LOW_8;

// Where BIT_MASK_LOW_8 is defined as:
#define BIT_MASK_LOW_8  0xff  // All bits set (255)
```

### How It Works

**XOR (Exclusive OR) Properties:**
- `A XOR B XOR B = A` (reversible)
- `X XOR 0xFF` flips all bits in byte X
- The same operation encrypts and decrypts

**Encryption/Decryption Formula:**
```
encrypted_byte = original_byte XOR 0xFF
decrypted_byte = encrypted_byte XOR 0xFF
```

**Example:**
```
Original:  'A' = 0x41 = 01000001
XOR 0xFF:       = 11111111
Result:         = 10111110 = 0xBE

Decrypt:   0xBE = 10111110
XOR 0xFF:       = 11111111
Result:         = 01000001 = 0x41 = 'A'
```

---

## 📂 File Structure

### Data Files

The game uses several data files:

| File | Purpose |
|------|---------|
| **SKULL.M** | Main message/string data |
| **SKULL.X** | Extended data |
| **SKULL.T** | Text/description data |
| **SKULL.MM** | Additional messages |
| **SKULL.MO** | More data |
| **SKULL.V** | Vocabulary/word data |

### File Format

Each file contains:

1. **String Table** (in memory, not in file)
   - Array of entries: `[string_id (4 bytes), file_offset (2 bytes)]`
   - Used to locate strings in the data file

2. **Data Section** (in file)
   - Length prefix (2 bytes) - indicates string length
   - Encrypted string data (variable length)
   - Each byte XORed with 0xFF

---

## 🔍 Decryption Process

### Step-by-Step Decryption

**From `load_string_from_file()` function:**

```c
// 1. Search string table for string_id
while (search_index < MEM_READ32(MEM_COMMAND_COUNT) && 
       *(int *)(string_table + search_index * 4) != string_id) {
    search_index++;
}

// 2. Get file offset from string table entry
uint16_t file_offset = *(uint16_t*)(string_table + search_index * 4 + 2);

// 3. Seek to position in file
file_seek(file_handle, file_offset, 0, 0);

// 4. Read length prefix (2 bytes)
string_length = file_read_word(file_handle, buffer_ptr, offset);

// 5. Decrypt each byte (except null terminator)
for (int i = 0; i < string_length - 1; i++) {
    buffer[i] = buffer[i] ^ 0xFF;  // Flip all bits
}

// 6. Add null terminator
buffer[string_length - 1] = 0;
```

---

## 🛠️ Decryption Tool

### Python Decryption Script

```python
#!/usr/bin/env python3
"""
Skull Game Data File Decryptor
Decrypts SKULL.M, SKULL.X, SKULL.T, etc.
"""

def decrypt_byte(byte):
    """Decrypt a single byte using XOR 0xFF"""
    return byte ^ 0xFF

def decrypt_file(input_file, output_file):
    """Decrypt an entire file"""
    with open(input_file, 'rb') as f_in:
        encrypted_data = f_in.read()
    
    # Decrypt each byte
    decrypted_data = bytes([decrypt_byte(b) for b in encrypted_data])
    
    with open(output_file, 'wb') as f_out:
        f_out.write(decrypted_data)
    
    print(f"Decrypted {input_file} -> {output_file}")
    print(f"Size: {len(encrypted_data)} bytes")

def decrypt_string(encrypted_bytes):
    """Decrypt a byte array to string"""
    decrypted = bytes([decrypt_byte(b) for b in encrypted_bytes])
    try:
        return decrypted.decode('ascii', errors='replace')
    except:
        return decrypted.hex()

def analyze_file(filename):
    """Analyze and display file structure"""
    with open(filename, 'rb') as f:
        data = f.read()
    
    print(f"\n=== Analyzing {filename} ===")
    print(f"File size: {len(data)} bytes")
    
    # Try to extract strings
    pos = 0
    string_count = 0
    
    while pos < len(data) - 2:
        # Read length prefix (2 bytes, little-endian)
        length = data[pos] | (data[pos + 1] << 8)
        
        if length > 0 and length < 1000 and pos + 2 + length <= len(data):
            # Extract and decrypt string
            encrypted_string = data[pos + 2:pos + 2 + length]
            decrypted_string = decrypt_string(encrypted_string)
            
            # Check if it looks like valid text
            if all(32 <= c < 127 or c in [9, 10, 13] for c in decrypted_string.encode('ascii', errors='replace')):
                print(f"\nString {string_count} at offset {pos}:")
                print(f"  Length: {length}")
                print(f"  Content: {decrypted_string[:100]}")
                string_count += 1
            
            pos += 2 + length
        else:
            pos += 1
    
    print(f"\nFound {string_count} potential strings")

if __name__ == "__main__":
    import sys
    
    if len(sys.argv) < 2:
        print("Usage:")
        print("  Decrypt: python decrypt.py <input_file> [output_file]")
        print("  Analyze: python decrypt.py --analyze <file>")
        sys.exit(1)
    
    if sys.argv[1] == "--analyze":
        analyze_file(sys.argv[2])
    else:
        input_file = sys.argv[1]
        output_file = sys.argv[2] if len(sys.argv) > 2 else input_file + ".decrypted"
        decrypt_file(input_file, output_file)
```

### PowerShell Decryption Script

```powershell
# Skull Game Data File Decryptor (PowerShell)

function Decrypt-Byte {
    param([byte]$byte)
    return $byte -bxor 0xFF
}

function Decrypt-File {
    param(
        [string]$InputFile,
        [string]$OutputFile
    )
    
    # Read encrypted file
    $encrypted = [System.IO.File]::ReadAllBytes($InputFile)
    
    # Decrypt each byte
    $decrypted = New-Object byte[] $encrypted.Length
    for ($i = 0; $i -lt $encrypted.Length; $i++) {
        $decrypted[$i] = Decrypt-Byte $encrypted[$i]
    }
    
    # Write decrypted file
    [System.IO.File]::WriteAllBytes($OutputFile, $decrypted)
    
    Write-Host "Decrypted $InputFile -> $OutputFile"
    Write-Host "Size: $($encrypted.Length) bytes"
}

function Analyze-File {
    param([string]$Filename)
    
    $data = [System.IO.File]::ReadAllBytes($Filename)
    
    Write-Host "`n=== Analyzing $Filename ==="
    Write-Host "File size: $($data.Length) bytes"
    
    $pos = 0
    $stringCount = 0
    
    while ($pos -lt $data.Length - 2) {
        # Read length prefix (2 bytes, little-endian)
        $length = $data[$pos] -bor ($data[$pos + 1] -shl 8)
        
        if ($length -gt 0 -and $length -lt 1000 -and ($pos + 2 + $length) -le $data.Length) {
            # Extract and decrypt string
            $encrypted = $data[($pos + 2)..($pos + 2 + $length - 1)]
            $decrypted = New-Object byte[] $encrypted.Length
            
            for ($i = 0; $i -lt $encrypted.Length; $i++) {
                $decrypted[$i] = Decrypt-Byte $encrypted[$i]
            }
            
            $text = [System.Text.Encoding]::ASCII.GetString($decrypted)
            
            # Check if it looks like valid text
            if ($text -match '^[\x20-\x7E\t\r\n]+$') {
                Write-Host "`nString $stringCount at offset $pos:"
                Write-Host "  Length: $length"
                Write-Host "  Content: $($text.Substring(0, [Math]::Min(100, $text.Length)))"
                $stringCount++
            }
            
            $pos += 2 + $length
        } else {
            $pos++
        }
    }
    
    Write-Host "`nFound $stringCount potential strings"
}

# Main script
if ($args.Length -lt 1) {
    Write-Host "Usage:"
    Write-Host "  Decrypt: .\decrypt.ps1 <input_file> [output_file]"
    Write-Host "  Analyze: .\decrypt.ps1 -analyze <file>"
    exit 1
}

if ($args[0] -eq "-analyze") {
    Analyze-File $args[1]
} else {
    $inputFile = $args[0]
    $outputFile = if ($args.Length -gt 1) { $args[1] } else { "$inputFile.decrypted" }
    Decrypt-File $inputFile $outputFile
}
```

---

## 💡 Why This Encryption?

### Historical Context

**1980s Software Protection:**
- Simple obfuscation to prevent casual viewing
- Not meant to be cryptographically secure
- Prevents text editors from reading strings
- Discourages casual hex editing

**XOR 0xFF Benefits:**
- Extremely fast (single CPU instruction)
- No key management needed
- Reversible with same operation
- Works on any byte value

**Limitations:**
- Trivial to break (single-byte key)
- No real security against determined analysis
- Pattern analysis reveals encryption method
- Common in shareware games of the era

---

## 🔬 Technical Analysis

### Bit-Level View

```
Original byte:    01001000  (0x48 = 'H')
XOR mask:         11111111  (0xFF)
                  --------
Encrypted byte:   10110111  (0xB7)

Decrypt:          10110111  (0xB7)
XOR mask:         11111111  (0xFF)
                  --------
Original byte:    01001000  (0x48 = 'H')
```

### Properties

**Involution:** `f(f(x)) = x`
- Applying XOR 0xFF twice returns original value
- Same function encrypts and decrypts

**Bit Inversion:**
- XOR with 0xFF inverts all bits
- Equivalent to bitwise NOT operation
- `x XOR 0xFF = ~x` (in C notation)

**Statistical Properties:**
- Preserves byte distribution
- 0x00 becomes 0xFF, 0xFF becomes 0x00
- 0x80 remains 0x7F (middle values swap)

---

## 📊 File Format Examples

### String Table Entry

```
Offset  | Size | Description
--------|------|-------------
0x0000  | 4    | String ID (int32, little-endian)
0x0004  | 2    | File offset (uint16, little-endian)
```

### Data File Entry

```
Offset  | Size | Description
--------|------|-------------
0x0000  | 2    | String length (uint16, little-endian)
0x0002  | N    | Encrypted string data (XOR 0xFF)
```

### Example Decryption

```
File bytes (hex):  0A 00 96 90 93 93 90 8B 8B 8B 8B
                   ^^^^^ ^^^^^^^^^^^^^^^^^^^^^^
                   Len=10  Encrypted string

Decrypt string bytes:
96 XOR FF = 69 = 'i'
90 XOR FF = 6F = 'o'
93 XOR FF = 6C = 'l'
93 XOR FF = 6C = 'l'
90 XOR FF = 6F = 'o'
8B XOR FF = 74 = 't'
8B XOR FF = 74 = 't'
8B XOR FF = 74 = 't'
8B XOR FF = 74 = 't'

Result: "iollotttt" (example - not actual game data)
```

---

## 🎮 Game Data Contents

### What's in the Files

**SKULL.M (Main messages):**
- Room descriptions
- Object descriptions
- Action messages
- Error messages
- Game text

**SKULL.X (Extended):**
- Additional descriptions
- Special messages
- Event text

**SKULL.T (Text):**
- Long-form text
- Story elements
- Detailed descriptions

**SKULL.V (Vocabulary):**
- Word list (~400 words)
- Verb definitions
- Noun definitions
- Adjective definitions

---

## 🔓 Extracting Game Content

### Using the Decryption Tool

**1. Decrypt all game files:**
```bash
python decrypt.py SKULL.M SKULL.M.txt
python decrypt.py SKULL.X SKULL.X.txt
python decrypt.py SKULL.T SKULL.T.txt
python decrypt.py SKULL.V SKULL.V.txt
```

**2. Analyze file structure:**
```bash
python decrypt.py --analyze SKULL.M
```

**3. Extract strings:**
- Decrypted files contain length-prefixed strings
- Parse using 2-byte length prefix
- Extract text for analysis

### Creating Complete Walkthrough

With decrypted data, you can:
- ✅ Map all locations
- ✅ List all objects
- ✅ Document all puzzles
- ✅ Create complete solution
- ✅ Build comprehensive guide

---

## 🛡️ Security Considerations

### Not Real Security

**Important Notes:**
- This is **obfuscation**, not encryption
- Provides **no real security**
- Easily broken by anyone
- Appropriate for 1980s shareware

**Modern Perspective:**
- Would use AES or similar today
- Key management would be required
- Much stronger protection available
- But unnecessary for game text

**Why It's Okay:**
- Game is shareware (meant to be shared)
- No sensitive data
- Just prevents casual viewing
- Historical artifact from different era

---

## 📝 Code Implementation

### C Implementation (from game)

```c
// From skull_ported.c, line 8891-8896
for (decrypt_index = 0; decrypt_index < string_length - 1; decrypt_index++) {
    if (decrypt_index + buffer_ptr >= 0 && 
        decrypt_index + buffer_ptr < (int)g_gameState->memory_pool_size) {
        decrypt_ptr = (byte *)(g_gameState->memory_pool + decrypt_index + buffer_ptr);
        *decrypt_ptr = *decrypt_ptr ^ BIT_MASK_LOW_8;  // XOR with 0xFF
    }
}
```

### Simplified Version

```c
void decrypt_string(unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] ^= 0xFF;  // XOR each byte with 0xFF
    }
}
```

### One-Liner

```c
// Encrypt/decrypt a single byte
#define CRYPT_BYTE(b) ((b) ^ 0xFF)
```

---

## 🎓 Educational Value

### Learning Points

**Cryptography Basics:**
- XOR cipher is simplest encryption
- Demonstrates symmetric encryption
- Shows importance of key strength
- Historical example of obfuscation

**Reverse Engineering:**
- Finding encryption in compiled code
- Identifying encryption patterns
- Breaking simple ciphers
- Understanding data formats

**Game Development:**
- Data file formats
- String table design
- Resource management
- Memory-efficient storage

---

## 📚 References

### Related Files

- `skull_ported.c` - Contains decryption code
- `game_constants.h` - Defines BIT_MASK_LOW_8
- `SKULL.DOC` - Original game documentation
- Data files: SKULL.M, SKULL.X, SKULL.T, SKULL.V, SKULL.MM, SKULL.MO

### Functions

- `load_string_from_file()` - Main decryption function (line 8832)
- `load_string_from_secondary_file()` - Alternative loader (line 8935)
- `file_read_word()` - Reads length prefix
- `file_seek()` - Positions file pointer

---

## 🎯 Summary

### Key Points

1. **Encryption Method:** Simple XOR with 0xFF (bit inversion)
2. **Purpose:** Obfuscation, not security
3. **Reversible:** Same operation encrypts and decrypts
4. **Fast:** Single CPU instruction per byte
5. **Historical:** Common in 1980s shareware
6. **Breakable:** Trivial to reverse engineer
7. **Appropriate:** Sufficient for game text protection

### Decryption Formula

```
decrypted_byte = encrypted_byte XOR 0xFF
```

That's it! The entire encryption system in one line.

---

**Document Version:** 1.0  
**Created:** 2026-01-17  
**Status:** Complete analysis  
**Purpose:** Educational and documentation

---

## ✅ Conclusion

The Skull Game uses a simple but effective XOR-based encryption that was perfect for its time and purpose. While not cryptographically secure by modern standards, it successfully prevents casual viewing of game text while remaining fast and easy to implement.

**For creating a complete walkthrough, you can now:**
1. Decrypt the data files using the provided tools
2. Extract all game strings and descriptions
3. Map the complete game world
4. Document all puzzles and solutions
5. Create the ultimate comprehensive guide!

🔐🎮📖
