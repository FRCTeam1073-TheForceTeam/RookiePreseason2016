/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: Have the LED on pin 5 turn on when the button is pressed
Feel free to view the example program within the same folder if you need help!
*/

#include "Led.h"
#include "Button.h"

#define PIN_LED_YELLOW  3
#define PIN_LED_RED     5
#define PIN_LED_GREEN   6
#define PIN_BUTTON       7

Led *yellowLed;
Led *redLed;
Led *greenLed;
Button *aButton;

void setup(){
  yellowLed = new Led(PIN_LED_YELLOW);
  redLed = new Led(PIN_LED_RED);
  greenLed = new Led(PIN_LED_GREEN);
  aButton = new Button(PIN_BUTTON);
}

void loop(){
  if(aButton->isPressed()){
    redLed->setOn(true);
  } else {
    redLed->setOn(false);
  }
}
/*  else if {
   redLed->turnOff();
   yellowLed->turnOn();
  }
   else if {
   yellowLed->turnOff();
   greenLed->turnOn();
  }
  else {
    greenLed->turnOff();
  }
}
*/

