#include "Led.h"

Led::Led(int pin, int delay) {
	ledPin = pin;
	pinMode(ledPin, OUTPUT);
	blinkDelay = delay;
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
	for (int i = 0; i < count; i++) {
		turnOn();
		delay(blinkDelay * dutyCycle / 100);
		turnOff();
		delay(blinkDelay * (100 - dutyCycle) / 100);
	}
}

void Led::rampUp(int steps, int delayMs) {
	int stepSize = (int) (256.0 / (float) steps);
	for (int i = 0; i < 256; i+=stepSize ) {
		turnOnDim(i);
		delay(delayMs);
	}
}

void Led::rampDown(int steps, int delayMs) {
	int stepSize = (int) (256.0 / (float) steps);
	for (int i =255; i >= 0; i-=stepSize ) {
		turnOnDim(i);
		delay(delayMs);
	}
}
