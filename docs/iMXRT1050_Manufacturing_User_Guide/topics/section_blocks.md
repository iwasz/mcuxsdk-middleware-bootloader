# Section blocks

The Section blocks are used to create the sections for an i.MX RT bootable image, for example, all sections for CSF data. For the unsigned image, the Section block is a fixed blank section, as shown below.

```
section (0)
{
}
```

For signed and encrypted image, the following sections are defined for the elftosb utility to generate the CSF descriptor file which is required by CST for CSF data generation.

-   SEC_CSF_HEADER

This section defines the necessary elements required for CSF Header generation as well as default values used for other sections throughout the remaining CSF.

**Elements for CSF Header section generation**
| Element                      | Description                                                                    |
| ---------------------------- | ------------------------------------------------------------------------------ |
| Header_Version               | HAB library version<br>Valid values: 4.0, 4.1, 4.2, 4.3                        |
| Header_HashAlgorithm         | Default Hash Algorithm<br>Valid values: sha1, sha256, sha512                   |
| Header_Engine                | Default Engine<br>Valid values: ANY, DCP, CAAM, SW                             |
| Header_EngineConfiguration   | Default Engine Configuration<br>Recommended value: 0                           |
| Header_CertificateFormat     | Default Certificate Format<br>Valid values: WTLS, X509                         |
| Header_SignatureFormat       | Default signature format Valid values: PKCS, CMS                               |
| Header_SecurityConfiguration | Fused security configuration<br>Valid values: Engineering, Production          |
| Header_UID                   | Generic (matches any value)<br>U0, U1,... Un<br>where each Ui=0..255 and n<255 |
| Header_CustomerCode          | Value expected in “customer code” fuses<br>0..255    

An example section block is shown as follows.

```
section (SEC_CSF_HEADER;
    Header_Version="4.3",
    Header_HashAlgorithm="sha256",
    Header_Engine="DCP",
    Header_EngineConfiguration=0,
    Header_CertificateFormat="x509",
    Header_SignatureFormat="CMS"
    )
{
}
```
-   SEC\_CSF\_INSTALL\_SRK

This section contains the elements to authenticate and install the root public key for use in subsequent sections, as shown in the following table.

**Elements for CSF Install SRK section generation**
| Element                  | Description                                                        |
| ------------------------ | ------------------------------------------------------------------ |
| InstallSRK_Table         | Path pointing to the Super Root Key Table file                     |
| InstallSRK_Source        | SRK index with the SRK table                                       |
| InstallSRK_HashAlgorithm | SRK table hash algorithm.<br>Valid values: SHA1, SHA256 and SHA512 |

An example section block is shown as follows.

```
section (SEC_CSF_INSTALL_SRK;
    InstallSRK_Table="keys/SRK_1_2_3_4_table.bin", // "valid file path"
    InstallSRK_SourceIndex=0
    )
{
}
```

-   SEC\_CSF\_INSTALL\_CSFK

This section consists of the elements used to authenticate and install a public key for use in subsequent sections.

**Elements for CSF Install CSFK section generation**
| Element                       | Description                                         |
| ----------------------------- | --------------------------------------------------- |
| InstallCSFK_File              | File path pointing to CSFK certificate              |
| InstallCSFK_CertificateFormat | CSFK certificate format<br>Valid values: WTLS, X509 |
```
section (SEC_CSF_INSTALL_CSFK;
    InstallCSFK_File="crts/CSF1_1_sha256_2048_65537_v3_usr_crt.pem", // "valid file path"
    InstallCSFK_CertificateFormat="x509" // "x509"
    )
{
}
```

-   SEC\_CSF\_INSTALL\_NOCAK

The Install NOCAK command authenticates and installs a public key for use with the fast authentication mechanism \(HAB 4.1.2 and up\). With this mechanism, one key is used for all signatures.

The following table lists the install NOCAK command arguments.

**Elements for CSF Install NOCAK section generation**
| Element                        | Description                                      |
| ------------------------------ | ------------------------------------------------ |
| InstallNOCAK_File              | File path pointing to CSFK certificate           |
| InstallNOCAK_CertificateFormat | CSFK certificate format Valid values: WTLS, X509 |

An example section block is shown as follows:

```
section (SEC_CSF_INSTALL_NOCAK;
    InstallNOCAK_File= "crts/SRK1_sha256_2048_65537_v3_usr_crt.pem") // "valid file path"
    InstallNOCAK_CertificateFormat= "WTLS" // "WTLS", "X509"
    )
{
}
```

-   SEC\_CSF\_AUTHENTICATE\_CSF

This section is used to authenticate the CSF from which it is executed using the CSFK mentioned in the section above. See the following table for more details.

**Elements for CSF Authenticate CSF section generation**

| Element                             | Description                                                                                                                                                                     |
| ----------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| AuthenticateCSF_Engine              | CSF signature hash engine<br>Valid values: ANY, SAHARA, RTIC, DCP, CAAM and SW                                                                                                  |
| AuthenticateCSF_EngineConfiguration | Configuration flags for the hash engine. <br>Note that the hash is computed over an internal RAM copy of the CSF<br>Valid engine configuration values corresponding to engine name. |
| AuthenticateCSF_SignatureFormat     | CSF signature format<br>Valid values: PKCS1, CMS                    

An example section block is shown as follows:

```
section (SEC_CSF_AUTHENTICATE_CSF)
{
}
```

-   SEC\_CSF\_INSTALL\_KEY

This section consists of elements used to authenticate and install a public key for use in subsequent sections, as shown in the following table.

**Elements for CSF Install Key section generation**
| Element                      | Description                                                                                                                                                                                                                                    |
| ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| InstallKey_File              | File path pointing to a Public key file                                                                                                                                                                                                        |
| InstallKey_VerificationIndex | Verification key index in Key store Valid values: 0, 2, 3, 4                                                                                                                                                                                   |
| InstallKey_TargetIndex       | Target key index in key store Valid values: 2, 3, 4                                                                                                                                                                                            |
| InstallKey_CertificateFormat | Valid values: WTLS, X509                                                                                                                                                                                                                       |
| InstallKey_HashAlgorithm     | Hash algorithm for certificate binding. <br>If present, a hash of the certificate specified in the File argument is included in the command to prevent installation from other sharing the same verification key. <br>Valid values: SHA1, SHA256, SHA512 |

```
section (SEC_CSF_INSTALL_KEY;
    InstallKey_File="crts/IMG1_1_sha256_2048_65537_v3_usr_crt.pem",
    InstallKey_VerificationIndex=0, // Accepts integer or string
    InstallKey_TargetIndex=2) // Accepts integer or string
{
}
```

-   SEC\_CSF\_AUTHENTICATE\_DATA

This section contains elements that are used to verify the authenticity of pre-loaded data in memory.

**Elements for CSF Authenticate Data section generation**
| Element                              | Description                                                                                                                                                                                                                                                                                                              |
| ------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| AuthenticateData_VerificationIndex   | Verification key index in key store                                                                                                                                                                                                                                                                                      |
| AuthenticateData_Engine              | Data signature hash engine<br>Valid values: ANY, DCP, CAAM, SW                                                                                                                                                                                                                                                           |
| AuthenticateData_EngineConfiguration | Configuration flags for the engine                                                                                                                                                                                                                                                                                       |
| AuthenticateData_SignatureFormat     | Data signature format  Valid values: PKCS1, CMS                                                                                                                                                                                                                                                                          |
| AuthenticateData_Binding             | 64-bit unique ID (UID) for binding.<br>If present, authentication succeeds only if the UID fuse value matches this argument, and the TYPE fuse value matches the Security Configuration argument from the Header command<br>Valid values:<br>U0, U1, ... U7<br>with<br>Ui: 0, ..., 255.<br>UID bytes separated by commas |


An example section block is shown as follows:

```
section (SEC_CSF_AUTHENTICATE_DATA;
    AuthenticateData_VerificationIndex=2,
    AuthenticateData_Engine="DCP",
    AuthenticateData_EngineConfiguration=0)
{
}
```

-   SEC\_CSF\_INSTALL\_SECRET\_KEY

This section contains elements used to install the secret key to the MCU secret key store which is used for KeyBlob decryption. This section is required for encrypted image generation and not for signed image.

**Elements for CSF Install Secret Key section generation**
| Element               | Description                                                                     |
| --------------------- | ------------------------------------------------------------------------------- |
| SecretKey_Name        | Specifies the file path used for CST to generate the random decryption key file |
| SecretKey_Length      | Key length in bits<br>Valid values: 128, 192, and 256                           |
| SecretKey_VerifyIndex | Master KEK index Valid values: 0 or 1                                           |
| SecretKey_TargetIndex | Target secret key store index Valid values: 0-3                                 |
| SecretKey_BlobAddress | Internal or external DDR address                                                |


An example section block is shown as follows:

```
section (SEC_CSF_INSTALL_SECRET_KEY;
    SecretKey_Name="dek.bin",
    SecretKey_Length=128,
    SecretKey_VerifyIndex=0,
    SecretKey_TargetIndex=0)
{
}
```

-   SEC\_CSF\_DECRYPT\_DATA

This section is required for encrypted image generation and not for signed image. It contains the necessary elements used to decrypt and authenticate a list of code/data blocks using the secret key stored in the secret key store, as shown in the following table.

**Elements for CSF Decrypt Data section generation**
| Element                     | Description                                                                                                                                                      |
| --------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Decrypt_Engine              | MAC engine<br>Valid value: CAAM, DCP                                                                                                                             |
| Decrypt_EngineConfiguration | Configuration flags for the engine Default value: 0                                                                                                              |
| Decrypt_VerifyIndex         | Secret key index in the Secret key store Valid values: 0-3                                                                                                       |
| Decrypt_MacBytes            | Size of MAC in bytes<br>If engine is CAAM, the valid value is even number between 4-16. The recommended value is 16.<br>If engine is DCP, the valid value is 16. |

An example section block is shown as follows.

```
section (SEC_CSF_DECRYPT_DATA;
    Decrypt_Engine="DCP",
    Decrypt_EngineConfiguration="0", // "valid engine configuration values"
    Decrypt_VerifyIndex=0,
    Decrypt_MacBytes=16)
{
}
```

-   SEC\_NOP

The command in this section has no effect. It also has no arguments.

An example section block is shown as follows.

```
section (SEC_NOP)
    // NOP command has no arguments
{
}
```

-   SEC\_SET\_MID

The Set MID command selects a range of fuse locations to use as a manufacturing identifier \(MID\). MID values are bound with Authenticate Data signatures when verified using keys with the MID binding flag in the Install Key command.

**Elements for CSF Set MID section generation**
| Element     | Description                                                     |
| ----------- | --------------------------------------------------------------- |
| SetMID_Bank | Fuse bank containing MID. Valid values: 0, …, 255               |
| SetMID_Row  | Starting row number of MID within bank. Valid values: 0, …, 255 |
| SetMID_Fuse | Starting fuse of MID within row. Valid values: 0, …, 255        |
| SetMID_Bits | Number of bits for MID. Valid values: 0, …, 255                 |

An example section block is shown as follows:

```
section (SEC_SET_MID;
  SetMID_Bank = 4,
  SetMID_Row = 0,
  SetMID_Fuse = 7,
  SetMID_Bits = 64)
{
}
```

-   SEC\_SET\_ENGINE

The Set Engine command selects the default engine and engine configuration for a given algorithm.

**Elements for CSF Set Engine section generation**
| Element                       | Description                                                                                                  |
| ----------------------------- | ------------------------------------------------------------------------------------------------------------ |
| SetEngine_Engine              | Engine<br>Use ANY to restore the HAB internal criteria.<br>Valid values: ANY, SAHARA, RTIC, DCP, CAAM and SW |
| SetEngine_HashAlgorithm       | Hash algorithm<br>Valid values: SHA1, SHA256 and SHA512                                                      |
| SetEngine_EngineConfiguration | Configuration flags for the engine.<br>Valid engine configuration values corresponding to engine name.       |

An example section block is shown as follows:

```
section (SEC_SET_ENGINE;
  SetEngine_HashAlgorithm = "sha256",
  SetEngine_Engine = "DCP",
  SetEngine_EngineConfiguration = "0")
{
}
```

• SEC\_INIT

The Init command initializes specified engine features when exiting the internal BootROM.

**Elements for CSF Init section generation**
| Element       | Description                                                                                              |
| ------------- | -------------------------------------------------------------------------------------------------------- |
| INIT_Engine   | Engine to initialize Valid value – SRTC                                                                  |
| INIT_Features | Comma-separated list of features to initialize<br>Valid engine feature corresponding to engine argument. |

An example section block is shown as follows:

```
section (SEC_INIT;
  Init_Engine = "SRTC")
  // Init_Features= "MID"
{
}
```

• SEC\_UNLOCK

The Unlock command prevents specified engine features from being locked when exiting the internal BootROM.

**Elements for CSF Unlock section generation**
| Element         | Description                                                                                           |
| --------------- | ----------------------------------------------------------------------------------------------------- |
| Unlock_Engine   | Engine to unlock. Valid values: SRTC, CAAM, SNVS and OCOTP                                            |
| Unlock_features | Comma-separated list of features to unlock.<br>Valid engine feature corresponding to engine argument. |
| Unlock_UID      | Device specific 64-bit UID.<br>U0, U1, …, U7 with Ui=0...255<br>UID bytes separated by commas.        |

An example section block is shown as follows:

```
section (SEC_UNLOCK;
  Unlock_Engine = "OCOTP",
  Unlock_features = "JTAG, SRK REVOKE",
  Unlock_UID = "0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef")
{
}
```

