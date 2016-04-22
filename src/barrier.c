#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "barrier.h"

void setupBarrier(int periode_time){
	pinMode(1, PWM_OUTPUT); /* corresponds to pin 12 */ 
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(384);   
	pwmSetRange(512); /* adaptation of the clock frequency to the motor frequency */
	pwmWrite(PIN, periode_time);
}

void moveBarrier(Barrier* b){
	printf("position : %d\n", b->position);	
	if(b->position == UP){
		b->position = DOWN;
		pwmWrite(PIN, SET);
	}
	if(b->position == DOWN){
		b->position = UP;
		pwmWrite(PIN, RAISED);
	}
		
	
}

