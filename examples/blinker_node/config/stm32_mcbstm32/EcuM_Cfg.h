/*
 * Configuration of module EcuM (EcuM_Cfg.h)
 *
 * Created by: 
 * Configured for (MCU): STM32_F103
 *
 * Module vendor: ArcCore
 * Module version: 2.0.1
 *
 * 
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Wed Jan 26 12:28:57 CET 2011
 */


#if !(((ECUM_SW_MAJOR_VERSION == 2) && (ECUM_SW_MINOR_VERSION == 0)) )
#error "EcuM: Configuration file version differs from BSW version."
#endif



#ifndef ECUM_CFG_H_
#define ECUM_CFG_H_

#define ECUM_VERSION_INFO_API	STD_ON
#define ECUM_DEV_ERROR_DETECT	STD_ON

#include "EcuM_Generated_Types.h"

#define ECUM_MAIN_FUNCTION_PERIOD  (200)
#define ECUM_NVRAM_READALL_TIMEOUT (10000)
#define ECUM_NVRAM_WRITEALL_TIMEOUT (10000)
#define ECUM_NVRAM_MIN_RUN_DURATION (10000)

// EcuM_UserType definitions
typedef enum {
    ECUM_USER_SYSTEM,   // Dummy user to get at least one user in system
	ECUM_USER_ENDMARK	// Must be the last in list!
} EcuM_UserList;

extern EcuM_ConfigType EcuMConfig;

#endif /*ECUM_CFG_H_*/
