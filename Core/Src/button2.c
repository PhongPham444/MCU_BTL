/*
 * button2.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "button2.h"

static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;
static int KeyReg3 = NORMAL_STATE; // previous

static int TimerForKeyPress = 100;

void updateTempValue(int increment) {
	if (mode){
		temp[mode - 1] += increment;
		if (temp[mode - 1] > 99000) {
			temp[mode - 1] = 0;
		}
	}
}

void KeyInputHandler2() {
    updateTempValue(1000); // Handle short press
}

void LongKeyInputHandler2() {
    updateTempValue(5000); // Handle long press
}

void getKeyInput2() {
    KeyReg0 = KeyReg1;
    KeyReg1 = KeyReg2;
    KeyReg2 = HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin);

    if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) { // Debounced state
        if (KeyReg3 != KeyReg2) {
            KeyReg3 = KeyReg2;
            if (KeyReg2 == PRESSED_STATE) {
                KeyInputHandler2();
                TimerForKeyPress = 100; // Reset timer for long press
            }
        } else if (KeyReg2 == PRESSED_STATE) { // Button still pressed
            TimerForKeyPress--;
            if (TimerForKeyPress == 0) {
                LongKeyInputHandler2(); // Trigger long press action
                TimerForKeyPress = 100; // Reset timer after long press
            }
        }
    }
}
