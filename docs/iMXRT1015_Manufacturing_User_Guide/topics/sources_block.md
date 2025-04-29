# Sources block

Typically, all the application image paths are provided in this section. Currently, the ELF file and SREC file are supported for i.MX RT Bootable image generation, for example:

```
sources {
    elfFile = extern(0);
}
```