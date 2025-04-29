# Introduction

The Kinetis family and i.MX RT series of MCUs are pre-manufactured with the MCU bootloader in either the ROM or flash memory of the device, and can boot into the MCU bootloader application. A PC host or master can connect to the MCU bootloader device via the USB-HID or UART interface, and uses the bootloader’s command protocol interface to program the image onto the MCU device.

The latest version of the Manufacturing tool \(MfgTool\) application supports the MCU bootloader and can be used in factory production environment in the same way as with other MfgTool-supported devices. The MfgTool application can detect the presence of the MCU bootloader connected to the PC and invokes the *blhost.exe* file to program the image onto the target device. This document provides a user’s guide on how to use the MfgTool for the MCU device manufacturing.

