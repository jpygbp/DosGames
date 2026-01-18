/* DOS Compatibility Layer Implementation */

/* Suppress warnings for deprecated functions and unavoidable porting issues */
#pragma warning(push)
#pragma warning(disable: 4996)  /* GetVersionExA deprecated */
#pragma warning(disable: 4013) /* Function undefined - expected from decompiled code */
#pragma warning(disable: 4142) /* Benign redefinition - expected from decompiled code */
#pragma warning(disable: 4101) /* Unreferenced local variable - from decompiled code */
#pragma warning(disable: 4312) /* Pointer size conversion - expected when porting 16-bit to 64-bit */
#pragma warning(disable: 4311) /* Pointer truncation - expected when porting 16-bit to 64-bit */
#pragma warning(disable: 4047) /* Function parameter type mismatch - from decompiled code */
#pragma warning(disable: 4024) /* Function parameter type mismatch - from decompiled code */
#pragma warning(disable: 4018) /* Signed/unsigned mismatch - from decompiled code */
#pragma warning(disable: 4146) /* Unary minus on unsigned - from decompiled code */
#pragma warning(disable: 4554) /* Operator precedence - from decompiled code */
#pragma warning(disable: 4700) /* Uninitialized variable - from decompiled code */
#pragma warning(disable: 4133) /* Incompatible types - from decompiled code */
#pragma warning(disable: 4723) /* Potential divide by 0 - may be intentional */

#include "dos_compat.h"
#include "game_constants.h"
#include <io.h>
#include <fcntl.h>
/* Windows 11 Compatibility: conio.h no longer needed - using ReadConsoleInput instead of _getch()/_kbhit() */
#ifdef _WIN32
/* Windows-specific includes are in dos_compat.h via windows.h */
#else
#include <conio.h> /* Only needed for non-Windows platforms */
#endif
#include <stdarg.h>
#include <limits.h>
#include <string.h>

/* Global game state */
GameState* g_gameState = NULL;

/* Piped input detection - set once at startup */
static BOOL g_stdin_is_piped = FALSE;
static BOOL g_stdin_checked = FALSE;

/* File opening state - tracks which file to open next in game_init sequence */
static int g_file_open_index = 0;

/* Reset file open index - useful for test initialization */
void reset_file_open_index(void) {
    g_file_open_index = 0;
}

/* Check if stdin is piped/redirected (not a console) */
static BOOL is_stdin_piped(void) {
    if (g_stdin_checked) {
        return g_stdin_is_piped;
    }
    
    g_stdin_checked = TRUE;
    
    #ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD dwMode = 0;
    
    /* If GetConsoleMode fails, stdin is redirected/piped */
    g_stdin_is_piped = (hStdin == INVALID_HANDLE_VALUE || !GetConsoleMode(hStdin, &dwMode));
    
    if (g_stdin_is_piped) {
        log_info("is_stdin_piped: Detected piped/redirected stdin");
        fprintf(stderr, "INFO: Detected piped/redirected stdin - skipping console-specific initialization\n");
        fflush(stderr);
    } else {
        log_info("is_stdin_piped: Detected console stdin");
    }
    #else
    /* On non-Windows, assume console */
    g_stdin_is_piped = FALSE;
    #endif
    
    return g_stdin_is_piped;
}

/* File names in the order they're opened during game_init */
static const char* g_game_files[] = {
    "SKULL.M",   /* First file - main data */
    "SKULL.X",   /* Second file */
    "SKULL.V",   /* Third file */
    "SKULL.T",   /* Fourth file */
    "SKULL.MO",  /* Fifth file */
    "SKULL.MM",  /* Sixth file */
    NULL
};

/* Track the last opened file handle for file_read_word_wrapper */
static HANDLE g_current_file_handle = INVALID_HANDLE_VALUE;

/* Forward declaration */
static char* convert_to_long_path(const char* filename);

/* Windows File Handle Management - Maps DOS file handles (0-9) to Windows HANDLEs */
#define MAX_DOS_FILE_HANDLES 10
static HANDLE g_dos_file_handles[MAX_DOS_FILE_HANDLES] = { 
    INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE,
    INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE, INVALID_HANDLE_VALUE 
};

/* Get Windows HANDLE for DOS file handle (0-9) */
static HANDLE get_windows_file_handle(uint dos_handle) {
    if (dos_handle >= MAX_DOS_FILE_HANDLES) {
        return INVALID_HANDLE_VALUE;
    }
    return g_dos_file_handles[dos_handle];
}

/* Set Windows HANDLE for DOS file handle (0-9) */
static void set_windows_file_handle(uint dos_handle, HANDLE win_handle) {
    if (dos_handle < MAX_DOS_FILE_HANDLES) {
        /* Close old handle if it exists */
        if (g_dos_file_handles[dos_handle] != INVALID_HANDLE_VALUE && 
            g_dos_file_handles[dos_handle] != win_handle) {
            CloseHandle(g_dos_file_handles[dos_handle]);
        }
        g_dos_file_handles[dos_handle] = win_handle;
    }
}

/* Free a DOS file handle slot */
static void free_dos_file_handle(uint dos_handle) {
    if (dos_handle < MAX_DOS_FILE_HANDLES) {
        if (g_dos_file_handles[dos_handle] != INVALID_HANDLE_VALUE) {
            CloseHandle(g_dos_file_handles[dos_handle]);
            g_dos_file_handles[dos_handle] = INVALID_HANDLE_VALUE;
        }
    }
}

/* Close all DOS file handles */
void close_all_dos_file_handles(void) {
    for (uint i = 0; i < MAX_DOS_FILE_HANDLES; i++) {
        if (g_dos_file_handles[i] != INVALID_HANDLE_VALUE) {
            CloseHandle(g_dos_file_handles[i]);
            g_dos_file_handles[i] = INVALID_HANDLE_VALUE;
        }
    }
}

/* Read filename from memory pool at given offset */
static const char* read_filename_from_memory(uint32_t filename_offset) {
    if (g_gameState == NULL || g_gameState->memory_pool == NULL) {
        return NULL;
    }
    
    if (filename_offset >= g_gameState->memory_pool_size) {
        log_warning("read_filename_from_memory: filename_offset (0x%x) out of bounds", filename_offset);
        return NULL;
    }
    
    /* Filename is a null-terminated string starting at the offset */
    /* Maximum filename length is 260 characters (MAX_PATH) */
    static char filename_buffer[MAX_PATH + 1];
    uint32_t max_len = (uint32_t)(g_gameState->memory_pool_size - filename_offset);
    if (max_len > sizeof(filename_buffer) - 1) {
        max_len = sizeof(filename_buffer) - 1;
    }
    
    /* Copy filename string from memory pool */
    const char* src = (const char*)(g_gameState->memory_pool + filename_offset);
    size_t len = 0;
    while (len < max_len && src[len] != '\0') {
        filename_buffer[len] = src[len];
        len++;
    }
    filename_buffer[len] = '\0';
    
    if (len == 0) {
        log_warning("read_filename_from_memory: Empty filename at offset 0x%x", filename_offset);
        return NULL;
    }
    
    return filename_buffer;
}

/* Windows File Emulation: Open file and assign to DOS file handle */
/* Returns DOS file handle (0-9) or -1 on error */
int win32_emulate_file_open(uint32_t filename_offset, uint mode, uint access) {
    if (g_gameState == NULL || g_gameState->memory_pool == NULL) {
        log_error("win32_emulate_file_open: Game state not initialized");
        return -1;
    }
    
    /* Read filename from memory */
    const char* filename = read_filename_from_memory(filename_offset);
    if (filename == NULL) {
        log_error("win32_emulate_file_open: Failed to read filename from offset 0x%x", filename_offset);
        return -1;
    }
    
    /* Find free DOS file handle slot (0-9) */
    uint dos_handle = 0;
    for (; dos_handle < MAX_DOS_FILE_HANDLES; dos_handle++) {
        if (g_dos_file_handles[dos_handle] == INVALID_HANDLE_VALUE) {
            break;
        }
    }
    if (dos_handle >= MAX_DOS_FILE_HANDLES) {
        log_error("win32_emulate_file_open: No free file handle slots available");
        return -1;
    }
    
    /* Convert DOS mode/access to Windows flags */
    DWORD dwDesiredAccess = 0;
    DWORD dwCreationDisposition = OPEN_EXISTING;
    
    if (mode & 0x01 || access & 0x01) { /* Read */
        dwDesiredAccess |= GENERIC_READ;
    }
    if (mode & 0x02 || access & 0x02) { /* Write */
        dwDesiredAccess |= GENERIC_WRITE;
    }
    if (mode & 0x10) { /* Create */
        dwCreationDisposition = CREATE_ALWAYS;
    }
    
    /* Convert to long path if needed */
    const char* path_to_use = convert_to_long_path(filename);
    if (path_to_use == NULL) {
        log_error("win32_emulate_file_open: Failed to convert path");
        return -1;
    }
    
    /* Open file with Windows API */
    HANDLE win_handle = CreateFileA(
        path_to_use,
        dwDesiredAccess,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        dwCreationDisposition,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    if (win_handle == INVALID_HANDLE_VALUE) {
        DWORD error = GetLastError();
        log_error("win32_emulate_file_open: Failed to open '%s' (offset 0x%x)", filename, filename_offset);
        log_windows_error("win32_emulate_file_open", error);
        return -1;
    }
    
    /* Store Windows handle in DOS handle slot */
    set_windows_file_handle(dos_handle, win_handle);
    
    /* Set file flags in MEM_POINTER_STORAGE */
    if (dos_handle + MEM_POINTER_STORAGE < g_gameState->memory_pool_size) {
        byte flags = 0;
        if (dwDesiredAccess & GENERIC_READ) flags |= 1;
        if (dwDesiredAccess & GENERIC_WRITE) flags |= 2;
        g_gameState->memory_pool[dos_handle + MEM_POINTER_STORAGE] = flags;
    }
    
    log_debug("win32_emulate_file_open: Opened '%s' -> DOS handle %u", filename, dos_handle);
    return (int)dos_handle;
}

/* Windows File Emulation: Read from file using DOS handle */
int win32_emulate_file_read(uint dos_handle, void* buffer, uint32_t count) {
    if (dos_handle >= MAX_DOS_FILE_HANDLES) {
        log_error("win32_emulate_file_read: DOS file handle %u out of range (max %d)", dos_handle, MAX_DOS_FILE_HANDLES - 1);
        return -1;
    }
    
    HANDLE win_handle = get_windows_file_handle(dos_handle);
    if (win_handle == INVALID_HANDLE_VALUE) {
        /* File not opened - return -1 instead of error log for test compatibility */
        log_debug("win32_emulate_file_read: DOS file handle %u not mapped to Windows handle (file not opened)", dos_handle);
        return -1;
    }
    
    if (buffer == NULL) {
        log_error("win32_emulate_file_read: NULL buffer");
        return -1;
    }
    
    DWORD bytesRead = 0;
    if (!ReadFile(win_handle, buffer, count, &bytesRead, NULL)) {
        DWORD error = GetLastError();
        log_error("win32_emulate_file_read: Failed to read from DOS handle %u", dos_handle);
        log_windows_error("win32_emulate_file_read", error);
        return -1;
    }
    
    log_debug("win32_emulate_file_read: Read %lu bytes from DOS handle %u", bytesRead, dos_handle);
    return (int)bytesRead;
}

/* Windows File Emulation: Seek in file using DOS handle */
int64_t win32_emulate_file_seek(uint dos_handle, int64_t offset, int origin) {
    HANDLE win_handle = get_windows_file_handle(dos_handle);
    if (win_handle == INVALID_HANDLE_VALUE) {
        log_error("win32_emulate_file_seek: Invalid DOS file handle %u", dos_handle);
        return -1;
    }
    
    DWORD dwMoveMethod;
    switch (origin) {
        case 0: dwMoveMethod = FILE_BEGIN; break;
        case 1: dwMoveMethod = FILE_CURRENT; break;
        case 2: dwMoveMethod = FILE_END; break;
        default:
            log_error("win32_emulate_file_seek: Invalid origin %d", origin);
            return -1;
    }
    
    LARGE_INTEGER liOffset;
    liOffset.QuadPart = offset;
    
    LARGE_INTEGER liNewPos;
    if (!SetFilePointerEx(win_handle, liOffset, &liNewPos, dwMoveMethod)) {
        DWORD error = GetLastError();
        log_error("win32_emulate_file_seek: Failed to seek in DOS handle %u", dos_handle);
        log_windows_error("win32_emulate_file_seek", error);
        return -1;
    }
    
    log_debug("win32_emulate_file_seek: Seeked to position %lld in DOS handle %u", 
              (long long)liNewPos.QuadPart, dos_handle);
    return liNewPos.QuadPart;
}

/* Windows File Emulation: Close file using DOS handle */
int win32_emulate_file_close(uint dos_handle) {
    HANDLE win_handle = get_windows_file_handle(dos_handle);
    if (win_handle == INVALID_HANDLE_VALUE) {
        log_warning("win32_emulate_file_close: Invalid DOS file handle %u", dos_handle);
        return -1;
    }
    
    if (!CloseHandle(win_handle)) {
        DWORD error = GetLastError();
        log_error("win32_emulate_file_close: Failed to close DOS handle %u", dos_handle);
        log_windows_error("win32_emulate_file_close", error);
        free_dos_file_handle(dos_handle);
        return -1;
    }
    
    free_dos_file_handle(dos_handle);
    log_debug("win32_emulate_file_close: Closed DOS handle %u", dos_handle);
    return 0;
}

/* Windows File Emulation: Check if file is at end */
int win32_emulate_file_at_end(uint dos_handle) {
    HANDLE win_handle = get_windows_file_handle(dos_handle);
    if (win_handle == INVALID_HANDLE_VALUE) {
        log_warning("win32_emulate_file_at_end: Invalid DOS file handle %u", dos_handle);
        return 1; /* Treat as end-of-file */
    }
    
    /* Get current file position */
    LARGE_INTEGER liCurrent;
    liCurrent.QuadPart = 0;
    LARGE_INTEGER liFileSize;
    
    if (!SetFilePointerEx(win_handle, liCurrent, &liCurrent, FILE_CURRENT)) {
        log_error("win32_emulate_file_at_end: Failed to get current position for DOS handle %u", dos_handle);
        return 1;
    }
    
    /* Get file size */
    if (!GetFileSizeEx(win_handle, &liFileSize)) {
        log_error("win32_emulate_file_at_end: Failed to get file size for DOS handle %u", dos_handle);
        return 1;
    }
    
    int at_end = (liCurrent.QuadPart >= liFileSize.QuadPart) ? 1 : 0;
    log_debug("win32_emulate_file_at_end: DOS handle %u at position %lld, size %lld, at_end=%d",
              dos_handle, (long long)liCurrent.QuadPart, (long long)liFileSize.QuadPart, at_end);
    return at_end;
}

/* Log file handle */
static FILE* g_log_file = NULL;

/* Initialize log file */
static void init_log_file(void) {
    if (g_log_file == NULL) {
        g_log_file = fopen("skull_game.log", "w");
        if (g_log_file == NULL) {
            fprintf(stderr, "WARNING: Failed to open log file skull_game.log\n");
        } else {
            fprintf(g_log_file, "=== Skull Game Log File ===\n");
            fprintf(g_log_file, "Started: %s\n", __DATE__ " " __TIME__);
            fprintf(g_log_file, "================================\n\n");
            fflush(g_log_file);
        }
    }
}

/* Close log file */
static void close_log_file(void) {
    if (g_log_file != NULL) {
        fprintf(g_log_file, "\n=== Log file closed ===\n");
        fclose(g_log_file);
        g_log_file = NULL;
    }
}

/* Write debug message to both stderr and log file */
void log_debug_message(const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    /* Initialize log file if needed */
    if (g_log_file == NULL) {
        init_log_file();
    }
    
    /* Write to stderr */
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    fflush(stderr);
    
    /* Write to log file */
    if (g_log_file != NULL) {
        va_list args_copy;
        va_copy(args_copy, args);
        vfprintf(g_log_file, format, args_copy);
        fprintf(g_log_file, "\n");
        fflush(g_log_file);
        va_end(args_copy);
    }
    
    va_end(args);
}

void InitGameState(void) {
    if (g_gameState == NULL) {
        // log_info("InitGameState: Initializing game state");
        
        #ifdef _WIN32
        /* Use Windows HeapAlloc for memory allocation */
        HANDLE hHeap = GetProcessHeap();
        if (hHeap == NULL) {
            log_error("InitGameState: Failed to get process heap");
            set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
            fprintf(stderr, "FATAL: Failed to get process heap\n");
            exit(1);
        }
        
        g_gameState = (GameState*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, sizeof(GameState));
        if (g_gameState == NULL) {
            log_error("InitGameState: Failed to allocate game state structure");
            set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
            fprintf(stderr, "FATAL: Failed to allocate game state\n");
            exit(1);
        }
        #else
        /* Non-Windows: Use standard calloc */
        g_gameState = (GameState*)calloc(1, sizeof(GameState));
        if (g_gameState == NULL) {
            log_error("InitGameState: Failed to allocate game state structure");
            set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
            fprintf(stderr, "FATAL: Failed to allocate game state\n");
            exit(1);
        }
        #endif
        
        /* Allocate memory pool to simulate DOS memory model */
        /* Increased to 256KB to accommodate game data (original DOS had more memory available) */
        g_gameState->memory_pool_size = 0x40000; /* 256KB - enough for game data structures */
        
        #ifdef _WIN32
        /* Use Windows HeapAlloc for memory pool allocation */
        g_gameState->memory_pool = (uint8_t*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, g_gameState->memory_pool_size);
        if (g_gameState->memory_pool == NULL) {
            log_error("InitGameState: Failed to allocate memory pool (%zu bytes)", 
                     g_gameState->memory_pool_size);
            set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
            HeapFree(hHeap, 0, g_gameState);
            g_gameState = NULL;
            fprintf(stderr, "FATAL: Failed to allocate memory pool\n");
            exit(1);
        }
        #else
        /* Non-Windows: Use standard calloc */
        g_gameState->memory_pool = (uint8_t*)calloc(1, g_gameState->memory_pool_size);
        if (g_gameState->memory_pool == NULL) {
            log_error("InitGameState: Failed to allocate memory pool (%zu bytes)", 
                     g_gameState->memory_pool_size);
            set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
            free(g_gameState);
            g_gameState = NULL;
            fprintf(stderr, "FATAL: Failed to allocate memory pool\n");
            exit(1);
        }
        #endif
        
        // log_info("InitGameState: Allocated memory pool (%zu bytes)", g_gameState->memory_pool_size);
        
        /* Initialize critical memory addresses to safe values */
        /* These addresses are used by setup_function_context and other functions */
        MEM_WRITE32(0x634, (uint32_t)(uintptr_t)g_gameState->memory_pool + 0x1000); /* Stack pointer area */
        MEM_WRITE32(0x58e, 0); /* Function pointer - initialize to NULL (will be set later if needed) */
        MEM_WRITE32(0x603, 0); /* Status/error code */
        MEM_WRITE32(0x97c, 0); /* Function pointer */
        MEM_WRITE32(0x97e, 0); /* Status flag - MUST be 0 to exit setup_function_context loop early */
        MEM_WRITE32(0x632, 0); /* Function pointer for flush_file_buffers */
        MEM_WRITE32(0x601, 0); /* Segment/pointer */
        MEM_WRITE32(0x2c, 0);  /* Environment pointer */
        MEM_WRITE32(0x5ef, 0); /* Pointer storage */
        MEM_WRITE32(0x5f1, 0); /* Segment storage */
        MEM_WRITE32(0x5e2, 0); /* Buffer pointer */
        MEM_WRITE32(0x60a, 0); /* File handle area - initialize to 0 */
        MEM_WRITE32(0x608, 10); /* Max file handles */
        MEM_WRITE32(0x8a6, 0xffff); /* Keyboard buffer - initialize to empty (0xffff = no character) */
        
        /* Initialize MEM_BASE_POINTER to a safe offset value */
        /* This is used to calculate MEM_DATA_BASE - initialize to a reasonable offset */
        /* Original DOS used segment:offset, we use flat offsets starting from 0 */
        MEM_WRITE32(MEM_BASE_POINTER, 0x5d00); /* Initialize to base offset for data area */
        // log_info("InitGameState: Initialized MEM_BASE_POINTER to 0x%x", MEM_BASE_POINTER);
        
        /* Verify memory initialization */
        uint32_t verify_97e = MEM_READ32(0x97e);
        // log_info("InitGameState: Initialized critical memory addresses (0x97e = %u)", verify_97e);
        if (verify_97e != 0) {
            log_warning("InitGameState: WARNING - 0x97e is not 0 after initialization! Value: %u", verify_97e);
            fprintf(stderr, "WARNING: 0x97e is not 0 after initialization! Value: %u\n", verify_97e);
            fflush(stderr);
            /* Force it to 0 */
            MEM_WRITE32(0x97e, 0);
            verify_97e = MEM_READ32(0x97e);
            // log_info("InitGameState: Forced 0x97e to 0, new value: %u", verify_97e);
        }
        
        /* Initialize function pointers to safe no-op functions */
        initialize_function_pointers();
        
        /* Initialize console for Windows */
        #ifdef _WIN32
        /* Set console output code page to UTF-8 */
        if (SetConsoleOutputCP(CP_UTF8)) {
            log_debug("InitGameState: Set console output to UTF-8");
        } else {
            log_warning("InitGameState: Failed to set console output to UTF-8");
        }
        
        /* Windows 11 Compatibility: Set console input mode for ReadConsoleInput to work properly */
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        if (hStdin != INVALID_HANDLE_VALUE) {
            /* Check if stdin is actually a console (not redirected) */
            DWORD dwMode = 0;
            if (GetConsoleMode(hStdin, &dwMode)) {
                /* stdin is a console - can set mode */
                /* Enable window input and mouse input (required for ReadConsoleInput) */
                dwMode |= ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
                /* Keep line input mode disabled for character-by-character input */
                dwMode &= ~ENABLE_LINE_INPUT;
                dwMode &= ~ENABLE_ECHO_INPUT;
                if (SetConsoleMode(hStdin, dwMode)) {
                    log_debug("InitGameState: Set console input mode for ReadConsoleInput");
                } else {
                    /* Non-critical: Failed to set mode, but ReadConsoleInput may still work */
                    log_debug("InitGameState: Failed to set console input mode (non-critical)");
                }
            } else {
                /* stdin is redirected (file/pipe) - this is OK, don't warn */
                /* GetConsoleMode fails when stdin is redirected, which is expected */
                log_debug("InitGameState: stdin is redirected, console mode not applicable");
            }
        } else {
            /* Invalid handle - this is unusual, but non-critical */
            log_debug("InitGameState: Invalid stdin handle (stdin may be redirected)");
        }
        #endif
        
        // log_info("InitGameState: Game state initialized successfully");
    } else {
        log_warning("InitGameState: Game state already initialized");
    }
}

void CleanupGameState(void) {
    if (g_gameState) {
        #ifdef _WIN32
        /* Use Windows HeapFree for memory deallocation */
        HANDLE hHeap = GetProcessHeap();
        if (hHeap != NULL) {
            if (g_gameState->memory_pool) {
                HeapFree(hHeap, 0, g_gameState->memory_pool);
            }
            HeapFree(hHeap, 0, g_gameState);
        } else {
            log_warning("CleanupGameState: Failed to get process heap, using free() fallback");
            if (g_gameState->memory_pool) {
                free(g_gameState->memory_pool);
            }
            free(g_gameState);
        }
        #else
        /* Non-Windows: Use standard free */
        if (g_gameState->memory_pool) {
            free(g_gameState->memory_pool);
        }
        free(g_gameState);
        #endif
        g_gameState = NULL;
    }
    
    /* Close log file on cleanup */
    close_log_file();
}

/* Windows 11 Compatibility: Helper function to convert path to long path format */
static char* convert_to_long_path(const char* filename) {
    static char long_path[32768]; /* PATHCCH_MAX_CCH + 1 */
    
    if (filename == NULL) {
        log_error("convert_to_long_path: filename is NULL");
        return NULL;
    }
    
    size_t len = strlen(filename);
    log_debug("convert_to_long_path: Processing path '%s' (length: %zu)", filename, len);
    
    /* Windows 11: If path is already long path format (\\?\), return as-is */
    if (len >= 4 && filename[0] == '\\' && filename[1] == '\\' && 
        filename[2] == '?' && filename[3] == '\\') {
        if (len < sizeof(long_path)) {
            strncpy(long_path, filename, sizeof(long_path) - 1);
            long_path[sizeof(long_path) - 1] = '\0'; /* Ensure null termination */
            return long_path;
        }
    }
    
    /* If path is longer than MAX_PATH (260), convert to long path format */
    if (len >= MAX_PATH || strchr(filename, '~') != NULL) {
        /* Prepend \\?\ for long path support */
        if (len + 4 < sizeof(long_path)) {
            snprintf(long_path, sizeof(long_path), "\\\\?\\%s", filename);
            return long_path;
        }
    }
    
    /* Short path, return as-is */
    if (len < sizeof(long_path)) {
        strncpy(long_path, filename, sizeof(long_path) - 1);
        long_path[sizeof(long_path) - 1] = '\0'; /* Ensure null termination */
        return long_path;
    }
    
    log_error("convert_to_long_path: Path too long (>32767 characters)");
    return NULL;
}

/* DOS File I/O Implementation */
dos_file_handle dos_open_file(const char* filename, int mode) {
    if (filename == NULL) {
        log_error("dos_open_file: NULL filename provided");
        set_last_error(SKULL_ERROR_INVALID_PARAMETER);
        return DOS_INVALID_HANDLE;
    }
    
    DWORD dwDesiredAccess = 0;
    DWORD dwCreationDisposition = 0;
    
    /* Convert DOS mode to Windows flags */
    if (mode & 0x01) { /* Read */
        dwDesiredAccess |= GENERIC_READ;
    }
    if (mode & 0x02) { /* Write */
        dwDesiredAccess |= GENERIC_WRITE;
    }
    
    if (mode & 0x10) { /* Create */
        dwCreationDisposition = CREATE_ALWAYS;
    } else {
        dwCreationDisposition = OPEN_EXISTING;
    }
    
    /* Windows 11 Compatibility: Convert to long path format if needed */
    const char* path_to_use = convert_to_long_path(filename);
    if (path_to_use == NULL) {
        log_error("dos_open_file: Failed to convert path to long path format");
        set_last_error(SKULL_ERROR_INVALID_PARAMETER);
        return DOS_INVALID_HANDLE;
    }
    
    log_debug("dos_open_file: Opening '%s' with mode 0x%x (long path: '%s')", filename, mode, path_to_use);
    
    HANDLE hFile = CreateFileA(
        path_to_use,
        dwDesiredAccess,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        dwCreationDisposition,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    if (hFile == INVALID_HANDLE_VALUE) {
        DWORD error = GetLastError();
        ErrorCode error_code = SKULL_ERROR_FILE_NOT_FOUND;
        
        if (error == ERROR_ACCESS_DENIED) {
            error_code = SKULL_ERROR_FILE_ACCESS_DENIED;
        } else if (error == ERROR_FILE_NOT_FOUND || error == ERROR_PATH_NOT_FOUND) {
            error_code = SKULL_ERROR_FILE_NOT_FOUND;
        }
        
        log_error("dos_open_file: Failed to open '%s'", filename);
        log_windows_error("dos_open_file", error);
        set_last_error(error_code);
        return DOS_INVALID_HANDLE;
    }
    
    // log_info("dos_open_file: Successfully opened '%s'", filename);
    return hFile;
}

int dos_close_file(dos_file_handle handle) {
    if (handle == DOS_INVALID_HANDLE) {
        log_warning("dos_close_file: Attempted to close invalid handle");
        set_last_error(SKULL_ERROR_INVALID_HANDLE);
        return -1;
    }
    
    if (CloseHandle(handle)) {
        log_debug("dos_close_file: Successfully closed file handle");
        return 0;
    } else {
        DWORD error = GetLastError();
        log_error("dos_close_file: Failed to close file handle");
        log_windows_error("dos_close_file", error);
        set_last_error(SKULL_ERROR_FILE_WRITE_FAILED);
        return -1;
    }
}

int dos_read_file(dos_file_handle handle, void* buffer, uint32_t count) {
    if (handle == DOS_INVALID_HANDLE) {
        log_warning("dos_read_file: Invalid handle");
        set_last_error(SKULL_ERROR_INVALID_HANDLE);
        return -1;
    }
    
    if (buffer == NULL) {
        log_error("dos_read_file: NULL buffer provided");
        set_last_error(SKULL_ERROR_INVALID_PARAMETER);
        return -1;
    }
    
    DWORD bytesRead = 0;
    if (ReadFile(handle, buffer, count, &bytesRead, NULL)) {
        log_debug("dos_read_file: Read %lu bytes (requested %u)", bytesRead, count);
        if (bytesRead < count) {
            log_warning("dos_read_file: Partial read - requested %u, got %lu", count, bytesRead);
        }
        return (int)bytesRead;
    } else {
        DWORD error = GetLastError();
        log_error("dos_read_file: Failed to read %u bytes", count);
        log_windows_error("dos_read_file", error);
        set_last_error(SKULL_ERROR_FILE_READ_FAILED);
        return -1;
    }
}

int dos_write_file(dos_file_handle handle, const void* buffer, uint32_t count) {
    if (handle == DOS_INVALID_HANDLE) {
        log_warning("dos_write_file: Invalid handle");
        set_last_error(SKULL_ERROR_INVALID_HANDLE);
        return -1;
    }
    
    if (buffer == NULL) {
        log_error("dos_write_file: NULL buffer provided");
        set_last_error(SKULL_ERROR_INVALID_PARAMETER);
        return -1;
    }
    
    DWORD bytesWritten = 0;
    if (WriteFile(handle, buffer, count, &bytesWritten, NULL)) {
        log_debug("dos_write_file: Wrote %lu bytes (requested %u)", bytesWritten, count);
        if (bytesWritten < count) {
            log_warning("dos_write_file: Partial write - requested %u, got %lu", count, bytesWritten);
        }
        return (int)bytesWritten;
    } else {
        DWORD error = GetLastError();
        log_error("dos_write_file: Failed to write %u bytes", count);
        log_windows_error("dos_write_file", error);
        set_last_error(SKULL_ERROR_FILE_WRITE_FAILED);
        return -1;
    }
}

int64_t dos_seek_file(dos_file_handle handle, int64_t offset, int origin) {
    if (handle == DOS_INVALID_HANDLE) {
        log_warning("dos_seek_file: Invalid handle");
        set_last_error(SKULL_ERROR_INVALID_HANDLE);
        return -1;
    }
    
    DWORD dwMoveMethod;
    switch (origin) {
        case 0: dwMoveMethod = FILE_BEGIN; break;
        case 1: dwMoveMethod = FILE_CURRENT; break;
        case 2: dwMoveMethod = FILE_END; break;
        default:
            log_error("dos_seek_file: Invalid origin %d", origin);
            set_last_error(SKULL_ERROR_INVALID_PARAMETER);
            return -1;
    }
    
    LARGE_INTEGER liOffset;
    liOffset.QuadPart = offset;
    
    LARGE_INTEGER liNewPos;
    if (SetFilePointerEx(handle, liOffset, &liNewPos, dwMoveMethod)) {
        log_debug("dos_seek_file: Seeked to position %lld (origin %d, offset %lld)", 
                  (long long)liNewPos.QuadPart, origin, offset);
        return liNewPos.QuadPart;
    } else {
        DWORD error = GetLastError();
        log_error("dos_seek_file: Failed to seek to offset %lld (origin %d)", offset, origin);
        log_windows_error("dos_seek_file", error);
        set_last_error(SKULL_ERROR_FILE_SEEK_FAILED);
        return -1;
    }
}

/* DOS Memory Functions - Now using Windows APIs */
void* dos_alloc_memory(size_t size) {
    if (size == 0) {
        log_warning("dos_alloc_memory: Attempted to allocate 0 bytes");
        return NULL;
    }
    
    #ifdef _WIN32
    /* Use Windows HeapAlloc for memory allocation */
    HANDLE hHeap = GetProcessHeap();
    if (hHeap == NULL) {
        log_error("dos_alloc_memory: Failed to get process heap");
        set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
        return NULL;
    }
    
    void* ptr = HeapAlloc(hHeap, 0, size);
    if (ptr == NULL) {
        log_error("dos_alloc_memory: Failed to allocate %zu bytes", size);
        set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
    } else {
        log_debug("dos_alloc_memory: Allocated %zu bytes at %p (Windows HeapAlloc)", size, ptr);
    }
    return ptr;
    #else
    /* Non-Windows: Use standard malloc */
    void* ptr = malloc(size);
    if (ptr == NULL) {
        log_error("dos_alloc_memory: Failed to allocate %zu bytes", size);
        set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
    } else {
        log_debug("dos_alloc_memory: Allocated %zu bytes at %p", size, ptr);
    }
    return ptr;
    #endif
}

void dos_free_memory(void* ptr) {
    if (ptr == NULL) {
        log_warning("dos_free_memory: Attempted to free NULL pointer");
        return;
    }
    
    #ifdef _WIN32
    /* Use Windows HeapFree for memory deallocation */
    HANDLE hHeap = GetProcessHeap();
    if (hHeap != NULL) {
        if (HeapFree(hHeap, 0, ptr)) {
            log_debug("dos_free_memory: Freed memory at %p (Windows HeapFree)", ptr);
        } else {
            log_warning("dos_free_memory: HeapFree failed for %p", ptr);
        }
    } else {
        log_warning("dos_free_memory: Failed to get process heap, using free() fallback");
        free(ptr);
    }
    #else
    /* Non-Windows: Use standard free */
    log_debug("dos_free_memory: Freeing memory at %p", ptr);
    free(ptr);
    #endif
}

void* dos_resize_memory(void* ptr, size_t new_size) {
    if (new_size == 0) {
        log_warning("dos_resize_memory: Attempted to resize to 0 bytes");
        if (ptr != NULL) {
            #ifdef _WIN32
            dos_free_memory(ptr);
            #else
            free(ptr);
            #endif
        }
        return NULL;
    }
    
    #ifdef _WIN32
    /* Use Windows HeapReAlloc for memory resizing */
    HANDLE hHeap = GetProcessHeap();
    if (hHeap == NULL) {
        log_error("dos_resize_memory: Failed to get process heap");
        set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
        return NULL;
    }
    
    void* new_ptr;
    if (ptr == NULL) {
        /* Allocate new block if ptr is NULL */
        new_ptr = HeapAlloc(hHeap, 0, new_size);
    } else {
        /* Resize existing block */
        new_ptr = HeapReAlloc(hHeap, 0, ptr, new_size);
    }
    
    if (new_ptr == NULL) {
        log_error("dos_resize_memory: Failed to resize memory from %p to %zu bytes", ptr, new_size);
        set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
    } else {
        log_debug("dos_resize_memory: Resized memory from %p to %p (%zu bytes) (Windows HeapReAlloc)", 
                  ptr, new_ptr, new_size);
    }
    return new_ptr;
    #else
    /* Non-Windows: Use standard realloc */
    void* new_ptr = realloc(ptr, new_size);
    if (new_ptr == NULL && new_size > 0) {
        log_error("dos_resize_memory: Failed to resize memory from %p to %zu bytes", ptr, new_size);
        set_last_error(SKULL_ERROR_MEMORY_ALLOCATION_FAILED);
    } else {
        log_debug("dos_resize_memory: Resized memory from %p to %p (%zu bytes)", ptr, new_ptr, new_size);
    }
    return new_ptr;
    #endif
}

/* DOS System Functions */
/* Windows 11 Compatibility: GetVersionExA is deprecated and returns incorrect values on Windows 10/11 */
/* Return a fixed version to indicate modern Windows (10/11) */
void dos_get_version(uint8_t* major, uint8_t* minor) {
    /* Windows 11 Compatibility: GetVersionExA is deprecated and returns incorrect values */
    /* On Windows 10/11, it always returns 10.0 regardless of actual version */
    /* Since we're targeting Windows 10+, just return that */
    if (major != NULL) {
        *major = 10;  /* Windows 10/11 both report as major version 10 */
    }
    if (minor != NULL) {
        *minor = 0;   /* Minor version for Windows 10/11 */
    }
    log_debug("dos_get_version: Returning Windows 10/11 (compatibility mode)");
}

void dos_terminate(int exit_code) {
    exit(exit_code);
}

/* TEST MODE: Persistent buffer for test input injection */
static uint32_t g_test_keyboard_buffer = 0xffff; /* Default: empty */
static bool g_test_buffer_active = false;
static int g_test_buffer_read_count = 0; /* Track how many times buffer has been read */
static int g_test_buffer_set_count = 0; /* Track how many times buffer has been set */

/* Function to set test keyboard buffer (called from tests) */
void set_test_keyboard_buffer(uint32_t value) {
    g_test_keyboard_buffer = value;
    g_test_buffer_active = (value != 0xffff && value != 0xffffffff && ((value >> 8) & 0xFF) != 0);
    g_test_buffer_read_count = 0; /* Reset read count when buffer is set */
    g_test_buffer_set_count++;
    
    if (g_gameState != NULL && g_gameState->memory_pool != NULL && MEM_KEYBOARD_BUFFER + 4 <= g_gameState->memory_pool_size) {
        MEM_WRITE32(MEM_KEYBOARD_BUFFER, value);
    }
    
    uint8_t high_byte = (uint8_t)(value >> 8);
    uint8_t low_byte = (uint8_t)(value & 0xFF);
    log_info("set_test_keyboard_buffer: Set test buffer to 0x%08x (high=0x%02x, low=0x%02x, active=%d, set_count=%d)", 
             value, high_byte, low_byte, g_test_buffer_active, g_test_buffer_set_count);
    fprintf(stderr, "set_test_keyboard_buffer: Set test buffer to 0x%08x (high=0x%02x, low=0x%02x, active=%d)\n",
            value, high_byte, low_byte, g_test_buffer_active);
    fflush(stderr);
}

/* Console I/O - Windows 11 Compatibility: Use modern ReadConsoleInput instead of deprecated _getch()/_kbhit() */
int dos_get_char(void) {
    #ifdef _WIN32
    /* TEST MODE: Check persistent test buffer first, then memory buffer */
    if (g_test_buffer_active) {
        uint8_t high_byte = (uint8_t)(g_test_keyboard_buffer >> 8);
        if (high_byte != 0) {
            uint8_t char_value = (uint8_t)(g_test_keyboard_buffer & 0xFF);
            g_test_buffer_read_count++;
            log_info("dos_get_char: Using persistent test buffer character 0x%02x ('%c') (buffer=0x%08x, read_count=%d)", 
                     char_value, (char_value >= 32 && char_value < 127) ? (char)char_value : '?', 
                     g_test_keyboard_buffer, g_test_buffer_read_count);
            fprintf(stderr, "dos_get_char: Using persistent test buffer character 0x%02x ('%c') (read_count=%d)\n",
                    char_value, (char_value >= 32 && char_value < 127) ? (char)char_value : '?', 
                    g_test_buffer_read_count);
            fflush(stderr);
            
            /* REUSABLE BUFFER: Don't clear immediately - allow multiple reads of same character */
            /* Only clear if explicitly requested or if we've read it too many times */
            /* For now, keep it active so it can be reused */
            /* Tests can call set_test_keyboard_buffer() again to change the character */
            return (int)char_value;
        } else {
            log_info("dos_get_char: Test buffer active but high byte is 0 (buffer=0x%08x)", g_test_keyboard_buffer);
            g_test_buffer_active = false; /* Deactivate if high byte is 0 */
        }
    } else {
        log_info("dos_get_char: Test buffer not active (buffer=0x%08x, set_count=%d, read_count=%d)", 
                 g_test_keyboard_buffer, g_test_buffer_set_count, g_test_buffer_read_count);
    }
    
    /* Check keyboard buffer in memory (may be cleared by setup_function_context) */
    if (g_gameState != NULL && g_gameState->memory_pool != NULL) {
        if (MEM_KEYBOARD_BUFFER + 4 <= g_gameState->memory_pool_size) {
            uint32_t buffer_value = MEM_READ32(MEM_KEYBOARD_BUFFER);
            uint8_t high_byte = (uint8_t)(buffer_value >> 8);
            
            log_info("dos_get_char: Checking memory buffer = 0x%08x (high=0x%02x)", buffer_value, high_byte);
            
            /* If buffer has a character (high byte != 0) and it's not the error marker */
            if (high_byte != 0 && buffer_value != 0xffff && buffer_value != 0xffffffff) {
                /* Extract the character from low byte */
                uint8_t char_value = (uint8_t)(buffer_value & 0xFF);
                log_info("dos_get_char: Using memory buffer character 0x%02x ('%c') (buffer=0x%08x)", 
                         char_value, (char_value >= 32 && char_value < 127) ? (char)char_value : '?', buffer_value);
                fprintf(stderr, "dos_get_char: Using memory buffer character 0x%02x ('%c')\n",
                        char_value, (char_value >= 32 && char_value < 127) ? (char)char_value : '?');
                fflush(stderr);
                /* REUSABLE: Don't clear immediately - allow reuse */
                /* Only clear if we want to force reading from keyboard next time */
                /* For now, keep it so it can be reused */
                return (int)char_value;
            } else {
                log_info("dos_get_char: Memory buffer empty or invalid (0x%08x)", buffer_value);
            }
        } else {
            log_info("dos_get_char: MEM_KEYBOARD_BUFFER out of bounds");
        }
    } else {
        log_info("dos_get_char: Game state not initialized");
    }
    
    /* Windows 11 Compatibility: Use ReadConsoleInput instead of deprecated _getch() */
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    
    /* Check if stdin is a console or redirected input */
    DWORD dwMode = 0;
    BOOL is_console = (hStdin != INVALID_HANDLE_VALUE && GetConsoleMode(hStdin, &dwMode));
    
    if (!is_console) {
        /* stdin is redirected (file/pipe) or invalid - use fgetc() */
        log_debug("dos_get_char: stdin is redirected or invalid, using fgetc() fallback");
        int ch = fgetc(stdin);
        if (ch == EOF) {
            return 0;
        }
        return (unsigned char)ch;
    }
    
    INPUT_RECORD input_record;
    DWORD num_read = 0;
    
    /* Wait for key press */
    /* Limit retries to prevent infinite loop if ReadConsoleInputA keeps failing */
    int retry_count = 0;
    const int MAX_RETRIES = 5; /* Only retry 5 times - if it fails, stdin is likely redirected */
    
    while (retry_count < MAX_RETRIES) {
        if (!ReadConsoleInputA(hStdin, &input_record, 1, &num_read)) {
            retry_count++;
            DWORD error = GetLastError();
            
            /* If error is ERROR_INVALID_HANDLE, stdin might have been redirected */
            if (error == ERROR_INVALID_HANDLE) {
                log_debug("dos_get_char: ReadConsoleInputA failed with ERROR_INVALID_HANDLE, using fgetc() fallback");
                int ch = fgetc(stdin);
                if (ch == EOF) {
                    return 0;
                }
                return (unsigned char)ch;
            }
            
            /* Only log first few failures */
            if (retry_count <= 3) {
                log_warning("dos_get_char: ReadConsoleInputA failed (retry %d, error=%d)", retry_count, error);
            }
            
            /* If we've retried too many times, fall back to fgetc() */
            if (retry_count >= MAX_RETRIES) {
                log_warning("dos_get_char: ReadConsoleInputA failed %d times, using fgetc() fallback", retry_count);
                int ch = fgetc(stdin);
                if (ch == EOF) {
                    return 0;
                }
                return (unsigned char)ch;
            }
            
            /* Small delay before retrying to avoid tight loop */
            Sleep(10); /* 10ms delay */
            continue;
        }
        
        retry_count = 0; /* Reset counter on success */
        
        if (input_record.EventType == KEY_EVENT && input_record.Event.KeyEvent.bKeyDown) {
            /* Return the ASCII character */
            char ch = input_record.Event.KeyEvent.uChar.AsciiChar;
            if (ch != 0) {
                return (unsigned char)ch;
            }
            /* Extended key - return scan code in high byte */
            WORD vkey = input_record.Event.KeyEvent.wVirtualKeyCode;
            return (vkey << 8) | 0x00;
        }
    }
    
    /* Should never reach here, but return 0 if we do */
    log_error("dos_get_char: Exited retry loop unexpectedly");
    return 0;
    #else
    /* Fallback for non-Windows */
    return getchar();
    #endif
}

int dos_kbhit(void) {
    #ifdef _WIN32
    /* Windows 11 Compatibility: Use PeekConsoleInput instead of deprecated _kbhit() */
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE) {
        return 0;
    }
    
    INPUT_RECORD input_record;
    DWORD num_events = 0;
    
    /* Check if there are pending input events */
    if (!GetNumberOfConsoleInputEvents(hStdin, &num_events)) {
        return 0;
    }
    
    if (num_events == 0) {
        return 0;
    }
    
    /* Peek at the next event without removing it */
    if (!PeekConsoleInputA(hStdin, &input_record, 1, &num_events)) {
        return 0;
    }
    
    /* Check if it's a key event */
    if (input_record.EventType == KEY_EVENT) {
        return 1;
    }
    
    /* Not a key event, remove it and check next */
    ReadConsoleInputA(hStdin, &input_record, 1, &num_events);
    return dos_kbhit(); /* Recursively check next event */
    #else
    return 0; /* Not available on non-Windows */
    #endif
}

void dos_put_char(char c) {
    putchar(c);
    fflush(stdout);
}

void dos_put_string(const char* str) {
    printf("%s", str);
    fflush(stdout);
}

int dos_get_string(char* buffer, int max_len) {
    if (fgets(buffer, max_len, stdin) != NULL) {
        /* Remove newline */
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        return (int)len;
    }
    return 0;
}

/* DOS Interrupt handling - swi() function */
/* This is a stub that returns a no-op function pointer */
/* In a real implementation, this would handle DOS interrupts (INT 21h, INT 10h, etc.) */
void noop_interrupt(void) {
    // log_info("noop_interrupt: Called (DOS interrupt stub)");
    // fprintf(stderr, "noop_interrupt: Called (DOS interrupt stub)\n");
    fflush(stderr);
    /* No-op: DOS interrupts are not directly supported on Windows */
    /* The actual interrupt handling would need to be implemented based on context */
    // log_info("noop_interrupt: Returning");
    return;
}

/* Safe no-op function for function pointer calls */
void safe_noop_call(void) {
    log_debug("safe_noop_call: Called");
    /* Safe no-op function that can be called via function pointers */
    /* Used to prevent crashes from uninitialized function pointers */
    return;
}

interrupt_handler* swi(int interrupt_num) {
    // log_info("swi: Called with interrupt_num = 0x%x", interrupt_num);
    // fprintf(stderr, "swi: Called with interrupt_num = 0x%x\n", interrupt_num);
    fflush(stderr);
    /* Return a function pointer that does nothing */
    /* In the original code, this would execute a DOS interrupt */
    /* For now, we return a no-op function */
    // log_info("swi: Returning noop_interrupt function pointer");
    return (interrupt_handler*)noop_interrupt;
}

/* Initialize function pointer addresses to safe no-op functions */
void initialize_function_pointers(void) {
    if (g_gameState == NULL || g_gameState->memory_pool == NULL) {
        return;
    }
    
    /* Initialize function pointer at 0x58e to safe no-op */
    code **func_ptr_58e = (code **)(g_gameState->memory_pool + 0x58e);
    *func_ptr_58e = (code *)safe_noop_call;
    
    /* Initialize function pointer at 0x97c to safe no-op */
    code **func_ptr_97c = (code **)(g_gameState->memory_pool + 0x97c);
    *func_ptr_97c = (code *)safe_noop_call;
    
    log_debug("initialize_function_pointers: Initialized function pointers to safe no-ops");
}

/* Forward declarations for functions in skull_ported.c */
extern void setup_function_context(undefined reg_ax, undefined2 reg_bx, undefined reg_cx, undefined2 reg_dx, undefined2 reg_si);
extern void init_random_seed(undefined2 seed);
extern int file_open(undefined2 filename_ptr);
extern int file_read_word(undefined2 file_handle, undefined2 buffer, undefined2 count);
extern undefined2 call_dos_interrupt(byte interrupt_id, int regs_ptr, undefined2 *result_ptr);
extern void display_string(char *str);
extern void display_status_screen(int screen_id);
extern void print_string(int window_id, char *text);
extern int load_and_display_message(undefined2 message_id);
extern char* format_string(char *dest, char *format, char **args);
extern int process_commands(int command_buffer, undefined2 context);
extern void copy_string_data(undefined2 *dest, undefined2 *src);
extern int string_length(char *str);
extern undefined2 get_input_line(byte *buffer, int max_length);
extern undefined2 execute_command(uint *command_params, int has_object);
extern int parse_command_input(int token_buffer, int input_buffer);
extern int process_command_parameters(uint *params, int count, int offset, int result_ptr);
extern undefined2 handle_location_change(undefined2 new_location_id);
extern undefined2 handle_special_command(undefined2 command_id);
extern uint* check_command_conditions(uint *command_data, int param_count, int offset, uint *result);
extern int* process_game_action(int *action_data);
extern undefined2 match_game_objects(uint *command_data, uint *result_ptr, char *object_name);
extern int find_objects_in_location(byte *list_ptr, uint location_id, uint flags, int max_count);

/* Wrapper functions for functions called without parameters */
void setup_function_context_wrapper(void) {
    // log_info("setup_function_context_wrapper: Entering");
    // fprintf(stderr, "setup_function_context_wrapper: Entering\n");
    fflush(stderr);
    
    if (g_gameState == NULL) {
        log_error("setup_function_context_wrapper: g_gameState is NULL!");
        fprintf(stderr, "ERROR: setup_function_context_wrapper: g_gameState is NULL!\n");
        fflush(stderr);
        return;
    }
    
    /* Skip console-specific setup when stdin is piped/redirected */
    /* This prevents crashes when reading commands from a file or pipe */
    if (is_stdin_piped()) {
        // log_info("setup_function_context_wrapper: Skipping setup (stdin is piped)");
        return;
    }
    
    // log_info("setup_function_context_wrapper: Calling setup_function_context");
    // fprintf(stderr, "setup_function_context_wrapper: Calling setup_function_context\n");
    fflush(stderr);
    
    #ifdef _WIN32
    __try {
        setup_function_context(0, 0, 0, 0, 0);  /* All registers set to 0 */
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        __try {
            log_exception_details(GetExceptionCode(), "setup_function_context_wrapper: setup_function_context", __FILE__, __LINE__);
        } __except(EXCEPTION_EXECUTE_HANDLER) {
            fprintf(stderr, "setup_function_context_wrapper: Exception in setup_function_context (0x%x)\n", GetExceptionCode());
            fflush(stderr);
        }
        /* Continue execution - setup_function_context may fail but caller might still work */
    }
    #else
    setup_function_context(0, 0, 0, 0, 0);  /* All registers set to 0 */
    #endif
    
    // log_info("setup_function_context_wrapper: Returned from setup_function_context");
    // fprintf(stderr, "setup_function_context_wrapper: Returned from setup_function_context\n");
    fflush(stderr);
}

void init_random_seed_wrapper(void) {
    init_random_seed(0);
}

int file_open_wrapper(void) {
    /* Determine which file to open based on sequence */
    const char* filename = NULL;
    
    if (g_file_open_index < (int)(sizeof(g_game_files) / sizeof(g_game_files[0]) - 1)) {
        filename = g_game_files[g_file_open_index];
        fprintf(stderr, "file_open_wrapper: Opening file #%d: %s\n", g_file_open_index, filename);
        fflush(stderr);
    } else {
        log_error("file_open_wrapper: File index %d out of range", g_file_open_index);
        fprintf(stderr, "ERROR: file_open_wrapper: File index %d out of range\n", g_file_open_index);
        fflush(stderr);
        return -1;
    }
    
    /* Check if filename is valid */
    if (filename == NULL) {
        log_error("file_open_wrapper: filename is NULL");
        fprintf(stderr, "ERROR: file_open_wrapper: filename is NULL\n");
        fflush(stderr);
        g_file_open_index++;
        return -1;
    }
    
    // log_info("file_open_wrapper: About to convert path to long path format");
    // fprintf(stderr, "file_open_wrapper: About to convert path to long path format\n");
    // fflush(stderr);
    
    /* Windows 11 Compatibility: Convert to long path format if needed */
    const char* path_to_use = convert_to_long_path(filename);
    // log_info("file_open_wrapper: Path conversion completed, path_to_use = %s", path_to_use ? path_to_use : "NULL");
    // fprintf(stderr, "file_open_wrapper: Path conversion completed\n");
    // fflush(stderr);
    
    if (path_to_use == NULL) {
        log_error("file_open_wrapper: Failed to convert path to long path format");
        fprintf(stderr, "ERROR: file_open_wrapper: Failed to convert path to long path format\n");
        fflush(stderr);
        g_file_open_index++; /* Increment even on failure to avoid infinite loop */
        return -1;
    }
    
    // log_info("file_open_wrapper: About to call CreateFileA");
    // fprintf(stderr, "file_open_wrapper: About to call CreateFileA\n");
    // fflush(stderr);
    
    /* Open the file using Windows API */
    HANDLE hFile = CreateFileA(
        path_to_use,
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    // log_info("file_open_wrapper: CreateFileA returned, checking handle");
    // fprintf(stderr, "file_open_wrapper: CreateFileA returned\n");
    // fflush(stderr);
    
    if (hFile == INVALID_HANDLE_VALUE) {
        DWORD error = GetLastError();
        log_error("file_open_wrapper: Failed to open '%s'", filename);
        log_windows_error("file_open_wrapper", error);
        fprintf(stderr, "ERROR: file_open_wrapper: Failed to open '%s' (error: %lu)\n", filename, error);
        fflush(stderr);
        g_file_open_index++; /* Increment even on failure to avoid infinite loop */
        return -1;
    }
    
    fprintf(stderr, "file_open_wrapper: Successfully opened '%s', handle: %p\n", filename, (void*)hFile);
    fflush(stderr);
    
    /* Store handle for file_read_word_wrapper to use */
    g_current_file_handle = hFile;
    
    /* Increment index for next call */
    g_file_open_index++;
    
    /* Return handle as integer (file handle index) */
    /* Note: In the original DOS code, this would be a file handle index, not the actual handle */
    /* We'll store the actual Windows handle in a table and return the index */
    /* For now, return the handle value directly (cast to int) */
    return (int)(intptr_t)hFile;
}

void file_close_wrapper(void) {
    if (g_current_file_handle != INVALID_HANDLE_VALUE) {
        // log_info("file_close_wrapper: Closing file handle");
        // fprintf(stderr, "file_close_wrapper: Closing file handle\n");
        fflush(stderr);
        
        if (CloseHandle(g_current_file_handle)) {
            log_debug("file_close_wrapper: File closed successfully");
        } else {
            DWORD error = GetLastError();
            log_error("file_close_wrapper: Failed to close file handle");
            log_windows_error("file_close_wrapper", error);
            fprintf(stderr, "ERROR: file_close_wrapper: Failed to close file (error: %lu)\n", error);
            fflush(stderr);
        }
        g_current_file_handle = INVALID_HANDLE_VALUE;
    } else {
        log_warning("file_close_wrapper: No file handle to close");
        fprintf(stderr, "WARNING: file_close_wrapper: No file handle to close\n");
        fflush(stderr);
    }
}

/* file_close_impl() is defined in skull_ported.c */

int file_read_word_wrapper(void) {
    /* file_read_word expects: file_handle, buffer_address, count */
    /* file_read_word calls read_file_buffer which needs the actual file handle */
    /* We track the current file handle in g_current_file_handle */
    
    static int read_count = 0;
    read_count++;
    
    /* Only log every 1000th call to reduce log verbosity during file loading */
    if (read_count % 1000 == 0) {
        fprintf(stderr, "file_read_word_wrapper: Call #%d\n", read_count);
        fflush(stderr);
    }
    
    if (g_current_file_handle == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "ERROR: file_read_word_wrapper: No file handle available\n");
        fflush(stderr);
        return -1;
    }
    
    /* Read a 16-bit word (2 bytes) from the file */
    /* We need to determine where to read it - this is complex */
    /* For now, read into a temporary buffer and return the value */
    uint16_t word_buffer = 0;
    DWORD bytes_read = 0;
    
    if (!ReadFile(g_current_file_handle, &word_buffer, 2, &bytes_read, NULL)) {
        DWORD error = GetLastError();
        /* Check if this is actually EOF (ERROR_HANDLE_EOF = 38) */
        if (error == ERROR_HANDLE_EOF || error == 0) {
            /* EOF reached - this is normal at end of file */
            return -1; /* Return -1 to signal EOF clearly */
        }
        fprintf(stderr, "ERROR: file_read_word_wrapper: Failed to read from file (error: %lu)\n", error);
        fflush(stderr);
        return -1;
    }
    
    if (bytes_read != 2) {
        if (bytes_read == 0) {
            /* EOF - only log if it's an unexpected EOF (not when we're near end of file) */
            return -1; /* Return -1 to signal EOF clearly */
        } else {
            /* Partial read - file has odd number of bytes */
            return -1; /* Signal EOF after partial read */
        }
    }
    
    /* Only log every 1000th word to reduce log verbosity during file loading */
    if (read_count % 1000 == 0) {
        fprintf(stderr, "file_read_word_wrapper: Read word: 0x%04x (call #%d)\n", word_buffer, read_count);
        fflush(stderr);
    }
    
    /* The original file_read_word would store this in memory and return a status */
    /* For now, return the word value as success indicator */
    /* Note: This might not be correct - the original might return bytes read or status */
    return (int)word_buffer;
}

void call_dos_interrupt_wrapper(void) {
    /* In DOS, interrupt parameters would be passed via registers */
    /* This is a DOS-specific function that's likely no-op on Windows */
    log_debug("call_dos_interrupt_wrapper: Called (no-op on Windows)");
    /* Don't call the actual function with dummy values - it's not needed on Windows */
}

void display_string_wrapper(void) {
    /* In DOS, the string pointer would be in a register */
    /* For now, just flush output to ensure display works */
    fflush(stdout);
}

void display_status_screen_wrapper(void) {
    /* In DOS, screen type would be passed via register */
    /* For now, output a status indicator */
    DisplayPrint("--- Status ---\n");
    fflush(stdout);
}

void print_string_wrapper(void) {
    /* In DOS, parameters would be passed via registers/stack */
    /* No-op for clean player output - actual messages come from display_message_wrapper_0 */
    /* Debug: fprintf(stderr, "[print_string_wrapper called]\n"); */
    fflush(stdout);
}

int load_and_display_message_wrapper(void) {
    /* In DOS, message ID would be passed via register */
    /* For now, output a generic response */
    DisplayPrint("OK.\n");
    fflush(stdout);
    return 1; /* Return success */
}

/* Global variable to store last command line for simple game engine */
static char g_last_command_line[256] = {0};

/* Get last command line (for simple game engine) */
const char* get_last_command_line(void) {
    return g_last_command_line;
}

/* Check if stdin is interactive (not piped) */
static int is_stdin_interactive(void) {
    #ifdef _WIN32
    return _isatty(_fileno(stdin));
    #else
    return isatty(fileno(stdin));
    #endif
}

/* Separate function for piped input to avoid stack corruption issues */
static int read_piped_input_line(byte *buffer, int max_length) {
    char temp_buffer[256];
    static int is_interactive = -1; /* Cache the result */
    
    if (buffer == NULL || max_length == 0) {
        return 0;
    }
    
    /* Check if interactive on first call */
    if (is_interactive == -1) {
        is_interactive = is_stdin_interactive();
    }
    
    /* Show prompt for interactive mode */
    if (is_interactive) {
        printf("> ");
        fflush(stdout);
    }
    
    if (fgets(temp_buffer, sizeof(temp_buffer), stdin) != NULL) {
        size_t len = strlen(temp_buffer);
        
        /* Remove trailing newline */
        if (len > 0 && temp_buffer[len-1] == '\n') {
            temp_buffer[len-1] = '\0';
            len--;
        }
        
        /* Copy to output buffer */
        if (len > 0 && len < (size_t)max_length) {
            memcpy(buffer, temp_buffer, len + 1);
            
            /* Save for simple game engine */
            strncpy(g_last_command_line, temp_buffer, sizeof(g_last_command_line) - 1);
            g_last_command_line[sizeof(g_last_command_line) - 1] = '\0';
            
            /* Echo command only for piped input (for logs) */
            if (!is_interactive) {
                printf("> %s\n", temp_buffer);
                fflush(stdout);
            }
            
            /* Debug info to stderr */
            fprintf(stderr, "read_piped_input_line: Read \"%s\" (len=%d, interactive=%d)\n", 
                    temp_buffer, (int)len, is_interactive);
            fflush(stderr);
            return (int)len;
        } else if (len == 0) {
            buffer[0] = '\0';
            return 0;
        } else {
            /* Truncate if too long */
            memcpy(buffer, temp_buffer, max_length - 1);
            buffer[max_length - 1] = '\0';
            return max_length - 1;
        }
    }
    
    /* EOF or error */
    buffer[0] = '\0';
    return 0;
}

undefined2 get_input_line_wrapper(void) {
    /* Check if stdin is piped - use separate function to avoid stack corruption */
    #ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD dwMode = 0;
    BOOL is_console = (hStdin != INVALID_HANDLE_VALUE && GetConsoleMode(hStdin, &dwMode));
    
    if (!is_console) {
        /* Use piped input function with MEM_BUFFER_STORAGE */
        if (g_gameState != NULL && g_gameState->memory_pool != NULL) {
            byte *buffer = (byte *)(g_gameState->memory_pool + MEM_BUFFER_STORAGE);
            int len = read_piped_input_line(buffer, 256);
            fprintf(stderr, "get_input_line_wrapper: Piped input returned %d\n", len);
            fflush(stderr);
            return (undefined2)len;
        }
        return 0;
    }
    #endif
    
    /* Console mode - use normal function */
    return get_input_line(NULL, 0);
}

undefined2 execute_command_wrapper(uint *param_1, int param_2, int param_3, int param_4) {
    UNUSED(param_3);
    UNUSED(param_4);
    return execute_command(param_1, param_2);
}

/* FUN_1000_03a6_wrapper is defined later with correct signature */

int* handle_location_change_wrapper(int *param_1) {
    undefined2 result = handle_location_change((undefined2)(uintptr_t)param_1);
    return (int*)(uintptr_t)result;
}

undefined2 handle_special_command_wrapper(void) {
    /* In DOS, command ID would be passed via register */
    /* Return 0 to indicate no special command handled */
    log_debug("handle_special_command_wrapper: Called with command ID 0");
    return 0; /* No special command */
}

int check_command_conditions_wrapper(void) {
    /* FIXED: Allocate a result buffer in memory pool since check_command_conditions needs it */
    if (g_gameState == NULL || g_gameState->memory_pool == NULL) {
        return 0;
    }
    
    /* Allocate result buffer at a safe offset */
    uint32_t result_offset = 0x7B00; /* Use safe offset for result buffer */
    if (result_offset + 256 > g_gameState->memory_pool_size) {
        return 0; /* Not enough space */
    }
    
    /* Initialize result buffer to zeros */
    memset(g_gameState->memory_pool + result_offset, 0, 256);
    
    uint* result = (uint*)(g_gameState->memory_pool + result_offset);
    uint* string_result = check_command_conditions(NULL, 0, 0, result);
    
    /* Return non-zero if string_result is valid, 0 if NULL */
    if (string_result == NULL) {
        return 0;
    }
    
    /* Check if string_result points to a valid location in memory pool */
    uintptr_t string_offset = (uintptr_t)string_result - (uintptr_t)g_gameState->memory_pool;
    if (string_offset >= g_gameState->memory_pool_size) {
        return 0;
    }
    
    return (int)(uintptr_t)string_result;
}

int process_game_action_wrapper(void) {
    /* In DOS, action data would be passed via register */
    /* Return 0 to indicate no action processed */
    log_debug("process_game_action_wrapper: Called with no action data (NULL)");
    return 0;
}

int parse_command_input_wrapper(void) {
    /* When stdin is piped, input is in MEM_BUFFER_STORAGE, so use that as input_buffer */
    #ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD dwMode = 0;
    BOOL is_console = (hStdin != INVALID_HANDLE_VALUE && GetConsoleMode(hStdin, &dwMode));
    
    fprintf(stderr, "parse_command_input_wrapper: is_console=%d\n", is_console);
    fflush(stderr);
    
    if (!is_console) {
        /* Piped input - use MEM_BUFFER_STORAGE as input_buffer */
        /* parse_command_input(token_buffer, input_buffer) */
        fprintf(stderr, "parse_command_input_wrapper: Using MEM_BUFFER_STORAGE (0x%x) as input_buffer, MEM_COMMAND_BUFFER (0x%x) as token_buffer\n", MEM_BUFFER_STORAGE, MEM_COMMAND_BUFFER);
        fflush(stderr);
        return parse_command_input(MEM_COMMAND_BUFFER, MEM_BUFFER_STORAGE);
    }
    #endif
    
    /* Console input - use 0 (will be filled by get_input_line) */
    fprintf(stderr, "parse_command_input_wrapper: Using 0 as input_buffer (console mode)\n");
    fflush(stderr);
    return parse_command_input(0, 0);
}

int find_matching_objects_wrapper(uint param_1) {
    return find_matching_objects((byte*)(uintptr_t)param_1, 0, 0);
}

undefined2 match_game_objects_wrapper(uint *param_1, uint *param_2) {
    /* Third parameter (result buffer) would be passed via register in DOS */
    /* Allocate a temporary result buffer in memory pool if available */
    if (g_gameState != NULL && g_gameState->memory_pool != NULL) {
        uint32_t temp_buffer_offset = 0x7C00; /* Safe temp buffer location */
        if (temp_buffer_offset + 256 <= g_gameState->memory_pool_size) {
            uint *temp_result = (uint*)(g_gameState->memory_pool + temp_buffer_offset);
            return match_game_objects(param_1, param_2, temp_result);
        }
    }
    /* Fallback: return 0 if can't allocate temp buffer */
    log_debug("match_game_objects_wrapper: No temp buffer available, returning 0");
    return 0;
}

int process_command_parameters_wrapper_5(uint *param_1, int param_2, int param_3, uint *param_4, uint *param_5) {
    /* Original call has 5 params, but function takes 4 - ignoring 5th param */
    return process_command_parameters(param_1, param_2, param_3, (int)(uintptr_t)param_4);
}

int find_objects_in_location_wrapper_2(uint param_1, uint param_2) {
    return find_objects_in_location((byte*)(uintptr_t)param_1, param_2, 0, 0);
}

int find_objects_in_location_wrapper_3(byte *param_1, uint param_2, uint param_3) {
    return find_objects_in_location(param_1, param_2, param_3, 0);
}

void print_string_wrapper_1(int param_1) {
    /* In DOS, text pointer would be passed via register */
    /* For now, output window-specific text marker */
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "[Window %d output]\n", param_1);
    DisplayPrint(buffer);
    fflush(stdout);
}

char* format_string_wrapper_4(char *param_1, int param_2, char **param_3, char *param_4) {
    /* Original call has 4 params, but function takes 3 - ignoring 4th param */
    return format_string(param_1, (char*)(uintptr_t)param_2, param_3);
}

int process_commands_wrapper(void) {
    return process_commands(0, 0);
}

void copy_string_data_wrapper_0(void) {
    /* In DOS, source and dest pointers would be passed via registers */
    /* No-op since we have no valid pointers */
    log_debug("copy_string_data_wrapper_0: Called with NULL source and dest");
    /* Do nothing - no valid data to copy */
}

void copy_string_data_wrapper_1(undefined2 *param_1) {
    /* In DOS, dest pointer would be passed via register */
    /* No-op since we have no valid dest pointer */
    log_debug("copy_string_data_wrapper_1: Called with NULL dest");
    /* Do nothing - no valid destination to copy to */
}

int string_length_wrapper_int(int param_1) {
    return string_length((char*)(uintptr_t)param_1);
}

extern void setup_display_window(int param_1, int param_2);
void setup_display_window_wrapper(void) {
    /* No-op in Windows mode - display is handled by modern APIs */
    /* The DOS display window setup causes ACCESS_VIOLATION exceptions */
    /* and isn't needed for automated testing */
    return;
}

extern byte* convert_number_to_string(uint number, byte *buffer, uint base);
byte* convert_number_to_string_safe(uint number, byte *buffer, uint base) {
    /* Validate parameters to prevent divide-by-zero and NULL pointer access */
    if (base == 0 || buffer == NULL) {
        log_debug("convert_number_to_string_safe: Invalid params (base=%u, buffer=%p), returning NULL", base, (void*)buffer);
        return NULL;
    }
    return convert_number_to_string(number, buffer, base);
}

extern int parse_command_input(int token_buffer, int input_buffer);
int parse_command_input_wrapper_2(int token_buffer, int input_buffer) {
    return parse_command_input(token_buffer, input_buffer);
}

extern void display_inventory(void);
undefined2 display_inventory_wrapper(void) {
    display_inventory();
    return 0;
}

extern void refresh_display(undefined2 param_1, undefined2 param_2);
void refresh_display_wrapper_1(undefined2 param_1) {
    refresh_display(param_1, 0);
}

extern int display_message(uint param_1);
int display_message_wrapper_0(void) {
    /* No-op: Simple game engine now provides all output */
    /* This wrapper is called during command processing but we handle */
    /* display in the simple game engine layer instead */
    return 1; /* Return success */
}

int display_message_wrapper_2(uint param_1, uint param_2) {
    #ifdef _WIN32
    __try {
        return display_message(param_1);
    } __except(EXCEPTION_EXECUTE_HANDLER) {
        log_exception_details(GetExceptionCode(), "display_message_wrapper_2: display_message", __FILE__, __LINE__);
        return 0; /* Return 0 on exception - non-fatal */
    }
    #else
    return display_message(param_1);
    #endif
}

int display_message_wrapper_3(uint param_1, uint param_2, uint param_3) {
    return display_message(param_1);
}

extern undefined2 report_error(undefined2 param_1);
undefined2 report_error_wrapper_2(undefined2 param_1, uint param_2) {
    return report_error(param_1);
}

undefined2 report_error_wrapper_3(undefined2 param_1, uint param_2, uint param_3) {
    return report_error(param_1);
}

extern void move_object_between_locations(uint param_1, int param_2, int param_3);
void move_object_between_locations_wrapper_2(uint param_1, int param_2) {
    move_object_between_locations(param_1, param_2, 0);
}

/* Additional wrapper functions for parameter mismatches */
extern uint find_matching_objects(byte *param_1, uint param_2, int param_3);
uint find_matching_objects_wrapper_0(void) {
    /* In DOS, search criteria would be passed via register */
    /* Return 0 to indicate no objects found */
    log_debug("find_matching_objects_wrapper_0: Called with no search criteria (NULL)");
    return 0;
}

extern undefined2 report_error(undefined2 param_1);
undefined2 report_error_wrapper_0(void) {
    /* In DOS, error code would be passed via register */
    /* Return 0 to indicate no error or generic error */
    log_debug("report_error_wrapper_0: Called with error code 0");
    return 0;
}

/* is_object_in_inventory declaration - defined in skull_ported.c with bool return */
extern bool is_object_in_inventory(uint param_1);
undefined2 is_object_in_inventory_wrapper_0(void) {
    /* In DOS, object ID would be passed via register */
    /* Return 0 (false) to indicate object 0 not in inventory */
    log_debug("is_object_in_inventory_wrapper_0: Called with object ID 0");
    return 0; /* Object not found */
}

extern undefined2 take_object(uint param_1, int param_2);
undefined2 take_object_wrapper_0(void) {
    /* In DOS, object ID would be passed via register */
    /* Return 0 to indicate failure to take object 0 */
    log_debug("take_object_wrapper_0: Called with object ID 0");
    return 0; /* Operation failed */
}

undefined2 take_object_wrapper_1(uint param_1) {
    return take_object(param_1, 0);
}

extern void display_formatted_message(undefined2 param_1, uint param_2);
void display_formatted_message_wrapper_0(void) {
    /* In DOS, message ID and value would be passed via registers */
    /* For now, output a generic formatted response */
    DisplayPrint("[Formatted message]\n");
    fflush(stdout);
}

void display_formatted_message_wrapper_3(undefined2 param_1, uint param_2, uint param_3) {
    UNUSED(param_3);
    display_formatted_message(param_1, param_2);
}

extern undefined2 handle_object_command(int param_1, undefined2 param_2);
undefined2 handle_object_command_wrapper_3(int param_1, undefined2 param_2, int param_3) {
    UNUSED(param_3);
    return handle_object_command(param_1, param_2);
}

extern undefined2 handle_put_command(int param_1, undefined2 param_2);
undefined2 handle_put_command_wrapper_3(int param_1, undefined2 param_2, undefined2 param_3) {
    UNUSED(param_3);
    return handle_put_command(param_1, param_2);
}

extern undefined2 handle_object_interaction(int param_1, int param_2, undefined2 param_3);
undefined2 handle_object_interaction_wrapper_2(int param_1, int param_2) {
    return handle_object_interaction(param_1, param_2, 0);
}

undefined2 handle_object_interaction_wrapper_4(int param_1, int param_2, undefined2 param_3, int param_4) {
    UNUSED(param_4);
    return handle_object_interaction(param_1, param_2, param_3);
}

extern void display_item_list(uint param_1);
void display_item_list_wrapper_0(void) {
    /* In DOS, list ID would be passed via register */
    /* For now, output a placeholder */
    DisplayPrint("[Item list]\n");
    fflush(stdout);
    log_debug("display_item_list_wrapper_0: Called with list ID 0");
}

extern void clear_display_line(int param_1);
void clear_display_line_wrapper_0(void) {
    /* In DOS, line number would be passed via register */
    /* For now, just clear line 0 (top line) - this may be correct default */
    log_debug("clear_display_line_wrapper_0: Clearing line 0");
    clear_display_line(0);
}

extern void call_interrupt_by_id(undefined2 param_1);
void call_interrupt_by_id_wrapper_0(void) {
    /* In DOS, interrupt ID would be passed via register */
    /* Call with ID 0 - may be no-op on Windows */
    log_debug("call_interrupt_by_id_wrapper_0: Called with interrupt ID 0");
    call_interrupt_by_id(0);
}

extern void flush_file_buffers(void);
void flush_file_buffers_wrapper_1(int param_1) {
    UNUSED(param_1);
    flush_file_buffers();
}

extern void handle_dos_interrupt(undefined2 param_1);
void handle_dos_interrupt_wrapper_0(void) {
    /* In DOS, interrupt ID would be passed via register */
    /* Call with ID 0 - may be no-op on Windows */
    log_debug("handle_dos_interrupt_wrapper_0: Called with interrupt ID 0");
    handle_dos_interrupt(0);
}

extern void allocate_memory_block(void);
void allocate_memory_block_wrapper_2(int param_1, void *param_2) {
    UNUSED(param_1);
    UNUSED(param_2);
    allocate_memory_block();
}

extern void display_item_details(byte *param_1);
undefined2 display_item_details_wrapper_1(byte *param_1) {
    display_item_details(param_1);
    return 0;
}

extern int process_command_parameters(uint *params, int count, int offset, int result_ptr);
int process_command_parameters_wrapper(uint params) {
    return process_command_parameters((uint*)(uintptr_t)params, 0, 0, 0);
}

/* Forward declarations for functions with different signatures */
extern bool is_object_in_inventory(uint param_1);
undefined2 is_object_in_inventory_wrapper_1(uint param_1) {
    return (undefined2)is_object_in_inventory(param_1);
}

extern void refresh_display(undefined2 param_1, undefined2 param_2);
void refresh_display_wrapper_0(void) {
    refresh_display(0, 0);
}

extern undefined2 is_format_char(char param_1);
undefined2 is_format_char_wrapper_0(void) {
    /* In DOS, character would be passed via register */
    /* Return result for character 0 (null) - likely returns false */
    log_debug("is_format_char_wrapper_0: Called with char 0");
    return is_format_char(0);
}

extern void format_float_output(int param_1);
void format_float_output_wrapper_0(void) {
    /* In DOS, value would be passed via register */
    /* Format 0 as default - may be reasonable fallback */
    log_debug("format_float_output_wrapper_0: Called with value 0");
    format_float_output(0);
}

extern void output_format_char(uint param_1);
void output_format_char_wrapper_0(void) {
    output_format_char(0);
}

extern void format_string_output(int length);
void format_string_output_wrapper_0(void) {
    format_string_output(0);
}

extern void output_format_string(byte *str, int length);
void output_format_string_wrapper_0(void) {
    output_format_string(NULL, 0);
}

void output_format_string_wrapper_1(byte *param_1) {
    output_format_string(param_1, 0);
}

void output_format_string_wrapper_3(byte *param_1, uint param_2, int param_3) {
    UNUSED(param_3);
    output_format_string(param_1, (int)param_2);
}

extern int* process_game_action(int *action_data);
int* process_game_action_wrapper_int(int action_data) {
    return process_game_action((int*)(uintptr_t)action_data);
}

extern void format_number_output(int param_1);
void format_number_output_wrapper_0(void) {
    format_number_output(0);
}

/* ============================================================================
 * Logging and Error Handling Implementation
 * ============================================================================ */

/* Set default log level to WARNING to reduce verbosity during file loading */
static LogLevel g_log_level = LOG_LEVEL_WARNING;
static ErrorCode g_last_error = SKULL_ERROR_NONE;

void log_set_level(LogLevel level) {
    g_log_level = level;
    // log_info("Log level set to %d", level);
}

LogLevel log_get_level(void) {
    return g_log_level;
}

static void log_message(LogLevel level, const char* prefix, const char* format, va_list args) {
    if (level > g_log_level) {
        return;
    }
    
    /* Skip if format string is NULL or empty (avoid empty log lines) */
    if (format == NULL || format[0] == '\0') {
        return;
    }
    
    /* Check if the formatted message would be empty after processing */
    /* Do this BEFORE initializing log file or printing timestamp to avoid empty log lines */
    va_list args_copy;
    va_copy(args_copy, args);
    
    /* Try to format into a temporary buffer to check if it's empty */
    char temp_buffer[1024];
    int formatted_len = vsnprintf(temp_buffer, sizeof(temp_buffer), format, args_copy);
    
    /* Skip if formatted message is empty or just whitespace */
    if (formatted_len <= 0) {
        va_end(args_copy);
        return;
    }
    
    /* Trim whitespace and check if empty */
    int start = 0;
    int end = formatted_len - 1;
    while (start <= end && (temp_buffer[start] == ' ' || temp_buffer[start] == '\t' || temp_buffer[start] == '\n' || temp_buffer[start] == '\r')) {
        start++;
    }
    while (end >= start && (temp_buffer[end] == ' ' || temp_buffer[end] == '\t' || temp_buffer[end] == '\n' || temp_buffer[end] == '\r')) {
        end--;
    }
    
    if (start > end) {
        /* Message is all whitespace - skip it */
        va_end(args_copy);
        return;
    }
    
    /* Initialize log file if not already done */
    if (g_log_file == NULL) {
        init_log_file();
    }
    
    time_t now;
    time(&now);
    struct tm* timeinfo = localtime(&now);
    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    /* Reset va_list for actual output */
    va_end(args_copy);
    
    /* Write to stderr */
    fprintf(stderr, "[%s] [%s] ", timestamp, prefix);
    va_copy(args_copy, args);
    vfprintf(stderr, format, args_copy);
    va_end(args_copy);
    fprintf(stderr, "\n");
    fflush(stderr);
    
    /* Write to log file */
    if (g_log_file != NULL) {
        fprintf(g_log_file, "[%s] [%s] ", timestamp, prefix);
        vfprintf(g_log_file, format, args_copy);
        fprintf(g_log_file, "\n");
        fflush(g_log_file);
    }
    va_end(args_copy);
}

void log_error(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_LEVEL_ERROR, "ERROR", format, args);
    va_end(args);
}

void log_warning(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_LEVEL_WARNING, "WARN", format, args);
    va_end(args);
}

void log_info(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_LEVEL_INFO, "INFO", format, args);
    va_end(args);
}

void log_debug(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_LEVEL_DEBUG, "DEBUG", format, args);
    va_end(args);
}

void log_verbose(const char* format, ...) {
    va_list args;
    va_start(args, format);
    log_message(LOG_LEVEL_VERBOSE, "VERBOSE", format, args);
    va_end(args);
}

const char* error_code_to_string(ErrorCode error_code) {
    switch (error_code) {
        case SKULL_ERROR_NONE: return "No error";
        case SKULL_ERROR_FILE_NOT_FOUND: return "File not found";
        case SKULL_ERROR_FILE_ACCESS_DENIED: return "File access denied";
        case SKULL_ERROR_FILE_READ_FAILED: return "File read failed";
        case SKULL_ERROR_FILE_WRITE_FAILED: return "File write failed";
        case SKULL_ERROR_FILE_SEEK_FAILED: return "File seek failed";
        case SKULL_ERROR_MEMORY_ALLOCATION_FAILED: return "Memory allocation failed";
        case SKULL_ERROR_MEMORY_POOL_FULL: return "Memory pool full";
        case SKULL_ERROR_INVALID_HANDLE: return "Invalid handle";
        case SKULL_ERROR_INVALID_PARAMETER: return "Invalid parameter";
        case SKULL_ERROR_GAME_STATE_NOT_INITIALIZED: return "Game state not initialized";
        case SKULL_ERROR_FILE_ALREADY_OPEN: return "File already open";
        case SKULL_ERROR_FILE_NOT_OPEN: return "File not open";
        case SKULL_ERROR_UNKNOWN: return "Unknown error";
        default: return "Invalid error code";
    }
}

void log_error_with_code(ErrorCode error_code, const char* context, const char* details) {
    log_error("%s: %s (%s)", context, error_code_to_string(error_code), details ? details : "No details");
}

ErrorCode get_last_error(void) {
    return g_last_error;
}

void set_last_error(ErrorCode error_code) {
    g_last_error = error_code;
    if (error_code != SKULL_ERROR_NONE) {
        log_debug("Error set: %s", error_code_to_string(error_code));
    }
}

void clear_last_error(void) {
    g_last_error = SKULL_ERROR_NONE;
}

const char* windows_error_to_string(DWORD error_code) {
    static char error_buffer[256];
    DWORD result = FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        error_code,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        error_buffer,
        sizeof(error_buffer),
        NULL
    );
    
    if (result == 0) {
        snprintf(error_buffer, sizeof(error_buffer), "Windows error code %lu", error_code);
    } else {
        /* Remove trailing newlines */
        size_t len = strlen(error_buffer);
        while (len > 0 && (error_buffer[len-1] == '\n' || error_buffer[len-1] == '\r')) {
            error_buffer[--len] = '\0';
        }
    }
    
    return error_buffer;
}

void log_windows_error(const char* context, DWORD error_code) {
    const char* error_msg = windows_error_to_string(error_code);
    log_error("%s: Windows error %lu - %s", context, error_code, error_msg);
}

/* Enhanced exception logging with detailed information */
/* Note: exception_code must be obtained via GetExceptionCode() within the __except handler */
void log_exception_details(DWORD exception_code, const char* function_name, const char* file, int line) {
    const char* exception_name = "Unknown";
    
    /* Map exception codes to human-readable names */
    switch (exception_code) {
        case EXCEPTION_ACCESS_VIOLATION:
            exception_name = "ACCESS_VIOLATION (Invalid memory access)";
            break;
        case EXCEPTION_INT_DIVIDE_BY_ZERO:
            exception_name = "INT_DIVIDE_BY_ZERO (Division by zero)";
            break;
        case EXCEPTION_FLT_DIVIDE_BY_ZERO:
            exception_name = "FLT_DIVIDE_BY_ZERO (Floating point divide by zero)";
            break;
        case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
            exception_name = "ARRAY_BOUNDS_EXCEEDED (Array bounds exceeded)";
            break;
        case EXCEPTION_ILLEGAL_INSTRUCTION:
            exception_name = "ILLEGAL_INSTRUCTION (Illegal instruction)";
            break;
        case EXCEPTION_IN_PAGE_ERROR:
            exception_name = "IN_PAGE_ERROR (Page fault)";
            break;
        case EXCEPTION_STACK_OVERFLOW:
            exception_name = "STACK_OVERFLOW (Stack overflow)";
            break;
        case EXCEPTION_BREAKPOINT:
            exception_name = "BREAKPOINT (Breakpoint hit)";
            break;
        default:
            exception_name = "UNKNOWN";
            break;
    }
    
    /* Log to file */
    log_error("%s: Exception 0x%08lX (%s) at %s:%d", 
              function_name, exception_code, exception_name, file, line);
    
    /* Also output to stderr for immediate visibility */
    fprintf(stderr, "[EXCEPTION] %s: 0x%08lX (%s) at %s:%d\n", 
            function_name, exception_code, exception_name, file, line);
    fflush(stderr);
    
    /* In debug builds, break into debugger for critical exceptions */
    #ifdef _DEBUG
    if (exception_code == EXCEPTION_ACCESS_VIOLATION ||
        exception_code == EXCEPTION_INT_DIVIDE_BY_ZERO ||
        exception_code == EXCEPTION_ILLEGAL_INSTRUCTION ||
        exception_code == EXCEPTION_STACK_OVERFLOW) {
        fprintf(stderr, "[DEBUG] Breaking into debugger for critical exception...\n");
        fflush(stderr);
        DebugBreak();  /* Breaks into debugger if one is attached */
    }
    #endif
}

/* ===================================================================
 * Parameter Validation Helpers
 * =================================================================== */

/* Validate a pointer is not NULL and potentially accessible */
bool validate_pointer(const void* ptr, const char* param_name, const char* function_name) {
    if (ptr == NULL) {
        log_error("%s: NULL pointer for parameter '%s'", function_name, param_name);
        return false;
    }
    
    /* On Windows, we can't safely check pointer validity without accessing it,
     * so we just check for NULL. The exception handler will catch invalid accesses. */
    return true;
}

/* Validate a memory offset is within bounds of the memory pool */
bool validate_memory_offset(uint32_t offset, size_t size, const char* param_name, const char* function_name) {
    if (g_gameState == NULL || g_gameState->memory_pool == NULL) {
        log_error("%s: Game state not initialized for parameter '%s'", function_name, param_name);
        return false;
    }
    
    /* Check for overflow in addition - use uintptr_t to handle large offsets */
    uintptr_t total_size = (uintptr_t)offset + (uintptr_t)size;
    if (total_size < (uintptr_t)offset) {
        /* Overflow occurred */
        log_error("%s: Memory offset overflow for parameter '%s' (offset=0x%x, size=%zu)", 
                  function_name, param_name, offset, size);
        return false;
    }
    
    if (offset + size > g_gameState->memory_pool_size) {
        log_error("%s: Memory offset out of bounds for parameter '%s' (offset=0x%x, size=%zu, pool_size=%zu)", 
                  function_name, param_name, offset, size, g_gameState->memory_pool_size);
        return false;
    }
    
    return true;
}

/* Validate a DOS file handle is valid */
bool validate_file_handle(uint dos_handle, const char* param_name, const char* function_name) {
    if (dos_handle >= MAX_DOS_FILE_HANDLES) {
        log_error("%s: Invalid file handle for parameter '%s' (handle=%u, max=%d)", 
                  function_name, param_name, dos_handle, MAX_DOS_FILE_HANDLES);
        return false;
    }
    
    HANDLE win_handle = get_windows_file_handle(dos_handle);
    if (win_handle == INVALID_HANDLE_VALUE) {
        log_error("%s: File handle %u for parameter '%s' is not open", 
                  function_name, dos_handle, param_name);
        return false;
    }
    
    return true;
}

/* Validate a string pointer and length */
bool validate_string(const char* str, size_t max_len, const char* param_name, const char* function_name) {
    if (str == NULL) {
        log_error("%s: NULL string pointer for parameter '%s'", function_name, param_name);
        return false;
    }
    
    /* Try to validate string length if max_len is specified */
    if (max_len > 0) {
        size_t len = strnlen(str, max_len);
        if (len >= max_len) {
            log_warning("%s: String for parameter '%s' may be unterminated (max_len=%zu)", 
                       function_name, param_name, max_len);
            /* Not necessarily an error, just a warning */
        }
    }
    
    return true;
}

/* Validate game state is initialized */
bool validate_game_state(const char* function_name) {
    if (g_gameState == NULL) {
        log_error("%s: Game state is NULL", function_name);
        set_last_error(SKULL_ERROR_GAME_STATE_NOT_INITIALIZED);
        return false;
    }
    
    if (g_gameState->memory_pool == NULL) {
        log_error("%s: Memory pool is NULL", function_name);
        set_last_error(SKULL_ERROR_GAME_STATE_NOT_INITIALIZED);
        return false;
    }
    
    return true;
}

/* ===================================================================
 * Error Context Tracking
 * =================================================================== */

#define MAX_ERROR_CONTEXT_STACK 16
static ErrorContext g_error_context_stack[MAX_ERROR_CONTEXT_STACK];
static int g_error_context_stack_top = -1;

void push_error_context(ErrorCode code, const char* function_name, const char* context) {
    if (g_error_context_stack_top < MAX_ERROR_CONTEXT_STACK - 1) {
        g_error_context_stack_top++;
        g_error_context_stack[g_error_context_stack_top].error_code = code;
        g_error_context_stack[g_error_context_stack_top].function_name = function_name;
        g_error_context_stack[g_error_context_stack_top].context_message = context;
        g_error_context_stack[g_error_context_stack_top].line_number = 0; /* Could use __LINE__ macro if needed */
        g_error_context_stack[g_error_context_stack_top].windows_error = 0;
    } else {
        log_warning("Error context stack overflow - discarding context");
    }
}

ErrorContext* pop_error_context(void) {
    if (g_error_context_stack_top >= 0) {
        ErrorContext* ctx = &g_error_context_stack[g_error_context_stack_top];
        g_error_context_stack_top--;
        return ctx;
    }
    return NULL;
}

ErrorContext* get_current_error_context(void) {
    if (g_error_context_stack_top >= 0) {
        return &g_error_context_stack[g_error_context_stack_top];
    }
    return NULL;
}

void clear_error_context_stack(void) {
    g_error_context_stack_top = -1;
}

/* ===================================================================
 * User-Friendly Error Messages
 * =================================================================== */

const char* get_user_friendly_error_message(ErrorCode code) {
    switch (code) {
        case SKULL_ERROR_NONE:
            return "No error occurred.";
        case SKULL_ERROR_FILE_NOT_FOUND:
            return "The game file could not be found. Please ensure all game files (SKULL.M, SKULL.X, etc.) are in the game directory.";
        case SKULL_ERROR_FILE_ACCESS_DENIED:
            return "Access to the game file was denied. Please check file permissions.";
        case SKULL_ERROR_FILE_READ_FAILED:
            return "Failed to read from game file. The file may be corrupted or in use by another program.";
        case SKULL_ERROR_FILE_WRITE_FAILED:
            return "Failed to write to game file. The disk may be full or the file may be read-only.";
        case SKULL_ERROR_FILE_SEEK_FAILED:
            return "Failed to seek within game file. The file may be corrupted.";
        case SKULL_ERROR_MEMORY_ALLOCATION_FAILED:
            return "Memory allocation failed. You may be low on system memory. Please close other applications and try again.";
        case SKULL_ERROR_MEMORY_POOL_FULL:
            return "Game memory pool is full. This may indicate a memory leak or insufficient memory allocation.";
        case SKULL_ERROR_INVALID_HANDLE:
            return "Invalid file handle. The file operation failed because the file handle is not valid.";
        case SKULL_ERROR_INVALID_PARAMETER:
            return "Invalid parameter provided to game function. This is an internal error.";
        case SKULL_ERROR_GAME_STATE_NOT_INITIALIZED:
            return "Game state not initialized. The game may not have started properly.";
        case SKULL_ERROR_FILE_ALREADY_OPEN:
            return "File is already open. Cannot open the same file twice.";
        case SKULL_ERROR_FILE_NOT_OPEN:
            return "File is not open. Cannot perform file operation on closed file.";
        case SKULL_ERROR_UNKNOWN:
        default:
            return "An unknown error occurred. Please check the log file for details.";
    }
}

void log_user_error(ErrorCode code, const char* operation, const char* details) {
    const char* friendly_msg = get_user_friendly_error_message(code);
    log_error("[USER ERROR] Operation: %s | Error: %s | Details: %s", 
              operation ? operation : "Unknown", friendly_msg, details ? details : "None");
    fprintf(stderr, "\n[ERROR] %s\n", friendly_msg);
    if (operation) {
        fprintf(stderr, "  Operation: %s\n", operation);
    }
    if (details) {
        fprintf(stderr, "  Details: %s\n", details);
    }
    fflush(stderr);
}

void display_user_error(ErrorCode code, const char* operation) {
    const char* friendly_msg = get_user_friendly_error_message(code);
    
    /* Log to file */
    log_error("[DISPLAY ERROR] %s: %s", operation ? operation : "Error", friendly_msg);
    
    /* Display to user on stderr (console) */
    fprintf(stderr, "\n=== ERROR ===\n");
    fprintf(stderr, "%s\n", friendly_msg);
    if (operation) {
        fprintf(stderr, "Operation: %s\n", operation);
    }
    fprintf(stderr, "Error Code: %d (%s)\n", code, error_code_to_string(code));
    fprintf(stderr, "=============\n\n");
    fflush(stderr);
}

/* ===================================================================
 * Error Recovery Mechanisms
 * =================================================================== */

bool try_recover_from_error(ErrorCode code, RecoveryStrategy strategy, int max_retries) {
    static int retry_counts[MAX_ERROR_CONTEXT_STACK] = {0};
    static ErrorCode last_error = SKULL_ERROR_NONE;
    
    if (code != last_error) {
        /* New error - reset retry count */
        memset(retry_counts, 0, sizeof(retry_counts));
        last_error = code;
    }
    
    switch (strategy) {
        case RECOVERY_RETRY:
            if (retry_counts[0] < max_retries) {
                retry_counts[0]++;
                log_info("Retrying operation (attempt %d/%d) after error: %s", 
                         retry_counts[0], max_retries, error_code_to_string(code));
                Sleep(100); /* Brief delay before retry */
                return true;
            } else {
                log_error("Max retries (%d) exceeded for error: %s", max_retries, error_code_to_string(code));
                return false;
            }
            
        case RECOVERY_FALLBACK:
            log_info("Attempting fallback recovery for error: %s", error_code_to_string(code));
            /* Fallback strategies would be implemented based on specific error type */
            return true;
            
        case RECOVERY_SKIP:
            log_warning("Skipping operation due to error: %s", error_code_to_string(code));
            return true; /* Skip is considered successful */
            
        case RECOVERY_FAIL:
        default:
            log_error("Operation failed with no recovery strategy for error: %s", error_code_to_string(code));
            return false;
    }
}

bool validate_and_recover(const char* operation, bool (*validate_func)(void*), void* param, RecoveryStrategy strategy) {
    if (validate_func == NULL) {
        log_error("validate_and_recover: NULL validation function for operation: %s", operation);
        return false;
    }
    
    if (!validate_func(param)) {
        ErrorCode error = get_last_error();
        if (error == SKULL_ERROR_NONE) {
            set_last_error(SKULL_ERROR_INVALID_PARAMETER);
        }
        return try_recover_from_error(error, strategy, 3); /* Default 3 retries */
    }
    
    return true;
}

/* Helper functions for bit manipulation and arithmetic operations */
/* Note: CONCAT11, CONCAT22, CARRY2, SBORROW2, and ZEXT24 are defined as macros in dos_compat.h */
/* Only POPCOUNT fallback function is needed here */

/* POPCOUNT: Population count (number of set bits) - fallback implementation */
/* Note: This function is only used if compiler intrinsics are not available */
int popcount_fallback(uint32_t value) {
    int count = 0;
    while (value != 0) {
        count += (value & 1);
        value >>= 1;
    }
    return count;
}

/* Restore warning settings */
#pragma warning(pop)

