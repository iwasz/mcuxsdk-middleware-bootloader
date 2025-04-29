# Configure Memory command

The Configure Memory command configures the external memory device using a pre-programmed configuration image. The parameters passed in the command are the memory ID \(which should be 1 QuadSPI Nor Memory\) and the memory address from which the configuration data can be loaded from. The options for loading the data can be a scenario where the configuration data is written to a RAM or flash location and this command directs the bootloader to use the data at that location to configure the external memory devices.

**Parameters for Configure QuadSPI Command**
| Byte # | Command |
| --- | --- |
| 0 – 3 | Memory ID |
| 4 – 7 | Configuration block address |

**Response:** The target \(MCU bootloader\) returns a GenericResponse packet with a status code either set to kStatus\_Success upon a successful execution of the command, or set to an appropriate error code.

**Parent topic:**[MCU bootloader command API](../topics/mcu_bootloader_command_api.md)

