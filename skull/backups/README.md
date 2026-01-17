# Build Backups

This directory contains automatic backups of compiled executables created after each successful build.

## Format

Backups are named with the following format:
```
<executable_name>_YYYYMMDD_HHMMSS.exe
```

Example: `skull_20250115_143022.exe`

## Purpose

These backups allow you to:
- Keep a history of working builds
- Roll back to a previous version if a new build breaks
- Compare different build versions
- Track changes over time

## Management

- Backups are created automatically after each successful compilation
- Old backups are not automatically deleted - you may want to clean them up periodically
- Backups are excluded from version control (see `.gitignore`)

## Manual Cleanup

To remove old backups, you can:
- Delete individual files manually
- Use PowerShell: `Get-ChildItem backups\*.exe | Where-Object {$_.LastWriteTime -lt (Get-Date).AddDays(-30)} | Remove-Item`
- Or simply delete the entire `backups` folder if you want to start fresh






