#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Vora 2.4G";
const char* password = "tomate0001";
const char* mqttServer = "192.168.0.18";
const int mqttPort = 1883;
const char* mqttUser = "tomas";
const char* mqttPassword = "escape";


WiFiClient espClient;
PubSubClient client(espClient);

void setup()
{
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    Serial.println("...................................");
    Serial.print("Connecting to WiFi.");
    while (WiFi.status() != WL_CONNECTED)
    {  delay(500);
        Serial.print(".") ;
    }
    Serial.println("first esp32 program");

    client.setServer(mqttServer, mqttPort);
    while (!client.connected())
    {      Serial.println("Connecting to MQTT...");
        if (client.connect("ESP32Client",mqttUser,mqttPassword))
            Serial.println("connected");
        else
        {   Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
}

void loop()
{
    client.loop();
     char str[16];
     sprintf(str, "%u", random(100));

     client.publish("hola", str);
     Serial.println(str);
     delay(700);
}
