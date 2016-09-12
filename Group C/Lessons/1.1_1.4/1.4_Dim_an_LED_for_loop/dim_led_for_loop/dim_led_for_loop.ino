/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/9/14

Program: Dims an led using a for loop
*/

int red = 5;

int blinkDelay = 20; //creates an int used for delay timing

void setup(){ //setup runs just once
  pinMode(red, OUTPUT); //establishes red as an output
}
void loop(){
  for(int i = 0; i < 255; i += 5){
    analogWrite(red, i);
    delay(blinkDelay);
  }
  for(int i = 255; i >= 0; i -= 5){
    analogWrite(red, i);
    delay(blinkDelay);
  }
}
