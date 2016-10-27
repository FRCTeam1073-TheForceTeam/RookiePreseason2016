
#include "Arduino.h"
#include "Button.h"

Button::Button(int thePinNum) {
	// Your code here
 pinMode(pinNum, INPUT);
 this->pinNum = thePinNum;
  
}

bool Button::isPressed() {
	// Your code here
 return digitalRead(pinNum);

}

