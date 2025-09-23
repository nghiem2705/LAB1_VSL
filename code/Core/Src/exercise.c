/*
 * exercise.c
 *
 *  Created on: Sep 23, 2025
 *      Author: Admin
 */
#include "exercise.h"
//exercise 1
void exercise1_init() {
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
}

void exercise1_run() {
	HAL_Delay(2000);
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}

//exercise 2
int count = 0 ;
void exercise2_init(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
}

void exercise2_run() {
	if (count < 5) {
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	}

	else if (count < 7) {
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	}

	else {
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	}

	count = (count + 1) % 10 ;

	HAL_Delay(1000);

	exercise2_init();
}

