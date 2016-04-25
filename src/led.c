#include "led.h"
#include <wiringPi.h>

void all_led_off(){
	digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
}

void red_led_on(){
	all_led_off();
	digitalWrite(RED_LED, HIGH);
}

void green_led_on(){
	all_led_off();
	digitalWrite(GREEN_LED, HIGH);
}

void yellow_led_on(){
	all_led_off();
	digitalWrite(RED_LED, HIGH);
	digitalWrite(GREEN_LED, HIGH);
}

void blink_yellow_led(){
	int i;
	for(i=0;i<4;i++){
		yellow_led_on();
		delay(300);
		all_led_off();
		delay(300);
	}
}



