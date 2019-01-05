#include "timer_control.h"

#include <avr/io.h>

unsigned int counter = 0;

void setTimerMs(int ms)
{
	counter = ms / 16; //check prescaler
	TCNT0 = 0x00;
	TIFR=0x01;
}

int checkTimer() //true if it hasnt expired
{
	if(counter)
	{
		if ((TIFR & 0x01) == 0)
		{
			TCNT0 = 0x00;
			TIFR=0x01; //clear timer1 overflow flag
			--counter;
		}
	}
	return counter;
}