# Framing packet

The framing packet is used for the flow control and error detection for the communications links that do not have such features built in. The framing packet structure sits between the link layer and the command layer. It wraps the command and data packets as well.

Every framing packet containing data sent in one direction results in a synchronizing response framing packet in the opposite direction.

The framing packet described in this section is used for serial peripherals including the UART, I2C, and SPI. The USB HID peripheral does not use the framing packets. Instead, the packetization inherent in the USB protocol itself is used.

**Framing Packet Format**
|Byte \#|Value|Parameter| |
|:-----:|:---:|---------|--|
|0|0x5A|start byte| |
|1| |packetType| |
|2| |length\_low|Length is a 16-bit field that specifies the entire command or data packet size in bytes.|
|3| |length\_high|
|4| |crc16\_low|This is a 16-bit field. The CRC16 value covers the entire framing packet, including the start byte and command or data packets, but does not include the CRC bytes. See the CRC16 algorithm after this table.|
|5| |crc16\_high|
|6 . . .n| |Command or Data packet payload| |

A special framing packet that contains only a start byte and a packet type is used for synchronization between the host and the target.

**Special Framing Packet Format**
|Byte \#|Value|Parameter|
|:-----:|:---:|---------|
|0|0x5A|start byte|
|1|0xA*n*|packetType|

The Packet Type field specifies the type of the packet from one of these defined types:

**packetType Field**
|packetType|Name|Description|
|:--------:|:---|-----------|
|0xA1|kFramingPacketType\_Ack|The previous packet was received successfully; the sending of more packets is allowed.|
|0xA2|kFramingPacketType\_Nak|The previous packet was corrupt and must be re-sent.|
|0xA3|kFramingPacketType\_AckAbort|The data phase is being aborted.|
|0xA4|kFramingPacketType\_Command|The framing packet contains a command packet payload.|
|0xA5|kFramingPacketType\_Data|The framing packet contains a data packet payload.|
|0xA6|kFramingPacketType\_Ping|Sent to verify that the other side is alive. Also used for the UART autobaud.

|
|0xA7|kFramingPacketType\_PingResponse|A response to Ping; contains the framing protocol version number and options.|

**Parent topic:**[Bootloader packet types](../topics/bootloader_packet_types.md)

