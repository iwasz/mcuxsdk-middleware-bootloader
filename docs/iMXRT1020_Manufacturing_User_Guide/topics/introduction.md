# Introduction

This document describes the generation of bootable images for i.MX RT devices. It also explains the process to interface i.MX RT BootROM and MCUBOOT-based Flashloader and to program a bootable image into the external flash including:

-   QuadSPI NOR / Octal Flash / HyperFlash
-   Serial NAND
-   eMMC
-   SD
-   Parallel NOR
-   SLC raw NAND
-   SPI NOR / EEPROM

The i.MX RT BootROM resides in the ROM and enables loading the RAM. The Flashloader is loaded into SRAM and facilitates loading of boot images from boot devices into RAM. It also authenticates and executes the boot image.

This document introduces the Flashloader, a companion tool to i.MX RT BootROM, and a complete solution for programming boot images to bootable devices. The Flashloader runs in SRAM so it should be downloaded to SRAM via ROM serial download interface. The Flashloader prepares and configures the devices for boot. It creates boot configuration structure on the bootable media, helps in programming encrypted images, generates key blobs, and communicates with master on serial peripherals like USB and UART using MCUBOOT commands interface protocol for downloading boot images.

It also introduces the elftosb utility. The elftosb utility converts an elf image to signed, encrypted, and bootable image for i.MX RT devices. It also creates all the boot structures like image vector table, boot data. It generates the input command sequence file required to code sign or encrypt using the NXP signing tool \(cst\). It also calls the cst to generate the signatures and packs it as a boot image acceptable by BootROM.

The document describes the usage of MfgTool2.exe \(Manufacturing Tool\) in a manufacturing environment for production of devices \(programming boot images on the bootable media using all the available tools\).

