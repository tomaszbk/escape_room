#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include "Rfid.h"

// #define MOSI_PIN 11 // Change to the desired digital pin number
// #define MISO_PIN 12 // Change to the desired digital pin number
// #define SCK_PIN 13 // Change to the desired digital pin number

SPIClass SPI1(HSPI);
//rfid rfid(SDA_PIN, RST_PIN);  // Create rfid instance
MFRC522 rfid(HSPI_CS); 
byte ActualUID[4];
byte answer[4] = {0xD9, 0x8D, 0xF1, 0xB0};
 
void setup() {
	Serial.begin(9600);
	SPI1.begin();			// Init SPI bus
	
	rfid.PCD_Init();		// Init rfid
	delay(400);				// Optional delay. Some board do need more time after init to be ready, see Readme
	rfid.PCD_DumpVersionToSerial();	// Show details of PCD - rfid Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
	Serial.println("listorta");
}
 
void loop() {
	// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	if ( ! rfid.PICC_IsNewCardPresent()) {
		return;
	}
 
	// Select one of the cards
	if ( rfid.PICC_ReadCardSerial()) {
		// Dump debug info about the card; PICC_Halt
		Serial.print(F("Card UID:"));
					for (byte i = 0; i < rfid.uid.size; i++) {
							Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
							Serial.print(rfid.uid.uidByte[i], HEX);   
							ActualUID[i] = rfid.uid.uidByte[i];          
					} 
		Serial.println("");
		delay(500);
		bool isEqual = true;
		for (int i = 0; i < 4; i++) {
		if (answer[i] != ActualUID[i]) {
			isEqual = false;
			break;
		}
		}

		// Check if the values are equal
		if (isEqual) {
			Serial.println("correcto!");
		}
		delay(500);
	}
}