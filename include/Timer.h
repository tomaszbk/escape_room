#ifndef TIMER__H
#define NUM_OF_DIGITS 4
#define DATA_PIN  4 
#define LATCH_PIN  3 
#define CS_PIN  2 

extern int8_t isPaused;


//  DP G F E D C B A
//0: 1 1 0 0 0 0 0 0 0xc0
//1: 1 1 1 1 1 0 0 1 0xf9
//2: 1 0 1 0 0 1 0 0 0xa4
//3: 1 0 1 1 0 0 0 0 0xb0
//4: 1 0 0 1 1 0 0 1 0x99
//5: 1 0 0 1 0 0 1 0 0x92
//6: 1 0 0 0 0 0 1 0 0x82
//7: 1 1 1 1 1 0 0 0 0xf8
//8: 1 0 0 0 0 0 0 0 0x80
//9: 1 0 0 1 0 0 0 0 0x90

void setupTimer();
void updateTimer();
void display(byte id, unsigned char num);
void resetTimer();

#endif