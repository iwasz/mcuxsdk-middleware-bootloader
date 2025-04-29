# Program Image to Flash using MfgTool

Use the following steps to program a boot image into a flash device

1.  Copy the boot\_image.sb file to “<mfgtool\_root\_dir\>/Profiles/device\_name/OS Firmware” folder.
2.  Change the “name” under “\[List\]” to MXRT102x-SecureBoot in cfg.ini file in <mfgtool\_root\_dir\> folder.
3.  Put the device\_name-EVK board to Serial Downloader mode by setting SW7 to “1-OFF, 2-ON, 3-OFF, 4-ON” .
4.  Power up device\_name-EVK board and insert USB cable to J9.
5.  Open MfgTool, it will show as the detected device like the one shown in Figure 19 .
6.  Click “Start”, MfgTool will do manufacturing process. After completion, it will show the status as success as shown in Figure 20 . Click “Stop” and close the MfgTool.
7.  Put the device\_name-EVK board to internal boot mode and select HyperFlash as boot device by setting SW7 to “1-OFF, 2-ON, 3-ON, 4-OFF”. Then reset the device to start running application.

**Parent topic:**[Manufacturing process in Development phase](../topics/manufacturing_process_in_development_phase.md)

