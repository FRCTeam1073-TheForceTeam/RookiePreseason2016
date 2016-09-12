#include <Servo.h>

class Drive {
  public:
    Drive();
      void forward(int x);
      void stopMoving();
  private:
    Servo left;
    Servo right;
    int button = 7;
};

  Drive::Drive() {
    left.attach(10);
    right.attach(9);
  }

void Drive::forward(int x) {
  left.writeMicroseconds(1500 + ((x * 1500) / 100));
  right.writeMicroseconds(1500 - ((x * 1500) / 100));
}

void Drive::stopMoving() {
  left.writeMicroseconds(1500);
  right.writeMicroseconds(1500);
}



// put your setup code here, to run once:
void setup() {
  Drive *drive = new Drive();
    // drive->driveFunction(int);
    drive->forward(50);
    delay(3000);
    drive->stopMoving();
}

// put your main code here, to run repeatedly:
void loop() {
  
}
