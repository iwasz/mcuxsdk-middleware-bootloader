# Modifying source files

The files that cover the majority of the customization options needed by applications are located in the device-specific folder. These files allow modification to the basic configuration elements of the bootloader application, and are not associated with the core functionality of the bootloader.

In the device-specific folder, the source files contain this information:

-   **bootloader\_config.h** – Bootloader configuration options such as encryption, timeouts, CRC checking, the UART module number and baud rate, and most importantly, the vector table offset for the user application.
-   **clock\_config\_<device\>.c** – Configures the clock for the device. This includes system, bus, etc.
-   **hardware\_init\_<device\>.c** – Enables and configures peripherals used by the application. This includes pin muxing, peripheral initialization, and the pin used as a bootloader re-entry \(bootstrap\) mechanism.
-   **memory\_map\_<device\>.c** – Contains a table that stores the memory map information for the targeted device.
-   **peripherals\_<device\>.c** – Contains the table used by the bootloader to check which peripheral interfaces are enabled. This is the file used to disable any unused peripheral interfaces.
-   **peripherals\_pinmux.h** - Contains macros to identifiy peripheral pin mux, typically specific to a target platform.

**Parent topic:**[Creating a custom flash-resident bootloader](../topics/creating_a_custom_flash-resident_bootloader.md)

