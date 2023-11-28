/*
 * timer.h
 *
 *  Created on: Nov 27, 2023
 *      Author: MY PC
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <stdint.h>
#define FREQUENCY_OF_TIM	1000 // Hz
#define TICKS				1
#define HALF_SECOND         500
#define ONE_SECOND			1000 // 1s
#define ONE_AND_A_HALF 		1500
#define TWO_SECOND			2000
#define TWO_AND_A_HALF		2500

void GetFreq(uint32_t prescaler, uint32_t period);
void set_timer(int i, int count);
void run_timer(void);
int is_timer_on(int i);

#endif /* INC_TIMER_H_ */
