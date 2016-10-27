/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: Dim the led on pin 5 using the potentiometer, so that as the potentiometer is turned, the brightness is adjusted
Feel free to view the example program within the same folder if you need help!
*/
#include "Potentiometer.h"
int ledNum = 5;
int potentiometerNum = 5;
int potBrightness = 0;
int finalBrightness = 0;
void setup(){
pinMode(ledNum, OUTPUT);
}

void loop(){
potBrightness = analogRead(5);
finalBrightness = map(potBrightness, 0, 1023, 0, 255);
analogWrite(ledNum, finalBrightness);
}

