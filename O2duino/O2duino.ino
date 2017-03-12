#include <LiquidCrystal.h>

/*
  O2duino
  Reads the wideband oxigen sensor controler analog output on analog input pin 5, converts it to Lambda Scale and prints the result to the serial monitor (LCD Keypad Shield).
  Attach the signal cable of the sensor to the pin A5.

*/

// Initialize Display
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


//Optional use of a Led Bar Graph
/*
const int ledCount = 3;    // the number of LEDs in the bar graph
const int top = 300;
const int bottom = 100;

int ledRich = 12;
int ledStoich = 2;
int ledLean = 3;

int ledPins[] = { 
  12, 2, 3};   // an array of pin numbers to which LEDs are attached
*/


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("O2duino");
  
  // loop over the pin array and set them all to output:
  //for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    //pinMode(ledPins[thisLed], OUTPUT);
  //}
  
  //pinMode(ledRich, OUTPUT);
  //pinMode(ledStoich, OUTPUT);
  //pinMode(ledLean, OUTPUT);
}

float readInput(uint8_t analogInput) {
  float total=0;  
  for (int i=0; i<12; i++) {
    total += 1.0 * analogRead(analogInput);
    delay(5);
  }
  return total / (float)12;
}  

// the loop routine runs over and over again forever:
void loop() {
  
  //digitalWrite(ledRich, LOW);
  //digitalWrite(ledStoich, LOW);
  //digitalWrite(ledLean, LOW);
  
  // read the input on analog pin 5:
  int sensorValue = readInput(A5);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 1V):
  //float voltage = sensorValue * (1 / 1023.0);
  float o2Lambda = (sensorValue * 5) / 3365.0;
  float o2Volts = (sensorValue * 5) / 1024.0;
  // print out the value you read:
  Serial.println("###############");
  Serial.print("Logic Value: ");
  Serial.println(sensorValue);
  Serial.print("Volts Value: ");
  Serial.println(o2Volts);
  Serial.print("Lambda Value: ");
  Serial.println(o2Lambda);
  

  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(o2Lambda);
  lcd.print(" Lambda");


//Optional output to Led Array
/*
  
  if (sensorValue > top) {
    digitalWrite(ledRich, HIGH);
//    digitalWrite(ledPins[1], HIGH);
//    digitalWrite(ledPins[2], LOW);
//    digitalWrite(ledPins[3], LOW);
  }
  else {
    if (sensorValue > bottom) {
      digitalWrite(ledStoich, HIGH);
//      digitalWrite(ledPins[1], LOW);
//      digitalWrite(ledPins[2], HIGH);
//      digitalWrite(ledPins[3], LOW);
    }
    else {
      digitalWrite(ledLean, HIGH);      
//      digitalWrite(ledPins[1], LOW);
//      digitalWrite(ledPins[2], LOW);
//      digitalWrite(ledPins[3], HIGH);
    }
  }
  
*/  
  
  delay(500);
  
}
