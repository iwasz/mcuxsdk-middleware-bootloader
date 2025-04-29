# Program Signed Image to Flash using MfgTool

Here are the steps to program boot image into the Flash device

1.  Copy the boot\_image.sb file, ivt\_flashloader\_signed.bin and enable\_hab.sb to “<mfgtool\_root\_dir\>/Profiles/MXRT106X/OS Firmware” folder
2.  Change the “name” under “\[List\]” to “MXRT106x-SecureBoot” in cfg.ini file in <mfgtool\_root\_dir\> folder
3.  Put the RT10604-EVK board to Serial Downloader mode by setting SW7 to “1-OFF, 2-OFF, 3-OFF, 4-ON”
4.  Power up RT10604-EVK board, and insert USB cable to J9
5.  Open MfgTool, it will show the detected device.
6.  Click “Start”, MfgTool will do manufacturing process and after completion, it will show the status as success. Click “Stop” and close the MfgTool
7.  Put the RT10604-EVK board to internal boot mode and select QSPI FLASH as boot device by setting SW7 to “1-OFF, 2-OFF,3-ON, 4-OFF”. Reset the device. The LED above the ethernet interface starts blinking which indicates that the image is running.


