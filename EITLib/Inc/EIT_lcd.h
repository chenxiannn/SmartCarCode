/*
 *******************************************************************************
 *                                EIT CarLib
 *                             lib FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_LCD.h
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
#ifndef _LCD_H_
#define _LCD_H_
#include "include.h"
extern volatile Site_t site;


extern void lcd_car_int(void);
//extern void LCD_show_L(uint32 sitex);
//extern void LCD_show_R(uint32 sitex);
//extern void LCD_show_LDIR(uint32 sitex);
//extern void LCD_show_RDIR(uint32 sitex);
//extern void sendimg(uint8 *imgaddr, uint32 imgsize);


#endif      //_LCD_H_