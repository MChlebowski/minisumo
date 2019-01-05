#include <avr/io.h>
#include <util/delay.h>

#include "state.h"
#include "distance_measurement.h"
#include "white_line_measurement.h"
#include "motor_control.h"

int main(void)
{
    DDRC = 0x00; //input
    DDRD = 0xff; //output
    DDRB = 0xff; //output
	
	TCCR1A |= (1<<WGM10);//Tryb: Fast PWM 8bit
	TCCR1B |= (1<<WGM12);
	TCCR1A |= (1<<COM1A1)|(1<<COM1B1);//Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM
	TCCR1B |= (1<<CS10)|(1<<CS11);//Preksaler = 64,  fpwm = 976,5Hz
	
	ADCSRA = (1<<ADEN) //ADEN=1 w??czenie przetwornika ADC)
	    |(1<<ADPS0) // ustawienie preskalera na 128
	    |(1<<ADPS1)
	    |(1<<ADPS2);
	
	State* currentState;
    while (1) 
    {/*
		OCR1A = 0;
		PORTD |= 0x80;
		PORTB &= ~0x01;
		_delay_ms(2000);
		PORTB |= 0x01;
		PORTD &= ~0x80;
		_delay_ms(2000);
		*/
	    setMotorSpeed(LEFT_MOTOR, STRAIGHT, STOP);
	    _delay_ms(2000);
	    setMotorSpeed(RIGHT_MOTOR, STRAIGHT, STOP);
	    _delay_ms(2000);
		setMotorSpeed(LEFT_MOTOR, STRAIGHT, FAST);
		_delay_ms(2000);
		setMotorSpeed(LEFT_MOTOR, BACK, FAST);
		_delay_ms(2000);
		setMotorSpeed(LEFT_MOTOR, STRAIGHT, MEDIUM);
		_delay_ms(2000);
		setMotorSpeed(LEFT_MOTOR, STRAIGHT, SLOW);
		_delay_ms(2000);
		setMotorSpeed(LEFT_MOTOR, BACK, MEDIUM);
		_delay_ms(2000);
		setMotorSpeed(LEFT_MOTOR, BACK, SLOW);
		_delay_ms(2000);
		/*
		if(checkWhiteLine(RIGHT_WHITE_LINE))
			PORTB |= 1<<PORTB0;
		else
			PORTB &= ~(1<<PORTB0);
		if(checkWhiteLine(LEFT_WHITE_LINE))
			PORTB |= 1<<PORTB1;
		else
			PORTB &= ~(1<<PORTB1);
		//_delay_ms(500);
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