# GBALib Potentiometer v2.1.0

![Arduino Logo](./extras/ArduinoCommunityLogo.png)

## Overview
The **GBALib_Potentiometer** library provides a straightforward interface to manage potentiometer inputs connected to an Arduino. It allows for reading raw analog values, converting them to voltages, and mapping the readings to specified ranges with optional step increments.


## Installation

The library is included in the **Arduino Library Manager**. You can install it either by using the Library Manager or manually by following the steps below.

1. **Download the Library:**
   - Click on the "Code" button in the GitHub repository.
   - Select "Download ZIP" to download the library as a ZIP file.

2. **Extract the ZIP File:**
   - Extract the contents of the ZIP file to your Arduino libraries directory.

3. **Restart the Arduino IDE:**
   - Restart the Arduino IDE to ensure that the library is recognized.

## Usage

1. **Include the Library:**
   ```cpp
   #include <GBALib_Potentiometer.h>
   ```

2. **Instantiate the Pot object:**
   ```cpp
   // Specify the pin to which the potentiometer is connected
   Pot pot(A1); 
   ```

---

## Documentation
## Class: `Pot`

### Constructor: `Pot(uint8_t pin)`
- **Purpose**: Initializes the potentiometer object with the specified pin.
- **Parameters**:
  - `pin` (uint8_t): The analog pin number to which the potentiometer is connected.
- **Example**:
    ```cpp
    Pot potentiometer(A0);
    ```

### Constructor: `Pot(uint8_t pin, int min, int max)`
- **Purpose**: Initializes the potentiometer object with the specified pin and range.
- **Parameters**:
  - `pin` (uint8_t): The analog pin number to which the potentiometer is connected.
  - `min` (int): The minimum value for the potentiometer range.
  - `max` (int): The maximum value for the potentiometer range.
- **Example**:
    ```cpp
    Pot potentiometer(A0, 0, 100); // Maps readings between 0 and 100.
    ```

### Constructor: `Pot(uint8_t pin, int min, int max, int step)`
- **Purpose**: Initializes the potentiometer object with the specified pin and range and step.
- **Parameters**:
  - `pin` (uint8_t): The analog pin number to which the potentiometer is connected.
  - `min` (int): The minimum value for the potentiometer range.
  - `max` (int): The maximum value for the potentiometer range.
  - `step` (int): The step size for the mapped output values.
- **Example**:
    ```cpp
    Pot potentiometer(A0, 0, 100, 5); // Maps readings between 0 and 100. Increments values by steps of 5.
    ```

### Method: `void range(int min, int max)`
- **Purpose**: Sets the default range for potentiometer readings.
- **Parameters**:
  - `min` (int): The minimum value for the potentiometer range.
  - `max` (int): The maximum value for the potentiometer range.
- **Example**:
    ```cpp
    potentiometer.range(0, 100); // Maps readings between 0 and 100.
    ```

### Method: `void step(int step)`
- **Purpose**: Sets the default step size for mapped potentiometer readings.
- **Parameters**:
  - `step` (int): The step size for the mapped output values.
- **Example**:
    ```cpp
    potentiometer.step(5); // Increments values by steps of 5.
    ```

### Method: `int input()`
- **Purpose**: Reads the raw potentiometer input value from the specified analog pin.
- **Returns**: The average of several analog readings ranging between 0 and 1023.
- **Example**:
    ```cpp
    int rawValue = potentiometer.input();
    ```

### Method: `float voltage()`
- **Purpose**: Calculates the voltage based on the potentiometer input.
- **Returns**: The voltage value in the range of 0V to 5V.
- **Example**:
    ```cpp
    float voltage = potentiometer.voltage();
    ```

### Method: `int value()`
- **Purpose**: Reads and maps the potentiometer value to a defined range `[vMin, vMax]` with a specified step size. If the step size is greater than 0, the mapped value is adjusted to the nearest step.
- **Returns**: The mapped and adjusted potentiometer value within the default range.
- **Example**:
    ```cpp
    int mappedValue = potentiometer.value();
    ```

### Method: `int valueToCustomRange(int min, int max)`
- **Purpose**: Reads and maps the potentiometer value to a custom range `[min, max]`. This method ignores the default range set previously.
- **Parameters**:
  - `min` (int): The minimum value for the custom range.
  - `max` (int): The maximum value for the custom range.
- **Returns**: The mapped potentiometer value within the custom range.
- **Example**:
    ```cpp
    int customValue = potentiometer.valueToCustomRange(50, 150);
    ```

### Method: `int valueToCustomRange(int min, int max, int step)`
- **Purpose**: Reads and maps the potentiometer value to a custom range `[min, max]` with a specified step size. This method ignores the default range and step size set previously.
- **Parameters**:
  - `min` (int): The minimum value for the custom range.
  - `max` (int): The maximum value for the custom range.
  - `step` (int): The step size for the mapped output values.
- **Returns**: The mapped and adjusted potentiometer value within the custom range.
- **Example**:
    ```cpp
    int customSteppedValue = potentiometer.valueToCustomRange(0, 200, 10);
    ```

## Example Usage

```cpp
#include <GBALib_Potentiometer.h>

Pot pot(A0);

void setup() {
  Serial.begin(9600);
  
  // Set range and step
  pot.range(0, 100);
  pot.step(5);
}

void loop() {
  int raw = pot.input();
  float voltage = pot.voltage();
  int mapped = pot.value();
  
  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(", Mapped: ");
  Serial.println(mapped);
  
  delay(500);
}
```

## Notes
- Ensure that the potentiometer is correctly connected to the specified analog pin.
- Use `range()` and `step()` to set default mapping and step values, and utilize custom range methods when you need specific mappings.


## License
This library is released under the GNU License. See the [LICENSE](./LICENSE) file for more information.