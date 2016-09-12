
#include "Led.h"

Led::Led(int pin, int delay) {
	pinMode(pin, OUTPUT);
	ledPin=pin;
}

void Led::turnOn() {
	digitalWrite(ledPin, HIGH);
}

void Led::turnOff() {
	digitalWrite(ledPin, LOW);
}

void Led::turnOnDim(int brightness) {
	analogWrite(ledPin, brightness);
}


void Led::cycle(int count, int dutyCycle) {
	// Your code here
}

void Led::rampUp(int steps, int delayMs) {
	// Your code here
}

void Led::rampDown(int steps, int delayMs) {
	// Your code here
}
