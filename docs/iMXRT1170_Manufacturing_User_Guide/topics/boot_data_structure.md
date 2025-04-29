# Boot data structure

**Boot Data structure**

|Offset|Field|Description|
|---|---|---|
|0x00\-0x03|start|Absolute address of the bootable image|
|0x04\-0x07|length|Size of the bootable image|
|0x08\-0x0b|plugin|Plugin flag, set to 0 because plugin boot is not supported on the RT1170|


**Parent topic:**[Boot image format](../topics/boot_image_format.md)

