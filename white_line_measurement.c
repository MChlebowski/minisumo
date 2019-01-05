#include "white_line_measurement.h"

#include <avr/io.h>

//C0 - right
//C1 - left

int checkWhiteLine(int sensorNumber)
{
	switch(sensorNumber)
	{
		case LEFT_WHITE_LINE:
		return PINC & 0x02;
			ADMUX  =    (1<<REFS1) | (1<<REFS0);
			break;
		case RIGHT_WHITE_LINE:
		return PINC & 0x01;
			ADMUX  =    (1<<REFS1) | (1<<REFS0) | (1<<MUX0);
			break;
	}
	//ADMUX  =    0xc0;
	ADCSRA  |= (1<<ADSC);	// Start conversion
	while (ADCSRA &  (1<<ADSC));
	// wait until conversion  completes; ADSC=0 means Complete
	return ADC > 512;
}