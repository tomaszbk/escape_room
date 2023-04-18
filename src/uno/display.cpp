#include <Arduino.h>
#include <LCD_I2C.h>
#include "Display.h"

LCD_I2C lcd(0x27, 16, 2);

void setupDisplay(){

    lcd.begin();

  //Encender la luz de fondo.
    lcd.backlight();
  
  // Escribimos el Mensaje en el LCD.
    displayPuzzle1();
}

void displayPuzzle1(){
    lcd.setCursor(0,0);
    lcd.print("El desorden es");
    lcd.setCursor(0,1);
    lcd.print("quizas un orden");
}

void displayPuzzle2(){
    lcd.setCursor(0,0);
    lcd.print("completar");
    lcd.setCursor(0,1);
    lcd.print("la colec");
}