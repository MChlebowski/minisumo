#include "distance_measurement.h"

#include <util/delay.h>
#include <avr/io.h>

int measureDistance(int triggerPort, int triggerPin, int echoPort, int echoPin) {
	triggerPort |= (1<<triggerPin);
	_delay_us(10);
	triggerPort &= ~(1<<triggerPin);
	while(echoPort & (1<<echoPin));
	long time = ICR1;
	while(~echoPort & (1<<echoPin));
	time = ICR1 - time;
	return time * 34 / 2000;
}
