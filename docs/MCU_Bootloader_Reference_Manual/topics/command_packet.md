# Command packet

The command packet carries a 32-bit command header and a list of 32-bit parameters.

**Command packet format**
| Command packet format (32 bytes)|||||||||||
| --------------------------------|-|-|-|-|-|-|-|-|-|-------------------|
| Command header (4 bytes)||| | 28 bytes for Parameters (Max 7 parameters) |
| Tag | Flags | Rsvd | Param Count | Param1 (32-bit) | Param2 (32-bit) | Param3 (32-bit) | Param4 (32-bit) | Param5 (32-bit) | Param6 (32-bit) | Param7 (32-bit) |
| byte 0 | byte 1 | byte 2 | byte 3 | - | - | - | - | - | - | - |

**Command Header format**
|Byte \#|Command header field| |
|:-----:|:-------------------|--|
|0|Command or Response tag|The command header is 4 bytes long, with these fields.|
|1|Flags|
|2|Reserved. Should be 0x00.|
|3|ParameterCount|

The header is followed by 32-bit parameters up to the value of the ParameterCount field specified in the header. Because a command packet is 32 bytes long, only seven parameters fit into the command packet.

The command packets are also used by the target to send responses back to the host. The command packets and data packets are embedded into the framing packets for all of the transfers.

**Command Tags**
|Command Tags|Name| |
|:----------:|:---|:-|
|0x01|FlashEraseAll|The command tag specifies one of the commands supported by the MCU bootloader. The valid command tags for the MCU bootloader are listed here.|
|0x02|FlashEraseRegion|
|0x03|ReadMemory|
|0x04|WriteMemory|
|0x05|FillMemory|
|0x06|FlashSecurityDisable|
|0x07|GetProperty|
|0x08|Reserved|
|0x09|Execute|
|0x10|FlashReadResource|
|0x11|Reserved|
|0x0A|Call|
|0x0B|Reset|
|0x0C|SetProperty|
|0x0D|FlashEraseAllUnsecure|
|0x0E|FlashProgramOnce|
|0x0F|FlashReadOnce|
|0x10|FlashReadResource|
|0x11|ConfigureMemory|
|0x12|ReliableUpdate|

**Response Tags**
|Response Tag|Name| |
|:----------:|:---|:-|
|0xA0|GenericResponse|The response tag specifies one of the responses the MCU bootloader \(target\) returns to the host. The valid response tags are listed here.|
|0xA7|GetPropertyResponse \(used for sending responses to GetProperty command only\)|
|0xA3|ReadMemoryResponse \(used for sending responses to ReadMemory command only\)|
|0xAF|FlashReadOnceResponse \(used for sending responses to FlashReadOnce command only\)|
|0xB0|FlashReadResourceResponse \(used for sending responses to FlashReadResource command only\)|

**Flags:** Each command packet contains a flag byte. Only bit 0 of the flag byte is used. If bit 0 of the flag byte is set to 1, then the data packets follow in the command sequence. The number of bytes that are transferred in the data phase is determined by a command-specific parameter in the parameters array.

**ParameterCount:** The number of parameters included in the command packet.

**Parameters:** The parameters are word-length \(32 bits\). With the default maximum packet size of 32 bytes, a command packet can contain up to seven parameters.

**Parent topic:**[Bootloader packet types](../topics/bootloader_packet_types.md)

