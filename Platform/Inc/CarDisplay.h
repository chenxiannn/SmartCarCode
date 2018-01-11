/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      :CarDisplay.h
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
#ifndef __EIT_CARDISPLAY_h__
#define __EIT_CARDISPLAY_h__
#include "include.h"
#define  KEY1_UP PTB0
#define  KEY1_DN PTB1
#define  KEY1_LF PTB2  //×ó
#define  KEY1_RT PTB3  //ÓÒ
 
#define  KEY1_SE PTC0
   
#define  KEY_UP_IOn 0
#define  KEY_DN_IOn 1
#define  KEY_RT_IOn 2
#define  KEY_LF_IOn 3
#define  KEY_SE_IOn 0
#define  MIN_STEP   10

#define  MODE_EN PTD0
#define  MODE_ENn 0
#define  MODE_EN_D1 PTD1
#define  MODE_ENn_D1 1
#define  MODE_EN_C16 PTC16
#define  MODE_ENn_C16 16
#define  MODE_EN_C17 PTC17
#define  MODE_ENn_C17 17

   
enum {H_MAX,C_MAX,C_MIN,S_KLR,S_DEC,BendDec,StrMid,DIR_Kp,blacksped,C_ALL};

extern volatile int  Mode_flag;
extern volatile int  Display_flag;
extern volatile int  Mode_flag;
extern volatile int  Mode_flag_D1;
extern volatile int  Mode_flag_C16;
extern volatile int  Mode_flag_C17;
extern void DisplayKey_Init(void);
extern void Param_Display_Task(void);
extern void param_kay(void);
#endif