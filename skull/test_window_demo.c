/* Simple Window Demo - Test the window system
 * This is a standalone demo to verify the window works
 */

#ifdef _WIN32

#include "game_window.h"
#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int nCmdShow) {
    /* Initialize window */
    if (!InitGameWindow(hInstance)) {
        MessageBox(NULL, "Failed to create window!", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    /* Show window */
    ShowGameWindow();
    
    /* Display demo content */
    WindowClearScreen();
    
    WindowSetTextColor(GAME_COLOR_HIGHLIGHT);
    WindowPrintText("SKULL GAME - Window Demo\n");
    WindowSetTextColor(GAME_COLOR_TEXT);
    WindowPrintText("========================\n\n");
    
    WindowPrintText("This is a demonstration of the window system.\n\n");
    
    WindowSetTextColor(GAME_COLOR_SUCCESS);
    WindowPrintText("Features:\n");
    WindowSetTextColor(GAME_COLOR_TEXT);
    WindowPrintText("  - 800x600 pixel window\n");
    WindowPrintText("  - 100 columns x 37 rows text\n");
    WindowPrintText("  - Consolas fixed-width font\n");
    WindowPrintText("  - Double-buffered rendering\n");
    WindowPrintText("  - Full keyboard support\n");
    WindowPrintText("  - Auto-scrolling text\n\n");
    
    WindowSetTextColor(GAME_COLOR_HIGHLIGHT);
    WindowPrintText("Try typing something!\n");
    WindowSetTextColor(GAME_COLOR_TEXT);
    WindowPrintText("(Press ESC or close window to exit)\n\n");
    
    /* Demonstrate scrolling */
    WindowPrintText("Scrolling test:\n");
    for (int i = 1; i <= 20; i++) {
        char line[100];
        sprintf(line, "Line %d - This is a test of the scrolling system.\n", i);
        WindowPrintText(line);
        Sleep(100); /* Small delay to show scrolling */
    }
    
    WindowSetTextColor(GAME_COLOR_SUCCESS);
    WindowPrintText("\nWindow system is working correctly!\n");
    WindowSetTextColor(GAME_COLOR_TEXT);
    
    WindowRefresh();
    
    /* Message loop */
    int result = WindowMessageLoop();
    
    /* Cleanup */
    CleanupGameWindow();
    
    return result;
}

#else

int main(void) {
    printf("This demo requires Windows.\n");
    return 1;
}

#endif
