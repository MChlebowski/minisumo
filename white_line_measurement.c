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
		case RIGHT_WHITE_LINE:
			return PINC & 0x01;
	}
}