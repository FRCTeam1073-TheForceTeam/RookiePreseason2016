/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/10/14

Program: Use the potentiometer to control the speed of the robot
*/

#include <Servo.h>
#include <Potentiometer.h>
#include <Drive.h>

#define PIN_POT           5
#define PIN_SERVO_RIGHT   9
#define PIN_SERVO_LEFT    10

Drive *drive;
Potentiometer *myPot;

int servoVal = 0; //creates a variable to store the manipulated potentiometer value

void speedControl(){   //creates a method called speedcontrol
  servoVal = myPot->getPercent();  //manipulate the analog read for servo use
  drive->fwd(servoVal);
}

void setup(){ //setup runs just once
  drive = new Drive(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);
  myPot = new Potentiometer(PIN_POT);
}

void loop(){ //loop runs over and over again
  speedControl();
}


