
/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/10/14

Program: Drive the robot when the button is pressed
*/

#include <Servo.h>
#include <Drive.h>
#include <Button.h>

#define PIN_BUTTON        7
#define PIN_SERVO_RIGHT   9
#define PIN_SERVO_LEFT    10

Button *myButton;
Drive *drive;

void setup(){
  drive = new Drive(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);
  myButton = new Button(PIN_BUTTON);
}

void loop(){
  if(myButton->isPressed()){
    drive->fwd(50);
  }
  else{
    drive->stop();
  }
}
