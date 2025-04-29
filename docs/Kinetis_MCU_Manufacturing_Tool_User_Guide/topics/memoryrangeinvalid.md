# MemoryRangeInvalid

```
{
   "command" : "write-memory",
   "response" : [],
   "status" : {
      "description" : "10200 (0x27D8) kStatusMemoryRangeInvalid",
      "value" : 10200
   }
}
```

The memory range may be in the reserved region used by the bootloader. See the device reference manual for the available memory region to program the flash and fix the address range for the command accordingly.

**Parent topic:**[Examples of common failure error messages in the log](../topics/examples_of_common_failure_error_messages_in_the_l.md)

