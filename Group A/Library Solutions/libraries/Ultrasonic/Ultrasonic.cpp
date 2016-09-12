#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int triggerPin, int echoPin) {
	trigger = triggerPin;
	echo = echoPin;
	distDelay = 50;
	sonar = new NewPing(trigger, echo, MAX_DISTANCE);
}

int Ultrasonic::getDistance() {
	delay(distDelay);
	unsigned int uS = sonar->ping();
	unsigned int cmDist = uS / US_ROUNDTRIP_CM;
	return (int) cmDist;
}
