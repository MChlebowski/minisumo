#include <avr/io.h>

#include "state.h"
#include "distance_measurement.h"
#include "white_line_measurement.h"
#include "motor_control.h"

extern State prepare;

int main(void)
{
	//to check
    DDRC = 0x00; //input
    DDRD = 0xff; //output
    DDRB = 0xff; //output
	
	TCCR1A |= (1<<WGM10);//Mode: Fast PWM 8bit
	TCCR1B |= (1<<WGM12);
	TCCR1A |= (1<<COM1A1)|(1<<COM1B1);//Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM
	TCCR1B |= (1<<CS10)|(1<<CS11);//Prescaler = 64,  fpwm = 976,5Hz
	OCR1A = 255;
	OCR1B = 255;
	
	TCCR0 = (1<<CS00) | (1<<CS02); // perpare timer
	
	State* currentState = &prepare;
	currentState->onEntry();
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

// 01 00 01 00
// 00 01 01 00
// 00 01 01 00