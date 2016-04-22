#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "barrier.h"


int main(int argc, char* argv[]){
	int periode_time;
	Barrier b;

	if(argc < 2)
		periode_time = 75;
	else{
		sscanf(argv[1], "%d", &periode_time);
		printf("periode : %d\n", periode_time);
	}
 
	if(wiringPiSetup() == -1)
		exit(1);

	setupBarrier(periode_time);

	b.position = DOWN;
	/*moveBarrier(&b);*/
	return 0;
}
