#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer(int thePinNum) {
	pinNum = thePinNum;
}

int Potentiometer::getValue() {
	return analogRead(pinNum);
}

int Potentiometer::getPercent() {
	return (int) (analogRead(pinNum) * 100.0 / 1023.0);
}
