#include <Arduino.h>
#include "Led.h"

void setupLed()
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(WRONG_LED, OUTPUT);
}

void ledOneOn(){
    digitalWrite(LED1, HIGH);
}

void ledTwoOn(){
    digitalWrite(LED2, HIGH);
}

void ledWrongBlink(){
    digitalWrite(WRONG_LED, HIGH);
    delay(1000);
    digitalWrite(WRONG_LED, LOW);
}