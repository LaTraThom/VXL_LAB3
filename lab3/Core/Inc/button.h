/*
 * button.h
 *
 *  Created on: Nov 15, 2024
 *      Author: TIEN DUY
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

int isButton1Pressed();
int isButton1LongPressed();
int isButton2Pressed();
int isButton2LongPressed();
int isButton3Pressed();
int isButton3LongPressed();
void getKeyInput();
void subKeyProcess(int button_id);

#endif /* INC_BUTTON_H_ */
