/* Display Adapter - Unified display interface
 * Routes display calls to either console or window
 */

#ifndef DISPLAY_ADAPTER_H
#define DISPLAY_ADAPTER_H

#include <stdbool.h>

#ifdef _WIN32
#include "game_window.h"
#endif

/* Display mode */
typedef enum {
    DISPLAY_MODE_CONSOLE,
    DISPLAY_MODE_WINDOW
} DisplayMode;

/* Get current display mode */
DisplayMode GetDisplayMode(void);

/* Unified display functions */
void DisplayPrint(const char *text);
void DisplayPrintAt(int x, int y, const char *text);
void DisplayClear(void);
void DisplayRefresh(void);
void DisplaySetCursor(int x, int y);

/* Input functions */
bool DisplayGetInput(char *buffer, int maxLength);
bool DisplayHasInput(void);

#endif /* DISPLAY_ADAPTER_H */
