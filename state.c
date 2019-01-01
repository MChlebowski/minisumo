#include "state.h"
#include "distance_measurement.h"
#include "white_line_measurement.h"
#include "motor_control.h"
#include "led_control.h"
#include "control_module.h"
#include "timer_control.h"

State prepare = {.onEntry = prepareEntry, .nextState = nextFromPrepare};
State idle = {.onEntry = idleEntry, .nextState = nextInFight};
State goStraight = {.onEntry = goStraightEntry, .nextState = nextInFight};
State goLeft = {.onEntry = goLeftEntry, .nextState = nextInFight};
State goRight = {.onEntry = goRightEntry, .nextState = nextInFight};
State goBack = {.onEntry = goBackEntry, .nextState = nextFromGoBack};
State stop = {.onEntry = stopEntry, .nextState = nextFromStop};

void prepareEntry()
{
	setLed(1, 1);
	setMotorSpeed(LEFT_MOTOR, STRAIGHT, STOP);
	setMotorSpeed(RIGHT_MOTOR, STRAIGHT, STOP);
}

State* nextFromPrepare()
{
	return checkStart() ? &idle : &prepare;
}

void idleEntry()
{
	setLed(1, 0);
	setMotorSpeed(LEFT_MOTOR, STRAIGHT, SLOW);
	setMotorSpeed(RIGHT_MOTOR, STRAIGHT, MEDIUM);
}

void goStraightEntry()
{
	setMotorSpeed(LEFT_MOTOR, STRAIGHT, FAST);
	setMotorSpeed(RIGHT_MOTOR, STRAIGHT, FAST);
}

void goLeftEntry()
{
	setMotorSpeed(LEFT_MOTOR, STRAIGHT, FAST);
	setMotorSpeed(RIGHT_MOTOR, STRAIGHT, MEDIUM);
}

void goRightEntry()
{
	setMotorSpeed(LEFT_MOTOR, STRAIGHT, MEDIUM);
	setMotorSpeed(RIGHT_MOTOR, STRAIGHT, FAST);
}

State* nextInFight()
{
	if(checkStop())
	{
		return &stop;
	}
	if(checkWhiteLine(LEFT_WHITE_LINE))
	{
		return &goRight;
	}
	if(checkWhiteLine(RIGHT_WHITE_LINE))
	{
		return &goLeft;
	}
	if(checkWhiteLine(FRONT_WHITE_LINE))
	{
		return &goBack;
	}
	
	int rightFound = findEnemy(RIGHT_DISTANCE_SENSOR);
	int leftFound = findEnemy(LEFT_DISTANCE_SENSOR);
	int frontFound = findEnemy(FRONT_DISTANCE_SENSOR);
	if(frontFound || (rightFound && leftFound))
	{
		return &goStraight;
	}
	if(rightFound)
	{
		return &goRight;
	}
	if(leftFound)
	{
		return &goLeft;
	}
	return &idle;
}

void goBackEntry()
{
	setMotorSpeed(LEFT_MOTOR, BACK, FAST);
	setMotorSpeed(RIGHT_MOTOR, BACK, FAST);
	setTimerMs(500);
}

State* nextFromGoBack()
{
	State* nextStateInFight = nextInFight();
	if(nextStateInFight == &idle && checkTimer())
	{
		return &goBack;
	}
	return nextStateInFight;
}