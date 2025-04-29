# Ping Response packet

The target sends the Ping Response packet back to the host after receiving the Ping packet. If the communication is over a UART peripheral, the target uses the incoming Ping packet to determine the baud rate before replying with the Ping Response packet. When the Ping Response packet is received by the host, the connection is established and the host starts sending commands to the target.

**Ping Response packet format**
|Byte \#|Value|Parameter|
|:-----:|:---:|---------|
|0|0x5A|start byte|
|1|0xA7|Ping response code|
|2| |Protocol bugfix|
|3| |Protocol minor|
|4| |Protocol major|
|5| |Protocol name = 'P' \(0x50\)|
|6| |Options low|
|7| |Options high|
|8| |CRC16 low|
|9| |CRC16 high|

The Ping Response packet can be sent from the host to the target anytime the target expects a command packet. For the UART peripheral to run the autobaud, it must be sent by the host when a connection is first established. It is optional for the other serial peripherals, but it is recommended to determine the serial protocol version. The version number is in the same format as the bootloader version number returned by the GetProperty command.

**Parent topic:**[Bootloader packet types](../topics/bootloader_packet_types.md)

