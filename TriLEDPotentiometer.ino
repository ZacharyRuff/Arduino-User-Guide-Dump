/*
CONNECT THE POTENTIOMETER TO ANALOG PIN 0 WITH A 5V POWER SOURCE GOING TO THE POTENTIOMETER'S INPUT
This program reads the value of a potentiometer in bits and uses it to manipulate an array of 3 LEDs, 
Whilst the potentionmeter is turned from 0 to 1/3 of its maximum value, the LED connected to pin 11 will fade from low to maximum value based on a bit scale of 0-342 bits
Whilst the potentionmeter is turned from 1/3 to 2/3 of its maximum value, the LED connected to pin 10 will fade from low to maximum value based on a bit scale of 342-682 bits
Whilst the potentionmeter is turned from 2/3 to its maximum value, the LED connected to pin 9 will fade from low to maximum value based on a bit scale of 682-1024 bits
*/
void setup() {
 
pinMode(11, OUTPUT); // set pin 11 as OUTPUT
pinMode(10, OUTPUT); // set pin 10 as OUTPUT
pinMode(9, OUTPUT);  // set pin 9 as OUTPUT
Serial.begin(9600);  // set the baudrate of the Arduino UNO for communication with the serial monitor
}

void loop() {
int Grade = analogRead(A0); // Define grade as the analog read value of analog pin 0    (I defined this as both an integer and a float so I choose if I want decimals or not in the serial monitor)
float GradeF = analogRead(A0); 
if (Grade != 0 and Grade <= 342){ // if Grade is between 0 and 342, fade pin 11 
  analogWrite(11, (Grade)/1.34);  // Grade (0-342) scaled to analog write values (0-255) and output to the LED
  Serial.print("Red LED ON, potentiometer at "); // all Serial.print are just relaying information to the serial monitor so the user can read
  Serial.print(GradeF / 1024 * 100);
  Serial.print("%");
  Serial.println(" "); 
  digitalWrite(9, LOW); // whilst Grade is within the range of 0-342, turn off pin 9 and 10
  digitalWrite(10, LOW);
}
if (Grade > 342 and Grade <= 682 and Grade != 0){ // if Grade is between 343 and 682 fade pin 10
  analogWrite(10, (Grade - 342)/1.34); //Grade (0-342) scaled to analog write values (0-255) and output to the LED (simplified)
  Serial.print("Green LED ON, potentiometer at ");  // all Serial.print are just relaying information to the serial monitor so the user can read
  Serial.print(GradeF / 1024 * 100);
  Serial.print("%");
  Serial.println(" ");
  digitalWrite(9, LOW); // whilst Grade is within the range of 343 and 682 turn off pin 9 and 11
  digitalWrite(11, LOW);
}
if (Grade > 682 and Grade <= 1024 and Grade != 0){  // if Grade is between 683 and 1024 fade pin 9
  analogWrite(9, (Grade - 682)/1.34); //Grade (0-342) scaled to analog write values (0-255) and output to the LED (simplified)
  Serial.print("Blue LED ON, potentiometer at "); // all Serial.print are just relaying information to the serial monitor so the user can read
  Serial.print(GradeF / 1024 * 100);  
  Serial.print("%");
  Serial.println(" ");
  digitalWrite(10, LOW);  // whilst Grade is within the range of 683 and 1024 turn off pin 9 and 11
  digitalWrite(11, LOW);
}
delay(5); // 5ms delay between each loop
} 
