/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : main.c
 * This file is part of EIT Car Project
 * Embedded Innovation Team(EIT) - Car@EIT  
 * ----------------------------------------------------------------------------
 * LICENSING TERMS:
 * 
 *     CarLib is provided in source form for FREE evaluation and  educational 
 * use.
 *    If you plan on using  CarLib  in a commercial product you need to contact 
 * Car@EIT to properly license its use in your product. 
 * 
 * ----------------------------------------------------------------------------
 * Change Logs:
 * Date           Author       Notes
 * 2015-01-22    ZHU JIAN NING   the first version
 *
 *******************************************************************************
 */

#ifndef __EIT_ENC_03_H__
#define __EIT_ENC_03_H__

#include "include.h"
         
#define ENC_PORT_X_AR2     ADC1_SE15             //PTB11
#define ENC_PORT_Y_AR1     ADC1_SE14           //PTB10
#define ENC_PORT_Z_AR3     ADC0_SE17            //PTA17

void Enc_03_init();
void Enc_03_GetAD();

#endif