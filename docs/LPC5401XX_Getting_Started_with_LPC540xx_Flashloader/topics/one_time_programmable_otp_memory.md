# One Time Programmable \(OTP\) memory

The flashloader also provides commands to program and read the on-chip one-time programmable \(OTP\) fuse memory from the LPC540xx/LPC54S0xx device. The efuse-program-once command is used for programming the fuses and efuse-read-once to read the programmed data from the fuse memory. The OTP memory for LPC540xx/LPC54S0xx devices contains four memory banks of 128 bits each. Every 128-bit bank is comprised of four 32-bit words. From Bank 0 Register 0 to Bank 3 Register 3, there are sixteen 32-bit words. A single word can be read or programmed in each call to the bootloader fuse commands. See Chapter 46.12, OTP functional details in [UM11060 LPC540xx/LPC54S0xx User's Manual](https://www.nxp.com/docs/en/user-guide/UM11060.pdf) to see OTP functional details.


```{include} ../topics/efuse-read-once.md
:heading-offset: 1
```

```{include} ../topics/efuse-program-once.md
:heading-offset: 1
```

```{include} ../topics/program-aeskey.md
:heading-offset: 1
```

