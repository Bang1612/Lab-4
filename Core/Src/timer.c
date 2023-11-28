/*
 * timer.c
 *
 *  Created on: Nov 27, 2023
 *      Author: MY PC
 */

#include "main.h"
#include "timer.h"
#define NUMBER_OF_TIMERS 1

struct {
	int state;
	int count;
} timer[NUMBER_OF_TIMERS];
uint32_t freq=FREQUENCY_OF_TIM;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
		run_timer();
}
void GetFreq(uint32_t prescaler, uint32_t period){
	freq = HAL_RCC_GetHCLKFreq()/((prescaler + 1)*(period + 1));
}
void set_timer(int i, int count) {
	timer[i].count = count * freq /(10 * FREQUENCY_OF_TIM);

	timer[i].state = 0;
}
void run_timer() {
	for (int i = 0; i < NUMBER_OF_TIMERS; i++) {
		if (!timer[i].state) {
			timer[i].count--;
			if (timer[i].count <= 0) {
				timer[i].state = 1;
			}
		}
	}
}
int is_timer_on(int i) {
	return timer[i].state;
}
