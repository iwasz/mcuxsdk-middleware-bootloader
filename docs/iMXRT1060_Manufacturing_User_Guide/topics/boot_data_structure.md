# Boot data structure

**Boot data structure**

| Offset | Field | Description |
| --- | --- | --- |
| 0x00-0x03 | start | Absolute address of the bootable image |
| 0x04-0x07 | length | Size of the bootable image |
| 0x08-0x0b | plugin | Plugin flag, set to 0 because plugin boot is not supported on the RT1010 |