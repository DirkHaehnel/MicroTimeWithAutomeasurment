#pragma once
#include<windows.h>
#include "NiFpga.h"
#include "NiFpga_target_main_001.h"
typedef NiFpga_Status (WINAPI *N_NiFpga_Initialize)();
typedef NiFpga_Status (WINAPI *N_NiFpga_Open)(const char* bitfile, const char* signature, const char* resource, uint32_t attribute, NiFpga_Session* session);
typedef NiFpga_Status (WINAPI *N_NiFpga_ConfigureFifo)(NiFpga_Session session, uint32_t fifo, uint32_t depth);
typedef NiFpga_Status (WINAPI *N_NiFpga_Run)(NiFpga_Session session, uint32_t attribute);
typedef NiFpga_Status (WINAPI *N_NiFpga_StopFifo)(NiFpga_Session session, uint32_t fifo);
typedef NiFpga_Status (WINAPI *N_NiFpga_WriteBool)(NiFpga_Session session, uint32_t control, NiFpga_Bool value);
typedef NiFpga_Status (WINAPI *N_NiFpga_Close)(NiFpga_Session session, uint32_t attribute);
typedef NiFpga_Status (WINAPI *N_NiFpga_WriteI16)(NiFpga_Session session, uint32_t control, int16_t value);
typedef NiFpga_Status (WINAPI *N_NiFpga_WriteU32)(NiFpga_Session session, uint32_t control, uint32_t value);
typedef NiFpga_Status (WINAPI *N_NiFpga_WriteU64)(NiFpga_Session session, uint32_t control, uint64_t value);
typedef NiFpga_Status (WINAPI *N_NiFpga_ReadFifoU32)(NiFpga_Session session, uint32_t fifo, uint32_t* data, uint32_t numberOfElements, uint32_t timeout, uint32_t* elementsRemaining);
typedef NiFpga_Status (WINAPI *N_NiFpga_ReadFifoU64)(NiFpga_Session session, uint32_t fifo, uint64_t* data, uint32_t numberOfElements, uint32_t timeout, uint32_t* elementsRemaining);
typedef NiFpga_Status (WINAPI *N_NiFpga_WriteFifoI32) (NiFpga_Session session, uint32_t fifo, const int32_t * data, uint32_t count, uint32_t timeout, uint32_t * remaining);
typedef NiFpga_Status (WINAPI *N_NiFpga_ReadU32) (NiFpga_Session session, uint32_t indicator, uint32_t * value);
typedef NiFpga_Status (WINAPI *N_NiFpga_StartFifo)(NiFpga_Session session, uint32_t fifo);
typedef NiFpga_Status (WINAPI *N_NiFpga_WriteU8)(NiFpga_Session session, uint32_t control, uint8_t value);
typedef NiFpga_Status (WINAPI *N_NiFpga_Reset)(NiFpga_Session session);
typedef NiFpga_Status (WINAPI *N_NiFpga_Abort)(NiFpga_Session session);

class FPGA_target_class
{
public:
	
	int FPGA_start();
	int FPGA_Run();
	int FPGA_stop();
	int FPGA_close();

	double get_tau(unsigned int i);
		
	double get_gxx(unsigned int j,unsigned int i);	
	double get_gyy(unsigned int j, unsigned int i);	
	double get_gxy(unsigned int j, unsigned int i);	
	double get_gyx(unsigned int j, unsigned int i);
     
	int set_RUN(unsigned int RUN_0);
	int set_Gxx(double Gxx0,unsigned int ind_0);
	int set_Gyy(double Gyy0,unsigned int ind_0);
	int set_Gxy(double Gxy0,unsigned int ind_0);
	int set_Gyx(double Gyx0,unsigned int ind_0);
	int set_Mx(double Mxi,unsigned int ind_0);
	int set_My(double Myi,unsigned int ind_0);
	int set_T(double T0,unsigned int ind_0);
    int write_res_tofile();
	bool ACF0,ACF1,CCF01,CCF10;
	FPGA_target_class(void);
	NiFpga_Status status;
	NiFpga_Session *session0;
	HANDLE consH,waitTH;
	bool running,sprunning,OK,ended;
	bool thread_1_exit;
	unsigned int ptime,sptime;

	N_NiFpga_ReadFifoU32 MNiFpga_ReadFifoU32;
	N_NiFpga_ReadFifoU64 MNiFpga_ReadFifoU64;
	N_NiFpga_WriteFifoI32 MNiFpga_WriteFifoI32;
	N_NiFpga_ReadU32 MNiFpga_ReadU32;
	int data_reset();
	char *fname_0,*fname_1,*fname_2,*fname_3,*fname_RAW;
	friend class forward_class;
	
	

	double tau[1000];	

	double Gxx[100][1000];
	double Gyy[100][1000];
	double Gxy[100][1000];
	double Gyx[100][1000];
	double Mx[100][1000];
	double My[100][1000];
	double T[100][1000];
	double Mx0[100][1000],My0[100][1000];
	unsigned int RUN,RUN_MAX,sum_num;
private:	
	
	HANDLE readth,readth2;
	int FPGA_init();
	int initfunc();	
	
	unsigned long depth;
	
	N_NiFpga_Initialize MNiFpga_Initialize;
	N_NiFpga_Open MNiFpga_Open;
	N_NiFpga_ConfigureFifo MNiFpga_ConfigureFifo;
	N_NiFpga_Run MNiFpga_Run;
	N_NiFpga_StopFifo MNiFpga_StopFifo;
	N_NiFpga_WriteBool MNiFpga_WriteBool;
	N_NiFpga_Close MNiFpga_Close;
	N_NiFpga_WriteU64 MNiFpga_WriteU64;
	N_NiFpga_WriteU32 MNiFpga_WriteU32;
	N_NiFpga_WriteI16 MNiFpga_WriteI16;
	N_NiFpga_StartFifo MNiFpga_StartFifo;
	N_NiFpga_WriteU8 MNiFpga_WriteU8;
	N_NiFpga_Reset MN_NiFpga_Reset;
	N_NiFpga_Abort MN_NiFpga_Abort;
	HMODULE ni_DLL;
	
};
