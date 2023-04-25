#include <Arduino.h>
#include "Buzzer.h"
#include "Timer.h"
#include "Led.h"
#include "Display.h"
#include "Teclado.h"
#include "Servom.h"


char codigo[6] = {'3','1','5','4','6','2'};
int8_t codigo_counter = 0;
int8_t puzzle1IsCorrect = 1; // 0 is False, 1 is True
int8_t puzzle_actual = 1;
int8_t isPaused = 1;

void puzzle1Completed();
void puzzle2Completed();
void blockPuzzle1();
void unblockPuzzle1();
String leerMensaje();
void unpauseRoom();
void pauseRoom();
void restartRoom();

void setup() {
  Serial.begin(19200);
  Serial.println("empieza setup");
  setupDisplay();
  setupTimer();
  resetServo();
  setupLed();
  setupBuzzer();
  Serial.println("termina setup");
  delay(1200);
}

void loop() {

  //SERIAL COMMUNICATIONS
  if (Serial.available()){
    delay(10);
    String mensaje = leerMensaje();
    Serial.println(mensaje);
    if (mensaje == "unblockPuzzle1"){
      unblockPuzzle1();
    }else if (mensaje =="unpauseRoom"){
      unpauseRoom();
    }
    else if (mensaje=="pauseRoom"){
      pauseRoom();
    }else if (mensaje=="restartRoom"){
      restartRoom();
    }else if (mensaje=="puzzle2Completed"){ 
      puzzle2Completed();
    } 
  }

  updateTimer();

  if (!isPaused){

    if(puzzle_actual == 1){
      int key = getKey();
      if(key != 0){
        if(codigo[codigo_counter] != key){
          puzzle1IsCorrect = 0;
          Serial.print("ingreso numero equivocado: ");
          Serial.print(key);
          Serial.print(" y deberia haber ingresado: ");
          Serial.println(codigo[codigo_counter] - '0');
        }
        if (codigo_counter == 5)
        {
          if (puzzle1IsCorrect==1){
            puzzle1Completed();
            Serial.println("puzzle completado");
          }else{
            blockPuzzle1();
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
}



void puzzle1Completed(){
  correctSound();
  puzzle_actual++;
  ledOneOn();
  displayPuzzle2();
  Serial.println("puzzle1Completed");
}

void puzzle2Completed(){
  correctSound();
  writeServo180();
  ledTwoOn();
  displayFinalPuzzle();
  pauseRoom();
}

void blockPuzzle1(){
  ledWrongOn();
  puzzle_actual = -1;
  Serial.println("blockPuzzle1");
  incorrectSound();
  codigo_counter = 0;
  puzzle1IsCorrect=1;
}
void unblockPuzzle1(){
  ledWrongOff();
  puzzle_actual = 1;
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

void unpauseRoom(){
  isPaused = 0;
}
void pauseRoom(){
  isPaused = 1;
}
void restartRoom(){
  puzzle_actual = 1;
  isPaused = 1;
  ledsOff();
  resetTimer();
  resetServo();
}