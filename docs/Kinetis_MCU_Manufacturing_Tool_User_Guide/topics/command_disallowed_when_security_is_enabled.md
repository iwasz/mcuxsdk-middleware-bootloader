# Command disallowed when security is enabled



```
{
   "command" : "flash-erase-all",
   "response" : [],
   "status" : {
      "description" : "10001 (0x2711) Command disallowed when security is enable
d.",
      "value" : 10001
   }
}
```

The device is in a secure state and cannot be programmed. To program a secured device, add the unlock command to the ucl2.xml file.

**Parent topic:**[Examples of common failure error messages in the log](../topics/examples_of_common_failure_error_messages_in_the_l.md)

