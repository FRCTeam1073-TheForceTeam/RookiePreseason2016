/*Software 1073 Arduino BoeBots
User Program 
Method stubs are pre-made. add your own code to complete the challenge!

Program Task: drive the robot forward for a few seconds
Feel free to view the example program within the same folder if you need help!
*/

int val = 0;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

}

void loop() {
  /*if (Serial.available() > 0) {
    String str = "";
    str += ((char) Serial.read());
    
    val += str.toInt(;
  Serial.write(val); */ 
  //}
  analogWrite(9, 40);
  analogWrite(10, 215);
}
