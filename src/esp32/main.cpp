#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

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

void setup()
{
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    Serial.println("...................................");
    Serial.print("Connecting to WiFi.");
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".") ;
    }
    Serial.println("Wifi Connected");

    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);
    client.subscribe("esp32");

    while (!client.connected())
    {      Serial.println("Connecting to MQTT...");
        if (client.connect("ESP32Client",mqttUser,mqttPassword)){
            Serial.println("connected");
            client.publish("esp32", "esp32 conectado");
        }else{
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
}

void loop()
{
    client.loop();
    
    if (activated){
        
    }
    
}


void callback(char* topic, byte* payload, unsigned int length) {
  String message = String((char*)payload);
  if (message == "activatePuzzle2")
  {
    activatePuzzle2();
  }else if (message == "deactivatePuzzle2")
  {
    deactivatePuzzle2();
  }
}

void activatePuzzle2(){
    activated=1;
    client.publish("esp32","puzzle 2 activado");
}
void deactivatePuzzle2(){
    activated=0;
    client.publish("esp32","puzzle 2 desactivado");
}