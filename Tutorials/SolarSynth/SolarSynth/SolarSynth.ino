/* L M Wilkins 2022, Solar Media Synth Logger
 * WARNING: DO NOT USE MORE THAN 5V SOLAR CELL WITHOUT VOLTAGE
 * DIVIDER! Also amend multiplier for acurate voltage (multple the
 * times you divided the voltage :) 
 * 
 * Makes music out of voltage and prints voltage to serial
 * 
 * Circuit: 
 * Buzzer on pin 11
 * Solar cell on pin A0
 * Knob on pin A1
 * 
 * You could add more knobs for duration, delay, etc. 
 */

int modifier; // modifer for synth sound
int v = 1; // Modifier if you're using more than 5v 
#define solarPin A0 
#define knobPin A1 // synth knob

void setup() {
  Serial.begin(9600); // start serial 
}

void loop() {
  modifier = analogRead(knobPin) * 2;
  tone(11, random((analogRead(A0) - modifier), analogRead(A0) + modifier), random(0, analogRead(A0)));
  delay(random(300));
  voltage();
}

void voltage() {
  Serial.print("The read value is:");
  Serial.println(analogRead(solarPin));
  int Input  = analogRead(solarPin); 
  double voltage = Input * (5.0 / 1024.0)*v; 
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
}
