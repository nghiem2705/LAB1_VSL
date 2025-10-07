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
}


//exercise4
const uint8_t digits[10][7] = {
  {0,0,0,0,0,0,1}, //0
  {1,0,0,1,1,1,1}, //1
  {0,0,1,0,0,1,0}, //2
  {0,0,0,0,1,1,0}, //3
  {1,0,0,1,1,0,0}, //4
  {0,1,0,0,1,0,0}, //5
  {0,1,0,0,0,0,0}, //6
  {0,0,0,1,1,1,1}, //7
  {0,0,0,0,0,0,0}, //8
  {0,0,0,0,1,0,0}  //9
};


uint8_t a = 0;
uint8_t b = 0;
uint8_t c = 0;
uint8_t d = 0;
uint8_t e = 0;
uint8_t f = 0;
uint8_t g = 0;

void display7SEG(int count) {
    a = digits[count][0];
    b = digits[count][1];
    c = digits[count][2];
    d = digits[count][3];
    e = digits[count][4];
    f = digits[count][5];
    g = digits[count][6];

    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, a);
    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, b);
    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, c);
    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, d);
    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, e);
    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, f);
    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, g);
}

