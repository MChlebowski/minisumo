#include <avr/io.h>
#include <util/delay.h>

#include "state.h"
#include "distance_measurement.h"
#include "white_line_measurement.h"

int main(void)
{
    DDRC = 0x00; //input
    DDRD = 0x00; //input
    DDRB = 0xff; //output
	
	ADCSRA  = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);
	ADMUX=0x05;
	
	State* currentState;
    while (1) 
    {
		if(findEnemy(LEFT_DISTANCE_SENSOR))
			PORTB |= 1<<PORTB0;
		else
			PORTB &= ~(1<<PORTB0);
		if(checkWhiteLine(LEFT_WHITE_LINE))
			PORTB |= 1<<PORTB1;
		else
			PORTB &= ~(1<<PORTB1);
		_delay_ms(500);
		/*
		State* previousState = currentState;
		currentState = currentState->nextState();
		if(currentState != previousState)
		{
			currentState->onEntry();
		}*/
    }
}

// 01 00 01 00
// 00 01 01 00
// 00 01 01 00