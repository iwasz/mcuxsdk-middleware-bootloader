# Features Supported

Here are some of the features supported by the MCU bootloader:

-   Supports UART, I2C, SPI, CAN, and USB peripheral interfaces.
-   Automatic detection of an active peripheral.
-   Ability to disable a peripheral.
-   UART peripheral implements autobaud.
-   Common packet-based protocol for all peripherals.
-   Packet error detection and retransmit.
-   Flash-resident configuration options.
-   Supports flash security including mass erase and unlock security via the backdoor key.
-   Protection of RAM used by the bootloader while it is running.
-   Provides command to read properties of the device such as flash and RAM size.
-   Multiple options for executing the bootloader either at system start-up or under application control at runtime.
-   Supports internal flash, serial QuadSPI, and other external memories.
-   Supports encrypted image download.

**Parent topic:**[Introduction](../topics/introduction_002.md)

