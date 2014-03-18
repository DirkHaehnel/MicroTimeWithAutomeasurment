#ifndef __NiFpga_target_h__
#define __NiFpga_target_h__

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 */
static const char* const NiFpga_target_Bitfile = "NiFpga_target.lvbitx";

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_target_Signature = "6D5857B2C697A55C41B4B04C0A135867";

typedef enum
{
   NiFpga_target_ControlBool_Acqiure = 0x810E,
   NiFpga_target_ControlBool_Alternate = 0x811A,
   NiFpga_target_ControlBool_Continous = 0x814E,
   NiFpga_target_ControlBool_FPGA_laser = 0x813E,
   NiFpga_target_ControlBool_Imaging = 0x8156,
   NiFpga_target_ControlBool_ch0bool = 0x8166,
   NiFpga_target_ControlBool_ch1bool = 0x8162,
   NiFpga_target_ControlBool_ch2bool = 0x815E,
   NiFpga_target_ControlBool_exit = 0x813A,
   NiFpga_target_ControlBool_exit2 = 0x8136,
   NiFpga_target_ControlBool_start = 0x8132,
   NiFpga_target_ControlBool_stop = 0x815A,
} NiFpga_target_ControlBool;

typedef enum
{
   NiFpga_target_ControlU8_laser_1 = 0x8116,
   NiFpga_target_ControlU8_laser_2 = 0x8112,
} NiFpga_target_ControlU8;

typedef enum
{
   NiFpga_target_ControlI16_Connector0AO0 = 0x814A,
   NiFpga_target_ControlI16_Connector0AO1 = 0x8146,
   NiFpga_target_ControlI16_Connector0AO2 = 0x8142,
} NiFpga_target_ControlI16;

typedef enum
{
   NiFpga_target_ControlU64_1laseroff = 0x8128,
   NiFpga_target_ControlU64_1laseron = 0x812C,
   NiFpga_target_ControlU64_2laseroff = 0x8124,
   NiFpga_target_ControlU64_2laseron = 0x8120,
   NiFpga_target_ControlU64_lenght = 0x811C,
   NiFpga_target_ControlU64_y = 0x8150,
} NiFpga_target_ControlU64;

typedef enum
{
   NiFpga_target_TargetToHostFifoU32_image = 0,
} NiFpga_target_TargetToHostFifoU32;

typedef enum
{
   NiFpga_target_TargetToHostFifoU64_FIFO_to_Host = 1,
} NiFpga_target_TargetToHostFifoU64;

#endif
