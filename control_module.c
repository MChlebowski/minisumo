#include "control_module.h"

#include <avr/io.h>

int checkStart()
{
	return !(PORTC & 0x04); //TODO
}

int checkStop()
{
	return !(PORTC & 0x08); //TODO
}