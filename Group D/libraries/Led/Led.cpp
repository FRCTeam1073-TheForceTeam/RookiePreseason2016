
#include "Led.h"
//this sets up everything needed for LED based on the parameters

Led::Led(int pin, int delay) {
	// Your code here
 pinMode(pin, OUTPUT);
 this->ledPin = pin;
 this->on = false;
}

void Led::turnOn() {
	// Your code here
 digitalWrite(ledPin, HIGH);
 this->on = true;
}

void Led::turnOff() {
	// Your code here
 digitalWrite(ledPin, LOW);
 this->on = false;
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

bool Led:: isOn() {
  return on;
}

