/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : EIT_Log.c
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

#include  "EIT_Log.h"             //header用户应用程序

static int32 DataLog[LOG_COUNT][LOG_NUM_EACH];
static volatile int32 cnt=0;
void DataLog_Init(void)
{
   gpio_init(LOG_EN, GPI, 0);
   port_init_NoALT(LOG_EN, PULLUP);
   cnt=0;
   
}

void DataLog_Add(void)
{
   if(cnt>=LOG_COUNT)
     return;
   else
   {
       DataLog[cnt][0]=MotorR_PID.fbValFilter;
       DataLog[cnt][1]=MotorR_PID.spVal;
       DataLog[cnt][2]=MotorR_PID.spValRamp;
       DataLog[cnt][3]=MotorR_PID.err;
       DataLog[cnt][4]=MotorR_PID.outVal;
       DataLog[cnt][5]=gVar.InAngle*100;
       DataLog[cnt][6]=gDir_FarFilter;
       DataLog[cnt][7]=gDir_MidFilter;
       DataLog[cnt][8]=angle;

       cnt++;
   }
}

void DataLog_Print(void)
{
    int i,j;
    
    for(i=0;i<LOG_COUNT;i++)
    {
        for(j=0;j<LOG_NUM_EACH;j++)
            printf("%d ",DataLog[i][j]);
        printf("\n");
    }
}
int32 DataLog_CheckEN(void)
{
    static uint8 InLast=1;
    int32 ret=0;
    uint8 In=gpio_get(LOG_EN);
    if(In==0&&InLast==1)
        ret= 1;
    else
        ret= 0;
    InLast=In;
    return ret;
}
void DataLog_Image2Computer(void)
{
    int H,W;
    
    for(H=0;H<CAMERA_H;H++)
    {
        for(W=0;W<CAMERA_W;W++)
        {
             printf("%d ",Image_Data[H][W]);
        }
        printf("\n");
    }
    printf("OK\n");
}
