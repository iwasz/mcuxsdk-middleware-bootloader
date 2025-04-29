# Normal mode

There are 6 steps in the BD file to program the bootable image to eMMC for normal boot mode.

1.  The bootable image file path is provided in sources block.
2.  Prepare eMMC option block.
3.  Enable eMMC access using enable command.
4.  Erase eMMC card memory as needed.
5.  Program boot image binary into eMMC.
6.  Program optimal eMMC boot parameters into Fuse \(optional, remove it if it is not required in actual project\).

**Example BD file for eMMC boot image programming for Normal boot mode**

![](../images/figure31.png "Example BD file for eMMC boot image programming for Normal boot mode")

**Parent topic:**[Generate SB file for eMMC image programming](../topics/generate_sb_file_for_emmc_image_programming.md)

