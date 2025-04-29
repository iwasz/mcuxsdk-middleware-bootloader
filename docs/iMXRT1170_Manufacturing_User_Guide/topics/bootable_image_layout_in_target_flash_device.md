# Bootable image layout in target flash device

There are two types of supported boot image:

-   XIP \(Execute-In-Place\) boot image: This type of boot image is only applicable to Serial NOR devices connected to QuadSPI or FlexSPI interfaces and Parallel NOR devices connected to WEIM or SEMC interface. The boot device memory is identical to the destination memory. ROM can boot this boot image directly.
-   Non-XIP boot image: This type of boot image is usually for the NAND, SD, and eMMC devices. The boot device memory is different from the destination memory. ROM loads the boot image from the boot device memory to the destination memory and then boots from the destination memory.

**Bootable image layout**

![](../images/figure1.png "Bootable image layout")

**Parent topic:**[i.MX RT bootable image](../topics/imx_rt_bootable_image.md)

