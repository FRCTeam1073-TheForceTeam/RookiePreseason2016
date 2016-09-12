#ifndef Ultrasonic_h
#define Ultrasonic_h

#include <NewPing.h>

#define MAX_DISTANCE 200

class Ultrasonic {
private:
	int distDelay;
	int trigger;
	int echo;
	NewPing *sonar;
public:
	Ultrasonic(int triggerPin, int echoPin);
	int getDistance();
};

#endif
