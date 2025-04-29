# BD file for memory programming

Typically, “load”, “enable”, and “erase” commands are the most commonly used commands in a BD file for memory programming.

1.  “load” command: This command loads raw binary, srec file, elf file, and hex string. It also supports loading data to external memory devices, for example:
    -   Load itcm\_boot\_image.bin \> 0x8000; \(Load data to ITCM\)
    -   Load flexspi\_nor\_boot\_image.bin \> 0x60001000; \(Load data to the memory mapped memory device\)
    -   Load semc\_nor\_boot\_image.bin \> 0x80001000; \(Load data to SEMC NOR, memory mapped memory device\)
    -   Load spinand boot\_image.bin \> 0x04; \(Load data to SPI NAND\)
    -   Load sdcard boot\_image.bin \> 0x400; \(Load data to the SD Card\)
    -   Load mmccard boot\_image.bin \> 0x400; \(Load data to eMMC\)
    -   Load spieeprom boot\_image.bin \> 0x400; \(Load data to SPI EEPROM/NOR\)
    -   Load semcnand boot\_image.bin \> 0x400; \(Load data to SLC raw NAND via SEMC\)
    -   Load fuse 0x00000000 \> 0x10; \(Load data to the Fuse block\)
2.  “enable” command: This command configures external memory devices, for example:
    -   Enable flexspinor 0x1000
    -   Enable spinand 0x1000
    -   Enable sdcard 0x1000
    -   Enable mmccard 0x1000
    -   Enable spieeprom 0x1000
    -   Enable semcnor 0x1000
    -   Enable semcnand 0x1000
3.  “erase” command: This command erases a memory range in the selected memory device. For example:
    -   Erase 0x60000000..0x60010000 \(Erase 64 KB from FlexSPI NOR\)
    -   Erase spinand 0x4..0x08 \(Erase 4 blocks from SPI NAND\)
    -   Erase sdcard 0x400..0x14000
    -   Erase mmccard 0x400..0x14000
    -   Erase spieeprom 0x400..0x14000
    -   Erase semcnand 0x400..0x14000

