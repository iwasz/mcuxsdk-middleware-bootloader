# UnknownCommand

```
{
   "command" : "flash-erase-all-unsecure",
   "response" : [],
   "status" : {
      "description" : "10000 (0x2710) kStatus_UnknownCommand",
      "value" : 10000
   }
}
```

The blhost.exe can execute all MCU bootloader commands. However, the command itself may not be supported by the target MCU bootloader device. See the ROM Bootloader/Flashloader chapter of the device reference manual to check whether the command is supported.

**Parent topic:**[Examples of common failure error messages in the log](../topics/examples_of_common_failure_error_messages_in_the_l.md)

