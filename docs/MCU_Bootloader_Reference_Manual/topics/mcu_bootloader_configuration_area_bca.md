# MCU Bootloader Configuration Area \(BCA\)

The MCU bootloader reads data from the Bootloader Configuration Area \(BCA\) to configure various features of the bootloader. The BCA resides in flash memory at offset 0x3C0 from the beginning of the user application and provides all the parameters required to configure the bootloader operation. For uninitialized flash, the MCU bootloader uses a predefined default configuration. A host application can use the MCU bootloader to program the BCA for use during subsequent initializations of the bootloader.

**Note:** Flashloader does not support this feature.

**Configuration Fields for the MCU bootloader**
|Offset|Size \(bytes\)|Configuration Field|Description|
|:----:|:------------:|-------------------|-----------|
|0x00 - 0x03|4|tag|Magic number to verify bootloader configuration is valid. Must be set to 'kcfg'.|
|0x04 - 0x07|4|crcStartAddress|Start address for application image CRC check. To generate the CRC, see the CRC chapter.|
|0x08 - 0x0B|4|crcByteCount|Byte count for application image CRC check.|
|0x0C - 0x0F|4|crcExpectedValue|Expected CRC value for application CRC check.|
|0x10|1|enabledPeripherals|Bitfield of peripherals to enable.<br> bit 0 UART<br>bit 1 I2C <br>bit 2 SPI <br>bit 3 CAN<br>bit 4 USB-HID<br>bit 7 USB MSC|
|0x11|1|i2cSlaveAddress|If not 0xFF, used as the 7-bit I2C slave address.|
|0x12 - 0x13|2|peripheralDetectionTimeout|If not 0xFF, used as the timeout in milliseconds for active peripheral detection.|
|0x14 - 0x15|2|usbVid|Sets the USB Vendor ID reported by the device during enumeration.|
|0x16- 0x17|2|usbPid|Sets the USB Product ID reported by the device during enumeration.|
|0x18 - 0x1B|4|usbStringsPointer|Sets the USB Strings reported by the device during enumeration.|
|0x1C|1|clockFlags|Reserved.See clockFlags Configuration Field.|
|0x1D|1|clockDivider|Reserved.Inverted value of the divider used for core and bus clocks when in high-speed mode.|
|0x1E|1|bootFlags|One's complement of direct boot flag. 0xFE represents direct boot.|
|0x1F|1|pad0|Reserved, set to 0xFF.|
|0x20 - 0x23|4|mmcauConfigPointer|Reserved, holds a pointer value to the MMCAU configuration.|
|0x24 - 0x27|4|keyBlobPointer|Reserved, holds a value to the key blob array used to configure OTFAD.|
|0x28|1|pad1|Reserved.|
|0x29|1|canConfig1|ClkSel\[1\], PropSeg\[3\], SpeedIndex\[4\]|
|0x2A - 0x2B|2|canConfig2|Pdiv\[8\], Pseg\[3\], Pseg2\[3\], rjw\[2\]|
|0x2C - 0x2D|2|canTxId|txId|
|0x2E - 0x2F|2|canRxId|rxId|
|0x30 - 0x33|4|qspiConfigBlockPointer|QuadSPI configuration block pointer|

The first configuration field 'tag' is a tag value or magic number. The bootloader configuration data is valid if the tag value is set to 'kcfg'. If tag-field verification fails, the MCU bootloader acts as if the configuration data is not present. The tag value is treated as a character string, so bytes 0-3 must be set as shown in the table.

**tag Configuration Field**
|Offset|tag Byte Value|
|:----:|:------------:|
|0|'k' \(0x6B\)|
|1|'c' \(0x63\)|
|2|'f' \(0x66\)|
|3|'g' \(0x67\)|

The flags in the clockFlags configuration field are enabled if the corresponding bit is cleared \(0\).

**clockFlags Configuration Field**
|Bit|Flag|Description|
|:-:|----|-----------|
|0|HighSpeed|Enable high-speed mode \(i.e., 48 MHz\).|
|1 - 7|-|Reserved.|

**Parent topic:**[Functional description](../topics/functional_description.md)

