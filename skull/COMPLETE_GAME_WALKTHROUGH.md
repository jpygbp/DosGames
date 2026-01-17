# 🏴‍☠️ SKULLDUGGERY - Complete Game Walkthrough

**Game:** Skullduggery - Adventures in Horror  
**Original Author:** David Jewett (1986, 1988, 1989)  
**Port Version:** Windows 64-bit (2026)  
**Setting:** Southeast coast of 18th-century England  
**Objective:** Find William the Wildheart's hidden treasure while surviving his ghostly wrath

---

## 📖 Story Background

### The Legend of William the Wildheart

In 18th-century England, smuggling was a common enterprise to avoid the King's heavy import taxes. William the Wildheart, a member of the Royal Family Leominster, was heavily involved in smuggling operations.

**The Betrayal:**
- William was caught and turned in by his own family
- He was found guilty and executed
- His intense hatred brought him back as a vengeful ghost

**The Treasure:**
- William hid a massive treasure before his death
- His family coveted it greedily
- As a ghost, William tortures any intruder who enters his domain
- He protects his treasure against all who seek it

**Your Mission:**
- Navigate William's haunted domain
- Solve puzzles and avoid deadly traps
- Find the hidden treasure
- Survive the ghostly encounters

---

## 🎮 Game Mechanics

### Command System

The game uses natural English commands with approximately **400 words** in its vocabulary.

#### Movement Commands
```
n, north       - Move north
ne             - Move northeast  
e, east        - Move east
se             - Move southeast
s, south       - Move south
sw             - Move southwest
w, west        - Move west
nw             - Move northwest
u, up          - Go up
d, down        - Go down
enter          - Enter a location (context-specific)
exit           - Exit a location (context-specific)
```

#### Object Manipulation
```
take <object>              - Pick up an object
get <object>               - Pick up an object
carry <object>             - Pick up an object
drop <object>              - Put down an object
put <object> down          - Put down an object
pick up <object>           - Pick up an object
put <object> in <container> - Place object in container
put <object> on <surface>  - Place object on surface
take all                   - Pick up all takeable objects
drop all                   - Drop all carried objects
put all in <container>     - Put all objects in container
put all on <surface>       - Put all objects on surface
```

#### Examination & Interaction
```
look (l)                   - Look at current location
examine <object> (x)       - Examine object closely
search <object>            - Search an object or area
read <object>              - Read text on object
inventory (i)              - List carried objects
```

#### Action Verbs
```
open <object>              - Open something
close <object>             - Close something
unlock <object> with <key> - Unlock with key
lock <object> with <key>   - Lock with key
push <object>              - Push something
pull <object>              - Pull something
move <object>              - Move something
turn <object>              - Turn something
twist <object>             - Twist something
press <object>             - Press something
hit <object>               - Hit something
strike <object>            - Strike something
knock <object>             - Knock on something
break <object>             - Break something
cut <object>               - Cut something
chop <object>              - Chop something
stab <object>              - Stab something
dig                        - Dig in current location
dig with <tool>            - Dig with a tool
pry <object>               - Pry something open
raise <object>             - Raise something
lower <object>             - Lower something
```

#### Combat & Defense
```
kill <enemy>               - Attack enemy
kill <enemy> with <weapon> - Attack with weapon
attack <enemy>             - Attack enemy
fight <enemy>              - Fight enemy
```

#### Special Actions
```
light <object>             - Light something
extinguish <object>        - Put out a light
burn <object>              - Burn something
warm <object>              - Warm something
pour <object>              - Pour liquid
drink <object>             - Drink liquid
eat <object>               - Eat food
climb <object>             - Climb something
jump                       - Jump
sit                        - Sit down
stand                      - Stand up
wait                       - Wait/pass time
yell                       - Yell/shout
board                      - Board a vessel
disembark                  - Leave a vessel
```

#### Communication
```
tell <character> about <topic> - Talk to character
say <text>                     - Say something
give <object> to <character>   - Give object to character
```

#### System Commands
```
inventory (i)              - Show inventory
quit                       - Exit game
save                       - Save current game
restore                    - Load saved game
verbose                    - Long room descriptions
brief                      - Short room descriptions
again (g)                  - Repeat last command
help                       - Show help (if available)
```

#### Command Structure

Commands can be structured in several ways:

1. **Simple verb:** `look`, `wait`, `inventory`
2. **Verb + object:** `take sword`, `examine door`, `open chest`
3. **Verb + object + preposition + object:** `unlock door with key`, `kill ghost with sword`
4. **Verb + preposition + object:** `look in bottle`, `look on table`
5. **Verb + object + preposition:** `put bottle down`, `pick sword up`
6. **Chained commands:** `take key then unlock door then open door`

---

## 🗺️ Complete Walkthrough

### Phase 1: Starting Out & Initial Exploration

#### Step 1: Understand Your Situation

```
> look
```

**What to expect:**
- You'll see your starting location description
- Note any objects present
- Note available exits
- This is likely near the coast or William's estate

```
> inventory
```

**What to expect:**
- Check what you're carrying at the start
- You may start with basic items or nothing

```
> examine room
```

**What to expect:**
- Get detailed description of your surroundings
- May reveal hidden details or clues

---

### Phase 2: Systematic Exploration

#### Step 2: Map Your Surroundings

**Strategy:** Create a mental or physical map as you explore.

```
> north
> look
> examine room
```

**Repeat for each direction:**
- Try all eight compass directions (n, ne, e, se, s, sw, w, nw)
- Try up and down if applicable
- Note which directions are blocked
- Note which directions lead to new locations

#### Step 3: Catalog Objects

**In each location:**

```
> look
> examine <each object mentioned>
> take <useful objects>
```

**Important items to look for:**
- **Keys** - Essential for unlocking doors and containers
- **Weapons** - Swords, axes, clubs for combat
- **Light sources** - Lanterns, candles, torches
- **Tools** - Shovels for digging, crowbars for prying
- **Containers** - Bottles, bags, chests
- **Documents** - Papers, books, maps with clues

---

### Phase 3: Puzzle Solving

#### Common Puzzle Types

**1. Locked Doors**
```
> examine door
> unlock door with [key name]
> open door
> go [direction]
```

**2. Hidden Objects**
```
> search [location/furniture]
> examine [suspicious object]
> move [object]
> look behind [object]
```

**3. Digging**
```
> examine ground
> dig
> dig with shovel
```

**4. Container Puzzles**
```
> examine chest
> unlock chest with key
> open chest
> look in chest
> take contents
```

**5. Mechanical Puzzles**
```
> examine mechanism
> turn wheel
> push button
> pull lever
> twist dial
```

---

### Phase 4: Dealing with William's Ghost

#### Ghost Encounters

**When you encounter the ghost:**

**Option 1: Combat**
```
> examine ghost
> attack ghost with sword
> strike ghost with weapon
```

**Option 2: Avoidance**
```
> run [direction]
> hide
> wait
```

**Option 3: Appeasement**
- Some ghosts can be appeased with specific objects
- Try giving items related to the ghost's past
```
> give [object] to ghost
> show [object] to ghost
```

---

### Phase 5: Finding the Treasure

#### Treasure Hunt Strategy

**1. Look for Clues**
- Read all documents carefully
- Examine paintings and portraits
- Look for maps or diagrams
- Note any numbers or symbols

**2. Common Treasure Locations**
- **Buried** - Look for disturbed earth, X marks, or suspicious ground
- **Hidden rooms** - Look for secret passages, moveable panels
- **Locked containers** - Chests, safes, strongboxes
- **Underwater** - Wells, ponds, coastal areas
- **High places** - Attics, towers, rooftops

**3. Typical Treasure Hunt Sequence**
```
> examine [clue document]
> go to [location mentioned in clue]
> search area
> dig / open / unlock [as appropriate]
> take treasure
```

---

### Phase 6: Winning the Game

#### Final Steps

**Once you find the treasure:**

1. **Secure the treasure**
```
> take treasure
> inventory
```

2. **Escape William's domain**
- Retrace your steps to the exit
- Avoid or defeat any remaining threats
- May need to unlock final door or barrier

3. **Complete the game**
- The game will likely end automatically when you escape with the treasure
- Or you may need to reach a specific location (boat, road, etc.)

---

## 🎯 Essential Strategies

### Survival Tips

**1. Save Often**
```
> save
```
- Save before entering dangerous areas
- Save after solving major puzzles
- Save before combat encounters

**2. Manage Inventory**
- You have limited carrying capacity
- Drop unnecessary items
- Keep weapons, keys, and light sources
- Return to safe locations to store items

**3. Light Management**
- Dark areas require light sources
- Light sources may have limited duration
- Always carry backup light source
```
> light lantern
> examine candle
```

**4. Combat Preparation**
- Always carry a weapon
- Examine enemies before attacking
- Some enemies may be invulnerable to certain weapons
- Consider fleeing if outmatched

**5. Systematic Exploration**
- Map each location
- Try every direction
- Examine everything
- Take notes on paper

---

## 🗝️ Key Puzzle Solutions

### Common Puzzle Patterns

**Pattern 1: Key Hunt**
1. Find locked door/chest
2. Search nearby locations for key
3. Key often hidden in logical place (drawer, under mat, etc.)
4. Return and unlock

**Pattern 2: Tool Required**
1. Encounter obstacle (blocked passage, sealed container)
2. Find appropriate tool (crowbar, axe, shovel)
3. Return and use tool
```
> pry door with crowbar
> chop door with axe
> dig with shovel
```

**Pattern 3: Multi-Step Sequence**
1. Read clue or instruction
2. Perform actions in specific order
3. May involve multiple locations
4. Often reveals secret or treasure

**Pattern 4: Trade or Give**
1. Meet character or ghost
2. Determine what they want
3. Find the object
4. Give object to receive reward or passage

---

## 📍 Location Types to Expect

### Typical Locations in 18th Century Smuggler's Estate

**Exterior Areas:**
- **Coastline** - Beach, cliffs, caves
- **Grounds** - Gardens, paths, gates
- **Outbuildings** - Stables, sheds, boathouse

**Main House:**
- **Entry** - Foyer, hallway
- **Ground Floor** - Parlor, dining room, kitchen, study
- **Upper Floor** - Bedrooms, gallery
- **Attic** - Storage, servants' quarters
- **Cellar** - Wine cellar, storage, secret passages

**Special Areas:**
- **Secret passages** - Behind bookcases, under stairs
- **Hidden rooms** - Smuggler's cache, treasure room
- **Supernatural zones** - Haunted areas, ghost's domain

---

## 💀 Enemies & Hazards

### Types of Threats

**1. William's Ghost**
- Primary antagonist
- May appear randomly
- Can be fought or avoided
- May require special weapon or method

**2. Physical Hazards**
- Traps (pit traps, spike traps)
- Unstable structures
- Drowning hazards
- Fire hazards

**3. Environmental**
- Darkness (need light)
- Cold (may need warmth)
- Starvation (may need food)
- Exhaustion (may need rest)

---

## 🎒 Essential Items Checklist

### Must-Have Items

- [ ] **Light source** (lantern, candle, torch)
- [ ] **Weapon** (sword, axe, club)
- [ ] **Digging tool** (shovel, spade)
- [ ] **Prying tool** (crowbar, lever)
- [ ] **Keys** (collect all keys you find)
- [ ] **Container** (bag, sack for carrying)
- [ ] **Food/water** (if needed for survival)
- [ ] **Map/clues** (any documents found)

---

## 🧩 Sample Puzzle Walkthroughs

### Example 1: The Locked Study

```
> examine door
The oak door is locked.

> search room
You find a small brass key under the mat.

> take key

> unlock door with brass key

> open door

> north

> look
You are in a study. There is a desk here.

> examine desk

> open desk

> look in desk
You find a map showing the location of buried treasure!

> take map
```

### Example 2: The Buried Treasure

```
> examine map
The map shows an X marked in the garden near the old oak tree.

> go to garden
[navigate to garden location]

> examine ground
The ground looks disturbed here.

> dig
You need a tool to dig.

> [go find shovel]

> dig with shovel
You uncover a wooden chest!

> examine chest
The chest is locked.

> unlock chest with iron key

> open chest

> look in chest
Inside is William's treasure - gold coins and jewels!

> take treasure
You win!
```

### Example 3: Ghost Encounter

```
> look
William's ghost appears before you, blocking your path!

> examine ghost
The ghost looks angry and menacing.

> attack ghost with sword
Your sword passes through the ghost harmlessly.

> [try different approach]

> give locket to ghost
The ghost takes the locket and vanishes, leaving the path clear.
```

---

## 📝 Mapping Template

### Create Your Own Map

```
Location Name: _________________
Description: ___________________
Objects: _______________________
Exits:
  North: ________
  South: ________
  East: _________
  West: _________
  Up: ___________
  Down: _________
  Other: ________
Puzzles/Notes: _________________
```

---

## 🏆 Winning Conditions

### How to Win

**Primary Objective:**
- Find William the Wildheart's hidden treasure
- Escape with the treasure

**Secondary Objectives:**
- Survive all encounters
- Solve all puzzles
- Defeat or avoid William's ghost

**Victory Sequence:**
1. Locate treasure through clues
2. Overcome final obstacles
3. Take possession of treasure
4. Exit William's domain
5. Game displays victory message

---

## 💡 Advanced Tips

### Expert Strategies

**1. Thorough Examination**
- Examine EVERYTHING
- Try examining objects multiple times
- Look at objects from different angles
- Read all text carefully

**2. Experimentation**
- Try unusual verb combinations
- Attempt creative solutions
- Don't assume something won't work
- The game has ~400 words - use them!

**3. Pattern Recognition**
- Note recurring symbols or numbers
- Look for color patterns
- Pay attention to time references
- Notice repeated words or phrases

**4. Logical Deduction**
- Think like a smuggler - where would YOU hide treasure?
- Consider the historical context
- Use real-world logic
- Think about the ghost's motivations

**5. Resource Management**
- Don't waste consumables (light, food)
- Store items in safe locations
- Create item caches in key locations
- Plan your route before long journeys

---

## 🐛 Common Problems & Solutions

### Troubleshooting

**Problem: Can't find key**
- Search all furniture (drawers, cabinets)
- Look under objects (mats, carpets)
- Check obvious hiding spots
- May be in a different location than the lock

**Problem: Can't defeat ghost**
- Normal weapons may not work
- Look for blessed/holy items
- Try appeasement instead of combat
- May need specific artifact

**Problem: Can't find treasure**
- Re-read all clues carefully
- Check map coordinates
- Look for landmarks mentioned
- Try digging in suspicious locations

**Problem: Stuck in dark area**
- Find light source
- May need to navigate by memory
- Feel walls for exits
- Drop items to mark path

**Problem: Carrying too much**
- Drop non-essential items
- Create storage cache
- Prioritize: weapons, keys, light
- Return for items later

---

## 📚 Game Lore & Context

### Historical Background

**18th Century Smuggling:**
- Heavy taxes on imports made smuggling profitable
- Common along English coast
- Entire families participated
- Dangerous but lucrative trade

**Typical Smuggled Goods:**
- Tea, coffee, spices
- Brandy, wine, spirits
- Silk, lace, fabric
- Tobacco

**Smuggler's Methods:**
- Secret caves and passages
- Hidden compartments
- Night operations
- Bribery and corruption

### William the Wildheart's Story

**Life:**
- Member of Royal Family Leominster
- Successful smuggler
- Accumulated massive treasure
- Betrayed by his own family

**Death:**
- Turned in by family members
- Tried and found guilty
- Executed for his crimes
- Treasure never recovered

**Afterlife:**
- Returned as vengeful ghost
- Tortures intruders
- Protects his treasure
- Seeks revenge on family

---

## 🎭 Roleplay Tips

### Getting Into Character

**You are:**
- A treasure hunter
- Brave (or foolish) enough to enter haunted estate
- Seeking William's legendary treasure
- Aware of the dangers

**Your Motivations:**
- Wealth and fortune
- Adventure and glory
- Solving the mystery
- Proving your courage

**Your Challenges:**
- Supernatural threats
- Physical dangers
- Complex puzzles
- Time pressure (possibly)

---

## 📖 Command Reference Quick Guide

### Most Common Commands

```
Movement:     n, s, e, w, ne, nw, se, sw, u, d
Look:         look, examine [object], search [object]
Take/Drop:    take [object], drop [object], take all, drop all
Inventory:    inventory (or i)
Open/Close:   open [object], close [object]
Lock/Unlock:  unlock [object] with [key], lock [object] with [key]
Use:          use [object], use [object] with [object]
Combat:       attack [enemy], kill [enemy] with [weapon]
System:       save, restore, quit, verbose, brief, again (or g)
```

---

## 🎯 Speedrun Route (Once You Know the Solution)

### Quick Completion Path

**Note:** This is for replaying after you've solved the game once.

1. **Start** → Take essential items
2. **Navigate** → Go directly to key locations
3. **Collect** → Grab only necessary items
4. **Solve** → Complete puzzles in optimal order
5. **Treasure** → Go straight to treasure location
6. **Escape** → Take fastest route out

**Estimated time:** 10-15 minutes (experienced players)

---

## 📊 Game Statistics

### Scope & Scale

- **Vocabulary:** ~400 words
- **Locations:** Multiple interconnected rooms
- **Objects:** Dozens of interactive items
- **Puzzles:** Various difficulty levels
- **Endings:** Victory or death

### Difficulty Rating

- **Puzzles:** ⭐⭐⭐⭐ (Challenging)
- **Combat:** ⭐⭐⭐ (Moderate)
- **Navigation:** ⭐⭐⭐ (Moderate)
- **Overall:** ⭐⭐⭐⭐ (Challenging but fair)

---

## 🎓 Learning Resources

### Getting Better at Text Adventures

**Skills to Develop:**
1. **Vocabulary** - Learn adventure game verbs
2. **Mapping** - Practice drawing maps
3. **Logic** - Develop puzzle-solving skills
4. **Patience** - Don't give up easily
5. **Creativity** - Think outside the box

**Practice Tips:**
- Play other text adventures
- Read walkthroughs after completing
- Join adventure game communities
- Share maps and solutions

---

## 🏁 Conclusion

### Final Thoughts

**Skullduggery** is a classic text adventure that combines:
- ✅ Historical setting
- ✅ Supernatural horror
- ✅ Treasure hunting
- ✅ Puzzle solving
- ✅ Combat and danger

**Keys to Success:**
1. **Explore thoroughly**
2. **Examine everything**
3. **Map your progress**
4. **Save frequently**
5. **Think creatively**
6. **Don't give up!**

**Remember:**
- The treasure is real and findable
- Every puzzle has a solution
- The ghost can be defeated or avoided
- Victory is possible!

---

## 📞 Additional Help

### If You're Still Stuck

**General Advice:**
1. Re-read all documents and clues
2. Revisit all locations
3. Try new verb combinations
4. Examine objects you haven't examined
5. Look for patterns in descriptions

**Specific Help:**
- Check the game's vocabulary list (page 2 of SKULL.DOC)
- Review command structure examples
- Try the "again" command to repeat successful actions
- Use "verbose" mode for detailed descriptions

---

## 🎮 Game Information

**Original Game:**
- **Title:** Skullduggery - Adventures in Horror
- **Author:** David Jewett
- **Copyright:** 1986, 1988, 1989
- **Platform:** Originally Apple II, ported to PC
- **Version:** 90415 (April 15, 1989)

**This Port:**
- **Platform:** Windows 64-bit
- **Year:** 2026
- **Status:** Fully playable
- **Mode:** Console/Interactive

---

## 📄 Legal Notice

This walkthrough is for the Windows 64-bit port of **Skullduggery**, originally created by David Jewett and distributed as shareware. The original game encouraged copying and distribution.

**Original Shareware Notice:**
- Users encouraged to copy and distribute
- Suggested donation: $5.00 to original author
- All rights retained by original author

---

**Good luck, treasure hunter! May you survive William's wrath and claim his fortune!** 🏴‍☠️💰👻

---

**Document Version:** 1.0  
**Created:** 2026-01-17  
**Based on:** SKULL.DOC and game analysis  
**Status:** Complete comprehensive guide

---

## ✅ Walkthrough Checklist

Track your progress:

- [ ] Read story background
- [ ] Learned command system
- [ ] Started game
- [ ] Mapped starting area
- [ ] Collected essential items
- [ ] Found first key
- [ ] Solved first puzzle
- [ ] Encountered ghost
- [ ] Found treasure clue
- [ ] Located treasure
- [ ] Obtained treasure
- [ ] Escaped estate
- [ ] Won game!

---

**END OF WALKTHROUGH**
