# Constants block

The Constants block provides a constant variable that is used to generate CSF data for image authentication and decryption. The Constants block is optional for an unsigned image. The supported constants are listed below.

```
Constants {
    SEC_CSF_HEADER = 20;
    SEC_CSF_INSTALL_SRK = 21;
    SEC_CSF_INSTALL_CSFK = 22;
    SEC_CSF_INSTALL_NOCAK = 23;
    SEC_CSF_AUTHENTICATE_CSF = 24;
    SEC_CSF_INSTALL_KEY = 25;
    SEC_CSF_ AUTHENTICATE_DATA = 26;
    SEC_CSF_INSTALL_SECRET_KEY = 27;
    SEC_CSF_DECRYPT_DATA = 28;
    SEC_NOP = 29;
    SEC_SET_MID = 30;
    SEC_SET_ENGINE = 31;
    SEC_INIT = 32;
    SEC_UNLOCK = 33;
}
```

