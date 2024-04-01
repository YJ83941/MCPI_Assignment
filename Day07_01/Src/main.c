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

#include "uart.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int c=0;
	char s[16];
	SystemInit();
	UartInit(BAUD_9600);
	SwitchInit(SWITCH);
	while(1) {
		// wait until switch interrupt generated
		while(exti0_flag == 0)
			;
		// Blink the Led
		sprintf(s,"%d",c);
		UartPuts(s);
		UartPuts("\n");
		c++;
		exti0_flag = 0;
	}
	return 0;
}
