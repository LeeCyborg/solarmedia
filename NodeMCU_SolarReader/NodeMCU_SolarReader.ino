// scavenged by arnbarn 03-23-22
// tutorials to generate this included:
// https://diyi0t.com/lcd-display-tutorial-for-arduino-and-esp8266/
// https://randomnerdtutorials.com/esp8266-adc-reading-analog-values-with-nodemcu/
// https://www.programmingelectronics.com/sprintf-arduino/

// include the library code:
#include "LiquidCrystal_I2C.h"
#include "LiquidCrystal.h"

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// const int RS = D2, EN = D3, d4 = D5, d5 = D6, d6 = D7, d7 = D8;

// if you use the NodeMCU 12E the suggested pins are
const int RS = 4, EN = 0, d4 = 12 , d5 = 13, d6 = 15, d7 = 3;

const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0
int sensorValue = 0;  // value read from the pot
int solarValue = 0; // convert ADC to solar voltage
LiquidCrystal lcd(RS, EN, d4, d5, d6, d7);

void setup() {
Serial.begin(115200);
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.print("Solar Values:");
}

void loop() {
// read the analog in value
sensorValue = analogRead(analogInPin);
solarValue = (sensorValue * 3300 / 1023) * 2; 
// the 3W panel (~6V, 500ma?) is reporting across a voltage divider, hence multiple ADC conversion by two

char buffer[16];
  sprintf(buffer, "ADC:%3d  mV:%-8d", sensorValue, solarValue);  
  // to print multiple values to a single line, you need to use sprintf() command
  // see here --> https://www.programmingelectronics.com/sprintf-arduino/
  // the printout is "padded", an explanation is here: 
  // https://www.baldengineer.com/arduino-lcd-display-tips.html
  Serial.println(buffer);
  lcd.setCursor(0, 1);  
  // set the cursor to column 0, line 1
  //note: line 1 is the second row, since counting begins with 0
  lcd.print(buffer);

delay(2000);
}
