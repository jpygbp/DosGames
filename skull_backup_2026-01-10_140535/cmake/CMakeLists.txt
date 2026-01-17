cmake_minimum_required(VERSION 3.15)
project(SkullGame VERSION 1.0.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Compiler-specific options
if(MSVC)
    # MSVC compiler options
    add_compile_options(/W4 /WX- /permissive-)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options(/MD)  # Use multithreaded DLL runtime
else()
    # GCC/Clang options
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Source files
set(COMPAT_SOURCES
    dos_compat.c
    main.c
    function_stubs.c
)

# Check if we have the full decompiled source
if(EXISTS "${CMAKE_SOURCE_DIR}/skull_ghidra_decompiled.c")
    message(STATUS "Using Ghidra decompiled source")
    set(DECOMPILED_SOURCE skull_ghidra_decompiled.c)
else()
    message(STATUS "Using basic decompiled source")
    set(DECOMPILED_SOURCE skull_decompiled.c)
endif()

# Create a ported version of the decompiled code
set(PORTED_SOURCE skull_ported.c)

# Headers
set(HEADERS
    dos_compat.h
)

# Create executable
add_executable(skull
    ${COMPAT_SOURCES}
    skull_ported.c
    ${HEADERS}
)

# Link Windows libraries
if(WIN32)
    target_link_libraries(skull
        kernel32
        user32
    )
endif()

# Include directories
target_include_directories(skull PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Copy game data files to output directory
file(GLOB GAME_DATA_FILES 
    "${CMAKE_SOURCE_DIR}/SKULL.M"
    "${CMAKE_SOURCE_DIR}/SKULL.X"
    "${CMAKE_SOURCE_DIR}/SKULL.V"
    "${CMAKE_SOURCE_DIR}/SKULL.T"
    "${CMAKE_SOURCE_DIR}/SKULL.MO"
    "${CMAKE_SOURCE_DIR}/SKULL.MM"
)

foreach(file ${GAME_DATA_FILES})
    get_filename_component(filename ${file} NAME)
    configure_file(${file} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename} COPYONLY)
endforeach()

# Installation
install(TARGETS skull
    RUNTIME DESTINATION bin
)

install(FILES ${GAME_DATA_FILES}
    DESTINATION bin
)

