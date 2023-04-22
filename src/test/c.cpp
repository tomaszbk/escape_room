#include <Arduino.h>

char mensaje;

void setup() {
  Serial.begin(9600);  // Initialize Serial communication
  delay(1000);         // Allow time for Serial monitor to open
}

void loop() {

  if (Serial.available())
  {
    Serial.println("llego algo");
    mensaje = Serial.read();
    Serial.println(mensaje);
  }
  
  
  delay(200);  // Delay for 1 second
}

char 