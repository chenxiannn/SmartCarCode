/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_MotorR.h
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
 * 2015-01-24     Xian.Chen    the first version
 *
 *******************************************************************************
 */

#ifndef __EIT_MOTORR_DEF__
#define __EIT_MOTORR_DEF__
#include "include.h"
/*Motor Driver*/
#define    MOTORR_PWM_MAX   1000
#define    MOTORR_PWM_MIN   (-1000)
#define    MOTORR_PWM_FREQ  15000
#define    MOTORR_FTM    FTM0
#define    MOTORR_EN     PTA24
#define    MOTORR_PWMA   FTM_CH3
#define    MOTORR_PWMB   FTM_CH4
#define    MOTORR_PWMAIO PTA6
#define    MOTORR_PWMBIO PTA7


/*Encode */
#define    MOTORR_ENCODE_FTM             FTM2                                       //左编码器用FTM1
#define    MOTORR_GEAR_N                 36                                        //B车电机自带齿轮齿轮数
#define    ENCODR_GEAR_N                 40                                      //B车主动轴齿轮齿轮数
#define    WHEELR_GEAR_N                 105  
#define    ENCODR_CYCLE                  2000 //One Cycle
#define    WHEELR_LENGTH                 18  //17.8cm

#define    SPEEDR_FS                     100 //Hz

extern void MotorR_Init(void);
extern void MotorR_Run(int32 pwm);
extern void MotorR_Brake(void);
extern void MotorR_Slip(void);

extern int32 MotorR_GetWheelSpeed(int32 CntInTs);
extern int32 MotorR_GetTsCount(void);

#endif