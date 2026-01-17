/* Game Window Implementation - GUI Window for Windows
 * Provides graphical window with text display and input
 */

#ifdef _WIN32

#include "game_window.h"
#include "dos_compat.h"
#include <stdio.h>
#include <string.h>

/* Global window instance */
GameWindow *g_gameWindow = NULL;

/* Forward declarations */
static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
static void DrawTextBuffer(GameWindow *window);
static void ProcessKeyPress(GameWindow *window, WPARAM wParam);

/* Initialize game window */
bool InitGameWindow(HINSTANCE hInstance) {
    /* Allocate window structure */
    g_gameWindow = (GameWindow *)calloc(1, sizeof(GameWindow));
    if (!g_gameWindow) {
        return false;
    }
    
    /* Initialize window state */
    g_gameWindow->cursorX = 0;
    g_gameWindow->cursorY = 0;
    g_gameWindow->inputLength = 0;
    g_gameWindow->needsRedraw = true;
    g_gameWindow->textColor = GAME_COLOR_TEXT;
    memset(g_gameWindow->textBuffer, ' ', TEXT_BUFFER_SIZE);
    
    /* Register window class */
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = WINDOW_CLASS_NAME;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    
    if (!RegisterClassEx(&wc)) {
        free(g_gameWindow);
        g_gameWindow = NULL;
        return false;
    }
    
    /* Calculate window size with borders */
    RECT rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
    
    /* Create window */
    g_gameWindow->hwnd = CreateWindowEx(
        0,
        WINDOW_CLASS_NAME,
        WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    if (!g_gameWindow->hwnd) {
        free(g_gameWindow);
        g_gameWindow = NULL;
        return false;
    }
    
    /* Get device context */
    g_gameWindow->hdc = GetDC(g_gameWindow->hwnd);
    
    /* Create memory DC for double buffering */
    g_gameWindow->memDC = CreateCompatibleDC(g_gameWindow->hdc);
    g_gameWindow->memBitmap = CreateCompatibleBitmap(g_gameWindow->hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
    SelectObject(g_gameWindow->memDC, g_gameWindow->memBitmap);
    
    /* Create font */
    g_gameWindow->font = CreateFont(
        CHAR_HEIGHT, CHAR_WIDTH, 0, 0,
        FW_NORMAL, FALSE, FALSE, FALSE,
        ANSI_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        FIXED_PITCH | FF_MODERN,
        "Consolas"
    );
    
    SelectObject(g_gameWindow->memDC, g_gameWindow->font);
    SetBkMode(g_gameWindow->memDC, TRANSPARENT);
    
    return true;
}

/* Cleanup game window */
void CleanupGameWindow(void) {
    if (g_gameWindow) {
        if (g_gameWindow->font) DeleteObject(g_gameWindow->font);
        if (g_gameWindow->memBitmap) DeleteObject(g_gameWindow->memBitmap);
        if (g_gameWindow->memDC) DeleteDC(g_gameWindow->memDC);
        if (g_gameWindow->hdc) ReleaseDC(g_gameWindow->hwnd, g_gameWindow->hdc);
        if (g_gameWindow->hwnd) DestroyWindow(g_gameWindow->hwnd);
        free(g_gameWindow);
        g_gameWindow = NULL;
    }
}

/* Show game window */
void ShowGameWindow(void) {
    if (g_gameWindow && g_gameWindow->hwnd) {
        ShowWindow(g_gameWindow->hwnd, SW_SHOW);
        UpdateWindow(g_gameWindow->hwnd);
    }
}

/* Hide game window */
void HideGameWindow(void) {
    if (g_gameWindow && g_gameWindow->hwnd) {
        ShowWindow(g_gameWindow->hwnd, SW_HIDE);
    }
}

/* Check if in window mode */
bool IsWindowMode(void) {
    return (g_gameWindow != NULL);
}

/* Print text to window */
void WindowPrintText(const char *text) {
    if (!g_gameWindow || !text) return;
    
    while (*text) {
        if (*text == '\n') {
            /* Newline */
            g_gameWindow->cursorX = 0;
            g_gameWindow->cursorY++;
            if (g_gameWindow->cursorY >= TEXT_ROWS) {
                WindowScrollUp();
                g_gameWindow->cursorY = TEXT_ROWS - 1;
            }
        } else if (*text == '\r') {
            /* Carriage return */
            g_gameWindow->cursorX = 0;
        } else if (*text == '\t') {
            /* Tab */
            g_gameWindow->cursorX = (g_gameWindow->cursorX + 4) & ~3;
            if (g_gameWindow->cursorX >= TEXT_COLS) {
                g_gameWindow->cursorX = 0;
                g_gameWindow->cursorY++;
                if (g_gameWindow->cursorY >= TEXT_ROWS) {
                    WindowScrollUp();
                    g_gameWindow->cursorY = TEXT_ROWS - 1;
                }
            }
        } else {
            /* Regular character */
            int pos = g_gameWindow->cursorY * TEXT_COLS + g_gameWindow->cursorX;
            if (pos < TEXT_BUFFER_SIZE) {
                g_gameWindow->textBuffer[pos] = *text;
            }
            g_gameWindow->cursorX++;
            if (g_gameWindow->cursorX >= TEXT_COLS) {
                g_gameWindow->cursorX = 0;
                g_gameWindow->cursorY++;
                if (g_gameWindow->cursorY >= TEXT_ROWS) {
                    WindowScrollUp();
                    g_gameWindow->cursorY = TEXT_ROWS - 1;
                }
            }
        }
        text++;
    }
    
    g_gameWindow->needsRedraw = true;
    WindowRefresh();
}

/* Print text at specific position */
void WindowPrintTextAt(int x, int y, const char *text) {
    if (!g_gameWindow || !text) return;
    if (x < 0 || x >= TEXT_COLS || y < 0 || y >= TEXT_ROWS) return;
    
    int pos = y * TEXT_COLS + x;
    while (*text && pos < TEXT_BUFFER_SIZE && (pos % TEXT_COLS) < TEXT_COLS) {
        if (*text != '\n' && *text != '\r') {
            g_gameWindow->textBuffer[pos] = *text;
            pos++;
        }
        text++;
    }
    
    g_gameWindow->needsRedraw = true;
    WindowRefresh();
}

/* Clear screen */
void WindowClearScreen(void) {
    if (!g_gameWindow) return;
    
    memset(g_gameWindow->textBuffer, ' ', TEXT_BUFFER_SIZE);
    g_gameWindow->cursorX = 0;
    g_gameWindow->cursorY = 0;
    g_gameWindow->needsRedraw = true;
    WindowRefresh();
}

/* Set text color */
void WindowSetTextColor(COLORREF color) {
    if (g_gameWindow) {
        g_gameWindow->textColor = color;
    }
}

/* Scroll text up one line */
void WindowScrollUp(void) {
    if (!g_gameWindow) return;
    
    /* Move all lines up */
    memmove(g_gameWindow->textBuffer, 
            g_gameWindow->textBuffer + TEXT_COLS,
            TEXT_BUFFER_SIZE - TEXT_COLS);
    
    /* Clear bottom line */
    memset(g_gameWindow->textBuffer + TEXT_BUFFER_SIZE - TEXT_COLS, ' ', TEXT_COLS);
    
    g_gameWindow->needsRedraw = true;
}

/* Refresh window display */
void WindowRefresh(void) {
    if (!g_gameWindow || !g_gameWindow->needsRedraw) return;
    
    DrawTextBuffer(g_gameWindow);
    g_gameWindow->needsRedraw = false;
    
    /* Force window update */
    InvalidateRect(g_gameWindow->hwnd, NULL, FALSE);
}

/* Set cursor position */
void WindowSetCursorPosition(int x, int y) {
    if (!g_gameWindow) return;
    
    if (x >= 0 && x < TEXT_COLS) g_gameWindow->cursorX = x;
    if (y >= 0 && y < TEXT_ROWS) g_gameWindow->cursorY = y;
}

/* Get cursor position */
void WindowGetCursorPosition(int *x, int *y) {
    if (!g_gameWindow) return;
    
    if (x) *x = g_gameWindow->cursorX;
    if (y) *y = g_gameWindow->cursorY;
}

/* Draw text buffer to window */
static void DrawTextBuffer(GameWindow *window) {
    if (!window || !window->memDC) return;
    
    /* Clear background */
    RECT rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    FillRect(window->memDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
    
    /* Set text color */
    SetTextColor(window->memDC, window->textColor);
    
    /* Draw each line of text */
    for (int y = 0; y < TEXT_ROWS; y++) {
        char line[TEXT_COLS + 1];
        memcpy(line, window->textBuffer + y * TEXT_COLS, TEXT_COLS);
        line[TEXT_COLS] = '\0';
        
        /* Remove trailing spaces for cleaner display */
        int len = TEXT_COLS;
        while (len > 0 && line[len - 1] == ' ') len--;
        line[len] = '\0';
        
        if (len > 0) {
            TextOut(window->memDC, 5, y * CHAR_HEIGHT + 5, line, len);
        }
    }
    
    /* Draw cursor */
    int cursorPixelX = window->cursorX * CHAR_WIDTH + 5;
    int cursorPixelY = window->cursorY * CHAR_HEIGHT + 5;
    RECT cursorRect = {
        cursorPixelX,
        cursorPixelY + CHAR_HEIGHT - 2,
        cursorPixelX + CHAR_WIDTH,
        cursorPixelY + CHAR_HEIGHT
    };
    FillRect(window->memDC, &cursorRect, (HBRUSH)GetStockObject(WHITE_BRUSH));
}

/* Process key press */
static void ProcessKeyPress(GameWindow *window, WPARAM wParam) {
    if (!window) return;
    
    if (wParam == VK_RETURN) {
        /* Enter key - process input */
        window->inputBuffer[window->inputLength] = '\0';
        WindowPrintText("\n");
        /* Input will be retrieved by WindowGetInput() */
    } else if (wParam == VK_BACK) {
        /* Backspace */
        if (window->inputLength > 0) {
            window->inputLength--;
            /* Visual backspace */
            if (window->cursorX > 0) {
                window->cursorX--;
                int pos = window->cursorY * TEXT_COLS + window->cursorX;
                if (pos < TEXT_BUFFER_SIZE) {
                    window->textBuffer[pos] = ' ';
                }
                window->needsRedraw = true;
                WindowRefresh();
            }
        }
    }
}

/* Window procedure */
static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            if (g_gameWindow && g_gameWindow->memDC) {
                /* Copy from memory DC to window */
                BitBlt(hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
                       g_gameWindow->memDC, 0, 0, SRCCOPY);
            }
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_CHAR: {
            if (g_gameWindow && wParam >= 32 && wParam < 127) {
                /* Printable character */
                if (g_gameWindow->inputLength < 255) {
                    char ch = (char)wParam;
                    g_gameWindow->inputBuffer[g_gameWindow->inputLength++] = ch;
                    
                    /* Echo character */
                    char str[2] = {ch, '\0'};
                    WindowPrintText(str);
                }
            }
            return 0;
        }
        
        case WM_KEYDOWN: {
            ProcessKeyPress(g_gameWindow, wParam);
            return 0;
        }
        
        case WM_CLOSE: {
            PostQuitMessage(0);
            return 0;
        }
        
        case WM_DESTROY: {
            PostQuitMessage(0);
            return 0;
        }
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

/* Get input from window */
bool WindowGetInput(char *buffer, int maxLength) {
    if (!g_gameWindow || !buffer || maxLength <= 0) return false;
    
    /* Check if we have input (Enter was pressed) */
    if (g_gameWindow->inputLength > 0 && 
        g_gameWindow->inputBuffer[g_gameWindow->inputLength - 1] == '\0') {
        
        int len = g_gameWindow->inputLength - 1;
        if (len >= maxLength) len = maxLength - 1;
        
        memcpy(buffer, g_gameWindow->inputBuffer, len);
        buffer[len] = '\0';
        
        /* Reset input buffer */
        g_gameWindow->inputLength = 0;
        
        return true;
    }
    
    return false;
}

/* Check if input is available */
bool WindowHasInput(void) {
    if (!g_gameWindow) return false;
    
    return (g_gameWindow->inputLength > 0 && 
            g_gameWindow->inputBuffer[g_gameWindow->inputLength - 1] == '\0');
}

/* Message loop */
int WindowMessageLoop(void) {
    MSG msg;
    
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}

#endif /* _WIN32 */
