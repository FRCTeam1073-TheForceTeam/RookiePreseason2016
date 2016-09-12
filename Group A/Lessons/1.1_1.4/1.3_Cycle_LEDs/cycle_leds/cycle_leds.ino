/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/9/14

Program: blink each led in succession (cycle leds)
*/

int yellow = 3;
int green = 6;
int red = 5;

int blinkDelay = 500; //creates an int used for delay timing

void cycle(int led){
  digitalWrite(led, HIGH);
  delay(blinkDelay);
  digitalWrite(led, LOW);
}

void setup(){ //setup runs just once
  pinMode(red, OUTPUT); //establishes red as an output
  pinMode(yellow, OUTPUT); //establishes yellow as an output
  pinMode(green, OUTPUT); //establishes green as an output
}
void loop(){
  cycle(green);
  cycle(yellow);
  cycle(red);
}

