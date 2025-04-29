# Encrypted image

RT1010 supports only the encrypted XIP image format.

The encrypted XIP image is generated using the AES-CTR algorithm. In different scenarios, the image can be generated on-chip or with an external tool. Upon execution, the hardware engine does the decryption on the programmed image.