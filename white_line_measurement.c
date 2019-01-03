#include "white_line_measurement.h"

#include <avr/io.h>

//C0 - right
//C1 - left

int checkWhiteLine(int sensorNumber)
{
	switch(sensorNumber)
	{
		case LEFT_WHITE_LINE:
		ADCSRA  |= (1<<ADSC);	// Start conversion
		while (ADCSRA &  (1<<ADSC));
		// wait until conversion  completes; ADSC=0 means Complete

		return ADCW > 512;
	}
}