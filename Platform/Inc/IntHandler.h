/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : PORTn_handler.h
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

#ifndef __INT_Handler_h__
#define __INT_Handler_h__
   
#include "include.h"
extern volatile uint8 flag_a6 ;
extern volatile uint8 flag_car ;
extern void PORTA_handler(void);
extern void PIT0_IRQHandler(void);
extern void DMA0_IRQHandler(void);
extern void PORTD_handler(void);
extern void PORTE_IRQHandler();
#endif 