# Introduction

The MCU bootloader device works in the slave mode. All data communication is initiated by a host, which is either a PC or an embedded host. The MCU bootloader device is the target that receives a command or a data packet. All data communication between the host and the target is packetized.

**Note:** The term "target" refers to the "MCU bootloader device".

There are six types of packets used:

-   Ping packet
-   Ping Response packet
-   Framing packet
-   Command packet
-   Data packet
-   Response packet

All fields in the packets are in the little-endian byte order.

**Parent topic:**[Bootloader packet types](../topics/bootloader_packet_types.md)

