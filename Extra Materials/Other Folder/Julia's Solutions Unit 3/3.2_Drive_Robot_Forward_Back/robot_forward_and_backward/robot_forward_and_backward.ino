/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/10/14

Program: Drive the robot forward for a duration, then backward for a different duration
*/

#include <Servo.h>

Servo left;  
Servo right;  //creates two servo objects

int delayValueForward = 2000; //creates an int that controls how long to drive forward
int delayValueBack = 1000; //creates an int that controls how long to drive backward

void setup(){ //setup runs just once
  left.attach(10);
  right.attach(9); //mounts each servo on their respective digital pin
  left.writeMicroseconds(1700);
  right.writeMicroseconds(1300);
  delay(delayValueForward);
  left.writeMicroseconds(1300);
  right.writeMicroseconds(1700);
  delay(delayValueBack);
  left.writeMicroseconds(1500);
  right.writeMicroseconds(1500);
  
}
void loop(){ //loop runs over and over again
  ; //nothing needed here
}


