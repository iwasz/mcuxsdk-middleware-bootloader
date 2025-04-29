# Peripheral initialization

After the peripheral configuration has been selected, the low-level initialization must be accounted for. The bootloader automatically enables the clock and configures the peripheral, so the only thing required for the port is to tell the bootloader which pins to use for each peripheral. This is handled in the peripherals\_pinmux.h file in middleware/ mcu-boot/targets/<device\>/src. The hardware\_init\_<device\>.c file selects the boot pin used by the bootloader, which may need to be changed for the new target device.

These files most likely require significant changes to account for the differences between devices when it comes to pin routing. Each function should be checked for correctness and modified as needed.

**Parent topic:**[Bootloader peripherals](../topics/bootloader_peripherals_001.md)

