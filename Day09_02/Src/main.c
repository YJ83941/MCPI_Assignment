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
#include "lis3dsh.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);

	int ret, count,buf=1500;
	int xt;
	int yt;
	LIS_Data val;
	LIS_Init();
	DelayMs(500);
	char str[32];
	SystemInit();


		/*LcdPuts(LCD_LINE1, "!DESD @ SUNBEAM!");
		for(count = 1; count < 100; count++) {
			LcdPuts(LCD_LINE2,"YOOOOO!");
		}*/
	ret = LIS_DRdy();
	DelayMs(100);
	LedBlink(LED_BLUE,500);
	if(1) {
		val = LIS_GetData();
				//sprintf(str, "%d",val.x);
		DelayMs(2000);
		xt=val.x;
		yt=val.y;
		LedBlink(LED_RED,400);
		while(1){
			val = LIS_GetData();
			if(val.x<xt-buf && val.y<yt-buf){
				LedOn(LED_GREEN);
				LedOn(LED_BLUE);
				LedOff(LED_RED);
				LedOff(LED_ORANGE);
			}
			else if(val.x<xt-buf && val.y>yt+buf){
				LedOn(LED_GREEN);
				LedOn(LED_ORANGE);
				LedOff(LED_RED);
				LedOff(LED_BLUE);
			}
			else if(val.x>xt+buf && val.y<yt-buf){
				LedOn(LED_RED);
				LedOn(LED_BLUE);
				LedOff(LED_ORANGE);
				LedOff(LED_GREEN);
			}
			else if(val.x>xt+buf && val.y>yt+buf){
				LedOn(LED_RED);
				LedOn(LED_ORANGE);
				LedOff(LED_GREEN);
				LedOff(LED_BLUE);
			}
			else if(val.x>xt+buf){
				LedOn(LED_RED);
				LedOff(LED_BLUE);
				LedOff(LED_GREEN);
				LedOff(LED_ORANGE);
					}
			else if(val.x<xt-buf){
				LedOn(LED_GREEN);
				LedOff(LED_RED);
				LedOff(LED_BLUE);
				LedOff(LED_ORANGE);
					}
			else if(val.y>yt+buf){
				LedOn(LED_ORANGE);
				LedOff(LED_RED);
				LedOff(LED_BLUE);
				LedOff(LED_GREEN);
					}
			else if(val.y<yt-buf){
				LedOn(LED_BLUE);
				LedOff(LED_RED);
				LedOff(LED_GREEN);
				LedOff(LED_ORANGE);
					}

			else{
				LedOff(LED_RED);
				LedOff(LED_BLUE);
				LedOff(LED_GREEN);
				LedOff(LED_ORANGE);
				}
				DelayMs(200);
			}


		}

	return 0;
}

