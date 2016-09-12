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
      void backward(int x);
      void pivotLeft(int x);
      void pivotRight(int x);
      void arcLeft(int radius);
      void arcRight(int radius);
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

void Drive::backward(int x) {
  left.writeMicroseconds(1500 - ((x * 1500) / 100));
  right.writeMicroseconds(1500 + ((x * 1500) / 100));
}

void Drive::pivotLeft(int x) {
  left.writeMicroseconds(1500 + ((x * 1500) / 100));
  right.writeMicroseconds(1500 + ((x * 1500) / 100));
}

void Drive::pivotRight(int x) {
  left.writeMicroseconds(1500 - ((x * 1500) / 100));
  right.writeMicroseconds(1500 - ((x * 1500) / 100));
}
//make int degree
void Drive::arcLeft(int radius) {
  double log1 = log(2.0 / 3.0 * radius);
  double log2 = log(2.0);
  left.writeMicroseconds(3000);
  right.writeMicroseconds(1500 - (10 * log1 / log2 + 10));
}

void Drive::arcRight(int radius) {
  double log1 = log(2.0 / 3.0 * radius);
  double log2 = log(2.0);
  left.writeMicroseconds(1500 + (10 * log1 / log2 + 10));
  right.writeMicroseconds(0);
}

void Drive::stopMoving() {
  left.writeMicroseconds(1500);
  right.writeMicroseconds(1500);
}

Drive *drive;
Button *button;
Potentiometer *potentiometer;
boolean shouldIDrive;
int buttonCounter;
int ledRed = 5;
int ledGreen = 6;

// put your setup code here, to run once:
void setup() {
  Serial.begin(38400);
  drive = new Drive();
  button = new Button(7);
  potentiometer = new Potentiometer();
  shouldIDrive = false;
  buttonCounter = 0;
  pinMode(ledRed, OUTPUT); //establishes the led as an output
  pinMode(ledGreen, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  // if the button is pushed
  if (button->isButtonPushed()) {
    // if the button counter is greater than 50
    if (buttonCounter > 5000) {
      // should i drive is being set to the inverse of should i drive - toggling
      shouldIDrive = not(shouldIDrive);
      //Serial.println(shouldIDrive);
      // resets the button counter
      buttonCounter = 0;
    }
    // incrementing the button counter
    //Serial.print("Pushed  ");
    //Serial.println(buttonCounter);
    buttonCounter++;
  }
  // if should i drive is true then drive in a circle
  if (true == shouldIDrive) {
    //Serial.println("Drive");
    drive->arcLeft(3);
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
