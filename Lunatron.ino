#include <avr/io.h>
#include <avr/interrupt.h>
#include "motor.h"
#include "state.h"

void setup()
{

  /* add setup code here */
	Serial.begin(57600);
}

void loop()
{

  /* add main program code here */
	checkSerial();
}

void checkSerial()
{
	if (Serial.available() > 0)
	{
		char input = Serial.read();
		switch (input){
		case '0':
			for (int h = 0; h < 6; h++)
				Motor::location[h]->setDir(State::BRAKE);
			break;
		case '1':
			for (int h = 0; h < 6; h++)
				Motor::location[h]->setDir(State::FWD);
			break;
		case '2':
			for (int h = 0; h < 6; h++)
				Motor::location[h]->setDir(State::REV);
			break;
		}
		}
}
