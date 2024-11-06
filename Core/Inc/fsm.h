/*
 * fsm.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_
#include "global.h"

void display7SEG(int num);          // Display number on 7-segment display
void updateClockBuffer();           // Update buffer for 7-segment display
void displayMode();                 // Display mode on 7-segment
void displayTime();                 // Display time on 7-segment
void fsm_run();
void init();
#endif /* INC_FSM_H_ */
