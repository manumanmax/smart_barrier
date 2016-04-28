#include <time.h>
#include <stdio.h>
#include "init.h"
#include <wiringPi.h>
#include "barrier.h"


void stopBarrier()	
{
	pwmWrite(PIN,0);
	printf("barrier stop/n");
	
}
int main(){
	int i;
	Barrier b;
	if(wiringPiSetup() == -1)
		exit(1);

	setupBarrier(&b);
  	for(i = 0; i < 4; i++){
  		sleep(1);
  		moveBarrier(&b);
  	}
  	sleep(1);
  	stopBarrier();
	return 0;
}
