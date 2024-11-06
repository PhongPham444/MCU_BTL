/*
 * software_timer.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "software_timer.h"
int redTime = 5000;
int yellowTime = 2000;
int greenTime = 3000;

int TIMER_CYCLE = 10;
int timer_counter = 0, timer_flag = 0;
int timer_counter_side = 0, timer_flag_side = 0;
int display_timer_counter = 0, display_timer_flag = 0;

int idx = 0;

void setTimer(int duration) {
    timer_counter = duration / TIMER_CYCLE;
    timer_flag = 0;
}
void setTimerSide(int duration) {
    timer_counter_side = duration / TIMER_CYCLE;
    timer_flag_side = 0;
}
void setDisplayTimer(int duration) {
    display_timer_counter = duration / TIMER_CYCLE;
    display_timer_flag = 0;
}

void timer_run() {
    if (timer_counter > 0) {
        timer_counter--;
        if (timer_counter == 0) {
            timer_flag = 1;
        }
    }
    if (timer_counter_side > 0) {
		timer_counter_side--;
		if (timer_counter_side == 0) {
			timer_flag_side = 1;
		}
	}
    if (display_timer_counter > 0) {
		display_timer_counter--;
		if (display_timer_counter == 0) {
			display_timer_flag = 1;
			idx = (idx + 1) % 4;
		}
	}
}

