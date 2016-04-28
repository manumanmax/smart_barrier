#include "init.h"
#include <time.h>
#include <stdio.h>

int main(){
	init_setup();
	int i,x;
	for(;;){
		if((tracking(TRACK_SENS1))){
			red_led_on();
		}
		else {
			green_led_on();
                }
	}
	return 0;
}
