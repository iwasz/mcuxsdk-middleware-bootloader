# Create i.MX RT bootable image

Using Chapter 4, *Generate i.MX RT botable image*, based on the memory map assigned for RT102x SoC, here are the steps to generate i.MX RT bootable image using elftosb utility.

1.  Generate the BD file for boot image generation. The BD file content is showed as follows.

    ```
    options {
        flags = 0x00;
        startAddress = 0x60000000;
        ivtOffset = 0x1000;
        initialLoadSize = 0x2000;
    }
    sources {
        elfFile = extern(0);
    }
    section (0)
    {
    }
    ```

2.  Generate the i.MX RT bootable image using elftosb utility.

    Here is the example command:

    **Example command to generate FlexSPI NOR boot image**

    ![](../images/figure22_1.png "Example command to generate FlexSPI NOR boot
                            image")
    -   ivt\_flexspi\_nor\_xip.bin
    -   ivt\_flexspi\_nor\_xip\_nopadding.bin

    The ivt\_flexspi\_nor\_xip\_nopadding.bin will be used to generate SB file for HyperFlash programming in a subsequent section.

**Parent topic:**[Manufacturing process in Development phase](../topics/manufacturing_process_in_development_phase.md)

