// FPGA_corr_001.cpp : main project file.

#include "stdafx.h"
#include<iostream>

#include "Forward/forward_task.h"
#include "FPGA_class/FPGA_target_class.h"
forward_task ch1_toALV,ch1_toFPGA;
forward_task ch2_toALV,ch2_toFPGA;
forward_task ch3_toALV,ch3_toFPGA;
FPGA_target_class target;
CRITICAL_SECTION CriticalSection0,CriticalSection1;
#include "Form1.h"

using namespace FPGA_corr_001;

[STAThreadAttribute]

int ch_forward_Start(){																					
																										//PFI35 normál
	ch1_toALV.dev="PXI1Slot2/ctr0";	ch1_toALV.outpterm="/PXI1Slot2/PFI32";	ch1_toALV.triggerterm="/PXI1Slot2/PFI35";	
	ch1_toALV.init();	ch1_toALV.start();	
	
	ch2_toALV.dev="PXI1Slot2/ctr2";	ch2_toALV.outpterm="/PXI1Slot2/PFI33";	ch2_toALV.triggerterm="/PXI1Slot2/PFI36";	
	ch2_toALV.init();	ch2_toALV.start();	
	
	ch1_toFPGA.dev="PXI1Slot2/ctr1"; ch1_toFPGA.outpterm="/PXI1Slot2/PFI20";	ch1_toFPGA.triggerterm="/PXI1Slot2/PFI35";
	ch1_toFPGA.init();	ch1_toFPGA.start();
	
	ch2_toFPGA.dev="PXI1Slot2/ctr3"; ch2_toFPGA.outpterm="/PXI1Slot2/PFI24";	ch2_toFPGA.triggerterm="/PXI1Slot2/PFI36";
	ch2_toFPGA.init();	ch2_toFPGA.start();
	
	ch3_toFPGA.dev="PXI1Slot2/ctr5"; ch3_toFPGA.outpterm="/PXI1Slot2/PFI28";	ch3_toFPGA.triggerterm="/PXI1Slot2/PFI37";	
	ch3_toFPGA.init();	ch3_toFPGA.start();
return 0;
}

int ch_forward_Stop(){	
	ch1_toALV.stop();	ch1_toALV.clear();		
	ch2_toALV.stop();	ch2_toALV.clear();	
	
	ch1_toFPGA.stop();	ch1_toFPGA.clear();	
	ch2_toFPGA.stop();	ch2_toFPGA.clear();	
	ch3_toFPGA.stop();	ch3_toFPGA.clear();
return 0;
}

int main(array<System::String ^> ^args)
{	
	if (!InitializeCriticalSectionAndSpinCount(&CriticalSection0, 0x80000400) )return -4;
	if (!InitializeCriticalSectionAndSpinCount(&CriticalSection1, 0x80000400) )return -4;

	ch_forward_Start();


	// Enabling Windows XP visual effects before any controls are created

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	ch_forward_Stop();
	return 0;
}

extern "C" DWORD WINAPI ch0readsp(void *){
	System::Console::Write("thread 1:				 STARTED\n");
	target.thread_1_exit=false;	
	unsigned __int32 data0[9],RUNS,numRUNS;
	uint32_t remaining;
	
	unsigned int address;
	FILE *out=fopen("lllll.dat","w+");
	
	
	numRUNS=0;
	RUNS=0;
	Sleep(100);
	while( target.running==true && RUNS < target.RUN_MAX){		
		target.MNiFpga_ReadFifoU32(*(target.session0),NiFpga_main_010_sched_5_TargetToHostFifoU32_FIFO,data0,9,10000,&remaining);
		if(data0[8]!=0){ numRUNS++; }
		address=data0[7];		
		if(numRUNS==target.sum_num){numRUNS=0;RUNS++;target.set_RUN(RUNS);
		System::Console::Write("New Run\n");		
		}
		target.set_Mx(data0[0],address);
		target.set_My(data0[1],address);
		target.set_Gxx(data0[2],address);
		target.set_Gyy(data0[3],address);
		target.set_Gxy(data0[4],address);
		target.set_Gyx(data0[5],address);
		target.set_T(data0[6],address);
		fprintf(out,"%ld %ld %ld %ld %ld %ld %ld %ld %ld\n",data0[8],data0[7],data0[0],data0[1],data0[2],data0[3],data0[4],data0[5],data0[6]);		
		}
	fclose(out);
	System::Console::Write("readstop\n");

	EnterCriticalSection(&CriticalSection0);

	target.running=false;	

	LeaveCriticalSection(&CriticalSection0);

	System::Console::Write("thread 1:				 EXIT\n");
	target.thread_1_exit=true;
	return 0;
}


extern "C" DWORD WINAPI ch0readFIFO(void *){
System::Console::Write("thread 2:				 STARTED\n");
HANDLE hFile;
uint32_t towrite,remaining;
DWORD dwBytesWritten;
unsigned __int64 *data0;
hFile = CreateFile("temp0000",GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);
if(GetLastError()==80){

}

if ( hFile == INVALID_HANDLE_VALUE ){
		System::Console::Write("create file: ERR\n");
		return 0;	
		}
else{
		System::Console::Write("create file: OK\n");
		unsigned __int64 last=0xFFFFFFFFFFFFFFFF;
		WriteFile(hFile, &last, sizeof(unsigned __int64), &dwBytesWritten, NULL);
		WriteFile(hFile, &last, sizeof(unsigned __int64), &dwBytesWritten, NULL);
		WriteFile(hFile, &last, sizeof(unsigned __int64), &dwBytesWritten, NULL);
		WriteFile(hFile, &last, sizeof(unsigned __int64), &dwBytesWritten, NULL);
}

Sleep(100);

//writeheader(hFile);
long sizeof64=sizeof(unsigned __int64);
unsigned long size0=1000;
int32_t *size00=new int32_t;
remaining=0;
*(size00)=size0;
System::Console::Write("read start\n");
bool enabled=true;
data0=new unsigned __int64[size0];
towrite=size0*sizeof64;
enabled=true;
while(enabled==true){	
	target.MNiFpga_ReadFifoU64(*(target.session0),NiFpga_main_010_sched_5_TargetToHostFifoU64_FIFO2,data0,size0,1000000,&remaining);
	WriteFile(hFile, data0, towrite, &dwBytesWritten, NULL);

	EnterCriticalSection(&CriticalSection0);

	enabled=target.running;

	LeaveCriticalSection(&CriticalSection0);
	
}
while(remaining>0){
    size0=remaining;
	data0=(unsigned __int64 *)realloc(data0,size0*sizeof64);
	target.MNiFpga_ReadFifoU64(*(target.session0),NiFpga_main_010_sched_5_TargetToHostFifoU64_FIFO2,data0,size0,1000000,&remaining);
	towrite=size0*sizeof64;
    WriteFile(hFile, data0, towrite, &dwBytesWritten, NULL);
}

if(CloseHandle(hFile) >0)System::Console::Write("file close: OK\n");
else System::Console::Write("file close: ERR\n");
delete data0;
while(target.thread_1_exit!=true){
	Sleep(100);
}
System::Console::Write("thread 2:				 EXIT\n");
target.FPGA_stop();
return 0;
}
