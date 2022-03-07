/*
a push button connected to ground and pullup input pin 9 will turn on pin 10 when pushed
*/
void setup() {
pinMode(9, INPUT_PULLUP); // set pin 9 to input_pullup, the reason it is an input_pullup is that a connection to a pb can provide a floating signal so the input_pullup allows for a more reliable signal
pinMode(10, OUTPUT); // set pin 10 to output
}

void loop() {
  if(!digitalRead(9) == 1) {  // if the button is pressed, send a HIGH signal to the led, th reason for the "!" in front of digitalRead(9) is because an input pullup is on by default and turns off when the button is pressed, the "!" makes it so you get the opposite of HIGH which is LOW and vice versa
    digitalWrite(10, HIGH);
  }
  else{ // if the button is not pressed, send a low signal
    digitalWrite(10, LOW);
  }
}
