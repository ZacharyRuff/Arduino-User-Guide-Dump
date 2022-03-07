/*
 the built-in LED will blink whilst the pushbutton connected to pin 2 is pressed down 
 this is possible due to the "millis()" which tracks the amount of time since the program was started, and the "if()" to make a pseudo "delay()" that does not 
 halt everything. this is what allows for the merging of the pushbutton input program and blink program.
 */


int ledState = LOW; //sets the LED
unsigned long previousMillis = 0; // this is meant to store the last time the LED was on 
//reason for "long" values is that they are storing large numbers and may grow too large to be stored without the "long" data type
//reason for "unsigned long" values is that they can store even larger numbers and due to millis being able to store 49.7 days worth of milliseconds, extra storage is needed 
const long interval = 1000; // blink interval, 

void setup() {
  // set the digital pin as output:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
 if(!digitalRead(2) == 1){ // while the pb is pressed, blink the led

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) { // how much time it has been since the program started - the time when the light was last on. if it equals the interval or more perform the if function
    // the reason for >= and not just == is that the program might take slightly more than a millisecond to execute which leads to deviation, the >= allows for said deviation
    previousMillis = currentMillis; // save the last time the LED was on

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(LED_BUILTIN, ledState);
  }
 }
 else{
  digitalWrite(LED_BUILTIN, LOW); // if the button is released whilst the light is still on, the interval will be bypassed and the light will be forced off
 }
}
