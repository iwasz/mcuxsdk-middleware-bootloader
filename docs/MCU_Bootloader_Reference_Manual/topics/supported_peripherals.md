# Supported peripherals

The bootloader uses the peripherals\_<device\>.c file to define which peripheral interfaces are active in the bootloader. The source file includes a single table, `g_peripherals[]`, that contains active peripheral information and pointers to configuration structures. This file is found in middleware/mcu-boot/targets/<device\>/src.

Only place configurations for peripherals that are present on the target device. Otherwise, the processor generates fault conditions when trying to initialize a peripheral that is not physically present.

For the content of each entry in the `g_peripherals[]` table, reuse existing entries and only modify the `.instance` member. For example, starting with the following UART0 member, make the change to UART1 by simply changing `.instance` from “0” to “1”.

```
{
      .typeMask = kPeripheralType_UART,
      .instance = 0,
      .pinmuxConfig = uart_pinmux_config,
      .controlInterface = &g_scuartControlInterface;
      .byteInterface = &g_scuartByteInterfacek;
      .packetInterface = &g_framingPacketInterface;
}
```

When the table has all required entries, it must be terminated with a null `{ 0 }` entry.

**Parent topic:**[Bootloader peripherals](../topics/bootloader_peripherals_001.md)

