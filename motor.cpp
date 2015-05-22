#include "Arduino.h"
#include "motor.h"
#include "state.h"

Motor Motor::BL(2, 22, 24, State::BRAKE, LoadCell::BL);
Motor Motor::ML(3, 28, 30, State::BRAKE, LoadCell::ML);
Motor Motor::FL(4, 34, 36, State::BRAKE, LoadCell::FL);
Motor Motor::FR(5, 40, 42, State::BRAKE, LoadCell::FR);
Motor Motor::MR(6, 46, 48, State::BRAKE, LoadCell::MR);
Motor Motor::BR(7, 53, 51, State::BRAKE, LoadCell::BR);

Motor* Motor::location[6] = { &Motor::BL, &Motor::ML, &Motor::FL, &Motor::FR, &Motor::MR, &Motor::BR };

Motor::Motor(int pin, int A, int B, State& dir, LoadCell& location)
{
	_PWMpin = pin;
	_dutyCycle = 40;
	_pinA = A;
	_pinB = B;
	_dir = &dir;
	_LoadSensor = &location;
	pinMode(_PWMpin, OUTPUT);
	analogWrite(_PWMpin, _dutyCycle);
	pinMode(_pinA, OUTPUT);
	pinMode(_pinB, OUTPUT);
	setDir(*_dir);
}

Motor::~Motor()
{	
}

void Motor::setDuty(int cycle)
{
	_dutyCycle = cycle;
	analogWrite(_PWMpin, _dutyCycle);
}

void Motor::setDir(State& state)
{
	_dir = &state;
	digitalWrite(_pinA, state.readA());
	digitalWrite(_pinB, state.readB());
}

void Motor::switchDir()
{
	_dir=&(_dir->opposite());
}

State& Motor::read()
{
	return *_dir;
}

