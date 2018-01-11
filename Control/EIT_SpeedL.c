/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_SpeedL.c
 * This file is part of EIT Car Project
 * Embedded Innovation Team(EIT) - 
 * Website:http://www.mizhiquan.com
 * ----------------------------------------------------------------------------
 * LICENSING TERMS:
 * 
 *     The Code is provided in source form for FREE evaluation and  educational 
 * use.
 * 
 * ----------------------------------------------------------------------------
 * Change Logs:
 * Date           Author       Notes
 * 2016-02-08     Xian.Chen    the first version
 * 2016-07-08     Xian.Chen    update
 *
 *******************************************************************************
 */

#include "EIT_SpeedL.h"
PID MotorL_PID;
void MotorLPID_Init(void)
{
    MotorLPID_InitParam();
    MotorLPID_InitState(0);
    MotorLPID_SetSpeed( 0);
    PID_InitFbVal(&MotorL_PID,0);
}
void MotorLPID_InitParam(void)
{
	MotorL_PID.Kp = gParam.MotorL_PID_KP;
        MotorL_PID.Ki = gParam.MotorL_PID_KI*gParam.MotorL_PID_Ts;
	MotorL_PID.Kd = -gParam.MotorL_PID_KD/gParam.MotorL_PID_Ts;
	MotorL_PID.MAX_Val = MOTORL_PWM_MAX;
	MotorL_PID.MIN_Val = MOTORL_PWM_MIN;	
}
void MotorLPID_InitState(int32 I)
{
	MotorL_PID.I = I;
}
void MotorLPID_SetSpeed( int32 spSpeed)
{
	MotorL_PID.spVal = spSpeed;
}
void MotorLPID_SpeedControl(void)
{
	
    PID_Run_PID(&MotorL_PID);
    MotorL_Run(MotorL_PID.outVal);
}

