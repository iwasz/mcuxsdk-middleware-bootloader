# Modifying a peripheral configuration macro

The bootloader\_confg.h file is located in <sdk\_package\>/middleware/mcu-boot/targets/<device\>/src. It contains macros such as:

```
#if !defined(BL_CONFIG_SPI0)
#define BL_CONFIG_SPI0 (1)
#endif
```

To remove an interface, either modify this file to set the macro to \(0\), or pass the macro define to the toolchain compiler in the project settings. For example:

BL\_CONFIG\_SPI0=0

Setting this macro to zero removes the interface from the g\_peripherals table and prevents related code from linking into the bootloader image.

**Parent topic:**[Creating a custom flash-resident bootloader](../topics/creating_a_custom_flash-resident_bootloader.md)

