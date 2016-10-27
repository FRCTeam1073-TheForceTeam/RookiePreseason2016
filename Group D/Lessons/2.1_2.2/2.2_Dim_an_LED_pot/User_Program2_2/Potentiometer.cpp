
#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer(int thePinNum) 
{
	pinNum = thePinNum;
}

int Potentiometer::getValue()
{
	return analogRead(pinNum);
}

int Potentiometer::getPercent() 
{
	return (Potentiometer::getValue()/1023)*100;
}
