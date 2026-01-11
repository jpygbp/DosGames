/* Function aliases and stubs */
/* All "missing" functions are actually already implemented in skull_ported.c with real names */

#include "dos_compat.h"

/* Forward declarations for functions defined in skull_ported.c */
extern uint get_char(void);
extern uint check_keyboard_status(void);
extern uint string_compare(char *param_1, char *param_2, uint param_3);
extern uint get_random_number(void);
extern uint file_open_read(undefined2 param_1, uint param_2, uint param_3);
extern uint file_seek(uint param_1, uint param_2, uint param_3, uint param_4);
extern int file_read(uint param_1, char *param_2, int param_3);
extern int read_file_buffer(uint param_1, byte *param_2, int param_3);
extern int string_length(char *param_1);

/* Function aliases - map old FUN_* names to real implementations */
/* These allow code that might still reference FUN_* names to work */

uint FUN_1000_55a6(void) {
    return get_char();
}

uint FUN_1000_5592(void) {
    return check_keyboard_status();
}

uint FUN_1000_550e(char *param_1, char *param_2, uint param_3) {
    return string_compare(param_1, param_2, param_3);
}

uint FUN_1000_56ae(void) {
    return get_random_number();
}

uint FUN_1000_4e86(undefined2 param_1, uint param_2, uint param_3) {
    return file_open_read(param_1, param_2, param_3);
}

uint FUN_1000_4e0c(uint param_1, uint param_2, uint param_3, uint param_4) {
    return file_seek(param_1, param_2, param_3, param_4);
}

int FUN_1000_5108(uint param_1, char *param_2, int param_3) {
    return file_read(param_1, param_2, param_3);
}

int FUN_1000_502a(uint param_1, byte *param_2, int param_3) {
    return read_file_buffer(param_1, param_2, param_3);
}

int FUN_1000_54f2(char *param_1) {
    return string_length(param_1);
}

/* 
 * All functions are now properly aliased to their real implementations.
 * 
 * Function name mappings:
 *   FUN_1000_55a6 -> get_char
 *   FUN_1000_5592 -> check_keyboard_status
 *   FUN_1000_550e -> string_compare
 *   FUN_1000_56ae -> get_random_number
 *   FUN_1000_4e86 -> file_open_read
 *   FUN_1000_4e0c -> file_seek
 *   FUN_1000_5108 -> file_read
 *   FUN_1000_502a -> read_file_buffer
 *   FUN_1000_54f2 -> string_length
 */
