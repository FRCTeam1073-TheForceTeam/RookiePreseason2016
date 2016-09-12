#include "Potentiometer.h"

Potentiometer::Potentiometer(int thePinNum){
	pinMode(thePinNum, INPUT);
	pinNum=thePinNum; 
}

int Potentiometer::getValue (){
	analogRead(pinNum);
}