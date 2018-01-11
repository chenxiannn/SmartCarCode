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

#ifndef  __EIT_CONTROL_PARAM_H__
#define  __EIT_CONTROL_PARAM_H__
#include "ControlType.h"

#define MOTOR_PID_TS 0.01
typedef  struct
{
	/*Left Motor*/	
	float   MotorL_PID_KP;	
	float   MotorL_PID_KI;	
	float   MotorL_PID_KD; 
	float   MotorL_PID_Ts; /*Unit: s   */
	cint32   MotorL_PWM_Max;
	cint32   MotorL_PWM_Min;
	
	/*Right Motor*/	
	float   MotorR_PID_KP;	
	float   MotorR_PID_KI;	
	float   MotorR_PID_KD; 
	float   MotorR_PID_Ts; /*Unit: s   */
    cint32   MOtroR_PID_UpRate;
    cint32   MOtroR_PID_DnRate;
	cint32   MotorR_PWM_Max;
	cint32   MotorR_PWM_Min;
        
    /*Max Speed*/
	cint32   MaxSpeed;
    cint32   MinSpeed;
    float    DecSpeedK;
    float    LRSpeedK;
    /*Dir Control*/
    float   DIR_Kp;
    float   DIR_KpInAngle;
    float   DIR_Kd;
    cint32  DIR_Dead;
    
    cint32 NearDirDeltaMax;
    cint32 FarDirDeltaMax;
    cint32 AngleDeltaMax;
    

    cint32 SteerMid;
    cint32 SteerDeltaMax;
    cint32 AngleMax;
    /*Dir Calculate*/
    cint32 NearStart;
    cint32 NearLen;
    
    cint32 MidStart;
    cint32 MidLen;
    float MidDirSpeedK;
    
    cint32 FarStart;
    cint32 FarLen;
    
    cint32 MaxCurrent;
    cint32 MaxCurrentInt;
    
    //∫Û÷·≥§∂»
    cint32 BackLength;
    cint32 InAngle_FarDir;
    cint32 OutAngle_FarDir;
}EIT_PARAM;
extern EIT_PARAM gParam;
extern void ControlParam_Init(void);
#endif
