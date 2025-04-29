# program-aeskey

The program-aeskey command is used to program a 128-bit AES key into OTP bank2 of LPC54S0xx. The AES key programming is different from the usual OTP programming. AES keys go through a "scrambler" block in hardware and they get programmed into OTP scrambled.

The program-aeskey command requires one argument which is a file containing a 128-bit data. This command can be used as described below:

`blhost -u 0x1fc9,0x01a2 -- program-aeskey aes_key.bin`

The srambled AES key in OTP bank2 can be read using command efuse-read-once command after power cycling the device.



