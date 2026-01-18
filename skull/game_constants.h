/* Game Constants - Meaningful names for hardcoded values
 * This file provides readable constant definitions for magic numbers
 * and memory addresses used throughout the game code
 */

#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

/* ============================================================
 * SAFETY LIMITS - Loop and Buffer Bounds
 * ============================================================ */

/* Loop safety limits to prevent infinite loops */
#define MAX_LOOPS                       10000   /* Maximum main game loop iterations (increased for full walkthrough support) */
#define MAX_GAME_LOOP_ITERATIONS        100     /* Maximum main game loop iterations (alias) */
#define MAX_COMMAND_PROCESS_LOOPS       5       /* Maximum command processing loops */
#define MAX_PROCESS_LOOPS               5       /* Alias for MAX_COMMAND_PROCESS_LOOPS */
#define MAX_ZERO_RESULT_ITERATIONS      2       /* Maximum consecutive zero results */
#define MAX_ZERO_ITERATIONS             2       /* Alias for MAX_ZERO_RESULT_ITERATIONS */
#define MAX_CONSECUTIVE_ERRORS          5       /* Maximum consecutive errors before exit */
#define MAX_TOTAL_ERRORS                1000    /* Maximum total errors in game loop (increased for automated walkthrough testing) */
#define MAX_EOF_ATTEMPTS                2       /* Maximum EOF attempts before exit */
#define MAX_SAME_COMMAND_REPEATS        10      /* Maximum same command repetitions */
#define MAX_SAME_COMMAND                10      /* Alias for MAX_SAME_COMMAND_REPEATS */
#define MAX_ZERO_RESULTS                10      /* Maximum zero results before exit */
#define MAX_INNER_LOOPS                 10      /* Maximum inner loop iterations */

/* File and data loading limits */
#define MAX_ITEMS_TO_READ               5000    /* Maximum items to read from file */
#define MAX_FILE_HANDLES                10      /* Maximum DOS file handles */
#define MAX_STRING_LENGTH               256     /* Maximum string length */
#define MAX_COMMAND_LENGTH              128     /* Maximum command input length */
#define MAX_PATH_LENGTH                 260     /* Standard Windows MAX_PATH */
#define MAX_LONG_PATH_LENGTH            32767   /* Windows long path support */

/* Buffer sizes */
#define BUFFER_SIZE_SMALL               64      /* Small buffer (64 bytes) */
#define BUFFER_SIZE_MEDIUM              256     /* Medium buffer (256 bytes) */
#define BUFFER_SIZE_LARGE               1024    /* Large buffer (1KB) */
#define BUFFER_SIZE_XLARGE              4096    /* Extra large buffer (4KB) */

/* Memory pool allocation */
#define MEMORY_POOL_SIZE                0x10000 /* 64KB memory pool */
#define TEMP_BUFFER_OFFSET              0x7C00  /* Temporary buffer location */
#define RESULT_BUFFER_OFFSET            0x7B00  /* Result buffer location */

/* ============================================================
 * MEMORY ADDRESSES - Game State Variables
 * ============================================================ */

/* Core game state addresses */
#define MEM_BASE_POINTER           0xbc      /* Base pointer for game data */
#define MEM_POOL_BASE_OFFSET       0x0       /* Memory pool base offset (offset 0) */
#define MEM_COMMAND_COUNT          0xcc      /* Number of commands */
#define MEM_OBJECT_COUNT           0xce      /* Number of objects */
#define MEM_STRING_COUNT           0xd0      /* Number of strings */
#define MEM_VIDEO_MODE             0xe6      /* Current video mode */
#define MEM_KEYBOARD_BUFFER        0x8a6     /* Keyboard input buffer */
#define MEM_COMMAND_TERMINATOR     0xec      /* Command terminator value */
#define MEM_COMMAND_SEPARATOR      0xee      /* Command separator value */

/* File handle addresses */
#define MEM_FILE_HANDLE_1          0x1080    /* First file handle */
#define MEM_FILE_HANDLE_2          0x10e6    /* Second file handle */
#define MEM_FILE_HANDLE_3          0x65fe    /* Third file handle */
#define MEM_FILE_HANDLE_4          0x680e    /* Fourth file handle */
#define MEM_FILE_HANDLE_5          0x65be    /* Fifth file handle */
#define MEM_FILE_HANDLE_6          0x6600    /* Sixth file handle */

/* Data structure addresses */
#define MEM_DATA_BASE              0x5dbc    /* Base address for game data */
#define MEM_STRING_TABLE           0x65c0    /* String table address */
#define MEM_STRING_TABLE_BASE      0x12ea    /* String table base address */
#define MEM_STRING_TABLE_OFFSET    0x10e8    /* String table offset */
#define MEM_LOCATION_DATA          0x6602    /* Current location data */
#define MEM_GAME_FLAGS             0x6605    /* Game state flags */
#define MEM_GAME_EXIT_FLAG         0x6606    /* Game exit flag */
#define MEM_COMMAND_BUFFER         0x6500    /* Command input buffer */
#define MEM_MOVE_COUNTER           0x6603    /* Movement counter */
#define MEM_MOVE_DIRECTION         0x6608    /* Movement direction */
#define MEM_LOCATION_ID            0x6609    /* Current location ID */
#define MEM_COMMAND_COUNTER        0x660c    /* Command execution counter */
#define MEM_DISPLAY_MODE           0x660a    /* Display mode flag */
#define MEM_LOCATION_TEMP          0x6607    /* Temporary location storage */

/* Format/Output addresses */
#define MEM_FORMAT_PARAM_PTR       0xe86     /* Format parameter pointer */
#define MEM_FORMAT_OUTPUT_PTR      0xe92     /* Format output pointer */
#define MEM_FORMAT_BUFFER          0xea2     /* Format string buffer */
#define MEM_POINTER_STORAGE        0x60a     /* Pointer storage address */
#define MEM_FORMAT_FLAG_1          0xe84     /* Format flag 1 */
#define MEM_STATE_VAR_1            0xef1     /* State variable 1 */
#define MEM_STATE_VAR_2            0xef3     /* State variable 2 */
#define MEM_STATE_VAR_3            0xefd     /* State variable 3 */
#define MEM_FUNCTION_PTR_3         0x936     /* Function pointer storage 3 */
#define MEM_CALC_BASE_OFFSET       0x327     /* Calculation base offset */
#define MEM_FORMAT_FLAG_2          0xe88     /* Format flag 2 */
#define MEM_FORMAT_FLAG_3          0xe8a     /* Format flag 3 */
#define MEM_FORMAT_FLAG_4          0xe8c     /* Format flag 4 */
#define MEM_FORMAT_FLAG_5          0xe8e     /* Format flag 5 */
#define MEM_FORMAT_FLAG_6          0xe90     /* Format flag 6 */
#define MEM_FORMAT_FLAG_7          0xe94     /* Format flag 7 */
#define MEM_FORMAT_FLAG_8          0xe96     /* Format flag 8 */
#define MEM_FORMAT_FLAG_9          0xe98     /* Format flag 9 */
#define MEM_FORMAT_WIDTH           0xea4     /* Format width */
#define MEM_FORMAT_PRECISION       0xe9e     /* Format precision */
#define MEM_FORMAT_PAD_CHAR        0xea8     /* Format padding character */
#define MEM_FORMAT_OUTPUT_COUNT    0xe9a     /* Format output count */
#define MEM_FORMAT_PARAM_COUNT     0xe9c     /* Format parameter count */
#define MEM_FORMAT_FLAG_10         0xea0     /* Format flag 10 */
#define MEM_RANDOM_SEED_1          0x8a8     /* Random number generator seed 1 */
#define MEM_RANDOM_SEED_2          0x8aa     /* Random number generator seed 2 */
#define MEM_POINTER_STORAGE_34     0x77e     /* Pointer storage address 34 */
#define MEM_BUFFER_STORAGE         0x900     /* General buffer storage address */
#define MEM_INTERRUPT_LOOP_FLAG    0x97e     /* Interrupt loop flag */

/* Display/UI addresses */
#define MEM_CURSOR_X               0x26a     /* Cursor X position */
#define MEM_DISPLAY_STRING_1      0x7a      /* Display string buffer 1 */
#define MEM_DISPLAY_STRING_2       0x7e      /* Display string buffer 2 */
#define MEM_DISPLAY_STRING_3       0x80      /* Display string buffer 3 */
#define MEM_DISPLAY_STRING_4       0x7c1     /* Display string buffer 4 */
#define MEM_DISPLAY_STRING_5       0x7d5     /* Display string buffer 5 */
#define MEM_DISPLAY_STRING_6       0x7e2     /* Display string buffer 6 */

/* Error/Status addresses */
#define MEM_ERROR_FLAG             0xe8      /* Error flag */
#define MEM_ERROR_CODE             0xfa      /* Error code */
#define MEM_STATUS_FLAG            0xf0      /* Status flag */
#define MEM_COUNTER_1              0xf6      /* General counter 1 */
#define MEM_COUNTER_2              0x43a     /* General counter 2 */
#define MEM_CURSOR_X               0x26a     /* Cursor X position */
#define MEM_REGISTER_STORAGE_1     0xf98     /* Register storage 1 */
#define MEM_REGISTER_STORAGE_2     0xf9a     /* Register storage 2 */
#define MEM_STACK_BASE             0x800     /* Stack base address */
#define MEM_COMPARISON_VALUE       0xf4      /* Comparison value for command matching */
#define MEM_LOCATION_BUFFER        0x6606    /* Location buffer address */
#define MEM_LOCATION_TEMP          0x6607    /* Temporary location storage */
#define MEM_LOCATION_TEMP_2         0x6604    /* Temporary location storage 2 */
#define MEM_ACTION_TABLE_BASE      0x100     /* Action table base address */
#define MEM_OBJECT_BUFFER          0x65c2    /* Object buffer address */
#define MEM_MATCH_COUNT            0x65c0    /* Match count storage */
#define MEM_DISPLAY_MODE_2         0x660a    /* Display mode flag 2 */
#define MEM_LOCATION_ID_2          0x6609    /* Location ID 2 */
#define MEM_LOCATION_BUFFER_2      0x660b    /* Location buffer 2 */
#define MEM_MAX_OBJECTS            0xc2      /* Maximum number of objects */
#define MEM_SPECIAL_FLAG           0xf8      /* Special flag */
#define MEM_OBJECT_LIST_BASE       0x370     /* Object list base address */
#define MEM_STRING_TABLE_LOOKUP    0x7a5     /* String table lookup address */
#define MEM_FUNCTION_PTR_1         0x636     /* Function pointer storage 1 */
#define MEM_FUNCTION_PTR_2         0x97c     /* Function pointer storage 2 */
#define MEM_FUNCTION_PTR_4         0x632     /* Function pointer storage 4 */
#define MEM_OBJECT_DATA_OFFSET_2   0x6f0     /* Object data offset 2 */
#define MEM_DISPLAY_REGION_X1      0xfe6     /* Display region X1 coordinate */
#define MEM_DISPLAY_REGION_X2      0xfe8     /* Display region X2 coordinate */
#define MEM_DISPLAY_REGION_Y1      0xfea     /* Display region Y1 coordinate */
#define MEM_DISPLAY_REGION_Y2      0xfec     /* Display region Y2 coordinate */
#define MEM_SPECIAL_VALUE_1       0xf5      /* Special value 1 */
#define MEM_SPECIAL_VALUE_2       0x2       /* Special value 2 */
#define MEM_SPECIAL_ADDR_1        0x1016    /* Special address 1 */
#define MEM_SPECIAL_ADDR_2        0x101c    /* Special address 2 */
#define BIT_MASK_HIGH_16           0xffff0000 /* High 16 bits mask */
#define BIT_MASK_HIGH_16U          0xffff0000UL /* High 16 bits mask (unsigned long) */
#define OFFSET_PARAM_E             0xe       /* Parameter E offset (14) */
#define MEM_POINTER_STORAGE_2      0x624     /* Pointer storage address 2 */
#define MEM_POINTER_STORAGE_3      0x601     /* Pointer storage address 3 */
#define MEM_POINTER_STORAGE_4      0x603     /* Pointer storage address 4 */
#define MEM_MEMORY_OFFSET          0x18ab    /* Memory offset constant */
#define MEM_ENVIRONMENT_VAR        0x2c      /* Environment variable storage */
#define MEM_FILE_BUFFER_1         0x656     /* File buffer 1 */
#define MEM_OBJECT_DATA_OFFSET     0x6ee     /* Object data offset */
#define MEM_ERROR_MSG_1            0x379     /* Error message 1 */
#define MEM_ERROR_MSG_2            0x3ad     /* Error message 2 */
#define MEM_STRING_PTR_1           0xd011    /* String pointer 1 */
#define MEM_STRING_PTR_2           0x376     /* String pointer 2 */
#define MEM_STRING_PTR_3           0xd023    /* String pointer 3 */
#define MEM_STRING_PTR_4           0xd002    /* String pointer 4 */
#define MEM_STRING_PTR_5           0x5b14    /* String pointer 5 */
#define MEM_STRING_PTR_6           0xcf2     /* String pointer 6 */
#define MEM_STRING_PTR_7           0xd004    /* String pointer 7 */
#define MEM_STRING_PTR_8           0xf20     /* String pointer 8 */
#define MEM_STRING_PTR_9           0x411     /* String pointer 9 */
#define MEM_STRING_PTR_10          0xf70     /* String pointer 10 */
#define MEM_STRING_PTR_11          0xd081    /* String pointer 11 */
#define MEM_STRING_PTR_12          0xd025    /* String pointer 12 */
#define MEM_STRING_PTR_13          0xd0a0    /* String pointer 13 */
#define MEM_ACTION_OFFSET_1        0x92a     /* Action offset 1 */
#define MEM_ACTION_OFFSET_2        0x903     /* Action offset 2 */
#define MEM_ACTION_OFFSET_3        0xbe0     /* Action offset 3 */
#define MEM_ACTION_OFFSET_4        0xab4     /* Action offset 4 */
#define MEM_ACTION_OFFSET_5        0x5abc    /* Action offset 5 */
#define MEM_ACTION_OFFSET_6        0x5b64    /* Action offset 6 */
#define MEM_ACTION_OFFSET_7        0xc5a     /* Action offset 7 */
#define MEM_ACTION_PARAM_OFFSET    0x100     /* Action parameter offset */
#define MEM_ACTION_FLAGS_OFFSET    0x100    /* Action flags offset */
#define MEM_ACTION_PARAM_PTR       0xfe      /* Action parameter pointer offset */
#define MEM_STACK_VALUE_1          0x50      /* Stack value 1 */
#define MEM_STACK_VALUE_2          0x3c4     /* Stack value 2 */
#define MEM_STACK_VALUE_3          0x443     /* Stack value 3 */
#define MEM_STACK_VALUE_4          0x6a0     /* Stack value 4 */
#define MEM_STACK_VALUE_5          0x1000    /* Stack value 5 */
#define MEM_STACK_VALUE_6          0x1570    /* Stack value 6 */
#define MEM_STACK_VALUE_7          0x5f1     /* Stack value 7 */
#define MEM_OBJECT_BASE_OFFSET     0x19a     /* Object base offset */

/* ============================================================
 * COMMAND AND ACTION FLAGS
 * ============================================================ */

/* Command flags */
#define CMD_FLAG_REQUIRE_OBJECT    0x400     /* Command requires object */
#define CMD_FLAG_SPECIAL           0x8000    /* Special command flag */
#define CMD_FLAG_HAS_PARAMS        0x4000    /* Command has parameters */
#define CMD_FLAG_SPECIAL_ACTION    0x4018    /* Special action command */
#define CMD_FLAG_END_COMMAND       0x401d    /* End command marker */
#define CMD_QUIT                   0x0011    /* Quit command ID */

/* Action flags */
#define ACTION_FLAG_REQUIRE_MATCH  0x40      /* Action requires object match */
#define ACTION_FLAG_REQUIRE_OBJECT 0x80      /* Action requires object */
#define ACTION_FLAG_REQUIRE_PARAM  0x20      /* Action requires parameter */
#define ACTION_FLAG_COPY_STRING    0x10      /* Action copies string */
#define ACTION_FLAG_CHECK_STATE    0x4       /* Action checks game state */
#define ACTION_FLAG_HAS_HANDLER    0x2       /* Action has handler function */
#define ACTION_FLAG_REQUIRE_ITEM   0x1       /* Action requires item */

/* Location flags */
#define LOC_FLAG_DARK              0x80      /* Location is dark */
#define LOC_FLAG_HAS_MESSAGE       0x40      /* Location has message */
#define LOC_FLAG_REQUIRE_LIGHT     0x20      /* Location requires light */
#define LOC_FLAG_SPECIAL           0x10       /* Special location */
#define LOC_FLAG_HAS_OBJECTS       0x8       /* Location has objects */
#define LOC_FLAG_HAS_DESCRIPTION   0x4       /* Location has description */
#define LOC_FLAG_REQUIRE_ITEM      0x2       /* Location requires item */
#define LOC_FLAG_VISITED           0x1        /* Location has been visited */

/* Object flags */
#define OBJ_FLAG_TAKEABLE          0x2000     /* Object can be taken */
#define OBJ_FLAG_WEARABLE          0x1000     /* Object can be worn */
#define OBJ_FLAG_CONTAINER         0x800      /* Object is a container */
#define OBJ_FLAG_LOCKED            0x400      /* Object is locked */
#define OBJ_FLAG_OPEN              0x200      /* Object is open */
#define OBJ_FLAG_LIGHT             0x100      /* Object provides light */
#define OBJ_FLAG_READABLE          0x80       /* Object can be read */
#define OBJ_FLAG_EDIBLE            0x40       /* Object can be eaten */
#define OBJ_FLAG_DRINKABLE         0x20       /* Object can be drunk */
#define OBJ_FLAG_WEAPON            0x10       /* Object is a weapon */
#define OBJ_FLAG_TOOL              0x8        /* Object is a tool */
#define OBJ_FLAG_KEY               0x4        /* Object is a key */
#define OBJ_FLAG_TREASURE          0x2        /* Object is treasure */
#define OBJ_FLAG_SPECIAL           0x1        /* Object has special properties */

/* ============================================================
 * DISPLAY AND UI CONSTANTS
 * ============================================================ */

/* Video modes */
#define VIDEO_MODE_TEXT            0xffff    /* Text mode */
#define VIDEO_MODE_GRAPHICS        0x0000    /* Graphics mode */

/* Display windows */
#define DISPLAY_WINDOW_MAIN        0         /* Main display window */
#define DISPLAY_WINDOW_STATUS      1         /* Status window */
#define DISPLAY_WINDOW_INVENTORY   2         /* Inventory window */
#define DISPLAY_WINDOW_MESSAGE     3         /* Message window */
#define DISPLAY_WINDOW_INPUT       4         /* Input window */
#define DISPLAY_WINDOW_MAX         6         /* Maximum number of windows */

/* Cursor positions */
#define CURSOR_HOME_X              0         /* Home X position */
#define CURSOR_HOME_Y              0         /* Home Y position */
#define CURSOR_INPUT_X             0x7a      /* Input X position */
#define CURSOR_INPUT_Y             0x4f2     /* Input Y position */

/* String offsets */
#define STRING_OFFSET_PROMPT       0x7a      /* Prompt string offset */
#define STRING_OFFSET_INPUT        0x7e      /* Input string offset */
#define STRING_OFFSET_DISPLAY      0x80      /* Display string offset */
#define STRING_OFFSET_STATUS       0x7c1     /* Status string offset */
#define STRING_OFFSET_NUMBER       0x7d5     /* Number string offset */
#define STRING_OFFSET_MESSAGE      0x7e2     /* Message string offset */

/* ============================================================
 * GAME LOGIC CONSTANTS
 * ============================================================ */

/* Location IDs */
#define LOCATION_ENTRANCE           0x5a     /* Entrance location */
#define LOCATION_EXIT               0x24     /* Exit location */
#define LOCATION_SPECIAL            7         /* Special location ID */

/* Movement constants */
#define MOVE_COUNTER_MAX            4         /* Maximum move counter */
#define MOVE_DIRECTION_NONE         0         /* No movement */
#define MOVE_DIRECTION_NORTH        1         /* North */
#define MOVE_DIRECTION_SOUTH        2         /* South */
#define MOVE_DIRECTION_EAST         3         /* East */
#define MOVE_DIRECTION_WEST         4         /* West */
#define MOVE_DIRECTION_UP           5         /* Up */
#define MOVE_DIRECTION_DOWN         6         /* Down */

/* Command processing */
#define COMMAND_TERMINATOR          0xec      /* Command terminator */
#define COMMAND_SEPARATOR           0xee      /* Command separator */
#define COMMAND_MAX_LENGTH          10        /* Maximum command length */
#define COMMAND_MAX_TOKENS          6         /* Maximum tokens per command */
#define COMMAND_SPECIAL_1           0x403     /* Special command 1 */
#define COMMAND_SPECIAL_2           0x405     /* Special command 2 */
#define COMMAND_SPECIAL_3           0x406     /* Special command 3 */
#define COMMAND_SPECIAL_4           0x407     /* Special command 4 */
#define COMMAND_SPECIAL_5           0x408     /* Special command 5 */
#define COMMAND_SPECIAL_6           0x409     /* Special command 6 */
#define COMMAND_SPECIAL_7           0x40b     /* Special command 7 */
#define COMMAND_SPECIAL_8           0x40c     /* Special command 8 */
#define COMMAND_SPECIAL_9           0x408     /* Special command 9 */
#define COMMAND_STRING_1            0x1007    /* Command string 1 */
#define COMMAND_STRING_2            0x100f    /* Command string 2 */
#define COMMAND_STRING_3            0xff6     /* Command string 3 */
#define COMMAND_STRING_4            0x100a    /* Command string 4 */
#define COMMAND_STRING_5            0x1023    /* Command string 5 */
#define COMMAND_STRING_6            0x1033    /* Command string 6 */
#define COMMAND_STRING_7            0x3       /* Command string 7 */
#define COMMAND_STRING_8            0xffff    /* Command string 8 (error) */

/* String processing */
#define STRING_MAX_LENGTH           72        /* Maximum string length */
#define STRING_COMPARE_LENGTH       6         /* String comparison length */
#define STRING_TABLE_ENTRY_SIZE     3         /* String table entry size */

/* Format string constants */
#define FORMAT_CHAR_PERCENT         '%'       /* Format specifier start */
#define FORMAT_CHAR_ZERO            '0'       /* Zero padding */
#define FORMAT_CHAR_MINUS           '-'      /* Left alignment */
#define FORMAT_CHAR_PLUS            '+'      /* Show sign */
#define FORMAT_CHAR_SPACE           ' '      /* Space padding */
#define FORMAT_CHAR_DOT             '.'      /* Precision separator */
#define FORMAT_CHAR_F               'F'      /* Float format */
#define FORMAT_CHAR_N               'N'      /* Number format */
#define FORMAT_CHAR_h               'h'      /* Short format */
#define FORMAT_CHAR_l               'l'      /* Long format */
#define FORMAT_CHAR_L               'L'      /* Long double format */
#define FORMAT_CHAR_c               'c'      /* Character format */
#define FORMAT_CHAR_d               'd'      /* Decimal format */
#define FORMAT_CHAR_i               'i'      /* Integer format */
#define FORMAT_CHAR_o               'o'      /* Octal format */
#define FORMAT_CHAR_p               'p'      /* Pointer format */
#define FORMAT_CHAR_u               'u'      /* Unsigned format */
#define FORMAT_CHAR_x               'x'      /* Hex format (lowercase) */
#define FORMAT_CHAR_X               'X'      /* Hex format (uppercase) */
#define FORMAT_CHAR_e               'e'      /* Scientific format (lowercase) */
#define FORMAT_CHAR_E               'E'      /* Scientific format (uppercase) */
#define FORMAT_CHAR_f               'f'      /* Float format */
#define FORMAT_CHAR_g               'g'      /* General format (lowercase) */
#define FORMAT_CHAR_G               'G'      /* General format (uppercase) */
#define FORMAT_CHAR_n               'n'      /* Number of chars written */

/* Format flag values */
#define FORMAT_FLAG_LEFT_ALIGN      0x30     /* Left alignment padding */
#define FORMAT_FLAG_ZERO_PAD        0x20     /* Zero padding */
#define FORMAT_FLAG_SHOW_SIGN       0x10     /* Show sign */
#define FORMAT_FLAG_SPACE_PAD       0x8      /* Space padding */
#define FORMAT_FLAG_ALT_FORM        0x4      /* Alternate form */
#define FORMAT_FLAG_UPPERCASE        0x2      /* Uppercase output */
#define FORMAT_FLAG_SIGNED          0x1      /* Signed number */

/* ============================================================
 * FILE I/O CONSTANTS
 * ============================================================ */

/* File operations */
#define FILE_OPEN_READ              0         /* Open for reading */
#define FILE_OPEN_WRITE             1         /* Open for writing */
#define FILE_OPEN_APPEND            2         /* Open for appending */
#define FILE_CLOSE_ALL              0         /* Close all files */

/* File offsets */
#define FILE_OFFSET_STRING_TABLE    0x924     /* String table file offset */
#define FILE_OFFSET_OBJECT_TABLE    0xbe0     /* Object table file offset */
#define FILE_OFFSET_LOCATION_TABLE  0x1154    /* Location table file offset */

/* ============================================================
 * MESSAGE AND ERROR CODES
 * ============================================================ */

/* Message IDs */
#define MSG_UNKNOWN_COMMAND         0xd001    /* Unknown command message */
#define MSG_LOCATION_CHANGE_1       0xb082    /* Location change message 1 */
#define MSG_LOCATION_CHANGE_2       0xb086    /* Location change message 2 */
#define MSG_LOCATION_CHANGE_3       0xb08a    /* Location change message 3 */
#define MSG_LOCATION_CHANGE_4       0xb08e    /* Location change message 4 */
#define MSG_LOCATION_CHANGE_5       0xb092    /* Location change message 5 */
#define MSG_SPECIAL_LOCATION        0xd136    /* Special location message */
#define MSG_LOCATION_DARK           0xd090    /* Location is dark */
#define MSG_LOCATION_DARK_2         0xd091    /* Location is dark (variant 2) */
#define MSG_LOCATION_DARK_3         0xd092    /* Location is dark (variant 3) */
#define MSG_LOCATION_DARK_4         0xd093    /* Location is dark (variant 4) */
#define MSG_SPECIAL_ACTION_1        0xd079    /* Special action message 1 */
#define MSG_SPECIAL_ACTION_2        0xd07a    /* Special action message 2 */
#define MSG_ACTION_RESULT           0xd003    /* Action result message */
#define MSG_LOCATION_BASE           0xb8       /* Location message base */
#define MSG_LOCATION_MASK           0xd000    /* Location message mask */
#define MSG_NO_OBJECT_FOUND         0xd005    /* No object found message */
#define MSG_NO_OBJECT_SPECIFIED     0xd006    /* No object specified message */
#define MSG_CANT_SEE_OBJECT         0xd007    /* Can't see that object message */
#define MSG_WHICH_OBJECT            0xd008    /* Which object (disambiguation) message */
#define MSG_AMBIGUOUS_OBJECT        0xd004    /* Ambiguous object message */
#define MSG_ERROR_3                 0x3f8     /* Error message 3 */
#define MSG_ERROR_4                 0x3e1     /* Error message 4 */
#define MSG_ERROR_5                 0x3e2     /* Error message 5 */
#define MSG_ERROR_6                 0x3e3     /* Error message 6 */
#define MSG_ERROR_7                 0x3e4     /* Error message 7 */
#define MSG_ERROR_8                 0x3e5     /* Error message 8 */
#define MSG_ERROR_9                 0x3e6     /* Error message 9 */
#define MSG_GENERIC                 0xb017    /* Generic message */
#define MSG_LOOK_COMMAND            0xd04c    /* Look command message */
#define MSG_OBJECT_INFO             0xd055    /* Object information message */
#define MSG_LOCATION_DESC           0xd057    /* Location description message */
#define MSG_MOVE_SUCCESS            0xd067    /* Move success message */
#define MSG_TAKE_OBJECT             0xd070    /* Take object message */
#define MSG_DROP_OBJECT             0xd073    /* Drop object message */
#define MSG_OBJECT_TAKEN            0xd074    /* Object taken message */
#define MSG_OBJECT_DROPPED          0xd075    /* Object dropped message */
#define MSG_CANT_TAKE               0xd06c    /* Can't take object message */
#define MSG_CANT_DROP               0xd06a    /* Can't drop object message */
#define MSG_OBJECT_LIST             0xd06b    /* Object list message */
#define MSG_SPECIAL_ACTION_3        0x1006    /* Special action 3 */
#define MSG_SPECIAL_ACTION_4        0x1008    /* Special action 4 */
#define MSG_SPECIAL_ACTION_5        0x100d    /* Special action 5 */
#define MSG_SPECIAL_ACTION_6        0x1011    /* Special action 6 */
#define MSG_SPECIAL_ACTION_7        0x1016    /* Special action 7 */
#define MSG_COMMAND_1               0x9009    /* Command message 1 */
#define MSG_COMMAND_2               0x900a    /* Command message 2 */
#define MSG_COMMAND_3               0x900b    /* Command message 3 */
#define MSG_COMMAND_4               0x900c    /* Command message 4 */

/* Error codes */
#define ERROR_NONE                  0         /* No error */
#ifndef ERROR_FILE_NOT_FOUND
#define ERROR_FILE_NOT_FOUND        1         /* File not found */
#endif
#define ERROR_INVALID_COMMAND       2         /* Invalid command */
#define ERROR_INVALID_OBJECT        3         /* Invalid object */
#define ERROR_INVALID_LOCATION      4         /* Invalid location */
#define ERROR_INVENTORY_FULL        5         /* Inventory full */
#define ERROR_OBJECT_NOT_HERE       6         /* Object not in location */
#define ERROR_OBJECT_NOT_INVENTORY  7         /* Object not in inventory */

/* ============================================================
 * BIT MANIPULATION CONSTANTS
 * ============================================================ */

/* Bit masks */
#define BIT_MASK_0                 0x0        /* No bits set */
#define BIT_MASK_1                 0x1        /* Bit 0 */
#define BIT_MASK_2                 0x2        /* Bit 1 */
#define BIT_MASK_4                 0x4        /* Bit 2 */
#define BIT_MASK_8                 0x8        /* Bit 3 */
#define BIT_MASK_16                0x10       /* Bit 4 */
#define BIT_MASK_32                0x20       /* Bit 5 */
#define BIT_MASK_64                0x40       /* Bit 6 */
#define BIT_MASK_128               0x80       /* Bit 7 */
#define BIT_MASK_256               0x100      /* Bit 8 */
#define BIT_MASK_512               0x200      /* Bit 9 */
#define BIT_MASK_1024              0x400      /* Bit 10 */
#define BIT_MASK_2048              0x800      /* Bit 11 */
#define BIT_MASK_4095              0xfff      /* Bit mask 4095 (12 bits) */
#define BIT_MASK_4096              0x1000     /* Bit 12 */
#define BIT_MASK_8192              0x2000     /* Bit 13 */
#define BIT_MASK_16384             0x4000     /* Bit 14 */
#define BIT_MASK_32768             0x8000     /* Bit 15 */
#define BIT_MASK_4095              0xfff      /* Bit mask 4095 (12 bits) */
#define BIT_MASK_4096              0x1000     /* Bit 12 */
#define BIT_MASK_8192              0x2000     /* Bit 13 */
#define BIT_MASK_2048              0x800      /* Bit 11 */
#define CHAR_SPACE                 0x20       /* Space character */
#define CHAR_ZERO                  0x30       /* Zero character '0' */
#define DOS_INT_21H                0x21      /* DOS interrupt 21h */
#define VIDEO_INT_10H               0x10      /* Video interrupt 10h */
#define BIT_MASK_1536              0x600      /* Bit mask 1536 (0x600) */
#define BIT_MASK_1024              0x400      /* Bit 10 */
#define BIT_MASK_512               0x200      /* Bit 9 */
#define BIT_MASK_0xfffe            0xfffe     /* 0xfffe bit mask */
#define BIT_MASK_0xff00            0xFF00     /* 0xFF00 bit mask */
#define BIT_MASK_0x7fff            0x7fff     /* 0x7fff bit mask */
#define BIT_MASK_32767             0x7fff     /* Bit mask for 32767 (same as 0x7fff) */
#define BIT_MASK_LOW_8              0xff       /* Lower 8 bits mask */
#define CHAR_SPECIAL_A000           0xa000     /* Special character A000 */
#define BIT_MASK_0xef               0xef       /* 0xef bit mask */
#define BIT_MASK_0xbf               0xbf       /* 0xbf bit mask */
#define BIT_MASK_0x81               0x81       /* 0x81 bit mask */
#define MEM_POINTER_STORAGE_5       0x608     /* Pointer storage address 5 */
#define MEM_POINTER_STORAGE_6       0x904     /* Pointer storage address 6 */
#define MEM_COUNTER_3               0xf6      /* General counter 3 */
#define MEM_POINTER_STORAGE_7       0x78c     /* Pointer storage address 7 */
#define MEM_POINTER_STORAGE_8       0x5e0     /* Pointer storage address 8 */
#define MEM_POINTER_STORAGE_9       0x8e8     /* Pointer storage address 9 */
#define MEM_POINTER_STORAGE_10      0x5ef     /* Pointer storage address 10 */
#define MEM_POINTER_STORAGE_11      0x9a2     /* Pointer storage address 11 */
#define MEM_POINTER_STORAGE_12      0x58a     /* Pointer storage address 12 */
#define MEM_POINTER_STORAGE_13      0xf00     /* Pointer storage address 13 */
#define MEM_POINTER_STORAGE_14      0xeff     /* Pointer storage address 14 */
#define MEM_POINTER_STORAGE_15      0xeb0     /* Pointer storage address 15 */
#define MEM_POINTER_STORAGE_16      0xe94     /* Pointer storage address 16 */
#define MEM_POINTER_STORAGE_17      0xea6     /* Pointer storage address 17 */
#define MEM_POINTER_STORAGE_18      0xfa4     /* Pointer storage address 18 */
#define MEM_POINTER_STORAGE_19      0x590     /* Pointer storage address 19 */
#define MEM_POINTER_STORAGE_20      0x901     /* Pointer storage address 20 */
#define MEM_POINTER_STORAGE_21      0x18af    /* Pointer storage address 21 */
#define MEM_POINTER_STORAGE_22      0x22a     /* Pointer storage address 22 */
#define MEM_POINTER_STORAGE_23      0x910     /* Pointer storage address 23 */
#define MEM_POINTER_STORAGE_24      0x101a    /* Pointer storage address 24 */
#define MEM_POINTER_STORAGE_25      0xff0     /* Pointer storage address 25 */
#define MEM_POINTER_STORAGE_26      0x91d     /* Pointer storage address 26 */
#define MEM_POINTER_STORAGE_27      0xeb2     /* Pointer storage address 27 */
#define MEM_POINTER_STORAGE_28      0x5e2     /* Pointer storage address 28 */
#define MEM_POINTER_STORAGE_29      0x5f1     /* Pointer storage address 29 */
#define MEM_POINTER_STORAGE_30      0x622     /* Pointer storage address 30 */
#define MEM_POINTER_STORAGE_31      0x942     /* Pointer storage address 31 */
#define MEM_POINTER_STORAGE_32      0xf90     /* Pointer storage address 32 */
#define MEM_POINTER_STORAGE_33      0xf92     /* Pointer storage address 33 */
#define MEM_STACK_OFFSET_680C       0x680c    /* Stack offset for register storage */
#define RETURN_VALUE_1800           0x1800    /* Return value 0x1800 */
#define MEM_POINTER_STORAGE_35      0x620     /* Pointer storage address 35 */
#define MEM_FILE_BUFFER_2          0x65e     /* File buffer 2 */
#define MSG_SPECIAL_ACTION_8       0x1004    /* Special action 8 */
#define OBJ_ID_SPECIAL_55          0x55      /* Special object ID 55 */
#define OFFSET_PARAM_34            0x34      /* Parameter 34 offset */
#define OFFSET_PARAM_14            0x14      /* Parameter 14 offset */
#define BIT_MASK_0x1c              0x1c      /* 0x1c bit mask */
/* Removed duplicate FORMAT_CHAR_X, FORMAT_CHAR_E, FORMAT_CHAR_G - already defined above as character literals */
#define FORMAT_CHAR_I              0x69      /* Format character 'i' */
#define FORMAT_CHAR_G_LOWER        0x67      /* Format character 'g' */
#define FORMAT_CHAR_X_LOWER        0x78      /* Format character 'x' */
#define MEM_POINTER_STORAGE_36      0xef7     /* Pointer storage address 36 */
#define MEM_POINTER_STORAGE_37      0xef9     /* Pointer storage address 37 */
#define MEM_POINTER_STORAGE_38      0xefe     /* Pointer storage address 38 */
#define MEM_POINTER_STORAGE_119     0xeb5     /* Pointer storage address 119 */
#define MEM_POINTER_STORAGE_120     0xeb6     /* Pointer storage address 120 */
#define MEM_POINTER_STORAGE_121     0xec0     /* Pointer storage address 121 */
#define MEM_POINTER_STORAGE_122     0x925     /* Pointer storage address 122 */
#define MEM_POINTER_STORAGE_123     0x944     /* Pointer storage address 123 */
#define MEM_POINTER_STORAGE_124     0xf88     /* Pointer storage address 124 */
#define MEM_POINTER_STORAGE_125     0xeaa     /* Pointer storage address 125 */
#define MEM_POINTER_STORAGE_126     0x95a     /* Pointer storage address 126 */
#define MEM_POINTER_STORAGE_119     0xeb5     /* Pointer storage address 119 */
#define MEM_POINTER_STORAGE_120     0xeb6     /* Pointer storage address 120 */
#define MEM_POINTER_STORAGE_121     0xec0     /* Pointer storage address 121 */
#define MEM_POINTER_STORAGE_122     0x925     /* Pointer storage address 122 */
#define MEM_POINTER_STORAGE_123     0x944     /* Pointer storage address 123 */
#define MEM_POINTER_STORAGE_124     0xf88     /* Pointer storage address 124 */
#define MEM_POINTER_STORAGE_125     0xeaa     /* Pointer storage address 125 */
#define MEM_POINTER_STORAGE_126     0x95a     /* Pointer storage address 126 */
#define MEM_POINTER_STORAGE_127     0xff5     /* Pointer storage address 127 */
#define MEM_POINTER_STORAGE_128     0x62c     /* Pointer storage address 128 */
#define MEM_POINTER_STORAGE_129     0x61e     /* Pointer storage address 129 */
#define MEM_POINTER_STORAGE_130     0x562     /* Pointer storage address 130 */
#define MEM_POINTER_STORAGE_131     0x83      /* Pointer storage address 131 */
#define MEM_POINTER_STORAGE_132     0x84      /* Pointer storage address 132 */
#define MEM_POINTER_STORAGE_133     0x85      /* Pointer storage address 133 */
#define MEM_POINTER_STORAGE_134     0x86      /* Pointer storage address 134 */
#define MEM_POINTER_STORAGE_135     0x87      /* Pointer storage address 135 */
#define MEM_POINTER_STORAGE_136     0x88      /* Pointer storage address 136 */
#define MEM_POINTER_STORAGE_151     0x97      /* Pointer storage address 151 */
#define MEM_POINTER_STORAGE_152     0x98      /* Pointer storage address 152 */
#define MEM_POINTER_STORAGE_153     0x99      /* Pointer storage address 153 */
#define MEM_POINTER_STORAGE_154     0x9a      /* Pointer storage address 154 */
#define MEM_POINTER_STORAGE_155     0x9b      /* Pointer storage address 155 */
#define MEM_POINTER_STORAGE_156     0x9c      /* Pointer storage address 156 */
#define MEM_POINTER_STORAGE_157     0x9d      /* Pointer storage address 157 */
#define MEM_POINTER_STORAGE_158     0x9e      /* Pointer storage address 158 */
#define MEM_POINTER_STORAGE_159     0x9f      /* Pointer storage address 159 */
#define MEM_POINTER_STORAGE_160     0xa0      /* Pointer storage address 160 */
#define MEM_POINTER_STORAGE_161     0xa1      /* Pointer storage address 161 */
#define MEM_POINTER_STORAGE_162     0xa2      /* Pointer storage address 162 */
#define MEM_POINTER_STORAGE_163     0xa3      /* Pointer storage address 163 */
#define MEM_POINTER_STORAGE_164     0xa4      /* Pointer storage address 164 */
#define MEM_POINTER_STORAGE_166     0xa6      /* Pointer storage address 166 */
#define MEM_POINTER_STORAGE_167     0xa7      /* Pointer storage address 167 */
#define MSG_SPECIAL_ACTION_9        0xd023    /* Special action 9 */
#define MSG_SPECIAL_ACTION_10       0xd04c    /* Special action 10 */
#define MSG_SPECIAL_ACTION_11       0xd098    /* Special action 11 */
#define MSG_SPECIAL_ACTION_12       0xd099    /* Special action 12 */
#define MSG_SPECIAL_ACTION_13       0xd0a1    /* Special action 13 */
#define MSG_SPECIAL_ACTION_14       0xd03b    /* Special action 14 */
#define MSG_SPECIAL_ACTION_15       0xd04d    /* Special action 15 */
#define MSG_SPECIAL_ACTION_16       0xd04f    /* Special action 16 */
#define MSG_SPECIAL_ACTION_17       0xd04e    /* Special action 17 */
#define MSG_SPECIAL_ACTION_18       0xd049    /* Special action 18 */
#define MSG_SPECIAL_ACTION_19       0xd04a    /* Special action 19 */
#define MSG_SPECIAL_ACTION_20       0xd04b    /* Special action 20 */
#define MSG_SPECIAL_ACTION_21       0xd048    /* Special action 21 */
#define MSG_SPECIAL_ACTION_22       0xd046    /* Special action 22 */
#define MSG_SPECIAL_ACTION_23       0xd050    /* Special action 23 */
#define MSG_SPECIAL_ACTION_24       0xd052    /* Special action 24 */
#define MSG_SPECIAL_ACTION_25       0xd054    /* Special action 25 */
#define MSG_SPECIAL_ACTION_26       0xd051    /* Special action 26 */
#define MSG_SPECIAL_ACTION_27       0xd05a    /* Special action 27 */
#define MSG_SPECIAL_ACTION_28       0xd05c    /* Special action 28 */
#define MSG_SPECIAL_ACTION_29       0xd05d    /* Special action 29 */
#define MSG_SPECIAL_ACTION_30       0xd05f    /* Special action 30 */
#define MSG_SPECIAL_ACTION_31       0xd05e    /* Special action 31 */
#define MSG_SPECIAL_ACTION_32       0xd063    /* Special action 32 */
#define MSG_SPECIAL_ACTION_33       0xd061    /* Special action 33 */
#define MSG_SPECIAL_ACTION_34       0xd095    /* Special action 34 */
#define MSG_SPECIAL_ACTION_35       0xd097    /* Special action 35 */
#define MSG_SPECIAL_ACTION_36       0xd0c2    /* Special action 36 */
#define MSG_SPECIAL_ACTION_37       0xd0bf    /* Special action 37 */
#define MSG_SPECIAL_ACTION_38       0xd0c0    /* Special action 38 */
#define MSG_SPECIAL_ACTION_39       0xd0c1    /* Special action 39 */
#define MSG_SPECIAL_ACTION_40       0xd07d    /* Special action 40 */
#define MSG_SPECIAL_ACTION_41       0xd077    /* Special action 41 */
#define MSG_SPECIAL_ACTION_42       0xd064    /* Special action 42 */
#define MSG_SPECIAL_ACTION_43       0xd066    /* Special action 43 */
#define CHAR_SPECIAL_A0            0xa0      /* Special character A0 */
#define MEM_POINTER_STORAGE_39      0xef5     /* Pointer storage address 39 */
#define MEM_POINTER_STORAGE_40      0xefb     /* Pointer storage address 40 */
#define MEM_POINTER_STORAGE_41      0x903     /* Pointer storage address 41 */
#define MEM_POINTER_STORAGE_42      0x905     /* Pointer storage address 42 */
#define MEM_POINTER_STORAGE_43      0x907     /* Pointer storage address 43 */
#define MEM_POINTER_STORAGE_44      0xeac     /* Pointer storage address 44 */
#define MEM_POINTER_STORAGE_45      0xeb4     /* Pointer storage address 45 */
#define MEM_DISPLAY_STRING_7       0x7c      /* Display string buffer 7 */
#define MEM_DISPLAY_STRING_8       0x7e      /* Display string buffer 8 */
#define MEM_STRING_PTR_14          0x5b64    /* String pointer 14 */
#define MEM_POINTER_STORAGE_46      0xa74     /* Pointer storage address 46 */
#define MEM_POINTER_STORAGE_47      0x5dbe    /* Pointer storage address 47 */
#define MEM_POINTER_STORAGE_48      0x47a     /* Pointer storage address 48 */
#define BIT_MASK_0xfff0            0xfff0    /* 0xfff0 bit mask */
#define MEM_POINTER_STORAGE_49      0xfd4     /* Pointer storage address 49 */
#define MEM_POINTER_STORAGE_50      0x1082    /* Pointer storage address 50 */
#define MEM_POINTER_STORAGE_51      0x1084    /* Pointer storage address 51 */
#define MEM_POINTER_STORAGE_52      0x10ea    /* Pointer storage address 52 */
#define MEM_POINTER_STORAGE_53      0x58e     /* Pointer storage address 53 */
#define MEM_SPECIAL_VALUE_4        0xd000    /* Special value 4 */
#define MEM_SPECIAL_VALUE_5        0xd0      /* Special value 5 */
#define MEM_BUFFER_OFFSET_A9C      0xa9c     /* Buffer offset A9C */
#define MEM_POINTER_STORAGE_54      0x91f     /* Pointer storage address 54 */
#define MEM_POINTER_STORAGE_55      0x90b     /* Pointer storage address 55 */
#define MEM_POINTER_STORAGE_56      0xeae     /* Pointer storage address 56 */
#define MEM_POINTER_STORAGE_57      0xfee     /* Pointer storage address 57 */
#define MEM_POINTER_STORAGE_58      0x8d4     /* Pointer storage address 58 */
#define MEM_POINTER_STORAGE_59      0x1018    /* Pointer storage address 59 */
#define MEM_POINTER_STORAGE_60      0x928     /* Pointer storage address 60 */
#define MEM_POINTER_STORAGE_61      0x968     /* Pointer storage address 61 */
#define MEM_POINTER_STORAGE_62      0x967     /* Pointer storage address 62 */
#define MEM_POINTER_STORAGE_63      0x91b     /* Pointer storage address 63 */
#define MEM_POINTER_STORAGE_64      0x792     /* Pointer storage address 64 */
#define MEM_POINTER_STORAGE_65      0x780     /* Pointer storage address 65 */
#define MEM_POINTER_STORAGE_66      0x784     /* Pointer storage address 66 */
#define MEM_POINTER_STORAGE_67      0x8fe     /* Pointer storage address 67 */
#define MEM_POINTER_STORAGE_68      0x8fa     /* Pointer storage address 68 */
#define MEM_SPECIAL_VALUE_6        0x5755    /* Special value 6 */
#define MEM_SPECIAL_VALUE_7        0x1c00    /* Special value 7 */
#define MEM_POINTER_STORAGE_69      0x100a    /* Pointer storage address 69 */
#define MEM_POINTER_STORAGE_70      0x100c    /* Pointer storage address 70 */
#define MEM_POINTER_STORAGE_71      0x1021    /* Pointer storage address 71 */
#define MEM_POINTER_STORAGE_72      0x1026    /* Pointer storage address 72 */
#define MEM_POINTER_STORAGE_73      0x1028    /* Pointer storage address 73 */
#define MEM_POINTER_STORAGE_74      0x1df9    /* Pointer storage address 74 */
#define MEM_POINTER_STORAGE_75      0x1dfb    /* Pointer storage address 75 */
#define MEM_POINTER_STORAGE_76      0x1dfd    /* Pointer storage address 76 */
#define MEM_POINTER_STORAGE_77      0x1dff    /* Pointer storage address 77 */
#define MEM_POINTER_STORAGE_78      0x1e70    /* Pointer storage address 78 */
#define MEM_POINTER_STORAGE_79      0x222     /* Pointer storage address 79 */
#define MEM_POINTER_STORAGE_80      0x228     /* Pointer storage address 80 */
#define MEM_POINTER_STORAGE_81      0x603     /* Pointer storage address 81 */
#define MEM_POINTER_STORAGE_82      0x500     /* Pointer storage address 82 */
#define MEM_POINTER_STORAGE_83      0x550     /* Pointer storage address 83 */
#define MEM_POINTER_STORAGE_84      0x562     /* Pointer storage address 84 */
#define MEM_POINTER_STORAGE_85      0x61e     /* Pointer storage address 85 */
#define MEM_POINTER_STORAGE_86      0x62c     /* Pointer storage address 86 */
#define MEM_POINTER_STORAGE_87      0x64c     /* Pointer storage address 87 */
#define MEM_POINTER_STORAGE_88      0x680e    /* Pointer storage address 88 */
#define MEM_POINTER_STORAGE_89      0x6600    /* Pointer storage address 89 */
#define MEM_POINTER_STORAGE_90      0x1000    /* Pointer storage address 90 */
#define MEM_POINTER_STORAGE_91      0x3cb8    /* Pointer storage address 91 */
#define MEM_POINTER_STORAGE_92      0x3d0a    /* Pointer storage address 92 */
#define MEM_POINTER_STORAGE_93      0x3cb0    /* Pointer storage address 93 */
#define MEM_POINTER_STORAGE_94      0x3cad    /* Pointer storage address 94 */
#define MEM_POINTER_STORAGE_95      0x44e     /* Pointer storage address 95 */
#define MEM_POINTER_STORAGE_96      0x462     /* Pointer storage address 96 */
#define MEM_POINTER_STORAGE_97      0x466     /* Pointer storage address 97 */
#define MEM_POINTER_STORAGE_98      0x47c     /* Pointer storage address 98 */
#define MEM_POINTER_STORAGE_99      0x47cb    /* Pointer storage address 99 */
#define MEM_POINTER_STORAGE_100     0x44      /* Pointer storage address 100 */
#define MEM_POINTER_STORAGE_101     0x47      /* Pointer storage address 101 */
#define MEM_POINTER_STORAGE_102     0x4c      /* Pointer storage address 102 */
#define MEM_POINTER_STORAGE_103     0x12      /* Pointer storage address 103 */
#define MEM_POINTER_STORAGE_104     0x16      /* Pointer storage address 104 */
#define MEM_POINTER_STORAGE_105     0x19      /* Pointer storage address 105 */
#define MEM_POINTER_STORAGE_106     0x1f      /* Pointer storage address 106 */
#define MEM_POINTER_STORAGE_107     0x22      /* Pointer storage address 107 */
#define MEM_POINTER_STORAGE_108     0x25      /* Pointer storage address 108 */
#define MEM_POINTER_STORAGE_109     0x26      /* Pointer storage address 109 */
#define MEM_POINTER_STORAGE_110     0x2f      /* Pointer storage address 110 */
#define MEM_POINTER_STORAGE_111     0x32      /* Pointer storage address 111 */
#define MEM_POINTER_STORAGE_112     0x35      /* Pointer storage address 112 */
#define MEM_POINTER_STORAGE_113     0x39      /* Pointer storage address 113 */
#define MEM_POINTER_STORAGE_114     0x57      /* Pointer storage address 114 */
#define MEM_SPECIAL_VALUE_8        0x269ec3  /* Special value 8 */
#define MEM_SPECIAL_VALUE_9        0x2fad    /* Special value 9 */
#define MEM_POINTER_STORAGE_115     0x929     /* Pointer storage address 115 */
#define MEM_POINTER_STORAGE_116     0x90e     /* Pointer storage address 116 */
#define MEM_POINTER_STORAGE_117     0x8ac     /* Pointer storage address 117 */
#define MEM_POINTER_STORAGE_118     0x64c     /* Pointer storage address 118 */
#define OFFSET_PARAM_1A            0x1a      /* Parameter 1A offset */
#define BIT_MASK_LOW_7             0x7f       /* Lower 7 bits */
#define BIT_MASK_LOW_16            0xffff     /* Lower 16 bits */
#define BIT_MASK_0x20              0x20       /* 0x20 bit mask */
#define BIT_SHIFT_16               16         /* 16-bit shift (0x10) */
#define SIZE_16                    0x10       /* Size 16 (0x10) */
#define BIT_MASK_0xc               0xc        /* 0xc bit mask */
#define BIT_MASK_0xf               0xf        /* Low nibble mask */
#define SIZE_12                    0xc        /* Size 12 (0xc) */
#define MEM_POINTER_STORAGE_137     0x226     /* Pointer storage address 137 */
#define MEM_POINTER_STORAGE_138     0x227     /* Pointer storage address 138 */
#define MEM_POINTER_STORAGE_139     0x228     /* Pointer storage address 139 */
#define MEM_POINTER_STORAGE_141     0x22a     /* Pointer storage address 141 */
#define MEM_POINTER_STORAGE_142     0x22b     /* Pointer storage address 142 */
#define MEM_POINTER_STORAGE_143     0x22c     /* Pointer storage address 143 */
#define MEM_POINTER_STORAGE_144     0x22d     /* Pointer storage address 144 */
#define MEM_POINTER_STORAGE_145     0x22e     /* Pointer storage address 145 */
#define MEM_POINTER_STORAGE_146     0x22f     /* Pointer storage address 146 */
#define MEM_POINTER_STORAGE_147     0x230     /* Pointer storage address 147 */
#define MEM_POINTER_STORAGE_148     0x231     /* Pointer storage address 148 */
#define MEM_POINTER_STORAGE_149     0x232     /* Pointer storage address 149 */
#define MEM_POINTER_STORAGE_150     0x233     /* Pointer storage address 150 */
#define SIZE_36                    0x24      /* Size 36 (0x24) */
#define SIZE_144                   0x90      /* Size 144 (0x90) */
#define BIT_MASK_3_BITS            0x3        /* 3-bit mask */
#define BIT_MASK_4_BITS            0xf        /* 4-bit mask (low nibble) */
#define BIT_MASK_6_BITS            0x3f       /* 6-bit mask */
#define BIT_SHIFT_12               12         /* 12-bit left shift (0xc) */
#define OFFSET_PARAM_32            0x32       /* Parameter 32 offset */
#define OFFSET_OBJECT_COUNT_OFFSET_1  0x459    /* Object count offset 1 */
#define OFFSET_OBJECT_COUNT_OFFSET_2  0x458    /* Object count offset 2 */
#define OFFSET_OBJECT_COUNT_OFFSET_3  0x43e    /* Object count offset 3 */
#define OFFSET_OBJECT_COUNT_OFFSET_4  0x43f    /* Object count offset 4 */
#define OFFSET_OBJECT_COUNT_OFFSET_5  0x43c    /* Object count offset 5 */
#define MSG_SPECIAL_ACTION_44       0xd12d    /* Special action 44 */
#define MSG_SPECIAL_ACTION_45       0x1ae2    /* Special action 45 */
#define MEM_SPECIAL_VALUE_12        0x19b4    /* Special value 12 */
#define MEM_SPECIAL_VALUE_13        0x11ed    /* Special value 13 */
#define MEM_SPECIAL_VALUE_14        0x4023    /* Special value 14 */
#define MEM_SPECIAL_VALUE_15        0x4024    /* Special value 15 */
#define MEM_SPECIAL_VALUE_16        0x4025    /* Special value 16 */
#define BIT_MASK_0x30              0x30       /* 0x30 bit mask */
#define BIT_MASK_380               0x380      /* 380 bit mask */
#define BIT_MASK_0xf7              0xf7       /* 0xf7 bit mask */
#define BIT_MASK_0xfe              0xfe       /* 0xfe bit mask */
#define BIT_MASK_0xef              0xef       /* 0xef bit mask */
#define BIT_MASK_0xfb              0xfb       /* 0xfb bit mask */
#define SIZE_384                     0x180     /* Size 384 (0x180) */
#define MEM_POINTER_STORAGE_168     0x620     /* Pointer storage address 168 */
#define MEM_POINTER_STORAGE_169     0x054e    /* Pointer storage address 169 */
#define MEM_POINTER_STORAGE_170     0x3c82    /* Pointer storage address 170 */
#define MEM_POINTER_STORAGE_171     0x224     /* Pointer storage address 171 */
#define MEM_POINTER_STORAGE_172     0x220     /* Pointer storage address 172 */
#define MEM_POINTER_STORAGE_173     0x21e     /* Pointer storage address 173 */
#define MEM_POINTER_STORAGE_174     0x500     /* Pointer storage address 174 */
#define MEM_POINTER_STORAGE_175     0x77d     /* Pointer storage address 175 */
#define MEM_POINTER_STORAGE_176     0x79c     /* Pointer storage address 176 */
#define MEM_POINTER_STORAGE_177     0x38a9    /* Pointer storage address 177 */
#define MEM_POINTER_STORAGE_178     0x4a8     /* Pointer storage address 178 */
#define MEM_POINTER_STORAGE_179     0x4c1     /* Pointer storage address 179 */
#define MEM_POINTER_STORAGE_180     0x4d5     /* Pointer storage address 180 */
#define MEM_POINTER_STORAGE_181     0x776     /* Pointer storage address 181 */
#define MEM_POINTER_STORAGE_182     0x1100    /* Pointer storage address 182 */
#define MEM_POINTER_STORAGE_183     0x1600    /* Pointer storage address 183 */
#define MEM_FILE_OFFSET_1           0x1       /* File offset 1 */
#define MEM_FILE_OFFSET_2           0x2       /* File offset 2 */
#define MEM_FILE_OFFSET_3           0x3       /* File offset 3 */
#define MEM_FILE_OFFSET_4           0x8302    /* File offset 4 */
#define MEM_SPECIAL_VALUE_17         0x00014010 /* Special value 17 */
#define MEM_SPECIAL_VALUE_18         0x0001476a /* Special value 18 */
#define MEM_SPECIAL_VALUE_19         0x00014f7e /* Special value 19 */
#define OFFSET_OBJECT_109           0x109     /* Object offset 109 */
#define OFFSET_OBJECT_10B           0x10b     /* Object offset 10B */
#define OFFSET_OBJECT_10E           0x10e     /* Object offset 10E */
#define MEM_POINTER_STORAGE_184     0x1002    /* Pointer storage address 184 */
#define MEM_POINTER_STORAGE_185     0x1011    /* Pointer storage address 185 */
#define MEM_POINTER_STORAGE_186     0x1017    /* Pointer storage address 186 */
#define MEM_POINTER_STORAGE_187     0x101b    /* Pointer storage address 187 */
#define MEM_POINTER_STORAGE_188     0x102a    /* Pointer storage address 188 */
#define MEM_POINTER_STORAGE_189     0x102e    /* Pointer storage address 189 */
#define MEM_POINTER_STORAGE_190     0x1030    /* Pointer storage address 190 */
#define MEM_POINTER_STORAGE_191     0x1032    /* Pointer storage address 191 */
#define MEM_POINTER_STORAGE_192     0x1034    /* Pointer storage address 192 */
#define MEM_POINTER_STORAGE_193     0x1035    /* Pointer storage address 193 */
#define MEM_POINTER_STORAGE_194     0x1035    /* Pointer storage address 194 (duplicate of 193) */
#define MEM_POINTER_STORAGE_195     0x12ea    /* Pointer storage address 195 */
#define MEM_POINTER_STORAGE_196     0x2310    /* Pointer storage address 196 */
#define MEM_POINTER_STORAGE_197     0x237f    /* Pointer storage address 197 */
#define MEM_POINTER_STORAGE_198     0x253e    /* Pointer storage address 198 */
#define MEM_POINTER_STORAGE_199     0x256e    /* Pointer storage address 199 */
#define MEM_POINTER_STORAGE_200     0x258e    /* Pointer storage address 200 */
#define MEM_POINTER_STORAGE_201     0x25b4    /* Pointer storage address 201 */
#define MEM_POINTER_STORAGE_202     0x26d0    /* Pointer storage address 202 */
#define MEM_POINTER_STORAGE_203     0x26fa    /* Pointer storage address 203 */
#define MEM_POINTER_STORAGE_204     0x280d    /* Pointer storage address 204 */
#define MEM_POINTER_STORAGE_205     0x2901    /* Pointer storage address 205 */
#define MEM_POINTER_STORAGE_206     0x2fd0    /* Pointer storage address 206 */
#define MEM_POINTER_STORAGE_207     0x33fa    /* Pointer storage address 207 */
#define MEM_POINTER_STORAGE_208     0x3491    /* Pointer storage address 208 */
#define MEM_POINTER_STORAGE_209     0x34af    /* Pointer storage address 209 */
#define MEM_POINTER_STORAGE_210     0x34bc    /* Pointer storage address 210 */
#define MEM_POINTER_STORAGE_211     0x34c9    /* Pointer storage address 211 */
#define MEM_POINTER_STORAGE_212     0x34d3    /* Pointer storage address 212 */
#define MEM_POINTER_STORAGE_213     0x3502    /* Pointer storage address 213 */
#define MEM_POINTER_STORAGE_214     0x355b    /* Pointer storage address 214 */
#define MEM_POINTER_STORAGE_215     0x3568    /* Pointer storage address 215 */
#define MEM_POINTER_STORAGE_216     0x357f    /* Pointer storage address 216 */
#define MEM_POINTER_STORAGE_217     0x35de    /* Pointer storage address 217 */
#define MEM_POINTER_STORAGE_218     0x35f2    /* Pointer storage address 218 */
#define MEM_POINTER_STORAGE_219     0x3621    /* Pointer storage address 219 */
#define MEM_POINTER_STORAGE_220     0x362e    /* Pointer storage address 220 */
#define MEM_POINTER_STORAGE_221     0x364a    /* Pointer storage address 221 */
#define MEM_POINTER_STORAGE_222     0x367c    /* Pointer storage address 222 */
#define MEM_POINTER_STORAGE_223     0x3694    /* Pointer storage address 223 */
#define MEM_POINTER_STORAGE_224     0x36a5    /* Pointer storage address 224 */
#define MEM_POINTER_STORAGE_225     0x380     /* Pointer storage address 225 */
#define MEM_POINTER_STORAGE_226     0x4000    /* Pointer storage address 226 */
#define MEM_POINTER_STORAGE_227     0x400a    /* Pointer storage address 227 */
#define MEM_POINTER_STORAGE_228     0x4016    /* Pointer storage address 228 */
#define MEM_POINTER_STORAGE_229     0x401a    /* Pointer storage address 229 */
#define MEM_POINTER_STORAGE_230     0x401f    /* Pointer storage address 230 */
#define MEM_POINTER_STORAGE_231     0x4025    /* Pointer storage address 231 */
#define MEM_POINTER_STORAGE_232     0x4130    /* Pointer storage address 232 */
#define MEM_POINTER_STORAGE_233     0x43fd    /* Pointer storage address 233 */
#define MEM_POINTER_STORAGE_234     0x460     /* Pointer storage address 234 */
#define MEM_POINTER_STORAGE_235     0x47e     /* Pointer storage address 235 */
#define MEM_POINTER_STORAGE_236     0x487     /* Pointer storage address 236 */
#define MEM_POINTER_STORAGE_237     0x515c    /* Pointer storage address 237 */
#define MEM_POINTER_STORAGE_238     0x518b    /* Pointer storage address 238 */
#define MEM_POINTER_STORAGE_239     0x5196    /* Pointer storage address 239 */
#define MEM_POINTER_STORAGE_240     0x51a1    /* Pointer storage address 240 */
#define MEM_POINTER_STORAGE_241     0x5b8a    /* Pointer storage address 241 */
#define MEM_POINTER_STORAGE_242     0x5dc1    /* Pointer storage address 242 */
#define MEM_POINTER_STORAGE_243     0x5e2     /* Pointer storage address 243 */
#define MEM_POINTER_STORAGE_244     0x5f4e    /* Pointer storage address 244 */
#define MEM_POINTER_STORAGE_245     0x5f5d    /* Pointer storage address 245 */
#define MEM_POINTER_STORAGE_246     0x659d    /* Pointer storage address 246 */
#define MEM_POINTER_STORAGE_247     0x6603    /* Pointer storage address 247 */
#define MEM_POINTER_STORAGE_248     0x6605    /* Pointer storage address 248 */
#define MEM_POINTER_STORAGE_249     0x6608    /* Pointer storage address 249 */
#define MEM_POINTER_STORAGE_250     0x6609    /* Pointer storage address 250 */
#define MEM_POINTER_STORAGE_251     0x660a    /* Pointer storage address 251 */
#define MEM_POINTER_STORAGE_252     0x660b    /* Pointer storage address 252 */
#define MEM_POINTER_STORAGE_253     0x788     /* Pointer storage address 253 */
#define MEM_POINTER_STORAGE_254     0x78e     /* Pointer storage address 254 */
#define MEM_POINTER_STORAGE_255     0x79a     /* Pointer storage address 255 */
#define MEM_POINTER_STORAGE_256     0x7af     /* Pointer storage address 256 */
#define MEM_POINTER_STORAGE_257     0x8400    /* Pointer storage address 257 */
#define MEM_POINTER_STORAGE_258     0x8ea     /* Pointer storage address 258 */
#define MEM_POINTER_STORAGE_259     0x900b    /* Pointer storage address 259 */
#define MEM_POINTER_STORAGE_260     0x900c    /* Pointer storage address 260 */
#define MEM_POINTER_STORAGE_261     0x921     /* Pointer storage address 261 */
#define MEM_POINTER_STORAGE_262     0x923     /* Pointer storage address 262 */
#define MEM_POINTER_STORAGE_263     0x927     /* Pointer storage address 263 */
#define MEM_POINTER_STORAGE_264     0x940     /* Pointer storage address 264 */
#define MEM_POINTER_STORAGE_265     0x946     /* Pointer storage address 265 */
#define MEM_POINTER_STORAGE_266     0x94a     /* Pointer storage address 266 */
#define MEM_POINTER_STORAGE_267     0x94c     /* Pointer storage address 267 */
#define MEM_POINTER_STORAGE_268     0x94e     /* Pointer storage address 268 */
#define MEM_POINTER_STORAGE_269     0x950     /* Pointer storage address 269 */
#define MEM_POINTER_STORAGE_270     0x952     /* Pointer storage address 270 */
#define MEM_POINTER_STORAGE_271     0xa74     /* Pointer storage address 271 */
#define MEM_POINTER_STORAGE_272     0xb000    /* Pointer storage address 272 */
#define MEM_POINTER_STORAGE_273     0xb0aa    /* Pointer storage address 273 */
#define MEM_POINTER_STORAGE_274     0xb0fa    /* Pointer storage address 274 */
#define MEM_POINTER_STORAGE_275     0xc000    /* Pointer storage address 275 */
#define MEM_POINTER_STORAGE_276     0xd00     /* Pointer storage address 276 */
#define MEM_POINTER_STORAGE_277     0xd00b    /* Pointer storage address 277 */
#define MEM_POINTER_STORAGE_278     0xd00c    /* Pointer storage address 278 */
#define MEM_POINTER_STORAGE_279     0xd012    /* Pointer storage address 279 */
#define MEM_POINTER_STORAGE_280     0xd013    /* Pointer storage address 280 */
#define MEM_POINTER_STORAGE_281     0xd016    /* Pointer storage address 281 */
#define MEM_POINTER_STORAGE_282     0xd024    /* Pointer storage address 282 */
#define MEM_POINTER_STORAGE_283     0xd026    /* Pointer storage address 283 */
#define MSG_SPECIAL_ACTION_46       0xd030    /* Special action message 46 */
#define MSG_SPECIAL_ACTION_47       0xd031    /* Special action message 47 */
#define MSG_SPECIAL_ACTION_48       0xd032    /* Special action message 48 */
#define MSG_SPECIAL_ACTION_49       0xd033    /* Special action message 49 */
#define MSG_SPECIAL_ACTION_50       0xd034    /* Special action message 50 */
#define MSG_SPECIAL_ACTION_51       0xd035    /* Special action message 51 */
#define MSG_SPECIAL_ACTION_52       0xd036    /* Special action message 52 */
#define MSG_SPECIAL_ACTION_53       0xd037    /* Special action message 53 */
#define MSG_SPECIAL_ACTION_54       0xd038    /* Special action message 54 */
#define MSG_SPECIAL_ACTION_55       0xd039    /* Special action message 55 */
#define MSG_SPECIAL_ACTION_56       0xd03a    /* Special action message 56 */
#define MSG_SPECIAL_ACTION_57       0xd03c    /* Special action message 57 */
#define MSG_SPECIAL_ACTION_58       0xd03d    /* Special action message 58 */
#define MSG_SPECIAL_ACTION_59       0xd03e    /* Special action message 59 */
#define MSG_SPECIAL_ACTION_60       0xd03f    /* Special action message 60 */
#define MSG_SPECIAL_ACTION_61       0xd040    /* Special action message 61 */
#define MSG_SPECIAL_ACTION_62       0xd041    /* Special action message 62 */
#define MSG_SPECIAL_ACTION_63       0xd047    /* Special action message 63 */
#define MSG_SPECIAL_ACTION_64       0xd056    /* Special action message 64 */
#define MSG_SPECIAL_ACTION_65       0xd065    /* Special action message 65 */
#define MSG_SPECIAL_ACTION_66       0xd069    /* Special action message 66 */
#define MSG_SPECIAL_ACTION_67       0xd07f    /* Special action message 67 */
#define MSG_SPECIAL_ACTION_68       0xd080    /* Special action message 68 */
#define MSG_SPECIAL_ACTION_69       0xd08c    /* Special action message 69 */
#define MSG_SPECIAL_ACTION_70       0xd08d    /* Special action message 70 */
#define MSG_SPECIAL_ACTION_71       0xd08e    /* Special action message 71 */
#define MSG_SPECIAL_ACTION_72       0xd08f    /* Special action message 72 */
#define MSG_SPECIAL_ACTION_73       0xd0a2    /* Special action message 73 */
#define MSG_SPECIAL_ACTION_74       0xd0a4    /* Special action message 74 */
#define MSG_SPECIAL_ACTION_75       0xd0a5    /* Special action message 75 */
#define MSG_SPECIAL_ACTION_76       0xd0a6    /* Special action message 76 */
#define MSG_SPECIAL_ACTION_77       0xd0a7    /* Special action message 77 */
#define MSG_SPECIAL_ACTION_78       0xd0ae    /* Special action message 78 */
#define MSG_SPECIAL_ACTION_79       0xd0be    /* Special action message 79 */
#define MSG_SPECIAL_ACTION_80       0xd0e5    /* Special action message 80 */
#define MSG_SPECIAL_ACTION_81       0xd0e6    /* Special action message 81 */
#define MSG_SPECIAL_ACTION_82       0xd12c    /* Special action message 82 */
#define MEM_STATE_VAR_4             0xeff     /* State variable 4 */
#define OFFSET_DATA_DA4             0xda4     /* Data offset DA4 */
#define BIT_MASK_0xf000             0xf000    /* 0xf000 bit mask (high nibble) */
#define BIT_MASK_0xff01             0xff01    /* 0xff01 bit mask */
#define VALUE_COMPARISON_FFEE        0xffee    /* Comparison value FFEE */
#define VALUE_COMPARISON_FFF7        0xfff7    /* Comparison value FFF7 */
#define VALUE_LARGE_MASK             0x7FFFFFFFFFFF /* Large mask value */
#define PARAM_MOVE_LOCATION          0x79      /* Move location parameter */
#define MEM_POINTER_STORAGE_284     0xd2      /* Pointer storage address 284 */
#define MEM_POINTER_STORAGE_285     0xd4      /* Pointer storage address 285 */
#define MEM_POINTER_STORAGE_286     0xd8      /* Pointer storage address 286 */
#define MEM_POINTER_STORAGE_287     0xf2      /* Pointer storage address 287 */
#define INTERRUPT_ID_FC              0xfc      /* Interrupt ID FC */
#define OBJ_ID_SPECIAL_34            0x22      /* Special object ID 34 */
#define CHAR_A                       0x41      /* Character 'A' */
#define CHAR_B                       0x42      /* Character 'B' */
#define CHAR_AT                      0x40      /* Character '@' */
#define CHAR_Y                       0x59      /* Character 'Y' */
#define CHAR_QUESTION                0x3f      /* Character '?' */
#define VALUE_96                      0x60      /* Value 96 (0x60) */
#define VALUE_137                    0x89      /* Value 137 (0x89) */
#define VALUE_169                    0xa9      /* Value 169 (0xa9) */
#define VALUE_205                    0xcd      /* Value 205 (0xcd) */
#define VALUE_224                    0xe0      /* Value 224 (0xe0) */
#define VALUE_227                    0xe3      /* Value 227 (0xe3) */
#define VALUE_250                    0xfa      /* Value 250 (0xfa) */
#define VALUE_111                    0x6f      /* Value 111 (0x6f) */
#define VALUE_110                    0x6e      /* Value 110 (0x6e) */
#define VALUE_112                    0x70      /* Value 112 (0x70) */
#define VALUE_115                    0x73      /* Value 115 (0x73) */
#define VALUE_102                    0x66      /* Value 102 (0x66) */
#define VALUE_117                    0x75      /* Value 117 (0x75) */
#define VALUE_131                    0x83      /* Value 131 (0x83) */
#define VALUE_157                    0x9d      /* Value 157 (0x9d) */
#define VALUE_43                     0x2b      /* Value 43 (0x2b) */
#define VALUE_128                    0x80      /* Value 128 (0x80) */
#define VALUE_18                     0x12      /* Value 18 (0x12) */
#define VALUE_24                     0x18      /* Value 24 (0x18) */
#define VALUE_27                     0x1b      /* Value 27 (0x1b) */
#define VALUE_23                     0x17      /* Value 23 (0x17) */
#define VALUE_29                     0x1d      /* Value 29 (0x1d) */
#define VALUE_21                     0x15      /* Value 21 (0x15) */
#define VALUE_7                      7         /* Value 7 */
#define VALUE_8                      8         /* Value 8 */
#define VALUE_9                      9         /* Value 9 */
#define VALUE_10                     10        /* Value 10 (0xa) */
#define BIT_MASK_0xdf                0xdf      /* 0xdf bit mask */
#define VALUE_180                    0xb4      /* Value 180 (0xb4) */

/* ============================================================
 * ARITHMETIC AND OFFSET CONSTANTS
 * ============================================================ */

/* Size constants */
#define SIZE_BYTE                  1         /* One byte */
#define SIZE_WORD                   2         /* One word (16 bits) */
#define SIZE_DWORD                 4         /* One dword (32 bits) */
#define SIZE_OBJECT_ENTRY          0xc        /* Object entry size */
#define SIZE_LOCATION_ENTRY        0x12      /* Location entry size */
#define SIZE_COMMAND_ENTRY       4         /* Command entry size */
#define SIZE_STRING_ENTRY          3         /* String entry size */

/* Offset constants */
#define OFFSET_OBJECT_FLAGS        2         /* Object flags offset */
#define OFFSET_OBJECT_STATE        3         /* Object state offset */
#define OFFSET_OBJECT_NAME         6         /* Object name offset */
#define OFFSET_OBJECT_PROPERTIES   10        /* Object properties offset */
#define OFFSET_OBJECT_FLAGS_2      0xb       /* Object flags offset 2 */
#define OFFSET_LOCATION_FLAGS      2         /* Location flags offset */
#define OFFSET_LOCATION_STATE      3         /* Location state offset */
#define OFFSET_LOCATION_NAME       6         /* Location name offset */
#define OFFSET_LOCATION_DESCRIPTION 10       /* Location description offset */

/* Address calculation constants */
#define ADDR_MULTIPLIER_OBJECT     0xc       /* Object address multiplier */
#define ADDR_MULTIPLIER_LOCATION   0x12      /* Location address multiplier */
#define ADDR_MULTIPLIER_COMMAND    4         /* Command address multiplier */
#define ADDR_MULTIPLIER_STRING     3         /* String address multiplier */
#define ADDR_MULTIPLIER_ACTION     6         /* Action address multiplier */

/* Stack and return values */
#define STACK_VALUE_DEFAULT        0x1000     /* Default stack value */
#define RETURN_VALUE_SUCCESS       0x1570     /* Success return value */
#define RETURN_VALUE_ERROR         0xffff     /* Error return value */
#define RETURN_VALUE_CONTINUE      2         /* Continue processing */
#define RETURN_VALUE_STOP          0         /* Stop processing */
#define RETURN_VALUE_DONE          1         /* Processing done */
#define RETURN_VALUE_INVALID       -1        /* Invalid return value */
#define RETURN_VALUE_NEGATIVE      -0x2ffd    /* Negative return value */

/* Object/Location property offsets */
#define OFFSET_PARAM_1             0x1        /* Parameter 1 offset */
#define OFFSET_PARAM_2             0x2        /* Parameter 2 offset */
#define OFFSET_PARAM_3             0x3        /* Parameter 3 offset */
#define OFFSET_PARAM_4             0x4        /* Parameter 4 offset */
#define OFFSET_PARAM_5             0x5        /* Parameter 5 offset */
#define OFFSET_PARAM_6             0x6        /* Parameter 6 offset */
#define OFFSET_PARAM_7             0x7        /* Parameter 7 offset */
#define OFFSET_PARAM_13            0x13      /* Parameter 13 offset */
#define OFFSET_PARAM_19            0x19      /* Parameter 19 offset */
#define OFFSET_PARAM_20            0x20      /* Parameter 20 offset */
#define OFFSET_PARAM_26            0x26      /* Parameter 26 offset */
#define CHAR_CARRIAGE_RETURN       0xd       /* Carriage return character */
#define CHAR_BACKSPACE             0x8       /* Backspace character (0x08) */
#define CHAR_LINEFEED              0xa       /* Line feed character (0x0A) */
#define CHAR_NEWLINE               0xa       /* Newline character (same as line feed) */
#define OFFSET_PARAM_1A            0x1a      /* Parameter 1A offset */
#define OFFSET_PARAM_1B            0x1b      /* Parameter 1B offset */
#define OFFSET_PARAM_1C            0x1c      /* Parameter 1C offset */
#define OFFSET_PARAM_E             0xe       /* Parameter E offset */
#define OFFSET_PARAM_10            0x10      /* Parameter 10 offset */
#define OFFSET_PARAM_D             0xd       /* Parameter D offset (13 decimal) */
#define OFFSET_ACTION_FLAGS        0x100     /* Action flags offset */
#define OFFSET_ACTION_PARAMS       0x101     /* Action parameters offset */
#define OFFSET_ACTION_PTR          0xfe      /* Action pointer offset */

/* Special values */
#define VALUE_INVALID              -1         /* Invalid value */
#define VALUE_FALSE                0          /* False value */
#define VALUE_TRUE                 1          /* True value */
#define VALUE_MAX_MOVE_COUNTER     2         /* Maximum move counter value */
#define VALUE_OBJECT_STATE_5       5          /* Object state 5 */
#define VALUE_OBJECT_STATE_6       6          /* Object state 6 */
#define VALUE_OBJECT_STATE_7       7          /* Object state 7 */
#define VALUE_OBJECT_STATE_8       8          /* Object state 8 */
#define VALUE_OBJECT_FLAG_4       4          /* Object flag 4 */
#define VALUE_LOCATION_OFFSET     0x12       /* Location data offset */
#define VALUE_ACTION_TABLE_ENTRY  6          /* Action table entry size */

/* Number base constants */
#define BASE_BINARY                2         /* Binary base (2) */
#define BASE_OCTAL                 8         /* Octal base (8) */
#define BASE_DECIMAL               10        /* Decimal base (10) */
#define BASE_HEXADECIMAL           16        /* Hexadecimal base (16) */

/* Buffer and size limits */
#define BUFFER_SIZE_STRING         24000     /* String buffer size (24000 bytes) */
#define MAX_OBJECT_ID              200       /* Maximum object/location ID (200) */
#define MAX_DIRECTION_ID           200       /* Maximum direction ID (200) */

#endif /* GAME_CONSTANTS_H */

