# DFU utility usage

The DFU Utility is the host application used to load the flashloader binary into the internal RAM memory of LPC540xx/LPC54S0xx device connected to the host in USB DFU mode. “dfu-util.exe” is an opensource command line application and is available for Windows® OS, Unix, and Mac® OS platforms. It can be downloaded from [dfu-util.sourceforge.net/releases/](http://dfu-util.sourceforge.net/releases/). The following is the command line to load the flashloader.bin:

`$ dfu-util.exe –D flashloader.bin`

The DFU Utility prints out messages on standard output to indicate whether flashloader.bin got is successfully loaded or not.



