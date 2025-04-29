# Generate SB file for fuse programming

In certain cases, the fuse must be programmed first to enable specific features for selected boot devices or security levels. For example, to enable Fast boot mode for eMMC, enable HAB closed mode, the fuse must be programmed first.

The elftosb utility can support programming the fuses using the built-in command *load fuse*. An example to program SRK table and enable HAB closed mode is shown as follows.

```
# The source block assign file name to identifiers
sources {
}
constants {
}
section (0) {
    # Program SRK table
    load fuse 0xD132E7F1 > 0x18;
    load fuse 0x63CD795E > 0x19;
    load fuse 0x8FF38102 > 0x1A;
    load fuse 0x22A78E77 > 0x1B;
    load fuse 0x01019c82 > 0x1C;
    load fuse 0xFC3AC699 > 0x1D;
    load fuse 0xF2C327A3 > 0x1E;
    load fuse 0xDAC9214E > 0x1F;
    # Program SEC_CONFIG to enable HAB closed mode
    load fuse 0x00000002 > 0x06;
}
```

**Parent topic:**[Generate SB file for bootable image programming](../topics/generate_sb_file_for_bootable_image_programming.md)

