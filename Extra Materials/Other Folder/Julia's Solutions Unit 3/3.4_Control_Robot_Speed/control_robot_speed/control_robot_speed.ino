/* Software 1073 Example Program
Written and debugged for use on the Arduino boebot platform
last updated: 9/10/14

Program: Use the potentiometer to control the speed of the robot
*/

#include <Servo.h>

Servo left;  
Servo right;  //creates two servo objects

int potPin = 5; //creates an int with a value of 5
int potVal = 0; //creates a variable to store the raw potentiometer values
int servoVal = 0; //creates a variable to store the manipulated potentiometer value

void speedControl(){   //creates a method called speedcontrol
  potVal = analogRead(potPin); //read the analog pin
  servoVal = potVal / 7;  //manipulate the analog read for servo use
  left.writeMicroseconds(1500 + servoVal);  
  right.writeMicroseconds(1500 - servoVal);  //write value to the servos
}

void setup(){ //setup runs just once
  left.attach(10);
  right.attach(9); //mounts each servo on their respective digital pin

  
}
void loop(){ //loop runs over and over again
  speedControl();
}


