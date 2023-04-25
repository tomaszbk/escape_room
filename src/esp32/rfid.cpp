#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include "Rfid.h"

MFRC522 rfid(SS_PIN, RST_PIN);
byte ActualUID[4];
byte answer[4] = {0xD9, 0x8D, 0xF1, 0xB0};
 
void rfidSetup() {
	SPI.begin();			// Init SPI bus
	rfid.PCD_Init();		// Init rfid
	Serial.println("setup esp32 finalizado");
}

int8_t checkRfid() {
	// Reset loop if no new card present on the sensor. Saves power when idle.
	if ( ! rfid.PICC_IsNewCardPresent()) {
		return 0;
	}
	// Read the card
	if ( rfid.PICC_ReadCardSerial()) {
			// Check if the card value is equal to answer
			client.publish("debug","tarjeta detectada");
			for (byte i = 0; i < rfid.uid.size; i++) {
				if (answer[i] != rfid.uid.uidByte[i]){
					client.publish("debug","tarjeta erronea");
					delay(1000);
					return 0;
				}				         
			}
			delay(1000); //check the card is still present
			for (int i = 5; i > 0; i--)
			{	
				if (rfid.PICC_IsNewCardPresent()) {
					if (rfid.PICC_ReadCardSerial()) {
						client.publish("debug","se devolvera 1");
						return 1;
					}
				}
			}
			client.publish("debug","tarjeta retirada antes de tiempo");
			return 0;
	}
	return 0;
}