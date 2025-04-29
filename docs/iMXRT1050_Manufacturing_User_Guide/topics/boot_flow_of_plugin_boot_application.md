# Boot Flow of Plugin boot application

The boot flow for Plugin boot application is as follows

1.  Boot ROM loads the XIP plugin boot image, does authentication and execution and then jump to plugin boot application
2.  The plugin boot application loads the signed Non-XIP image from address 0x60008000 and jumps back to Boot ROM
3.  Boot ROM does authentication/decryption based on the parameters output by plugin boot application and jumps to the non-XIP boot image after authenticating successfully


