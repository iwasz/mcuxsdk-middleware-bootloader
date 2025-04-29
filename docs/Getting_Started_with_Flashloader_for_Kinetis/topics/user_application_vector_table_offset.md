# User application: Vector table offset

[“ The MCU flashloader application section](flashloader_application.md#) discusses how to program the Kinetis flash memory with the *myApp.bin* user application. When creating the user application, the vector table of the application must be at the beginning address of the flash memory region.

When booting from flash, the Kinetis device considers offset 0, the initial stack pointer and offset 4, the entry point for the application.

