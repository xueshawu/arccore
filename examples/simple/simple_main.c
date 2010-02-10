/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/


#include "Os.h"
#include "Mcu.h"

#define USE_DEBUG
#include "Trace.h"

// How many errors to keep in error log.
#define ERROR_LOG_SIZE 20


/**
 * Just an example of a basic task.
 */

void btask_3( void ) {
	StackInfoType si;
	TaskType currTask;
	dbg_printf("[%08d] btask_3 start\n", GetOsTick() );

	GetTaskID(&currTask);
	Os_GetStackInfo(currTask,&si);
	dbg_printf("btask_3: Stack usage %d%%\n",OS_STACK_USAGE(&si));

	TerminateTask();
}

/**
 * An extended task is auto-started and is also triggered by an alarm
 * that sets event 2.
 */

void etask_1( void ) {
	volatile float tryFloatingPoint = 0.0F;
	StackInfoType si;
	TaskType currTask;


	dbg_printf("etask_1 start\n");
	for(;;) {
		SetEvent(TASK_ID_etask_2,1);
		WaitEvent(2);
		ClearEvent(2);
		tryFloatingPoint += 1.0F;
		GetTaskID(&currTask);
		Os_GetStackInfo(currTask,&si);
		dbg_printf("etask_1: Stack usage %d%% \n",OS_STACK_USAGE(&si));

	}
}

/**
 * An extended task that receives events from someone
 * and activates task: btask_3.
 */
void etask_2( void ) {
	dbg_printf("etask_2 start\n");

	for(;;) {
		WaitEvent(1);
		ClearEvent(1);
		ActivateTask(TASK_ID_btask_3);
		{
			StackInfoType si;
			TaskType currTask;
			GetTaskID(&currTask);
			Os_GetStackInfo(currTask,&si);
			dbg_printf("etask_1: Stack usage %d%% \n",OS_STACK_USAGE(&si));
		}
	}
}


/*
 * Functions that must be supplied by the example
 */

void OsIdle( void ) {
	for(;;);
}


/* Global hooks */
ProtectionReturnType ProtectionHook( StatusType FatalError ) {
	dbg_printf("## ProtectionHook\n");
	return PRO_KILLAPPL;
}

void StartupHook( void ) {
	uint32_t sys_freq = McuE_GetSystemClock();

	dbg_printf("## StartupHook\n");

	dbg_printf("Sys clock %d Hz\n",sys_freq);
}

void ShutdownHook( StatusType Error ) {
	dbg_printf("## ShutdownHook\n");
	while(1);
}

struct LogBad_s {
	uint32_t param1;
	uint32_t param2;
	uint32_t param3;
	TaskType taskId;
	OsServiceIdType serviceId;
	StatusType error;
};

void ErrorHook( StatusType Error ) {

	TaskType task;
	static struct LogBad_s LogBad[ERROR_LOG_SIZE];
	static uint8_t ErrorCount = 0;

	GetTaskID(&task);


	OsServiceIdType service = OSErrorGetServiceId();

	/* Grab the arguments to the functions
	 * This is the standard way, see 11.2 in OSEK spec
	 */
	switch(service) {
	case OSServiceId_SetRelAlarm:
	{
		// Read the arguments to the faulty functions...
		/* (Commented to remove warnings)
		AlarmType alarm_id = OSError_SetRelAlarm_AlarmId;
		TickType increment = OSError_SetRelAlarm_Increment;
		TickType cycle = OSError_SetRelAlarm_Cycle;	*/
		// ... Handle this some way.
		break;
	}
	/*
	 * The same pattern as above applies for all other OS functions.
	 * See Os.h for names and definitions.
	 */

	default:
		break;
	}

	dbg_printf("## ErrorHook err=%d\n",Error);

	/* Log the errors in a buffer for later review */
	LogBad[ErrorCount].param1 = os_error.param1;
	LogBad[ErrorCount].param2 = os_error.param2;
	LogBad[ErrorCount].param3 = os_error.param3;
	LogBad[ErrorCount].serviceId = service;
	LogBad[ErrorCount].taskId = task;
	LogBad[ErrorCount].error = Error;

	ErrorCount++;

	// Stall if buffer is full.
	while(ErrorCount >= ERROR_LOG_SIZE);
}

void PreTaskHook( void ) {
	TaskType task;
	GetTaskID(&task);
//	dbg_printf("## PreTaskHook, taskid=%d\n",task);
}

void PostTaskHook( void ) {
	TaskType task;
	GetTaskID(&task);
//	dbg_printf("## PostTaskHook, taskid=%d\n",task);
}
