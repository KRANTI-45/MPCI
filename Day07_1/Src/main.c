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
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"
#include "switch.h"
extern volatile int count_flag;
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*Assignments
1. Count number of switch press (using interrupt) and display the count on UART (polling).*/

int main(void)
{
	//char str[4];
	char str[16];

	int c = 0;
	SystemInit();
	UartInit(BAUD_9600);
	//UartPuts("Enter Strings...\r\n");
	while(1) {
		//UartGets(str);
		//strupr(str);
		if(count_flag == 1)
		{
			sprintf(str,"%d\n",c++);
			UartPuts(str);
			count_flag = 0;
		}

	}
	return 0;
}
