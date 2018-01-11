/*
 *******************************************************************************
 *                                EIT Car Project
 *                             Main FUNCTIONS
 *
 *                     (c) Copyright 2015-2020 Car@EIT 
 *                            All Rights Reserved
 * File      : COntrolVar.c
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

#include "ControlVar.h"
EIT_VAR gVar;
void ControlVar_Init(void)
{
	/*Left Motor*/	
	gVar.MotorL_CntInTs = 0;
        gVar.MotorL_Speed   = 0;
	/*Right Motor*/	
	gVar.MotorR_CntInTs = 0;
        gVar.MotorR_Speed   = 0;
        gVar.Car_Speed      =0;
        gVar.time=0;
        gVar.MotorR_Current =0;
        gVar.InAngle        =0;
        gVar.MotorR_CurrentInt =0;
}