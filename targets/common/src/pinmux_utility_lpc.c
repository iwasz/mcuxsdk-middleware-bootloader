/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc.
 * Copyright 2018-2020, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////
#include "bootloader_common.h"
#include "bl_context.h"
#include "fsl_device_registers.h"
#include "fsl_iocon.h"
#include "fsl_gpio.h"
#include "fsl_gint.h"
#include "fsl_inputmux.h"
#include "fsl_pint.h"
#include "peripherals_pinmux.h"
#include "pin_mux.h"

#if (BL_CONFIG_FLEXCOMM_USART)

#if BL_ENABLE_PINMUX_UART0
#define BL_ENABLED_MAX_UART_INSTANCE (0)
#endif

//! UART autobaud port irq configurations
#define GPIO_IRQC_INTERRUPT_ENABLED_PRIORITY 1
#define GPIO_IRQC_INTERRUPT_RESTORED_PRIORITY 0

//! this is to store the function pointer for calling back to the function that wants
//! the UART RX instance pin that triggered the interrupt. This only supports 1 pin
//! for UART0 because UART1 is on PORTC which does not support interrupts :(

static pin_irq_callback_t s_pin_irq_func[BL_ENABLED_MAX_UART_INSTANCE + 1] = { 0 };

#endif // BL_CONFIG_FLEXCOMM_USART

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Configure pinmux for uart module.
 *
 * This function only support switching default or gpio or fixed-ALTx mode on fixed pins
 * (Although there are many ALTx-pinmux configuration choices on various pins for the same
 * peripheral module)
 */
void uart_pinmux_config(uint32_t instance, pinmux_type_t pinmux)
{
    switch (instance)
    {
#if BL_ENABLE_PINMUX_UART0
        case 0:
            switch (pinmux)
            {
                case kPinmuxType_Default:
                    UART0_RestoreDefault();
                    break;
                case kPinmuxType_PollForActivity:
                    UART0_PollForActivity();
                    break;
                case kPinmuxType_Peripheral:
                    UART0_InitPins();
                    break;
                default:
                    break;
            }
            break;
#endif // #if BL_ENABLE_PINMUX_UART0

        default:
            break;
    }
}

/*!
 * @brief Configure pinmux for i2c module.
 *
 * This function only support switching default or gpio or fixed-ALTx mode on fixed pins
 * (Although there are many ALTx-pinmux configuration choices on various pins for the same
 * peripheral module)
 */
void i2c_pinmux_config(uint32_t instance, pinmux_type_t pinmux)
{
    switch (instance)
    {
#if BL_ENABLE_PINMUX_I2C2
        case 2:
            switch (pinmux)
            {
                case kPinmuxType_Default:
                    I2C2_RestoreDefault();
                    break;
                case kPinmuxType_Peripheral:
                    I2C2_InitPins();
                    break;
                default:
                    break;
            }
            break;
#endif // #if BL_ENABLE_PINMUX_I2C2

        default:
            break;
    }
}

/*!
 * @brief Configure pinmux for SPI module.
 *
 * This function only support switching default or gpio or fixed-ALTx mode on fixed pins
 * (Although there are many ALTx-pinmux configuration choices on various pins for the same
 * peripheral module)
 */
void spi_pinmux_config(uint32_t instance, pinmux_type_t pinmux)
{
    switch (instance)
    {
#if BL_ENABLE_PINMUX_SPI3
        case 3:
            switch (pinmux)
            {
                case kPinmuxType_Default:
                    SPI3_RestoreDefault();
                    break;
                case kPinmuxType_Peripheral:
                    SPI3_InitPins();
                    break;
                default:
                    break;
            }
            break;
#endif // #if BL_ENABLE_PINMUX_SPI3

#if BL_ENABLE_PINMUX_SPI9
        case 9:
            switch (pinmux)
            {
                case kPinmuxType_Default:
                    SPI9_RestoreDefault();
                    break;
                case kPinmuxType_Peripheral:
                    SPI9_InitPins();
                    break;
                default:
                    break;
            }
            break;
#endif // #if BL_ENABLE_PINMUX_SPI9

        default:
            break;
    }
}

//! @brief this is going to be used for autobaud IRQ handling for UART0
#if BL_ENABLE_PINMUX_UART0
void UART0_RX_GPIO_IRQHandler(void)
{
    // Clear interrupt before callback
#if UART0_ENABLE_GINT
    UART0_RX_GINT_BASE->CTRL |= GINT_CTRL_INT_MASK;
#elif UART0_ENABLE_PINT
    UART0_RX_PINT_BASE->FALL |= PINT_FALL_FDET_MASK;
#endif

    // Check if the pin for UART0 is what triggered the RX PORT interrupt
    if (s_pin_irq_func[0])
    {
        s_pin_irq_func[0](0);
    }
}
#endif // #if BL_ENABLE_PINMUX_UART0

void enable_autobaud_pin_irq(uint32_t instance, pin_irq_callback_t func)
{
    switch (instance)
    {
#if BL_ENABLE_PINMUX_UART0
        case 0:
            NVIC_SetPriority(UART0_RX_GPIO_IRQn, GPIO_IRQC_INTERRUPT_ENABLED_PRIORITY);
            NVIC_EnableIRQ(UART0_RX_GPIO_IRQn);
#if UART0_ENABLE_GINT
            // Only look for a falling edge for our interrupts
            // Initialize GINT
            GINT_Init(UART0_RX_GINT_BASE);
            // Setup GINT for edge trigger, "OR" mode
            GINT_SetCtrl(UART0_RX_GINT_BASE, kGINT_CombineOr, kGINT_TrigEdge, NULL);
            // Select pins & polarity for GINT
            GINT_ConfigPins(UART0_RX_GINT_BASE, UART0_RX_GINT_GROUP, ~(1U << UART0_RX_GPIO_PIN_NUM), (1U << UART0_RX_GPIO_PIN_NUM));
#elif UART0_ENABLE_PINT
            // Connect trigger sources to PINT
            INPUTMUX_Init(INPUTMUX);
            INPUTMUX_AttachSignal(INPUTMUX, UART0_RX_PINT_INT_TYPE, UART0_RX_PINT_INT_SRC);
            // Turnoff clock to inputmux to save power. Clock is only needed to make changes
            INPUTMUX_Deinit(INPUTMUX);
            // Initialize PINT
            PINT_Init(UART0_RX_PINT_BASE);
#if defined(PINT_USE_SIMPLE_CALLBACK) && PINT_USE_SIMPLE_CALLBACK
            // Setup Pin Interrupt x for falling edge
            PINT_PinInterruptConfig(UART0_RX_PINT_BASE, UART0_RX_PINT_INT_TYPE, kPINT_PinIntEnableFallEdge);
#else
            // Setup Pin Interrupt x for falling edge
            PINT_PinInterruptConfig(UART0_RX_PINT_BASE, UART0_RX_PINT_INT_TYPE, kPINT_PinIntEnableFallEdge, NULL);
#endif
#endif
            s_pin_irq_func[0] = func;
            break;
#endif // #if BL_ENABLE_PINMUX_UART0

        default:
            break;
    }
}

void disable_autobaud_pin_irq(uint32_t instance)
{
    switch (instance)
    {
#if BL_ENABLE_PINMUX_UART0
        case 0:
            NVIC_DisableIRQ(UART0_RX_GPIO_IRQn);
            NVIC_SetPriority(UART0_RX_GPIO_IRQn, GPIO_IRQC_INTERRUPT_RESTORED_PRIORITY);
#if UART0_ENABLE_GINT
            // De-initialize GINT
            GINT_Deinit(UART0_RX_GINT_BASE);
#elif UART0_ENABLE_PINT
            // De-initialize PINT
            PINT_Deinit(UART0_RX_PINT_BASE);
#endif
            s_pin_irq_func[0] = 0;
            break;
#endif // #if BL_ENABLE_PINMUX_UART0

        default:
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
