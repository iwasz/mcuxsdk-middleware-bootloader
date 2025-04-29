# No response received for the ping command

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

There could be several reasons for such error. Here are some troubleshooting steps:

-   See the reference manual for the device to ensure that the device is supported by the MCU bootloader.
-   Check whether the device is powered up.
-   The device may boot off the image on the flash and not the MCU bootloader image from the ROM or flash. Erase the flash memory and try again to enable the device to boot into the MCU bootloader mode.
-   Direct boot feature can be enabled. Erase the flash and try again to boot into the MCU bootloader.

**Parent topic:**[Examples of common failure error messages in the log](../topics/examples_of_common_failure_error_messages_in_the_l.md)

