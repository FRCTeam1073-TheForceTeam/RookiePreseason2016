
#include "Arduino.h"
#include "Button.h"

Button::Button(int thePinNum) {
	pinNum  = thePinNum;
}

bool Button::isPressed() {
	return digitalRead(pinNum) == HIGH;
}
