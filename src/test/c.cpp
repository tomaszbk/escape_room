#include <Arduino.h>

int codigo[6] = {3, 1, 5, 4, 6, 2};
char x = 3;
void setup() {
  Serial.begin(9600);  // Initialize Serial communication
  delay(1000);         // Allow time for Serial monitor to open
}

void loop() {
  // Print the value of codigo[0] to Serial monitor
  Serial.print("codigo[0] = ");
  Serial.println(codigo[0]);
  
  delay(1000);  // Delay for 1 second
}