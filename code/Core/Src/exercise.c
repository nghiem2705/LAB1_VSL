/*
 * exercise.c
 *
 *  Created on: Sep 23, 2025
 *      Author: Admin
 */
#include "exercise.h"
//exercise 1
void excercise1_init() {
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
}

void exercise1_run() {
	HAL_Delay(2000);
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}

