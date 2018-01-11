/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      :CarTest.h
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

 * 2015-02-10     Xian.Chen    the first version
 *
 *******************************************************************************
 */
#ifndef __EIT_CARSYSTERM_h__
#define __EIT_CARSYSTERM_h__
#include "include.h"

extern void CarSystem_Init(void);
extern void Motor_Test(void);
extern void SpeedReadTask(void);
#endif