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
 * 2015-01-22    ZhuJianNing   the first version
 *
 *******************************************************************************
 */

#include   "EIT_ENC_03.h"
 uint8 X_AD=0,Y_AD=0,Z_AD=0;
void Enc_03_init()
{
    adc_init(ENC_PORT_X_AR2);
    adc_init(ENC_PORT_Y_AR1);
    adc_init(ENC_PORT_Z_AR3);
}
void Enc_03_GetAD()
{
    X_AD = adc_once(ENC_PORT_X_AR2, ADC_8bit);
    Y_AD = adc_once(ENC_PORT_Y_AR1, ADC_8bit);
    Z_AD = adc_once(ENC_PORT_Z_AR3, ADC_8bit);
    printf("xyz  %d,%d,%d",X_AD,Y_AD,Z_AD);
    //return Y_AD;
}

