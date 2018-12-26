#ifndef STATE_H_
#define STATE_H_

typedef struct StateType {
	void (*onEntry)(void);
	struct StateType* (*nextState)(void);
} State;

void prepareEntry();
State* nextFromPrepare();

void idleEntry();
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

#endif /* STATE_H_ */