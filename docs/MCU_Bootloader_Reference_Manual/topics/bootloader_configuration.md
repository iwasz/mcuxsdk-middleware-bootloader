# Bootloader configuration

Configure the bootloader to match the supported features and the specific memory map for the target device. Turn features on or off by using \#define statements in the bootloader\_config.h file in middleware/mcu-boot/targets/<device\>/src. See examples for using these macros in bl\_command.c \(g\_commandHandlerTable\[\] table\) in the middleware/mcu-boot/src/bootloader/src folder. All checks that reference a BL\_\* feature can be turned on or off. Examples of these features are BL\_MIN\_PROFILE, BL\_HAS\_MASS\_ERASE, and BL\_FEATURE\_READ\_MEMORY.

One of the most important bootloader configuration choices is where to set the start address \(vector table\) of the user application. This is determined by the BL\_APP\_VECTOR\_TABLE\_ADDRESS define in bootloader\_config.h. Most bootloader configurations choose to place the user application at address 0xA000 because that accommodates the full-featured bootloader image. It is possible to move this start address if the resulting port reduces features \(and therefore, code size\) of the bootloader.

**Note:** Load the Release build of the flash-resident bootloader if you plan to place the user application at 0xA000. Loading the Debug build requires you to move the application address beyond the end of the bootloader image. This address can be determined from the bootloader map file.

**Parent topic:**[Primary porting tasks](../topics/primary_porting_tasks.md)

