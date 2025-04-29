# Clock configuration

The clock configuration used by the bootloader depends on the clock settings in the bootloader configuration area and the requirements of the enabled peripherals. The bootloader starts by using the default clock configuration of the part out of reset.

-   Alternate clock configurations are supported by setting fields in the bootloader configuration data.
-   If the HighSpeed flag of the clockFlags configuration value is cleared, the core and bus clock frequencies are determined by the clockDivider configuration value.
-   The core clock divider is set directly from the inverted value of clockDivider, unless a USB peripheral is enabled. If a USB peripheral is enabled and clockDivider is greater than 2, clockDivider is reduced to 2 in order to keep the CPU clock above 20 MHz.
-   The bus clock divider is set to 1, unless the resulting bus clock frequency is greater than the maximum supported value. In this instance, the bus clock divider is increased until the bus clock frequency is at or below the maximum.
-   The flash clock divider is set to 1, unless the resulting flash clock frequency is greater than the maximum supported value. In this instance, the flash clock divider is increased until the flash clock frequency is at or below the maximum.
-   If flex bus is available, the flex bus clock divider is set to 1, unless the resulting flex bus clock frequency is greater than the maximum supported value. In this instance, the flex bus clock divider is increased until the flex bus clock frequency is at or below the maximum.
-   If a USB peripheral is enabled, the IRC48Mhz clock is selected as the USB peripheral clock and the clock recovery feature is enabled.
-   Note that the maximum baud rate of serial peripherals is related to the core and bus clock frequencies.
-   Note that the bootloader code does not always configure the device core clock to run at 48 MHz. For devices with no USB peripheral and when HighSpeed flag is not enabled in the BCA, the core clock is configured to run at default clock rate \(i.e., 20.9 MHz\). This is also true for devices with USB but HighSpeed flag is not enabled in the BCA.

**Parent topic:**[Functional description](../topics/functional_description.md)

