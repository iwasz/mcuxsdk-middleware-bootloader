# Example ucl2.xml files

This section provides the typical *ucl2.xml* file content and shows how the different types of image files can be sent to the blhost using different commands, such as write-memory, flash-image, and receive-sb-file.

This is an example of a binary format file passed in an argument for the write-memory-command:

```
<CMD state="Blhost" type="blhost" timeout="5000" body="flash-erase-region 0xA000 0x800">Flash Erase Region</CMD>
<CMD state="Blhost" type="blhost" body="write-memory 0xA000
 \"Profiles\\Kinetis Bootloader\\OS Firmware\\files\\demo.bin\"">Write Memory</CMD>
<CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
```

These are the examples of the srec and hex format files passed with the flash-image command:

```
<CMD state="Blhost" type="blhost" timeout="5000" body="flash-image
 \"Profiles\\Kinetis Bootloader\\OS Firmware\\files\\simple.hex\" erase">Flash Image</CMD>
<CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
```

```
<CMD state="Blhost" type="blhost" timeout="5000" body="flash-image
 \"Profiles\\Kinetis Bootloader\\OS Firmware\\files\\simple.srec\" erase">Flash Image</CMD>
<CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
```

These is an examples of a SB \(Secure Binary\) file passed in an argument for the receive-sb-file command:

```
<CMD state="Blhost" type="blhost" timeout="5000" body="receive-sb-file
 \"Profiles\\Kinetis Bootloader\\OS Firmware\\files\\simple.sb\"">Receive SB File</CMD>
<CMD state="Blhost" type="blhost" body="Update Completed!">Done</CMD>
```

**Parent topic:**[Firmware update process](../topics/firmware_update_process.md)

