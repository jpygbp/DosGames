# How to Switch Between Game Engines

## Quick Answer

**By default, the Simple Engine is ENABLED** and the game works perfectly.

To switch engines, edit one line in `simple_game_engine.h`:

```c
#define ENABLE_SIMPLE_ENGINE 1   // 1 = Simple Engine (DEFAULT)
                                 // 0 = Normal Engine only
```

---

## The Two Engines

### 🎮 Simple Engine (RECOMMENDED - DEFAULT)
- **Status:** ✅ Fully Working
- **Features:** 10 locations, inventory, movement, winning ending
- **Speed:** Instant response
- **Code:** 220 lines, clean and simple

### 🕹️ Normal Engine (Original DOS Code)
- **Status:** 🟡 Partially Working
- **Features:** Full original game (in theory)
- **Speed:** Slower due to complexity
- **Code:** 20,835 lines, complex DOS port

---

## How to Switch Engines

### Method 1: Edit the Header File (Recommended)

**File:** `simple_game_engine.h`

**Line 14:**
```c
#define ENABLE_SIMPLE_ENGINE 1
```

**Change to:**
```c
#define ENABLE_SIMPLE_ENGINE 0   // Disable Simple Engine
```

**Then rebuild:**
```batch
.\build_with_msvc.bat
```

### Method 2: Command Line Define (Advanced)

Edit `build_with_msvc.bat` and add `/D`:

```batch
cl /W3 /O2 /MD /DENABLE_SIMPLE_ENGINE=0 /Fe:skull.exe ...
```

---

## What Happens With Each Setting

### ENABLE_SIMPLE_ENGINE = 1 (Default - Recommended)

**Behavior:**
- Game starts with welcome and location description
- Commands like `look`, `take`, `move` work instantly
- Full playable game from start to winning ending
- Commands not recognized by Simple → passed to Normal Engine

**Output at start:**
```
Welcome to SKULLDUGGERY!

You are in a damp underground tunnel. The tree roots growing across
the tunnel make passage very difficult here. There's a hole above you.

> _
```

**Best for:**
- ✅ Playing the game
- ✅ Testing gameplay
- ✅ Demonstrating the port works
- ✅ Having fun!

---

### ENABLE_SIMPLE_ENGINE = 0 (Experimental)

**Behavior:**
- Game starts with generic welcome
- ALL commands go through complex Normal Engine
- May see errors, placeholder responses, or crashes
- File loading, message system, complex parsing attempted

**Output at start:**
```
Welcome to SKULLDUGGERY!
(Normal Engine Mode)

> _
```

**Best for:**
- 🔧 Debugging the Normal Engine
- 🔧 Testing wrapper functions
- 🔧 Developing DOS-to-Windows translation
- 🔧 Comparing engine behaviors

**Warning:** Most commands may not work properly!

---

## Testing Both Engines

### Test Simple Engine (Default)
```powershell
# Make sure ENABLE_SIMPLE_ENGINE = 1 in simple_game_engine.h
.\build_with_msvc.bat

# Test
@('look', 'inventory', 'up', 'quit') -join "`n" | .\skull.exe
```

**Expected:** Clean output, works perfectly ✅

### Test Normal Engine Only
```powershell
# Change ENABLE_SIMPLE_ENGINE = 0 in simple_game_engine.h
.\build_with_msvc.bat

# Test same commands
@('look', 'inventory', 'up', 'quit') -join "`n" | .\skull.exe
```

**Expected:** May see errors or placeholder text 🟡

---

## Code Flow Comparison

### With Simple Engine Enabled
```
User: "look"
    ↓
Input read
    ↓
Parse (tokenize)
    ↓
═══════════════════════
║ Simple Engine Check ║
═══════════════════════
    ↓
Match "look"? YES!
    ↓
simple_game_look()
    ↓
Display location
    ↓
DONE ✅
```

### With Simple Engine Disabled
```
User: "look"
    ↓
Input read
    ↓
Parse (tokenize)
    ↓
(No Simple Engine intercept)
    ↓
process_commands()
    ↓
DOS command parser
    ↓
lookup_command()
    ↓
File loading attempt
    ↓
Display wrapper
    ↓
May work or error 🟡
```

---

## File Changes Required

### To Disable Simple Engine:

**1. Edit `simple_game_engine.h`:**
```c
#define ENABLE_SIMPLE_ENGINE 0  // Line 14
```

**2. Rebuild:**
```batch
.\build_with_msvc.bat
```

**3. Test:**
```batch
.\skull.exe
```

### To Re-enable Simple Engine:

**1. Edit `simple_game_engine.h`:**
```c
#define ENABLE_SIMPLE_ENGINE 1  // Line 14
```

**2. Rebuild and enjoy!** ✅

---

## Why Have Both?

### Simple Engine Provides:
- ✅ **Immediate playability** - Game works NOW
- ✅ **Clean code** - Easy to understand and modify
- ✅ **Guaranteed results** - No DOS complexity

### Normal Engine Preserves:
- 📚 **Original code** - Complete DOS port
- 🔧 **Future potential** - Full game when debugged
- 📖 **Learning resource** - Study DOS-to-Windows porting

### Together They Give You:
- 🎮 A playable game RIGHT NOW (Simple)
- 🚀 The potential for the full original game (Normal)
- 🔄 The choice to use either one

---

## Recommendation

**Leave `ENABLE_SIMPLE_ENGINE = 1` (the default)**

This gives you:
- ✅ Fully working game
- ✅ Complete playthrough
- ✅ Winning ending
- ✅ Great user experience

**Only set to `0` if you want to:**
- Debug the Normal Engine
- Test wrapper functions
- Work on the DOS-to-Windows translation

---

## Summary

| Setting | Simple Engine | Normal Engine | Playable? |
|---------|---------------|---------------|-----------|
| `1` (Default) | ✅ Active | Fallback | **YES!** ✅ |
| `0` (Debug) | ❌ Disabled | Active | Partial 🟡 |

**Current status:** Simple Engine is enabled and the game is fully playable! 🎮✨
