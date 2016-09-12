#ifndef LineSensor_h
#define LineSensor_h

#include "Arduino.h"

class LineSensor {
private:
	enum lineStateEnum {OFFBOTH, ONLEFT, ONRIGHT, ONBOTH};
	lineStateEnum lineState;
	int whiteValLeft = 0;
	int whiteValRight = 0;
	int changeVal = 150;
	int leftLight;
	int rightLight;
public:
  LineSensor(int leftPin, int rightPin);
	void calibrate(int wvLeft, int wvRight);
	void autoCalibrate();
	void readSensors();
	int getRawLeft();
	int getRawRight();
	bool noLine();
	bool lineOnLeftEdge();
	bool lineOnRightEdge();
	bool lineOnBoth();
};
#endif
