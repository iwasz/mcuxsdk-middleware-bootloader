# CRC16 algorithm

This section provides the CRC16 algorithm.

The CRC is computed over each byte in the framing packet header, excluding the crc16 field itself, plus all payload bytes. The CRC algorithm is the XMODEM variant of CRC-16.

The characteristics of the XMODEM variant are:

|width|16|
|polynomial|0x1021|
|init value|0x0000|
|reflect in|false|
|reflect out|false|
|xor out|0x0000|
|check result|0x31c3|

The check result is computed by running the ASCII character sequence "123456789" through the algorithm.

```
uint16_t crc16_update(const uint8_t * src, uint32_t lengthInBytes)
{
     uint32_t crc = 0;
     uint32_t j;
     for (j=0; j < lengthInBytes; ++j)
     {
          uint32_t i;
          uint32_t byte = src[j];
          crc ^= byte << 8;
          for (i = 0; i < 8; ++i)
          {
               uint32_t temp = crc << 1;
               if (crc & 0x8000)
               {
                    temp ^= 0x1021;
               }
               crc = temp;
           }
     }
          return crc;
}
```

**Parent topic:**[Bootloader packet types](../topics/bootloader_packet_types.md)

