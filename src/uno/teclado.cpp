#include <Arduino.h>
#include <Keypad.h>
#include "Teclado.h"
#include "Buzzer.h"


char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'}
};

byte rowPins[ROWS] = {A0,A1}; // Connect to the row pins of the keypad
byte colPins[COLS] = {A2, A3, 11};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char getKey() {
  char key = keypad.getKey(); // Read the key from the keypad
  if (key != NO_KEY) { // If a key is pressed
    Serial.println("Key pressed: " + String(key)); // Print the key value to serial monitor
    buttonPressedSound(); // Debounce delay because has delay
    return key;
  }
  return 0;
}