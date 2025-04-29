# Generate SB file for FlexSPI NAND image programming 

For FlexSPI NAND boot, the IVT offset is always 0x400. However, to reduce effort in calculating the start address for each firmware region, the Flashloader supports programming the FlexSPI NAND boot image to corresponding firmware region in block granularity. So, the bootable image without “\_nopadding” suffix will be used.

-   **[Generate SB file for FlexSPI NAND image programming](../topics/generate_sb_file_for_flexspi_nand_image_programmin.md)**  

-   **[Generate SB file for encrypted FlexSPI NAND Image and KeyBlob programming](../topics/generate_sb_file_for_encrypted_flexspi_nand_image_.md)**  




