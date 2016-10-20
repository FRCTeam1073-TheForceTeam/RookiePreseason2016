#include <Potentiometer.h>
#include <Led.h>

/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/9/14

Program: Dim an LED on pin 5, using the potentiometer on pin A5
*/
#define PIN_LED_RED     5
#define PIN_POT     5

Led *redLed;
//Potentiometer *myPot;

void setup(){ //setup runs just once
  redLed = new Led(PIN_LED_RED);
  myPot = new Potentiometer(PIN_POT);
}
void loop(){ //loop runs over and over again
  int dimVal = myPot->getValue(); //read the value of the potentiometer on potPin and set dimVal equal to it
  int ledVal = dimVal / 4; //analogRead ranges from 0 to 1023, analog write scales from 0 to 255. scales potentiometer input
  redLed->turnOnDim(ledVal); //writes the potentiometer value to the led
}


