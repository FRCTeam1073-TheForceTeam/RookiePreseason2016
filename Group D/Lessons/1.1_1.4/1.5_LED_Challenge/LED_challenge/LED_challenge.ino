// LED Challenge
/* Cycle all of the leds to cycle and fade them instead 
 *  of on and off... Use ''For'' loops!
 */
 int yellow = 3;
 int red = 5;
 int green = 6;
 int changeDelay = 20;
 
void fadeLoop (int led){
  for(int i = 0; i < 255; i += 5){
    analogWrite(led, i);
    delay(changeDelay);
  }
  for(int i = 255; i >= 0; i -= 5){
    analogWrite(led, i);
    delay(changeDelay);
  }
}

void setup(){
  pinMode (yellow, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
}

void loop(){
  fadeLoop (yellow);
  fadeLoop (red);
  fadeLoop (green);
}

