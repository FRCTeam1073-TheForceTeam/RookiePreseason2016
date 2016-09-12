#include "LineSensor.h"

LineSensor::LineSensor(int leftPin, int rightPin) {
	leftLight = leftPin;
	rightLight = rightPin;
	lineState = OFFBOTH;
}

void LineSensor::calibrate(int wvLeft, int wvRight) {
	whiteValLeft = wvLeft;
	whiteValRight = wvRight;
}

void LineSensor::autoCalibrate() {
	calibrate(getRawLeft(), getRawRight());
}

void LineSensor::readSensors() {
	int leftVal = analogRead(leftLight);
	int rightVal = analogRead(rightLight);

	if (leftVal >= whiteValLeft + changeVal) {
		if (rightVal >= whiteValRight + changeVal)
			lineState = ONBOTH;
		else
			lineState = ONLEFT;
	}
	else if (rightVal >= whiteValRight + changeVal) {
		lineState = ONRIGHT;
	}
	else
		lineState = OFFBOTH;
}

int LineSensor::getRawLeft() {
	return analogRead(leftLight);
}

int LineSensor::getRawRight() {
	return analogRead(rightLight);
}

bool LineSensor::noLine() {
	return (lineState == OFFBOTH);
}

bool LineSensor::lineOnLeftEdge() {
	return (lineState == ONLEFT);
}

bool LineSensor::lineOnRightEdge() {
	return (lineState == ONRIGHT);
}

bool LineSensor::lineOnBoth() {
	return (lineState == ONBOTH);
}
