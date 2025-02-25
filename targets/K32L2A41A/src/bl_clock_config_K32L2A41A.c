/*
 * Copyright (c) 2014-2015 Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "bootloader_common.h"
#include "bl_context.h"
#include "property.h"
#include "fsl_device_registers.h"
#include "fsl_assert.h"
#include "clock_config.h"
extern void BOARD_BootClockRUN_SIRC();
////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

typedef enum _clock_soruce_enum
{
    kClockSource_SystemOSC = 1u,
    kClockSource_SlowIRC = 2u,
    kClockSource_FastIRC = 3u,
    kClockSource_RtcOSC = 4u,
    kClockSource_SystemCFM = 5u,
    kClockSource_SystemPLL = 6u,
    kClockSource_UsbPhyPLL = 7u,
} clock_source_type_t;

enum
{
    kFIRC48M = 48000000ul,
    kFIRC52M = 52000000ul,
    kFIRC56M = 56000000ul,
    kFIRC60M = 60000000ul,
    kIRC8M = 8000000ul,
    kIRC2M = 2000000ul,
    //! The minimum core clock with usb workable is
    kMinCoreClockWithUsbSupport = 20000000u,
};

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
// See bootloader_common.h for documentation on this function.
void configure_clocks(bootloader_clock_option_t option)
{ 
    if (option == kClockOption_EnterBootloader)
    {
        BOARD_InitBootClocks();
    }
    else if (option == kClockOption_ExitBootloader)
    {
        BOARD_BootClockRUN_SIRC();
    }
}

// See bootloader_common.h for documentation on this function.
uint32_t get_bus_clock(void)
{
    CLOCK_SetIpSrc(kCLOCK_Lpi2c1, kCLOCK_IpSrcFircAsync);
    return CLOCK_GetIpFreq(kCLOCK_Lpi2c1);
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
