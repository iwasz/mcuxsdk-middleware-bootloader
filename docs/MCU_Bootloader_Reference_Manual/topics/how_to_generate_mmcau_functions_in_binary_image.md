# How to generate MMCAU functions in binary image

1.  Add the MMCAU driver to the project.

    Add the MMCAU driver `mmcau_aes_functions.c` to the project. There are only three functions in this driver.

    ```
    //! @brief An initialization function for the decryption peripheral
    void mmcau_aes_init(uint32_t *key, uint32_t *keySchedule, uint32_t *rcon);
    //! @brief Encrypts a 16 byte block of data//!
    in and out may use the same address so encrypting in place is supported
    void mmcau_aes_encrypt(uint32_t *in, uint32_t *key, uint32_t *keySchedule, uint32_t *out);
    //! @brief Decrypts a 16 byte block of data//!
    in and out may use the same address so decrypting in place is supported
    void mmcau_aes_decrypt(uint32_t *in, uint32_t *key, uint32_t *keySchedule, uint32_t *out);
    ```

    The following figure shows that the driver has been added to the K80F256 bootloader project

2.  Change the compile optimization level to low.

3.  Compile the project and view the map file while generating the binary file for the entire project. The start address and offset of `mmcau_aes_init, mmcau_aes_encrypt,` and `mmcau_aes_decrypt` are shown.

4.  Open the list file to see the MMCAU algorithm length - 1212 = 0x4BC.

5.  Extract functions from the address of `mmcau_aes_init` \(0x2058 in this case\) by the MMCAU algorithm length \(0x4BC\) and save it. This is the MMCAU algorithm only. See `mmcau_function_cm4.bin`.

6.  Add the MMCAU algorithm to the Bootloader Configuration Area \(BCA\).

    The MMCAU algorithm can be loaded to any accesible memory, such as RAM or flash. However, you need to update the BCA in order to have a pointer to an MMCAu set-up structure. See `aeas_security.h` for the structure definition.

    ```
    {
        uint32_t tag;                // 'kcau' = 0x
        uint32_t length;            // number of bytes to copy, copied from the start of aes_init
        uint32_t aes_init_start;
        uint32_t aes_encrypt_start;
        uint32_t aes_decrypt_start;
    } mmcau_function_info_t;
    ```

    The location offset of the MMCAU algorithm is x020. The BCA start is 0x3C0, and the `mmcau_function_info` address is 0x3E0. For decryption to work properly, the `mmcau_function_info` must contain valid values for all the fields in this structure. This structure size is 20 bytes \(0x14 bytes\).

    -   Tag

        The tag field must equal 'kcau'

    -   Length

        It is the total length of all MMCAU AES algorithms. See `mmcau_aes_functions.lst`. It is 1212 bytes \(0x4BC\).

    -   `aes_init_start`

        Memory location of the `aes_init` function, the address where `mmcau_function_cm4.bin` is to be loaded. This function size is 0xD6.

    -   `aes_encrypt_start`

        Memory location of the `aes_encrypt` function. This function size is 0x1B0.

    -   `aes_decrypt_start`

        Memory location of the `aes_decrypt` function. This function size is 0x1BE.

        The figure below contains information for each function.

7.  Example - Add the MMCAU algorithm after the BCA.
    -   BCA 0x30 ~ 0x3DF
    -   MMCAU setup in BCA - 0x3E0, which shows the start of `mmcau_function_info`
    -   Tag in `mmcau_function_info` \(0x410 ~ 0x413\)

        The values of 0x410 ~ 0x4\`3 are 'kcau'

    -   Length in `mmcau_function_into` \(0x414 ~ 0x417\)

        The value is 0x000004BC

    -   `aes_init_start` in `mmcau_function_into` \(0x418 ~ 0x41b\)

        The value is 0x00000424 \(0x410 + 0x14 \(`mmcau_function_info` structure size\)\)

    -   `aes_encrypt_start` in `mmcau_function_info` \(0x41c ~ 0x41f\)

        The value is 0x000004fa \(0x424 + 0xd6 \(`mmcau_aes_init` function size\)\)

    -   `aes_decrypt_start` in `mmcau_function_info` \(0x420 ~ 0x423\)

        The value is 0x000006aa \(0x4fa + 0x1b0 \(`mmcau_aes_encrypt` function size\)\)

    -   The MMCAU algorithm starts from flash address 0x424



**Parent topic:**[Creating a custom flash-resident bootloader](../topics/creating_a_custom_flash-resident_bootloader.md)

