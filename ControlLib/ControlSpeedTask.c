/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : ControlSpeedTask.c
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
#include "include.h"

static int32 int_abs(int32 d)
{
   if (d<0)
      return -d;
   else
     return d;
}

static int32 GetCarSpeed(int32 RSpeed,int32 LSpeed)
{
    int32 CarSpeed;
    int R;
    
    R=1852/(int_abs(angle)+15);
    if(angle>1)
    {
       CarSpeed=gVar.MotorR_Speed*(R+gParam.BackLength/2)/R;
    }
    else if(angle<-1)
    {
       CarSpeed=gVar.MotorR_Speed*(R+gParam.BackLength/2)/(R+gParam.BackLength);
    }
    else
    {
       CarSpeed=RSpeed;
    }

    return CarSpeed;
}

int32 CarSpeed2RSpeed(int32 CarSpeed,int angle)
{
    int32 RSpeed;
    int R;
    
    R=1852/(int_abs(angle)+15);
    if(angle>1)//œÚ”“
    {
       RSpeed=CarSpeed*R/(R+gParam.BackLength/2);
    }
    else if(angle<-1)//œÚ◊Û
    {
       RSpeed=CarSpeed*(R+gParam.BackLength)/(R+gParam.BackLength/2);
    }
    else
    {
       RSpeed=CarSpeed;
    }
    
    return RSpeed;
}

void ControlSpeedTask(void)
{

      gVar.MotorR_CntInTs = MotorR_GetTsCount();
      gVar.MotorR_Speed   = MotorR_GetWheelSpeed(gVar.MotorR_CntInTs);
      
      PID_SetFbVal(&MotorR_PID,gVar.MotorR_Speed);
      gVar.MotorR_Current=(MotorR_PID.outVal-MotorR_PID.fbValFilter/2)/30;
      
      if(MotorR_PID.fbValFilter<50 && MotorR_PID.fbValFilter>=-50 )   
      {
          gParam.MaxCurrent=15;
          gVar.MotorR_CurrentInt=0;
          MotorR_PID.I=0;
      }
      else
      {
          gParam.MaxCurrent=30;
          gVar.MotorR_CurrentInt=0;
      }
      MotorR_PID.MAX_Val=(MotorR_PID.fbValFilter/2+gParam.MaxCurrent*30);
      gVar.Car_Speed=GetCarSpeed(MotorR_PID.fbValFilter,MotorL_PID.fbValFilter);
      MotorRPID_SpeedControl();

}



