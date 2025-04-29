# i.MX RT BootROM

The i.MX RT BootROM is a standard bootloader for all i.MX RT devices. It resides in ROM and supports booting from external flash devices for both XIP and non-XIP boot cases. It also provides serial downloader feature via UART or USB-HID interface into the internal RAM of i.MX RT devices.

The i.MX RT BootROM is a specific implementation of the existing i.MX MPU ROM bootloader. The i.MX RT BootROM provides serial downloader feature for flash programming using command interface. For additional information, see chapter, *“System Boot”* in the . Using the MfgTool application, the MCU Boot based flashloader can be downloaded into the internal SRAM. Then the flashloader code execution begins and flash programming features are enabled via MCU Boot interface.