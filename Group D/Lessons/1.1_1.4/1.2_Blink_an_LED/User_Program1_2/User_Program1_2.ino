/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: Blink an LED on pin 5 
Feel free to view the example program within the same folder if you need help!
*/
int ledblink = 5;
int blinkdelay = 500;
void setup(){
  pinMode (ledblink, OUTPUT);
  digitalWrite (ledblink, HIGH);
}

void loop(){
  delay (blinkdelay);
  digitalWrite (ledblink, LOW);
  delay (blinkdelay);
  digitalWrite (ledblink, HIGH);
}

