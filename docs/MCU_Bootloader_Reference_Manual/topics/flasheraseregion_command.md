# FlashEraseRegion command

The FlashEraseRegion command performs an erase of one or more sectors of the flash memory.

The start address and number of bytes are the two parameters required for the FlashEraseRegion command. The start and byte count parameters must be 4-byte aligned \(\[1:0\] = 00\), or the FlashEraseRegion command fails and returns kStatus\_FlashAlignmentError\(101\). If the region specified does not fit into the flash memory space, the FlashEraseRegion command fails and returns kStatus\_FlashAddressError\(102\). If any part of the region specified is protected, the FlashEraseRegion command fails and returns kStatus\_MemoryRangeInvalid\(10200\).

**Parameters for FlashEraseRegion Command**
|Byte \#|Parameter|
|:-----:|---------|
|0 - 3|Start address|
|4 - 7|Byte count|
|8 - 11|Memory ID|

The FlashEraseRegion command has no data phase.

**Response:** The target returns a GenericResponse packet with one of the following error status codes.

**FlashEraseRegion Response Status Codes**
|Status Code|
|:----------|
|kStatus\_Success \(0\)|
|kStatus\_MemoryRangeInvalid \(10200\)|
|kStatus\_FlashAlignmentError \(101\)|
|kStatus\_FlashAddressError \(102\)|
|kStatus\_FlashAccessError \(103\)|
|kStatus\_FlashProtectionViolation \(104\)|
|kStatus\_FlashCommandFailure \(105\)|

**Parent topic:**[MCU bootloader command API](../topics/mcu_bootloader_command_api.md)

