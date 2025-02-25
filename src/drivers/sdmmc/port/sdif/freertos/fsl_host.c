/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "event.h"
#include "fsl_host.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

static sdif_handle_t g_sdifHandle;
static uint32_t g_sdifDmaTable[SDIF_DMA_TABLE_WORDS];
static volatile bool g_sdifTransferSuccessFlag = true;

/*******************************************************************************
 * Code
 ******************************************************************************/
/* Delay some time united in milliseconds. */
static void Delay(uint32_t milliseconds)
{
    uint32_t i;
    uint32_t j;

    for (i = 0; i < milliseconds; i++)
    {
        for (j = 0; j < 20000U; j++)
        {
            __asm("NOP");
        }
    }
}

status_t CardInsertDetect(HOST_TYPE *hostBase)
{
    /* Wait card insert */
    while (SDIF_DetectCardInsert(hostBase, false) != 0U)
        ;

    /* disable the card power */
    SDIF_EnableCardPower(hostBase, false);
    /* Delay some time to make card stable. */
    Delay(500U);
    /* Enable the card power */
    SDIF_EnableCardPower(hostBase, true);
    /* Delay some time to make card stable. */
    Delay(500U);

    return kStatus_Success;
}

/* Transfer complete callback function. */
static void SDIF_TransferCompleteCallback(SDIF_Type *base, void *handle, status_t status, void *userData)
{
    /* receive the right status, notify the event */
    if (status == kStatus_Success)
    {
        g_sdifTransferSuccessFlag = true;
    }
    else
    {
        g_sdifTransferSuccessFlag = false;
    }
    EVENT_Notify(kEVENT_TransferComplete);
}

/* User defined transfer function. */
static status_t SDIF_TransferFunction(SDIF_Type *base, sdif_transfer_t *content)
{
    status_t error = kStatus_Success;

    sdif_dma_config_t dmaConfig;

    memset(g_sdifDmaTable, 0, sizeof(g_sdifDmaTable));
    memset(&dmaConfig, 0, sizeof(dmaConfig));

    /* user DMA mode transfer data */
    if (content->data != NULL)
    {
        dmaConfig.enableFixBurstLen = false;
        dmaConfig.mode = kSDIF_DualDMAMode;
        dmaConfig.dmaDesBufferStartAddr = g_sdifDmaTable;
        dmaConfig.dmaDesBufferLen = SDIF_DMA_TABLE_WORDS;
        dmaConfig.dmaDesSkipLen = 0U;
    }

    do
    {
        error = SDIF_TransferNonBlocking(base, &g_sdifHandle, &dmaConfig, content);
    } while (error == kStatus_SDIF_SyncCmdTimeout);

    if ((error != kStatus_Success) || (false == EVENT_Wait(kEVENT_TransferComplete, EVENT_TIMEOUT_TRANSFER_COMPLETE)) ||
        (!g_sdifTransferSuccessFlag))
    {
        error = kStatus_Fail;
    }

    return error;
}

status_t HOST_Init(void *host)
{
    sdif_transfer_callback_t sdifCallback = { 0 };
    sdif_host_t *sdifHost = (sdif_host_t *)host;

    /* Initialize SDIF. */
    sdifHost->config.endianMode = kHOST_EndianModeLittle;
    sdifHost->config.responseTimeout = 0xFFU;
    sdifHost->config.cardDetDebounce_Clock = 0xFFFFFFU;
    sdifHost->config.dataTimeout = 0xFFFFFFU;
    SDIF_Init(sdifHost->base, &(sdifHost->config));

    /* Set callback for SDHC driver. */
    sdifCallback.TransferComplete = SDIF_TransferCompleteCallback;
    /* Create handle for SDHC driver */
    SDIF_TransferCreateHandle(sdifHost->base, &g_sdifHandle, &sdifCallback, NULL);

    /* Create transfer complete event. */
    if (false == EVENT_Create(kEVENT_TransferComplete))
    {
        return kStatus_Fail;
    }

    /* Define transfer function. */
    sdifHost->transfer = SDIF_TransferFunction;

    /* Enable the card power here for mmc card case, because mmc card don't need card detect*/
    SDIF_EnableCardPower(sdifHost->base, true);

    return kStatus_Success;
}

void HOST_Reset(HOST_TYPE *hostBase)
{
    /* reserved for future */
}

void HOST_Deinit(void *host)
{
    sdif_host_t *sdifHost = (sdif_host_t *)host;
    SDIF_Deinit(sdifHost->base);
    EVENT_Delete(kEVENT_TransferComplete);
}
