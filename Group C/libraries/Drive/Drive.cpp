
#include "Arduino.h"
#include "Drive.h"

Drive::Drive(int leftPin, int rightPin) {
  left.attach(leftPin);
  right.attach(rightPin);
}

// ToDo: implement turning

void Drive::move(int percentPower, int turnDir = 0) {
  int offset = (int) ((float) zeroPower * (float) percentPower /
    100.0);
  int leftSpeed = 0, rightSpeed = 0;

  if (turnDir == 0) {
    leftSpeed = zeroPower + offset;
    rightSpeed = zeroPower - offset;
  }
  else if (turnDir < 0) { // turning left
    leftSpeed = zeroPower - offset;
    rightSpeed = zeroPower - offset;
  }
  else { // turning right
    leftSpeed = zeroPower + offset;
    rightSpeed = zeroPower + offset;
  }
  left.writeMicroseconds(leftSpeed);
  right.writeMicroseconds(rightSpeed);
}

void Drive::fwd(int percentPower) {
  move(percentPower);
}

void Drive::rev(int percentPower) {
  move(-percentPower);
}

void Drive::turnLeft(int turnRate, int turnMs) {
  move(turnRate, -1);
  delay(turnMs);
}

void Drive::turnRight(int turnRate, int turnMs) {
  move(turnRate, 1);
  delay(turnMs);
}

void Drive::stop() {
  move(0);
}
