#include <Arduino.h>
#include "Timer.h"

int8_t minutes = 10;
int8_t seconds = 0;
unsigned long lastUpdateTime = 0;

byte dpins[4] = {5,6,7,8};

unsigned char table[] =
{0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void setupTimer(){
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CS_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    for (int j = 0; j < NUM_OF_DIGITS; j++){
    pinMode(dpins[j], OUTPUT);
    digitalWrite(dpins[j], HIGH);
  }
}

void updateTimer(){

    if (!isPaused){

      if (minutes == 0 && seconds == 0) {
        Serial.println("timeUp"); //time is up message to Node red
      } else if (millis() - lastUpdateTime >= 1000){
        //paso un segundo
        seconds--;
        if(seconds < 0){
          seconds = 59;
          minutes -=1;
      }
      lastUpdateTime = millis();
      }
    }

    if(minutes < 10){
      display(3,0);
      display(2,minutes);
    }
    else{
      display(3,minutes/10);
      display(2,minutes%10);
    }
    if(seconds < 10){
      display(1,0);
      display(0,seconds);
    }
    else{
      display(1,seconds/10);
      display(0,seconds%10);
    }
}

void display(byte id, unsigned char num) {
  digitalWrite(LATCH_PIN, LOW);
  if (id == 2)
  {
    shiftOut(DATA_PIN, CS_PIN, LSBFIRST, table[num] -128);
  } else{
    shiftOut(DATA_PIN, CS_PIN, LSBFIRST, table[num]);
  }
  digitalWrite(LATCH_PIN, HIGH);

  for (int j = 0; j < NUM_OF_DIGITS; j++) {
    digitalWrite(dpins[j], LOW); // Set all digit pins low to turn them off
  }
  
  digitalWrite(dpins[id], HIGH); // Set the current digit pin high to turn it on
  delay(3);
}

void resetTimer(){
  minutes =10;
  seconds=0;
}