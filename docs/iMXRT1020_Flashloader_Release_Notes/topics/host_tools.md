# Host tools

The bootloader release contains the binaries for the following PC-based host tools:

-   `MfgTool2.exe`: GUI Windows application to download and program an application image into the external flash device. cfg\_MXRT1020X.ini must be renamed to cfg.ini to use.

Host tools must be used with MCUBOOT and are available for downloaded from [nxp.com/MCUBOOT](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuboot-mcu-bootloader-for-nxp-microcontrollers:MCUBOOT?&tid=vanMCUBOOT).

-   `elftosb`: command-line tool to convert ELF/SREC formatted application image into bootable image format \(or SB format\). It is available on Windows and Linux platforms.
-   `blhost`: command-line debug tool called by MfgTool to program the application. It is available for Windows, Linux, and Mac operating systems.

