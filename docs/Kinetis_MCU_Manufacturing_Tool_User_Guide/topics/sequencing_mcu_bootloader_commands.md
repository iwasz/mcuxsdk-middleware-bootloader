# Sequencing MCU bootloader commands

The MCU bootloader provides a set of commands to enable the host to find information about the device and to perform operations on the device’s flash memory such as read memory, write memory, erase memory, get or set properties, etc. The list of commands and properties supported by the MCU bootloader are documented in the MCU Bootloader Reference Manual.

The blhost tool is the NXP implementation of Windows OS PC host tool that communicates with MCU bootloader device connected to host via UART or USB-HID interface. The blhost tool is command line driven, the bootloader command and its parameters are passed on the command line and by issuing a sequence of commands full firmware update on the device can be achieved. For complete documentation and usage of blhost, see the *blhost User's Guide* \(document ID MCUBLHOSTUG\) available at [www.nxp.com/MCUBOOT](http://www.nxp.com/KBOOT).

MfgTool support for the MCU bootloader device is limited to identifying the device’s presence, and using blhost as its backend to send commands to the MCU bootloader device. To complete manufacturing the device, the MfgTool expects the blhost commands and parameters to appear in the *body* for each CMD listed in the ucl2.xml file, such as:

```
<CMD state="Blhost" type="blhost" body="flash-erase-region 0xA000 0x800">Flash Erase Region</CMD>
<CMD state="Blhost" type="blhost" body="read-memory 0xA000 0x800">Read Memory</CMD>
<CMD state="Blhost" type="blhost" body="write-memory 0xA000
 \"Profiles\\Kinetis Bootloader\\OS Firmware\\files\\simple.bin\"">Write Memory</CMD>
<CMD state="Blhost" type="blhost" body="read-memory 0xA000 0x800">Read Memory</CMD>
```

The MfgTool cannot send any command to the bootloader directly, and instead uses *blhost.exe*for that purpose. The MfgTool does not decide what command to send, so the ucl2.xml should be crafted with the commands and its parameters needed to send to the device.

Each blhost command appears with separate &lt;CMD&gt; tag. The *state* and *type* indicates bootstrap operation using blhost. The actual blhost command line arguments goes with the *body*tag.

Example:

```
<CMD state="Blhost" type="blhost" body="write-memory 0x0 demo.bin">Write Memory</CMD>
```

In the above example, blhost is invoked for write-memory command with 0x0 and demo.bin as two arguments; 0x0 is the start address location to write the contents of the file demo.bin.

**Note:** The default location where MfgTool locates the demo.bin is the folder where the MfgTool.exe is placed, i.e., "bin\\tools\\mfgtools-rel". The complete path to demo.bin should be specified in the argument if demo.bin is placed elsewhere in the directory structure. For example: `<CMD state="Blhost" type="blhost" body="write-memory 0xA000 \"Profiles\\Kinetis Bootloader\\OS Firmware\\files\\demo.bin\"">Write BIN to A000</CMD>`

The last section of the &lt;CMD&gt; tag is the description text that will appear on MfgTool GUI when MfgTool is invoking the command and collecting its response. In the given example, “Write Memory” appears on the GUI.

The ucl2.xml does not need to specify the arguments needed for the type of connection such as --port or –usb, which is only necessary when using blhost in standalone mode. The MfgTool automatically provides the type of connection arguments to blhost.exe depending on the type of connection.

The MfgTool collects the device’s response that blhost outputs on the stdout, logs the response to MfgTool.log file, and inspects the results, reporting any error on the UI.

**Parent topic:**[Firmware update process](../topics/firmware_update_process.md)

