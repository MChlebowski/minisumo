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
			PORTD &= 0x7f;//~0x80;
		}
		else
		{
			PORTD |= 0x80;
			PORTB &= 0xfe;//~0x01;
		}
		OCR1A = speed;
	}
	else
	{
		if(direction == STRAIGHT)
		{
			
		}
		else
		{
			
		}
		OCR1B = speed;
	}
}