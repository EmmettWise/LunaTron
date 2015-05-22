/*
	motor.h - Library for controlling multiple motors
	Created by Nicole Devos, June 6, 2014
	NOTE: default pin for motor class is 2
		default dutyCycle for motor class is 0
*/
#ifndef Motor_h
#define Motor_h

#include "Arduino.h"
#include "state.h"
#include "LoadCell.h"

class Motor
{
public:
	static Motor FL, ML, BL, FR, MR, BR;
	~Motor();
	void setDuty(int cycle);
	void setDir(State& state);
	void switchDir();
	State& read();
	static Motor* location[6];

private:
	Motor(int PWMpin, int pinA, int pinB, State& dir, LoadCell& location);
	LoadCell* _LoadSensor;
	int _PWMpin;
	int _pinA;
	int _pinB;
	int _dutyCycle;
	State* _dir;
};

#endif
