# LPC540xx/LPC54S0xx platform

The NXP LPC540xx/LPC54S0xx platform must be connected to a host computer to load and interface with the flashloader application. On a device with blank external flash, LPC540xx/LPC54S0xx always enumerates on the host device as a USB Device Firmware Upgrade \(DFU\) mode device. This is the default In System Programming \(ISP\) function of the ROM code for the LPC540xx/LPC54S0xx device. This function supports serial interface booting \(UART, I2C, SPI\) from an application processor download. For a non-blank device, see Chapter 4, "LPC540xx Boot ROM for non-secure devices" in [UM11060 LPC540xx/LPC54S0xx User Manual](https://www.nxp.com/docs/en/user-guide/UM11060.pdf) for instructions on how to boot and connect the device with the host in DFU mode.



