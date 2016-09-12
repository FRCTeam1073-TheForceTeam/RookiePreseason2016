/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/9/14

Program: Blink an LED on pin 5
*/

int led = 5;  //creates an int called "led" with a value of 9
int blinkDelay = 500; //creates an int used for delay timing
void setup(){ //setup runs just once
  pinMode(led, OUTPUT); //establishes the led as an output
}
void loop(){
  digitalWrite(led, HIGH); //sends voltage to the led pin
  delay(blinkDelay); //waits the value of blinkDelay
  digitalWrite(led, LOW); //stops sending voltage to the led pin
  delay(blinkDelay); //waits the value of blinkDelay
}

