#ifndef BUZZER_H

#define BUZZER_PIN 13
// Melody notes in Hz
#define NOTE_C4 261
#define NOTE_D4 294
#define NOTE_E4 329
#define NOTE_F4 349
#define NOTE_G4 391
#define NOTE_A4 440
#define NOTE_B4 493
#define NOTE_C5 523

void setupBuzzer();
void correctSound();
void buttonPressedSound();
void incorrectSound();


#endif