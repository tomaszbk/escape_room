#include <Arduino.h>
#include <Servo.h>
#include "Led.h"

Servo servo1;

void setupLed()
{
    pinMode(LED1, OUTPUT);
    // pinMode(LED2, OUTPUT);
    pinMode(WRONG_LED, OUTPUT);
    servo1.attach(LED2);
    servo1.write(0);
    servo1.detach();
}

void ledOneOn(){
    digitalWrite(LED1, HIGH);
}

void ledTwoOn(){
    // digitalWrite(LED2, HIGH);
    servo1.attach(LED2);
    servo1.write(180);
}

void ledWrongBlink(){
    digitalWrite(WRONG_LED, HIGH);
    delay(250);
    digitalWrite(WRONG_LED, LOW);
    delay(250);
    digitalWrite(WRONG_LED, HIGH);
    delay(250);
    digitalWrite(WRONG_LED, LOW);
}
void ledWrongOn(){
    digitalWrite(WRONG_LED, HIGH);
}
void ledWrongOff(){
    digitalWrite(WRONG_LED, LOW);
}