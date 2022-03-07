/*
an led connected to pin 10 will slowly fade on until it reaches it's maximum brightness and then it will dim slowly until it turns off. loop
*/
int FADE; // define FADE as an integer before usage

void setup() {
  pinMode(10, OUTPUT); // set pin 10 to output
}

void loop() {
    for(FADE = 0; FADE <=255; FADE += 5 ){ // from values 0 to 255, as long as fade is less that 255, it will keep going up by 5 every 50ms. 
      analogWrite(10, FADE); // write the  value of FADE from 0-5V in bits (range is 0-255 bits)
      delay(50); // wait for 50ms before moving on
    }
    for(FADE = 255; FADE >= 0; FADE -= 5){ // once FADE reaches 255, the previous for loop will be broken and the value of FADE will keep going down until it reaches 0 at which point the previous loop will re-engage and the system loops
    analogWrite(10, FADE); 
    delay(50);
    }
}
