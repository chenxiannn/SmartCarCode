/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : ControlSpeedL.h
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

#ifndef  __EIT_CONTROL_SPEEDR_H__
#define  __EIT_CONTROL_SPEEDR_H__
#include "EIT_PID.h"
#include "EIT_MotorR.h"
#define MAX_R_PWM        900
extern  PID MotorR_PID;
extern void MotorRPID_Init(void);
extern void MotorRPID_InitParam(void);
extern void MotorRPID_InitState(int32 I);
extern void MotorRPID_SetSpeed(int32 spSpeed);
extern void MotorRPID_SpeedControl(void);

#endif
