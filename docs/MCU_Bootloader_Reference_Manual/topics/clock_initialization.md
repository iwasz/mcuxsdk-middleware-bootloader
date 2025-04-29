# Clock initialization

The MCU bootloader typically uses the device default clock configuration in order to avoid dependencies on external components and simplify use. In some situations, the default clock configuration cannot be used due to accuracy requirements of supported peripherals. On devices that have on-chip USB and CAN, the default system configuration is not suficient and the bootloader configures the device to run from the high-precision internal reference clock \(IRC\) if available. Otherwise, it depends on the external oscillator supply.

The bootloader uses the clock\_config\_<device\>.c file in middleware/mcu-boot/targets/ <device\>/src to override the default clock behavior. If the port's target device supports USB, this file can be used. If the port's target device does not support USB, the functions within clock\_config\_<device\>.c can be stubbed out or set to the required port value.

**Parent topic:**[Bootloader peripherals](../topics/bootloader_peripherals_001.md)

