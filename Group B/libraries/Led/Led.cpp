
#include "Led.h"

Led::Led(int pin, int delay) {
	// Your code here
	ledPin = pin;
	blinkDelay = delay;
}

void Led::turnOn() {
	// Your code here
	digitalWrite(ledPin, HIGH);
}

void Led::turnOff() {
	// Your code here
	digitalWrite(ledPin, LOW);
}

void Led::turnOnDim(int brightness) {
	// Your code here
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
