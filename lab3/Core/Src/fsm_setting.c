/*
 * fsm_setting.c
 *
 *  Created on: Nov 15, 2024
 *      Author: TIEN DUY
 */

#include "global.h"

void fsm_setting() {
	switch (MODE) {
	case MODE_RED_MODIFY:
		if (isButton2Pressed()) {
		   RED_TIME_MODIFY = RED_TIME_MODIFY + 1000;
		   if (RED_TIME_MODIFY > 99000) {
			   RED_TIME_MODIFY = 1000;
		   }
		}
		if (isButton3Pressed()) {
			RED_TIME = RED_TIME_MODIFY;
		}
		break;
	case MODE_YELLOW_MODIFY:
		if (isButton2Pressed()) {
		    YELLOW_TIME_MODIFY = YELLOW_TIME_MODIFY + 1000;
		    if (YELLOW_TIME_MODIFY > 99000) {
		    	YELLOW_TIME_MODIFY = 1000;
		    }
		}
		if (isButton3Pressed()) {
			YELLOW_TIME = YELLOW_TIME_MODIFY;
		}
		break;
	case MODE_GREEN_MODIFY:
		if (isButton2Pressed()) {
		    GREEN_TIME_MODIFY = GREEN_TIME_MODIFY + 1000;
		    if (GREEN_TIME_MODIFY > 99000) {
		    	GREEN_TIME_MODIFY = 1000;
		    }
		}
		if (isButton3Pressed()) {
			GREEN_TIME = GREEN_TIME_MODIFY;
		}
		break;
	default:
		break;
	}
}
