/*
 * button3.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#ifndef INC_BUTTON3_H_
#define INC_BUTTON3_H_
#include "global.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET


//function prototype
void KeyInputHandler3();
void LongKeyInputHandler3();
void getKeyInput3();
#endif /* INC_BUTTON3_H_ */
