//#include <Potentiometer.h>
#include <Led.h>
/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: Dim the led on pin 5 using the potentiometer, so that as the potentiometer is turned, the brightness is adjusted
Feel free to view the example program within the same folder if you need help!
*/
#define PIN_LED_RED       5
#define PIN_POT           A5

Led *redLed;
//Potentiometer *myPot;

void setup(){
  pinMode(5, OUTPUT);
  pinMode(A5, INPUT);
  analogWrite(5, 255);
}

void loop(){


analogRead(INPUT);
analogWrite(5, analogRead(A5)*100.0/1023.0);
}

