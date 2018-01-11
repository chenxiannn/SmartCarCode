/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : COntrolParam.c
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

#include "ControlParam.h"
EIT_PARAM gParam;
void ControlParam_Init(void)
{
        /*Left Motor*/	
	gParam.MotorL_PID_KP = 4;	
	gParam.MotorL_PID_KI = 6.0;	
	gParam.MotorL_PID_KD = 0.0; 
	gParam.MotorL_PID_Ts = MOTOR_PID_TS; /*Unit: s   */
        
	/*Right Motor*/	
	gParam.MotorR_PID_KP=4.0;	
	gParam.MotorR_PID_KI=2.5;	/*Unit: s   */
	gParam.MotorR_PID_KD=0.0; /*Unit: s   */
	gParam.MotorR_PID_Ts=MOTOR_PID_TS; /*Unit: s   */
    gParam.MOtroR_PID_UpRate = 1000;/*指令最大m/s^2*/
    gParam.MOtroR_PID_DnRate = -2000;/*指令最大m/s^2*/
        
        gParam.MaxSpeed     =330;    
        gParam.MinSpeed     =270;    
               
        /*Decrease Speed K*/
        gParam.DecSpeedK    =2.5;    //2.5
        
        /*Left Right Speed*/
        gParam.LRSpeedK     =1.0;      //1.2           

        /*DIR control PD*/
        gParam.DIR_Kp       =0.35;   //0.6
        gParam.DIR_KpInAngle=0.51;   //0.6
        
        gParam.DIR_Kd       =1.5;   //0
        gParam.DIR_Dead     =5;
        
        gParam.NearDirDeltaMax=10;
        gParam.FarDirDeltaMax=10;
        gParam.AngleDeltaMax=5;
        
        gParam.SteerMid=380;     //舵机中值   //旧车321    //新车355
        gParam.SteerDeltaMax=90; //最大舵机控制量
        
        gParam.AngleMax=30;   //最大转角
        gParam.BackLength=7;//后轴宽度
        
        /*Dir Calculate*/
        gParam.NearStart=10;
        gParam.NearLen  =40;
        
        gParam.MidLen   =40;
        gParam.MidDirSpeedK=0.11;//0.09   0.10  0.11
        
        gParam.FarStart =180;
        gParam.FarLen   =20;   
        
        gParam.MaxCurrent =15;
        gParam.MaxCurrentInt=500;
        
        gParam.InAngle_FarDir=16;
        gParam.OutAngle_FarDir=30;
}



