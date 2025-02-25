/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dspi_ucosiii.h"
#include <os.h>
#include <lib_mem.h>

static void DSPI_RTOS_Callback(SPI_Type *base, dspi_master_handle_t *drv_handle, status_t status, void *userData)
{
    OS_ERR err;
    dspi_rtos_handle_t *handle = (dspi_rtos_handle_t *)userData;
    OSFlagPost(&handle->event, RTOS_DSPI_COMPLETE, OS_OPT_POST_FLAG_SET, &err);
}

status_t DSPI_RTOS_Init(dspi_rtos_handle_t *handle,
                        SPI_Type *base,
                        const dspi_master_config_t *masterConfig,
                        uint32_t srcClock_Hz)
{
    OS_ERR err;

    if (handle == NULL)
    {
        return kStatus_InvalidArgument;
    }

    if (base == NULL)
    {
        return kStatus_InvalidArgument;
    }

    memset(handle, 0, sizeof(dspi_rtos_handle_t));

    OSSemCreate(&handle->mutex, "DSPI", (OS_SEM_CTR)1, &err);
    if (OS_ERR_NONE != err)
    {
        return kStatus_Fail;
    }

    OSFlagCreate(&handle->event, "DSPI", (OS_FLAGS)0, &err);
    if (OS_ERR_NONE != err)
    {
        OSSemDel(&handle->mutex, OS_OPT_DEL_ALWAYS, &err);
        return kStatus_Fail;
    }

    handle->base = base;

    DSPI_MasterInit(handle->base, masterConfig, srcClock_Hz);
    DSPI_MasterTransferCreateHandle(handle->base, &handle->drv_handle, DSPI_RTOS_Callback, (void *)handle);

    return kStatus_Success;
}

status_t DSPI_RTOS_Deinit(dspi_rtos_handle_t *handle)
{
    OS_ERR err;
    DSPI_Deinit(handle->base);
    OSFlagDel(&handle->event, OS_OPT_DEL_ALWAYS, &err);
    OSSemDel(&handle->mutex, OS_OPT_DEL_ALWAYS, &err);

    return kStatus_Success;
}

status_t DSPI_RTOS_Transfer(dspi_rtos_handle_t *handle, dspi_transfer_t *transfer)
{
    status_t status;
    OS_FLAGS ev;
    OS_ERR err;

    /* Lock resource mutex */
    OSSemPend(&handle->mutex, 0, OS_OPT_PEND_BLOCKING, NULL, &err);
    if (OS_ERR_NONE != err)
    {
        return kStatus_Fail;
    }

    ev = OSFlagPost(&handle->event, RTOS_DSPI_COMPLETE, OS_OPT_POST_FLAG_CLR, &err);
    assert((ev & RTOS_DSPI_COMPLETE) == 0);

    status = DSPI_MasterTransferNonBlocking(handle->base, &handle->drv_handle, transfer);
    if (status != kStatus_Success)
    {
        OSSemPost(&handle->mutex, OS_OPT_POST_1, &err);
        return status;
    }

    /* Wait for transfer to finish */
    ev = OSFlagPend(&handle->event, RTOS_DSPI_COMPLETE, 0, OS_OPT_PEND_FLAG_SET_ALL, NULL, &err);
    if (!(ev & RTOS_DSPI_COMPLETE))
    {
        OSSemPost(&handle->mutex, OS_OPT_POST_1, &err);
        return kStatus_Fail;
    }

    /* Unlock resource mutex */
    OSSemPost(&handle->mutex, OS_OPT_POST_1, &err);
    if (OS_ERR_NONE != err)
    {
        /* We could not post back the semaphore, exit with error */
        return kStatus_Fail;
    }

    /* Return status captured by callback function */
    return handle->async_status;
}
