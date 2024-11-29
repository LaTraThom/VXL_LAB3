/*
 * fsm_automatic.c
 *
 *  Created on: Nov 15, 2024
 *      Author: TIEN DUY
 */

#include "fsm_automatic.h"
#include "traffic_light.h"
#include "global.h"
int RED_TIME = 5000;
int YELLOW_TIME = 2000;
int GREEN_TIME = 3000;
int status = INIT;
void fsm_automatic(){
	switch (status){
		case INIT:
			HAL_GPIO_WritePin(LED_1_RED_GPIO_Port, LED_1_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_2_GREEN_GPIO_Port, LED_2_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_3_YELLOW_GPIO_Port, LED_3_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_4_RED_GPIO_Port, LED_4_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_5_GREEN_GPIO_Port, LED_5_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_6_YELLOW_GPIO_Port, LED_6_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_7_RED_GPIO_Port, LED_7_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_8_GREEN_GPIO_Port, LED_8_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_9_YELLOW_GPIO_Port, LED_9_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_10_RED_GPIO_Port, LED_10_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_11_GREEN_GPIO_Port, LED_11_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_12_YELLOW_GPIO_Port, LED_12_YELLOW_Pin, SET);
			status =  AUTO_RED_GREEN;
	        time_lane1 = RED_TIME / 1000;
	        time_lane2 = GREEN_TIME / 1000;
			setTimer1(GREEN_TIME);
			setTimer2(1000);
			setTimer3(100);
			break;
		case AUTO_RED_GREEN:
			traffic_light(RED_GREEN);
			led7_segment();
	        if (timer2_flag == 1) {
	        	timer2_flag = 0;
	        	time_lane1--;
	        	time_lane2--;
	        	setTimer2(1000);
	        }
			if (timer1_flag == 1) {
				timer1_flag = 0;
				status = AUTO_RED_YELLOW;
		        time_lane1 = RED_TIME / 1000;
		        time_lane2 = YELLOW_TIME / 1000;
				setTimer1(YELLOW_TIME);
				setTimer2(1000);
				setTimer3(100);
			}
			break;
		case AUTO_RED_YELLOW:
			traffic_light(RED_YELLOW);
			led7_segment();
	        if (timer2_flag == 1) {
	        	timer2_flag = 0;
	        	time_lane1--;
	        	time_lane2--;
	        	setTimer2(1000);
	        }
			if (timer1_flag == 1) {
				timer1_flag = 0;
				status = AUTO_GREEN_RED;
		        time_lane1 = GREEN_TIME / 1000;
		        time_lane2 = RED_TIME / 1000;
				setTimer1(GREEN_TIME);
				setTimer2(1000);
				setTimer3(100);
			}
			break;
		case AUTO_GREEN_RED:
			traffic_light(GREEN_RED);
			led7_segment();
	        if (timer2_flag == 1) {
	        	timer2_flag = 0;
	        	time_lane1--;
	        	time_lane2--;
	        	setTimer2(1000);
	        }
			if (timer1_flag == 1) {
				timer1_flag = 0;
				status = AUTO_YELLOW_RED;
		        time_lane1 = YELLOW_TIME / 1000;
		        time_lane2 = RED_TIME / 1000;
				setTimer1(YELLOW_TIME);
				setTimer2(1000);
				setTimer3(100);
			}
			break;
		case AUTO_YELLOW_RED:
			traffic_light(YELLOW_RED);
			led7_segment();
	        if (timer2_flag == 1) {
	        	timer2_flag = 0;
	        	time_lane1--;
	        	time_lane2--;
	        	setTimer2(1000);
	        }
			if (timer1_flag == 1) {
				timer1_flag = 0;
				status = AUTO_RED_GREEN;
				led7_segment(RED_GREEN);
				setTimer1(GREEN_TIME);
				setTimer2(1000);
				setTimer3(100);
			}
			break;
		default:
			break;
	}
}
