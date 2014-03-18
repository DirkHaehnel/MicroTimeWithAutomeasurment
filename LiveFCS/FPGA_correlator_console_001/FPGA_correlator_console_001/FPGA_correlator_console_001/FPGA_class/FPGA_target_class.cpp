#include "StdAfx.h"
#include "FPGA_target_class.h"
//#include "NiFpga_main_010_sched_5.h"
#include "NiFpga_target_main_001.h"
#include "NiFpga_mem_reset_001.h"
#include <stdio.h>
#include <windows.h>
#include <wchar.h>

//*********************************************************************************************************************

FPGA_target_class::FPGA_target_class(void)
{
AllocConsole();
OK=false;
sprunning=false;
consH=GetStdHandle(STD_OUTPUT_HANDLE);
if(consH==NULL){AllocConsole(); consH=GetStdHandle(STD_OUTPUT_HANDLE);}
if(FPGA_init()!=0){WriteConsole(consH,TEXT("FPGA init: ERR\n"),15,NULL,NULL);}
else{OK=true; WriteConsole(consH,TEXT("FPGA init: OK\n"),14,NULL,NULL);  }
}

//*********************************************************************************************************************

int FPGA_target_class::FPGA_init(){
status=0;
depth=200000;             //depth of FIFO
sprunning=false;
tau[	1	]=	0.0004	; //lag times, ms
tau[	2	]=	0.0008	;
tau[	3	]=	0.0012	;
tau[	4	]=	0.0016	;
tau[	5	]=	0.002	;
tau[	6	]=	0.0024	;
tau[	7	]=	0.0028	;
tau[	8	]=	0.0032	;
tau[	9	]=	0.004	;
tau[	10	]=	0.0048	;
tau[	11	]=	0.0056	;
tau[	12	]=	0.0064	;
tau[	13	]=	0.0072	;
tau[	14	]=	0.008	;
tau[	15	]=	0.0088	;
tau[	16	]=	0.0096	;
tau[	17	]=	0.0112	;
tau[	18	]=	0.0128	;
tau[	19	]=	0.0144	;
tau[	20	]=	0.016	;
tau[	21	]=	0.0176	;
tau[	22	]=	0.0192	;
tau[	23	]=	0.0208	;
tau[	24	]=	0.0224	;
tau[	25	]=	0.0256	;
tau[	26	]=	0.0288	;
tau[	27	]=	0.032	;
tau[	28	]=	0.0352	;
tau[	29	]=	0.0384	;
tau[	30	]=	0.0416	;
tau[	31	]=	0.0448	;
tau[	32	]=	0.048	;
tau[	33	]=	0.0544	;
tau[	34	]=	0.0608	;
tau[	35	]=	0.0672	;
tau[	36	]=	0.0736	;
tau[	37	]=	0.08	;
tau[	38	]=	0.0864	;
tau[	39	]=	0.0928	;
tau[	40	]=	0.0992	;
tau[	41	]=	0.112	;
tau[	42	]=	0.1248	;
tau[	43	]=	0.1376	;
tau[	44	]=	0.1504	;
tau[	45	]=	0.1632	;
tau[	46	]=	0.176	;
tau[	47	]=	0.1888	;
tau[	48	]=	0.2016	;
tau[	49	]=	0.2272	;
tau[	50	]=	0.2528	;
tau[	51	]=	0.2784	;
tau[	52	]=	0.304	;
tau[	53	]=	0.3296	;
tau[	54	]=	0.3552	;
tau[	55	]=	0.3808	;
tau[	56	]=	0.4064	;
tau[	57	]=	0.4576	;
tau[	58	]=	0.5088	;
tau[	59	]=	0.56	;
tau[	60	]=	0.6112	;
tau[	61	]=	0.6624	;
tau[	62	]=	0.7136	;
tau[	63	]=	0.7648	;
tau[	64	]=	0.816	;
tau[	65	]=	0.9184	;
tau[	66	]=	1.0208	;
tau[	67	]=	1.1232	;
tau[	68	]=	1.2256	;
tau[	69	]=	1.328	;
tau[	70	]=	1.4304	;
tau[	71	]=	1.5328	;
tau[	72	]=	1.6352	;
tau[	73	]=	1.84	;
tau[	74	]=	2.0448	;
tau[	75	]=	2.2496	;
tau[	76	]=	2.4544	;
tau[	77	]=	2.6592	;
tau[	78	]=	2.864	;
tau[	79	]=	3.0688	;
tau[	80	]=	3.2736	;
tau[	81	]=	3.6832	;
tau[	82	]=	4.0928	;
tau[	83	]=	4.5024	;
tau[	84	]=	4.912	;
tau[	85	]=	5.3216	;
tau[	86	]=	5.7312	;
tau[	87	]=	6.1408	;
tau[	88	]=	6.5504	;
tau[	89	]=	7.3696	;
tau[	90	]=	8.1888	;
tau[	91	]=	9.008	;
tau[	92	]=	9.8272	;
tau[	93	]=	10.6464	;
tau[	94	]=	11.4656	;
tau[	95	]=	12.2848	;
tau[	96	]=	13.104	;
tau[	97	]=	14.7424	;
tau[	98	]=	16.3808	;
tau[	99	]=	18.0192	;
tau[	100	]=	19.6576	;
tau[	101	]=	21.296	;
tau[	102	]=	22.9344	;
tau[	103	]=	24.5728	;
tau[	104	]=	26.2112	;
tau[	105	]=	29.488	;
tau[	106	]=	32.7648	;
tau[	107	]=	36.0416	;
tau[	108	]=	39.3184	;
tau[	109	]=	42.5952	;
tau[	110	]=	45.872	;
tau[	111	]=	49.1488	;
tau[	112	]=	52.4256	;
tau[	113	]=	58.9792	;
tau[	114	]=	65.5328	;
tau[	115	]=	72.0864	;
tau[	116	]=	78.64	;
tau[	117	]=	85.1936	;
tau[	118	]=	91.7472	;
tau[	119	]=	98.3008	;
tau[	120	]=	104.8544	;
tau[	121	]=	117.9616	;
tau[	122	]=	131.0688	;
tau[	123	]=	144.176	;
tau[	124	]=	157.2832	;
tau[	125	]=	170.3904	;
tau[	126	]=	183.4976	;
tau[	127	]=	196.6048	;
tau[	128	]=	209.712	;
tau[	129	]=	235.9264	;
tau[	130	]=	262.1408	;
tau[	131	]=	288.3552	;
tau[	132	]=	314.5696	;
tau[	133	]=	340.784	;
tau[	134	]=	366.9984	;
tau[	135	]=	393.2128	;
tau[	136	]=	419.4272	;
tau[	137	]=	471.856	;
tau[	138	]=	524.2848	;
tau[	139	]=	576.7136	;
tau[	140	]=	629.1424	;
tau[	141	]=	681.5712	;
tau[	142	]=	734	;
tau[	143	]=	786.4288	;
tau[	144	]=	838.8576	;
tau[	145	]=	943.7152	;
tau[	146	]=	1048.5728	;
tau[	147	]=	1153.4304	;
tau[	148	]=	1258.288	;
tau[	149	]=	1363.1456	;
tau[	150	]=	1468.0032	;
tau[	151	]=	1572.8608	;
tau[	152	]=	1677.7184	;
tau[	153	]=	1887.4336	;
tau[	154	]=	2097.1488	;
tau[	155	]=	2306.864	;
tau[	156	]=	2516.5792	;
tau[	157	]=	2726.2944	;
tau[	158	]=	2936.0096	;
tau[	159	]=	3145.7248	;
tau[	160	]=	3355.44	;
tau[	161	]=	3774.8704	;
tau[	162	]=	4194.3008	;
tau[	163	]=	4613.7312	;
tau[	164	]=	5033.1616	;
tau[	165	]=	5452.592	;
tau[	166	]=	5872.0224	;
tau[	167	]=	6291.4528	;
tau[	168	]=	6710.8832	;
tau[	169	]=	7549.744	;
tau[	170	]=	8388.6048	;
tau[	171	]=	9227.4656	;
tau[	172	]=	10066.3264	;
tau[	173	]=	10905.1872	;
tau[	174	]=	11744.048	;
tau[	175	]=	12582.9088	;
tau[	176	]=	13421.7696	;
tau[	177	]=	15099.4912	;
tau[	178	]=	16777.2128	;
tau[	179	]=	18454.9344	;
tau[	180	]=	20132.656	;
tau[	181	]=	21810.3776	;
tau[	182	]=	23488.0992	;
tau[	183	]=	25165.8208	;
tau[	184	]=	26843.5424	;
tau[	185	]=	30198.9856	;
tau[	186	]=	33554.4288	;
tau[	187	]=	36909.872	;
tau[	188	]=	40265.3152	;
tau[	189	]=	43620.7584	;
tau[	190	]=	46976.2016	;
tau[	191	]=	50331.6448	;
tau[	192	]=	53687.088	;
tau[	193	]=	60397.9744	;
tau[	194	]=	67108.8608	;
tau[	195	]=	73819.7472	;
tau[	196	]=	80530.6336	;
tau[	197	]=	87241.52	;
tau[	198	]=	93952.4064	;
tau[	199	]=	100663.2928	;
tau[	200	]=	107374.1792	;
tau[	201	]=	18454.934	;

unsigned int i,j;
j=0;
while(j<100){
	i=0;
	while(i<1000){
		Gxx[j][i]=Mx[j][i]=T[j][i]=0.0;
		Gyy[j][i]=My[j][i]=0.0;
		Gxy[j][i]=Gyx[j][i]=0.0;		
		i++;
		}
	j++;
}

return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::FPGA_close(){

	NiFpga_SetStatus(&status, MNiFpga_Close(*session0,0));
	if(status!=0){WriteConsole(consH,"FPGA Close: ERR\n",16,NULL,NULL);return -1;}
	else{System::Console::Write("FPGA Close: OK\n");}
status=0;
return 0;
}


//*********************************************************************************************************************

int FPGA_target_class::initfunc(){
running=false;
ni_DLL=LoadLibrary("NiFpga.dll");
if(ni_DLL==NULL){ System::Console::Write("LoadLibrary ERR");  return -1; }
else{System::Console::Write("LoadLibrary OK"); }

MNiFpga_Open=(N_NiFpga_Open)GetProcAddress(ni_DLL,"NiFpgaDll_Open");
if(MNiFpga_Open==NULL){ System::Console::Write("f2 errr");  return -1; }

MNiFpga_ConfigureFifo=(N_NiFpga_ConfigureFifo) GetProcAddress(ni_DLL,"NiFpgaDll_ConfigureFifo");
if(MNiFpga_ConfigureFifo==NULL){ System::Console::Write("f3 errr"); return -1; }

MNiFpga_Run=(N_NiFpga_Run)GetProcAddress(ni_DLL,"NiFpgaDll_Run");
if(MNiFpga_Run==NULL){ System::Console::Write("f4 errr"); return -1; }

MNiFpga_StopFifo=(N_NiFpga_StopFifo)GetProcAddress(ni_DLL,"NiFpgaDll_StopFifo");
if(MNiFpga_StopFifo==NULL){	System::Console::Write("f5 errr"); return -1; }

MNiFpga_WriteBool=(N_NiFpga_WriteBool)GetProcAddress(ni_DLL,"NiFpgaDll_WriteBool");
if(MNiFpga_WriteBool==NULL){ System::Console::Write("f6 errr"); return -1; }

MNiFpga_Close=(N_NiFpga_Close)GetProcAddress(ni_DLL,"NiFpgaDll_Close");
if(MNiFpga_Close==NULL){ System::Console::Write("f7 errr"); return -1; }

MNiFpga_WriteU64=(N_NiFpga_WriteU64)GetProcAddress(ni_DLL,"NiFpgaDll_WriteU64");
if(MNiFpga_WriteU64==NULL){ System::Console::Write("f8 errr"); return -1; }
 
MNiFpga_ReadFifoU32=(N_NiFpga_ReadFifoU32)GetProcAddress(ni_DLL,"NiFpgaDll_ReadFifoU32");
if(MNiFpga_ReadFifoU32==NULL){ System::Console::Write("f9 errr"); return -1; }

MNiFpga_WriteI16=(N_NiFpga_WriteI16)GetProcAddress(ni_DLL,"NiFpgaDll_WriteI16");
if(MNiFpga_WriteI16==NULL){ System::Console::Write("f10 errr"); return -1; }

MNiFpga_ReadFifoU64=(N_NiFpga_ReadFifoU64)GetProcAddress(ni_DLL,"NiFpgaDll_ReadFifoU64");
if(MNiFpga_ReadFifoU64==NULL){ System::Console::Write("f11 errr"); return -1; }

MNiFpga_StartFifo=(N_NiFpga_StartFifo)GetProcAddress(ni_DLL,"NiFpgaDll_StartFifo");
if(MNiFpga_StartFifo==NULL){ System::Console::Write("f12 errr"); return -1; }

MNiFpga_WriteFifoI32=(N_NiFpga_WriteFifoI32)GetProcAddress(ni_DLL,"NiFpgaDll_WriteFifoI32");
if(MNiFpga_WriteFifoI32==NULL){ System::Console::Write("f13 errr"); return -1; }

MNiFpga_ReadU32=(N_NiFpga_ReadU32)GetProcAddress(ni_DLL,"NiFpgaDll_ReadU32");
if(MNiFpga_ReadU32==NULL){ System::Console::Write("f14 errr"); return -1; }

MNiFpga_WriteU8=(N_NiFpga_WriteU8)GetProcAddress(ni_DLL,"NiFpgaDll_WriteU8");
if(MNiFpga_WriteU8==NULL){ System::Console::Write("f15 errr"); return -1; }

MNiFpga_WriteU32=(N_NiFpga_WriteU32)GetProcAddress(ni_DLL,"NiFpgaDll_WriteU32");
if(MNiFpga_WriteU32==NULL){ System::Console::Write("f16 errr"); return -1; }

MN_NiFpga_Reset=(N_NiFpga_Reset)GetProcAddress(ni_DLL,"NiFpgaDll_Reset");
if(MN_NiFpga_Reset==NULL){ System::Console::Write("f17 errr"); return -1; }

MN_NiFpga_Abort=(N_NiFpga_Abort)GetProcAddress(ni_DLL,"NiFpgaDll_Abort");
if(MN_NiFpga_Abort==NULL){ System::Console::Write("f18 errr"); return -1; }

return 0;
}

//*********************************************************************************************************************

extern "C" DWORD WINAPI ch0readsp(void *);
extern "C" DWORD WINAPI ch0readFIFO(void *);

//*********************************************************************************************************************

int FPGA_target_class::FPGA_start(){
	sprunning=false;
	unsigned long j1;
	if(sprunning==false) {
		RUN=0;
		data_reset();
		status=0;
		//sprunning=true;
		session0=new NiFpga_Session;
		if(initfunc()!=0){System::Console::Write("Initfunc: ERR\n");  return -1; }
		else { System::Console::Write("Initfunc: OK\n"); }

		NiFpga_IsNotFatal(status); if(status!=0){ System::Console::Write("FPGA 1: ERR\n"); return -1; }

//**********************************************************************************************************************
		NiFpga_SetStatus(&status,MNiFpga_Open(NiFpga_mem_reset_001_Bitfile,NiFpga_mem_reset_001_Signature,"RIO0",0,session0));
		if(status!=0){ System::Console::Write("FPGA Open: ERR\n");  return -2; }
		else{System::Console::Write("mem reset FPGA Open: OK\n"); }

		NiFpga_SetStatus(&status, MNiFpga_Run(*session0, NiFpga_RunAttribute_WaitUntilDone));
		NiFpga_SetStatus(&status, MNiFpga_Close(*session0,0));
		delete session0;
		status=0;
		session0=new NiFpga_Session;

//**********************************************************************************************************************
		NiFpga_SetStatus(&status,MNiFpga_Open(NiFpga_target_main_001_Bitfile,NiFpga_target_main_001_Signature,"RIO0",NiFpga_OpenAttribute_NoRun,session0));
		if(status!=0){ System::Console::Write("FPGA Open: ERR\n");  return -2; }
		else{System::Console::Write("FPGA Open: OK\n"); }
//**********************************************************************************************************************	
		NiFpga_SetStatus(&status,MNiFpga_ConfigureFifo(*session0, NiFpga_target_main_001_TargetToHostFifoU32_FIFO,depth));
		if(status!=0){ 
			System::Console::Write("FPGA FIFO 1 conf: ERR\n");  
			NiFpga_SetStatus(&status, MNiFpga_Close(*session0, 0));
   		    if(status!=0)System::Console::Write("stop 3: err\n");
			return -4;
		  }
		else{ System::Console::Write("FPGA FIFO 1 conf: OK\n"); }

//**********************************************************************************************************************	
		NiFpga_SetStatus(&status,MNiFpga_ConfigureFifo(*session0,NiFpga_target_main_001_TargetToHostFifoU64_FIFO2,depth));
		if(status!=0){ 
			System::Console::Write("FPGA FIFO 2 conf: ERR\n");  
			NiFpga_SetStatus(&status, MNiFpga_Close(*session0, 0));
			if(status!=0)System::Console::Write("stop 4: err\n");		
			return -4;	 
			}
		else{ System::Console::Write("FPGA FIFO 2 conf: OK\n"); }



//**********************************************************************************************************************

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	unsigned long length=((8388608)/2);	     //<<<======================== length of 1 run; number of clock cycles; see the labview code
	NiFpga_SetStatus(&status,MNiFpga_WriteU32(*session0,NiFpga_target_main_001_ControlU32_y,length));     
	if(status!=0){System::Console::Write("U32 conf: ERR\n");  NiFpga_SetStatus(&status, MNiFpga_Close(*session0, 0));}
	else{ System::Console::Write("U32 conf: OK\n");}
	Sleep(500);
//**********************************************************************************************************************
	if(FPGA_Run()==0) {
	running=true;
	readth=CreateThread(NULL,0,&ch0readsp,0,0,&j1);
	readth2=CreateThread(NULL,0,&ch0readFIFO,0,0,&j1);	
	}
	
	}
return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::FPGA_stop(){


if(sprunning==true){
	NiFpga_SetStatus(&status, MNiFpga_StopFifo(*session0, NiFpga_target_main_001_TargetToHostFifoU32_FIFO));
	if(status!=0){System::Console::Write("STOP Fifo 2: ERR\n");}
	else{System::Console::Write("STOP Fifo 2: OK\n"); ni_DLL=NULL;}

	NiFpga_SetStatus(&status, MNiFpga_StopFifo(*session0,NiFpga_target_main_001_TargetToHostFifoU64_FIFO2));
	if(status!=0){System::Console::Write("STOP Fifo 3: ERR\n");}
	else{System::Console::Write("STOP Fifo 2: OK\n"); ni_DLL=NULL;}
}

MN_NiFpga_Abort(*session0);
MN_NiFpga_Reset(*session0);
FPGA_close();
delete session0;
status=0;
if(FreeLibrary(GetModuleHandle("NiFpga.dll"))==0)System::Console::Write("Free Library: ERR\n");
else System::Console::Write("Free Library: OK\n");
sprunning=false;
return 0;
}

//*********************************************************************************************************************
double FPGA_target_class::get_tau(unsigned int i){
return 1000000*tau[i];
}

//*********************************************************************************************************************


double FPGA_target_class::get_gxx(unsigned int j, unsigned int i){

	if(T[i]>0){
		double g=(double) Gxx[j][i]/((double)T[j][i]);
		double mt=(double) Mx[j][i]/((double)T[j][i]);
		unsigned int k=(i)/9;

		double m0=(double) Mx0[j][k]/((double)T[j][i]);
		return ((g/(m0*mt))-1.0);
		}
	else{
	return 1.1;
	}
}


//*********************************************************************************************************************

double FPGA_target_class::get_gyy(unsigned int j, unsigned int i){

	if(T[i]>0){
		double g=(double) Gyy[j][i]/((double)T[j][i]);
		double mt=(double) My[j][i]/((double)T[j][i]);
		unsigned int k=(i)/9;
		double m0=(double) My0[j][k]/((double)T[j][i]);
		return ((g/(m0*mt))-1.0);
		}
	else{
	return 1.1;
	}
}


//*********************************************************************************************************************

double FPGA_target_class::get_gxy(unsigned int j, unsigned int i){

	if(T[i]>0){
		double g=(double) Gxy[j][i]/((double)T[j][i]);		
		double mt=(double) My[j][i]/((double)T[j][i]);

		unsigned int k=(i)/9;
		double m0=(double) Mx0[j][k]/((double)T[j][i]);

		return ((g/(m0*mt))-1.0);
		}
	else{
	return 1.1;
	}
}

//*********************************************************************************************************************

double FPGA_target_class::get_gyx(unsigned int j,unsigned int i){

	if(T[i]>0){
		double g=(double) Gyx[j][i]/((double)T[j][i]);
		double mt=(double) Mx[j][i]/((double)T[j][i]);
		unsigned int k=(i)/9;
		double m0=(double) My0[j][k]/((double)T[j][i]);
		return ((g/(m0*mt))-1.0);
		}
	else{
	return 1.1;
	}
}

//*********************************************************************************************************************

int FPGA_target_class::FPGA_Run(){

sprunning=true;
NiFpga_SetStatus(&status,MNiFpga_StartFifo(*session0, NiFpga_target_main_001_TargetToHostFifoU32_FIFO));
if(status!=0){
	System::Console::Write("FPGA FIFO 1 start: ERR\n"); 
	FPGA_stop();
	return -3;	
}
else{ System::Console::Write("FPGA FIFO 1 start: OK\n"); }


NiFpga_SetStatus(&status,MNiFpga_StartFifo(*session0,NiFpga_target_main_001_TargetToHostFifoU64_FIFO2));
if(status!=0){
	System::Console::Write("FPGA FIFO 2 start: ERR\n"); 
	FPGA_stop();
	return -3;	
}
else{ System::Console::Write("FPGA FIFO 2 start: OK\n"); }


NiFpga_SetStatus(&status, MNiFpga_Run(*session0, 0));
if(status!=0){
	System::Console::Write("FPGA Run: ERR\n"); 
	FPGA_stop();
	return -3;	
}
else{ System::Console::Write("FPGA Run: OK\n"); }

return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::set_Gxx(double Gxx0,unsigned int ind_0){
	if(ind_0 < 1000){ Gxx[RUN][ind_0]+=Gxx0; return 0;}
	else{System::Console::Write("param: ERR\n"); return -1;}
	return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::set_Gyy(double Gyy0,unsigned int ind_0){
	if(ind_0 < 1000){ Gyy[RUN][ind_0]+=Gyy0;return 0;}
	else{System::Console::Write("param: ERR\n"); return -1;}
	return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::set_Gxy(double Gxy0,unsigned int ind_0){
	if(ind_0 < 1000){ Gxy[RUN][ind_0]+=Gxy0; return 0; }
	else{System::Console::Write("param: ERR\n"); return -1;}
	return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::set_Gyx(double Gyx0,unsigned int ind_0){
	if(ind_0 < 1000){ Gyx[RUN][ind_0]+=Gyx0; return 0; }
	else{System::Console::Write("param: ERR\n"); return -1;}
	return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::set_Mx(double Mxi,unsigned int ind_0){

	if((ind_0+1)%9==0 || ind_0==0 ){
	unsigned int k=(ind_0)/9;
	Mx0[RUN][k]+=Mxi;
	}
	else{
		if(ind_0 < 1000){ Mx[RUN][ind_0]+=Mxi; return 0; }
		else{System::Console::Write("param: ERR\n"); return -1;}
	}
	return 0;
}
//*********************************************************************************************************************

int FPGA_target_class::set_My(double Myi,unsigned int ind_0){

if((ind_0+1)%9==0 || ind_0==0 ){
	unsigned int k=(ind_0)/9;
	My0[RUN][k]+=Myi;
	}
	else{
	if(ind_0 < 1000){ My[RUN][ind_0]+=Myi; return 0; }
	else{System::Console::Write("param: ERR\n"); return -1;}
	}
	return 0;
}
//*********************************************************************************************************************

int FPGA_target_class::set_T(double T0,unsigned int ind_0){
	if(ind_0 < 1000){ T[RUN][ind_0]+=T0; return 0; }
	else{System::Console::Write("param: ERR\n"); return -1;}
	return 0;
	}
//*********************************************************************************************************************

int FPGA_target_class::set_RUN(unsigned int RUN_0){
RUN=RUN_0;
return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::data_reset(){
unsigned int i,j;
j=0;
while(j<100){
	i=0;
	while(i<1000){
		Gxx[j][i]=Mx[j][i]=T[j][i]=0.0;
		Gyy[j][i]=My[j][i]=0.0;
		Gxy[j][i]=Gyx[j][i]=0.0;		
		Mx0[j][i]=My0[j][i]=0.0;
		i++;
		}	
	j++;
}

return 0;
}

//*********************************************************************************************************************

int FPGA_target_class::write_res_tofile(){

FILE *out_0,*out_1,*out_2,*out_3;
if(ACF0==true )
	{
	out_0=fopen(fname_0,"w+");
	if(out_0==NULL){return -1;  }
}
if(ACF1==true ){
	out_1=fopen(fname_1,"w+");
	if(out_1==NULL){ return -1; }
}
if(CCF01==true){
	out_2=fopen(fname_2,"w+");
	if(out_2==NULL){ return -1; }
}
if(CCF10==true){
	out_3=fopen(fname_3,"w+");
	if(out_3==NULL){ return -1; }

}

unsigned int i,j,l;
i=0;
l=1;
while(i<176){
	if((i+1)%9!=0 && i!=0)
		{
		j=0;	
		unsigned int k=0;
		while(j< RUN_MAX)
			{
				if(T[j][i]==0)k++;
				j++;
			}
		if(k==0)
			{
			j=0;
			if(ACF0==true){fprintf(out_0,"%.9lf",tau[l]/1000);}
			if(ACF1==true){fprintf(out_1,"%.9lf",tau[l]/1000);}
			if(CCF01==true){fprintf(out_2,"%.9lf",tau[l]/1000);}
			if(CCF10==true){fprintf(out_3,"%.9lf",tau[l]/1000);}
			l++;
			while(j< RUN)
				{
					if(ACF0==true){fprintf(out_0,", %.9f",get_gxx(j,i));}
					if(ACF1==true){fprintf(out_1,", %.9f",get_gyy(j,i));}
					if(CCF01==true){fprintf(out_2,", %.9f",get_gxy(j,i));}
					if(CCF10==true){fprintf(out_3,", %.9f",get_gyx(j,i));}
				j++;
				}
			if(ACF0==true){fprintf(out_0,"\n");}
			if(ACF1==true){fprintf(out_1,"\n");}
			if(CCF01==true){fprintf(out_2,"\n");}
			if(CCF10==true){fprintf(out_3,"\n");}
			}
	}
	i++;
	}
if(ACF0==true){fclose(out_0);}
if(ACF1==true){fclose(out_1);}
if(CCF01==true){fclose(out_2);}
if(CCF10==true){fclose(out_3);}

MoveFile("temp0000",fname_RAW);

return 0;
}

//*********************************************************************************************************************