/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: Turn on an LED at pin 5
Feel free to view the example program within the same folder if you need help!
*/
//ANdy is pretty cool and so is sreeka #booandy

#include <Potentiometer.h>

#define PIN_POT           5
Potentiometer *myPot;


int ledred = 5;
int ledgreen = 6;
int ledyellow = 3;

int led = 0;

int speed = 500;

void setup(){
  //your code goes here
  pinMode(ledyellow, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  
}

void loop(){
  Serial.print("Hello World");
  delay(speed);
  digitalWrite(ledred, LOW);
  digitalWrite(ledgreen, LOW);
  digitalWrite(ledyellow, LOW);
  switch(led)
  {
    case 0:
    digitalWrite(ledyellow, HIGH);
    break;
    case 1:
    digitalWrite(ledred, HIGH);
    break;
    case 2:
    digitalWrite(ledgreen, HIGH);
    led = -1;
    break;    
  }

  led = led+1;
  
  
}


