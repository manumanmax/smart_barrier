#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "barrier.h"
#include <time.h>

void setupBarrier(){
	pinMode(1, PWM_OUTPUT); /* corresponds to pin 12 */ 
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(19200000);   
	pwmSetRange(200); /* adaptation of the clock frequency to the motor frequency */
	//pwmWrite(PIN, SET);
	
}
void stopBarrier()	
{
	pwmWrite(PIN,0);
	printf("barrier stop\n");	
}

void moveBarrierUp(){
        printf("Barrier is down, I raise it with value %d\n", RAISED);
        pwmWrite(PIN, RAISED);
	sleep(1);
		stopBarrier();
}

void moveBarrierDown(){
        printf("barrier up, I set it down with value %d\n", SET);
        pwmWrite(PIN, SET);
	sleep(1);
		stopBarrier();
}

