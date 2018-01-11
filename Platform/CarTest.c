/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : CarTest.c
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

#include "CarTest.h"
#include "EIT_Key.h"

/**********************************************/
void  Car_Test(void)
{ 
    while(1)
    {  
       if(ImageOver)
       {
           ImageOver=0;
           img_extract((uint8 *)Image_Data, (uint8 *)imgbuff0, CAMERA_SIZE);
           ControlGraphTask();
           
           DataLog_Add();
           if(DataLog_CheckEN())
              DataLog_Print();
      }
    }
}
