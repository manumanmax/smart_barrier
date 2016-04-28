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
	
  	if(rfid_cycle()){
  		moveBarrier(&b);
  	}
	
        stopBarrier();
  	return 0;
}
