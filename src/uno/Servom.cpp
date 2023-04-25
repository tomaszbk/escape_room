#include <Arduino.h>
#include <Servo.h>
#include "Servom.h"
#include "Led.h"

Servo servo1;

void resetServo(){
    servo1.attach(LED2);
    servo1.write(0);
    delay(400);
    servo1.detach();
}

void writeServo180(){
    servo1.attach(LED2);
    servo1.write(180);
    delay(400);
    servo1.detach();
}
