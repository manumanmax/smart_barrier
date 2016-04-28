#include <time.h>
#include <stdio.h>
#include "init.h"
#include <wiringPi.h>
#include "barrier.h"
#include "rfid.h"

int main(){
	int i;
	Barrier b;
	 
	if(wiringPiSetup() == -1)
		exit(1);

	setupBarrier(&b);
	while(1){
  	if(rfid_cycle()){
  		moveBarrier(&b);
		delay(200);
  	}
	}
        stopBarrier();
  	return 0;
}
