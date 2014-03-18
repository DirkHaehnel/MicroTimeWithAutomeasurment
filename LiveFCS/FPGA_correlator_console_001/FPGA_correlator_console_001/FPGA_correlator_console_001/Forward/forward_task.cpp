#include "stdAfx.h"

#include "forward_task.h"

forward_task::forward_task(void)
{
  consH=GetStdHandle(STD_OUTPUT_HANDLE);
  if(consH==NULL){AllocConsole(); consH=GetStdHandle(STD_OUTPUT_HANDLE);}
}

forward_task::~forward_task(void)
{
}

int forward_task::init(){

	error=0;

	DAQmxErrChk (DAQmxCreateTask("",&taskHandle));

	DAQmxErrChk (DAQmxCreateCOPulseChanTime(taskHandle,dev,"",DAQmx_Val_Seconds,DAQmx_Val_Low,0,0.00000005,0.00000005));
	//DAQmxErrChk (DAQmxCreateCOPulseChanTime(taskHandle,dev,"",DAQmx_Val_Seconds,DAQmx_Val_Low,0,0.0000025,0.000005));

	DAQmxCfgImplicitTiming(taskHandle,DAQmx_Val_FiniteSamps  ,1);	

	DAQmxSetStartTrigRetriggerable(taskHandle,1);

	DAQmxErrChk (DAQmxCfgDigEdgeStartTrig(taskHandle,triggerterm,DAQmx_Val_Rising));

	DAQmxSetCOPulseTerm(taskHandle,dev,outpterm);	
	return 0;
	Error:
	char        errBuff[2048]={'\0'};
	if( DAQmxFailed(error) ) DAQmxGetExtendedErrorInfo(errBuff,2048);	
	if( DAQmxFailed(error) ){} ;



	return -1;
}

int forward_task::start(){
	if(init()!=0){
		System::Console::Write("Forward init: ERR\n");
	}
	else{		
		System::Console::Write("Forward init: OK\n");
	}
DAQmxErrChk (DAQmxStartTask(taskHandle));
return 0;
Error:
	char        errBuff[2048]={'\0'};
	if( DAQmxFailed(error) ) DAQmxGetExtendedErrorInfo(errBuff,2048);	
	if( DAQmxFailed(error) ){}  ;
return -1;
}


int forward_task::stop(){
DAQmxStopTask(taskHandle);
return 0;
}


int forward_task::clear(){
DAQmxClearTask(taskHandle);
return 0;
}