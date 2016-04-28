#include <wiringPi.h>
#include "led.h"
#include "sensor.h"
#include "init.h"

void init_setup(){
	wiringPiSetup();
	pinMode(RED_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(TRACK_SENS1, INPUT);
	pinMode(TRACK_SENS2, INPUT);
}