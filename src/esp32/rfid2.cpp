#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN    21
#define RST_PIN   22

// #define MOSI_PIN 11 // Change to the desired digital pin number
// #define MISO_PIN 12 // Change to the desired digital pin number
// #define SCK_PIN 13 // Change to the desired digital pin number


//rfid rfid(SDA_PIN, RST_PIN);  // Create rfid instance
MFRC522 rfid(SS_PIN, RST_PIN);
byte ActualUID[4];
byte answer[4] = {0xD9, 0x8D, 0xF1, 0xB0};
 
void setup() {
	Serial.begin(9600);
	SPI.begin();			// Init SPI bus
	rfid.PCD_Init();		// Init rfid
	delay(400);				// Optional delay. Some board do need more time after init to be ready, see Readme
	rfid.PCD_DumpVersionToSerial();	// Show details of PCD - rfid Card Reader details
	Serial.println("Scan PICC to see UID, SAK, type, and data blocks...");
	Serial.println("listorta");
}

int8_t checkRfid() {
	// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	if ( ! rfid.PICC_IsNewCardPresent()) {
		return 0;
	}
	// Select one of the cards
	if ( rfid.PICC_ReadCardSerial()) {
			// Check if the values are equal
			Serial.println("tarjeta detectada");
			for (byte i = 0; i < rfid.uid.size; i++) {
				if (answer[i] != rfid.uid.uidByte[i]){
					Serial.println("tarjeta erronea");
					delay(1000);
					return 0;
				}				         
			}
			delay(1000); //check the card is still present
			for (int i = 5; i > 0; i--)
			{	
				if (rfid.PICC_IsNewCardPresent()) {
					if (rfid.PICC_ReadCardSerial()) {
						return 1;
					}
				}
			}
			Serial.println("tarjeta retirada antes de tiempo");
			return 0;
	}
	return 0;
}

void loop(){
	if (checkRfid()){
		Serial.println("correcto");
		delay(1000);
	}
	
}