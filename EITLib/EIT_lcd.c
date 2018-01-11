/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : eit_lcd.c
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
 * 2015-01-22    MENG.ZHAO   the first version
 *
 *******************************************************************************
 */
#include "EIT_lcd.h"

volatile Site_t site;


//static volatile uint32 spd_l;
//static volatile uint32 spd_r;
//static volatile uint32 dir_l;
//static volatile uint32 dir_r;

//LCD初始化，和lcd显示。
void  lcd_car_int(void)
{
  LCD_init();         //初始化
}


//LCD参数显示，一个char类型高12像素，宽8像素。
  //uart_putchar (UART4, 'l');
   //uart_putchar (UART4, val8); 
//void LCD_show_L(uint32 sitex)
//{
//    site.x = 15;
//    site.y = 80;
//    LCD_num(site,sitex , BLUE, RED);
//}
//   // uart_putchar (UART4,'r');
//   //uart_putchar (UART4, val8); 
//void LCD_show_R(uint32 sitex)
//{
//    site.x = 60;
//    site.y = 80;
//    LCD_num(site,sitex , BLUE, RED);
//}
//   //uart_putchar (UART4, 'l');
//   //uart_putchar (UART4,pta_dir_data );
//void LCD_show_LDIR(uint32 sitex)
//{
//    site.y = 54;
//    site.x = 8;
//    LCD_str(site, "L_DIR 1", BLUE, RED);
//    site.x = 70;
//    LCD_num(site,sitex , BLUE, RED);
//}
//   //uart_putchar (UART4,'r');
//   //uart_putchar (UART4,pta_dir_data );
//void LCD_show_RDIR(uint32 sitex)
//{
//    site.y = 66;
//    site.x = 8;
//    LCD_str(site, "R_DIR 0", BLUE, RED); 
//    site.x = 70;
//    LCD_num(site,sitex , BLUE, RED);
//}
//
//
