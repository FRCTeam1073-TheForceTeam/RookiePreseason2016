#ifndef Potentiometer_h
#define Potentiometer_h

class Potentiometer {
private:
	int pinNum;
public:
	Potentiometer(int thePinNum);
	int getValue();
	int getPercent();
};

#endif