#ifndef AnalogOut_h
#define AnalogOut_h

#include "Arduino.h"

class AnalogOut {
private:
	int pinNum;
public:
	AnalogOut(int pin);
	void write(int value);
	void pulse(int value, int durationMs);
};

#endif
