# QuadSPI Peripheral

The MCU Bootloader supports read, write, and erase external SPI flash devices \(QuadSPI memory\) via the QuadSPI module. It supports booting directly to external SPI flash and XIP in QuadSPI memory. Before accessing external SPI flash devices, the QuadSPI module must be configured properly, using the QSPI configuration block.

## QSPI configuration block

The QSPI config block \(QCB\) provides many configuration parameters, which are intended to support many types of serial flash. All fields in the QSPI config block must be configured according to the specific flash device provided by your specific vendor, and all of them are related to the configuration for registers in the QuadSPI module. Also see the QuadSPI chapter.

**Note:** To correctly configure the QuadSPI, all unused QuadSPI configuration fields should be set to 0.

**Configuration fields in QSPI config block**
| Offset | Size (bytes) | Configuration Field | Description |
| --- | --- | --- | --- |
| 0x00 – 0x03 | 4 | tag | A magic number to verify whether the QSPI config block (QCB) is valid. Must be set to ‘kqcf’<br>[31:24] - ‘f’ (0x66)<br>[23:16] - ‘c’ (0x63)<br>[15: 8] - ‘q’(0x71)<br>[ 7: 0] - ‘k’(0x6B) |
| 0x04 – 0x07 | 4 | version | Version number of the QSPI config block <br>[31:24] - name: must be 'Q' (0x51)<br> [23:16] - major: must be 1<br>[15: 8] - minor: must be 0<br>[ 7: 0] - bugfix: must be 0 |
| 0x08 – 0x0b | 4 | lengthInBytes | Size of QSPI config block, in bytes <br>Must be 512 |
| 0x0c – 0x0f | 4 | dqs_loopback | Enable DQS loopback support<br>0  DQS loopback is disabled<br>1  DQS loopback is enabled, the DQS loopback mode is determined by subsequent ‘dqs_loopback_internal’ field |
| 0x10 – 0x13 | 4 | data_hold_time | Serial flash data hold time. Valid value 0/1/2. See the QuadSPI chapter for details. |
| 0x14 – 0x1b | 8 | - | Reserved |
| 0x1c – 0x1f | 4 | device_mode_config_en | Configure work mode Enable for external SPI flash devices<br>0  Disabled - ROM will not configure work mode of external flash devices.<br>1  Enabled - ROM will configure work mode of external flash devices, based on “device_cmd” and the LUT entry indicated by” write_cmd_ipcr”. |
| 0x20 – 0x23 | 4 | device_cmd | Command to configure the work mode of external flash devices. Effective only if“device_mode_config_en” is set to 1. It also depends on your specific external SPI flash device. |
| 0x24 – 0x27 | 4 | write_cmd_ipcr | IPCR pointed to LUT index for quad mode enablement Value = index << 24 |
| 0x28 – 0x2b | 4 | word_addressable | Word Addressable<br><br>0  Byte-addressable serial flash mode<br><br>1  Word-addressable serial flash mode |
| 0x2c – 0x2f | 4 | cs_hold_time | Serial flash CS hold time, in number of flash clock cycles |
| 0x30 – 0x33 | 4 | cs_setup_time | Serial flash CS setup time, in number of flash clock cycles |
| 0x34 – 0x37 | 4 | sflash_A1_size | Size of external flash connected to ports of QSPI0A and QSPI0A_CS0, in bytes |
| 0x38 – 0x3b | 4 | sflash_A2_size | Size of external flash connected to ports of QSPI0A and quadSPI0A_CS1, in bytes sflash_A2_size field must be set to 0 if the serial flash device is not present. |
| 0x3c – 0x3f | 4 | sflash_B1_size | Size of external flash connected to ports of QSPI0B and quadSPI0B_CS0, in bytessflash_B1_size field must be set to 0 if the serial flash device is not present. |
| 0x40 – 0x43 | 4 | sflash_B2_size | Size of external flash connected to ports of QSPI0B and quadSPI0B_CS1, in bytessflash_B2_size field must be set to 0 if the serial flash device is not present. |
| 0x44 – 0x47 | 4 | sclk_freq | Frequency of QuadSPI serial clock 1<br>0  Low frequency<br>1  Mid frequency<br>2  High frequency<br>See the MCU bootloader chapter in the chip reference manual for the definitions of low-frequency, mid- frequency, and high-frequency. In MK82F256, they are 24 MHz, 48 MHz, and 96 MHz. |
| 0x48 – 0x4b | 4 | busy_bit_offset | Busy bit offset in status register of Serial flash [31:16] Busy bit polarity, valid range is 0-1:<br>0  - Busy flag in status register is 1 when flash devices are busy.<br>1  - Busy flag in status register is 0 when flash devices are busy.[15:0]: The offset of busy flag in status register; valid range is 0 - 31. |
| 0x4c – 0x4f | 4 | sflash_type | Type of serial flash<br>0  Single mode<br>1  Dual mode<br>2  Quad mode<br>3  Octal mode |
| 0x50 – 0x53 | 4 | sflash_port | Port enablement for QuadSPI module<br>0  Only pins for QSPI0A are enabled<br>1  Pins for both QSPI0A and QSPI0B are enabled |
| 0x54 – 0x57 | 4 | ddr_mode_enable | Enable DDR mode<br>0  DDR mode is disabled<br>1  DDR mode is disabled |
| 0x58 – 0x5b | 4 | dqs_enable | Enable DQS<br>0  DQS is disabled<br>1  DQS is enabled |
| 0x5c – 0x5f | 4 | parallel_mode_enable | Enable Parallel Mode<br>0  Parallel mode is disabled<br>1  Parallel mode is enabled<sup>[1]</sup> |
| 0x60 – 0x63 | 4 | portA_cs1 | Enable QuadSPI0A_CS1<br>0  QuadSPI0A_CS1 is disabled<br>1  QuadSPI0A_CS1 is enabledportA_cs1 field must be set to 1 if sflash_A2_size is not equal to 0. |
| 0x64 – 0x67 | 4 | portB_cs1 | Enable QuadSPI0B_CS1<br>0  QuadSPI0B_CS1 is disabled<br>1  QuadSPI0B_CS1 is enabledportB_cs1 field must be set to 1 if sflash_B2_size is not equal to 0. |
| 0x68 – 0x6b | 4 | fsphs | Full Speed Phase selection for SDR instructions<br>0  Select sampling at non-inverted clock<br>1  Select sampling at inverted clock |
| 0x6c – 0x6f | 4 | fsdly | Full Speed Delay selection for SDR instructions<br>0  One clock cycle delay<br>1  Two clock cycles delay. |
| 0x70 – 0x73 | 4 | ddrsmp | DDR sampling point Valid range: 0 - 7 |
| 0x74 – 0x173 | 4 | look_up_table | Look-up-table for sequences of instructions |
| 0x174 – 0x177 | 4 | column_address_space | Column Address SpaceDefines the width of the column address |
| 0x178 – 0x17b | 4 | config_cmd_en | Enable additional configuration command0  Additional configuration command is not needed1  Additional configuration command is needed |
| 0x17c – 0x18b | 16 | config_cmds | IPCR arrays for each connected SPI flashAll fields must be set to 0 if config_cmd_en is not asserted. |
| 0x18c - 0x19b | 16 | config_cmds_args | Command arrays needed to be transferred to external spi flashAll fields must be set to 0 if config_cmd_en is not asserted. |
| 0x19c – 0x19f | 4 | differential_clock_pin_ena ble | Enable differential flash clock pin<br>0  Differential flash clock pin is disabled<br>1  Differential flash clock pin is enabled |
| 0x1a0 – 0x1a3 | 4 | flash_CK2_clock_pin_ena ble | Enable Flash CK2 Clock pin<br>0  Flash CK2 Clock pin is disabled<br>1  Flash CK2 Clock pin is enabled |
| 0x1a4 – 0x1a7 | 4 | dqs_inverse_sel | Select clock source for internal DQS generation<br>0  Use 1x internal reference clock for DQS generation<br>1  Use inverse 1x internal reference clock for DQS generation |
| 0x1a8 – 0x1ab | 4 | dqs_latency_enable | DQS Latency Enable<br>0  DQS latency disabled<br>1  DQS feature with latency included enabled |
| 0x1ac – 0x1af | 4 | dqs_loopback_internal | DQS loopback from internal DQS signal or DQS Pad<br>0  DQS loopback is sent to DQS pad first and then looped back to QuadSPI<br>1  DQS loopback from internal DQS signal directly |
| 0x1b0 – 0x1b3 | 4 | dqs_phase_sel | Select Phase Shift for internal DQS generation<br>0  No Phase shift<br>1  Select 45° phase shift<br>2  Select 90° phase shift<br>3  Select 135° phase shift |
| 0x1b4 – 0x1b7 | 4 | dqs_fa_delay_chain_sel | Delay chain tap number selection for QuadSPI0A DQS Valid range: 0 - 63 |
| 0x1b8 – 0x1bb | 4 | dqs_fb_delay_chain_sel | Delay chain tap number selection for QuadSPI0B DQS Valid range: 0 - 63 |
| 0x1bc – 0x1c3 | 8 | - | Reserved |
| 0x1c4 – 0x1c7 | 4 | page_size | Page size of external SPI flash<sup>[1]</sup>. Page size of all SPI flash devices must be the same |
| 0x1c8 – 0x1cb | 4 | sector_size | Sector size of external SPI flash<sup>[1]</sup>. Sector size of all SPI flash devices must be the same. |
| 0x1cc - 0x1cf | 4 | timeout_milliseconds | Timeout in terms of milliseconds. 0 Timeout check is disabled.NOTEIf the time that the external SPI device is busy is more than this timeout value, then the QuadSPI driver returns a timeout. |
| 0x1d0 – 0x1d3 | 4 | ips_cmd_second_divider | Second divider for IPs command based on QSPI_MCR[SCLKCFG]; the maximum value of QSPI_MCR[SCLKCFG] depends on the specific device. |
| 0x1d4 – 0x1d7 | 4 | need_multi_phase | 0  Only 1 phase is necessary to access external flash devices1  Multiple phases are necessary to erase/program external flash devices |
| 0x1d8 – 0x1db | 4 | is_spansion_hyperflash | <br>0  External flash devices is not in the Cypress HyperFlash family<br>1  External flash devices is in the Cypress HyperFlash family |
| 0x1dc – 0x1df | 4 | pre_read_status_cmd_add ress_offset<sup>[2]</sup> | Additional address for the PreReadStatus command. Set this field to 0xFFFF FFFF if it is not required. |
| 0x1e0 – 0x1e3 | 4 | pre_unlock_cmd_address_offset<sup>[2]</sup> | Additional address for PreWriteEnable command. Set this field to 0xFFFF FFFF if it is not required. |
| 0x1e4 – 0x1e7 | 4 | unlock_cmd_address_offs et<sup>[2]</sup> | Additional address for WriteEnable command. Set this field to 0xFFFF FFFF if it is not required. |
| 0x1e8 – 0x1eb | 4 | pre_program_cmd_addres s_offset<sup>[2]</sup> | Additional address for PrePageProgram command. Set this field to 0xFFFF FFFF if it is not required. |
| 0x1ec – 0x1ef | 4 | pre_erase_cmd_address_ offset<sup>[2]</sup> | Additional address for PreErase command. Set this field to 0xFFFF FFFF if it is not required. |
| 0x1f0 – 0x1f3 | 4 | erase_all_cmd_address_o ffset<sup>[2]</sup> | Additional address for EraseAll command. Set this field to 0xFFFF FFFF if it is not required. |
| 0x1f4 – 0x1ff | 12 | - | Reserved |

<sup>[1]</sup>: If parallel mode is enabled, then page size and sector size must be twice the actual size.

<sup>[2]</sup>: These fields are effective only if “need_multi_phase” field is set to 1.

**Note:** It is recommended to configure QSPI to SDR mode with one QCB during the program and switch to DDR mode with another QCB after the program completes, where it is possible to achieve higher program performance with the MCU bootloader.

## Look-up-table 

The look-up table \(LUT\) is a part of the QCB, and contains sequences for instructions, such as read and write instructions. The MCU bootloader defines LUT entries to support erase, program, and read operations.

**Note:** The sequence in each LUT entry is target-specific. See the datasheet or reference manual of the corresponding serial flash device.

**Look-up table entries for bootloader**
|Index|Field|Description|
|:---:|:----|:----------|
|0|Read|Sequence for read instructions|
|1|WriteEnable|Sequence for WriteEnable instructions|
|2|EraseAll|Sequence for EraseAll instructions|
|3|ReadStatus|Sequence for ReadStatus instructions|
|4|PageProgram|Sequence for Page Program instructions|
|6|PreErase<sup>[3]</sup>|Sequence for Pre-Erase instructions<sup>[3]</sup>|
|7|SectorErase|Sequence for Sector Erase|
|8|Dummy|Sequence for dummy operation if needed.<br> For example, if continuous read is configured in index 0, then the dummy LUT should be configured to force the external SPI flash to exit continuous read mode.<br> If a dummy operation is not required, then this LUT entry must be set to 0.|
|9|PreWriteEnable<sup>[3]</sup>|Sequence for Pre-WriteEnable instructions|
|10|PrePageProgram<sup>[3]</sup>|Sequence for Pre-PageProgram instructions|
|11|PreReadStatus<sup>[3]</sup>|Sequence for Pre-ReadStatus instructions|
|5, 12, 13, 14, 15|Undefined<sup>[3]</sup>|All of these sequences are free to be used for other purpose. For example, index 5 can be used for enabling Quad mode of SPI flash devices, see Section 3.3.2 for more details.|

<sup>[3]</sup>: If these LUT entries are are not required, then they are allowed to be used for other purposes.

**Note:** For most types of SPI flash devices available in the market, only index 0, 1, 3, 4, 7, and 8 are required. However, for other types of high-end SPI flash devices, i.e., Cypress HyperFlash, additional indexes listed above may be required.

## Configure QuadSPI module 

The MCU bootloader is able to access external SPI devices via the QuadSPI module, but only after the QuadSPI module is configured. There are 2 ways to configure the QuadSPI module:

-   Configure QuadSPI module at runtime
-   Configure QuadSPI module at start-up

**Configuring the QuadSPI module**
| Configure QuadSPI at | Procedure | Clock updates during QuadSPI module configuration |
| --- | --- | --- |
| runtime | 1.   Use a WriteMemory command to program the QCB to either a region of RAM or internal flash.<br>2.   Use the ConfigQuadSPI command to configure the QuadSPI module with the QCB that was programmed before.<br>3.   After the above operations, the QuadSPI module has been set to an expected mode specified by the QCB, so the MCU bootloader is now able to access all connected SPI flash devices. | If QuadSPI module is configured at runtime: The System Core clock will not be updated if the QuadSPI module is configured at runtime;only QUADSPI_MCR [SCLKCFG] isupdated according to sclk_freq field within the QCB. In this case, the clock source for QuadSPI module is MCGFLL (QUADSPI0_SOCCR[QSPISRC] equals 1). |
| start-up | The steps of configuring QuadSPI at startup is based on the runtime procedure, if the QCB is not present at address 0 of the 1st external SPI flash device.<br>1.   Configure the QuadSPI module at runtime (procedure above).<br>2.   Erase the 1st sector of the 1st connected external SPI flash device using the FlashEraseRegion command.<br>3.   Program the QCB to address 0 of the 1st connected external SPI flash device using the WriteMemory command.<br>NOTE<br>For some types of SPI flash devices (like Cypress HyperFlash) which do not support basic reads (0x03) with 24-bit addresses, an alternative is available: for this step, program the QCB to internal flash, set the “qspiConfigBlockPointer” in the BCA to the start address of QCB, and program the BCA to 0x3c0.<br>4.   Update BOOTSRC_SEL field (bits [7:6]) in FOPTregister at the address 0x40D to “0b’10”, which means "boot from ROM with QuadSPI configured".<br>5.   Reset the target.<br>6.   After start-up, ROM code reads the QCB from address 0 of the external SPI flash and then configures the QuadSPI according to the QCB.<br>7.   Now, the MCU bootloader is able to access all connected SPI flash devices.<br>The QuadSPI module will be configured automatically out of reset, if the QCB is already present and the BOOTSRC_SEL field (bits [7:6]) in FOPTregister at the address 0x40D equals to “0’b10”. | If QuadSPI module is configured at start-up: The System Core clock will be updated to 72/96 MHz, if the QuadSPI module is configured at start- up. In this case, the clock sourceof the QuadSPI module switches to MCGFLL. The corresponding registers are updated with the values listed in the table Register value updates when the QuadSPI module is configured at start- up.<br>NOTE<br>For K80/1/2, the core clock is updated to 96 MHz. For KL81/2, the core clock is updated to 72 MHz. |

**Note:** The user application boot from QuadSPI in XIP mode should not change the QuadSPI source clock from what ROM has configured \(as shown in the previous table\); otherwise a hard fault may occur. However, the QuadSPI source clocks \(listed in the next table\) can be changed successfully, if the application avoids shutting down the QSPI clock during clock switching; for example, if the clock switch-related codes are relocated in either internal flash or SRAM.

## Access external SPI flash devices using QuadSPI module 

The MCU bootloader supports access to external SPI flash devices using the following commands:

-   **Flash-erase-all:** This command can erase all SPI flash devices defined in the QCB. For example, if “flash-erase-all 1”, the 1 represents the source of the erasure command is QuadSPI memory.
-   **Flash-erase-region:** This command can erase a specified range of flash within connected SPI flash devices. For example “flash-erase-region 0x68000000 0x10000”.
-   **Write-memory:** The MCU bootloader calls the Write-memory command to program specified data to a given region of connected SPI flash devices. For example, “write-memory 0x68001000 led\_demo.bin”.
-   **Read-memory:** The MCU bootloader calls the Read-memory command to read data from a given region of connected SPI flash devices. For example, “read-memory 0x68000000 1024 temp.bin”.

These commands return error codes.

|Error Code|Value|Description|
|:---------|:---:|:----------|
|kStatus\_Success|0|Operation succeeded without error|
|kStatus\_QspiFlashSizeError|400|Size of external SPI flash is invalid|
|kStatus\_QspiFlashAlignmentError|401|Start Address for program is not page-aligned|
|kStatus\_QspiFlashAddressError|402|The address is invalid|
|kStatus\_QspiFlashCommandFailure|403|The operation failed|
|kStatus\_QspiNotConfigured|405|QSPI module is not successfully configured|
|kStatus\_QspiFlashUnkownProperty|404|Unknown QSPI property|
|kStatus\_QspiCommandNotSupported|406|The command is not supported under certain modes|
|kStatus\_QspiCommandTimeout|407|The time that the external SPI device is busy more than the timeout value \(timeout\_milliseconds\).|
|kStatus\_QspiWriteFailure|408|QSPI module cannot perform a program command at the current clock frequency|
|kStatus\_QspiModuleBusy|409|QSPI module is busy, or caused by incorrect configuation of QCB|

## Boot directly from QuadSPI 

The MCU bootloader supports booting directly from QuadSPI. To boot directly from QuadSPI, the following conditions must be met:

-   The bootFlags field in BCA is set to 0xFE, which means "boot directly from QuadSPI".
-   The BOOTSRC\_SEL field \(bits \[7:6\]\) in the FOPT register at address 0x40D is set to “0’b10”, which means "boot from ROM with QuadSPI configured".
-   User application is valid.
-   QuadSPI configuration block \(QCB\) is valid
-   CRC check passed if the CRC check feature is enabled.

## Example QCB 

Here is an example QCB for the MX25U3235F device on TWR-K80F150M, FRDM-K82F, TWR-KL82Z72M, and FRDM-KL82Z. See the *MCU Bootloader QuadSPI User's Guide* \(document MBOOTQSPIUG\) for more details.

```

const qspi_config_t qspi_config_block =
{
     .tag = kQspiConfigTag,                             ⁄⁄ Fixed value, do not change
     .version = {.version = kQspiVersionTag},  ⁄⁄ Fixed value, do not change
     .lengthInBytes = 512,                             ⁄⁄Fixed value, do not change
     .sflash_A1_size = 0x400000,                   ⁄⁄ 4MB
     .sclk_freq = kQspiSerialClockFreq_High,   ⁄⁄ High frequency, in K82-256, it means 96MHz/1 = 96MHz
     .sflash_type = kQspiFlashPad_Quad,        ⁄⁄ SPI Flash devices work under quad-pad mode
     .sflash_port = kQspiPort_EnableBothPorts, ⁄⁄ Both QSPI0A and QSPI0B are enabled.
     .busy_bit_offset = 0,                             ⁄⁄ Busy offset is 0
     .ddr_mode_enable = 0,                         ⁄⁄ disable DDR mode
     .dqs_enable = 0,                                  ⁄⁄ Disable DQS feature
     .parallel_mode_enable = 0,                   ⁄⁄ QuadSPI module work under serial mode
     .pagesize = 256,                                  ⁄⁄ Page Size : 256 bytes
     .sectorsize = 0x1000,                           ⁄⁄ Sector Size: 4KB
     .device_mode_config_en = 1,               ⁄⁄ Enable quad mode for SPI flash
     .device_cmd = 0x40,                           ⁄⁄ Enable quad mode via set bit 6 in status register to 1
     .write_cmd_ipcr = 0x05000000U,         ⁄⁄ IPCR indicating seq id for Quad Mode Enable (5<<24)
     .ips_command_second_divider = 3,      ⁄⁄Set second divider for QSPI serial clock to 3
     .look_up_table =
      {
           ⁄⁄ Seq0 : Quad Read (maximum supported freq: 104MHz)
           ⁄*
           CMD:        0xEB - Quad Read, Single pad
           ADDR:       0x18 - 24bit address, Quad pads
           DUMMY:      0x06 - 6 clock cycles, Quad pads
           READ:       0x80 - Read 128 bytes, Quad pads
           JUMP_ON_CS: 0
           *⁄
           [0] = 0x0A1804EB, [1] = 0x1E800E06, [2] = 0x2400,
           // Seq1: Write Enable (maximum supported freq: 104MHz)
           ⁄*
           CMD:      0x06 - Write Enable, Single pad
           *⁄
           [4] = 0x406,
           ⁄⁄ Seq2: Erase All (maximum supported freq: 104MHz)
           ⁄*
           CMD:    0x60 - Erase All chip, Single pad
           *⁄
           [8] = 0x460,
           ⁄⁄Seq3: Read Status (maximum supported freq: 104MHz)
           ⁄*
          CMD:    0x05 - Read Status, single pad
          READ:   0x01 - Read 1 byte
          *⁄
          [12] = 0x1c010405,
           ⁄⁄ Seq4: 4 I⁄O Page Program (maximum supported freq: 104MHz)
           ⁄*
           CMD:    0x38 - 4 I/O Page Program, Single pad
           ADDR:   0x18 - 24bit address, Quad pad
           WRITE:  0x40 - Write 64 bytes at one pass, Quad pad
           *⁄
           [16] = 0x0A180438, [17] = 0x2240,
           ⁄⁄ Seq5: Write status register to enable quad mode
           ⁄*
           CMD:    0x01 - Write Status Register, single pad
           WRITE:  0x01 - Write 1 byte of data, single pad
           *⁄
           [20] = 0x20010401,
           ⁄⁄ Seq7: Erase Sector
           ⁄*
           CMD:  0x20 - Sector Erase, single pad
           ADDR: 0x18 - 24 bit address, single pad
          *⁄
          [28] = 0x08180420,
          ⁄⁄ Seq8: Dummy
          ⁄*
          CMD:    0 - Dummy command, used to force SPI flash to exit continuous read mode.
          unnecessary here because the continuous read mode is not enabled.
          *⁄
          [32] = 0,
     },
    };
```

**Parent topic:**[Supported peripherals](../topics/supported_peripherals_001.md)

1 If parallel mode is enabled, then page size and sector size must be twice the actual size.<br>2 These fields are effective only if “need\_multi\_phase” field is set to 1.3 If these LUT entries are are not required, then they are allowed to be used for other purposes.

