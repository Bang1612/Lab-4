/*
 * func.c
 *
 *  Created on: Nov 28, 2023
 *      Author: MY PC
 */
#include "func.h"
#include "main.h"

void Toggle_LED1(void){
	HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
}

void Toggle_LED2(void){
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
}

void Toggle_LED3(void){
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}

void Toggle_LED4(void){
	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
}

void Toggle_LED5(void){
	HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
}
