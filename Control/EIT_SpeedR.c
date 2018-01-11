/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_SpeedR.c
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

#include "EIT_SpeedR.h"

PID MotorR_PID;
void MotorRPID_Init(void)
{
    MotorRPID_InitParam();
    MotorRPID_InitState(0);
    MotorRPID_SetSpeed(0);
    PID_InitFbVal(&MotorR_PID,0);
}
void MotorRPID_InitParam(void)
{
	MotorR_PID.Kp = gParam.MotorR_PID_KP;
    MotorR_PID.Ki = gParam.MotorR_PID_KI*gParam.MotorR_PID_Ts;
	MotorR_PID.Kd = -gParam.MotorR_PID_KD/gParam.MotorR_PID_Ts;
	MotorR_PID.MAX_Val = MOTORR_PWM_MAX;
	MotorR_PID.MIN_Val = MOTORR_PWM_MIN;	
    MotorR_PID.spUpRate=(int32)(gParam.MOtroR_PID_UpRate*gParam.MotorR_PID_Ts);
    MotorR_PID.spDnRate=(int32)(gParam.MOtroR_PID_DnRate*gParam.MotorR_PID_Ts);
}
void MotorRPID_InitState(int32 I)
{
	MotorR_PID.I = I;
    MotorR_PID.spValRamp=0;
}
void MotorRPID_SetSpeed( int32 spSpeed)
{
	MotorR_PID.spVal = spSpeed;
}
void MotorRPID_SpeedControl(void)
{
	PID_Run_PID(&MotorR_PID);
        //MotorR_PID.outVal=400;
	MotorR_Run(MotorR_PID.outVal);
}
