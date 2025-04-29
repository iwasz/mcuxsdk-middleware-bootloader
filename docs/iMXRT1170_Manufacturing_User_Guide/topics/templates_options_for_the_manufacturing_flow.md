# Templates options for the Manufacturing flow

To simplify the complexity of the Manufacturing flow, several templates are available in ucl2.xml.

The code block below is an example which is used for programming an SDK XIP project binary into RT1170-EVK board. To enable the XiP users need to

1.  Change the “*name*” item in cfg.ini to “*name = MXRT117x-DevBootFlexSpi1\_FlashXiP*
2.  Compile the SDK project
3.  Generate the binary file for the project
4.  Rename the binary to boot\_image.bin
5.  Copy it to the same folder as ucl2.xml

```
<!-- This List is for the MCUXpresso SDK XIP demo download via the MfgTool -->
<LIST name="MXRT117x-DevBootFlexSpi1_FlashXiP" desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="Blhost" type="blhost" body="load-image \"Profiles\\MXRT117x\\OS Firmware\\ivt_flashloader.bin"> Loading and running Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 12" > Get Property 12. </CMD> <!--Used to test if flashloader runs successfully-->
  <CMD state="Blhost" type="blhost" body="fill-memory 0x20000000 4 0xcf900001"> Select Instance : 1</CMD>
  <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x20000000"> Enable the FLEXSPI 1 support </CMD>
  <!--Note: This configuration is just an example, please use the correct option for the flash device soldered on the platorm
        See the usage of the configuration option from the System Boot, FLEXSPI NOR API section
  -->
  <CMD state="Blhost" type="blhost" body="fill-memory 0x20000000 4 0xc0000006> Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x20000000"> Configure QuadSPI NOR Flash </CMD>
    <!-- This erase size need to be updated based on the actual boot image size-->
    <CMD state="Blhost" type="blhost" timeout="30000" body="flash-erase-region 0x30000000 0x100000" > Erase 1MBytes </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x30000400 \"Profiles\\MXRT117x\\OS Firmware\\boot_image.bin\"" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
    </LIST>
```

The code block below is an example which is used for programming the SDK XIP project binary into RT1170-EVK board with other FLASH device. Users may need to modify the **_0xc0000006_** configuration option for actual soldered FLASH devices. See chapter "External memory support" in *MCU Flashloader Reference Manual* for more details.

To enable the option, users need to

1.  Change the “*name*” item in cfg.ini to *MXRT117x-DevBootFlexSpi1\_FlashXiP\_NoConfigBlock"*
2.  Compile the SDK project
3.  Generate the binary file for the project
4.  Rename the binary to boot\_image.bin
5.  Copy it to the same folder as ucl2.xml

```
<!-- This List is for the MCUXpresso SDK XIP demo download via the MfgTool -->
<LIST name="MXRT117x-DevBootFlexSpi1_FlashXiP_NoConfigBlock" desc="Manufacturing with Flashloader">
<!-- Stage 1, load and execute Flashloader -->
    <CMD state="Blhost" type="blhost" body="load-image \"Profiles\\MXRT117x\\OS Firmware\\ivt_flashloader.bin"> Loading and running Flashloader. </CMD>
<!-- Stage 2, Program boot image into external memory using Flashloader -->
    <CMD state="Blhost" type="blhost" body="get-property 12" > Get Property 12. </CMD> <!--Used to test if flashloader runs successfully-->
  <CMD state="Blhost" type="blhost" body="fill-memory 0x20000000 4 0xcf900001"> Select Instance : 1</CMD>
  <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x20000000"> Enable the FLEXSPI 1 support </CMD>
  <!--Note: This configuration is just an example, please use the correct option for the flash device soldered on the platorm
        See the usage of the configuration option from the System Boot, FLEXSPI NOR API section
  -->
    <CMD state="Blhost" type="blhost" body="fill-memory 0x20000000 4 0xc0000006"> Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x20000000"> Configure QuadSPI NOR Flash </CMD>
    <!-- This erase size need to be updated based on the actual boot image size-->
    <CMD state="Blhost" type="blhost" timeout="30000" body="flash-erase-region 0x30000000 0x100000" > Erase 1MBytes </CMD>
  <!-- Program the Flash Config block to the FLASH ofset 0x400 automatically -->
  <CMD state="Blhost" type="blhost" body="fill-memory 0x20000000 4 0xf000000f"> Prepare Flash Configuration option </CMD>
    <CMD state="Blhost" type="blhost" body="configure-memory 0x9 0x20000000"> Configure QuadSPI NOR Flash </CMD>
    <CMD state="Blhost" type="blhost" timeout="15000" body="write-memory 0x30000400 \"Profiles\\MXRT117x\\OS Firmware\\boot_image.bin\"" > Program Boot Image. </CMD>
    <CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
</LIST>
```

**Parent topic:**[Manufacturing process in Development phase](../topics/manufacturing_process_in_development_phase.md)

