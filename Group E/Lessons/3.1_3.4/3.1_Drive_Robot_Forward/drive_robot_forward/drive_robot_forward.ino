#include <Servo.h>
#include <Drive.h>

/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/10/14

Program: Drive the robot forward for a duration
*/

#define PIN_SERVO_RIGHT   A0
#define PIN_SERVO_LEFT    A1

int delayValue = 1000; //creates an int that controls how long to drive forward
Drive *drive;

void setup(){ //setup runs just once
  drive = new Drive(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);
  drive->fwd(50);
  delay(delayValue);
  drive->stop();
}

void loop(){ //loop runs over and over again
  ; //nothing needed here
}


