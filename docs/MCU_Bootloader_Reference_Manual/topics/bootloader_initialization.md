# Bootloader initialization

-   Load BCA data from flash at offset, corresponding to the application image start address + 0x3C0.
-   Initialize the CRC check status. If BCA is invalid \(the tag is not set to expected ‘kcfg’ value\), or the CRC parameters in valid BCA are not set, then the CRC check status is set to kStatus\_AppCrcCheckInvalid, meaning the integrity check is not enabled for the device. Otherwise, the CRC check status is set to kStatus\_AppCrcCheckInactive, meaning the integrity check is due for the device.
-   If a boot pin is not asserted and application address is a valid address \(the address is not null, the address resides in a valid executable memory range, and the flash is not blank\), then the bootloader begins the CRC check function. Otherwise, the CRC check function is bypassed.
-   The CRC check function. The bootloader checks the CRC check status initialized in the previous steps, and if it is not kStatus\_AppCrcCheckInvalid \(integrity check is enabled for the device\), then the bootloader verifies the application resides in internal flash or external QSPI flash.
    -   If the application address range is invalid, then the bootloader sets the status to kStatus\_AppCrcCheckOutOfRange.
    -   If the application address range is valid, then the CRC check process begins. If the CRC check passes, then the bootloader sets the status to kStatus\_AppCrcCheckPassed. Otherwise, the status is set to kStatus\_AppCrcCheckFailed.

**Parent topic:**[MCU bootloader flow with integrity checker](../topics/mcu_bootloader_flow_with_integrity_checker.md)

