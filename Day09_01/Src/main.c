/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "i2c_lcd.h"
#include "lis3dsh.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int ret, count;
	LIS_Data val;
	LIS_Init();
	DelayMs(500);
	char str[32];
	SystemInit();
	ret = LcdInit();
	if(ret) {
		/*LcdPuts(LCD_LINE1, "!DESD @ SUNBEAM!");
		for(count = 1; count < 100; count++) {
			LcdPuts(LCD_LINE2,"YOOOOO!");
		}*/
		ret = LIS_DRdy();
		if(ret) {
			while(1){
				val = LIS_GetData();
				sprintf(str, "X=%3d, Y=%3d", val.x, val.y);
				LcdPuts(LCD_LINE1,str);
				sprintf(str, "Z=3%d",val.z);
				LcdPuts(LCD_LINE2,str);
				DelayMs(1000);
			}
		}
	}
	return 0;
}
