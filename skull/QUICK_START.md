# Skullduggery - Quick Start Guide

## 🎮 Play the Game NOW!

### Interactive Mode (Type Your Commands)
```batch
cd skull
.\skull.exe
```

Then type commands like:
- `look`
- `inventory`
- `up`
- `take lamp`
- `quit`

### Automated Demo (Watch Complete Playthrough)
```powershell
cd skull
@('up', 'southeast', 'southwest', 'east', 'take lamp', 'south', 'north', 'down', 'north', 'take potion', 'down', 'take treasure') -join "`n" | .\skull.exe
```

## 📖 Complete Solution (Spoilers!)

Just copy these commands one by one (or all at once in automated mode):

```
up           → Exit tunnel to dark forest
southeast    → Go to dirt road
southwest    → Reach estate entrance
east         → Enter guard shack
take lamp    → Get the lamp (important!)
south        → Approach mansion
north        → Enter mansion
down         → Go to cellar
north        → Find laboratory
take potion  → Get magic potion (required!)
down         → Descend to treasure cavern
take treasure → WIN THE GAME! 🎉
```

## 🗺️ Map

```
Underground Tunnel (START)
    ↓ up
Dark Forest
    ↓ southeast
Dirt Road
    ↓ southwest
Recessed Entrance
    ↓ east
Guard Shack [GET LAMP HERE]
    ↓ south
Mansion Front
    ↓ north
Mansion Entrance
    ↓ down
Cellar
    ↓ north
Laboratory [GET POTION HERE]
    ↓ down
Cavern of Jewels [TREASURE - YOU WIN!]
```

## 🎯 Essential Commands

| Command | What It Does |
|---------|--------------|
| `look` | Describe current location |
| `inventory` or `i` | Check what you're carrying |
| `take <item>` | Pick up an item |
| `up`, `down` | Go up or down |
| `north`, `south`, `east`, `west` | Move in a direction |
| `quit` | Exit game |

## 📚 More Documentation

- **`SIMPLE_GAME_ENGINE.md`** - Complete game documentation with detailed walkthrough
- **`HOW_TO_PLAY_INTERACTIVE.md`** - Interactive vs piped mode explained
- **`INTERACTIVE_MODE_SUMMARY.md`** - Technical details of the implementation

## 🏆 What You'll Experience

When you complete the game by taking the treasure, you'll see:

```
You reach for the treasure...

A shimmering glow appears, hanging in the centre of the cavern.
'At last', the words are exclaimed in your mind.
'You have solved the mysteries of my treasure.'

From henceforth you shall guard the treasure, protecting it from
fortune hunters around the world.

A cackling laugh echoes in your mind, as the glow fades into the shadows...

***** To be continued *****

THE CYCLE CONTINUES: You have become the new guardian of the treasure,
replacing William's ghost. Your spirit will now haunt these halls forever...

========================================
    CONGRATULATIONS!
  You have completed SKULLDUGGERY!
========================================
```

## 💡 Tips

- **Take the lamp first** - You'll need it later
- **The potion is essential** - Can't reach the treasure without it
- **Explore freely** - You can move around and revisit locations
- **Type `look`** - To see the location description again
- **Type `inventory`** - To check what you're carrying

## 🚀 That's It!

The game is ready to play. Just run `.\skull.exe` and start your adventure!

Have fun! 🎮✨
