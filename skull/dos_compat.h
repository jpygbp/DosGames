/* DOS Compatibility Layer for 64-bit Windows
 * Converts 16-bit DOS types and functions to Windows equivalents
 */

#ifndef DOS_COMPAT_H
#define DOS_COMPAT_H

/* Debug logging control - define to enable verbose debug output */
/* Comment out or set to 0 for production builds to reduce overhead */
#ifndef ENABLE_DEBUG_LOGGING
#define ENABLE_DEBUG_LOGGING 0  /* 1 = enabled, 0 = disabled */
#endif

/* Windows 11 Compatibility: Target Windows 10/11 APIs */
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00  /* Windows 10 / Windows Server 2016 */
#endif
#ifndef WINVER
#define WINVER 0x0A00        /* Windows 10 / Windows Server 2016 */
#endif

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#ifdef _MSC_VER
#include <intrin.h>
#endif

/* Windows 11: Enable long path support (paths > 260 characters) */
#ifndef PATHCCH_MAX_CCH
#define PATHCCH_MAX_CCH 0x8000  /* 32767 characters for long paths */
#endif

/* Type definitions - convert 16-bit DOS types to modern equivalents */
typedef uint16_t undefined2;  // 16-bit unsigned (was 16-bit in DOS)
typedef uint32_t undefined4; // 32-bit unsigned (was 32-bit in DOS)
typedef uint8_t undefined;    // 8-bit unsigned
typedef uint32_t uint;        // 32-bit unsigned
typedef int32_t int32;        // 32-bit signed
typedef uint8_t byte;         // 8-bit unsigned byte
typedef unsigned long ulong;  // 64-bit unsigned long
typedef void (*interrupt_handler)(void);   // Function pointer type for interrupt handlers
typedef void (*code)(void);   // Function pointer type from decompiled code

/* Remove DOS-specific calling conventions */
#define __cdecl16near
#define __cdecl16far
#define __far
#define __near

/* Memory addressing - replace absolute addresses with proper structures */
/* In DOS, addresses like 0xbc were absolute memory locations */
/* We'll use a global data structure to simulate this */

typedef struct {
    /* Game state variables - mapped from original DOS addresses */
    uint32_t var_bc;          /* Original: 0xbc */
    uint32_t var_cc;          /* Original: 0xcc */
    uint32_t var_ce;          /* Original: 0xce */
    uint32_t var_d0;          /* Original: 0xd0 */
    uint32_t var_d2;          /* Original: 0xd2 */
    uint32_t var_d4;          /* Original: 0xd4 */
    uint32_t var_e6;          /* Original: 0xe6 */
    uint32_t var_ec;          /* Original: 0xec */
    
    /* Extended memory areas */
    uint32_t var_1080;        /* Original: 0x1080 */
    uint32_t var_1082;        /* Original: 0x1082 */
    uint32_t var_1084;        /* Original: 0x1084 */
    uint32_t var_10e6;        /* Original: 0x10e6 */
    uint32_t var_10e8;        /* Original: 0x10e8 */
    uint32_t var_12ea;        /* Original: 0x12ea */
    uint32_t var_5dbc;        /* Original: 0x5dbc */
    uint32_t var_65be;        /* Original: 0x65be */
    uint32_t var_65c0;        /* Original: 0x65c0 */
    uint32_t var_65fe;        /* Original: 0x65fe */
    uint32_t var_6600;        /* Original: 0x6600 */
    uint32_t var_6602;        /* Original: 0x6602 */
    uint32_t var_680e;        /* Original: 0x680e */
    
    /* Memory buffers for game data */
    uint8_t* memory_pool;
    size_t memory_pool_size;
    
} GameState;

/* Global game state */
extern GameState* g_gameState;

/* Initialize game state */
void InitGameState(void);
void CleanupGameState(void);

/* Memory access macros - convert absolute addresses to structure access */
#define MEM_READ16(addr) (*(uint16_t*)((uint8_t*)g_gameState->memory_pool + (addr)))
#define MEM_WRITE16(addr, val) (*(uint16_t*)((uint8_t*)g_gameState->memory_pool + (addr)) = (val))
#define MEM_READ32(addr) (*(uint32_t*)((uint8_t*)g_gameState->memory_pool + (addr)))
#define MEM_WRITE32(addr, val) (*(uint32_t*)((uint8_t*)g_gameState->memory_pool + (addr)) = (val))

/* DOS File I/O - replaced with Windows API */
typedef HANDLE dos_file_handle;
#define DOS_INVALID_HANDLE INVALID_HANDLE_VALUE

/* DOS file functions -> Windows equivalents */
dos_file_handle dos_open_file(const char* filename, int mode);
int dos_close_file(dos_file_handle handle);
int dos_read_file(dos_file_handle handle, void* buffer, uint32_t count);
int dos_write_file(dos_file_handle handle, const void* buffer, uint32_t count);
int64_t dos_seek_file(dos_file_handle handle, int64_t offset, int origin);

/* DOS memory functions */
void* dos_alloc_memory(size_t size);
void dos_free_memory(void* ptr);
void* dos_resize_memory(void* ptr, size_t new_size);

/* DOS system functions */
void dos_get_version(uint8_t* major, uint8_t* minor);
void dos_terminate(int exit_code);

/* Console I/O - DOS to Windows */
int dos_get_char(void);
int dos_kbhit(void);  /* Check if key is available without blocking */
void set_test_keyboard_buffer(uint32_t value); /* Test helper: Set keyboard buffer for testing */
void dos_put_char(char c);
void dos_put_string(const char* str);
int dos_get_string(char* buffer, int max_len);

/* DOS Interrupt handling - swi() function for interrupt calls */
/* Returns a function pointer that can be called to execute the interrupt */
interrupt_handler* swi(int interrupt_num);

/* Windows File Emulation - DOS file handle to Windows HANDLE mapping */
int win32_emulate_file_open(uint32_t filename_offset, uint mode, uint access);
int win32_emulate_file_read(uint dos_handle, void* buffer, uint32_t count);
int64_t win32_emulate_file_seek(uint dos_handle, int64_t offset, int origin);
int win32_emulate_file_close(uint dos_handle);
int win32_emulate_file_at_end(uint dos_handle);
void close_all_dos_file_handles(void); /* Helper to close all file handles for testing */
void reset_file_open_index(void); /* Reset file open index for test initialization */

/* Initialize function pointers in memory to safe no-op functions */
void initialize_function_pointers(void);

/* Wrapper functions for functions called without parameters */
void setup_function_context_wrapper(void);
void init_random_seed_wrapper(void);
int file_open_wrapper(void);
int file_read_word_wrapper(void);
void file_close_wrapper(void);
/* file_close can be called with or without parameters */
/* If called with 0 or invalid handle, uses current file handle wrapper */
/* If called with a valid handle, uses that handle */
extern long file_close_impl(uint param_1, ...); /* Implementation in skull_ported.c */
void call_dos_interrupt_wrapper(void);
void display_string_wrapper(void);
void display_status_screen_wrapper(void);
void print_string_wrapper(void);
int load_and_display_message_wrapper(void);
undefined2 get_input_line_wrapper(void);
undefined2 execute_command_wrapper(uint *param_1, int param_2, int param_3, int param_4);
/* Wrapper function declarations */
int* handle_location_change_wrapper(int *param_1);
undefined2 handle_special_command_wrapper(void);
int check_command_conditions_wrapper(void);
int process_game_action_wrapper(void);
int parse_command_input_wrapper(void);
const char* get_last_command_line(void); /* Get full command line for simple game engine */
int find_matching_objects_wrapper(uint param_1);
undefined2 match_game_objects_wrapper(uint *param_1, uint *param_2);
int process_command_parameters_wrapper_5(uint *param_1, int param_2, int param_3, uint *param_4, uint *param_5);
int find_objects_in_location_wrapper_2(uint param_1, uint param_2);
int find_objects_in_location_wrapper_3(byte *param_1, uint param_2, uint param_3);
void print_string_wrapper_1(int param_1);
int display_message_wrapper_0(void);
int display_message_wrapper_2(uint param_1, uint param_2);
int display_message_wrapper_3(uint param_1, uint param_2, uint param_3);
undefined2 report_error_wrapper_2(undefined2 param_1, uint param_2);
undefined2 report_error_wrapper_3(undefined2 param_1, uint param_2, uint param_3);
void move_object_between_locations_wrapper_2(uint param_1, int param_2);
char* format_string_wrapper_4(char *param_1, int param_2, char **param_3, char *param_4);
int process_commands_wrapper(void);
void copy_string_data_wrapper_0(void);
void copy_string_data_wrapper_1(undefined2 *param_1);
int string_length_wrapper_int(int param_1);
void setup_display_window_wrapper(void);
int parse_command_input_wrapper_2(int param_1, int param_2);
undefined2 display_inventory_wrapper(void);
void refresh_display_wrapper_1(undefined2 param_1);
uint find_matching_objects_wrapper_0(void);
undefined2 report_error_wrapper_0(void);
undefined2 is_object_in_inventory_wrapper_0(void);
undefined2 take_object_wrapper_0(void);
undefined2 take_object_wrapper_1(uint param_1);
void display_formatted_message_wrapper_0(void);
void display_formatted_message_wrapper_3(undefined2 param_1, uint param_2, uint param_3);
undefined2 handle_object_command_wrapper_3(int param_1, undefined2 param_2, int param_3);
undefined2 handle_put_command_wrapper_3(int param_1, undefined2 param_2, undefined2 param_3);
undefined2 handle_object_interaction_wrapper_2(int param_1, int param_2);
undefined2 handle_object_interaction_wrapper_4(int param_1, int param_2, undefined2 param_3, int param_4);
void display_item_list_wrapper_0(void);
void clear_display_line_wrapper_0(void);
void call_interrupt_by_id_wrapper_0(void);
void flush_file_buffers_wrapper_1(int param_1);
void handle_dos_interrupt_wrapper_0(void);
void allocate_memory_block_wrapper_2(int param_1, void *param_2);
undefined2 display_item_details_wrapper_1(byte *param_1);
int process_command_parameters_wrapper(uint param_1);
undefined2 is_object_in_inventory_wrapper_1(uint param_1);
void refresh_display_wrapper_0(void);
void format_number_output_wrapper_0(void);
undefined2 is_format_char_wrapper_0(void);
void format_float_output_wrapper_0(void);
void output_format_char_wrapper_0(void);
void format_string_output_wrapper_0(void);
void output_format_string_wrapper_0(void);
void output_format_string_wrapper_1(byte *param_1);
void output_format_string_wrapper_3(byte *param_1, uint param_2, int param_3);
int* process_game_action_wrapper_int(int param_1);

/* Utility macros for common patterns */
#define UNUSED(x) ((void)(x))

/* Bit manipulation macros for decompiled code - used extensively in skull_ported.c */
/* CONCAT11: Concatenate two 8-bit values into a 16-bit value (high byte, low byte) */
#define CONCAT11(high, low) ((uint16_t)(((uint8_t)(high) << 8) | ((uint8_t)(low) & 0xFF)))

/* CONCAT22: Concatenate two 16-bit values into a 32-bit value (high word, low word) */
#define CONCAT22(high, low) ((uint32_t)(((uint16_t)(high) << 16) | ((uint16_t)(low) & 0xFFFF)))

/* CARRY2: Check for carry flag in 16-bit addition (returns 1 if carry, 0 otherwise) */
#define CARRY2(a, b) (((uint32_t)(uint16_t)(a) + (uint32_t)(uint16_t)(b)) > 0xFFFF ? 1 : 0)

/* SBORROW2: Check for signed borrow in 16-bit subtraction (returns 1 if borrow, 0 otherwise) */
#define SBORROW2(a, b) ((int16_t)(a) < (int16_t)(b) ? 1 : 0)

/* POPCOUNT: Population count - count number of set bits in a value */
#ifdef _MSC_VER
    #define POPCOUNT(x) (__popcnt((uint32_t)(x)))
#elif defined(__GNUC__) || defined(__clang__)
    #define POPCOUNT(x) (__builtin_popcount((uint32_t)(x)))
#else
    /* Fallback function - declared in dos_compat.c */
    extern int popcount_fallback(uint32_t x);
    #define POPCOUNT(x) popcount_fallback((uint32_t)(x))
#endif

/* ZEXT24: Zero-extend to 24 bits (mask to 24 bits) */
#define ZEXT24(x) ((uint32_t)(x) & 0xFFFFFF)

/* Error handling and logging system */
typedef enum {
    LOG_LEVEL_NONE = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARNING = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_VERBOSE = 5
} LogLevel;

/* Error codes - using SKULL_ prefix to avoid Windows.h macro conflicts */
typedef enum {
    SKULL_ERROR_NONE = 0,
    SKULL_ERROR_FILE_NOT_FOUND = 1,
    SKULL_ERROR_FILE_ACCESS_DENIED = 2,
    SKULL_ERROR_FILE_READ_FAILED = 3,
    SKULL_ERROR_FILE_WRITE_FAILED = 4,
    SKULL_ERROR_FILE_SEEK_FAILED = 5,
    SKULL_ERROR_MEMORY_ALLOCATION_FAILED = 6,
    SKULL_ERROR_MEMORY_POOL_FULL = 7,
    SKULL_ERROR_INVALID_HANDLE = 8,
    SKULL_ERROR_INVALID_PARAMETER = 9,
    SKULL_ERROR_GAME_STATE_NOT_INITIALIZED = 10,
    SKULL_ERROR_FILE_ALREADY_OPEN = 11,
    SKULL_ERROR_FILE_NOT_OPEN = 12,
    SKULL_ERROR_UNKNOWN = 99
} ErrorCode;

/* Logging functions */
void log_set_level(LogLevel level);
LogLevel log_get_level(void);
void log_error(const char* format, ...);
void log_warning(const char* format, ...);
void log_info(const char* format, ...);
void log_debug(const char* format, ...);
void log_verbose(const char* format, ...);

/* Write debug message to both stderr and log file */
void log_debug_message(const char* format, ...);

/* Conditional debug logging macros - can be disabled for production */
#if ENABLE_DEBUG_LOGGING
    #define LOG_DEBUG(fmt, ...) log_debug(fmt, ##__VA_ARGS__)
    #define LOG_VERBOSE(fmt, ...) log_verbose(fmt, ##__VA_ARGS__)
    #define LOG_DEBUG_MSG(fmt, ...) log_debug_message(fmt, ##__VA_ARGS__)
#else
    #define LOG_DEBUG(fmt, ...) ((void)0)  /* No-op in production */
    #define LOG_VERBOSE(fmt, ...) ((void)0)  /* No-op in production */
    #define LOG_DEBUG_MSG(fmt, ...) ((void)0)  /* No-op in production */
#endif

/* Always-enabled logging (errors, warnings, info) */
#define LOG_ERROR(fmt, ...) log_error(fmt, ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...) log_warning(fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...) log_info(fmt, ##__VA_ARGS__)

/* Error handling functions */
const char* error_code_to_string(ErrorCode error_code);
void log_error_with_code(ErrorCode error_code, const char* context, const char* details);
ErrorCode get_last_error(void);
void set_last_error(ErrorCode error_code);
void clear_last_error(void);

/* Windows error code helpers */
const char* windows_error_to_string(DWORD error_code);
void log_windows_error(const char* context, DWORD error_code);

/* Enhanced exception handling helper */
/* Note: exception_code must be obtained via GetExceptionCode() within the __except handler */
void log_exception_details(DWORD exception_code, const char* function_name, const char* file, int line);

/* Parameter validation helpers */
bool validate_pointer(const void* ptr, const char* param_name, const char* function_name);
bool validate_memory_offset(uint32_t offset, size_t size, const char* param_name, const char* function_name);
bool validate_file_handle(uint dos_handle, const char* param_name, const char* function_name);
bool validate_string(const char* str, size_t max_len, const char* param_name, const char* function_name);
bool validate_game_state(const char* function_name);

/* Error context tracking */
typedef struct {
    ErrorCode error_code;
    const char* function_name;
    const char* context_message;
    int line_number;
    DWORD windows_error;  /* For Windows API errors */
} ErrorContext;

void push_error_context(ErrorCode code, const char* function_name, const char* context);
ErrorContext* pop_error_context(void);
ErrorContext* get_current_error_context(void);
void clear_error_context_stack(void);

/* User-friendly error message generation */
const char* get_user_friendly_error_message(ErrorCode code);
void log_user_error(ErrorCode code, const char* operation, const char* details);
void display_user_error(ErrorCode code, const char* operation);

/* Error recovery mechanisms */
typedef enum {
    RECOVERY_RETRY = 0,
    RECOVERY_FALLBACK,
    RECOVERY_SKIP,
    RECOVERY_FAIL
} RecoveryStrategy;

bool try_recover_from_error(ErrorCode code, RecoveryStrategy strategy, int max_retries);
bool validate_and_recover(const char* operation, bool (*validate_func)(void*), void* param, RecoveryStrategy strategy);

/* Pre-operation validation macros */
#define VALIDATE_POINTER(ptr, name) \
    do { \
        if (!validate_pointer(ptr, #name, __FUNCTION__)) { \
            set_last_error(SKULL_ERROR_INVALID_PARAMETER); \
            return; \
        } \
    } while(0)

#define VALIDATE_POINTER_RET(ptr, name, retval) \
    do { \
        if (!validate_pointer(ptr, #name, __FUNCTION__)) { \
            set_last_error(SKULL_ERROR_INVALID_PARAMETER); \
            return retval; \
        } \
    } while(0)

#define VALIDATE_MEMORY_OFFSET(offset, size, name) \
    do { \
        if (!validate_memory_offset(offset, size, #name, __FUNCTION__)) { \
            set_last_error(SKULL_ERROR_MEMORY_POOL_FULL); \
            return; \
        } \
    } while(0)

#define VALIDATE_MEMORY_OFFSET_RET(offset, size, name, retval) \
    do { \
        if (!validate_memory_offset(offset, size, #name, __FUNCTION__)) { \
            set_last_error(SKULL_ERROR_MEMORY_POOL_FULL); \
            return retval; \
        } \
    } while(0)

#define VALIDATE_FILE_HANDLE(handle, name) \
    do { \
        if (!validate_file_handle(handle, #name, __FUNCTION__)) { \
            set_last_error(SKULL_ERROR_INVALID_HANDLE); \
            return; \
        } \
    } while(0)

#define VALIDATE_FILE_HANDLE_RET(handle, name, retval) \
    do { \
        if (!validate_file_handle(handle, #name, __FUNCTION__)) { \
            set_last_error(SKULL_ERROR_INVALID_HANDLE); \
            return retval; \
        } \
    } while(0)

#define VALIDATE_GAME_STATE() \
    do { \
        if (!validate_game_state(__FUNCTION__)) { \
            return; \
        } \
    } while(0)

#define VALIDATE_GAME_STATE_RET(retval) \
    do { \
        if (!validate_game_state(__FUNCTION__)) { \
            return retval; \
        } \
    } while(0)

#endif /* DOS_COMPAT_H */

