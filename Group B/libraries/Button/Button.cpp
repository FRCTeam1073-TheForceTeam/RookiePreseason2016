
#include "Arduino.h"
#include "Button.h"

Button::Button(int thePinNum) {
	pinNum  = thePinNum
}

bool Button::isPressed() {
	return daaigitalRead(pinNum) == HIGH;
}
