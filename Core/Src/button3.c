/*
 * button3.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#include "button3.h"


static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;

static int KeyReg3 = NORMAL_STATE;

static int TimerForKeyPress = 200;


void KeyInputHandler3(){
	if(mode == 1){
		redTime = temp[mode-1];
		greenTime = redTime - yellowTime;
		temp[2] = greenTime;
	}
	else if(mode == 2){
		yellowTime = temp[mode-1];
		redTime = yellowTime+greenTime;
		temp[0] = redTime;
	}
	else if(mode == 3){
		greenTime = temp[mode-1];
		redTime = yellowTime+greenTime;
		temp[0] = redTime;
	}
	if (mode) {
		init();
		mode = 0;
	}
}
void LongKeyInputHandler3(){
	KeyInputHandler3();
}

void getKeyInput3(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				KeyInputHandler3();
				TimerForKeyPress = 200;
			}
		}
		else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				if(KeyReg2 == PRESSED_STATE){
					LongKeyInputHandler3();
				}
				TimerForKeyPress = 200;
			}
		}
	}
}


