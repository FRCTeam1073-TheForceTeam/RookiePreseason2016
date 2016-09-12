#ifndef Drive_h
#define Drive_h
#include "Servo.h"
class Drive {
private:
  int zeroPower = 1500;
  Servo left;
  Servo right;
  void move(int percentPower, int turnDir);
public:
  Drive(int leftPin, int rightPin);
  void fwd(int percentPower);
  void rev(int percentPower);
  void turnLeft(int turnRate, int turnMs);
  void turnRight(int turnRate, int turnMs);
  void stop();
};
#endif
