#include <Arduino.h>
#include "Buzzer.h"

int melody[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 };

void setupBuzzer(){
    pinMode(BUZZER_PIN, OUTPUT);
    //digitalWrite(BUZZER_PIN, LOW);
}

void correctSound(){

    tone(BUZZER_PIN, melody[7]); 
    delay(200);
    noTone(BUZZER_PIN); 
    delay(50);

    tone(BUZZER_PIN, melody[4]); 
    delay(100);
    noTone(BUZZER_PIN); 
    delay(50);
    tone(BUZZER_PIN, melody[4]); 
    delay(100);
    noTone(BUZZER_PIN); 
    delay(50);

    tone(BUZZER_PIN, melody[5]); 
    delay(200);
    noTone(BUZZER_PIN); 
    delay(50);
    tone(BUZZER_PIN, melody[4]); 
    delay(200);
    noTone(BUZZER_PIN); 
    delay(250);

    tone(BUZZER_PIN, melody[6]); 
    delay(200);
    noTone(BUZZER_PIN); 
    delay(50);
    tone(BUZZER_PIN, melody[7]); 
    delay(200);
    noTone(BUZZER_PIN); 
    delay(50);
}

void buttonPressedSound(){ //200ms
    tone(BUZZER_PIN, melody[7]); 
    delay(150);
    noTone(BUZZER_PIN);
}

void incorrectSound(){
    tone(BUZZER_PIN, 1000, 200); // Play a tone with 1000Hz frequency for 200ms
    delay(300); // Delay for 300ms
    tone(BUZZER_PIN, 500, 300);
}

