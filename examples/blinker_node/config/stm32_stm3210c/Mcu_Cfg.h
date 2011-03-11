/*
 * Configuration of module Mcu (Mcu_Cfg.h)
 *
 * Created by: 
 * Configured for (MCU): STM32_F107
 *
 * Module vendor: ArcCore
 * Module version: 2.0.2
 *
 * 
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Fri Jan 21 11:32:26 CET 2011
 */


#if !(((MCU_SW_MAJOR_VERSION == 2) && (MCU_SW_MINOR_VERSION == 0)) )
#error "Mcu: Configuration file version differs from BSW version."
#endif


#ifndef MCU_CFG_H_
#define MCU_CFG_H_

#include "Std_Types.h"
#include "Mcu_ConfigTypes.h"

#define MCU_DEV_ERROR_DETECT 	STD_OFF 
#define MCU_PERFORM_RESET_API 	STD_ON
#define MCU_VERSION_INFO_API 	STD_ON

typedef enum {
	MCU_CLOCKTYPE_EXT_REF_25MHZ = 0,
  MCU_NBR_OF_CLOCKS,
} Mcu_ClockType;

#define MCU_DEFAULT_CONFIG McuConfigData[0]

#endif /*MCU_CFG_H_*/
