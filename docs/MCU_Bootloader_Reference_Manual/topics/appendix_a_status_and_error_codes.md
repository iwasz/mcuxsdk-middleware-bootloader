# Appendix A: Status and error codes

Status and error codes are grouped by component. Each component that defines errors has a group number. This expression is used to construct a status code value.

status\_code = \(group \* 100\) + code

Component group numbers are listed in this table.

**Component group numbers**
|Group|Component|
|-----|---------|
|0|Generic errors|
|1|Flash driver|
|4|QuadSPI driver|
|5|OTFAD driver|
|100|Bootloader|
|101|SB loader|
|102|Memory interface|
|103|Property store|
|104|CRC checker|
|105|Packetizer|
|106|Reliable update|

The following table lists all of the error and status codes.

**Status and error codes**
|Name|Value|Description|
|----|-----|-----------|
|kStatus\_Success|0|Operation succeeded without error.|
|kStatus\_Fail|1|Operation failed with a generic error.|
|kStatus\_ReadOnly|2|Property cannot be changed because it is read-only.|
|kStatus\_OutOfRange|3|Requested value is out of range.|
|kStatus\_InvalidArgument|4|The requested command's argument is undefined.|
|kStatus\_Timeout|5|A timeout occurred.|
|kStatus\_NoTransferInProgress|6|The current transfer status is idle.|
|kStatus\_FlashSizeError|100|Not used.|
|kStatus\_FlashAlignmentError|101|Address or length does not meet required alignment.|
|kStatus\_FlashAddressError|102|Address or length is outside addressable memory.|
|kStatus\_FlashAccessError|103|The FTFA\_FSTAT\[ACCERR\] bit is set.|
|kStatus\_FlashProtectionViolation|104|The FTFA\_FSTAT\[FPVIOL\] bit is set.|
|kStatus\_FlashCommandFailure|105|The FTFA\_FSTAT\[MGSTAT0\] bit is set.|
|kStatus\_FlashUnknownProperty|106|Unknown Flash property.|
|kStatus\_FlashEraseKeyError|107|Error in erasing the key.|
|kStatus\_FlashRegionOnExecuteOnly|108|The region is execute only region.|
|kStatus\_FlashAPINotSupported|115|Unsupported Flash API is called.|
|kStatus\_QspiFlashSizeError|400|Error in QuadSPI flash size.|
|kStatus\_QspiFlashAlignmentError|401|Error in QuadSPI flash alignment.|
|kStatus\_QspiFlashAddressError|402|Error in QuadSPI flash address.|
|kStatus\_QspiFlashCommandFailure|403|QuadSPI flash command failure.|
|kStatus\_QspiFlashUnknownProperty|404|Unknown QuadSPI flash property.|
|kStatus\_QspiNotConfigured|405|QuadSPI not configured.|
|kStatus\_QspiCommandNotSupported|406|QuadSPI command not supported.|
|kStatus\_QspiCommandTimeout|407|QuadSPI command timed out.|
|kStatus\_QspiWriteFailure|408|QuadSPI write failure.|
|kStatusQspiModuleBusy|409|QuadSPI module is busy.|
|kStatus\_OtfadSecurityViolation|500|Security violation in OTFAD module.|
|kStatus\_OtfadLogicallyDisabled|501|OTFAD module is logically disabled.|
|kStatus\_OtfadInvalidKey|502|The key is invalid.|
|kStatus\_OtfadInvalidKeyBlob|503|The key blob is invalid.|
|kStatus\_UnknownCommand|10000|The requested command value is undefined.|
|kStatus\_SecurityViolation|10001|Command is disallowed because flash security is enabled.|
|kStatus\_AbortDataPhase|10002|Abort the data phase early.|
|kStatus\_Ping|10003|Internal: Received ping during command phase.|
|kStatus\_NoResponse|10004|There is no response for the command.|
|kStatus\_NoResponseExpected|10005|There is no response expected for the command.|
|kStatusRomLdrSectionOverrun|10100|ROM SB loader section overrun.|
|kStatusRomLdrSignature|10101|ROM SB loader incorrect signature.|
|kStatusRomLdrSectionLength|10102|ROM SB loader incorrect section length.|
|kStatusRomLdrUnencryptedOnly|10103|ROM SB loader does not support plain text image.|
|kStatusRomLdrEOFReached|10104|ROM SB loader EOF reached.|
|kStatusRomLdrChecksum|10105|ROM SB loader checksum error.|
|kStatusRomLdrCrc32Error|10106|ROM SB loader CRC32 error.|
|kStatusRomLdrUnknownCommand|10107|ROM SB loader unknown command.|
|kStatusRomLdrIdNotFound|10108|ROM SB loader ID not found.|
|kStatusRomLdrDataUnderrun|10109|ROM SB loader data underrun.|
|kStatusRomLdrJumpReturned|10110|ROM SB loader return from jump command occurred.|
|kStatusRomLdrCallFailed|10111|ROM SB loader call command failed.|
|kStatusRomLdrKeyNotFound|10112|ROM SB loader key not found.|
|kStatusRomLdrSecureOnly|10113|ROM SB loader security state is secured only.|
|kStatusRomLdrResetReturned|10114|ROM SB loader return from reset occurred.|
|kStatusMemoryRangeInvalid|10200|Memory range conflicts with a protected region.|
|kStatusMemoryReadFailed|10201|Failed to read from memory range.|
|kStatusMemoryWriteFailed|10202|Failed to write to memory range.|
|kStatus\_UnknownProperty|10300|The requested property value is undefined.|
|kStatus\_ReadOnlyProperty|10301|The requested property value cannot be written.|
|kStatus\_InvalidPropertyValue|10302|The specified property value is invalid.|
|kStatus\_AppCrcCheckPassed|10400|CRC check passed.|
|kStatus\_AppCrcCheckFailed|10401|CRC check failed.|
|kStatus\_AppCrcCheckInactive|10402|CRC checker is not enabled.|
|kStatus\_AppCrcCheckInvalid|10403|Invalid CRC checker due to blank part of BCA not present.|
|kStatus\_AppCrcCheckOutOfRange|10404|CRC check is valid but addresses are out of range.|
|kStatus\_NoPingResponse|10500|Packetizer did not receive any response for the ping packet.|
|kStatus\_InvalidPacketType|10501|Packet type is invalid.|
|kStatus\_InvalidCRC|10502|Invalid CRC in the packet.|
|kStatus\_NoCommandResponse|10503|No response received for the command.|
|kStatus\_ReliableUpdateSuccess|10600|Reliable update process completed successfully.|
|kStatus\_ReliableUpdateFail|10601|Reliable update process failed.|
|kStatus\_ReliableUpdateInacive|10602|Reliable update feature is inactive.|
|kStatus\_ReliableUpdateBackupApplicationInvalid|10603|Backup application image is invalid.|
|kStatus\_ReliableUpdateStillInMainApplication|10604|Next boot will still be with Main Application image.|
|kStatus\_ReliableUpdateSwapSystemNotReady|10605|Cannot swap flash by default because swap system is not ready.|
|kStatus\_ReliableUpdateBackupBootloaderNotReady|10606|Cannot swap flash because there is no valid backup bootloader image.|
|kStatus\_ReliableUpdateSwapIndicatorAddressInvalid|10607|Cannot swap flash because provided swap indicator is invalid.|

