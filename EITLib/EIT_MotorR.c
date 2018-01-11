/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_MotorR.c
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

#include "EIT_MotorR.h"

void MotorR_Init(void)
{
   /*Motor Drive*/
   gpio_init (MOTORR_EN, GPO,0);
   //port_init(MOTORR_PWMAIO, PULLUP );
   //port_init(MOTORR_PWMBIO, PULLUP );
   FTM_PWM_init(MOTORR_FTM, MOTORR_PWMA, MOTORR_PWM_FREQ,0);
   FTM_PWM_init(MOTORR_FTM, MOTORR_PWMB, MOTORR_PWM_FREQ,0);
   
   /*Speed Measure*/
   FTM_QUAD_Init(MOTORR_ENCODE_FTM);
}

void MotorR_Run(int32 pwm)
{
   uint32 PWM_A =0;
   uint32 PWM_B =0;
   
   if(pwm>MOTORR_PWM_MAX)
       pwm=MOTORR_PWM_MAX;
   else if(pwm<MOTORR_PWM_MIN)
       pwm=MOTORR_PWM_MIN;
   
   if ( pwm >0 )
   {
      PWM_A = pwm;
   }
   else if ( pwm <0 )
   {
      PWM_B = -pwm;
   }
   FTM_PWM_Duty(MOTORR_FTM, MOTORR_PWMA,PWM_A);
   FTM_PWM_Duty(MOTORR_FTM, MOTORR_PWMB,PWM_B);
   gpio_set ( MOTORR_EN,1);
}
void MotorR_Brake(void)
{   
   FTM_PWM_Duty(MOTORR_FTM, MOTORR_PWMA,0);
   FTM_PWM_Duty(MOTORR_FTM, MOTORR_PWMB,0);
   gpio_set  ( MOTORR_EN,1);
}
void MotorR_Slip(void)
{
   gpio_set  (MOTORR_EN,0);
   FTM_PWM_Duty(MOTORR_FTM, MOTORR_PWMA,0);
   FTM_PWM_Duty(MOTORR_FTM, MOTORR_PWMB,0);
}

int32 MotorR_GetWheelSpeed(int32 CntInTs)
{
      int32 speed=0;
      speed = (int32)(CntInTs*ENCODR_GEAR_N*WHEELR_LENGTH*SPEEDR_FS/ENCODR_CYCLE/WHEELR_GEAR_N);
      return speed;
}

int32 MotorR_GetTsCount(void)
{
      int32 val;
      val = FTM_QUAD_get(MOTORR_ENCODE_FTM);
      FTM_QUAD_clean(MOTORR_ENCODE_FTM);
      return val;
}
