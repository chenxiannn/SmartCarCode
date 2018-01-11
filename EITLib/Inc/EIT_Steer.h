/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_HEADER.h
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
 * 2015-01-24     MENG.ZHAO    the first version
 *
 *******************************************************************************
 */
#ifndef _EIT_STEER_H_
#define _EIT_STEER_H_

#include "include.h"


#define STEER_FTM    FTM3
#define STEER_PWM    FTM_CH0

#define STEER_PWM_FREQ   225

extern void Steer_Init(int32 mid);
extern void Steer_Run(int32 Mid,int32 Deg);
#endif      //_HEADER_H_