#include <Servo.h>

class Button {
  public:
    Button(int x);
    boolean isButtonPushed();
  private:
    int button;
    boolean toggleState;
};

Button::Button(int x) {
    button = x;
    pinMode(button, INPUT);
    toggleState = false;
}

boolean Button::isButtonPushed() {
  int buttonVal = digitalRead(button);
  if (buttonVal == 1) {
    return true;
  }
  else {
    return false;
  }
}

class Drive {
  public:
    Drive();
      void forward(int x);
      void stopMoving();
  private:
    Servo left;
    Servo right;
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

Drive *drive;
Button *button;
boolean shouldIDrive;
int buttonCounter;
int ledRed = 5;
int ledGreen = 6;

// put your setup code here, to run once:
void setup() {
  Serial.begin(38400);
  drive = new Drive();
  button = new Button(7);
  shouldIDrive = false;
  buttonCounter = 0;
  pinMode(ledRed, OUTPUT); //establishes the led as an output
  pinMode(ledGreen, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  // if the button is pushed
  if (button->isButtonPushed()) {
    // should i drive is being set to the inverse of should i drive - toggling
    shouldIDrive = not(shouldIDrive);
  }
  // if should i drive is true then drive
  if (true == shouldIDrive) {
    //Serial.println("Drive");
    drive->forward(20);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
  }
  else {
    // if should i drive is false do not move
    //Serial.println("Stop Please");
    drive->stopMoving();
    digitalWrite(ledRed, HIGH); //sends voltage to the led pin
    digitalWrite(ledGreen, LOW);
  }
}
