# Introduction

In some situations the ROM-based or full-featured flash-resident bootloader cannot meet the requirements of a use application. Examples of such situations include special signaling requirements on IO and peripherals not supported by the bootloader, or the more basic need to have as small of a code footprint as possible \(for the flash-resident bootloader\). This section discusses how to customize the flash-resident bootloader for a specific use case. The IAR tool chain is used for this example. Other supported tool chains can be similarly configured.

**Parent topic:**[Creating a custom flash-resident bootloader](../topics/creating_a_custom_flash-resident_bootloader.md)

