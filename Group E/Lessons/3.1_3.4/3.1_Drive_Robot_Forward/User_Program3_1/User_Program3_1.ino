/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: drive the robot forward for a few seconds
Feel free to view the example program within the same folder if you need help!
*/

#include<Servo.h>
#include<Drive.h>

#define PIN_SERVO_RIGHT   9
#define PIN_SERVO_LEFT    10

int led = 5;

int delayValue = 1000;
Drive *drive;

void setup(){
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  drive = new Drive(PIN_SERVO_LEFT, PIN_SERVO_RIGHT); 
  drive->fwd(50);
  delay(delayValue);
  drive->stop();
}

void loop(){
  //also here
}
