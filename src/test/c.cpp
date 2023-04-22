#include <Arduino.h>

char mensaje;
String leerMensaje();

void setup() {
  Serial.begin(9600);  // Initialize Serial communication
  delay(1000);         // Allow time for Serial monitor to open
}

void loop() {

  if (Serial.available())
  {

    String mensaje = leerMensaje();
    Serial.println(mensaje);
  }
  
  
  delay(200);  // Delay for 1 second
}

String leerMensaje(){
  char caracter;
  String mensaje = "";
  caracter = Serial.read();
  while (caracter != '\n'){
    mensaje += caracter;
    caracter = Serial.read();
  }
  return mensaje;
} 