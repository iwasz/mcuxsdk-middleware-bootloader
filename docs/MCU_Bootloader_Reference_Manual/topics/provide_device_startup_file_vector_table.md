# Provide device startup file \(vector table\)

A device-specific startup file is a key piece to the port. The bootloader may not function correctly without the correct vector table. A startup file from the closest match device can be used as a reference, but it is strongly recommended that the file be thoroughly checked before using it to port due to differences in interrupt vector mappings between devices.

Create the startup file and place into the `middleware/mcu-boot/targets/<device>/src/startup/<tool chain>` folder. Startup files are often assembly \(\*.s\) and are named startup\_<device\>.s.

**Note:** For Kinetis devices, the 16-byte Flash Configuration Field should be carefully set in the bootloader image. The Flash Configuration Field is placed at the offset 0x400 in the bootloader image. The field is documented in the SOC reference manual under the subsection called, "Flash Configuration Field" in the "Flash Memory Module" chapter. To change the default 16-byte value for the field in the template startup\_<device\>.s file of the bootloader project, follow these steps:

1.  Open the startup\_<device\>.s file in a text editor.
2.  Locate the symbol where Flash Configuration Field is specified. The symbol name is "\_\_FlashConfig" The 16-byte Flash Configuration Field data is enclosed with \_\_FlashConfig and \_\_FlashConfig\_End symbols in the startup\_<device\>.s file
3.  Change the 16-byte setting to the correct value. For example set the flash security byte, enable or disable backdoor access key, specify the 8-byte backdoor key, and so on.
4.  Once the field is updated, save the startup\_<device\>.s file and close the text editor.

**Parent topic:**[Preliminary porting tasks](../topics/preliminary_porting_tasks.md)

