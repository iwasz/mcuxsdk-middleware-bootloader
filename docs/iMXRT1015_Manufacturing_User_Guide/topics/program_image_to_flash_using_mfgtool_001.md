# Program Image to Flash using MfgTool

Here are the steps to program boot image into Flash device

1.  Copy the boot\_image.sb file, ivt\_flashloader\_signed.bin and enable\_hab.sb to “<mfgtool\_root\_dir\>/Profiles/device\_name/OS Firmware” folder.
2.  Change the “name” under “\[List\]” to device\_name-SecureBoot in cfg.ini file in <mfgtool\_root\_dir\> folder.
3.  Put the device\_name-EVK board to Serial Downloader mode by setting SW8 to “1-OFF, 2-ON, 3-OFF, 4-ON”.
4.  Power up device\_name-EVK board, and insert USB cable to J9.
5.  Open MfgTool, it will show the detected device like the one shown in [Connect to the i.MX RT Platform](connect_to_the_imx_rt_platform.md).
6.  Click “Start”, MfgTool will do manufacturing process and after completion, it will show the status as success as shown in [Program bootable image during development](program_bootable_image_during_development.md). Click “Stop” and close the MfgTool.
7.  Put the device\_name-EVK board to internal boot mode and select QSPI NOR Flash as boot device by setting SW8 to “1-OFF, 2-ON, 3-ON, 4-OFF”. Then reset the device to start running the application.