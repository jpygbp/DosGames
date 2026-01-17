# Exception Handling Improvements

## Current Status: Exception Handling Masks Errors

**Problem:** Our current exception handling catches all exceptions, logs them, and returns safe default values. This prevents crashes but can hide real bugs.

## Current Pattern (Masking Errors)

```c
#ifdef _WIN32
__try {
#endif
  // Function code that might crash
#ifdef _WIN32
} __except(EXCEPTION_EXECUTE_HANDLER) {
  log_error("function_name: Exception in function");
  return -1;  // Safe default - but hides the real problem
}
#endif
```

## Issues with Current Approach

1. **Real bugs are hidden**: Null pointer dereferences, invalid memory access, etc. get caught and silently handled
2. **Hard to debug**: Only function name is logged, no stack trace or context
3. **No distinction**: Can't tell expected exceptions (invalid test params) from unexpected bugs
4. **Production vs Development**: Same behavior in both modes

## Recommended Improvements

### Option 1: Enhanced Logging (Quick Fix)

Add more diagnostic information:

```c
#ifdef _WIN32
} __except(EXCEPTION_EXECUTE_HANDLER) {
  DWORD exception_code = GetExceptionCode();
  log_error("function_name: Exception 0x%08X in function at %s:%d", 
            exception_code, __FILE__, __LINE__);
  fprintf(stderr, "FATAL: Exception 0x%08X in %s\n", exception_code, __FUNCTION__);
  
  #ifdef _DEBUG
  // In debug builds, also log stack trace or break
  DebugBreak();  // Breaks into debugger
  #endif
  
  return -1;
}
#endif
```

### Option 2: Debug Mode with Breaking (Better)

Make exceptions visible in debug builds:

```c
#ifdef _WIN32
__try {
#endif
  // Function code
#ifdef _WIN32
} __except(EXCEPTION_EXECUTE_HANDLER) {
  DWORD exception_code = GetExceptionCode();
  log_error("function_name: Exception 0x%08X", exception_code);
  
  #ifdef _DEBUG
  // In debug builds, break into debugger to investigate
  fprintf(stderr, "DEBUG: Exception in %s - breaking into debugger\n", __FUNCTION__);
  DebugBreak();
  #elif defined(EXCEPTION_BREAK_ON_ERROR)
  // Or use compile-time flag for controlled testing
  fprintf(stderr, "ERROR: Exception in %s - check logs\n", __FUNCTION__);
  #endif
  
  return -1;
}
#endif
```

### Option 3: Exception Filtering (Best for Development)

Distinguish between expected and unexpected exceptions:

```c
#ifdef _WIN32
} __except(
  #ifdef _DEBUG
  // In debug, catch but report all exceptions
  (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION) ? 
    EXCEPTION_CONTINUE_SEARCH :  // Let access violations crash in debug
    EXCEPTION_EXECUTE_HANDLER     // Handle other exceptions
  #else
  // In release, handle all exceptions gracefully
  EXCEPTION_EXECUTE_HANDLER
  #endif
) {
  DWORD code = GetExceptionCode();
  log_error("%s: Exception 0x%08X - %s", __FUNCTION__, code, 
            (code == EXCEPTION_ACCESS_VIOLATION) ? "Access Violation" :
            (code == EXCEPTION_INT_DIVIDE_BY_ZERO) ? "Divide by Zero" :
            "Unknown");
  return -1;
}
#endif
```

### Option 4: Assert-Style Wrapper (Most Flexible)

Create a macro that can be configured:

```c
#ifdef _WIN32
#define SAFE_EXECUTE(code, default_return) \
  do { \
    __try { \
      code; \
    } __except(EXCEPTION_EXECUTE_HANDLER) { \
      DWORD exc = GetExceptionCode(); \
      log_error("%s: Exception 0x%08X", __FUNCTION__, exc); \
      fprintf(stderr, "ERROR: Exception in %s\n", __FUNCTION__); \
      #ifdef _DEBUG \
      DebugBreak(); \
      #endif \
      return default_return; \
    } \
  } while(0)
#else
#define SAFE_EXECUTE(code, default_return) code
#endif

// Usage:
SAFE_EXECUTE({
  file_handle = file_open_read(filename_ptr, mode, access);
}, (uint)-1);
```

## Recommendation for This Project

Given that this is a **DOS game port** with:
- Legacy code that may have assumptions about DOS environment
- Many functions that need to work despite potential issues
- Testing with invalid parameters is expected

**Recommended Approach:**
1. **Keep current pattern** for production robustness
2. **Add enhanced logging** with exception codes and file/line info
3. **Add debug build support** that breaks into debugger
4. **Document exception patterns** so developers know when exceptions are expected

### Example: Enhanced Current Pattern

```c
#ifdef _WIN32
} __except(EXCEPTION_EXECUTE_HANDLER) {
  DWORD exception_code = GetExceptionCode();
  
  // Enhanced logging
  log_error("%s: Exception 0x%08X at %s:%d", 
            __FUNCTION__, exception_code, __FILE__, __LINE__);
  fprintf(stderr, "[EXCEPTION] %s: 0x%08X\n", __FUNCTION__, exception_code);
  
  // Break in debug builds to investigate
  #ifdef _DEBUG
  if (exception_code == EXCEPTION_ACCESS_VIOLATION ||
      exception_code == EXCEPTION_INT_DIVIDE_BY_ZERO) {
    fprintf(stderr, "DEBUG: Breaking into debugger for critical exception\n");
    DebugBreak();
  }
  #endif
  
  return -1;
}
#endif
```

## Implementation Priority

1. **Immediate**: Add exception code logging (helps identify bug types)
2. **Short-term**: Add file/line number logging (helps locate issues)
3. **Medium-term**: Add debug build breakpoints (helps development)
4. **Long-term**: Consider exception filtering or assert macros (advanced)

## When to Remove Exception Handling

Exception handling should be **removed or tightened** when:
- The root cause of the exception is identified and fixed
- The function has been proven to work correctly
- Testing shows the exception was due to invalid test parameters, not a bug

For now, keep exception handling because:
- This is legacy DOS code ported to Windows
- Many assumptions about memory layout may be wrong
- It allows the game to continue running while we identify issues
- Logs help us track down problems systematically
