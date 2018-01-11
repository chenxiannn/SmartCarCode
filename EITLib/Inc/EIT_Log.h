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

#ifndef __EIT_LOG_DEF__
#define __EIT_LOG_DEF__
#include "include.h"

#define    MAX_LOG_MEMORY   75000
#define    LOG_NUM_EACH     9
#define    LOG_COUNT        (MAX_LOG_MEMORY/LOG_NUM_EACH/4)

#define    LOG_EN      PTD15     //屏幕上的按键向下按



extern void DataLog_Init(void);
extern int32 DataLog_CheckEN(void);
extern void DataLog_Print(void);
extern void DataLog_Add(void);

extern void DataLog_Image2Computer(void);

extern void Key_IRQ(void);                                                      //按键中断函数

#endif