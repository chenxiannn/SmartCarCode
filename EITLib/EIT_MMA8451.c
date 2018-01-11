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

#include   "EIT_MMA8451.h"

 int16 XOUT;
 int16 YOUT;
 int16 ZOUT;


uint8 EIT_MMA8451_Init()
{
    uint8 device_id;
    port_init (MMA8451_IRQ, IRQ_ZERO| PULLUP ); 
    i2c_init(MMA8451_I2C,MMA8451_FREQ);                       //400K的通信频率
   // EIT_MMA8451_Write(MMA8451_REG_SYSMOD, 0x00);             //默认模式Standby Mode
    EIT_MMA8451_Write(MMA8451_REG_CTRL_REG4,0x01);           //配置中断源寄存器
    EIT_MMA8451_Write(MMA8451_REG_CTRL_REG2, 0x02);          //High Resolution
    EIT_MMA8451_Write(MMA8451_REG_CTRL_REG1, 0x01);          //主动模式,800HZ
    
    device_id = EIT_MMA8451_Read(MMA8451_REG_WHOAMI);
    
    if (device_id != MMA8451_DEV_ID)
    {
        printf("Read ID Error!");
    }
    return device_id;
}

void EIT_MMA8451_Write(uint8 RegAddr,uint8 Data)
{
    i2c_write_reg(MMA8451_I2C,MMA8451_DEV_ADDR,RegAddr,Data);
}

uint8 EIT_MMA8451_Read(uint8 RegAddr)
{
    uint8 result;
    
    result = i2c_read_reg(MMA8451_I2C,MMA8451_DEV_ADDR,RegAddr);
    return result;
}

int16 EIT_MMA8451_GetResult(uint8 RegsAddr) 
{
    int16 result,temp;
    result= EIT_MMA8451_Read( RegsAddr);
    temp  = EIT_MMA8451_Read( RegsAddr+1);
    result=result<<8;
    result=result|temp;
    result = result>>2;
    return result;

//    uint8 ret=0;
//    uint16 cnt=0;
//    if(RegsAddr>MMA8451_REG_OUTZ_LSB)
//        return 0;
//  
//  // 等待转换完成并取出值 
//    while(!(ret&Status)) 
//    {
//      ret = EIT_MMA8451_Read( MMA8451_REG_STATUS);
//      if(++cnt>500)
//        break;
//    }
  
}
void EIT_MMA8451_IRQ(void)
{
      XOUT = EIT_MMA8451_GetResult(MMA8451_REG_OUTX_MSB);
      YOUT = EIT_MMA8451_GetResult(MMA8451_REG_OUTY_MSB);
      ZOUT = EIT_MMA8451_GetResult(MMA8451_REG_OUTZ_MSB);
      printf("x=%d,y=%d,z=%d",XOUT,YOUT,ZOUT);
      disable_irq(PORTD_IRQn);
}