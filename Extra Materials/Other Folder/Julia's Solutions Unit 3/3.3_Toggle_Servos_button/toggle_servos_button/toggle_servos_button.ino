/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/10/14

Program: Drive the robot when the button is pressed
*/

#include <Servo.h>

Servo left;  
Servo right;  //creates two servo objects

int button = 7;

void setup(){
  left.attach(10);
  right.attach(9);
}
void loop(){
  int buttonVal = digitalRead(button);
  if(buttonVal == 1){
    left.writeMicroseconds(1700);
    right.writeMicroseconds(1300);
  }
  else{
    left.writeMicroseconds(1500);
    right.writeMicroseconds(1500);
  }
}
