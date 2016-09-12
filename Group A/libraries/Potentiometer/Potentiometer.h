#ifndef Potentiometer_h
#define Potentiometer_h

#include "Arduino.h"

class Potentiometer {
private:
	int pinNum;
public:
	Potentiometer(int thePinNum);
	int getValue ();
};

#endif
