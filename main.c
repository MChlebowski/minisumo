#include <avr/io.h>
#include <util/delay.h>

#include "state.h"
#include "distance_measurement.h"

void prepareEntry();
State* nextFromPreare();

void idleEnty();
State* nextFromIdle();

void goStraightEntry();
State* nextFromGoStraight();

void goLeftEntry();
State* nextFromGoLeft();

void goRightEntry();
State* nextFromGoRight();

void goBackEntry();
State* nextFromGoBack();

void stopEntry();
State* nextFromStop();

int main(void)
{
	State prepare = {.onEntry = prepareEntry, .nextState = nextFromPrepare};
	State idle = {.onEntry = idleEntry, .nextState = nextFromIdle};
	State goStraight = {.onEntry = goStraightEntry, .nextState = nextFromGoStraight};
	State goLeft = {.onEntry = goLeftEntry, .nextState = nextFromGoLeft};
	State goRight = {.onEntry = goRightEntry, .nextState = nextFromGoRight};
	State goBack = {.onEntry = goBackEntry, .nextState = nextFromGoBack};
	State stop = {.onEntry = stopEntry, .nextState = nextFromStop};
		
		
    DDRC = 0xf0; //input
    //DDRC = 0xff; //output
    PORTC &= ~(1<<5);
	_delay_ms(1000);
	PORTC |= 1<<5;
	_delay_ms(1000);
	
    while (1) 
    {
		if (measureDistance(PINC, 3, PORTC, 4) > 20){
			PORTC &= ~(1<<5);
		}
		else {
			PORTC |= 1<<5;
		}
		_delay_ms(50);
		
    }
}

