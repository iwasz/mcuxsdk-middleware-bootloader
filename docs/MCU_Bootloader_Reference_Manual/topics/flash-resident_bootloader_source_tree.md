# Flash-resident bootloader source tree

It is important to understand the source tree to understand where modifications are possible. Here is an example of a source tree for one of the bootloader configurations.

There are two folders in each bootloader project: a device-specific folder and a “source” folder. All files in the device-specific folder are located in the <sdk\_package\>/ middleware/mcu-boot/targets/<device\>/src folder, and are specific to the target device. The “source” folder is located at the top level of the bootloader tree, and the subfolders in the project correspond to the real folder/file structure on the PC. The files in the “source” folder are the core files of the bootloader.

The bootloader source is separated in a way that creates a clear line between what a user needs to modify and what they do not. Among other things, the files in the devicespecific folder allow the application to select which peripherals are active as well as how to configure the clock, and are intended to be modified by the user. The files in the “source” folder can be modified, but should only require modification where very specific customization is needed in the bootloader.

**Parent topic:**[Creating a custom flash-resident bootloader](../topics/creating_a_custom_flash-resident_bootloader.md)

