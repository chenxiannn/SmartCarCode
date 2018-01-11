/* @filename:Eit_Bmp.c
*
* @brief: 实现bmp文件的保存，用于保存赛道信息；
*
* @the library:  VCAN、kinetis。
*
* @date:2015.1.9
*
* @modification time:2015.1.9
*
* @author: Hu wensong
*
*/

#include "Eit_SD.h"

FIL      bmpfdest;                                                              //文件
FATFS     bmpfs;                                                                 //文件系统 

uint16 img_sd[CAMERA_H][CAMERA_W];
 
uint8 Header[62] =
{
  0x42,0x4d,0,0,0,0,
  0,0,0,0,62,0,0,0,
  
  40,0,0,0,0,0,0,0,
  0,0,0,0,1,0,1,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  
  0xff,0xff,0xff,0x00,
  0x00,0x00,0x00,0x00
};     
/*!
 *  @brief      将摄像头采集到图像以bmp文件保存到sd卡中
 *  @date       2015.1.9
 *  @modification time:   2015.1.9
 */
void Img_Sdbmp(uint8 hight,uint8 width,uint8 *filename)
{
  long file_size;                                                               //文件的大小
  long Hight;                                                                   //图像的高
  long Width;                                                                   //图像的宽
  uint8 Byte;
  uint8 bmp_name[30];                                                           //存文件名
  int res=0,w_res;
  uint32 mybw;
  int x,y,i,j;
  int temp,tempy;
  char kk[4]={0,0,0,0};
  /* 宽*高 +补充的字节 + 头部信息 */
	file_size = (long)width * (long)hight/8+62;                                              //文件大小：高*宽+文件头
  Header[2] = (uint8)file_size&0x000000ff;                                      //保存文件大小到文件头
  Header[3] = (file_size >> 8)&0x000000ff;
  Header[4] = (file_size >> 16)&0x000000ff;
  Header[5] = (file_size >> 24)&0x000000ff;
    
  Width = width;                                                                //保存宽度到文件头
  Header[18] = Width & 0x000000ff;
  Header[19] = (Width >> 8)&0x000000ff;
  Header[20] = (Width >> 16)&0x000000ff;
  Header[21] = (Width >> 24)&0x000000ff;
  
  Hight = hight;                                                                //保存高度到文件头
  Header[22] = Hight & 0x000000ff;
  Header[23] = (Hight >> 8)&0x000000ff;
  Header[24] = (Hight >> 16)&0x000000ff;
  Header[25] = (Hight >> 24)&0x000000ff;
  
  sprintf((char *)bmp_name,"0:/%s.bmp",filename);                               //将文件名以一定格式保存到bmp_name中
  f_mount(0,&bmpfs);                                                            //注册一个工作区
  
  res = f_open(&bmpfdest,(char *)bmp_name,FA_OPEN_ALWAYS | FA_WRITE);       //打开文件
  printf("%d",res);
  if(res == FR_OK)
  {
    w_res=f_write(&bmpfdest,Header,sizeof(Header),&mybw);                      //将文件头写入文件
    
    if(w_res != FR_OK)
    {
      printf("写头文件失败！\r\n");
    }
    else
      printf("写文件头成功！\r\n");
    for(i=0;i<Hight;i++)
    {
      if(!(Width%4))
      {
        for(j=0;j<Width;j++)
{
          Byte = imgbuff0[j+i*Width];
    
          w_res=f_write(&bmpfdest, &Byte,sizeof(unsigned char), &mybw);
  
        }
       }
      else
      {
        for(j=0;j<Width;j++)
        {
          Byte = imgbuff0[i+j*Width];
    
          w_res=f_write(&bmpfdest, &Byte,sizeof(unsigned char), &mybw);
        }
        w_res = f_write(&bmpfdest, kk,sizeof(unsigned char)*(Width%4), &mybw);
      }
    }
    f_sync(&bmpfdest);
    f_close(&bmpfdest);
  }  
  else
    printf("SD卡错误");
  
}