# Terminology

The below table summarizes the terms and abbreviations included in this document.

**Terminology and Abbreviations**

| Terminology | Description |
| --- | --- |
| MCUBOOT | MCU Bootloader |
| KeyBlob | KeyBlob is a data structure that wraps the DEK for image decryption using the AES-CCM algorithm |
| DEK | “Key” used to decrypt the encrypted bootable image |
| SB file | The SB file is the NXP binary file format for bootable images. <p>The file consists of sections, sequence of bootloader commands, and data that assists MCU Bootloader in programming the image to target memory. <p>The image data can also be encrypted in the SB file.<p>The file can be downloaded to the target using the MCU Bootloader receive-sb-file command. |
| CST | Code Signing Tool |
| XIP | Execute-In-Place |