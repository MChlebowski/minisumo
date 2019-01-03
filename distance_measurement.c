#include "distance_measurement.h"

#include <util/delay.h>
#include <avr/io.h>

//D0 - left
//D1 - right
//D2 - middle

int findEnemy(int sensorNumber) {
	switch(sensorNumber)
	{
		case LEFT_DISTANCE_SENSOR:
		return PIND & 0x01;
	}
}
