#include "sensor.h"
#include <wiringPi.h>
 
int tracking(int sensor){
	return digitalRead(sensor);
}
