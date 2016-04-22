#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "barrier.h"

void setupBarrier(Barrier* b){
	pinMode(1, PWM_OUTPUT); /* corresponds to pin 12 */ 
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(384);   
	pwmSetRange(512); /* adaptation of the clock frequency to the motor frequency */
	b->position = DOWN;
	pwmWrite(PIN, SET);
	
}

void moveBarrier(Barrier* b){
	printf("position : %d\n", b->position);	
	if(b->position == UP){
		printf("barrier up, I set it down with value %d\n",SET);
		b->position = DOWN;
		pwmWrite(PIN, SET);
	}
	else{
		printf("barrier down, I raise it with value %d\n",RAISED);
		b->position = UP;
		pwmWrite(PIN, RAISED);
	}
		
	
}

