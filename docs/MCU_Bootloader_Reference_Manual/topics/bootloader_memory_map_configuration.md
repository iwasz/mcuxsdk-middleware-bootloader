# Bootloader memory map configuration

The MCU device memory map and flash configuration must be defined for proper operation of the bootloader. The device memory map is defined in the g\_memoryMap\[\] structure of the memory\_map\_<device\>.c file, which can be found in middleware/mcu-boot/targets/<device\>/src. An example memory map configuration is shown.

```
memory_map_entry_t g_memoryMap[] =
{
    {0x00000000,0x000fffff, kMemoryIsExecutable, &g_flashMemoryInterface},   // Flash array (1024KB)
    {0x1fff0000,0x2002ffff, kMemoryIsExecutable, &g_normalMemoryInterface},  // SRAM (256KB)
    {0x40000000,0x4007ffff, kMemoryNotExecutable, &g_deviceMemoryInterface},// AIPS peripherals
    {0x400ff000,0x400fffff, kMemoryNotExecutable, &g_deviceMemoryInterface}, // GPIO
    {0xe0000000,0xe00fffff, kMemoryNotExecutable, &g_deviceMemoryInterface},// M4 private peripherals
    {0}                                                                                                                    // Terminator
};
```

In addition to the device memory map, the correct SRAM initialization file must be selected according to the target device. This file is split based on ARM® Cortex®-M4 and Cortex-M0+ based devices, so the likelihood of having to change it is low.

The sram\_init\_cm4.c file is located in middleware/mcu-boot/src/memory/src for M4 devices and sram\_init\_cm0plus.c for M0+ devices.

**Parent topic:**[Primary porting tasks](../topics/primary_porting_tasks.md)

