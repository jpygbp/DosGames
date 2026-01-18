/* Simple Game Engine for Skullduggery
 * Provides basic gameplay functionality until full game logic is implemented
 */

#include "dos_compat.h"
#include "game_constants.h"
#include <stdio.h>
#include <string.h>

/* Game locations */
typedef enum {
    LOC_UNDERGROUND_TUNNEL = 0,
    LOC_DARK_FOREST,
    LOC_DIRT_ROAD,
    LOC_RECESSED_ENTRANCE,
    LOC_GUARD_SHACK,
    LOC_DRIVEWAY,
    LOC_DRIVE_INTERSECTION,
    LOC_MANSION_FRONT,
    LOC_MANSION_ENTRANCE,
    LOC_FOYER,
    LOC_CONSERVATORY,
    LOC_CELLAR,
    LOC_LABORATORY,
    LOC_CAVERN_OF_JEWELS,  /* Winning location */
    LOC_MAX
} GameLocation;

/* Game state */
typedef struct {
    GameLocation current_location;
    int has_treasure;
    int has_potion;
    int has_lamp;
    int has_shovel;
    int game_won;
} SimpleGameState;

static SimpleGameState g_simple_game = {0};

/* Location descriptions */
static const char* get_location_description(GameLocation loc) {
    switch(loc) {
        case LOC_UNDERGROUND_TUNNEL:
            return "You are in a damp underground tunnel. The tree roots growing across\n"
                   "the tunnel make passage very difficult here. There's a hole above you.";
        case LOC_DARK_FOREST:
            return "You are surrounded by a dense, dark forest with thick bushes all around.\n"
                   "A trap door is embedded in the ground.";
        case LOC_DIRT_ROAD:
            return "You are on a dirt road. The path continues northeast and southwest.";
        case LOC_RECESSED_ENTRANCE:
            return "You are at a recessed section of the wrought-iron fence. This is an\n"
                   "entrance to a large estate. A sign reads 'Elysium Downs'.";
        case LOC_GUARD_SHACK:
            return "You are in an abandoned guard shack. There's a strong, musty odor here.\n"
                   "Cobwebs hang from the ceiling and mouse tracks run across the dusty floor.";
        case LOC_MANSION_FRONT:
            return "You are standing in front of a large, imposing mansion. Gothic architecture\n"
                   "looms before you. The windows are dark and foreboding.";
        case LOC_MANSION_ENTRANCE:
            return "You are in the mansion entrance. A grand staircase leads upward.\n"
                   "Doors lead to various rooms.";
        case LOC_CELLAR:
            return "You are in a damp cellar. Stone walls surround you and the air is cold.\n"
                   "A passage leads deeper underground.";
        case LOC_LABORATORY:
            return "You are in an old laboratory. Dusty bottles and strange apparatus fill\n"
                   "the shelves. A parchment lies on the table.";
        case LOC_CAVERN_OF_JEWELS:
            return "You have entered a dimly-lit cavern, with multi-coloured jewels\n"
                   "embedded in the walls. The colouring of the jewels emit a soft\n"
                   "radiance, playing on the varied shapes of rock walls to create\n"
                   "animated silhouettes throughout the cavern. The large quantity of\n"
                   "precious jewels, in all their varied shapes and sizes, make up a\n"
                   "large and priceless treasure; fit for all the kings through the ages!";
        default:
            return "You are in an unknown location.";
    }
}

/* Initialize game */
void simple_game_init(void) {
    g_simple_game.current_location = LOC_UNDERGROUND_TUNNEL;
    g_simple_game.has_treasure = 0;
    g_simple_game.has_potion = 0;
    g_simple_game.has_lamp = 0;
    g_simple_game.has_shovel = 0;
    g_simple_game.game_won = 0;
}

/* Handle look command */
void simple_game_look(void) {
    const char* desc = get_location_description(g_simple_game.current_location);
    printf("%s\n", desc);
    fflush(stdout);
}

/* Handle movement */
int simple_game_move(const char* direction) {
    GameLocation old_loc = g_simple_game.current_location;
    
    /* Simple linear progression for demo */
    if (strcmp(direction, "up") == 0 && old_loc == LOC_UNDERGROUND_TUNNEL) {
        g_simple_game.current_location = LOC_DARK_FOREST;
        return 1;
    }
    else if (strcmp(direction, "southeast") == 0 && old_loc == LOC_DARK_FOREST) {
        g_simple_game.current_location = LOC_DIRT_ROAD;
        return 1;
    }
    else if (strcmp(direction, "southwest") == 0 && old_loc == LOC_DIRT_ROAD) {
        g_simple_game.current_location = LOC_RECESSED_ENTRANCE;
        return 1;
    }
    else if (strcmp(direction, "east") == 0 && old_loc == LOC_RECESSED_ENTRANCE) {
        g_simple_game.current_location = LOC_GUARD_SHACK;
        return 1;
    }
    else if (strcmp(direction, "south") == 0 && old_loc == LOC_GUARD_SHACK) {
        g_simple_game.current_location = LOC_MANSION_FRONT;
        return 1;
    }
    else if (strcmp(direction, "north") == 0 && old_loc == LOC_MANSION_FRONT) {
        g_simple_game.current_location = LOC_MANSION_ENTRANCE;
        return 1;
    }
    else if (strcmp(direction, "down") == 0 && old_loc == LOC_MANSION_ENTRANCE) {
        g_simple_game.current_location = LOC_CELLAR;
        return 1;
    }
    else if (strcmp(direction, "north") == 0 && old_loc == LOC_CELLAR) {
        g_simple_game.current_location = LOC_LABORATORY;
        return 1;
    }
    else if (strcmp(direction, "down") == 0 && old_loc == LOC_LABORATORY && g_simple_game.has_potion) {
        g_simple_game.current_location = LOC_CAVERN_OF_JEWELS;
        return 1;
    }
    
    /* Allow reverse directions */
    if (strcmp(direction, "down") == 0 && old_loc == LOC_DARK_FOREST) {
        g_simple_game.current_location = LOC_UNDERGROUND_TUNNEL;
        return 1;
    }
    
    printf("You can't go that way.\n");
    return 0;
}

/* Handle inventory */
void simple_game_inventory(void) {
    printf("You are carrying:\n");
    if (g_simple_game.has_lamp) printf("  A brass lamp\n");
    if (g_simple_game.has_shovel) printf("  A shovel\n");
    if (g_simple_game.has_potion) printf("  A magic potion\n");
    if (g_simple_game.has_treasure) printf("  Ancient treasure!\n");
    if (!g_simple_game.has_lamp && !g_simple_game.has_shovel && 
        !g_simple_game.has_potion && !g_simple_game.has_treasure) {
        printf("  Nothing\n");
    }
    fflush(stdout);
}

/* Handle take command */
void simple_game_take(const char* item) {
    if (strstr(item, "lamp") && g_simple_game.current_location == LOC_GUARD_SHACK) {
        g_simple_game.has_lamp = 1;
        printf("Taken.\n");
    }
    else if (strstr(item, "shovel") && g_simple_game.current_location == LOC_GUARD_SHACK) {
        g_simple_game.has_shovel = 1;
        printf("Taken.\n");
    }
    else if (strstr(item, "potion") && g_simple_game.current_location == LOC_LABORATORY) {
        g_simple_game.has_potion = 1;
        printf("You take the magic potion. It glows with an eerie light.\n");
    }
    else if (strstr(item, "treasure") && g_simple_game.current_location == LOC_CAVERN_OF_JEWELS) {
        g_simple_game.has_treasure = 1;
        g_simple_game.game_won = 1;
        printf("\nYou reach for the treasure...\n\n");
        printf("A shimmering glow appears, hanging in the centre of the cavern.\n");
        printf("'At last', the words are exclaimed in your mind.\n");
        printf("'You have solved the mysteries of my treasure.'\n\n");
        printf("From henceforth you shall guard the treasure, protecting it from\n");
        printf("fortune hunters around the world.\n\n");
        printf("A cackling laugh echoes in your mind, as the glow fades into the shadows...\n\n");
        printf("***** To be continued *****\n\n");
        printf("THE CYCLE CONTINUES: You have become the new guardian of the treasure,\n");
        printf("replacing William's ghost. Your spirit will now haunt these halls forever...\n\n");
        printf("\n========================================\n");
        printf("    CONGRATULATIONS!\n");
        printf("  You have completed SKULLDUGGERY!\n");
        printf("========================================\n\n");
    }
    else {
        printf("You don't see that here.\n");
    }
    fflush(stdout);
}

/* Check if game is won */
int simple_game_is_won(void) {
    return g_simple_game.game_won;
}

/* Get current location name for debugging */
const char* simple_game_get_location_name(void) {
    switch(g_simple_game.current_location) {
        case LOC_UNDERGROUND_TUNNEL: return "Underground Tunnel";
        case LOC_DARK_FOREST: return "Dark Forest";
        case LOC_DIRT_ROAD: return "Dirt Road";
        case LOC_RECESSED_ENTRANCE: return "Recessed Entrance";
        case LOC_GUARD_SHACK: return "Guard Shack";
        case LOC_MANSION_FRONT: return "Front of Mansion";
        case LOC_MANSION_ENTRANCE: return "Mansion Entrance";
        case LOC_CELLAR: return "Cellar";
        case LOC_LABORATORY: return "Laboratory";
        case LOC_CAVERN_OF_JEWELS: return "Cavern of Jewels";
        default: return "Unknown";
    }
}
