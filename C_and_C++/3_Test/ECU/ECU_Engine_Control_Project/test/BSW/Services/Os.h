#ifndef  __OS_H__
#define  __OS_H__

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void Os_Init(void);

void Os_CreateTask(void* (*function)(void*), const char* taskName);

void Os_Delay(int miliTime);

void Os_Shutdown(void);


#endif