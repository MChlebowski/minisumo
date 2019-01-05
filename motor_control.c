#include "motor_control.h"

#include <avr/io.h>

//PD7 - back
//PB0 - forward

void setMotorSpeed(int motorNumber, int direction, int speed)
{
	if(motorNumber == LEFT_MOTOR)
	{
		if(direction == STRAIGHT)
		{
			PORTB |= 0x01;
			PORTD &= 0x7f;
		}
		else
		{
			PORTD |= 0x80;
			PORTB &= 0xfe;
		}
		OCR1A = speed;
	}
	else //TODO
	{
		if(direction == STRAIGHT)
		{
			PORTB |= 0x01;
			PORTD &= 0x7f;
		}
		else
		{
			PORTD |= 0x80;
			PORTB &= 0xfe;
		}
		OCR1B = speed;
	}
}