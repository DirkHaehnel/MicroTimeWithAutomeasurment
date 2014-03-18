#pragma once
//#include "c:\program files (x86)\national instruments\shared\externalcompilersupport\include\nidaqmx.h"
#include "c:\Program Files\National Instruments\Shared\externalcompilersupport\C\include\nidaqmx.h"
#include<windows.h>
class forward_task
{
public:
	forward_task(void);
	~forward_task(void);
	TaskHandle  taskHandle;
	HANDLE consH;
	char *dev;
	char *outpterm;
	char *triggerterm;
	int init();
	int start();
	int stop();
	int clear();
	int32 error;
};

