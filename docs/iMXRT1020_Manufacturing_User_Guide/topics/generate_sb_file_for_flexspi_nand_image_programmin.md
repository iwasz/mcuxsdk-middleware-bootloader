# Generate SB file for FlexSPI NAND image programming

In general, a BD file for FlexSPI NAND image programming consists of 4 steps.

1.  The bootable image file path is provided in sources block.
2.  Enable FlexSPI NAND access using FlexSPI NAND Configuration Option block.
3.  Erase SPI NAND device as needed.
4.  Program boot image binary into Serial NAND via FlexSPI module.
    <br>
    **Example BD file for FlexSPI NAND image programming**
    ![Figure](../images/figure9_new.png "Example BD file for FlexSPI NAND image programming")

**Parent topic:**[Generate SB file for FlexSPI NAND image programming](../topics/generate_sb_file_for_flexspi_nand_image_programmin_001.md)

