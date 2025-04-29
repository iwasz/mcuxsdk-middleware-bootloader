# Appendix B: GetProperty and SetProperty commands

Properties are the defined units of data that can be accessed with the GetProperty or SetProperty commands. Properties may be read-only or read-write. All read-write properties are 32-bit integers, so that they can easily be carried in a command parameter. Not all properties are available on all platforms. If a property is not available, GetProperty and SetProperty return kStatus\_UnknownProperty.

The tag values shown in the table below are used with the GetProperty and SetProperty commands to query information about the bootloader.

**Tag values GetProperty and SetProperty**
| Name | Writable | Tag value | Size | Description |
| --- | --- | --- | --- | --- |
| CurrentVersion | no | 0x01 | 4 | The current bootloader version. |
| AvailablePeripherals | no | 0x02 | 4 | The set of peripherals supported on this chip. |
| FlashStartAddress | no | 0x03 | 4 | Start address of program flash. |
| FlashSizeInBytes | no | 0x04 | 4 | Program flash size in bytes. |
| FlashSectorSize | no | 0x05 | 4 | The size of one sector of program flash in bytes. This is the minimum erase size. |
| FlashBlockCount | no | 0x06 | 4 | Number of blocks in the flash array. |
| AvailableCommands | no | 0x07 | 4 | The set of commands supported by the bootloader. |
| CRCCheckStatus | no | 0x08 | 4 | The status of the application CRC check. |
| Reserved | n/a | 0x09 | n/a |  |
| VerifyWrites | yes | 0x0a | 4 | Controls whether the bootloader verifies writes to flash. The VerifyWrites feature is enabled by default.<br>0  - No verification is done.<br>1  - Enable verification. |
| MaxPacketSize | no | 0x0b | 4 | Maximum supported packet size for the currently active peripheral interface. |
| ReservedRegions | no | 0x0c | n | List of memory regions reserved by the bootloader.Returned as value pairs (<start-address- of-region>,<end- address-of-region>).<br>•     If HasDataPhase flag is not set, then the Response packet parameter count indicates number of pairs.<br>•     If HasDataPhase flag is set, then the second parameter is the numberof bytes in the data phase. |
| RAMStartAddress | no | 0x0e | 4 | Start address of RAM. |
| RAMSizeInBytes | no | 0x0f | 4 | RAM size in bytes. |
| SystemDeviceId | no | 0x10 | 4 | Value of theKinetis System Device Identification register. |
| FlashSecurityState | no | 0x11 | 4 | Indicates whether Flash securityis enabled.<br>0  - Flash security is disabled.<br>1  - Flash security is enabled. |
| UniqueDeviceId | no | 0x12 | n | Unique device identification. This value is the concatenation of the Kinetis UniqueIdentification registers. For details, see the Unique Identification registers located in the SIM module. |
| FlashFacSupport | no | 0x13 | 4 | FAC (Flash Access Control) support flag<br>0  - FAC not supported<br>1  - FAC supported |
| FlashAccessSegmentS ize | no | 0x14 | 4 | The size of 1 segment of flash in bytes. |
| FlashAccessSegmentC ount | no | 0x15 | 4 | FAC segment count (The count of flash access segments within the flash model.) |
| FlashReadMargin | yes | 0x16 | 4 | The margin level setting for flash erase and program verify commands.0=Normal 1=User 2=Factory |
| TargetVersion | no | 0x18 | 4 | Target build version number. |
| ExternalMemoryAttribut es | no | 0x19 | 24 | List of attributes supported by the specified memory Id (0=Internal Flash, 1=QuadSpi0). See description for the return value in the section ExternalMemoryAttribu tes Property. |
| ReliableUpdateStatus | - | 0x1a | 4 | Result of last Reliable Update operation. See Table 12-2. |

