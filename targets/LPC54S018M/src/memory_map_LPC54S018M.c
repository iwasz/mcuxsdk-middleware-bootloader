/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "bl_context.h"
#include "memory.h"

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

//! @brief Memory map for LPC54S018M.
//!
//! This map is not const because it is updated at runtime with the actual sizes of
//! flash and RAM for the chip we're running on.
//! @note See memory.h for index requirements.
memory_map_entry_t g_memoryMap[] = {
    { 0x00000000, 0x0002ffff, kMemoryIsExecutable | kMemoryType_RAM, kMemoryInternal,
      &g_normalMemoryInterface }, // SRAMX (192KB)
    { 0x20000000, 0x2000ffff, kMemoryIsExecutable | kMemoryType_RAM, kMemoryInternal,
      &g_normalMemoryInterface }, // SRAM0 (64KB)
    { 0x20010000, 0x20017fff, kMemoryIsExecutable | kMemoryType_RAM, kMemoryInternal,
      &g_normalMemoryInterface }, // SRAM1 (32KB)
    { 0x20018000, 0x2001ffff, kMemoryIsExecutable | kMemoryType_RAM, kMemoryInternal,
      &g_normalMemoryInterface }, // SRAM2 (32KB)
    { 0x20020000, 0x20027fff, kMemoryIsExecutable | kMemoryType_RAM, kMemoryInternal,
      &g_normalMemoryInterface }, // SRAM3 (32KB)
#if BL_FEATURE_SPIFI_NOR_MODULE
    { 0x10000000, 0x103fffff, kMemoryNotExecutable | kMemoryType_FLASH, kMemorySpifiNor,
      &g_spifiMemoryInterface }, // On-chip SPIFI NOR flash (4MB)
#endif
    { 0 } // Terminator
};

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
