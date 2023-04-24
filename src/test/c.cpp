#include <Arduino.h>
#include <Servo.h>

Servo servo1;

void setup() {
  servo1.attach(A5);
  delay(250);
}

void loop() {

  servo1.write(0);

  delay(2500);  // Delay for 1 second
  servo1.write(180);

  delay(2500);
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