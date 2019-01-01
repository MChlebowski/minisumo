#include <avr/io.h>
#include <util/delay.h>

#include "state.h"
#include "distance_measurement.h"

int main(void)
{
		
		
    DDRC = 0xf0; //input
    //DDRC = 0xff; //output
    PORTC &= ~(1<<5);
	_delay_ms(1000);
	PORTC |= 1<<5;
	_delay_ms(1000);
	
	State* currentState;
    while (1) 
    {
		State* previousState = currentState;
		currentState = currentState->nextState();
		if(currentState != previousState)
		{
			currentState->onEntry();
		}
    }
}

