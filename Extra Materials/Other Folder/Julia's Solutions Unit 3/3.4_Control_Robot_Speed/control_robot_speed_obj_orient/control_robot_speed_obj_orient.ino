#include <Servo.h>

class Potentiometer {
  public:
    Potentiometer();
    int potVal;
    int servoVal;
    void speedControl();
  private:
    int potPin;
    Servo left;
    Servo right;
};

Potentiometer::Potentiometer() {
  potVal = 0;
  potPin = 5;
}

void Potentiometer::speedControl() {
  potVal = analogRead(potPin);
  servoVal = potVal / 7;
  left.writeMicroseconds(1500 + servoVal);
  right.writeMicroseconds(1500 - servoVal);
}

Potentiometer *potentiometer;

// put your setup code here, to run once:
void setup() {
  potentiometer = new Potentiometer();
}

// put your main code here, to run repeatedly:
void loop() {
  potentiometer->speedControl();
}
