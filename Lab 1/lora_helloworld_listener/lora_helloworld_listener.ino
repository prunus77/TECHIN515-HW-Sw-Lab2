#include <SPI.h>
#include <LoRa.h>

// define the pins used by the LoRa module
#define ss 5
#define rst 14
#define dio0 2

void setup() {
  Serial.begin(115200);
  Serial.println("LoRa Receiver");

  // setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);

  while (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed...");
    delay(500);
  }

  LoRa.setSyncWord(0xF3); // sync word must match transmitter
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet: '");
    
    String LoRaData = "";
    while (LoRa.available()) {
      LoRaData += (char)LoRa.read();
    }
    
    Serial.print(LoRaData);
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }

  delay(10); // tiny delay to avoid busy-waiting
}
