# BD file for memory programming

Typically, “load”, “enable”, and “erase” commands are the most commonly used commands in a BD file for memory programming.

1.  **load** command: This command loads raw binary, srec file, elf file, and hex string. It also supports loading data to external memory devices, for example:
    -   Load itcm\_boot\_image.bin \> 0x8000; \(Load data to ITCM\)
    -   Load flexspi\_nor\_boot\_image.bin \> 0x60001000; \(Load data to the memory mapped memory device\)
2.  **enable** command: This command configures external memory devices, for example:
    -   Enable flexspinor 0x1000
3.  **erase** command: This command erases a memory range in the selected memory device. For example:
    -   Erase 0x60000000..0x60010000 \(Erase 64 KB from FlexSPI NOR\)