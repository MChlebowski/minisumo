#ifndef STATE_H_
#define STATE_H_

typedef struct StateType {
	void (*onEntry)(void);
	struct StateType* (*nextState)(void);
} State;

void prepareEntry();
State* nextFromPrepare();

void idleEntry();
void goStraightEntry();
void goLeftEntry();
void goRightEntry();
State* nextInFight();

void goBackEntry();
State* nextFromGoBack();

void stopEntry();
State* nextFromStop();
	
#endif /* STATE_H_ */