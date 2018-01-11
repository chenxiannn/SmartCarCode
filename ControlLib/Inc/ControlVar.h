/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : ControlParam.h
 * This file is part of EIT Car Project
 * Embedded Innovation Team(EIT) - Car@EIT  
 * ----------------------------------------------------------------------------
 * LICENSING TERMS:
 * 
 *     CarLib is provided in source form for FREE evaluation and  educational 
 * use.
 *    If you plan on using  EITLib  in a commercial product you need to contact 
 * Car@EIT to properly license its use in your product. 
 * 
 * ----------------------------------------------------------------------------
 * Change Logs:
 * Date           Author       Notes
 * 2015-02-08     Xian.Chen    the first version
 *
 *******************************************************************************
 */

#ifndef  __EIT_CONTROL_VAR_H__
#define  __EIT_CONTROL_VAR_H__
#include "ControlType.h"
typedef  struct
{
	/*Left Motor*/	
        cint32   MotorL_CntInTs;
        cint32   MotorL_Speed;
	/*Right Motor*/	
        cint32   MotorR_CntInTs;
        cint32   MotorR_Speed;
        
        cint32   Car_Speed;
        /*Time Cnt*/
        cint32   time;
        
        cint32   MotorR_Current;
        cint32   MotorR_CurrentInt;
        cint32   InAngle;
	
}EIT_VAR;
extern EIT_VAR gVar;
extern void ControlVar_Init(void);
#endif