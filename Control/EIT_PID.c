/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_PID.c
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
 #include "EIT_PID.h"


void   PID_SetFbVal(PID_t tPID,int32 fbVal)
{
        tPID->fbVal_k3 =tPID->fbVal_k2;
	tPID->fbVal_k2 =tPID->fbVal_k1;
	tPID->fbVal_k1 =tPID->fbVal_k0;
	tPID->fbVal_k0 =fbVal;
        tPID->fbValFilterLast=tPID->fbValFilter;
        tPID->fbValFilter    =(fbVal+tPID->fbVal_k1+tPID->fbVal_k2+tPID->fbVal_k3)/4;
        tPID->fbValFilterDiff=tPID->fbValFilter-tPID->fbValFilterLast;
}
void   PID_InitFbVal(PID_t tPID,int32 fbVal)
{
        tPID->fbVal_k3 =fbVal;
	tPID->fbVal_k2 =fbVal;
	tPID->fbVal_k1 =fbVal;
	tPID->fbVal_k0 =fbVal;
        tPID->fbValFilter    =fbVal;

}
static int32 PID_MaxMin(PID_t tPID,int32 u)
{
    if (u > tPID->MAX_Val)
        u = tPID->MAX_Val;
    else if (u < tPID->MIN_Val)
        u = tPID->MIN_Val;
    return u;		
}
static float PID_MaxMinFloat(PID_t tPID,float u)
{
    if (u > tPID->MAX_Val)
        u = tPID->MAX_Val;
    else if (u < tPID->MIN_Val)
        u = tPID->MIN_Val;
    return u;		
}

void  PID_Run_STD(PID_t tPID)
{
    int32 err;
    if(tPID->spVal-tPID->spValRamp > tPID->spUpRate)
        tPID->spValRamp+= tPID->spUpRate;
    if(tPID->spVal-tPID->spValRamp < tPID->spDnRate)
        tPID->spValRamp+= tPID->spDnRate;

    err=tPID->spValRamp-tPID->fbValFilter;
    tPID->err = err;

    tPID->P =  (int32)(tPID->Kp*err);
		
    tPID->D =  (int32)(tPID->Kd*(tPID->fbVal_k0-tPID->fbVal_k1));
    
    tPID->outVal = (int32)(tPID->P + tPID->I+tPID->D);
    tPID->outVal = PID_MaxMin(tPID,tPID->outVal);
	
    tPID->I =  (int32)(tPID->I  +  tPID->Ki*err);
    tPID->I =  PID_MaxMinFloat(tPID,tPID->I);
}
void  PID_Run_PID(PID_t tPID)
{
    int32 err;
    if(tPID->spVal-tPID->spValRamp > tPID->spUpRate)
        tPID->spValRamp+= tPID->spUpRate;
    if(tPID->spVal-tPID->spValRamp < tPID->spDnRate)
        tPID->spValRamp+= tPID->spDnRate;

    err=tPID->spValRamp-tPID->fbValFilter;
    tPID->err = err; 

    tPID->P =   (int32)(tPID->Kp*err);
    tPID->D =  (int32)(tPID->Kd*tPID->fbValFilterDiff);
    tPID->outVal = tPID->P + (int32)(tPID->I)+tPID->D;
    tPID->outVal = PID_MaxMin(tPID,tPID->outVal);
    tPID->I =   (int32)(tPID->I  +  tPID->Ki*err);
    tPID->I =  PID_MaxMinFloat(tPID,tPID->I);  
}

