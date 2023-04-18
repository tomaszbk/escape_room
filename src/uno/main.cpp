#include <Arduino.h>
#include <Servo.h>
#include "Buzzer.h"
#include "Timer.h"
#include "Led.h"
#include "Display.h"
#include "Teclado.h"

#define SERVO_PIN 11

Servo servo1;
char codigo[6] = {'3','1','5','4','6','2'};
int8_t codigo_counter = 0;
int8_t estado = 1; // 0 is False, 1 is True
int8_t puzzle_actual = 1;

void puzzle1Completed();

void setup() {
  Serial.begin(9600);
  Serial.println("empieza setup");
  // servo1.attach(SERVO_PIN);
  setupDisplay();
  setupTimer();
  setupLed();
  // setupBuzzer();
  Serial.println("termina setup");
  delay(1200);
}

void loop() {
  updateTimer();
  if(puzzle_actual == 1){
    int key = getKey();
    if(key != 0){
      if(codigo[codigo_counter] != key){
        estado = 0;
        Serial.print("ingreso numero equivocado: ");
        Serial.print(key);
        Serial.print(" y deberia haber ingresado: ");
        Serial.println(codigo[codigo_counter] - '0');
      }
      if (codigo_counter == 5)
      {
        if (estado==1){
          puzzle1Completed();
          Serial.println("puzzle completado");
        }else{
          incorrectSound();
          ledWrongBlink();
          codigo_counter = 0;
          estado=1;
        }
      }else{
        codigo_counter++;
        
      }
    }

  }else if (puzzle_actual == 2)
  {
    /* code */
  } 
}


void puzzle1Completed(){
  correctSound();
  puzzle_actual++;
  ledOneOn();
  //mover servo?
  servo1.write(180);
  displayPuzzle2();
}