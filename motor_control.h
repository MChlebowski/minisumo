#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
#define STRAIGHT 0
#define BACK 1
#define STOP 0
#define SLOW 40
#define MEDIUM 75
#define FAST 100

void setMotorSpeed(int motorNumber, int direction, int speed);

#endif /* MOTOR_CONTROL_H_ */