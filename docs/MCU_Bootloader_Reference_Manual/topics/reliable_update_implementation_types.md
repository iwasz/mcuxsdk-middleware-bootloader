# Reliable update implementation types

There are two kinds of reliable update implementations. They can be classified as either the software version or hardware version. The main differences between software and hardware implementation are listed below:

**Software and hardware implementation**
|Item|Software implementation|Hardware implementation|
|----|-----------------------|-----------------------|
|Applicable device|All Kinetis devices|Devices with flash swap support|
|Device memory distribution|Bootloader + main application + backup application|Main bootloader + main application + backup bootloader + backup application|
|Backup application address|Flexible|Fixed|
|The ability to keep two applications|No|Yes|

The most obvious difference is that the software implementation copies the backup application to the main application region, while hardware implementation swaps two half flash blocks to make the backup application become the main application. The detailed differences will be reflected in Section 12.2.3, “Reliable update flow”.

See Section 12.3, “Configuration macros” on how to enable different implementations of the reliable update.

**Parent topic:**[Functional description](../topics/functional_description_001.md)

