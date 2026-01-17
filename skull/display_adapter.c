/* Display Adapter Implementation
 * Routes display calls to appropriate output
 */

#include "display_adapter.h"
#include <stdio.h>
#include <string.h>

/* Get current display mode */
DisplayMode GetDisplayMode(void) {
    #ifdef _WIN32
    if (IsWindowMode()) {
        return DISPLAY_MODE_WINDOW;
    }
    #endif
    return DISPLAY_MODE_CONSOLE;
}

/* Print text */
void DisplayPrint(const char *text) {
    if (!text) return;
    
    #ifdef _WIN32
    if (IsWindowMode()) {
        WindowPrintText(text);
        return;
    }
    #endif
    
    /* Console mode */
    printf("%s", text);
    fflush(stdout);
}

/* Print text at position */
void DisplayPrintAt(int x, int y, const char *text) {
    if (!text) return;
    
    #ifdef _WIN32
    if (IsWindowMode()) {
        WindowPrintTextAt(x, y, text);
        return;
    }
    #endif
    
    /* Console mode - just print (no positioning in console) */
    printf("%s", text);
    fflush(stdout);
}

/* Clear screen */
void DisplayClear(void) {
    #ifdef _WIN32
    if (IsWindowMode()) {
        WindowClearScreen();
        return;
    }
    #endif
    
    /* Console mode - use ANSI escape codes or system call */
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

/* Refresh display */
void DisplayRefresh(void) {
    #ifdef _WIN32
    if (IsWindowMode()) {
        WindowRefresh();
        return;
    }
    #endif
    
    /* Console mode - just flush */
    fflush(stdout);
}

/* Set cursor position */
void DisplaySetCursor(int x, int y) {
    #ifdef _WIN32
    if (IsWindowMode()) {
        WindowSetCursorPosition(x, y);
        return;
    }
    #endif
    
    /* Console mode - no-op for now */
    /* Could use ANSI escape codes: printf("\033[%d;%dH", y+1, x+1); */
}

/* Get input */
bool DisplayGetInput(char *buffer, int maxLength) {
    if (!buffer || maxLength <= 0) return false;
    
    #ifdef _WIN32
    if (IsWindowMode()) {
        return WindowGetInput(buffer, maxLength);
    }
    #endif
    
    /* Console mode */
    if (fgets(buffer, maxLength, stdin)) {
        /* Remove newline */
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        return true;
    }
    
    return false;
}

/* Check if input available */
bool DisplayHasInput(void) {
    #ifdef _WIN32
    if (IsWindowMode()) {
        return WindowHasInput();
    }
    #endif
    
    /* Console mode - always return false, use blocking input */
    return false;
}
