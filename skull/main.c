/* Main entry point for Skull Game - 64-bit Windows port */

#include "dos_compat.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <excpt.h>
#endif

/* Forward declaration */
void entry(void);

int main(int argc, char* argv[]) {
    /* Set default log level - can be overridden by environment variable */
    const char* log_level_str = getenv("SKULL_LOG_LEVEL");
    if (log_level_str != NULL) {
        int level = atoi(log_level_str);
        if (level >= LOG_LEVEL_NONE && level <= LOG_LEVEL_VERBOSE) {
            log_set_level((LogLevel)level);
        }
    } else {
        /* Default to INFO level for better debugging */
        log_set_level(LOG_LEVEL_INFO);
    }
    
    /* Also output to stderr for immediate visibility */
    fprintf(stderr, "Skull Game - 64-bit Windows Port\n");
    fprintf(stderr, "==================================\n");
    
    log_info("Skull Game - 64-bit Windows Port");
    log_info("==================================");
    
    /* Initialize game state */
    log_info("Initializing game...");
    fprintf(stderr, "Initializing game...\n");
    InitGameState();
    
    if (get_last_error() != SKULL_ERROR_NONE) {
        log_error("Failed to initialize game state");
        fprintf(stderr, "ERROR: Failed to initialize game state\n");
        return 1;
    }
    
    atexit(CleanupGameState);
    
    /* Initialize log file early */
    fprintf(stderr, "Log file: skull_game.log\n");
    fflush(stderr);
    
    /* Call the original entry point */
    log_info("Starting game...");
    fprintf(stderr, "Starting game...\n");
    fflush(stderr);  /* Ensure output is flushed */
    
    /* Call entry() - this runs the full game including initialization and main loop */
    /* Note: entry() contains DOS-specific initialization code that may need additional work */
    entry();
    
    log_info("Game exited normally");
    fprintf(stderr, "Game exited normally\n");
    return 0;
}

