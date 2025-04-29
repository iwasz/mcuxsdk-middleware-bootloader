# USB peripheral

The MCU bootloader supports loading data into flash or RAM using the USB peripheral. The target is implemented as USB-HID and USB MSC \(Mass Storage Class\) composite device classes.

When transfer data through USB-HID device class, USB-HID does not use framing packets. Instead, the packetization, inherent in the USB protocol itself, is used. The ability for the device to NAK Out transfers \(until they can be received\) provides the required flow control. The built-in CRC of each USB packet provides the required error detection.

When transfer data through USB MSC device class, USB MSC does not use framing packets. Instead, the packetization, inherent in the USB protocol itself, is used. As with any mass storage class device, a device drive letter appears in the file manager of the operating system, and the file image can be dragged and dropped to the storage device. Right now, the USB MSC download only supports SB file drag-and-drop. Reading the SB file from the MSC device is not supported.

The USB peripheral can work as HID + MSC in Composite device mode. For HID-only mode or MSC-only mode, this is configured using macros during compile time. If configured as the HID and MSC composite device, users can either send commands to the HID interface, or drag/drop SB files to the MSC device.

**Parent topic:**[Supported peripherals](../topics/supported_peripherals_001.md)

