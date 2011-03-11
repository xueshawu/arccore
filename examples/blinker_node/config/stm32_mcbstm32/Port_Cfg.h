/*
 * Configuration of module Port (Port_Cfg.h)
 *
 * Created by: 
 * Configured for (MCU): STM32_F103
 *
 * Module vendor: ArcCore
 * Module version: 2.0.2
 *
 * 
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Wed Jan 26 12:28:57 CET 2011
 */


#if !(((PORT_SW_MAJOR_VERSION == 1) && (PORT_SW_MINOR_VERSION == 0)) )
#error "Port: Configuration file version differs from BSW version."
#endif


#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#include "Std_Types.h"
#include "Port_ConfigTypes.h"

#define	PORT_VERSION_INFO_API				STD_ON
#define	PORT_DEV_ERROR_DETECT				STD_ON
#define PORT_SET_PIN_DIRECTION_API	        STD_OFF

/** Instance of the top level configuration container */
extern const Port_ConfigType PortConfigData;

#endif /* PORT_CFG_H_ */
