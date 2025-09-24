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

	else if (count < 8) {
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	}

	else {
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	}

	count = (count + 1) % 10 ;

	HAL_Delay(1000);

	exercise2_init();
}

//exercise 3
int current_state = state1;
int next_state = state1;
int count1 = 0;

void exercise3_init() {
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);

    HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
    HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
    HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
}

void exercise3_run() {
    // Tắt hết LED trước khi bật state mới
    exercise3_init();

    switch (current_state) {
        case state1:
            HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
            HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
            if (count1 >= 2) next_state = state2;
            break;

        case state2:
            HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
            HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
            if (count1 >= 4) next_state = state3;
            break;

        case state3:
            HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
            HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
            if (count1 >= 7) next_state = state4;
            break;

        case state4:
            HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
            HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
            if (count1 >= 9) next_state = state1;
            break;
    }

    // Cập nhật state và counter
    current_state = next_state;
    count1 = (count1 + 1) % 10;
    HAL_Delay(1000);
}
