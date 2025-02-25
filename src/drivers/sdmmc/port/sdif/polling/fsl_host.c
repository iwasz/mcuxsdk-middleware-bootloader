/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

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

static uint32_t g_sdifDmaTable[SDIF_DMA_TABLE_WORDS];
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

/* User defined transfer function. */
static status_t SDIF_TransferFunction(SDIF_Type *base, sdif_transfer_t *content)
{
    status_t error = kStatus_Success;

    sdif_dma_config_t dmaConfig;

    memset(g_sdifDmaTable, 0, sizeof(g_sdifDmaTable));
    memset(&dmaConfig, 0, sizeof(dmaConfig));

    if (content->data != NULL)
    {
        dmaConfig.enableFixBurstLen = true;
        dmaConfig.mode = kSDIF_ChainDMAMode;
        dmaConfig.dmaDesBufferStartAddr = g_sdifDmaTable;
        dmaConfig.dmaDesBufferLen = SDIF_DMA_TABLE_WORDS;
    }

    if (kStatus_Success != SDIF_TransferBlocking(base, &dmaConfig, content))
    {
        error = kStatus_Fail;
    }

    return error;
}

status_t HOST_Init(void *host)
{
    sdif_host_t *sdifHost = (sdif_host_t *)host;

    /* Initialize SDIF. */
    sdifHost->config.endianMode = kHOST_EndianModeLittle;
    sdifHost->config.responseTimeout = 0xFFU;
    sdifHost->config.cardDetDebounce_Clock = 0xFFFFFFU;
    sdifHost->config.dataTimeout = 0xFFFFFFU;
    SDIF_Init(sdifHost->base, &(sdifHost->config));

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
}
