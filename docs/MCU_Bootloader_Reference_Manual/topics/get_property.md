# Get property

A property has been added to get the state of reliable update. To implement this, a property member called ***reliableUpdateStatus*** has been added to propertyStore. Additionally, eight new status codes have been defined for the reliable update status. See the following table for details.

**Reliable update status error codes**
|Status|Value|Description|
|------|-----|-----------|
|kStatus\_ReliableUpdateSuccess|10600|Reliable update operation succeeded.|
|kStatus\_ReliableUpdateFail|10601|Reliable update operation failed.|
|kStatus\_ReliableUpdateInactive|10602|Reliable update feature is inactive.|
|kStatus\_ReliableUpdateBackupApplicationInvalid|10603|Backup application is invalid.|
|kStatus\_ReliableUpdateStillInMainApplication|10604|\(For hardware implementation only\) The bootloader still jumps to the original main application.|
|kStatus\_ReliableUpdateSwapSystemNotReady|10605|\(For hardware implementation only\) Failed to get the swap indicator address from IFR due to the swap system not being ready.|
|kStatus\_ReliableUpdateBackupBootloaderNotReady|10606|\(For hardware implementation only\) Failed in copying the main application image to the backup application region.|
|kStatus\_ReliableUpdateSwapIndicatorAddressInvalid|10607|\(For hardware implementation only\) Swap indicator address is invalid for the swap system.|

**Parent topic:**[Bootloader Reliable Update](../topics/bootloader_reliable_update.md)

