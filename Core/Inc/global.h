/*
 * global.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include <stdio.h>
#include "main.h"
#include "software_timer.h"
#include "fsm.h"
#include "button1.h"
#include "button2.h"
#include "button3.h"
#include "i2c-lcd.h"

extern int mode;
extern int temp[3];

extern int redTime;
extern int yellowTime;
extern int greenTime;

// Timer cycle in milliseconds
extern int TIMER_CYCLE;

// Timer flags and counters
extern int timer_counter;
extern int timer_flag;

extern int timer_counter_side;
extern int timer_flag_side;

extern int display_timer_counter;
extern int display_timer_flag;

extern int idx;

extern int curState;
extern int curSideState;

#endif /* INC_GLOBAL_H_ */
