/*
 * Copyright 2017-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#if !defined(__TARGET_CONFIG_H__)
#define __TARGET_CONFIG_H__

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Constants for clock frequencies.
enum _target_clocks
{
    kFLL_96MHz = 96000000ul,
    kFLL_48MHz = 48000000ul,
    kFLL_HighFreq = 96000000ul,

    kHIRC = 48000000,  //! Frequency of the HIRC.
    kLIRC8M = 8000000, //! 8MHz low frequency IRC.
    kLIRC2M = 2000000, //! 2MHz low frequency IRC.
    //! The core clock cannot go above 72MHz.
    kMaxCoreClock = 72000000u,
    //! The bus clock cannot go above 72MHz.
    kMaxBusClock = 72000000u,
    //! The flash clock cannot go above 24MHz
    kMaxFlashClock = 24000000u,

    kDivider_Min = 1,
    kDivider_Max = 16,
};

//! @brief Constants for sram partition
enum _sram_partition
{
    kSram_LowerPart = 1,
    kSram_UpperPart = 3,
};

//!@brief Unique ID constants
enum _uid_constrants
{
    kUniqueId_SizeInBytes = 8,
};

//! @brief Version constants for the target.
enum _target_version_constants
{
    kTarget_Version_Name = 'T',
    kTarget_Version_Major = 1,
    kTarget_Version_Minor = 0,
    kTarget_Version_Bugfix = 0
};

//! @brief Memory Map index constants
enum
{
    kIndexSRAM = 0,
    kIndexSRAM0 = 1,
    kIndexSRAM1 = 2,
    kIndexSRAM2 = 3,
    kIndexSRAM3 = 4,
    kIndexSpifiNor = 5,
};

enum
{
    kRAMSections = 5,
};

//! CRC check pinmux configurations
// Note: This default muxing slot of selected crc check failure pin must be ALT0
#define CRC_CHECK_FAILURE_PIN_NUMBER 11
#define CRC_CHECK_FAILURE_PIN_PORT PORTA
#define CRC_CHECK_FAILURE_PIN_GPIO GPIOA
#define CRC_CHECK_FAILURE_PIN_DEFAULT_MODE 0
#define CRC_CHECK_FAILURE_PIN_GPIO_MODE 1

#endif // __TARGET_CONFIG_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
