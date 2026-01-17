# Variable Renaming Opportunities

## Summary

**Total Generic Variables Found:**
- **98 unique generic variable names**
- **7,596 total instances**
- **103 functions** use `param_X` naming convention

## Categories

### 1. Function Parameters (High Priority)

**Total: ~1,050+ instances across 103 functions**

#### Display Functions
- `display_message(uint param_1)` → `display_message(uint message_id)`
- `display_formatted_message(undefined2 param_1, uint param_2)` → `display_formatted_message(undefined2 format_id, uint value)`
- `display_item_list(uint param_1)` → `display_item_list(uint location_id)`
- `display_status_screen(int param_1)` → `display_status_screen(int screen_id)`
- `print_string(int param_1, char *param_2)` → `print_string(int length, char *str)`
- `clear_display_line(int param_1)` → `clear_display_line(int line_number)`
- `setup_display_window(int param_1, int param_2)` → `setup_display_window(int x, int y)`

#### Object Functions
- `take_object(uint param_1, int param_2)` → `take_object(uint object_id, int location_id)`
- `drop_object(int param_1, int param_2)` → `drop_object(int object_id, int location_id)`
- `is_object_in_inventory(uint param_1)` → `is_object_in_inventory(uint object_id)`
- `add_object_to_list(byte *param_1, byte param_2)` → `add_object_to_list(byte *list_ptr, byte object_id)`
- `move_object_between_locations(uint param_1, int param_2, int param_3)` → `move_object_between_locations(uint object_id, int from_location, int to_location)`
- `handle_object_command(int param_1, undefined2 param_2)` → `handle_object_command(int object_id, undefined2 command_id)`
- `handle_object_interaction(int param_1, int param_2, undefined2 param_3)` → `handle_object_interaction(int object_id, int action_id, undefined2 result)`

#### Location Functions
- `move_to_location(byte param_1, byte param_2, uint param_3, char param_4, undefined2 param_5)` → `move_to_location(byte location_id, byte direction, uint message_id, char flag, undefined2 context)`
- `handle_location_change(undefined2 param_1)` → `handle_location_change(undefined2 new_location_id)`
- `display_location_description(int param_1)` → `display_location_description(int location_id)`

#### Command Functions
- `handle_special_command(undefined2 param_1)` → `handle_special_command(undefined2 command_id)`
- `handle_put_command(int param_1, undefined2 param_2)` → `handle_put_command(int object_id, undefined2 target_id)`
- `take_all_objects(int param_1, undefined2 param_2)` → `take_all_objects(int location_id, undefined2 result)`
- `drop_all_objects(int param_1, undefined2 param_2)` → `drop_all_objects(int location_id, undefined2 result)`

#### File/System Functions
- `call_interrupt_by_id(undefined2 param_1)` → `call_interrupt_by_id(undefined2 interrupt_id)`
- `handle_dos_interrupt(undefined2 param_1)` → `handle_dos_interrupt(undefined2 interrupt_id)`
- `setup_file_buffer(undefined2 *param_1)` → `setup_file_buffer(undefined2 *buffer_ptr)`
- `handle_file_buffer_flush(int param_1, undefined2 *param_2)` → `handle_file_buffer_flush(int file_handle, undefined2 *buffer_ptr)`

#### Format Functions
- `format_number_output(int param_1)` → `format_number_output(int value)`
- `format_string_output(int param_1)` → `format_string_output(int length)`
- `format_float_output(int param_1)` → `format_float_output(int precision)`
- `output_format_char(uint param_1)` → `output_format_char(uint character)`
- `output_format_padding(int param_1)` → `output_format_padding(int width)`
- `output_format_string(byte *param_1, int param_2)` → `output_format_string(byte *str, int length)`

### 2. Local Variables (Medium Priority)

**Total: ~3,000+ instances**

#### Integer Variables (iVar1-6)
- `iVar1`, `iVar2`, `iVar3`, `iVar4`, `iVar5`, `iVar6` - Used for:
  - Loop counters → `counter`, `index`, `i`
  - Object IDs → `object_id`, `obj_id`
  - Location IDs → `location_id`, `loc_id`
  - Array indices → `array_index`, `idx`
  - Return values → `result`, `ret_val`
  - File handles → `file_handle`, `fh`

#### Unsigned Variables (uVar1-7)
- `uVar1`, `uVar2`, `uVar3`, `uVar4`, `uVar5`, `uVar6`, `uVar7` - Used for:
  - Flags → `flags`, `flag_value`
  - Message IDs → `message_id`, `msg_id`
  - Bit masks → `mask`, `bit_mask`
  - Counters → `count`, `counter`
  - Offsets → `offset`, `addr_offset`

#### Pointer Variables
- `pbVar1-9` (byte pointers) → `byte_ptr`, `data_ptr`, `buffer_ptr`
- `puVar1-9` (unsigned pointers) → `uint_ptr`, `value_ptr`
- `pcVar1-9` (char pointers) → `char_ptr`, `str_ptr`, `string_ptr`
- `piVar1-9` (int pointers) → `int_ptr`, `index_ptr`

#### Local Variables (local_X)
- `local_6`, `local_a`, `local_c`, etc. → Based on usage:
  - Counters → `count`, `counter`
  - Flags → `flag`, `is_valid`
  - Indices → `index`, `idx`
  - Results → `result`, `ret_val`

### 3. Stack Variables (Low Priority)

**Total: ~500+ instances**

- `in_stack_0000fffa`, `in_stack_0000fff8`, etc. → Based on usage:
  - Parameters → `param_value`, `arg_value`
  - Temporary values → `temp`, `tmp`
  - Return addresses → `ret_addr`

## Renaming Strategy

### Phase 1: Function Parameters (High Impact)
1. Start with most frequently called functions
2. Rename parameters based on function purpose
3. Update all call sites

### Phase 2: Local Variables in Key Functions
1. Focus on complex functions first
2. Rename variables based on context
3. Use consistent naming patterns

### Phase 3: Remaining Variables
1. Batch rename similar variables
2. Use search-and-replace with careful review
3. Test after each batch

## Examples of Good Renames

### Before:
```c
int display_message(uint param_1)
{
  uint uVar1;
  int iVar2;
  // ...
  uVar1 = param_1;
  iVar2 = MEM_READ32(MEM_STRING_TABLE);
  // ...
}
```

### After:
```c
int display_message(uint message_id)
{
  uint current_message;
  int string_table_base;
  // ...
  current_message = message_id;
  string_table_base = MEM_READ32(MEM_STRING_TABLE);
  // ...
}
```

## Recommendations

1. **Start with display functions** - Most visible, easier to verify
2. **Focus on object/location functions** - Core game logic
3. **Use consistent naming patterns** - `object_id`, `location_id`, `message_id`, etc.
4. **Rename incrementally** - Test after each function
5. **Document changes** - Keep track of renames for reference

## Priority Functions for Renaming

### High Priority (Most Used)
1. `display_message` - 622 instances of `param_1`
2. `handle_object_interaction` - Complex logic
3. `move_to_location` - Core game function
4. `take_object` / `drop_object` - Common operations

### Medium Priority
1. Format functions
2. File I/O functions
3. Command processing functions

### Low Priority
1. Helper functions
2. Internal utility functions
3. Rarely called functions

