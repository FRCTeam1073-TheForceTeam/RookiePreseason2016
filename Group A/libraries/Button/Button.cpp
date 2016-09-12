
#include "Arduino.h"
#include "Button.h"

Button::Button(int thePinNum) {
	pinMode(thePinNum, INPUT);
	pinNum=thePinNum;
}

bool Button::isPressed() {
	if (digitalRead(thePinNum) == HIGH) {return true}
		else {return false};

}
