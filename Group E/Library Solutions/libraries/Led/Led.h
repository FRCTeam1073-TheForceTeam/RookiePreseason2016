#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led {
private:
	int ledPin;
	int blinkDelay;
public:
	Led(int pin, int delay = 500);
	void turnOn();
	void turnOff();
	void turnOnDim(int brightness);
	void cycle(int count, int dutyCycle = 50);
	void rampUp(int steps, int delayMs);
	void rampDown(int steps, int delayMs);
};

#endif
