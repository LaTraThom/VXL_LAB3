/*
 * button.c
 *
 *  Created on: Nov 15, 2024
 *      Author: TIEN DUY
 */
#include "button.h"
#include "main.h"
//BUTTON 1
int KeyReg0_1 = NORMAL_STATE;
int KeyReg1_1 = NORMAL_STATE;
int KeyReg2_1 = NORMAL_STATE;
int KeyReg3_1 = NORMAL_STATE;
//BUTTON 2
int KeyReg0_2 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;
int KeyReg3_2 = NORMAL_STATE;
//BUTTON 3
int KeyReg0_3 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;
int KeyReg3_3 = NORMAL_STATE;

int TimeOutForKeyPress1 = 500;
int TimeOutForKeyPress2 = 500;
int TimeOutForKeyPress3 = 500;

int button1_pressed = 0;
int button1_long_pressed = 0;
int button1_flag = 0;

int button2_pressed = 0;
int button2_long_pressed = 0;
int button2_flag = 0;

int button3_pressed = 0;
int button3_long_pressed = 0;
int button3_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(){
	if(button1_long_pressed == 1){
		button1_long_pressed = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2LongPressed(){
	if(button2_long_pressed == 1){
		button2_long_pressed = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3LongPressed(){
	if(button3_long_pressed == 1){
		button3_long_pressed = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int button_id){
	//TODO
    switch (button_id) {
        case 1:
            button1_flag = 1;
            break;
        case 2:
            button2_flag = 1;
            break;
        case 3:
            button3_flag = 1;
            break;
        default:
            break;
    }
}

void getKeyInput(){
    // Xử lý button 1
    KeyReg2_1 = KeyReg1_1;
    KeyReg1_1 = KeyReg0_1;
    KeyReg0_1 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

    if ((KeyReg1_1 == KeyReg0_1) && (KeyReg1_1 == KeyReg2_1)) {
        if (KeyReg2_1 != KeyReg3_1) {
            KeyReg3_1 = KeyReg2_1;
            if (KeyReg3_1 == PRESSED_STATE) {
                TimeOutForKeyPress1 = 500;
                subKeyProcess(1);
            }
        } else {
            TimeOutForKeyPress1--;
            if (TimeOutForKeyPress1 == 0) {
                TimeOutForKeyPress1 = 500;
                if (KeyReg3_1 == PRESSED_STATE) {
                    subKeyProcess(1);
                }
            }
        }
    }

    // Xử lý button 2
    KeyReg2_2 = KeyReg1_2;
    KeyReg1_2 = KeyReg0_2;
    KeyReg0_2 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);

    if ((KeyReg1_2 == KeyReg0_2) && (KeyReg1_2 == KeyReg2_2)) {
        if (KeyReg2_2 != KeyReg3_2) {
            KeyReg3_2 = KeyReg2_2;
            if (KeyReg3_2 == PRESSED_STATE) {
                TimeOutForKeyPress2 = 500;
                subKeyProcess(2);
            }
        } else {
            TimeOutForKeyPress2--;
            if (TimeOutForKeyPress2 == 0) {
                TimeOutForKeyPress2 = 500;
                if (KeyReg3_2 == PRESSED_STATE) {
                    subKeyProcess(2);
                }
            }
        }
    }

    // Xử lý button 3
    KeyReg2_3 = KeyReg1_3;
    KeyReg1_3 = KeyReg0_3;
    KeyReg0_3 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

    if ((KeyReg1_3 == KeyReg0_3) && (KeyReg1_3 == KeyReg2_3)) {
        if (KeyReg2_3 != KeyReg3_3) {
            KeyReg3_3 = KeyReg2_3;
            if (KeyReg3_3 == PRESSED_STATE) {
                TimeOutForKeyPress3 = 500;
                subKeyProcess(3);
            }
        } else {
            TimeOutForKeyPress3--;
            if (TimeOutForKeyPress3 == 0) {
                TimeOutForKeyPress3 = 500;
                if (KeyReg3_3 == PRESSED_STATE) {
                    subKeyProcess(3);
                }
            }
        }
    }
}



