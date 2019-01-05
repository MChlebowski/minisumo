#include "control_module.h"

#include <avr/io.h>

int checkStart()
{
	return !(PINC & 0x04); //TODO start switch pin
}

int checkStop()
{
	return !(PINC & 0x08); //TODO stop switch pin
}