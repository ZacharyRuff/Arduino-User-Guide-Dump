/*
 a potentiometer hooked up to analog pin 0 will control the brightness of an LED connected to pin 10 using the Arduino to scale the signal 
 */

void setup() {
}
void loop() {
  analogWrite(10,analogRead(A0)/4); //write the value of analog pin A0 then divide by 4 to scale from analogRead bit to analogWrite bit ((1024/0)*(255/0)= 4.01)
}
