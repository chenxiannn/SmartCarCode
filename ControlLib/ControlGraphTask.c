/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : ControlGraphTask.c
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


#include "ControlTask.h"
int angleLast=0;
int angle=0;
int spSpeedL;
int spSpeedR;
int gDir_NearLast=0;
int gDir_MidLast=0;
int gDir_FarLast=0;

int gDir_MidFilter=0;
int gDir_MidFilterLast=0;
int gDir_MidFilterDiff=0;

int gDir_FarFilter=0;
int gDir_FarFilterLast=0;
int gDir_FarFilterDiff=0;

int gDir_FarFilterSlow=0;
int gDir_FarFilterSlowLast=0;
int gDir_FarFilterSlowDiff=0;

void GetSetPointMaxSpeed(void);
void gDir_Filter(void);
void ControlGraphTask(void)
{
    Graph_FindMidLine();
    Graph_Calculate_Dir(gVar.Car_Speed);  
    gDir_Filter();
    SteerDirControl();
    GetSetPointMaxSpeed();
}
static int32 int_abs(int32 d)
{
   if (d<0)
      return -d;
   else
     return d;
}
static int32 int_delta_Limit(int32 x,int32 xLast,int32 deltaMax)
{
    if( x - xLast > deltaMax)
       x=xLast+deltaMax;
    else if(  xLast-x > deltaMax)
       x=xLast-deltaMax;
    
    return x;
}

void GetSetPointMaxSpeed(void)
{
    int MidSpeed;
    
    if( gVar.InAngle)
    {
        MidSpeed = gParam.MinSpeed;
    }
    else
    {
        MidSpeed =gParam.MaxSpeed;
        
    }
    //spSpeedL = CarSpeed2LSpeed(MidSpeed,angle);;
    spSpeedR = CarSpeed2RSpeed(MidSpeed,angle);
    
    //MotorLPID_SetSpeed(spSpeedL);
    MotorRPID_SetSpeed(spSpeedR);
}
void SteerDirControl(void)
{   
    int MidDir;
    
    MidDir=gDir_Mid;
    if(int_abs(MidDir)>=gParam.DIR_Dead)
    {
        if(MidDir>0)
           MidDir-=gParam.DIR_Dead;
        else
           MidDir+=gParam.DIR_Dead;
    }
    else
    {
        MidDir=0;
    }
    
    if(gVar.InAngle)
       angle =(int32)((float)(MidDir)*gParam.DIR_KpInAngle+ (float)(gDir_MidFilterDiff)*gParam.DIR_Kd);
    else
       angle =(int32)((float)(MidDir)*gParam.DIR_Kp+ (float)(gDir_MidFilterDiff)*gParam.DIR_Kd);
    
    if (angle >gParam.AngleMax)
       angle =gParam.AngleMax;
    else if (angle <-gParam.AngleMax)
       angle =-gParam.AngleMax;
    angle=int_delta_Limit(angle,angleLast, gParam.AngleDeltaMax);
    angleLast=angle;
    Steer_Run(gParam.SteerMid,angle*gParam.SteerDeltaMax/gParam.AngleMax);
}

void gDir_Filter(void)
{
   static int MidDir[5];
   static int FarDir[15];
   
   MidDir[4]=MidDir[3];
   MidDir[3]=MidDir[2];
   MidDir[2]=MidDir[1];
   MidDir[1]=MidDir[0];
   MidDir[0]=gDir_Mid;
   
   gDir_MidFilterLast=gDir_MidFilter;
   gDir_MidFilter=(MidDir[0]+MidDir[1]+MidDir[2]+MidDir[3]+MidDir[4])/5;
   gDir_MidFilterDiff=gDir_MidFilter-gDir_MidFilterLast;
   

   FarDir[9]=FarDir[8];
   FarDir[8]=FarDir[7];
   FarDir[7]=FarDir[6];
   FarDir[6]=FarDir[5];
   FarDir[5]=FarDir[4];
   FarDir[4]=FarDir[3];
   FarDir[3]=FarDir[2];
   FarDir[2]=FarDir[1];
   FarDir[1]=FarDir[0];
   FarDir[0]=gDir_Far;
   
   gDir_FarFilterLast=gDir_FarFilter;
   gDir_FarFilter=(FarDir[0]+FarDir[1]+FarDir[2]+FarDir[3]+FarDir[4])/5;
   gDir_FarFilterDiff=gDir_FarFilter-gDir_FarFilterLast;
   
   gDir_FarFilterSlowLast=gDir_FarFilterSlow;
   gDir_FarFilterSlow=gDir_FarFilter/2+(FarDir[9]+FarDir[8]+FarDir[7]+FarDir[6]+FarDir[5])/10;
   gDir_FarFilterSlowDiff=gDir_FarFilterSlow-gDir_FarFilterSlowLast;
   
   switch(gVar.InAngle)
   {
       case 0:
          if(gDir_FarFilterDiff>0 && gDir_FarFilter>gParam.InAngle_FarDir )
             gVar.InAngle=1;
          if(gDir_FarFilterDiff<0 && gDir_FarFilter<-gParam.InAngle_FarDir)
             gVar.InAngle=1;
          if(gVar.InAngle == 1)
             MotorR_PID.I = MotorR_PID.I/3;
       break;
       case 1:
          if(gDir_FarFilterDiff<0 && gDir_FarFilter<gParam.OutAngle_FarDir && gDir_FarFilter>0)
             gVar.InAngle=0;
          if(gDir_FarFilterDiff>0 && gDir_FarFilter>-gParam.OutAngle_FarDir && gDir_FarFilter<0)
             gVar.InAngle=0;
          if(gVar.InAngle == 0)
             MotorR_PID.I = MotorR_PID.I*3;
     break;
   }
   
}

