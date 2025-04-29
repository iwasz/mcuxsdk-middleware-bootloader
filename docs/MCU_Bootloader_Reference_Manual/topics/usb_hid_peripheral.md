# USB HID Peripheral

The MCU bootloader supports loading data into flash via the USB peripheral. The target is implemented as a USB HID class.

USB HID does not use framing packets; instead the packetization inherent in the USB protocol itself is used. The ability for the device to NAK Out transfers \(until they can be received\) provides the required flow control; the built-in CRC of each USB packet provides the required error detection.

## Device descriptor 

The MCU bootloader configures the default USB VID/PID/Strings as below:

Default VID/PID:

For legacy FSL devices:

-   VID = 0x15A2
-   PID = 0x0073

For NXP devices:

-   VID = 0x1FC9
-   PID = 0x007F

Default Strings:

-   For legacy FSL devices:
    -   Manufacturer \[1\] = "Freescale Semiconductor Inc."
    -   Product \[2\] = "Kinetis bootloader"
-   For NXP devices:
    -   Manufacturer \[1\] = "NXP Semiconductor Inc."
    -   Product \[2\] = "Kinetis bootloader"

The USB VID, PID, and Strings can be customized using the Bootloader Configuration Area \(BCA\) of the flash. For example, the USB VID and PID can be customized by writing the new VID to the usbVid\(BCA + 0x14\) field and the new PID to the usbPid\(BCA + 0x16\) field of the BCA in flash. To change the USB strings, prepare a structure \(like the one shown below\) in the flash, and then write the address of the structure to the usbStringsPointer\(BCA + 0x18\) field of the BCA.

## Endpoints 

The HID peripheral uses 3 endpoints:

-   Control \(0\)
-   Interrupt IN \(1\)
-   Interrupt OUT \(2\)

The Interrupt OUT endpoint is optional for HID class devices, but the MCU bootloader uses it as a pipe, where the firmware can NAK send requests from the USB host.

## HID reports 

There are 4 HID reports defined and used by the bootloader USB HID peripheral. The report ID determines the direction and type of packet sent in the report; otherwise, the contents of all reports are the same.

|Report ID|Packet Type|Direction|
|:-------:|:---------:|:-------:|
|1|Command|OUT|
|2|Data|OUT|
|3|Command|IN|
|4|Data|IN|

For all reports, these properties apply:

|Protpety|Value|
|--|--|
| Usage Min | 1 |
| Usage Max | 1 |
| Logical Min | 0 |
| Logical Max | 255 |
| Report Size | 8 |
| Report Count | 34 |

Each report has a maximum size of 34 bytes. This is derived from the minimum bootloader packet size of 32 bytes, plus a 2-byte report header that indicates the length \(in bytes\) of the packet sent in the report.

**Note:** In the future, the maximum report size may be increased, to support transfers of larger packets. Alternatively, additional reports may be added with larger maximum sizes.

The actual data sent in all of the reports looks like:


| 0 | Report ID |
| --- | --- |
| 1 | Packet Length LSB |
| 2 | Packet Length MSB |
| 3 | Packet[0] |
| 4 | Packet[1] |
| 5 | Packet[2] |
|  | ... |
| N+3-1 | Packet[N-1] |

This data includes the Report ID, which is required if more than one report is defined in the HID report descriptor. The actual data sent and received has a maximum length of 35 bytes. The Packet Length header is written in little-endian format, and it is set to the size \(in bytes\) of the packet sent in the report. This size does not include the Report ID or the Packet Length header itself. During a data phase, a packet size of 0 indicates a data phase abort request from the receiver.

**Parent topic:**[Supported peripherals](../topics/supported_peripherals_001.md)

