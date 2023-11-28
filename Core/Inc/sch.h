/*
 * sch.h
 *
 *  Created on: Nov 15, 2023
 *      Author: MY PC
 */

#ifndef INC_SCH_H_
#define INC_SCH_H_
#include "main.h"
void SCH_Innit(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t Delay, uint32_t Period);
uint32_t SCH_Delete_Task(uint32_t taskid);

#endif /* INC_SCH_H_ */
