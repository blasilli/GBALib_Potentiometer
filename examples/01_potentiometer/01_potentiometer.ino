#include <GBALib_Potentiometer.h>  // Include the GBALib_Potentiometer library

// Create an instance of the Pot class to manage the potentiometer
// Arguments: pin A0 (analog input), minimum mapped value (0), maximum mapped value (255)
Pot myPot(A0, 0, 255);

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
}

void loop() {
  // Read the raw potentiometer input value (range 0-1023)
  int pval = myPot.input();

  // Map the raw input to the defined range (0-255 in this case)
  int mval = myPot.value();

  // Calculate the voltage value based on the input (0-5V for a default reference voltage)
  float voltage = myPot.voltage();

  // Print the raw value, mapped value, and voltage to the Serial Monitor
  Serial.print("Real Value = ");  // Label for the raw input value
  Serial.print(pval);             // Print the raw value
  Serial.print("    Mapped Value = ");  // Label for the mapped value
  Serial.print(mval);                     // Print the mapped value
  Serial.print("    Voltage = ");  // Label for the voltage
  Serial.print(voltage);           // Print the calculated voltage
  Serial.println("V");             // Add the unit "V" and move to the next line

  delay(200);  // Wait for 200 milliseconds before the next reading
}
