# ReceiveSBFile command

The ReceiveSBFile command starts the transfer of an SB file to the target. The command only specifies the size of the SB file that is sent in the data phase \(in bytes\). The SB file is processed as it is received by the bootloader.

**Parameters for ReceiveSBFile Command**
|Byte \#|Command|
|:-----:|-------|
|0 - 3|Byte count|

**Data Phase:** The ReceiveSBFile command has a data phase. The host sends data packets until the number of bytes of data specified in the byteCount parameter of the ReceiveSBFile command are received by the target.

**Response:** The target returns a GenericResponse packet with a status code set to kStatus\_Success upon a successful execution of the command or set to an appropriate error code.

**Parent topic:**[MCU bootloader command API](../topics/mcu_bootloader_command_api.md)

