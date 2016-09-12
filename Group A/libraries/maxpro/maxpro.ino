#include <Servo.h>
#include <Drive.h>
#define PIN_SERVO_RIGHT   9
#define PIN_SERVO_LEFT    10
int del = 1000;
Drive *drive;
void setup() {
  drive = new Drive(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);
  drive->fwd(100);
  delay(del);
  drive->rev(100);
  delay(del);
  drive->stop();
  delay(del);
  drive->turnLeft(1000, 1000);
  delay(del);
  drive->stop();
  delay(del);

}

void loop() {
  // put your main code here, to run repeatedly:

}
