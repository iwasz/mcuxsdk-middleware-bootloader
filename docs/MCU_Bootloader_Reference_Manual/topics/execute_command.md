# Execute command

The execute command results in the bootloader setting the program counter to the code at the provided jump address, R0 to the provided argument, and a Stack pointer to the provided stack pointer address. Before the jump, the system is returned to the reset state.

The Jump address, function argument pointer, and stack pointer are the parameters required for the Execute command. If the stack pointer is set to zero, the called code is responsible for setting the processor stack pointer before using the stack.

If the QSPI is enabled, it is initialized before the jump. The QSPI encryption \(OTFAD\) is also enabled \(if configured\).

**Parameters for Execute Command**
|Byte \#|Command|
|:-----:|-------|
|0 - 3|Jump address|
|4 - 7|Argument word|
|8 - 11|Stack pointer address|

The Execute command has no data phase.

**Response:** Before executing the Execute command, the target validates the parameters and returns a GenericResponse packet with a status code either set to kStatus\_Success or an appropriate error status code.

**Parent topic:**[MCU bootloader command API](../topics/mcu_bootloader_command_api.md)

