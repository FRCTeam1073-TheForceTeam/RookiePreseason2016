
/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/10/14

Program: Drive the robot forward for a duration, then backward for a different duration
*/

#include <Servo.h>
#include <Drive.h>

#define PIN_SERVO_RIGHT   9
#define PIN_SERVO_LEFT    10

int delayValueForward = 2000; //creates an int that controls how long to drive forward
int delayValueBack = 1000; //creates an int that controls how long to drive backward
Drive *drive;

void setup(){ //setup runs just once
  drive = new Drive(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);
  drive->fwd(50);
  delay(delayValueForward);
  drive->rev(50);
  delay(delayValueBack);
  drive->stop();
}
void loop(){ //loop runs over and over again
  ; //nothing needed here
}


