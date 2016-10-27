#include "Arduino.h"
#include "Button.h"

Button::Button(int thePinNum) {
	pinNum = thePinNum;
	pinMode(pinNum, INPUT);
}

bool Button::isPressed() {
	return(digitalRead(pinNum) == HIGH);
}
