# Program Image to Flash using MfgTool

Use the following steps to program a boot image into a flash device

1.  Copy the boot\_image.sb file to “<mfgtool\_root\_dir\>/Profiles/MXRT1024/OS Firmware” folder.
2.  Change the “name” under “\[List\]” to MXRT1024-SecureBoot in cfg.ini file in <mfgtool\_root\_dir\> folder.
3.  Put the MXRT1024-EVK board to Serial Downloader mode by setting SW8 to "0001".
4.  Power up MXRT1024-EVK board and insert USB cable to J9.
5.  Open MfgTool, it will show as the detected device like the one shown in [Connect to the i.MX RT Platform](connect_to_the_imx_rt_platform.md).
6.  Click “Start”, MfgTool will do manufacturing process. After completion, it will show the status as success as shown in [Program bootable image during development](program_bootable_image_during_development.md). Click “Stop” and close the MfgTool.
7.  Put the MXRT1024-EVK board to internal boot mode and by setting SW 8 to "0010". Then reset the device to start running application.