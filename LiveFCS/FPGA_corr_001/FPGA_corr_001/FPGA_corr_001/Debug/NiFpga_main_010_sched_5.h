#ifndef __NiFpga_main_010_sched_5_h__
#define __NiFpga_main_010_sched_5_h__

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 */
static const char* const NiFpga_main_010_sched_5_Bitfile = "NiFpga_main_010_sched_5.lvbitx";

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_main_010_sched_5_Signature = "002F23B59BF3BFFBD14DBAAE9EF0BDDD";

typedef enum
{
   NiFpga_main_010_sched_5_ControlBool_stop2 = 0x810E,
} NiFpga_main_010_sched_5_ControlBool;

typedef enum
{
   NiFpga_main_010_sched_5_ControlU32_y = 0x8110,
} NiFpga_main_010_sched_5_ControlU32;

typedef enum
{
   NiFpga_main_010_sched_5_TargetToHostFifoU32_FIFO = 0,
} NiFpga_main_010_sched_5_TargetToHostFifoU32;

#endif
