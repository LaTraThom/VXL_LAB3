/*
 * global.h
 *
 *  Created on: Nov 15, 2024
 *      Author: TIEN DUY
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_setting.h"
#include "traffic_light.h"
#include "led7_segment.h"
#include "main.h"

#define INIT 1
#define AUTO_RED_GREEN 2
#define AUTO_RED_YELLOW 3
#define AUTO_GREEN_RED 4
#define AUTO_YELLOW_RED 5

#define RED_GREEN 11
#define RED_YELLOW 12
#define GREEN_RED 13
#define YELLOW_RED 14

extern int RED_TIME;
extern int YELLOW_TIME;
extern int GREEN_TIME;
extern int status;
extern int time_lane1;
extern int time_lane2;
extern int index_led;
#endif /* INC_GLOBAL_H_ */
