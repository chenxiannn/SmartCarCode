/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_SpeedL.h
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

#ifndef  __EIT_CONTROL_SPEEDL_H__
#define  __EIT_CONTROL_SPEEDL_H__

#include "EIT_PID.h"
#include "EIT_MotorL.h"
#define MAX_L_PWM          900
extern PID MotorL_PID;
extern void MotorLPID_Init(void);
extern void MotorLPID_InitParam(void);
extern void MotorLPID_InitState(int32 I);
extern void MotorLPID_SetSpeed(int32 spSpeed);
extern void MotorLPID_SpeedControl(void);

#endif
