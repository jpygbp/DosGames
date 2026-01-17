# Remaining Constants Report

## Summary
**Total Remaining Constants: 49 unique constants**

## Categories

### 1. Message IDs (0xd0xx range) - 38 constants
These appear to be message/string IDs used in `display_message()` and `display_formatted_message()` calls:

#### Already Defined (but not used):
- `0xd136` → `MSG_SPECIAL_LOCATION` (defined but not used in code)
- `0xd055` → `MSG_OBJECT_INFO` (defined but not used in code)
- `0xd057` → `MSG_LOCATION_DESC` (defined but not used in code)

#### Need Definition:
- `0xd030` - Used in `display_formatted_message(0xd030,param_1)`
- `0xd031` - Used in `display_message(0xd031)`
- `0xd032` - Used in `display_message(0xd032)`
- `0xd033` - Used in `uVar3 = 0xd033`
- `0xd034` - Used in `uVar3 = 0xd034`
- `0xd035` - Used in `uVar3 = 0xd035`
- `0xd036` - Used in `uVar3 = 0xd036`
- `0xd037` - Used in `uVar3 = 0xd037`
- `0xd038` - Used in `uVar3 = 0xd038`
- `0xd039` - Used in `uVar3 = 0xd039`
- `0xd03a` - Used in `display_message(0xd03a)`
- `0xd03c` - Used in `display_formatted_message(0xd03c,uVar3)`
- `0xd03d` - Used in `display_message(0xd03d)`
- `0xd03e` - Used in `uVar6 = 0xd03e`
- `0xd03f` - Used in `display_formatted_message(0xd03f,param_2)`
- `0xd040` - Used in `uVar6 = 0xd040`
- `0xd041` - Used in `uVar6 = 0xd041`
- `0xd047` - Used in `display_formatted_message_wrapper_3(0xd047, iVar1, bVar2)`
- `0xd056` - Used in `uVar5 = 0xd056`
- `0xd065` - Used in `uVar5 = 0xd065`
- `0xd069` - Used in `uVar6 = 0xd069`
- `0xd07f` - Used in `uVar4 = 0xd07f`
- `0xd080` - Used in `display_message_and_move(0xd080,0)`
- `0xd08c` - Used in `display_formatted_message(0xd08c,param_2)`
- `0xd08d` - Used in `display_message(0xd08d)`
- `0xd08e` - Used in `display_formatted_message(0xd08e,MEM_POINTER_STORAGE_110)`
- `0xd08f` - Used in `uVar6 = 0xd08f`
- `0xd0a2` - Used in `uVar6 = 0xd0a2`
- `0xd0a4` - Used in `uVar4 = 0xd0a4`
- `0xd0a5` - Used in `uVar4 = 0xd0a5`
- `0xd0a6` - Used in `display_message(0xd0a6)`
- `0xd0a7` - Used in `display_message_wrapper_2(0xd0a7, param_1 + 2)`
- `0xd0ae` - Used in `display_formatted_message(0xd0ae,iVar3)`
- `0xd0be` - Used in `display_message(0xd0be)`
- `0xd0e5` - Used in `in_stack_0000fffa = 0xd0e5`
- `0xd0e6` - Used in `in_stack_0000fffa = 0xd0e6`

### 2. Other Message IDs - 2 constants
- `0xd12c` - Used in `move_to_location(MEM_READ32(MEM_LOCATION_DATA),0x79,0xd12c,1,unaff_SI)`

### 3. Memory Addresses - 3 constants
#### Already Defined (but not used):
- `0xef1` → `MEM_STATE_VAR_1` (defined but not used in code)
- `0xef3` → `MEM_STATE_VAR_2` (defined but not used in code)

#### Need Definition:
- `0xeff` - Used in `MEM_READ32(0xeff)` (similar to MEM_STATE_VAR_1-3, might be MEM_STATE_VAR_4)

### 4. Offsets and Addresses - 1 constant
- `0xda4` - Used in `MEM_READ32(MEM_DATA_BASE) + 0xda4` (appears to be an offset)

### 5. Bit Masks and Special Values - 4 constants
- `0xf000` - Used in `(param_1 & 0xf000) == MEM_POINTER_STORAGE_272` (bit mask for high nibble)
- `0xff01` - Used in `((uint)puVar5 & 0xff01) == BIT_MASK_0xfffe` (bit mask)
- `0xffee` - Used in `uVar7 < 0xffee` (comparison value)
- `0xfff7` - Used in `(uint8_t*)0xfff7 < auStack6` (comparison value)

### 6. Large Constants - 1 constant
- `0x7FFFFFFFFFFF` - Used in comparison (appears to be a large mask or limit)

### 7. Numeric Constants - 1 constant
- `0x79` - Used in `move_to_location(MEM_READ32(MEM_LOCATION_DATA),0x79,0xd12c,1,unaff_SI)` (appears to be a parameter value)

## Recommendations

### High Priority (Already Defined - Just Need to Use):
1. Replace `0xd136` with `MSG_SPECIAL_LOCATION`
2. Replace `0xd055` with `MSG_OBJECT_INFO`
3. Replace `0xd057` with `MSG_LOCATION_DESC`
4. Replace `0xef1` with `MEM_STATE_VAR_1`
5. Replace `0xef3` with `MEM_STATE_VAR_2`

### Medium Priority (Message IDs - Should Define):
All the `0xd0xx` message IDs should be defined as `MSG_*` constants for consistency.

### Low Priority (Context-Specific):
- `0x79` - May be a location ID or parameter (could be `LOCATION_ID_*` or `PARAM_*`)
- `0xda4` - Offset value (could be `OFFSET_DATA_DA4` or similar)
- `0xf000`, `0xff01`, `0xffee`, `0xfff7` - Bit masks or comparison values
- `0x7FFFFFFFFFFF` - Large constant, likely a mask or limit
- `0xeff` - Could be `MEM_STATE_VAR_4` if it follows the pattern

## Status
- **Total constants remaining**: 49
- **Already defined but not used**: 5
- **Need definition**: 44
