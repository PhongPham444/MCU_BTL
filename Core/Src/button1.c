/*
 * button1.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#include "button1.h"

static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;

static int KeyReg3 = NORMAL_STATE;

static int TimerForKeyPress = 200;

void KeyInputHandler1(){
	mode++;
	if(mode >= 4){
		mode = 0;
	}
	else if (mode != 0){
		display_timer_flag = 1;
	}
	switch(mode){
	case 0:{
		lcd_clear_display();
		init();
		break;
	}
	case 1:{
		lcd_clear_display();
		HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_SET);
		break;
	}
	case 2:{
		lcd_clear_display();
		HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_SET);
		break;
	}
	case 3:{
		lcd_clear_display();
		HAL_GPIO_WritePin(EN_B1_GPIO_Port, EN_B1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN_B2_GPIO_Port, EN_B2_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(EN_A1_GPIO_Port, EN_A1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN_A2_GPIO_Port, EN_A2_Pin, GPIO_PIN_SET);
		break;
	}
	default:{
		break;
	}
	}
}
void LongKeyInputHandler1(){
	KeyInputHandler1();
}

void getKeyInput1(){

	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				KeyInputHandler1();
				TimerForKeyPress = 200;
			}
		}
		else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				if(KeyReg2 == PRESSED_STATE){
					LongKeyInputHandler1();
				}
				TimerForKeyPress = 200;
			}
		}
	}
}
