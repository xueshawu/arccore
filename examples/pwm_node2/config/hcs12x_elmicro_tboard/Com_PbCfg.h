/*
* Configuration of module: Com (Com_PbCfg.h)
*
* Created by:              Arccore AB
* Copyright:               
*
* Configured for (MCU):    HCS12
*
* Module vendor:           ArcCore
* Generator version:       2.0.5
*
* Generated by Arctic Studio (http://arccore.com) 
*           on Thu Mar 10 14:35:00 CET 2011
*/


#if !(((COM_SW_MAJOR_VERSION == 1) && (COM_SW_MINOR_VERSION == 1)) )
#error Com: Configuration file expected BSW module version to be 1.1.*
#endif

#ifndef COM_PBCFG_H
#define COM_PBCFG_H

#include "Com_Types.h"

extern const Com_ConfigType ComConfiguration;

//  COM Polite Defines.
#define COM_PDU_ID_LedCommandRx		0



// PDU group definitions
#define RxGroup 0


// Signal definitions
#define SetLedLevelRx 0




#endif /* COM_PBCFG_H */
