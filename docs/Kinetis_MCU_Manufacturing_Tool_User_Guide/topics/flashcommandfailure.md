# FlashCommandFailure

```
{
   "command" : "write-memory",
   "response" : [],
   "status" : {
      "description" : "105 (0x69) kStatus_FlashCommandFailure",
      "value" : 105
   }
}
```

The possible cause for the failure may be the flash region not being erased before writing to it. A flash-erase-region command must be called before writing to it.

**Parent topic:**[Examples of common failure error messages in the log](../topics/examples_of_common_failure_error_messages_in_the_l.md)

