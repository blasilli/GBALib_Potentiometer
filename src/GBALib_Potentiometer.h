/*
  GBALib_Potentiometer.h - Potentiometer Management Library
  Copyright (c) 2024 Graziano Blasilli.
  
  This library provides a simple interface to read potentiometer inputs and map the values 
  to specific voltage ranges, including step increments.
*/

#ifndef GBALib_Potentiometer_h
#define GBALib_Potentiometer_h

#include <Arduino.h>

class GBALib_Potentiometer {
  public:
    /**
     * Constructor to initialize a potentiometer object on the specified pin.
     * Sets the default value range and step size.
     * 
     * @param pin  The analog pin number to which the potentiometer is connected.
     */
    GBALib_Potentiometer(uint8_t pin);
    
    /**
     * Set the default range for potentiometer readings.
     * 
     * @param min  The minimum value for the potentiometer range.
     * @param max  The maximum value for the potentiometer range.
     */
    void range(int min, int max);

    /**
     * Set the default step value for mapped potentiometer readings.
     * 
     * @param step  The step size for the mapped output values.
     */
    void step(int step);

    /**
     * Read the raw potentiometer input value from the specified analog pin.
     * The returned value ranges between 0 and 1023.
     * 
     * @return int The average analog reading of the potentiometer.
     */
    int input();

    /**
     * Calculate the voltage value based on the potentiometer input.
     * The voltage is calculated between 0V and 5V.
     * 
     * @return float The calculated voltage value.
     */
    float voltage();

    /**
     * Read and map the potentiometer value to a defined range [vMin, vMax] with a specified step size.
     * If the step size is greater than 0, the mapped value is adjusted to the nearest step.
     * 
     * @return int The mapped and adjusted potentiometer value.
     */
    int value();

    /**
     * Read and map the potentiometer value to a custom range [min, max].
     * This function ignores the default range and uses the custom range specified.
     * 
     * @param min  The minimum value for the custom range.
     * @param max  The maximum value for the custom range.
     * @return int The mapped potentiometer value within the custom range.
     */
    int valueToCustomRange(int min, int max);

    /**
     * Read and map the potentiometer value to a custom range [min, max] with a specified step size.
     * This function ignores the default range and uses the custom range and step size specified.
     * 
     * @param min   The minimum value for the custom range.
     * @param max   The maximum value for the custom range.
     * @param step  The step size for the mapped output values.
     * @return int The mapped and adjusted potentiometer value within the custom range.
     */
    int valueToCustomRange(int min, int max, int step);

  private:
    uint8_t pin;   // Analog pin connected to the potentiometer
    int vMin;      // Minimum range value
    int vMax;      // Maximum range value
    int vStep;     // Step value for the output
};

#endif
