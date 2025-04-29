# Bootloader entry point

The MCU bootloader provides a function \(runBootloader\) that a user application can call, to run the bootloader.

**Note:** Flashloader does not support this feature.

To get the address of the entry point, the user application reads the word containing the pointer to the bootloader API tree at offset 0x1C of the bootloader's vector table. The vector table is placed at the base of the bootloader's address range.

The bootloader API tree is a structure that contains pointers to other structures, which have the function and data addresses for the bootloader. The bootloader entry point is always the first word of the API tree.

The prototype of the entry point is:

```
void run_bootloader(void * arg);
```

The arg parameter is currently unused, and intended for future expansion. For example, passing options to the bootloader. To ensure future compatibility, a value of NULL should be passed for arg.

Example code to get the entry pointer address from the ROM and start the bootloader:

```
// Variables
uint32_t runBootloaderAddress;
void (*runBootloader)(void * arg);
// Read the function address from the ROM API tree.
runBootloaderAddress = **(uint32_t **)(0x1c00001c);
runBootloader = (void (*)(void * arg))runBootloaderAddress;
// Start the bootloader.
runBootloader(NULL);
```

**Note:** The user application must be executing at Supervisor \(Privileged\) level when calling the bootloader entry point.

**Parent topic:**[Functional description](../topics/functional_description.md)

