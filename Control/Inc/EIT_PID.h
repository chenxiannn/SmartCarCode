/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_PID.h
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
 * 2015-02-06     Xian.Chen    the first version
 * 2015-02-08     Xian.Chen    add PID_SetSpVal and PID_SetSpVal
 *
 *******************************************************************************
 */
#ifndef __EIT_PID_h__
#define __EIT_PID_h__

#include "common.h"

typedef struct _PID
{
    /*In*/
    int32   spVal;
    int32   spValRamp;
    int32   spUpRate;
    int32   spDnRate;
    int32   fbValFilterLast;
    int32   fbValFilter;
    int32   fbValFilterDiff;
    int32   fbVal_k0;
    int32   fbVal_k1;
    int32   fbVal_k2;
    int32   fbVal_k3;
    /*Out*/
    int32   outVal;
    /*Var*/
    int32   err;
    int32   P;
    float   I;
    int32   D;
    
    /*Param*/
    int32   MAX_Val;
    int32   MIN_Val;
	
    float   Kp;
    float   Ki;
    float   Kd;
}PID;
typedef  PID*   PID_t;
extern void   PID_InitFbVal(PID_t tPID,int32 fbVal);
extern void   PID_SetFbVal(PID_t tPID,int32 fbVal);
extern void   PID_Run_STD(PID_t tPID);
extern void   PID_Run_PID(PID_t tPID);
#endif 
