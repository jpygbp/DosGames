# Variable Renaming Status Report

**Generated**: Current Session  
**Purpose**: Comprehensive analysis of all remaining variables that need renaming

---

## Summary Statistics

- **Total `param_X` instances**: 736
- **Functions with `param_X` parameters**: ~50+ functions
- **Already renamed**: 18 functions (display_message, take_object, drop_object, etc.)

---

## Remaining Functions with `param_X` Parameters

### File I/O Functions (High Priority)

1. **`format_text_line(int param_1, int param_2)`**
   - Suggested: `format_text_line(int text_ptr, int max_length)`
   - Location: Forward declaration line 98, definition ~3617

2. **`load_string_from_file(int param_1, int param_2)`**
   - Suggested: `load_string_from_file(int string_id, int buffer_ptr)`
   - Location: Forward declaration line 99, definition ~3765

3. **`load_string_from_secondary_file(int param_1, int param_2)`**
   - Suggested: `load_string_from_secondary_file(int string_id, int buffer_ptr)`
   - Location: Forward declaration line 100, definition ~3800

4. **`read_file_exact(undefined2 param_1, undefined2 param_2, int param_3)`**
   - Suggested: `read_file_exact(undefined2 file_handle, undefined2 buffer, int count)`
   - Location: Forward declaration line 101, definition ~3835

5. **`file_read_word(undefined2 param_1, undefined2 param_2, undefined2 param_3)`**
   - Suggested: `file_read_word(undefined2 file_handle, undefined2 buffer, undefined2 count)`
   - Location: Forward declaration line 102, definition ~3857

6. **`file_open(undefined2 param_1)`**
   - Suggested: `file_open(undefined2 filename_ptr)`
   - Location: Forward declaration line 103, definition ~3874

7. **`file_open_read(undefined2 param_1, uint param_2, uint param_3)`**
   - Suggested: `file_open_read(undefined2 filename_ptr, uint mode, uint access)`
   - Location: Forward declaration line 104, definition ~7146

8. **`file_seek(uint param_1, uint param_2, uint param_3, uint param_4)`**
   - Suggested: `file_seek(uint file_handle, uint offset, uint origin, uint reserved)`
   - Location: Forward declaration line 105, definition ~7002

9. **`file_read(uint param_1, char *param_2, int param_3)`**
   - Suggested: `file_read(uint file_handle, char *buffer, int count)`
   - Location: Forward declaration line 106, definition ~7467

10. **`read_file_buffer(uint param_1, byte *param_2, int param_3)`**
    - Suggested: `read_file_buffer(uint file_handle, byte *buffer, int count)`
    - Location: Forward declaration line 107, definition ~7287

### System/Error Functions

11. **`report_error(undefined2 param_1)`**
    - Suggested: `report_error(undefined2 error_code)`
    - Location: Forward declaration line 149

12. **`setup_file_buffer(undefined2 *param_1)`**
    - Suggested: `setup_file_buffer(undefined2 *buffer_ptr)`
    - Location: Forward declaration line 150

13. **`initialize_file_handle(undefined2 *param_1)`**
    - Suggested: `initialize_file_handle(undefined2 *handle_ptr)`
    - Location: Forward declaration line 151

14. **`handle_file_buffer_flush(int param_1, undefined2 *param_2)`**
    - Suggested: `handle_file_buffer_flush(int file_handle, undefined2 *buffer_ptr)`
    - Location: Forward declaration line 152

15. **`flush_file_buffer(int *param_1)`**
    - Suggested: `flush_file_buffer(int *file_handle_ptr)`
    - Location: Forward declaration line 153

### Format Functions

16. **`format_string_printf(undefined2 param_1, char *param_2, undefined2 param_3)`**
    - Suggested: `format_string_printf(undefined2 format_id, char *buffer, undefined2 value)`
    - Location: Forward declaration line 154

17. **`format_number_output(int param_1)`**
    - Suggested: `format_number_output(int value)`
    - Location: Forward declaration line 155

18. **`format_string_output(int param_1)`**
    - Suggested: `format_string_output(int length)`
    - Location: Forward declaration line 156

19. **`format_float_output(int param_1)`**
    - Suggested: `format_float_output(int precision)`
    - Location: Forward declaration line 157

20. **`output_format_char(uint param_1)`**
    - Suggested: `output_format_char(uint character)`
    - Location: Forward declaration line 158

21. **`output_format_padding(int param_1)`**
    - Suggested: `output_format_padding(int width)`
    - Location: Forward declaration line 159

22. **`output_format_string(byte *param_1, int param_2)`**
    - Suggested: `output_format_string(byte *str, int length)`
    - Location: Forward declaration line 160

23. **`format_output_with_padding(int param_1)`**
    - Suggested: `format_output_with_padding(int width)`
    - Location: Forward declaration line 161

24. **`is_format_char(char param_1)`**
    - Suggested: `is_format_char(char character)`
    - Location: Forward declaration line 164

### Memory Functions

25. **`resize_memory_block(int param_1, int param_2, int param_3)`**
    - Suggested: `resize_memory_block(int block_ptr, int old_size, int new_size)`
    - Location: Forward declaration line 170

26. **`is_file_at_end(int param_1)`**
    - Suggested: `is_file_at_end(int file_handle)`
    - Location: Forward declaration line 172

27. **`convert_number_to_string(uint param_1, byte *param_2, uint param_3)`**
    - Suggested: `convert_number_to_string(uint number, byte *buffer, uint base)`
    - Location: Forward declaration line 173

28. **`convert_long_to_string(uint param_1, uint param_2, byte *param_3, uint param_4)`**
    - Suggested: `convert_long_to_string(uint high_word, uint low_word, byte *buffer, uint base)`
    - Location: Forward declaration line 174

### Display/Video Functions

29. **`display_error(char param_1)`**
    - Suggested: `display_error(char error_code)`
    - Location: Forward declaration line 89

30. **`set_video_mode(uint param_1)`**
    - Suggested: `set_video_mode(uint mode)`
    - Location: Forward declaration line 175

31. **`handle_display_mode(uint param_1)`**
    - Suggested: `handle_display_mode(uint mode)`
    - Location: Forward declaration line 181

32. **`display_string(char *param_1)`**
    - Suggested: `display_string(char *str)`
    - Location: Forward declaration line 182

33. **`set_cursor_position(uint param_1, uint param_2)`**
    - Suggested: `set_cursor_position(uint x, uint y)` ✅ Already renamed
    - Location: Forward declaration line 183

34. **`set_display_wrap_mode(undefined2 param_1)`**
    - Suggested: `set_display_wrap_mode(undefined2 wrap_flag)`
    - Location: Forward declaration line 187

35. **`draw_display_line(uint param_1)`**
    - Suggested: `draw_display_line(uint length)`
    - Location: Forward declaration line 200

36. **`save_video_registers(undefined2 param_1, undefined2 param_2)`**
    - Suggested: `save_video_registers(undefined2 reg1, undefined2 reg2)`
    - Location: Forward declaration line 215

### Command/Game Functions

37. **`lookup_command(undefined2 param_1)`**
    - Suggested: `lookup_command(undefined2 command_id)`
    - Location: Forward declaration line 222

38. **`find_matching_objects(byte *param_1, uint param_2, int param_3)`**
    - Suggested: `find_matching_objects(byte *buffer, uint count, int flags)`
    - Location: Forward declaration line 223

39. **`find_objects_in_location(byte *param_1, uint param_2, uint param_3, int param_4)`**
    - Suggested: `find_objects_in_location(byte *buffer, uint location_id, uint flags, int max_count)`
    - Location: Forward declaration line 224

40. **`string_compare(char *param_1, char *param_2, uint param_3)`**
    - Suggested: `string_compare(char *str1, char *str2, uint length)`
    - Location: Forward declaration line 227

41. **`string_length(char *param_1)`**
    - Suggested: `string_length(char *str)` ✅ Already renamed
    - Location: Forward declaration line 228

42. **`remove_object_from_list(byte *param_1, byte param_2)`**
    - Suggested: `remove_object_from_list(byte *list_ptr, byte object_id)`
    - Location: Forward declaration line 229

43. **`load_and_display_message(undefined2 param_1)`**
    - Suggested: `load_and_display_message(undefined2 message_id)`
    - Location: Forward declaration line 230

44. **`display_object_info(uint param_1)`**
    - Suggested: `display_object_info(uint object_id)`
    - Location: Forward declaration line 231

45. **`handle_direction_move(byte param_1, uint param_2)`**
    - Suggested: `handle_direction_move(byte direction, uint location_id)`
    - Location: Forward declaration line 232

### Process Commands Function

46. **`process_commands(int param_1, undefined2 param_2)`**
    - Suggested: `process_commands(int command_buffer, undefined2 context)`
    - Location: Definition ~line 462

---

## Local Variables (Medium Priority)

### Integer Variables (iVar1-6)
- **Total instances**: ~500+
- **Common uses**: Loop counters, object IDs, location IDs, array indices, return values, file handles
- **Suggested renames**: Based on context (counter, index, object_id, location_id, result, file_handle)

### Unsigned Variables (uVar1-7)
- **Total instances**: ~400+
- **Common uses**: Flags, message IDs, bit masks, counters, offsets
- **Suggested renames**: Based on context (flags, message_id, mask, count, offset)

### Pointer Variables
- **pbVar1-9** (byte pointers): ~200+ instances
- **puVar1-9** (unsigned pointers): ~150+ instances
- **pcVar1-9** (char pointers): ~100+ instances
- **piVar1-9** (int pointers): ~50+ instances

### Local Variables (local_X)
- **local_6, local_a, local_c, etc.**: ~300+ instances
- **Suggested renames**: Based on usage context

---

## Renaming Priority

### Phase 1: High Priority (File I/O & System Functions)
- File I/O functions (10 functions)
- System/Error functions (5 functions)
- **Impact**: High - These are core infrastructure functions

### Phase 2: Medium Priority (Format & Display Functions)
- Format functions (9 functions)
- Display/Video functions (8 functions)
- **Impact**: Medium - Used frequently but less critical

### Phase 3: Lower Priority (Game Logic Functions)
- Command/Game functions (9 functions)
- Memory functions (4 functions)
- **Impact**: Lower - More context-specific, harder to rename safely

### Phase 4: Local Variables
- Rename local variables in already-renamed functions first
- Focus on complex functions with many local variables
- **Impact**: Variable - Improves readability but requires careful analysis

---

## Recommendations

1. **Start with File I/O functions** - Clear parameter meanings, high usage
2. **Rename in batches** - Group related functions together
3. **Update both declarations and definitions** - Ensure consistency
4. **Test after each batch** - Verify no regressions
5. **Document changes** - Keep track of renames for reference

---

## Next Steps

1. ✅ Analyze all remaining `param_X` parameters
2. ⏳ Rename File I/O function parameters (10 functions)
3. ⏳ Rename System/Error function parameters (5 functions)
4. ⏳ Rename Format function parameters (9 functions)
5. ⏳ Rename Display/Video function parameters (8 functions)
6. ⏳ Rename remaining Game Logic function parameters (13 functions)
7. ⏳ Rename local variables in key functions

