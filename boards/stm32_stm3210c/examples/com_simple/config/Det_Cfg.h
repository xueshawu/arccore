/*
* Configuration of module: Det (Det_Cfg.h)
*
* Created by:              
* Copyright:               
*
* Configured for (MCU):    STM32_F107
*
* Module vendor:           ArcCore
* Generator version:       2.0.1
*
* Generated by Arctic Studio (http://arccore.com) 
*/


#if !(((DET_SW_MAJOR_VERSION == 1) && (DET_SW_MINOR_VERSION == 0)) )
#error Det: Configuration file expected BSW module version to be 1.0.*
#endif

/*
 * Development Error Tracer driver
 *
 * Specification: Autosar v2.0.1, Final
 *
 */
#ifndef DET_CFG_H
#define DET_CFG_H 

#define DET_ENABLE_CALLBACKS STD_OFF // Enable to use callback on errors
#define DET_USE_RAMLOG       STD_ON  // Enable to log DET errors to ramlog
#define DET_WRAP_RAMLOG      STD_ON  // The ramlog wraps around when reaching the end
#define DET_USE_STDERR       STD_OFF // Enable to get DET errors on stderr
#define DET_DEINIT_API       STD_OFF // Enable/Disable the Det_DeInit function
#define DET_RAMLOG_SIZE         (16)  // Number of entries in ramlog
#define DET_NUMBER_OF_CALLBACKS (5)  // Number of callbacks

#endif /* DET_CFG_H */
