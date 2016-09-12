#include "AnalogOut.h"

AnalogOut::AnalogOut(int pin) {
	pinNum = pin;
}

void AnalogOut::write(int value) {
	analogWrite(pinNum, value);
}

void AnalogOut::pulse(int value, int durationMs) {
	write(value);
	delay(durationMs);
	write(0);
}
