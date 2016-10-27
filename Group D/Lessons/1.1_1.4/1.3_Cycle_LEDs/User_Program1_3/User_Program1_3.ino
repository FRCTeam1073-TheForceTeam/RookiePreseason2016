/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: Cycle the 3 leds of the robot, so that one led turns on, then the next, then the next
Feel free to view the example program within the same folder if you need help!
*/
int ledcolor = 3;
int switchtime = 500;
void setup(){
  pinMode (ledcolor, OUTPUT);
  ledcolor = 5;
  pinMode (ledcolor, OUTPUT);
  ledcolor = 6;
  pinMode (ledcolor, OUTPUT);
  ledcolor = 3;
  digitalWrite (ledcolor, HIGH);
}

void loop(){
  delay (switchtime);
  digitalWrite (ledcolor, LOW);
  ledcolor = 5;
  digitalWrite (ledcolor, HIGH);
  delay (switchtime);
  digitalWrite (ledcolor, LOW);
  ledcolor = 6;
  digitalWrite (ledcolor, HIGH);
  delay (switchtime);
  digitalWrite (ledcolor, LOW);
  ledcolor = 3;
  digitalWrite (ledcolor, HIGH);
}

