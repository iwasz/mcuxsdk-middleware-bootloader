# Flashloader

The MCU bootloader is a standard bootloader for Kinetis devices. It provides a standard interface to the device using any of the peripherals supported by the bootloader on a given Kinetis device.

The flashloader is a specific implementation of the MCU bootloader. For the flashloader implementation, the MCU bootloader command interface is packaged as an executable. This executable is loaded from flash and executed from RAM. This configuration allows the user to place the application at the beginning of the on-chip flash where it automatically launches when the device boots from flash.

Other MCU bootloader implementations include a ROM-based bootloader and a flash-resident bootloader. The MCU bootloader is available as source code for custom flash-based implementations. The package includes source code and example applications to demonstrate how to interface with the bootloader.

Using the flashloader to program a user application to the beginning of the Kinetis flash makes this implementation of the bootloader a one-time programming aid.

The developers creating a manufacturing flow for their hardware and software implementations may restore flashloader so that the device works as it did in the NXP factory. To accomplish this, use an external debugger to program the `flashloader_loader.bin` file built from flashloader\_loader project to the Kinetis on-chip flash. The procedure for programming `flashloader_loader.bin` varies depending on hardware design and available tools.


