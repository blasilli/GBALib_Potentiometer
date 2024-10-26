/*
  GBALib_Potentiometer.h - Potentiometer Management Library
  Copyright (c) 2024 Graziano Blasilli.
  
  This library provides a simple interface to read potentiometer inputs and map the values 
  to specific voltage ranges, including step increments.
*/

#include "GBALib_Potentiometer.h"



/**
 * Constructor to initialize a potentiometer object on the specified pin.
 * Sets the default value range and step size.
 * 
 * @param pin  The analog pin number to which the potentiometer is connected.
 */
Pot::Pot(uint8_t pin) {
  this->pin = pin;
  
  this->vMin = 0;
  this->vMax = 1023;
  this->vStep = 1;

  pinMode(this->pin, INPUT);
}

/**
 * Constructor to initialize a potentiometer object on the specified pin.
 * Sets the default value range and step size.
 * 
 * @param pin  The analog pin number to which the potentiometer is connected.
 * @param min  The minimum value for the potentiometer range.
 * @param max  The maximum value for the potentiometer range.
 */
Pot::Pot(uint8_t pin, int min, int max) {
  this->pin = pin;
  
  this->vMin = min;
  this->vMax = max;
  this->vStep = 1;

  pinMode(this->pin, INPUT);
}

/**
 * Constructor to initialize a potentiometer object on the specified pin.
 * Sets the default value range and step size.
 * 
 * @param pin  The analog pin number to which the potentiometer is connected.
 * @param min  The minimum value for the potentiometer range.
 * @param max  The maximum value for the potentiometer range.
 * @param step  The step size for the mapped output values.
 */
Pot::Pot(uint8_t pin, int min, int max, int step) {
  this->pin = pin;
  
  this->vMin = min;
  this->vMax = max;
  this->vStep = step;

  pinMode(this->pin, INPUT);
}

/**
 * Set the default range for potentiometer readings.
 * 
 * @param min  The minimum value for the potentiometer range.
 * @param max  The maximum value for the potentiometer range.
 */
void Pot::range(int min, int max) {
  this->vMin = min;
  this->vMax = max;
}

/**
 * Set the default step value for mapped potentiometer readings.
 * 
 * @param step  The step size for the mapped output values.
 */
void Pot::step(int step) {
  this->vStep = step;
}

/**
 * Read the raw potentiometer input value from the specified analog pin.
 * The returned value ranges between 0 and 1023.
 * 
 * @return int The average analog reading of the potentiometer.
 */
int Pot::input() {
  const int numReadings = 5;
  float sum = 0;
  for (int i = 0; i < numReadings; i++) {
    sum += analogRead(this->pin);
    delay(1);
  }
  return int(sum / numReadings);
}

/**
 * Calculate the voltage value based on the potentiometer input.
 * The voltage is calculated between 0V and 5V.
 * 
 * @return float The calculated voltage value.
 */
float Pot::voltage() {
  int inVal = this->input();
  float voltage = inVal * (5.0 / 1023.0);
  return voltage;
}


/**
 * Read and map the potentiometer value to a custom range [min, max].
 * This function ignores the default range and uses the custom range specified.
 * 
 * @param min  The minimum value for the custom range.
 * @param max  The maximum value for the custom range.
 * @return int The mapped potentiometer value within the custom range.
 */
int Pot::valueToCustomRange(int min, int max) {
  int inVal = this->input();
  return map(inVal, 0, 1023, min, max);
}

/**
 * Read and map the potentiometer value to a custom range [min, max] with a specified step size.
 * This function ignores the default range and uses the custom range and step size specified.
 * 
 * @param min   The minimum value for the custom range.
 * @param max   The maximum value for the custom range.
 * @param step  The step size for the mapped output values.
 * @return int The mapped and adjusted potentiometer value within the custom range.
 */
int Pot::valueToCustomRange(int min, int max, int step) {
  int mappedValue = this->valueToCustomRange(min, max);
  if (step > 0) {
    int mod = mappedValue % step;
    int base = mappedValue - mod;
    float halfStep = float(step) / 2.0;

    if (mod >= halfStep) {
      mappedValue = base + step;
    } else {
      mappedValue = base;
    }

    if (mappedValue > max) {
      mappedValue = max;
    }
  }

  return mappedValue;
}


/**
 * Read and map the potentiometer value to the default range [vMin, vMax] with a specified step size.
 * If the step size is greater than 0, the mapped value is adjusted to the nearest step.
 * 
 * @return int The mapped and adjusted potentiometer value.
 */
int Pot::value() {
  return this->valueToCustomRange(this->vMin, this->vMax, this->vStep);
}
