/*
make an ohmeter circuit and display the resistance of the connected circuit on an lcd.
connecting the lcd is partially shown in the defniniton of the lcd inputs below.
*/
#include <LiquidCrystal.h> // import the lcd library
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // define the pins that each of the lcd inputs are connected to
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // setting the pins associated with the lcd
byte omega[8] = { // creating the ohm symbol using bit values
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000
};

float voltage; // defining voltage integer
float current; // defining current integer
float resistance; // defining resistance integer
void setup() { 
Serial.begin(9600); // setting the baud rate of the arduino for communication with the serial monitor (not needed)
lcd.begin(16, 2); // setting the number of characters and rows of the lcd
lcd.createChar(0, omega); // creating the omega character and assigning a byte number to it
}

void loop() { // using ohm's law to calculate the resistance of the circuit
  voltage = (analogRead(A0))/220.00; // calculate the voltage 
  current = (3.30-voltage)/1000.00; // calculate the current 
  resistance = voltage/current; // calculate the resistance
Serial.print(current); // none of the Serial.# is necessary
Serial.print("mA   ");
Serial.print(voltage);
Serial.print("V   ");
Serial.print(resistance);
Serial.print("ohm   ");
Serial.println();
lcd.setCursor(0, 0); // display from the 0th digit on the 0th row (top left, first row)
lcd.print(resistance); // print the resistance value
lcd.write(byte(0)); // print the ohm symbol
delay(1000); // refresh the lcd every second
}
