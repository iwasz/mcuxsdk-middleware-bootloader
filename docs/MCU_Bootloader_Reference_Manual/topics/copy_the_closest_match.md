# Copy the closest match

Copy the folder of the device that most closely matches the target device in the /middleware/mcu-boot/targets folder of the bootloader source tree. Rename the folder to match the target device part number.

After the files are copied, browse the newly created folder. Rename all files that have reference to the device from which they were copied. Rename the following files:

-   clock\_config\_<old\_device\>.c —\> clock\_config\_<new\_device\>.c
-   hardware\_init\_<old\_device\>.c —\> hardware\_init \_<new\_device\>.c
-   memory\_map\_<old\_device\>.c —\> memory\_map \_<new\_device\>.c
-   peripherals\_<old\_device\>.c —\> peripherals \_<new\_device\>.c

Copy the following files from their location in devices/<device\>/<tool chain\> to the new middleware/mcu-boot/targets/<device\>/src/startup folder:

-   <tool chain\>/startup\_<device\>.s

**Parent topic:**[Preliminary porting tasks](../topics/preliminary_porting_tasks.md)

