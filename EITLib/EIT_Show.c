/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_Show.c
 * This file is part of EIT Car Project
 * Embedded Innovation Team(EIT) - 
 * Website:http://www.mizhiquan.com
 * ----------------------------------------------------------------------------
 * LICENSING TERMS:
 * 
 *     The Code is provided in source form for FREE evaluation and  educational 
 * use.
 * 
 * ----------------------------------------------------------------------------
 * Change Logs:
 * Date           Author       Notes
 * 2016-02-08     Xian.Chen    the first version
 * 2016-07-08     Xian.Chen    update
 *
 *******************************************************************************
 */
#include "EIT_Show.h"

Site_t Site_DirKp = {0,0};                      //开始坐标
Site_t Site_DirKpNum = {30,0};

Site_t Site_DirKd = {60,0};
Site_t Site_DirKdNum = {90,0};

Site_t Site_MaxSpeed = {0,16};
Site_t Site_MaxSpeedNum = {75,16};

Site_t Site_MinSpeed = {0,32};
Site_t Site_MinSpeedNum = {75,32};

Site_t Site_KpInAngle = {0,48};
Site_t Site_KpInAngleNum = {45,48};

Site_t Site_MDSK = {70,48};
Site_t Site_MDSKNum = {110,48};

Site_t Site_W_MIDNum = {0,64};

Site_t site     = {48, 68};                           //显示图像左上角位置
Size_t imgsize  = {CAMERA_W, CAMERA_H};             //图像大小
Size_t size; 

void Lcd_Show(void)
{
  size.H = 60;
  size.W = 80;

  LCD_str(Site_DirKp,"Kp:",BLUE,RED);
  LCD_num(Site_DirKpNum, (uint16)(gParam.DIR_Kp*100), BLUE,RED);
  
  LCD_str(Site_DirKd,"Kd:",BLUE,RED);
  LCD_num(Site_DirKdNum, (uint16)(gParam.DIR_Kd*100), BLUE,RED);
  
  LCD_str(Site_MaxSpeed,"MaxSpeed:",BLUE,RED);
  LCD_num(Site_MaxSpeedNum, gParam.MaxSpeed, BLUE,RED);
  
  LCD_str(Site_MinSpeed,"MinSpeed:",BLUE,RED);
  LCD_num(Site_MinSpeedNum, gParam.MinSpeed, BLUE,RED);
  
  LCD_str(Site_KpInAngle ,"KpIn:",BLUE,RED);
  LCD_num(Site_KpInAngleNum, gParam.DIR_KpInAngle*100, BLUE,RED);
  
  LCD_str(Site_MDSK ,"MDSK:",BLUE,RED);
  LCD_num(Site_MDSKNum, gParam.MidDirSpeedK*100, BLUE,RED);

  LCD_Img_gray_Z(site, size, (uint8*)Image_Data, imgsize);
}


void Lcd_ShowImageData(void)
{
  size.H = 60;
  size.W = 80;
  
  LCD_Img_gray_Z(site, size, (uint8*)Image_Data, imgsize);
  
}

void Lcd_ShowImageDataF(void)
{
  int H;
  Site_t Linesite;
  
  Site_t site     = {1, 1};
  size.H = 90;
  size.W = 120;  
  LCD_Img_gray_Z(site, size, (uint8*)Image_Data, imgsize);
  
  for(H=0;H<H_END;H=H+2)
  {
      Linesite.x=site.x+HBoundL[H]*2/3;
      Linesite.y=site.y+H*2/3;
      LCD_point(Linesite, GREEN);
      
      Linesite.x=site.x+HBoundR[H]*2/3;
      Linesite.y=site.y+H*2/3;
      LCD_point(Linesite, BLUE);
      
      Linesite.x=site.x+HBoundM[H]*2/3;
      Linesite.y=site.y+H*2/3;
      LCD_point(Linesite, RED);

      
      Linesite.x=site.x+HBoundM_F[H]*2/3;
      Linesite.y=site.y+H*2/3;
      LCD_point(Linesite, YELLOW);
  }
}