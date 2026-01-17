/* Game Window Header - GUI Window for Windows
 * Provides graphical window option for playing the game
 */

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#ifdef _WIN32
#include <windows.h>
#include <stdbool.h>

/* Window configuration */
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Skull Game - Windows Edition"
#define WINDOW_CLASS_NAME "SkullGameWindow"

/* Text display configuration */
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 16
#define TEXT_COLS 100
#define TEXT_ROWS 37
#define TEXT_BUFFER_SIZE (TEXT_COLS * TEXT_ROWS)

/* Colors (RGB) - prefixed with GAME_ to avoid Windows API conflicts */
#define GAME_COLOR_BACKGROUND RGB(0, 0, 0)        /* Black */
#define GAME_COLOR_TEXT RGB(192, 192, 192)        /* Light gray */
#define GAME_COLOR_HIGHLIGHT RGB(255, 255, 0)     /* Yellow */
#define GAME_COLOR_ERROR RGB(255, 0, 0)           /* Red */
#define GAME_COLOR_SUCCESS RGB(0, 255, 0)         /* Green */

/* Window state structure */
typedef struct {
    HWND hwnd;                              /* Window handle */
    HDC hdc;                                /* Device context */
    HDC memDC;                              /* Memory DC for double buffering */
    HBITMAP memBitmap;                      /* Bitmap for double buffering */
    HFONT font;                             /* Font for text */
    char textBuffer[TEXT_BUFFER_SIZE];      /* Text display buffer */
    int cursorX;                            /* Cursor X position (column) */
    int cursorY;                            /* Cursor Y position (row) */
    char inputBuffer[256];                  /* Input line buffer */
    int inputLength;                        /* Current input length */
    bool needsRedraw;                       /* Flag for redraw */
    COLORREF textColor;                     /* Current text color */
} GameWindow;

/* Global window instance */
extern GameWindow *g_gameWindow;

/* Window management functions */
bool InitGameWindow(HINSTANCE hInstance);
void CleanupGameWindow(void);
void ShowGameWindow(void);
void HideGameWindow(void);
bool IsWindowMode(void);

/* Display functions */
void WindowPrintText(const char *text);
void WindowPrintTextAt(int x, int y, const char *text);
void WindowClearScreen(void);
void WindowSetTextColor(COLORREF color);
void WindowScrollUp(void);
void WindowRefresh(void);

/* Input functions */
bool WindowGetInput(char *buffer, int maxLength);
bool WindowHasInput(void);

/* Utility functions */
void WindowSetCursorPosition(int x, int y);
void WindowGetCursorPosition(int *x, int *y);

/* Message loop */
int WindowMessageLoop(void);

#endif /* _WIN32 */

#endif /* GAME_WINDOW_H */
