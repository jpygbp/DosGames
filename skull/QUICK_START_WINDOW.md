# 🚀 Quick Start - Window Mode
## Skull Game - Windows 11 Edition

---

## ⚡ TL;DR

```bash
# Build
.\build_window.bat

# Run with window
.\skull_window.exe --window

# Run with console
.\skull_window.exe --console

# Choose at startup
.\skull_window.exe
```

---

## 📦 What You Get

**TWO ways to play:**
1. **Console Mode** - Classic command-line (like original DOS)
2. **Window Mode** - Modern graphical window

---

## 🎮 How to Play

### Option 1: Choose When You Start
```bash
.\skull_window.exe
```
You'll see:
```
Choose display mode:
  1. Console Mode (text in command window)
  2. Window Mode (graphical window)

Enter choice (1 or 2):
```

### Option 2: Command Line
```bash
# Window mode (GUI)
.\skull_window.exe --window

# Console mode (CMD)
.\skull_window.exe --console
```

---

## 🔧 Building

### First Time Setup
```bash
cd c:\Users\Danie\Documents\GitHub\DosGame\skull
.\build_window.bat
```

### Rebuild After Changes
```bash
.\build_window.bat
```

---

## 📊 Comparison

| Feature | Console Mode | Window Mode |
|---------|-------------|-------------|
| **Look** | CMD window | Graphical window |
| **Font** | System default | Consolas (clean) |
| **Size** | Variable | 800×600 pixels |
| **Resize** | Yes | Yes |
| **Colors** | Limited | Full RGB |
| **Performance** | Fastest | Fast |
| **Debugging** | Easy | Medium |

---

## 🎯 Which Mode to Choose?

### Choose **Console Mode** if:
- ✅ You like classic DOS feel
- ✅ You want fastest performance
- ✅ You're debugging
- ✅ You want to redirect output

### Choose **Window Mode** if:
- ✅ You want modern look
- ✅ You want better readability
- ✅ You want colors
- ✅ You want professional appearance

---

## 🐛 Troubleshooting

### Build Fails
**Problem:** MSVC not found  
**Solution:** Check Visual Studio installation

**Problem:** Linking errors  
**Solution:** Run `vcvars64.bat` first

### Run Fails
**Problem:** Window doesn't appear  
**Solution:** Try console mode first: `.\skull_window.exe --console`

**Problem:** Text is garbled  
**Solution:** Check font installation (Consolas)

---

## 📝 Files

### Executables
- `skull_window.exe` - New dual-mode version
- `skull.exe` - Original console-only version

### Build Scripts
- `build_window.bat` - Build window version
- `build_with_msvc.bat` - Build console version

### Source Files
- `main_window.c` - New main with mode selection
- `game_window.c` - Window implementation
- `display_adapter.c` - Display routing

---

## 🎉 Features

### Window Mode Features
- ✅ 800×600 pixel window
- ✅ 100×37 text area
- ✅ Consolas font
- ✅ Double-buffered (smooth)
- ✅ Full keyboard input
- ✅ Auto-scrolling
- ✅ Cursor display

### Console Mode Features
- ✅ Standard CMD window
- ✅ Full logging
- ✅ Redirectable I/O
- ✅ Scriptable

---

## 🚀 Next Steps

1. **Build:** Run `.\build_window.bat`
2. **Test:** Run `.\skull_window.exe --window`
3. **Play:** Enjoy the game!
4. **Feedback:** Report any issues

---

## 📚 More Info

- **`GUI_WINDOW_IMPLEMENTATION.md`** - Technical details
- **`WINDOW_MODE_COMPLETE.md`** - Completion report
- **`STUB_TO_FULL_CONVERSION_PLAN.md`** - Full conversion plan

---

**Ready to play! 🎮**
