/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_PID.c
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
 *
 *******************************************************************************
 */
#ifndef  __EIT_CONTROL_H__
#define  __EIT_CONTROL_H__
#include "include.h"
extern int spSpeedL;
extern int spSpeedR;
extern int angle;
extern int gDir_MidFilter;
extern int gDir_MidFilterDiff;
extern int gDir_FarFilter;
extern int gDir_FarFilterDiff;
extern int gDir_FarFilterSlow;
extern int gDir_FarFilterSlowDiff;
extern int InAngle;
extern void ControlSpeedTask(void);
extern void GetImagTask(void);
extern void ControlGraphTask(void);
extern void SteerDirControl(void);
extern void  Car_Test(void);


extern  int32 CarSpeed2RSpeed(int32 CarSpeed,int angle);
#endif
