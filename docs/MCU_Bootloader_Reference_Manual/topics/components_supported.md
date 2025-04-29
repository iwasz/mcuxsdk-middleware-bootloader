# Components supported

Components for the bootloader firmware:

-   Startup code \(clocking, pinmux, etc.\)
-   Command phase state machine
-   Command handlers
    -   GenericResponse
    -   FlashEraseAll
    -   FlashEraseRegion
    -   ReadMemory
    -   ReadMemoryResponse
    -   WriteMemory
    -   FillMemory
    -   FlashSecurityDisable
    -   GetProperty
    -   GetPropertyResponse
    -   Execute
    -   Call
    -   Reset
    -   SetProperty
    -   FlashEraseAllUnsecure
    -   FlashProgramOnce
    -   FlashReadOnce
    -   FlashReadOnceResponse
    -   FlashReadResource
    -   FlashReadResourceResponse
    -   ConfigureMemory
    -   ReliableUpdate
-   SB file state machine
    -   Encrypted image support \(AES-128\)
-   Packet interface
    -   Framing packetizer
    -   Command/data packet processor
-   Memory interface
    -   Abstract interface
    -   Flash Driver Interface
    -   Low-level flash driver
    -   QuadSPI interface
    -   Low-level QuadSPI driver
    -   On-the-fly QuadSPI decryption engine initialization
-   Peripheral drivers
    -   I2C slave
    -   SPI slave
    -   CAN
        -   Auto-baud detector
    -   UART
        -   Auto-baud detector
    -   USB device
        -   USB controller driver
        -   USB framework
        -   USB HID class
        -   USB Mass storage class
-   CRC check engine
    -   CRC algorithm

**Parent topic:**[Introduction](../topics/introduction_002.md)

