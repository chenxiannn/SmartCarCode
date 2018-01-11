#ifndef _EIT_SHOW_H
#define _EIT_SHOW_H

#include "include.h"
//#include "common.h"

extern int Flag_Car;

extern Site_t Site_DirKp;                      //开始坐标
extern Site_t Site_DirKpNum;

extern Site_t Site_DirKd;
extern Site_t Site_DirKdNum;

extern Site_t Site_MaxSpeed;
extern Site_t Site_MaxSpeedNum;

extern Site_t Site_MinSpeed ;
extern Site_t Site_MinSpeedNum ;

extern Site_t Site_KpInAngle ;
extern Site_t Site_KpInAngleNum ;

extern Site_t Site_MDSK ;
extern Site_t Site_MDSKNum ;

extern Site_t site  ;                           //显示图像左上角位置
extern Size_t imgsize ;             //图像大小
extern Size_t size; 

extern void Lcd_Show(void);

extern void Lcd_ShowImageData(void);

extern void Lcd_ShowImageDataF(void);

#endif //_EIT_SHOW_H