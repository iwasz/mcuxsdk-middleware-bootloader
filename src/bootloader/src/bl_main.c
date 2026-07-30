/*
 * Copyright (c) 2013-2015 Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#define exit exit_default
#include "bl_context.h"
#include "bl_peripheral.h"
#include "bl_shutdown_cleanup.h"
#include "board.h"
#include "bootloader.h"
#include "bootloader_common.h"
#include "clock_config.h"
#include "fsl_assert.h"
#include "pin_mux.h"
#include <fsl_debug_console.h>
#include <fsl_iomuxc.h>
#include <stdbool.h>

#if !BL_FEATURE_HAS_NO_INTERNAL_FLASH
#if !BL_DEVICE_IS_LPC_SERIES
#include "fsl_flash.h"
#else
#include "fsl_iap.h"
#endif
#endif // #if !BL_FEATURE_HAS_NO_INTERNAL_FLASH
#include "fsl_rtos_abstraction.h"
#include "microseconds.h"
#include "property.h"
#include "vector_table_info.h"
#if BL_FEATURE_CRC_CHECK
#include "bl_app_crc_check.h"
#endif
#if BL_FEATURE_QSPI_MODULE
#include "qspi.h"
#endif
#include "memory.h"

#if BL_FEATURE_RELIABLE_UPDATE
#include "bl_reliable_update.h"
#endif

//! @addtogroup bl_core
//! @{

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////
// GPIO_AD_07 maps to GPIO1, Pin 7
#define LED_GPIO GPIO1
// #define LED_PIN 21U // GPIO_AD_07 is a pin 21. Nothing is obvious whey you use IMX.
#define LED_PIN 24U // GPIO_AD_10 is a pin 24.

void configure ()
{
        // 1. Enable clock for IOMUXC and GPIO1
        CLOCK_EnableClock (kCLOCK_Iomuxc);
        CLOCK_EnableClock (kCLOCK_Gpio1);

        // // 2. Mux GPIO_AD_07 to ALT5 (which is GPIO1_IO07)
        IOMUXC_SetPinMux (IOMUXC_GPIO_AD_10_GPIOMUX_IO24, 0U);

        // // 3. Configure pad settings for high speed and drive strength
        IOMUXC_SetPinConfig (IOMUXC_GPIO_AD_10_GPIOMUX_IO24,
                             IOMUXC_SW_PAD_CTL_PAD_SRE_MASK |        // Fast slew rate
                                     IOMUXC_SW_PAD_CTL_PAD_DSE (6)); // High drive strength

        // 4. Initialize GPIO pin as output
        gpio_pin_config_t led_config = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};
        GPIO_PinInit (LED_GPIO, LED_PIN, &led_config);

        // 5. Turn the LED on (e.g., Solid Red)
        // Format: Red, Green, Blue (0-255)
        // ws2812_set_color (255, 0, 0);
}

static inline void delay_cycles (uint32_t cycles)
{
        while (cycles--) {
                __NOP ();
        }
}

// Send a single byte using the WS2812 protocol
void ws2812_send_byte (uint8_t data)
{
        for (int i = 7; i >= 0; i--) {
                if (data & (1 << i)) {
                        // Send '1' bit: High for ~0.8us, Low for ~0.45us
                        LED_GPIO->DR_SET = (1U << LED_PIN);
                        delay_cycles (53); // T1H (Tune this)
                        LED_GPIO->DR_CLEAR = (1U << LED_PIN);
                        delay_cycles (27); // T1L (Tune this)
                }
                else {
                        // Send '0' bit: High for ~0.4us, Low for ~0.85us
                        LED_GPIO->DR_SET = (1U << LED_PIN);
                        delay_cycles (25); // T0H (Tune this)
                        LED_GPIO->DR_CLEAR = (1U << LED_PIN);
                        delay_cycles (56); // T0L (Tune this)
                }
        }
}

// Set the color of one WS2812 LED
void setColor (uint8_t r, uint8_t g, uint8_t b)
{
        // Disable interrupts to prevent timing hiccups during data transmission
        __disable_irq ();

        // WS2812 expects data in GRB order
        ws2812_send_byte (g);
        ws2812_send_byte (r);
        ws2812_send_byte (b);

        __enable_irq ();

        // Latch the color by pulling low for > 50 microseconds
        delay_cycles (10000);
}

//! @brief Initialize the bootloader and peripherals.
//!
//! This function initializes hardware and clocks, loads user configuration data, and initialzes
//! a number of drivers. It then enters the active peripheral detection phase by calling
//! get_active_peripheral(). Once the peripheral is detected, the packet and comand interfaces
//! are initialized.
//!
//! Note that this routine may not return if peripheral detection times out and the bootloader
//! jumps directly to the user application in flash.
static void bootloader_init (void)
{
#if 0
    // Init the global irq lock
    lock_init();

    // Init pinmux and other hardware setup.
    init_hardware();

#if !BL_FEATURE_HAS_NO_INTERNAL_FLASH
    // Init flash driver.
    bootloader_flash_init();
#endif // #if !BL_FEATURE_HAS_NO_INTERNAL_FLASH

// Init QSPI module if needed
#if BL_FEATURE_QSPI_MODULE
    configure_quadspi_as_needed();
#endif // BL_FEATURE_QSPI_MODULE

    // Configure clocks.
    configure_clocks(kClockOption_EnterBootloader);
#endif

        // BOARD_ConfigMPU ();
        // BOARD_InitBootPins ();
        BOARD_InitBootClocks ();
        BOARD_InitDebugConsole ();
        NVIC_SetPriorityGrouping (7); // 0 preempt bits, 4 subpriority bits

        // Start the lifetime counter
        microseconds_init ();
        configure ();
        setColor (0, 0, 255);

        volatile int i = 0;
        while (true) {
                ++i;
        }
}

//! @brief Entry point for the bootloader.
int main (void)
{
        bootloader_init ();
        return 0;
}
