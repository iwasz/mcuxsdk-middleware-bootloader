# ReliableUpdate command

The ReliableUpdate command performs the reliable update operation.

-   **For a software implementation:** the backup application address is the parameter that is required for the ReliableUpdate command. If the *backup address* is set to 0, then the bootloader uses the *predefined address*.
-   **For a hardware implementation:** the swap indicator address is the parameter that is required for the ReliableUpdate command.
    -   If the flash swap system is **uninitialized**, then the swap indicator address can be arbitrarily specified.
    -   If the flash swap system is **initialized**, then the swap indicator must be aligned with the swap system.

**Parameters for ReliableUpdate command**
|Byte number|Command|
|-----------|-------|
|0 - 3|-   **For a software implementation:** the value is the backup application address.<br>-   **For a hardware implementation:** the value is the swap indicator address.|

**Response:**The target returns a GenericResponse packet with a status code either set to kStatus\_Success upon a successful execution of the command, or set to an appropriate error status code.

**Parent topic:**[MCU bootloader command API](../topics/mcu_bootloader_command_api.md)

