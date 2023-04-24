#include <PubSubClient.h>

#define SS_PIN    21
#define RST_PIN   22

extern PubSubClient client;

void rfidSetup();
int8_t checkRfid();

// #define MOSI_PIN 11 // Change to the desired digital pin number
// #define MISO_PIN 12 // Change to the desired digital pin number
// #define SCK_PIN 13 // Change to the desired digital pin number