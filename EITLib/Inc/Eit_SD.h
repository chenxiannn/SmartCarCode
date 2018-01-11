/* @filename:Eit_Bmp.h
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

#ifndef _EIT_BMP_H
#define _EIT_BMP_H

#include "include.h"
                                                                         
extern uint16 img_sd[CAMERA_H][CAMERA_W];
void Img_Sdbmp(uint8 hight,uint8 width,uint8 *filename);             





#endif //EIT_BMP_H