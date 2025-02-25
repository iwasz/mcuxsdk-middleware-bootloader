/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"
#include "event.h"
#include "fsl_host.h"
#include "fsl_port.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief host controller error recovery.
 * @param host base address.
 */
static void Host_ErrorRecovery(HOST_TYPE *hostBase);
/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint32_t g_sdhcAdmaTable[SDHC_ADMA_TABLE_WORDS];
/*! @brief Card detect flag. */
static volatile uint32_t g_sdInsertedFlag;
extern volatile uint32_t g_timeMilliseconds;
/*******************************************************************************
 * Code
 ******************************************************************************/

/* Delay some time united in milliseconds. */
static void Delay(uint32_t milliseconds)
{
    uint32_t startTime = g_timeMilliseconds;
    uint32_t periodTime = 0;
    while (periodTime < milliseconds)
    {
        periodTime = g_timeMilliseconds - startTime;
    }
}

static void DetectCardByGpio(void)
{
    if (GPIO_ReadPinInput(BOARD_SDHC_CD_GPIO_BASE, BOARD_SDHC_CD_GPIO_PIN))
#if defined BOARD_SDHC_CD_LOGIC_RISING
    {
        g_sdInsertedFlag = 1U;
    }
    else
    {
        g_sdInsertedFlag = 0U;
    }
#else
    {
        g_sdInsertedFlag = 0U;
    }
    else
    {
        g_sdInsertedFlag = 1U;
    }
#endif
}

/* Card detect. */
status_t CardInsertDetect(HOST_TYPE *hostBase)
{
    EVENT_InitTimer();

    if (!EVENT_Create(kEVENT_CardDetect))
    {
        return kStatus_Fail;
    }

    /* Card detection pin will generate interrupt on either eage */
    PORT_SetPinInterruptConfig(BOARD_SDHC_CD_PORT_BASE, BOARD_SDHC_CD_GPIO_PIN, kPORT_InterruptEitherEdge);
    /* Open card detection pin NVIC. */
    NVIC_EnableIRQ(BOARD_SDHC_CD_PORT_IRQ);

    DetectCardByGpio();

    if (!g_sdInsertedFlag)
    {
        /* Wait card inserted. */
        do
        {
            if (!EVENT_Wait(kEVENT_CardDetect, EVENT_TIMEOUT_CARD_DETECT))
            {
                return kStatus_Fail;
            }
        } while (!g_sdInsertedFlag);
    }

    EVENT_Delete(kEVENT_CardDetect);

    /* Delat some time to make card stable. */
    Delay(1000U);

    return kStatus_Success;
}

/* Card detect pin port interrupt handler. */
void HOST_CARD_DETECT_INTERRUPT_HANDLER(void)
{
    if (PORT_GetPinsInterruptFlags(BOARD_SDHC_CD_PORT_BASE) == (1U << BOARD_SDHC_CD_GPIO_PIN))
    {
        DetectCardByGpio();
    }
    /* Clear interrupt flag.*/
    PORT_ClearPinsInterruptFlags(BOARD_SDHC_CD_PORT_BASE, ~0U);
    EVENT_Notify(kEVENT_CardDetect);
}

/* User defined transfer function. */
static status_t SDHC_TransferFunction(SDHC_Type *base, sdhc_transfer_t *content)
{
    status_t error = kStatus_Success;

    if (kStatus_Success != SDHC_TransferBlocking(base, g_sdhcAdmaTable, SDHC_ADMA_TABLE_WORDS, content))
    {
        error = kStatus_Fail;
        /* host error recovery */
        Host_ErrorRecovery(base);
    }

    return error;
}

static void Host_ErrorRecovery(HOST_TYPE *hostBase)
{
    uint32_t status = 0U;
    /* get host present status */
    status = SDHC_GetPresentStatusFlags(hostBase);
    /* check command inhibit status flag */
    if ((status & kSDHC_CommandInhibitFlag) != 0U)
    {
        /* reset command line */
        SDHC_Reset(hostBase, kSDHC_ResetCommand, 100U);
    }
    /* check data inhibit status flag */
    if ((status & kSDHC_DataInhibitFlag) != 0U)
    {
        /* reset data line */
        SDHC_Reset(hostBase, kSDHC_ResetData, 100U);
    }
}

status_t HOST_Init(void *host)
{
    sdhc_host_t *sdhcHost = (sdhc_host_t *)host;

    /* Initializes SDHC. */
    sdhcHost->config.cardDetectDat3 = false;
    sdhcHost->config.endianMode = SDHC_ENDIAN_MODE;
    sdhcHost->config.dmaMode = SDHC_DMA_MODE;
    sdhcHost->config.readWatermarkLevel = SDHC_READ_WATERMARK_LEVEL;
    sdhcHost->config.writeWatermarkLevel = SDHC_WRITE_WATERMARK_LEVEL;
    SDHC_Init(sdhcHost->base, &(sdhcHost->config));

    /* Define transfer function. */
    sdhcHost->transfer = SDHC_TransferFunction;

    return kStatus_Success;
}

void HOST_Reset(HOST_TYPE *hostBase)
{
    /* reserved for future */
}

void HOST_Deinit(void *host)
{
    sdhc_host_t *sdhcHost = (sdhc_host_t *)host;
    SDHC_Deinit(sdhcHost->base);
}
