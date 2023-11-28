/*
 * sch.c
 *
 *  Created on: Nov 15, 2023
 *      Author: MY PC
 */
#include "sch.h"
#define MAX_NUMBER_OF_TASKS 5
struct sTask{
	void (*pTask) (void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t Run;
	uint32_t TaskID;
};

struct sTask Task_queue[MAX_NUMBER_OF_TASKS];
//uint8_t Error_code_G =0;
uint8_t Return_code=0;
int taskID=0;

void SCH_Innit(void){
	for(int i=0; i< MAX_NUMBER_OF_TASKS; i++){
		Task_queue[i].pTask= NULL;
		Task_queue[i].Delay=0;
		Task_queue[i].Period=0;
		Task_queue[i].Run=0;
		Task_queue[i].TaskID=0;
	}
//	Error_code_G=0;
	Return_code =0;
}

void SCH_Update(void){
	for(int i=0; i < MAX_NUMBER_OF_TASKS;i++){
		if( Task_queue[i].pTask){
			if(Task_queue[i].Delay == 0){
				Task_queue[i].Run++;
				if(Task_queue[i].Period){
					Task_queue[i].Delay= Task_queue[i].Period;
				}
			}
			else{
				Task_queue[i].Delay--;
			}
		}
	}
}
void SCH_Dispatch_Tasks(void){
	for(int i=0; i < MAX_NUMBER_OF_TASKS; i++){
		if(Task_queue[i].Run > 0){
			(*Task_queue[i].pTask) ();
			Task_queue[i].Run--;
			if(Task_queue[i].Period == 0){
				SCH_Delete_Task(i);
			}
		}
	}
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t Delay, uint32_t Period ){
	for(int i=0; i< MAX_NUMBER_OF_TASKS; i++){
		if(!Task_queue[i].pTask){
			Task_queue[i].pTask= pFunction;
			Task_queue[i].Delay= Delay;
			Task_queue[i].Period= Period;
			Task_queue[i].Run=0;
			Task_queue[i].TaskID=i;
			return i;
		}
	}
//	Error_code_G= ERROR_SCH_TOO_MANY_TASKS;
	Return_code= RETURN_NORMAL;
	return -1;
}

uint32_t SCH_Delete_Task(uint32_t taskid){
	struct sTask *task= NULL;
	for(int i=0; i< MAX_NUMBER_OF_TASKS; i++){
		if(Task_queue[i].TaskID == taskid){
			task=&Task_queue[i];
		}
	}
	if(!task){
//		Error_code_G= ERROR_SCH_CANNOT_FIND_TASK;
		Return_code= RETURN_ERROR;
	}
	else{
		if(!task->pTask){
//				Error_code_G= ERROR_SCH_CANNOT_DELETE_TASK;
				Return_code= RETURN_ERROR;
			}
			else{
				Return_code = RETURN_NORMAL;
				task->pTask = 0x0000;
				task->Delay = 0;
				task->Period = 0;
				task->Run = 0;
				task->TaskID = 0;
			}
	}


	return Return_code ;

}
