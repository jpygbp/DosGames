# Error Handling and Logging System

## Overview

A comprehensive error handling and logging infrastructure has been added to the Skull game port to improve debugging, error tracking, and runtime diagnostics.

## Features

### 1. Logging System

#### Log Levels
- `LOG_LEVEL_NONE` (0) - No logging
- `LOG_LEVEL_ERROR` (1) - Only errors
- `LOG_LEVEL_WARNING` (2) - Errors and warnings
- `LOG_LEVEL_INFO` (3) - Errors, warnings, and info (default)
- `LOG_LEVEL_DEBUG` (4) - Detailed debugging information
- `LOG_LEVEL_VERBOSE` (5) - Very detailed logging

#### Logging Functions
```c
void log_error(const char* format, ...);
void log_warning(const char* format, ...);
void log_info(const char* format, ...);
void log_debug(const char* format, ...);
void log_verbose(const char* format, ...);
```

#### Setting Log Level
```c
void log_set_level(LogLevel level);
LogLevel log_get_level(void);
```

**Environment Variable**: Set `SKULL_LOG_LEVEL` to control logging at runtime:
```bash
set SKULL_LOG_LEVEL=4  # Enable debug logging
```

### 2. Error Code System

#### Error Codes
- `ERROR_NONE` - No error
- `ERROR_FILE_NOT_FOUND` - File not found
- `ERROR_FILE_ACCESS_DENIED` - File access denied
- `ERROR_FILE_READ_FAILED` - File read operation failed
- `ERROR_FILE_WRITE_FAILED` - File write operation failed
- `ERROR_FILE_SEEK_FAILED` - File seek operation failed
- `ERROR_MEMORY_ALLOCATION_FAILED` - Memory allocation failed
- `ERROR_MEMORY_POOL_FULL` - Memory pool is full
- `ERROR_INVALID_HANDLE` - Invalid file handle
- `ERROR_INVALID_PARAMETER` - Invalid function parameter
- `ERROR_GAME_STATE_NOT_INITIALIZED` - Game state not initialized
- `ERROR_FILE_ALREADY_OPEN` - File already open
- `ERROR_FILE_NOT_OPEN` - File not open
- `ERROR_UNKNOWN` - Unknown error

#### Error Handling Functions
```c
ErrorCode get_last_error(void);
void set_last_error(ErrorCode code);
void clear_last_error(void);
const char* error_code_to_string(ErrorCode code);
void log_error_with_code(ErrorCode code, const char* context, const char* details);
```

### 3. Enhanced File Operations

All file operations now include:
- Parameter validation (NULL checks)
- Detailed error logging
- Windows error code translation
- Error code tracking

#### File Functions Enhanced
- `dos_open_file()` - Logs file open attempts, translates Windows errors
- `dos_close_file()` - Validates handles, logs close operations
- `dos_read_file()` - Validates parameters, logs partial reads
- `dos_write_file()` - Validates parameters, logs partial writes
- `dos_seek_file()` - Validates parameters, logs seek operations

### 4. Enhanced Memory Operations

All memory operations now include:
- NULL pointer checks
- Size validation
- Error logging
- Error code tracking

#### Memory Functions Enhanced
- `dos_alloc_memory()` - Logs allocations, checks for failures
- `dos_free_memory()` - Validates pointers before freeing
- `dos_resize_memory()` - Logs resize operations, handles failures

### 5. Game State Initialization

`InitGameState()` now includes:
- Detailed logging of initialization steps
- Proper error handling for memory allocation failures
- Cleanup on failure
- UTF-8 console setup logging

## Usage Examples

### Basic Logging
```c
log_info("Game starting...");
log_debug("Loading file: %s", filename);
log_error("Failed to open file: %s", filename);
```

### Error Handling
```c
dos_file_handle file = dos_open_file("SKULL.M", 1);
if (file == DOS_INVALID_HANDLE) {
    ErrorCode error = get_last_error();
    log_error_with_code(error, "File open failed", "SKULL.M");
    return -1;
}
```

### Windows Error Translation
```c
DWORD win_error = GetLastError();
log_windows_error("CreateFile failed", win_error);
// Output: CreateFile failed: Windows error 2 - The system cannot find the file specified.
```

## Log Output Format

```
[2024-01-15 14:30:45] [INFO] Game starting...
[2024-01-15 14:30:45] [DEBUG] Opening 'SKULL.M' with mode 0x1
[2024-01-15 14:30:45] [INFO] Successfully opened 'SKULL.M'
[2024-01-15 14:30:45] [ERROR] Failed to read 1024 bytes
[2024-01-15 14:30:45] [ERROR] dos_read_file: Windows error 5 - Access is denied.
```

## Configuration

### Compile-Time Options

**Memory Checks**: Define `SKULL_ENABLE_MEMORY_CHECKS` to enable bounds checking on memory pool access:
```c
#define SKULL_ENABLE_MEMORY_CHECKS
```

**Note**: Memory checks are disabled by default for performance. Enable during development/debugging.

### Runtime Options

**Log Level**: Set via environment variable:
```bash
# Windows CMD
set SKULL_LOG_LEVEL=4

# PowerShell
$env:SKULL_LOG_LEVEL=4

# Linux/Mac
export SKULL_LOG_LEVEL=4
```

## Integration Points

### Main Entry Point
- `main()` now initializes logging
- Logs game startup and shutdown
- Checks for initialization errors

### File Operations
- All file I/O functions log operations
- Errors are logged with context
- Windows errors are translated to readable messages

### Memory Operations
- All memory allocations are logged
- Failures are tracked with error codes
- Memory pool operations can be monitored

## Benefits

1. **Debugging**: Detailed logs help identify issues quickly
2. **Error Tracking**: Error codes provide structured error information
3. **Diagnostics**: Windows error translation makes system errors understandable
4. **Monitoring**: Can track file operations and memory usage
5. **Development**: Different log levels allow focusing on relevant information

## Future Enhancements

1. **Log File Output**: Option to write logs to file instead of stderr
2. **Log Rotation**: Automatic log file rotation
3. **Performance Metrics**: Track operation timings
4. **Memory Leak Detection**: Track allocations and detect leaks
5. **Crash Reporting**: Automatic crash dump generation

## Notes

- Logging is thread-safe for single-threaded use
- Log output goes to `stderr` by default
- Error codes are stored in thread-local storage (single-threaded)
- Memory checks can impact performance - disable in release builds






