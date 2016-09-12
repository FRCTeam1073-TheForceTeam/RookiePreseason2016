/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/10/14

Program: Drive the robot forward for a duration
*/

#include <Servo.h>
// creates two servo objects
Servo left;  
Servo right;

// creates an int that controls how long to drive forward
int delayValue = 1000;

//setup runs just once
void setup(){
  // mounts each servo on their respective digital pin
  left.attach(10);
  right.attach(9);
  /* 
  1500 is like "zero velocity" for wheels.
  <1500 turns the wheel "backwards"; >1700 turns the wheel "forwards"
  the servos are attached to the BoeBot in different directions,
  so in order for it to drive forward, one wheel needs to be
  going "forward" and one needs to go "backwards"
  */
  left.writeMicroseconds(1700);
  right.writeMicroseconds(1300);
  delay(delayValue);
  left.writeMicroseconds(1500);
  right.writeMicroseconds(1500);
}
// loop runs over and over again
void loop(){
  ; // nothing needed here
}


