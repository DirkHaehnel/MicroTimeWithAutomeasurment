#ifndef __NiFpga_target_main_001_h__
#define __NiFpga_target_main_001_h__

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 */
static const char* const NiFpga_target_main_001_Bitfile = "NiFpga_target_main_001.lvbitx";

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_target_main_001_Signature = "F02B3BECCCA156BC2B6A4E55068B6C22";

typedef enum
{
   NiFpga_target_main_001_ControlBool_stop2 = 0x810E,
} NiFpga_target_main_001_ControlBool;

typedef enum
{
   NiFpga_target_main_001_ControlU32_y = 0x8110,
} NiFpga_target_main_001_ControlU32;

typedef enum
{
   NiFpga_target_main_001_TargetToHostFifoU32_FIFO = 1,
} NiFpga_target_main_001_TargetToHostFifoU32;

typedef enum
{
   NiFpga_target_main_001_TargetToHostFifoU64_FIFO2 = 0,
} NiFpga_target_main_001_TargetToHostFifoU64;

#endif
