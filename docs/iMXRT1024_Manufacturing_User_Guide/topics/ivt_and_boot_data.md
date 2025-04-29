# IVT and boot data

The IVT is the data structure that the BootROM reads from the boot devices. This data structure supplies the bootable image containing the required data components to perform a successful boot.

See the *Program image* section in the *System Boot* chapter of the device reference manual for more details.

**IVT data structure**

| Offset | Field | Description |
| --- | --- | --- |
| 0x00 - 0x03 | header | •   Byte 0 tag, fixed to 0xD1<p> •   Byte 1,2 length, bit endian format containing the overall length of the IVT in bytes, fixed to 0x00, 0x20<p> •   Byte 3: version, valid values: 0x40, 0x41, 0x42, 0x43 |
| 0x04 - 0x07 | entry | Absolute address of the first instruction to execute from the image, or the vector address of the image |
| 0x08 - 0x0b | reserved1 | Reserved for future use, set to 0 |
| 0x0c - 0x0f | dcd | Absolute address of the image DCD. It is optional, so this field can be set to NULL if no DCD is required |
| 0x10 - 0x13 | boot_data | Absolute address of the boot data |
| 0x14 - 0x17 | self | Absolute address of the IVT |
| 0x18 - 0x1b | csf | Absolute address of the Command Sequence File (CSF) used by the HAB library |
| 0x1c - 0x1f | reserved2 | Reserved, set to 0 |