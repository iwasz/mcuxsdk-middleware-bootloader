# Configuration macros

The configuration macros defined in bootloader\_config.h are used to enable the reliable update feature. For MCU bootloader v2.0.0, the feature is only enabled in the K65 Freedom and Tower flash target builds. All code added for this feature should be enabled only if the macros are defined. Currently, these macros are defined as:

-   BL\_FEATURE\_RELIABLE\_UPDATE – Used to enable or disable the reliable update feature.
-   BL\_FEATURE\_HARDWARE\_SWAP\_UPDATE – Used to switch to the hardware or software implementation of reliable update.
-   BL\_BACKUP\_APP\_START – Used to define the start address of the backup application if the reliable update feature is enabled.

**Parent topic:**[Bootloader Reliable Update](../topics/bootloader_reliable_update.md)

