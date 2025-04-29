# Generate Plugin boot image

The plugin boot image generation process is similar to the one for normal boot image. The only difference is that the bit 4 in the “flags” element within the “options” block must be set to 1. In other words, the valid flags value list for the plugin boot image is \{0x10, 0x18, 0x1c\}.

An example BD file for plugin boot image generation is shown as follows.

```
options {
    flags = 0x10;
    startAddress = 0x60000000;
    ivtOffset = 0x1000;
    initialLoadSize = 0x2000;
}
sources {
    elfFile = extern(0);
}
section (0)
{
}
```

**Parent topic:**[Generate i.MX RT bootable image](../topics/generate_imx_rt_bootable_image.md)

