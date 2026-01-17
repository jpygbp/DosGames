/* Main entry point for Skull Game - Windows GUI Version
 * Supports both console mode and windowed mode
 */

#include "dos_compat.h"
#include "game_window.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <excpt.h>
#endif

/* Forward declaration */
void entry(void);

/* Command line options */
static bool g_useWindowMode = false;
static bool g_useConsoleMode = false;

/* Parse command line arguments */
static void ParseCommandLine(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--window") == 0 || strcmp(argv[i], "-w") == 0) {
            g_useWindowMode = true;
        } else if (strcmp(argv[i], "--console") == 0 || strcmp(argv[i], "-c") == 0) {
            g_useConsoleMode = true;
        } else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            printf("Skull Game - 64-bit Windows Port\n");
            printf("Usage: skull [options]\n");
            printf("Options:\n");
            printf("  --window,  -w    Launch in windowed mode (GUI)\n");
            printf("  --console, -c    Launch in console mode (default)\n");
            printf("  --help,    -h    Show this help message\n");
            exit(0);
        }
    }
    
    /* If neither specified, ask user */
    if (!g_useWindowMode && !g_useConsoleMode) {
        printf("Skull Game - 64-bit Windows Port\n");
        printf("==================================\n\n");
        printf("Choose display mode:\n");
        printf("  1. Console Mode (text in command window)\n");
        printf("  2. Window Mode (graphical window)\n\n");
        printf("Enter choice (1 or 2): ");
        fflush(stdout);
        
        char choice[10];
        if (fgets(choice, sizeof(choice), stdin)) {
            if (choice[0] == '2') {
                g_useWindowMode = true;
            } else {
                g_useConsoleMode = true;
            }
        } else {
            /* Default to console */
            g_useConsoleMode = true;
        }
    }
}

/* Console mode entry point */
int ConsoleMain(int argc, char* argv[]) {
    /* Set default log level */
    const char* log_level_str = getenv("SKULL_LOG_LEVEL");
    if (log_level_str != NULL) {
        int level = atoi(log_level_str);
        if (level >= LOG_LEVEL_NONE && level <= LOG_LEVEL_VERBOSE) {
            log_set_level((LogLevel)level);
        }
    } else {
        log_set_level(LOG_LEVEL_INFO);
    }
    
    fprintf(stderr, "Skull Game - Console Mode\n");
    fprintf(stderr, "==========================\n");
    
    log_info("Skull Game - Console Mode");
    log_info("==========================");
    
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
    
    fprintf(stderr, "Log file: skull_game.log\n");
    fflush(stderr);
    
    /* Call the original entry point */
    log_info("Starting game...");
    fprintf(stderr, "Starting game...\n");
    fflush(stderr);
    
    entry();
    
    log_info("Game exited normally");
    fprintf(stderr, "Game exited normally\n");
    return 0;
}

/* Window mode entry point */
#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int nCmdShow) {
    /* Parse command line */
    int argc = __argc;
    char **argv = __argv;
    ParseCommandLine(argc, argv);
    
    /* If console mode requested, redirect to console main */
    if (g_useConsoleMode) {
        /* Allocate console for output */
        AllocConsole();
        FILE *fDummy;
        freopen_s(&fDummy, "CONOUT$", "w", stdout);
        freopen_s(&fDummy, "CONOUT$", "w", stderr);
        freopen_s(&fDummy, "CONIN$", "r", stdin);
        
        return ConsoleMain(argc, argv);
    }
    
    /* Window mode */
    log_set_level(LOG_LEVEL_INFO);
    
    /* Initialize game window */
    if (!InitGameWindow(hInstance)) {
        MessageBox(NULL, "Failed to create game window!", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    /* Initialize game state */
    InitGameState();
    
    if (get_last_error() != SKULL_ERROR_NONE) {
        MessageBox(NULL, "Failed to initialize game state!", "Error", MB_OK | MB_ICONERROR);
        CleanupGameWindow();
        return 1;
    }
    
    atexit(CleanupGameState);
    atexit(CleanupGameWindow);
    
    /* Show window */
    ShowGameWindow();
    
    /* Display welcome message */
    WindowClearScreen();
    WindowSetTextColor(GAME_COLOR_HIGHLIGHT);
    WindowPrintText("SKULL GAME - Windows Edition\n");
    WindowSetTextColor(GAME_COLOR_TEXT);
    WindowPrintText("============================\n\n");
    WindowPrintText("Welcome to Skull Game!\n\n");
    WindowPrintText("Loading game...\n");
    WindowRefresh();
    
    /* Start game in separate thread to keep window responsive */
    /* For now, just show the window and message loop */
    /* TODO: Run game logic in background thread */
    
    /* Message loop */
    return WindowMessageLoop();
}
#endif

/* Standard main for console mode */
int main(int argc, char* argv[]) {
    ParseCommandLine(argc, argv);
    
    if (g_useWindowMode) {
        #ifdef _WIN32
        /* Launch window mode */
        return WinMain(GetModuleHandle(NULL), NULL, GetCommandLine(), SW_SHOW);
        #else
        fprintf(stderr, "Window mode not supported on this platform\n");
        return 1;
        #endif
    }
    
    /* Console mode */
    return ConsoleMain(argc, argv);
}
