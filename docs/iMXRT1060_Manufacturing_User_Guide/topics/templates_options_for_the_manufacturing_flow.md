# Templates options for the Manufacturing flow

To simplify the complexity of the Manufacturing flow, several templates are available in ucl2.xml.

The code block below is an example which is used for programming an SDK XIP project binary into RT1060-EVK board. To enable the XiP users need to

1.  Change the “*name*” item in cfg.ini to “*name = MXRT106x-DevBootSerialFlashXiP*
2.  Compile the SDK project
3.  Generate the binary file for the project
4.  Rename the binary to boot\_image.bin
5.  Copy it to the same folder as ucl2.xml

```

<LIST name="MXRT106x-DevBootSerialFlashXiP" desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="BootStrap" type="boot" body="BootStrap" file="ivt_flashloader.bin">
        Loading Flashloader. </CMD>
    <CMD state="BootStrap" type="jump" onError = "ignore"> Jumping to Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" > Get Property 1. </CMD>
    <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" body="fill-memory 0x2000 4 0xc0000007">
        Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x2000">
        Configure QuadSPI NOR Flash </CMD>
    <!-- This erase size need to be updated based on the actual boot image size-->
    <CMD state="Blhost" type="blhost" timeout="30000" body="flash-erase-region
     0x60000000 0x100000" > Erase 1MBytes </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x60000000
     \"Profiles\\MXRT106x\\OS Firmware\\boot_image.bin\"" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
</LIST>
```

The code block below is an example which is used for programming the SDK XIP project binary into RT1060-EVK board with other FLASH device. Users may need to modify the **_0xc0000007_** configuration option for actual soldered FLASH devices. See chapter "External memory support" in *MCU Flashloader Reference Manual* for more details.

To enable the option, users need to

1.  Change the “*name*” item in cfg.ini to *"name = MXRT106x-DevBootSerialFlashXiP\_NoConfigBlock"*
2.  Compile the SDK project
3.  Generate the binary file for the project
4.  Rename the binary to boot\_image.bin
5.  Copy it to the same folder as ucl2.xml

```
<LIST name="MXRT106x-DevBootSerialFlashXiP_NoConfigBlock"
      desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="BootStrap" type="boot" body="BootStrap" file="ivt_flashloader.bin">
        Loading Flashloader. </CMD>
    <CMD state="BootStrap" type="jump" onError = "ignore">
        Jumping to Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" > Get Property 1. </CMD>
    <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" body="fill-memory 0x2000 4 0xc0000007">
        Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x2000">
        Configure Serial FLASH </CMD>
    <!-- This erase size need to be updated based on the actual boot image size-->
    <CMD state="Blhost" type="blhost" timeout="30000" body="flash-erase-region
     0x60000000 0x10000" > Erase 64KBytes </CMD>
    <CMD state="Blhost" type="blhost" body="fill-memory 0x3000 4 0xf000000f">
        Prepare Magic number for config block programming </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x3000">
        Write auto-generated config block to QuadSPI NOR Flash </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x60001000
     \"Profiles\\MXRT106x\\OS Firmware\\boot_image.bin\"" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
</LIST>
```

The code block below is an example which is used for programming the SDK XIP project binary without FCB and Boot data information. Users may need to modify the **_0xc0000007_**in the configuration option for actual soldered FLASH device. See chapter "External memory support" in *MCU Flashloader Reference Manual* for more details.

To enable the option, users need to

1.  Change the “*name*” item in cfg.ini to “*name = MXRT106x-DevBootSerialFlashXiP\_NoConfigBlockBootData*”
2.  Compile the SDK project
3.  Generate the binary file for the project
4.  Rename the binary to boot\_image.bin
5.  Copy it to the same folder as ucl2.xml

**Note:**

1.  The application start address must be 0x60002000 for this example.
2.  The default image size is configured to 4 Mbytes in the ivt\_bootdata\_0x6000\_2000. It fits most application requirement. Users can modify offset 0x24-0x27 in this file to change the image size to meet the actual requirement.

```

<LIST name="MXRT106x-DevBootSerialFlashXiP_NoConfigBlockBootData"
      desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="BootStrap" type="boot" body="BootStrap" file="ivt_flashloader.bin">
        Loading Flashloader. </CMD>
    <CMD state="BootStrap" type="jump" onError = "ignore"> Jumping to Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" > Get Property 1. </CMD>
    <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" body="fill-memory 0x2000 4 0xc0000007">
        Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x2000">
        Configure Serial FLASH </CMD>
    <!-- This erase size need to be updated based on the actual boot image size-->
    <CMD state="Blhost" type="blhost" timeout="30000" body="flash-erase-region
     0x60000000 0x100000" > Erase 1MBytes </CMD>
    <CMD state="Blhost" type="blhost" body="fill-memory 0x3000 4 0xf000000f">
        Prepare Magic nubmer for config block programming </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x3000">
        Write auto-generated config block to QuadSPI NOR Flash </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x60001000
     \"Profiles\\MXRT106x\\OS Firmware\\ivt_bootdata.bin\"" >
        Program IVT and Boot data. </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x60002000
     \"Profiles\\MXRT106x\\OS Firmware\\boot_image.bin\"" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
</LIST>
```

The code block below is an example which is used for programming the non-XIP ITCM image which is stored on the FlexSPI NOR. Users may need to modify the **_0xc0000007_**to the configuration option for actual soldered FLASH devices. See chapter "External memory support" in *MCU Flashloader Reference Manual* for more details.

To enable the option, users need to

1.  Change the “*name*” item in cfg.ini to “*name = MXRT106x-DevBootSerialFlashXiP\_ITCM\_0x0000\_1400*”
2.  Compile the SDK project
3.  Generate the binary file for the project
4.  Rename the binary to boot\_image.bin
5.  Copy it to the same folder as ucl2.xml

**Note:**

1.  The application start address must be 0x1400 for this option. The actual boot image starts from address 0x1000, the IVT starts at offset 0x100, and application starts at offset 0x1300.
2.  The default image size is configured to 127 Kbytes in the ivt\_bootdata\_0x0000\_1400. This is because it cannot exceed the default ITCM size\(128KB\).

```

<LIST name="MXRT106x-DevBootSerialFlashNonXiP_ITCM_0x0000_1400"
      desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="BootStrap" type="boot" body="BootStrap" file="ivt_flashloader.bin">
        Loading Flashloader. </CMD>
    <CMD state="BootStrap" type="jump" onError = "ignore"> Jumping to Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" > Get Property 1. </CMD>
    <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" body="fill-memory 0x2000 4 0xc0000007">
        Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x2000">
        Configure Serial FLASH </CMD>
    <!-- This erase size need to be updated based on the actual boot image size-->
    <CMD state="Blhost" type="blhost" timeout="30000" body="flash-erase-region
     0x60000000 0x80000" > Erase 512KBytes </CMD>
    <CMD state="Blhost" type="blhost" body="fill-memory 0x3000 4 0xf000000f">
        Prepare Magic nubmer for config block programming </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x3000">
        Write auto-generated config block to QuadSPI NOR Flash </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x60001000
     \"Profiles\\MXRT106x\\OS Firmware\\ivt_bootdata_0x0000_1400.bin\"" >
        Program IVT, Boot data. </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x60001300
     \"Profiles\\MXRT106x\\OS Firmware\\boot_image.bin\"" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
</LIST>

```

The code block below is an example which is used for programming the non-XIP DTCM image which is stored on the FlexSPI NOR. Users may need to modify the **_0xc0000007_**to the configuration option for actual soldered FLASH devices. See Chapter "External memory support" in the *MCU Flashloader Reference Manual* for more details.

To enable the option, users need to

1.  Change the “*name*” item in cfg.ini to “*name = MXRT106x-DevBootSerialFlash XiP\_DTCM\_0x2000\_2000*”
2.  Compile the SDK project
3.  Generate the binary file for the project
4.  Rename the binary to boot\_image.bin
5.  Copy it to the same folder as ucl2.xml

**Note:**

1.  The application start address must be 0x20002000 for this option. The actual boot image starts from address 0x20000000, the IVT starts at offset 0x1000, and application starts at offset 0x2000.
2.  The default image size is configured to 128 Kbytes in the ivt\_bootdata\_0x2000\_2000. This is because it cannot exceed the default DTCM size\(128 KB\).

```

<LIST name="MXRT106x-DevBootSerialFlashNonXiP_DTCM_0x2000_2000"
      desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="BootStrap" type="boot" body="BootStrap" file="ivt_flashloader.bin">
        Loading Flashloader. </CMD>
    <CMD state="BootStrap" type="jump" onError = "ignore"> Jumping to Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" > Get Property 1. </CMD>
    <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" body="fill-memory 0x2000 4 0xc0000007">
        Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x2000">
        Configure Serial FLASH </CMD>
    <!-- This erase size need to be updated based on the actual boot image size-->
    <CMD state="Blhost" type="blhost" timeout="30000" body="flash-erase-region
     0x60000000 0x80000" > Erase 512KBytes </CMD>
    <CMD state="Blhost" type="blhost" body="fill-memory 0x3000 4 0xf000000f">
        Prepare Magic nubmer for config block programming </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x3000">
        Write auto-generated config block to QuadSPI NOR Flash </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x60001000
     \"Profiles\\MXRT106x\\OS Firmware\\ivt_bootdata_0x2000_2000.bin\"" >
        Program IVT, Boot data. </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x60002000
     \"Profiles\\MXRT106x\\OS Firmware\\boot_image.bin\"" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
</LIST>

```

The code block below is an example which is used for programming the non-XIP OCRAM image which is stored on the FlexSPI NOR. Users may need to modify the **_0xc0000007_**to the configuration option for actual soldered FLASH devices. See chapter "External memory support" in *MCU Flashloader Reference Manual* for more details.

To enable the option, users need to

1.  Change the name item in cfg.ini to “*name = MXRT106x-DevBootSerialFlashNonXiP\_OCRAM\_0x2020\_a000*”
2.  Compile the SDK project
3.  Generate the binary file for the project
4.  Rename the binary to boot\_image.bin
5.  Copy it to the same folder as ucl2.xml

**Note:**

1.  The application start address must be 0x2020a000 for this option. The actual boot image starts from address 0x20208000, the IVT starts at offset 0x1000, and application starts at offset 0x2000.
2.  The default image size is configured to 736Kbytes in the ivt\_bootdata\_0x2020\_a000. This is because it cannot exceed the default OCRAM size \(768KB - 32KB Reserved RAM size for ROM use\).

```

<LIST name="MXRT106x-DevBootSerialFlashNonXiP_OCRAM_0x2020_a000"
      desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="BootStrap" type="boot" body="BootStrap" file="ivt_flashloader.bin">
        Loading Flashloader. </CMD>
    <CMD state="BootStrap" type="jump" onError = "ignore"> Jumping to Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" > Get Property 1. </CMD>
    <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" body="fill-memory 0x2000 4 0xc0000007">
        Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x2000">
        Configure Serial FLASH </CMD>
    <!-- This erase size need to be updated based on the actual boot image size-->
    <CMD state="Blhost" type="blhost" timeout="30000" body="flash-erase-region
     0x70000000 0x80000" > Erase 512KBytes </CMD>
    <CMD state="Blhost" type="blhost" body="fill-memory 0x3000 4 0xf000000f">
        Prepare Magic nubmer for config block programming </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x3000">
        Write auto-generated config block to QuadSPI NOR Flash </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x70001000
     \"Profiles\\MXRT106x\\OS Firmware\\ivt_bootdata_0x2020_a000.bin\"" >
        Program IVT, Boot data. </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x70002000
     \"Profiles\\MXRT106x\\OS Firmware\\boot_image.bin\"" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
</LIST>

```

The code block below is an example which is used for general purpose. SB format boot image, boot\_image.sb, needs to be created and copied to the same folder as ucl2.mxl. Details of creating SB format boot image can be found in chapter 4 and chapter 5.

```

<LIST name="MXRT106x-DevBoot" desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="BootStrap" type="boot" body="BootStrap" file="ivt_flashloader.bin">
        Loading Flashloader. </CMD>
    <CMD state="BootStrap" type="jump" onError = "ignore"> Jumping to Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" > Get Property 1. </CMD>
    <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" timeout="15000" body="receive-sb-file
     \"Profiles\\MXRT106X\\OS Firmware\\boot_image.sb\"" > Program Boot image </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
</LIST>

```

The code block below is an example which is used for general purpose in production phase. SB format boot image, boot\_image.sb, needs to be created and copied to the same folder as ucl2.mxl. Details of creating SB format boot image can be found in chapter 4 and chapter 5.

```

<LIST name="MXRT106x-SecureBoot" desc="Boot Signed Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="BootStrap" type="boot" body="BootStrap" file="ivt_flashloader_signed.bin" >
        Loading Flashloader. </CMD>
    <CMD state="BootStrap" type="jump" onError="ignore"> Jumping to Flashloader. </CMD>
<!-- Stage 2, Enable HAB closed mode using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" ifhab="Open" >
        Get Property 1. </CMD> <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" body="receive-sb-file \"Profiles\\MXRT106X\\OS
     Firmware\\enable_hab.sb\"" ifhab="Open" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="reset" ifhab="Open"> Reset. </CMD>
    <!--Reset device to enable HAB Close Mode-->
<!-- Stage 3, Program signed image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 1" ifhab="Close">
        Get Property 1. </CMD> <!--Used to test if flashloader runs successfully-->
    <CMD state="Blhost" type="blhost" timeout="15000" body="receive-sb-file
     \"Profiles\\MXRT106X\\OS Firmware\\boot_image.sb\"" ifhab="Close" >
        Program Boot Image.</CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!" ifhab="Close">Done</CMD>
</LIST>
```