/*
 * exercise.h
 *
 *  Created on: Sep 23, 2025
 *      Author: Admin
 */

#ifndef SRC_EXERCISE_H_
#define SRC_EXERCISE_H_

#include "main.h"

#define state1 1 // LED_RED ON , LED_GREEN1 ON, OTHERS OFF
#define state2 2 // LED_RED ON , LED_YELLOW ON, OTHERS OFF
#define state3 3 // LED_GREEN ON, LED_RED1 ON, OTHERS OFF
#define state4 4 // LED_YELLOW ON, LED_RED1 ON, OTHERS OFF

//exercise1
void exercise1_init();
void exercise1_run();

//exercise2
void exercise2_init();
void exercise2_run();

//exercise3
void exercise3_init();
void exercise3_run();

//exercise4
extern const uint8_t digits[10][7];
extern uint8_t a, b, c, d, e, f, g;

void display7SEG(int count);

//exercise5
void exercise5_run();
#endif /* SRC_EXERCISE_H_ */
