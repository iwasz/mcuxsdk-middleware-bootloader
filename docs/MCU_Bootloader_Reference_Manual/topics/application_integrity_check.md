# Application integrity check

The application integrity check is an important step in the boot process. The MCU bootloader provides an option, and when enabled, does not allow the application code to execute on the device unless it passes the integrity check.

MCU bootloader uses CRC-32 as its integrity checker algorithm. To properly configure this feature, the following fields in the BCA must be set to valid values:

-   Set crcStartAddress to the start address that should be used for the CRC check. This is generally the start address of the application image, where it resides in the flash or QuadSPI memory.
-   Set crcByteCount to the number of bytes to run the CRC check from the start address. This is generally the length of the application image in bytes.
-   Set crcExpectedValue to the checksum. This is the pre-calculated value of the checksum stored in the BCA for the bootloader to compare with the resultant CRC calculation. If the resultant value matches with the crcExpectedValue, then the application image passes the CRC check.

**Note:** See Section 2.3, "The MCU Bootloader Configuration Area \(BCA\)", in the MCU Bootloader Reference Manual \(document MCUBOOTRM\) for details about the BCA.


```{include} ../topics/mcu_bootloader_flow_with_integrity_checker.md
:heading-offset: 2
```

**Parent topic:**[Functional description](../topics/functional_description.md)

