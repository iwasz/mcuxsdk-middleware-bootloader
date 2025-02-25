/*
 * Copyright (c) 2013 Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "bootloader_common.h"
#include "bl_context.h"
#include "fsl_device_registers.h"
#include "fsl_intmux.h"
#include "smc.h"
#include "fsl_lpuart.h"
#include "fsl_assert.h"
#include "fsl_wdog32.h"
#if BL_ENABLE_CRC_CHECK
#include "bl_app_crc_check.h"
#endif
////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

enum
{
    //! @brief Mask for the bit of RCM_MR[BOOTROM] indicating that the BOOTCFG0 pin was asserted.
    kBootedViaPinMask = 1
};

enum _peripheral_clock_source
{
    kPeripheralClockSource_CLKOFF = 0,
    kPeripheralClockSource_OSCCLK = 1,
    kPeripheralClockSource_SCGIRCLK = 2,
    kPeripheralClockSource_SCGFIRCLK = 3,
    kPeripheralClockSource_SCGPCLK = 6
};

static INTMUX_Type *const s_intmuxBase[] = INTMUX_BASE_PTRS;

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////
//! return the frequency of HIRC
//extern uint32_t get_firc_clock(void);
//! return the frequency of SIRC
//extern uint32_t get_sirc_clock(void);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void init_hardware(void)
{
#if defined(BL_TARGET_ROM)
    // If we are in VLPR mode, exit it
    //! @todo If exiting from VLPR mode, we need to raise/restore clocks afterwards.
    exit_vlpr();
#endif

    // Enable clocks to ports.
    PCC0->CLKCFG[PCC_PORTA_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_CGC_MASK;
    PCC0->CLKCFG[PCC_PORTB_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_CGC_MASK;
    PCC0->CLKCFG[PCC_PORTC_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_CGC_MASK;
    PCC0->CLKCFG[PCC_PORTD_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_CGC_MASK;
    PCC0->CLKCFG[PCC_PORTE_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_CGC_MASK;

    // Configure Divider for SLOW_SRC_CLK
    uint32_t tmp = SCG->SIRCDIV;
    tmp &= SCG_SIRCDIV_SIRCDIV3_MASK;
    tmp |= SCG_SIRCDIV_SIRCDIV3(1);
    SCG->SIRCDIV = tmp;

    // Select the  SCGIRCLK as LPUARTx clock source.
    PCC0->CLKCFG[PCC_LPUART2_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);
    PCC0->CLKCFG[PCC_LPUART1_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);
    PCC1->CLKCFG[PCC_LPUART0_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);

    //  Select the  SCGIRCLK as LPSPIx/I2Cx clock source.
    PCC0->CLKCFG[PCC_LPSPI2_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);
    PCC0->CLKCFG[PCC_LPSPI1_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);
    PCC1->CLKCFG[PCC_LPSPI0_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);

    PCC0->CLKCFG[PCC_LPI2C2_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);
    PCC0->CLKCFG[PCC_LPI2C1_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);
    PCC1->CLKCFG[PCC_LPI2C0_INDEX & PCC_PERIPHERAL_MASK] |= PCC_CLKCFG_PCS(kPeripheralClockSource_SCGIRCLK);

//    SystemCoreClock = get_system_core_clock();

    // Enable clock to INTMUX0 and reset all channels
    INTMUX_Init((INTMUX_Type *)s_intmuxBase[0]);
    
    // Load the user configuration data so that we can configure the clocks
    g_bootloaderContext.propertyInterface->load_user_config();
}

void deinit_hardware(void)
{
#if BL_ENABLE_CRC_CHECK && BL_FEATURE_CRC_ASSERT
    restore_crc_check_failure_pin();
#endif

    PCC0->CLKCFG[PCC_PORTA_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_CGC_MASK;
    PCC0->CLKCFG[PCC_PORTB_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_CGC_MASK;
    PCC0->CLKCFG[PCC_PORTC_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_CGC_MASK;
    PCC0->CLKCFG[PCC_PORTD_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_CGC_MASK;
    PCC0->CLKCFG[PCC_PORTE_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_CGC_MASK;

    // Restore SIM/PCC related bits being changed
    SIM->SOPT1 &= (uint32_t)~SIM_SOPT1_USBREGEN_MASK;

    // Disable peripheral clock
    PCC0->CLKCFG[PCC_LPUART2_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;
    PCC0->CLKCFG[PCC_LPUART1_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;
    PCC1->CLKCFG[PCC_LPUART0_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;

    PCC0->CLKCFG[PCC_LPSPI2_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;
    PCC0->CLKCFG[PCC_LPSPI1_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;
    PCC1->CLKCFG[PCC_LPSPI0_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;

    PCC0->CLKCFG[PCC_LPI2C2_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;
    PCC0->CLKCFG[PCC_LPI2C1_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;
    PCC1->CLKCFG[PCC_LPI2C0_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;

    PCC0->CLKCFG[PCC_USB0FS_INDEX & PCC_PERIPHERAL_MASK] &= (uint32_t)~PCC_CLKCFG_PCS_MASK;

    INTMUX_Deinit((INTMUX_Type *)s_intmuxBase[0]);

    // Restore SCG_SIRCDIV_SIRCDIV3 to default value.
    SCG->SIRCDIV &= (uint32_t)~SCG_SIRCDIV_SIRCDIV3_MASK;

    WDOG32_Deinit(WDOG0);
}

bool usb_clock_init(void)
{
    SystemCoreClockUpdate();
    CLOCK_EnableUsbfs0Clock(kCLOCK_IpSrcFircAsync, CLOCK_GetFreq(kCLOCK_ScgFircAsyncDiv1Clk));

    return true;
}

uint32_t get_uart_clock(uint32_t instance)
{
    CLOCK_SetIpSrc(kCLOCK_Lpuart0, kCLOCK_IpSrcSircAsync);
    return CLOCK_GetFreq(kCLOCK_ScgSircAsyncDiv3Clk);
}

bool is_boot_pin_asserted(void)
{
    return false;
}

#if DEBUG && __ICCARM__

// Included only to satisfy linker.
size_t __write(int handle, const unsigned char *buf, size_t size)
{
    return size;
}

#endif // DEBUG && __ICCARM__

void debug_init(void)
{
}

void update_available_peripherals()
{
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
