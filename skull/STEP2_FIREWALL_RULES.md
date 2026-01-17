# Step 2: Add Windows Firewall Rules for Cursor

## Quick Method: Run the Script (Recommended)

1. **Open PowerShell as Administrator:**
   - Press `Win + X`
   - Select "Windows PowerShell (Admin)" or "Terminal (Admin)"
   - OR Right-click PowerShell → "Run as Administrator"

2. **Navigate to this directory:**
   ```powershell
   cd "C:\Users\Danie\Documents\GitHub\DosGame\skull"
   ```

3. **Run the script:**
   ```powershell
   .\add_cursor_firewall_rules.ps1
   ```

4. **Verify the rules were created:**
   - The script will show which rules were created
   - You should see 3 rules: HTTPS, HTTP, and All Outbound

5. **Restart Cursor:**
   - Close all Cursor windows
   - Reopen Cursor
   - Test if timeouts are resolved

---

## Manual Method: Add Rules via GUI

If you prefer to add rules manually:

1. **Open Windows Defender Firewall:**
   - Press `Win + R`
   - Type: `wf.msc`
   - Press Enter

2. **Create Outbound Rule:**
   - Click "Outbound Rules" in the left panel
   - Click "New Rule..." in the right panel

3. **Rule Type:**
   - Select "Program"
   - Click Next

4. **Program Path:**
   - Select "This program path:"
   - Browse to: `C:\Program Files\cursor\Cursor.exe`
   - Click Next

5. **Action:**
   - Select "Allow the connection"
   - Click Next

6. **Profile:**
   - Check all: Domain, Private, Public
   - Click Next

7. **Name:**
   - Name: `Cursor HTTPS Outbound`
   - Description: `Allow Cursor to make HTTPS connections`
   - Click Finish

8. **Repeat for HTTP (Port 80):**
   - Create another rule for port 80
   - Or create a rule for "All ports" if you want broader access

---

## Manual Method: Add Rules via PowerShell (One-by-One)

Run these commands in PowerShell (as Administrator):

### Rule 1: HTTPS (Port 443)
```powershell
New-NetFirewallRule -DisplayName "Cursor HTTPS Outbound" `
    -Direction Outbound `
    -Program "C:\Program Files\cursor\Cursor.exe" `
    -Action Allow `
    -Protocol TCP `
    -LocalPort Any `
    -RemotePort 443 `
    -Profile Any
```

### Rule 2: HTTP (Port 80)
```powershell
New-NetFirewallRule -DisplayName "Cursor HTTP Outbound" `
    -Direction Outbound `
    -Program "C:\Program Files\cursor\Cursor.exe" `
    -Action Allow `
    -Protocol TCP `
    -LocalPort Any `
    -RemotePort 80 `
    -Profile Any
```

### Rule 3: All Outbound (Broader)
```powershell
New-NetFirewallRule -DisplayName "Cursor All Outbound" `
    -Direction Outbound `
    -Program "C:\Program Files\cursor\Cursor.exe" `
    -Action Allow `
    -Protocol Any `
    -Profile Any
```

---

## Verify Rules Were Created

Run this command to see all Cursor firewall rules:

```powershell
Get-NetFirewallRule -DisplayName "Cursor*" | Format-Table DisplayName, Enabled, Direction, Action
```

You should see:
- `Cursor HTTPS Outbound` - Enabled
- `Cursor HTTP Outbound` - Enabled  
- `Cursor All Outbound` - Enabled

---

## Remove Rules (if needed)

If you need to remove the rules:

```powershell
Remove-NetFirewallRule -DisplayName "Cursor HTTPS Outbound"
Remove-NetFirewallRule -DisplayName "Cursor HTTP Outbound"
Remove-NetFirewallRule -DisplayName "Cursor All Outbound"
```

---

## Troubleshooting

### "Access Denied" Error
- Make sure PowerShell is running as Administrator
- Right-click PowerShell → "Run as Administrator"

### Rules Created But Cursor Still Times Out
- Check if Bitdefender is still blocking (Step 1)
- Verify DNS settings (Step 3)
- Check Windows Firewall is not blocking at a higher level
- Try temporarily disabling Windows Firewall to test

### Can't Find Cursor.exe
- Verify Cursor is installed at: `C:\Program Files\cursor\Cursor.exe`
- If installed elsewhere, update the path in the script

### Firewall Rules Not Working
- Make sure rules are enabled: `Enable-NetFirewallRule -DisplayName "Cursor*"`
- Check firewall profile (Domain/Private/Public) matches your network
- Verify Windows Firewall service is running: `Get-Service mpssvc`

---

## Next Steps

After completing Step 2:
- ✅ Restart Cursor
- ✅ Test for a few minutes
- ✅ If timeouts persist, proceed to **Step 3: Change DNS Servers**
- ✅ Check `CURSOR_TIMEOUT_FIX.md` for all solutions

---

## Quick Test

After adding rules, test connectivity:

```powershell
Test-NetConnection -ComputerName cursor.sh -Port 443
```

Should show: `TcpTestSucceeded : True`




