#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include "barrier.h"

void stopBarrier(){
	pwmWrite(PIN,0);
	printf("Barrier stopped !\n");
}

int main(){
	Barrier b;
	int i; 
	if(wiringPiSetup() == -1)
		exit(1);

	setupBarrier(&b);
	for(i = 0; i < 3; i++){
		sleep(1);
		moveBarrier(&b);
	}
	sleep(1);
	stopBarrier();
	
	return 0;
}
