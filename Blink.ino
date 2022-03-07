/*
pin 10 will be turned on every 50% at an interval of 250ms
*/
void setup() {
pinMode(10, OUTPUT); //set pin 10 to work as an output

}

void loop() {
  // anything within the loop function will be done repeatedly 
digitalWrite(10, HIGH); // send a high signal output to pin 10
delay(250);  // wait 250ms before advancing to the next step
digitalWrite(10, LOW); // turn off the signal on pin 10
delay(250); // wait 250ms before looping
}
