/*
LEDs connected to pins 9, 10 and 11 will be turned on off to make it look like the light is bouncing from side to side
*/
void setup() {
pinMode(11, OUTPUT); // set pins 9, 10 and 11 as outputs
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);

}

void loop() {
  digitalWrite(11, HIGH); // turn on pin 11 and turn off pin 9 and 10
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  delay(200); // wait 200ms before continuing
  digitalWrite(11, LOW); // turn on pin 10 and turn off pin 9 and 11
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  delay(200); // wait 200ms before continuing
  digitalWrite(11, LOW); // turn on pin 9 and turn off pin 10 and 11
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(200); // wait 200ms before continuing
  digitalWrite(11, LOW); // turn on pin 10 and turn off pin 9 and 11
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  delay(200); // wait 200ms before continuing
}
