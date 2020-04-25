#include <MFRC522.h>

MFRC522 rfid(10, 9);

void setup(){
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
}

void loop(){
  if(rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
    String uid = getUID();
    Serial.println("RFID ID: " + uid);
  }
  delay(10);
}

String getUID(){
  String uid = "";
  for(int i = 0; i < rfid.uid.size; i++){
    uid += rfid.uid.uidByte[i] < 0x10 ? "0" : "";
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  rfid.PICC_HaltA();
  return uid;
}
