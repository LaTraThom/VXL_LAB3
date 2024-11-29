/*
 * fsm_manual.c
 *
 *  Created on: Nov 15, 2024
 *      Author: TIEN DUY
 */

#include "global.h"
int MODE = MODE_NORMAL;
int led_buffer1[2] = {1,2};
void fsm_manual() {
	if (isButton1Pressed() && MODE == MODE_NORMAL) {
		traffic_light(RED_MODIFY);
		MODE = MODE_RED_MODIFY;
		RED_TIME_MODIFY = RED_TIME;
	  	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	  	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	    led_buffer1[0] = RED_TIME_MODIFY / 10000;
	    led_buffer1[1] = RED_TIME_MODIFY % 10000;
	}
	if (isButton1Pressed() && MODE == MODE_RED_MODIFY) {
		traffic_light(YELLOW_MODIFY);
		MODE = MODE_YELLOW_MODIFY;
		YELLOW_TIME_MODIFY = YELLOW_TIME;
	  	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	  	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	    led_buffer1[0] = YELLOW_TIME_MODIFY / 10000;
	    led_buffer1[1] = YELLOW_TIME_MODIFY % 10000;
	}
	if (isButton1Pressed() && MODE == MODE_YELLOW_MODIFY) {
		traffic_light(GREEN_MODIFY);
		MODE = MODE_GREEN_MODIFY;
		GREEN_TIME_MODIFY = GREEN_TIME;
	  	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	  	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	    led_buffer1[0] = GREEN_TIME_MODIFY / 10000;
	    led_buffer1[1] = GREEN_TIME_MODIFY % 10000;
	}
	if (isButton1Pressed() && MODE == MODE_GREEN_MODIFY) {
		MODE = MODE_NORMAL;
		status = INIT;
	}
}
