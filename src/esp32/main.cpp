#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "Rfid.h"

const char* ssid = "Vora 2.4G";
const char* password = "tomate0001";
const char* mqttServer = "192.168.0.18";
const int mqttPort = 1883;
const char* mqttUser = "tomas";
const char* mqttPassword = "escape";
int8_t activated = 0;


WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length);
void activatePuzzle2();
void deactivatePuzzle2();
void puzzle2Completed();
void reconnect();

void setup()
{
    // Serial.begin(9600);
    rfidSetup();
    WiFi.begin(ssid, password);
    // Serial.print("Esp32 Connecting to WiFi.");
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
    }
    //Serial.println("Wifi Connected");

    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);

    while (!client.connected()){
        //Serial.println("Connecting to MQTT...");
        if (client.connect("ESP32Client",mqttUser,mqttPassword)){
            //Serial.println("connected");
            client.subscribe("esp32");
            client.publish("debug", "esp32 conectado");
        }else{
            //Serial.print("failed");
            delay(1500);
        }
    }
}

void loop()
{
    if (! client.connected()){
        reconnect();
    }
    client.loop();
    if (activated == 1){    
        if (checkRfid()){
            client.publish("debug","se procede a llamar puzzle2Completed");
            puzzle2Completed();
        }
    }
}

void callback(char* topic, byte* payload, unsigned int length) {
    // String payloadStr = "";
    // for (int i = 0; i < length; i++) {
    //     payloadStr += (char)payload[i];
    // }
    // Serial.print("mensaje String payloadStr es: ");
    // Serial.println(payloadStr);

    char msg[length];
    memcpy(msg,payload,length);
    msg[length]='\0';

    // client.publish("fromDevice/debug", "esp32 llego mensaje");
    // client.publish("fromDevice/debug","2: ");
    // client.publish("fromDevice/debug", payloadStr.c_str());

    if (strcmp(msg,"activatePuzzle2") == 0){
        activatePuzzle2();
    }else if (strcmp(msg,"deactivatePuzzle2") == 0){
        deactivatePuzzle2();
    }
}

void activatePuzzle2(){
    activated=1;
    client.publish("debug","puzzle 2 activado");
}
void deactivatePuzzle2(){
    activated=0;
    client.publish("debug","puzzle 2 desactivado");
}

void puzzle2Completed(){
    client.publish("esp32","puzzle2Completed");
    activated=0;
}


void reconnect(){
  while (!client.connected()) {
    //Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client",mqttUser,mqttPassword)){
        client.subscribe("esp32");
        client.publish("debug", "esp32 reconectado");
    } else {
        //Serial.print("failed");
        delay(1000);
    }
  }
}