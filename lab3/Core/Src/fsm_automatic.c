/*
 * fsm_automatic.c
 *
 *  Created on: Nov 15, 2024
 *      Author: TIEN DUY
 */

#include "fsm_automatic.h"
#include "traffic_light.h"

void fsm_automatic_run(){
	switch (status){
		case INIT:
			HAL_GPIO_WritePin(LED_1_RED_GPIO_Port, LED_1_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_2_GREEN_GPIO_Port, LED_2_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_3_YELLOW_GPIO_Port, LED_3_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_4_RED_GPIO_Port, LED_4_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_5_GREEN_GPIO_Port, LED_5_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_6_YELLOW_GPIO_Port, LED_6_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_7_RED_GPIO_Port, LED_7_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_8_GREEN_GPIO_Port, LED_8_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_9_YELLOW_GPIO_Port, LED_9_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_10_RED_GPIO_Port, LED_10_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_11_GREEN_GPIO_Port, LED_11_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_12_YELLOW_GPIO_Port, LED_12_YELLOW_Pin, GPIO_PIN_SET);
			status =  AUTO_RED;
			setTimer1(500);
			break;
		case AUTO_RED:
			traffic_light(RED_LIGHT);
			if (timer1_flag == 1) {
				status = AUTO_GREEN;
				setTimer1(300);
			}
			break;
		case AUTO_GREEN:
			traffic_light(GREEN_LIGHT);
			if (timer1_flag == 1) {
				status = AUTO_YELLOW;
				setTimer1(200);
			}
			break;
		case AUTO_YELLOW:
			traffic_light(YELLOW_LIGHT);
			if (timer1_flag == 1) {
				status = AUTO_RED;
				setTimer1(500);
			}
			break;
		default:
			break;
	}
}
