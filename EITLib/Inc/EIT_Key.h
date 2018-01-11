#ifndef _EIT_KEY_H
#define _EIT_KEY_H

#include "include.h"

#define    KeyEnter         PTD5//PTD15                                             //进入按键调参
#define    KeyAck           PTD6//PTD11                                             //确认
#define    KeyInc           PTD3//PTD12                                            //增加
#define    KeyDec           PTD4//PTD13                                            //减少
#define    KeyQuit          PTD2//PTD14                                            //退出

#define    Model1           PTD7    //控制模式的4个拨码开关
#define    Model2           PTD8  
#define    Model3           PTD9  
#define    Model4           PTD10  

typedef enum 
{
  K_En,
  K_Ack,
  K_Inc,
  K_Dec,
  K_Quit,
  K_Null,
}KeyState;

extern int32 Key_En;

extern int32 state;


void Model_Init(void);
void Key_Init(void);
int32 Key_CheckEn(void);
void Key_Debug(void);

#endif //_EIT_KEY_H