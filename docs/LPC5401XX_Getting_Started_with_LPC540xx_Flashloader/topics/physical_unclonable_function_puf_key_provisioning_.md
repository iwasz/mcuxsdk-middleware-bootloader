# Physical Unclonable Function \(PUF\) key provisioning and related commands

This chapter describes usage of blhost for key provisioning using PUF block. In ISP mode, the blhost.exe provides commands to create and save key store.



-   PUF enroll \(generate activation code into key store\)

```
blhost -u 0x1fc9,0x01a2 -- key-provisioning enroll
```



-   set Image Key Code into key store. Image Key type = 1.

```
blhost -u 0x1fc9,0x01a2 -- key-provisioning set_user_key 1 ImageKey.bin[,<size>]
```



-   set UDS Key Code into key store. UDS key type = 2.

```
blhost -u 0x1fc9,0x01a2 -- key-provisioning set_key 2 <size>
```



-   set Firmware Update Key Code into key store. Firmware Update Key type = 3.

```
blhost -u 0x1fc9,0x01a2 -- key-provisioning set_user_key 3 FWUpdateKey.bin[,<size>]
```



-   upload the key store

```
blhost -u 0x1fc9,0x01a2 -- key-provisioning read_key_store key_store.bin
```



The first four commands create key store in RAM of the LPC54S0xx device. The last command will upload it to PC as key\_store.bin file.



Once the key\_store.bin is included in the signed application image, the chip can be put to master boot mode and boot this image.



The PUF Activation Codes and Key Codes are stored in a key store. The layout of key store is available in [UM11060 LPC540xx/LPC54S0xx User's Manual](https://www.nxp.com/docs/en/user-guide/UM11060.pdf), Chapter 4.8, "PUF key store".

