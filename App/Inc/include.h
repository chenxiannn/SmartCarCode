#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include  "common.h"

/*
 * Include 用户自定义的头文件
 */
#include  "MK60_wdog.h"
#include  "MK60_gpio.h"     //IO口操作
#include  "MK60_uart.h"     //串口
#include  "MK60_SysTick.h"
#include  "MK60_lptmr.h"    //低功耗定时器(延时)
#include  "MK60_i2c.h"      //I2C
#include  "MK60_spi.h"      //SPI
#include  "MK60_ftm.h"      //FTM
#include  "MK60_pit.h"      //PIT
#include  "MK60_rtc.h"      //RTC
#include  "MK60_adc.h"      //ADC
#include  "MK60_dac.h"      //DAC
#include  "MK60_dma.h"      //DMA
#include  "MK60_FLASH.h"    //FLASH
#include  "MK60_can.h"      //CAN
#include  "MK60_sdhc.h"     //SDHC
#include  "MK60_usb.h"      //usb

#include  "VCAN_LED.H"          //LED
#include  "VCAN_KEY.H"          //KEY
#include  "VCAN_OV7725_Eagle.h" //OV7725摄像头头文件
#include  "VCAN_NRF24L0.h"      //无线模块NRF24L01+
#include  "VCAN_LCD.h"          //液晶总头文件
#include  "ff.h"                //FatFs
#include  "VCAN_TSL1401.h"      //线性CCD
#include  "VCAN_key_event.h"    //按键消息处理

#include  "vcan_sd_app.h"       //SD卡应用（显示sd看上图片固件）

#include  "EIT_MotorL.h"           //电机文件
#include  "EIT_MotorR.h"           //电机文件
#include  "EIT_Steer.h"           //舵机文件

#include  "ControlParam.h"
#include  "ControlVar.h"
#include  "ControlTask.h"

#include  "EIT_SpeedL.h"
#include  "EIT_SpeedR.h"
#include  "EIT_PID.h"

#include  "CarSystem.h"
#include  "CarTest.h"
#include  "IntHandler.h"   

#include  "imProc.h" 
#include  "EIT_Log.h" 
#include  "EIT_Show.h"
#include  "EIT_Key.h"


#endif  //__INCLUDE_H__
