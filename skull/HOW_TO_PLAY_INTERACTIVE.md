# How to Play Skullduggery Interactively

## The Change

The game now supports **two input modes**:

### 1. Interactive Mode (Keyboard Entry)
When you run the game directly, you can type commands:

```batch
cd skull
.\skull.exe
```

You'll see prompts like this:
```
Welcome to SKULLDUGGERY!

You are in a damp underground tunnel. The tree roots growing across
the tunnel make passage very difficult here. There's a hole above you.

> _
```

Just type your commands and press Enter!

### 2. Piped Mode (Automated Scripts)
When you pipe commands in, it works as before:

```powershell
@('look', 'inventory', 'quit') -join "`n" | .\skull.exe
```

## What Changed in the Code

### File: `dos_compat.c`

**Added detection for interactive mode:**
```c
/* Check if stdin is interactive (not piped) */
static int is_stdin_interactive(void) {
    #ifdef _WIN32
    return _isatty(_fileno(stdin));
    #else
    return isatty(fileno(stdin));
    #endif
}
```

**Modified `read_piped_input_line()` to:**
1. Detect if stdin is a terminal (interactive) or pipe
2. Show `> ` prompt **before** reading input in interactive mode
3. Only echo commands in piped mode (for logs)

## Key Differences

| Feature | Interactive Mode | Piped Mode |
|---------|-----------------|------------|
| **Prompt** | Shows `> ` before input | Shows `> ` after input (echo) |
| **Detection** | `_isatty(_fileno(stdin))` returns 1 | Returns 0 |
| **User Experience** | Type commands as you go | Pre-scripted commands |

## Testing Interactive Mode

### Simple Test
```batch
.\skull.exe
```

Then type:
```
look
inventory
up
look
quit
```

### Complete Walkthrough (Interactive)
Run the game and type these commands:
```
up
southeast
southwest
east
take lamp
south
north
down
north
take potion
down
take treasure
```

## Available Commands

See `SIMPLE_GAME_ENGINE.md` for a complete list of commands, but here are the essentials:

- **Movement**: `up`, `down`, `north`, `south`, `east`, `west`, `northeast`, `southeast`, `southwest`, `northwest`
- **Actions**: `look`, `inventory`, `take <item>`, `examine <item>`
- **System**: `quit`

## Troubleshooting

**Q: I don't see a prompt**
- Make sure you're running `skull.exe` directly in a terminal
- Don't pipe input: just run `.\skull.exe` and type

**Q: The prompt appears but nothing happens when I type**
- Press Enter after typing your command
- Make sure the terminal window has focus

**Q: Commands are echoed twice**
- This is normal in some terminals - one echo is from the terminal, one from the game
- The game will only echo in piped mode, not interactive mode

## Demo Scripts Still Work

All existing demo scripts continue to work:
```powershell
.\demo_complete_game.ps1  # (without the keypress pause)
```

Or inline:
```powershell
@('up', 'southeast', 'southwest', 'east', 'take lamp', 'south', 'north', 'down', 'north', 'take potion', 'down', 'take treasure') -join "`n" | .\skull.exe
```

## Technical Details

The game uses Windows' `_isatty()` function to detect if `stdin` is:
- **A terminal** (file descriptor refers to an interactive console) → Interactive mode
- **A pipe or file** (redirected from another source) → Piped mode

This is determined once at the first input read and cached for performance.
