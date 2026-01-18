/* Simple Game Engine Header */
#ifndef SIMPLE_GAME_ENGINE_H
#define SIMPLE_GAME_ENGINE_H

/* ============================================
 * SIMPLE GAME ENGINE CONTROL
 * ============================================
 * 
 * Set to 1: Simple Engine intercepts commands (DEFAULT - RECOMMENDED)
 * Set to 0: Simple Engine disabled, only Normal Engine runs
 * 
 * Change this to test the Normal (DOS) Engine directly:
 */
#define ENABLE_SIMPLE_ENGINE 1

/* Initialize the simple game engine */
void simple_game_init(void);

/* Handle look command */
void simple_game_look(void);

/* Handle movement - returns 1 if successful, 0 if blocked */
int simple_game_move(const char* direction);

/* Handle inventory display */
void simple_game_inventory(void);

/* Handle take command */
void simple_game_take(const char* item);

/* Check if game is won */
int simple_game_is_won(void);

/* Get current location name (for debugging) */
const char* simple_game_get_location_name(void);

#endif /* SIMPLE_GAME_ENGINE_H */
