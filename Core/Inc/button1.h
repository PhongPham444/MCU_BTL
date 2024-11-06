/*
 * button1.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#ifndef INC_BUTTON1_H_
#define INC_BUTTON1_H_
#include "global.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET

//function prototype
void KeyInputHandler1();
void LongKeyInputHandler1();
void getKeyInput1();

#endif /* INC_BUTTON1_H_ */
