# Download MCUXpresso SDK

Porting the MCU bootloader to a new target is a manual process that requires updating the device header files. This process is time-consuming and error-prone, so NXP provides Software Development Kit \(SDK\) for ARM Cortex-M Core devices. SDK package contains device header files and drivers. These SDK packages can be downloaded from [mcuxpresso.nxp.com](https://mcuxpresso.nxp.com/en/welcome).

**Note:** Do not proceed with a port if a package does not yet exist for the desired target device.

In the downloaded package, header files including <device\>.h, <device\>\_features.h, fsl\_device\_registers, system\_<device\>.h can be found in devices/<device\>, and drivers can be found in devices/<device\>/drivers. Add these two folders to include directories of the target device's bootloader project or add these header files and drivers to the target device's bootloader project.

**Parent topic:**[Preliminary porting tasks](../topics/preliminary_porting_tasks.md)

