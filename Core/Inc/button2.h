/*
 * button2.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#ifndef INC_BUTTON2_H_
#define INC_BUTTON2_H_

#include "global.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET

//function prototype
void KeyInputHandler2();
void LongKeyInputHandler2();
void getKeyInput2();

#endif /* INC_BUTTON2_H_ */
