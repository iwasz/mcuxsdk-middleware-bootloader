/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __FSL_DSPI_UCOSII_H__
#define __FSL_DSPI_UCOSII_H__

#include <ucos_ii.h>

#include "fsl_dspi.h"

/*!
 * @addtogroup dspi_ucosii_driver DSPI uCOS II driver
 * @{
 */

/**********************************************************************************************************************
 * Definitions
 *********************************************************************************************************************/
/*! @brief DSPI uCOS II driver version */
#define FSL_DSPI_UCOSII_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0. */

/*! @brief DSPI uCOS II handle */
typedef struct _dspi_rtos_handle
{
    SPI_Type *base;                  /*!< DSPI base address */
    dspi_master_handle_t drv_handle; /*!< Handle of the underlying driver, treated as opaque by the RTOS layer */
    status_t async_status;
    OS_EVENT *mutex; /*!< Mutex to lock the handle during a trasfer */
#define RTOS_DSPI_COMPLETE 0x1
    OS_FLAG_GRP *event; /*!< Semaphore to notify and unblock task when transfer ends */
} dspi_rtos_handle_t;

/**********************************************************************************************************************
 * API
 *********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name DSPI RTOS Operation
 * @{
 */

/*!
 * @brief Initializes DSPI.
 *
 * This function initializes the DSPI module and related RTOS context.
 *
 * @param handle The RTOS DSPI handle, the pointer to an allocated space for RTOS context.
 * @param base The pointer base address of the DSPI instance to initialize.
 * @param masterConfig Configuration structure to set-up DSPI in master mode.
 * @param srcClock_Hz Frequency of input clock of the DSPI module.
 * @return status of the operation.
 */
status_t DSPI_RTOS_Init(dspi_rtos_handle_t *handle,
                        SPI_Type *base,
                        const dspi_master_config_t *masterConfig,
                        uint32_t srcClock_Hz);

/*!
 * @brief Deinitializes the DSPI.
 *
 * This function deinitializes the DSPI module and related RTOS context.
 *
 * @param handle The RTOS DSPI handle.
 */
status_t DSPI_RTOS_Deinit(dspi_rtos_handle_t *handle);

/*!
 * @brief Performs SPI transfer.
 *
 * This function performs an SPI transfer according to data given in the transfer structure.
 *
 * @param handle The RTOS DSPI handle.
 * @param transfer Structure specifying the transfer parameters.
 * @return status of the operation.
 */
status_t DSPI_RTOS_Transfer(dspi_rtos_handle_t *handle, dspi_transfer_t *transfer);

/*!
 * @}
 */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* __FSL_DSPI_UCOSII_H__ */
