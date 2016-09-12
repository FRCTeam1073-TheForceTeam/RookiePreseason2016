
#include <Button.h>
#include <Led.h>

/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/9/14

Program: Toggles an LED using the breadboard button
*/

#define PIN_LED_RED       5
#define PIN_BUTTON        7

Led *redLed;
Button *myButton;

void setup(){ //setup runs just once
  redLed = new Led(PIN_LED_RED);
  myButton = new Button(PIN_BUTTON);
}

void loop(){
  if(myButton->isPressed()){
    redLed->turnOn();
  }
  else{
    redLed->turnOff();
  }
}
