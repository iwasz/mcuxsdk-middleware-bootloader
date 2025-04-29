# Create signed Flashloader image

The BD file for signed Flashloader image generation is similar as the one in section Generate signed i.MX bootable image.

The only difference is that the startAddress is 0x20205800 and IVTOffset is 0.

After the BD file is ready, the next step is to generate i.MX boot image using elftosb utility. The example command is as below:

**Example command for Signed Flashloader image generation**

![](../images/figure_27.png "Example command for Signed Flashloader image generation")

After the command “imx-flashloader-signed.bd -o ivt\_flashloader\_signed.bin flashloader.srec” in Figure above, two bootable images are generated:

-   ivt\_flashloader\_signed.bin
-   ivt\_flashloader\_signed\_nopadding.bin

The first one is required by MfgTool for Secure Boot.