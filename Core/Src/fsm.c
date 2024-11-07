/*
 * fsm.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#include "fsm.h"

int temp[3] = {5000, 2000, 3000};
int mode = 0;
int curState = 0;
int curSideState = 1;


void displayContent() {
    lcd_clear_display();

    if (mode == 0) {
        int temp_main = timer_counter / 100;
        int temp_side = timer_counter_side / 100;

        lcd_goto_XY(1, 0);
        lcd_send_string(" Main: ");
        char mainTimeStr[7];
        snprintf(mainTimeStr, sizeof(mainTimeStr), "%d", temp_main);
        lcd_send_string(mainTimeStr);

        lcd_goto_XY(2, 0);
        lcd_send_string("Side: ");
        char sideTimeStr[7];
        snprintf(sideTimeStr, sizeof(sideTimeStr), "%d", temp_side);
        lcd_send_string(sideTimeStr);

    } else {
        lcd_goto_XY(1, 0);
        lcd_send_string(" Mode: ");
        char modeStr[3];
        snprintf(modeStr, sizeof(modeStr), "%d", mode);
        lcd_send_string(modeStr);

        lcd_goto_XY(2, 0);
        lcd_send_string("Duration: ");
        char durationStr[7];
        snprintf(durationStr, sizeof(durationStr), "%d", temp[mode - 1]);
        lcd_send_string(durationStr);
    }
}

void fsm_run(){
	switch(mode){
	case 0:{
		if (display_timer_flag) {
			display_timer_flag = 0;
			setDisplayTimer(250);
			displayContent();
		}
		if (timer_flag) {
			timer_flag = 0;

			switch (curState) {
			case 0:
				curState = 1;

				HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_RESET);

				setTimer(greenTime);
				break;

			case 1:
				curState = 2;

				HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_SET);

				setTimer(yellowTime);
				break;

			case 2:
				curState = 0;

				HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_SET);

				setTimer(redTime);
				break;
			}
		}

		if (timer_flag_side) {
			timer_flag_side = 0;

			switch (curSideState) {
			case 0:
				curSideState = 1;

				HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_RESET);

				setTimerSide(greenTime);
				break;

			case 1:
				curSideState = 2;

				HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_SET);

				setTimerSide(yellowTime);
				break;

			case 2:
				curSideState = 0;

				HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_SET);

				setTimerSide(redTime);
				break;
			}
		}
		break;
	}
	case 1:{
		if (display_timer_flag) {
			display_timer_flag = 0;
			setDisplayTimer(250);
			HAL_GPIO_TogglePin(EN_A1_GPIO_Port, EN_A1_Pin);
			HAL_GPIO_TogglePin(EN_A2_GPIO_Port, EN_A2_Pin);
			HAL_GPIO_TogglePin(EN_B1_GPIO_Port, EN_B1_Pin);
			HAL_GPIO_TogglePin(EN_B2_GPIO_Port, EN_B2_Pin);
			displayContent();
		}

		break;
	}
	case 2:{
		if (display_timer_flag) {
			display_timer_flag = 0;
			setDisplayTimer(250);
			HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(EN_B1_GPIO_Port, EN_B1_Pin);
			HAL_GPIO_TogglePin(EN_B2_GPIO_Port, EN_B2_Pin);
			displayContent();
		}
		break;
	}
	case 3:{
		if (display_timer_flag) {
			display_timer_flag = 0;
			setDisplayTimer(250);
			HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(EN_A1_GPIO_Port, EN_A1_Pin);
			HAL_GPIO_TogglePin(EN_A2_GPIO_Port, EN_A2_Pin);
			displayContent();
		}
		break;
	}
	default:
		break;
	}
}
void init() {
	HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_SET);
    setTimer(redTime);

	HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_RESET);
    setTimerSide(greenTime);

    setDisplayTimer(250);

    curState = 0;
    curSideState = 1;

    idx = 0;
}

