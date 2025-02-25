/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "property.h"
#include "bootloader_common.h"
#include "memory.h"

const external_memory_property_interface_t g_externalMemPropertyInterfaceMap[] = {
#if BL_FEATURE_SPIFI_NOR_MODULE
    { kMemorySpifiNor, spifi_nor_get_property },
#endif // #if BL_FEATURE_SPIFI_NOR_MODULE
    { 0 } // Terminator
};

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
