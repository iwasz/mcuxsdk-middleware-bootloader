# Choosing a starting point

The first step is to download the latest bootloader release. Updates for the bootloader are released multiple times per year, so having the latest package is important for finding the best starting point for your port. To find the most recent bootloader release, click on [mcuxpresso.nxp.com](https://mcuxpresso.nxp.com/en/welcome), select middleware mcu-boot when configuring the sdk package. MCU Bootloader projects can be found in <sdk\_package\>/boards/<board\>/bootloader\_examples.

The easiest way to port the bootloader is to choose a supported target that is the closest match to the desired target device.

**Note:** Just because a supported device has a similar part number to the desired target device, it may not necessarily be the best starting point. To determine the best match, refer to the data sheet and reference manual for all of the supported MCU devices.

**Parent topic:**[MCU bootloader porting](../topics/mcu_bootloader_porting.md)

