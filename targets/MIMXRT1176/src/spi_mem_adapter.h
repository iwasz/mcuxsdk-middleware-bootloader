/*
 * Copyright 2018 - 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __SPI_MEM_ADAPTER_H__
#define __SPI_MEM_ADAPTER_H__

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

//! @brief Serial NOR/EEPROM command codes.
enum _serial_nor_eeprom_command
{
    // Below commands are common for NOR/EEPROM
    kSerialNorEepromCmd_Invalid = 0x00U,
    kSerialNorEepromCmd_WriteStatus = 0x01U, /*!< WRSR: Write Status Register*/
    kSerialNorEepromCmd_WriteMemory =
        0x02U, /*!< WRITE: Write Byte/Page Data to Memory Array with less than 4-byte address*/
    kSerialNorEepromCmd_ReadMemory = 0x03U,   /*!< READ: Read Data from Memory Array with less than 4-byte address*/
    kSerialNorEepromCmd_WriteDisable = 0x04U, /*!< WRDI: Reset Write Enable Latch*/
    kSerialNorEepromCmd_ReadStatus = 0x05U,   /*!< RDSR: Read Status Register*/
    kSerialNorEepromCmd_WriteEnable = 0x06U,  /*!< WREN: Set Write Enable Latch*/

    // Below command is special for AT25M02
    kSerialNorEepromCmd_PageWriteMemory =
        0x07U, /*!< WRITE: Write Page Data to Memory Array with less than 4-byte address*/
    // Below commands are special for NOR FLASH
    kSerialNorEepromCmd_WriteMemoryA32 = 0x12U, /*!< 4PP: Write Byte/Page Data to Memory Array with 4-byte address*/
    kSerialNorEepromCmd_ReadMemoryA32 = 0x13U,  /*!< 4READ: Read Data from Memory Array with 4-byte address*/
    kSerialNorEepromCmd_EraseChipNor = 0x60U,   /*!< CE */
    // Below commands are special for NOR FLASH and 25AA512/1024
    kSerialNorEepromCmd_ErasePage = 0x42U,                          /*!< PE */
    kSerialNorEepromCmd_EraseSector4KB = 0x20U,                     /*!< SE4KB */
    kSerialNorEepromCmd_EraseSector32KB = 0x52U,                    /*!< SE32KB */
    kSerialNorEepromCmd_EraseSector = 0xd8U,                        /*!< SE */
    kSerialNorEepromCmd_ErasePageA32 = kSerialNorEepromCmd_Invalid, /*!< 4PE */
    kSerialNorEepromCmd_EraseSector4KBA32 = 0x21U,                  /*!< 4SE4KB */
    kSerialNorEepromCmd_EraseSectorA32 = 0xdcU,                     /*!< 4SE */
    kSerialNorEepromCmd_EraseChip = 0xc7U,                          /*!< CE */

    kSerialNorCmd_SE4K_3B = 0x20,
    kSerialNorCmd_SE4K_4B = 0x21,
    kSerialNorCmd_SE64K_3B = 0xD8,
    kSerialNorCmd_SE64K_4B = 0xDC,
    kSerialNorCmd_ReadSFDP = 0x5A,
    kSerialNorCmd_ReadManufacturerId = 0x9F,
};

//!@brief SPI Master Configuration for Adapter
typedef struct
{
    uint32_t whichPcs;  //!< PCS index
    uint32_t clockFreq; //!< Clock requency for SPI
    uint32_t baudRate;  //!< Baudrate for SPI
} spi_master_basic_cfg_t;

//!@brief SPI Memory transfer mode defintions
typedef enum _spi_mem_xfer_mode
{
    kSpiMem_Xfer_CommandOnly,      //!< Command Only
    kSpiMem_Xfer_CommandWriteData, //!< Command then Write Data
    kSpiMem_Xfer_CommandReadData,  //!< Comamdn then Read Data
} spi_mem_xfer_mode_t;

//!@brief SPI Memory Transfer Context
typedef struct __spi_mem_xfer
{
    uint8_t *cmd;             //!< Command buffer
    uint8_t *data;            //!< Data Buffer
    size_t cmdSize;           //!< Command buffer size
    size_t dataSize;          //!< Data buffer size
    spi_mem_xfer_mode_t mode; //!< Transfer mode
} spi_mem_xfer_t;

//!@brief Flash ID definition
typedef struct _flash_id
{
    uint8_t mid;    //!< Manufacturer Identifier
    uint8_t did[2]; //!< Device Identifier
    uint8_t reserved[17];
} flash_id_t;

//!@brief Memory type
enum
{
    kSpiMemoryType_Nor_Manual,
    kSpiMemoryType_EEPROM_Manual,
    kSpiMemoryType_Nor_Auto,
};

enum
{
    kSpiMem_ConfigOption_Tag = 0x0cu,
    kSpiMem_ConfigBlock_Tag = 0xcfu
};

//! @brief Spi NOR/EEPROM module properties
typedef enum _spi_nor_eeprom_property
{
    kSpiNorEepromProperty_InitStatus = 0,
    kSpiNorEepromProperty_StartAddress = 1,           //!< Tag used to retrieve start address
    kSpiNorEepromProperty_TotalFlashSizeInKBytes = 2, //!< Tag used to retrieve total flash size in terms of KByte
    kSpiNorEepromProperty_PageSize = 3,               //!< Tag used to retreive page size in terms of byte
    kSpiNorEepromProperty_SectorSize = 4,             //!< Tag used to retrieve sector size in term of byte
    kSpiNorEepromProperty_BlockSize = 5,              //!< Tag used to retrieve block size in terms of byte

    kSpiNorEepromProperty_TotalFlashSize = 0x10, //!< Tag used to retrieve total flash size in terms of byte
} spi_nor_eeprom_property_t;

//! @brief Spi NOR/EEPROM configuration option
typedef struct _spi_mem_config_option
{
    union {
        struct
        {
            uint32_t page_size : 4;   //!< Nor/Eeprom page size
            uint32_t sector_size : 4; //!< Nor/Eeprom sector size
            uint32_t memory_size : 4; //!< Nor/Eeprom memory size
            uint32_t memory_type : 4; //!< Determines the connected memory type
            uint32_t pcs_index : 4;   //!< PCS instance of SPI module
            uint32_t spi_index : 4;   //!< Index of SPI module
            uint32_t option_size : 4; //!< Option size, in terms of uint32_t, size = (option_size + 1) * 4
            uint32_t tag : 4;         //!< Tag, must be 0x0c
        } B;
        uint32_t U;
    } option0;

    union {
        struct
        {
            uint32_t spi_speed : 4; //!< SPI transfer speed to connected NOR/EEPROM
            uint32_t reserved : 28; //!< Reserved for future use
        } B;
        uint32_t U;
    } option1;

} spi_mem_config_option_t;

typedef struct
{
    uint8_t tag;
    uint8_t memoryType;
    uint8_t blockEraseAvailable;
    uint8_t sfdpTableAvailable;
    uint8_t sectorEraseCmd;
    uint8_t blockEraseCmd;
    uint8_t chipEraseCmd;
    uint8_t addressBits;
    uint32_t pageSizeInBytes;
    uint32_t sectorSizeInBytes;
    uint32_t blockSizeInBytes;
    uint32_t memorySizeInBytes;

} spi_mem_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C"
{
#endif /* __cplusplus */

    //!@brief Initialize SPI Memory
    status_t spi_mem_init(uint32_t instance);

    //!@brief Configure SPI Memory interface with specified config block
    status_t spi_mem_config(uint32_t instance, void *config);

    //!@brief Issue SPI Memory Transfer
    status_t spi_mem_xfer(uint32_t instance, spi_mem_xfer_t *xfer);

    //!@brief Read SPI Memory ID
    status_t spi_mem_read_id(uint32_t instance, flash_id_t *flashId);

    //!@brief Read Data from SPI Memory
    status_t spi_mem_read(uint32_t instance, uint32_t addr, uint8_t *buffer, uint32_t lengthInBytes);

    //!@brief Erase data from SPI memory
    status_t spi_mem_erase(uint32_t instance, uint32_t addr, uint32_t length);

    //!@brief Erase the whole FLASH
    status_t spi_mem_erase_all(uint32_t instance);

    //!@brief Program data to FLASH
    status_t spi_mem_write(uint32_t instance, uint32_t addr, uint8_t *buffer, uint32_t lengthInBytes);

    //!@brief Get the SPI Memory property
    status_t spi_mem_get_property(uint32_t whichProperty, uint32_t *value);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif // SPI_ADAPTER_H__
