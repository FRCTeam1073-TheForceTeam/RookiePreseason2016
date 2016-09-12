/* Team 1073's Arduino Boebot Diagnostics Program
Created for use on the Arduino BoeBot
Last Updated: 9/8/2014

Program: Run this program when you first create your BoeBot to 
  1) confirm that all the sensors are working and 
  2) calibrate any sensors or servos if necessary
  
IMPORTANT NOTES:   1)This program will not function properly if your hardware is connected to different ports than the reference design. Please see the pinout file for hardware ports.  
                   1)If you are looking to test the phototransistors (light sensors), open the file in the same directory called light_sensor_diag 
                   Please see the readme if you need more help, also located in this directory (to be written)
*/
#include <NewPing.h>
#include <Servo.h>

Servo left;
Servo right;

#define TRIGGER_PIN  12  
#define ECHO_PIN     8  
#define MAX_DISTANCE 200 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int buzzer = 11;

int yellow = 3;
int green = 6;
int red = 5;

int pot = 5;
int button = 7;

int counter = 0;
char val = 0;
char prev_val = 0;

void stop_bot(){
  left.writeMicroseconds(1500);
  right.writeMicroseconds(1500);
}
void forward(){
  left.writeMicroseconds(1700);
  right.writeMicroseconds(1300);
}
void setup(){
  left.attach(10);
  right.attach(9);
  Serial.begin(9600);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  stop_bot();
  Serial.println("Welcome to 1073's Boebot diagnostics and setup program. To begin, type b into the console window. \n");
}

void loop(){
  if(Serial.available() > 0){
    val = Serial.read();
  }
  if(val == prev_val){
    val = 0;
  }
  if(val == 'b' && counter == 0){
    Serial.println("First, let's calibrate the drive servos. make sure you have a philips head screwdriver for adjusting the potentiometer inside the servos ready. press a to continue. \n");
    counter = 1;
  }
  if(val == 'a' && counter == 1){
    forward();
    Serial.println("Both servos are now running in a forward direction. If one or both servos are not running, check your connections or the batteries for your BoeBot. if both are moving, press c to continue. \n");
    counter = 2;
  }
  if(val == 'c' && counter == 2){
    stop_bot();
    Serial.println("The Boebot is currently being told to stop. If one or more of the servos are still moving, then they need to be calibrated. use a screwdriver and adjust the potentiometer in each servo until the servo stops rotating. Once both are no longer moving, press d to continue. \n");
    counter = 3;
  }
  if(val == 'd' && counter == 3){
    Serial.println("Next, let's test the buzzer. When ready, press p to play a noise from the buzzer for 2 seconds. If you hear something, press e to continue. if not, check your connections. \n");
    counter = 4;
  }
  if(val == 'p' && counter == 4){
    analogWrite(buzzer, 15);
    delay(2000);
    analogWrite(buzzer, 0);
    counter = 5;
  }
  if(val == 'e' && counter == 5){
    Serial.println("Great. let's check the led's now to make sure they work. press t to turn on all three lights for 2 seconds. if one or more do not, then again, check your connections or your resistor. If they all work, press f to continue. \n");
    counter = 6;
  }
  if(val == 't' && counter == 6){
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    counter = 7;
  }
  if(val == 'f' && counter == 7){
    Serial.println("Great! Now we will test the ultrasonic module. Place an object in front of the sensor. ");
    Serial.println("Press g to print the ultrasonic output to the console. The sensor will print what it sees for 3 seconds, with a new output every 100ms. \n");
    counter = 8;
  }
  if(val == 'g' && counter == 8){        
    for(int i = 0;i<30;i++){
      delay(100);                     
      unsigned int uS = sonar.ping(); 
      Serial.print("Ping: ");
      Serial.print(uS / US_ROUNDTRIP_CM); 
      Serial.println("cm");
      }
    Serial.println("Ultrasonic values printed. press h to continue. \n");
    counter = 9;
  }
  if(val == 'h' && counter == 9){
    Serial.println("Now to test the potentiometer and button. As you turn the dial, the red led should dim. ");   
    Serial.print("Pressing the button should toggle the green led. If both work, then your BoeBot is fully functional! \n");
    counter = 10;
  }
  if(counter == 10){
    int potVal = analogRead(pot);
    analogWrite(red, potVal/6);
    int buttonVal = digitalRead(button);
    if(buttonVal == 1){
      digitalWrite(green, HIGH);
    }
    else{
      digitalWrite(green, LOW);
    }
  }
  prev_val = val;
}
