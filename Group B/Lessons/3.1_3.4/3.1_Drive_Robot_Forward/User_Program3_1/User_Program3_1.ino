/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: drive the robot forward for a few seconds
Feel free to view the example program within the same folder if you need help!
*/
#include "Servo.h"
#include "Drive.h"
#include "Button.h"


#define PIN_SERVO_RIGHT   9
#define PIN_SERVO_LEFT    10
#define PUSH_BUTTON   7

int delayValue = 1000;
Drive *drive;
Button *aButton;

void setup(){
 drive = new Drive (PIN_SERVO_LEFT, PIN_SERVO_RIGHT)
 

void loop(){
  if (aButton->isPressed()){
    drive->fwd(100);
   else drive->stop();
  }
}
 /*if(aButton->isPressed()){
    redLed->setOn(true);
  } else {
    redLed->setOn(false);
  }
}
*/

