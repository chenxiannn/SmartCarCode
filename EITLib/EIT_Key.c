
#include "EIT_Key.h"

int32 Key_En;
int32 state;
int i = 1;


void Model_Init(void)
{
  gpio_init(Model1, GPI, 0);
  port_init_NoALT(Model1 , PULLUP);
  
  gpio_init(Model2 , GPI, 0);
  port_init_NoALT(Model2 , PULLUP);

  gpio_init(Model3 , GPI, 0);
  port_init_NoALT(Model3 , PULLUP);

  gpio_init(Model4 , GPI, 0);
  port_init_NoALT(Model4 , PULLUP);

}
void Key_Init(void)
{
  gpio_init(KeyEnter , GPI, 0);
  port_init_NoALT(KeyEnter , PULLUP);
  
  gpio_init(KeyAck , GPI, 0);
  port_init_NoALT(KeyAck , PULLUP);
  
  gpio_init(KeyInc , GPI, 0);
  port_init_NoALT(KeyInc , PULLUP);
  
  gpio_init(KeyDec , GPI, 0);
  port_init_NoALT(KeyDec , PULLUP);
  
  gpio_init(KeyQuit , GPI, 0);
  port_init_NoALT(KeyQuit , PULLUP);
}
int32 Key_CheckEn(void)
{
  static uint8 KeyEnter_InLast=1;
  KeyState ret;
  uint8 KeyEnter_In=gpio_get(KeyEnter);
  if(KeyEnter_In==0&&KeyEnter_InLast==1)
      ret= K_En;
  else
      ret= K_Null;
  KeyEnter_InLast=KeyEnter_In;
  return ret;
}


void Key_Debug(void)
{
  static uint8 KeyAck_InLast=1;
  static uint8 KeyInc_InLast=1;
  static uint8 KeyDec_InLast=1;
  static uint8 KeyQuit_InLast=1;
  
  uint8 KeyAck_In;
  uint8 KeyInc_In;
  uint8 KeyDec_In;
  uint8 KeyQuit_In;
  
  if(state == 1)
  {
    Lcd_Show();
    KeyAck_In=gpio_get(KeyAck);
    KeyInc_In=gpio_get(KeyInc);
    KeyDec_In=gpio_get(KeyDec);
    KeyQuit_In=gpio_get(KeyQuit);
    if(KeyAck_In==0&&KeyAck_InLast==1)
    {
      i++;
      if(i>6)
        i = 1;
    }
    
    switch(i)
    {
    case 1:
      {
        LCD_str(Site_MDSK ,"MDSK:",BLUE,RED);
        //LCD_str(Site_MDSK ,"Flag:",BLUE,RED);
        LCD_str(Site_DirKp,"Kp:",GREEN,RED);
        if(KeyInc_In==0&&KeyInc_InLast==1)
        {
          gParam.DIR_Kp += 0.01;
          LCD_str(Site_DirKpNum,"    ",RED,RED);
          LCD_num(Site_DirKpNum, gParam.DIR_Kp*100, BLUE,RED);
  
        }
        if(KeyDec_In==0&&KeyDec_InLast==1)
        {
          gParam.DIR_Kp -= 0.01;
          if(gParam.DIR_Kp < 0)
            gParam.DIR_Kp = 0;
          LCD_str(Site_DirKpNum,"    ",RED,RED);
          LCD_num(Site_DirKpNum, gParam.DIR_Kp*100, BLUE,RED);
        }
        break;
      }
    case 2:
      {
        LCD_str(Site_DirKp,"Kp:",BLUE,RED);
        LCD_str(Site_DirKd,"Kd:",GREEN,RED);
        if(KeyInc_In==0&&KeyInc_InLast==1)
        {
          gParam.DIR_Kd += 0.1;
          LCD_str(Site_DirKdNum,"    ",RED,RED);
          LCD_num(Site_DirKdNum, gParam.DIR_Kd*100, BLUE,RED);
        }
        if(KeyDec_In==0&&KeyDec_InLast==1)
        {
          gParam.DIR_Kd -= 0.1;
          if(gParam.DIR_Kd < 0)
            gParam.DIR_Kd = 0;
          LCD_str(Site_DirKdNum,"    ",RED,RED);
          LCD_num(Site_DirKdNum, gParam.DIR_Kd*100, BLUE,RED);
        }
        break;
      }
    case 3:
      {
        LCD_str(Site_DirKd,"Kd:",BLUE,RED);
        LCD_str(Site_MaxSpeed,"MaxSpeed:",GREEN,RED);
        if(KeyInc_In==0&&KeyInc_InLast==1)
        {
          gParam.MaxSpeed += 10;
          if(gParam.MaxSpeed >= 1000)
            gParam.MaxSpeed = 1000;
          LCD_str(Site_MaxSpeedNum,"    ",RED,RED);
          LCD_num(Site_MaxSpeedNum, gParam.MaxSpeed, BLUE,RED);
        }
        if(KeyDec_In==0&&KeyDec_InLast==1)
        {
          gParam.MaxSpeed -= 10;
          if(gParam.MaxSpeed <= 0)
            gParam.MaxSpeed = 0;
          LCD_str(Site_MaxSpeedNum,"    ",RED,RED);
          LCD_num(Site_MaxSpeedNum, gParam.MaxSpeed, BLUE,RED);
        }
        break;
      }
    case 4:
      {
        LCD_str(Site_MaxSpeed,"MaxSpeed:",BLUE,RED);
        LCD_str(Site_MinSpeed,"MinSpeed:",GREEN,RED);
        if(KeyInc_In==0&&KeyInc_InLast==1)
        {
          gParam.MinSpeed += 10;
          if(gParam.MinSpeed >= 1000)
            gParam.MinSpeed = 1000;
          LCD_str(Site_MinSpeedNum,"    ",RED,RED);
          LCD_num(Site_MinSpeedNum, gParam.MinSpeed, BLUE,RED);
        }
        if(KeyDec_In==0&&KeyDec_InLast==1)
        {
          gParam.MinSpeed -= 10;
          if(gParam.MinSpeed <= 0)
            gParam.MinSpeed = 0;
          LCD_str(Site_MinSpeedNum,"    ",RED,RED);
          LCD_num(Site_MinSpeedNum, gParam.MinSpeed, BLUE,RED);
        }
        break;
      }
    case 5:
      {
        LCD_str(Site_MinSpeed,"MinSpeed:",BLUE,RED);
        LCD_str(Site_KpInAngle ,"KpIn:",GREEN,RED);
        if(KeyInc_In==0&&KeyInc_InLast==1)
        {
          gParam.DIR_KpInAngle += 0.01;
          LCD_str(Site_KpInAngleNum,"  ",RED,RED);
          LCD_num(Site_KpInAngleNum, gParam.DIR_KpInAngle*100, BLUE,RED);
        }
        if(KeyDec_In==0&&KeyDec_InLast==1)
        {
          gParam.DIR_KpInAngle -= 0.01;
          if(gParam.DIR_KpInAngle <= 0)
            gParam.DIR_KpInAngle = 0;
          LCD_str(Site_KpInAngleNum,"  ",RED,RED);
          LCD_num(Site_KpInAngleNum, gParam.DIR_KpInAngle*100, BLUE,RED);
        }
        break;
      }
      case 6:
      {
        LCD_str(Site_KpInAngle ,"KpIn:",BLUE,RED);
        LCD_str(Site_MDSK ,"MDSK:",GREEN,RED);
        if(KeyInc_In==0&&KeyInc_InLast==1)
        {
          gParam.MidDirSpeedK += 0.01;
          //Flag_Car = 1;
          LCD_str(Site_MDSKNum,"    ",RED,RED);
          LCD_num(Site_MDSKNum, gParam.MidDirSpeedK*100, BLUE,RED);
          //LCD_num(Site_MDSKNum, Flag_Car, BLUE,RED);
        }
        if(KeyDec_In==0&&KeyDec_InLast==1)
        {
          gParam.MidDirSpeedK -= 0.01;
          //Flag_Car = 0;
          if(gParam.MidDirSpeedK <= 0)
            gParam.MidDirSpeedK = 0;
          LCD_str(Site_MDSKNum,"    ",RED,RED);
          LCD_num(Site_MDSKNum, gParam.MidDirSpeedK*100, BLUE,RED);
          //LCD_num(Site_MDSKNum, Flag_Car, BLUE,RED);
        }
        break;
      }
    default:
      break;
    }
    if(KeyQuit_In==0&&KeyQuit_InLast==1)
    {
      state = 0;
      LCD_init();
      return;
        //break;
     }
     KeyInc_InLast=KeyInc_In;
     KeyDec_InLast=KeyDec_In;
     KeyAck_InLast=KeyAck_In;
     KeyQuit_InLast=KeyQuit_In;
  }
  else
  {
    state = 0;
    return;
  }
}