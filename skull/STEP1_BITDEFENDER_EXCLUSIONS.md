# Step 1: Add Cursor to Bitdefender Exclusions

## Quick Steps

### Method 1: Through Bitdefender Interface (Recommended)

1. **Open Bitdefender**
   - Look for the Bitdefender icon in your system tray (bottom-right corner)
   - Right-click it and select "Open Bitdefender"
   - OR search for "Bitdefender" in Windows Start menu

2. **Navigate to Exclusions**
   - Click on **"Protection"** (or shield icon)
   - Click on **"Antivirus"** (or "Antivirus Shield")
   - Click on **"Exclusions"** (or "Exceptions" / "Excluded Items")

3. **Add Cursor Exclusions**
   - Click **"Add"** or **"Add Exception"** button
   - You'll need to add these paths:

   **Path 1:**
   ```
   C:\Program Files\cursor\Cursor.exe
   ```
   - Select: **"File"** or **"Application"**
   - Browse to: `C:\Program Files\cursor\Cursor.exe`
   - Make sure these are checked:
     - ✅ Real-time Protection
     - ✅ Web Protection  
     - ✅ Advanced Threat Defense
     - ✅ All components (if available)

   **Path 2:**
   ```
   C:\Program Files\cursor\resources\app\**\*
   ```
   - Select: **"Folder"** or **"Directory"**
   - Browse to: `C:\Program Files\cursor\resources\app\`
   - Check "Include subfolders" or use wildcard `**\*`

   **Path 3 (Optional but recommended):**
   ```
   %APPDATA%\Cursor\**\*
   ```
   - This expands to: `C:\Users\Danie\AppData\Roaming\Cursor\**\*`
   - Select: **"Folder"**
   - Browse to: `C:\Users\Danie\AppData\Roaming\Cursor\`
   - Check "Include subfolders"

4. **Save Settings**
   - Click **"Save"** or **"Apply"** for each exclusion
   - Click **"OK"** to close the settings

5. **Restart Cursor**
   - Close all Cursor windows
   - Reopen Cursor
   - Test if timeouts are resolved

---

### Method 2: Quick Access via System Tray

1. Right-click **Bitdefender icon** in system tray
2. Look for **"Exclusions"** or **"Settings"** → **"Exclusions"**
3. Follow steps 3-5 from Method 1

---

### Method 3: Search in Bitdefender

1. Open Bitdefender
2. Use the search box (if available) and type: **"exclusions"**
3. Click on the result
4. Follow steps 3-5 from Method 1

---

## Verification

After adding exclusions, verify they're working:

1. **Check if exclusions are listed:**
   - Go back to Exclusions page
   - You should see Cursor paths listed

2. **Test Cursor connectivity:**
   - Open PowerShell
   - Run: `Test-NetConnection -ComputerName cursor.sh -Port 443`
   - Should show: `TcpTestSucceeded : True`

3. **Monitor Bitdefender logs:**
   - In Bitdefender, check if Cursor is still being scanned/blocked
   - Look for any alerts related to Cursor

---

## Troubleshooting

### If you can't find Exclusions:
- Look for: **"Exceptions"**, **"Excluded Items"**, **"Whitelist"**, or **"Allowed Items"**
- Different Bitdefender versions may use different terms

### If Cursor still times out:
- Make sure you added **ALL** the paths listed above
- Check that **Web Protection** exclusion is enabled (not just Antivirus)
- Try temporarily disabling Bitdefender Web Protection to test
- Proceed to Step 2 (Windows Firewall rules)

### If Bitdefender won't open:
- Check if Bitdefender service is running: `Get-Service | Where-Object {$_.Name -like "*bd*"}`
- Try restarting Bitdefender service
- Check Windows Event Viewer for errors

---

## Next Steps

After completing Step 1:
- ✅ Test Cursor for a few minutes
- ✅ If timeouts persist, proceed to **Step 2: Add Windows Firewall Rules**
- ✅ Check `CURSOR_TIMEOUT_FIX.md` for all solutions

---

## Quick Reference: Paths to Exclude

Copy these paths when adding exclusions:

```
C:\Program Files\cursor\Cursor.exe
C:\Program Files\cursor\resources\app\**\*
C:\Users\Danie\AppData\Roaming\Cursor\**\*
```

Make sure to enable exclusions for:
- ✅ Real-time Protection
- ✅ Web Protection
- ✅ Advanced Threat Defense




