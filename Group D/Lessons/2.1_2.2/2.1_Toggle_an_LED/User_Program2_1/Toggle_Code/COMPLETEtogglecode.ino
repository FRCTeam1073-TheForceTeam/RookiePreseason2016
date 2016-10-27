/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: Have the LED on pin 5 turn on when the button is pressed
Feel free to view the example program within the same folder if you need help!
*/
#include "Arduino.h"
#include "Button.h"
int buttonNum = 7;
int ledNum = 5;
int lightIsOn = 1;
Button butte = Button(buttonNum);
void setup(){
  pinMode(ledNum, OUTPUT);
  digitalWrite(ledNum, HIGH);
}

void loop(){
  if(butte.isPressed () == 1){
    if(lightIsOn == 1) {
      digitalWrite(ledNum, LOW);
      lightIsOn = 0;
      delay(500);
    }
    else{
        digitalWrite(ledNum, HIGH);
        lightIsOn = 1;
        delay(500);
      }
  }
}

