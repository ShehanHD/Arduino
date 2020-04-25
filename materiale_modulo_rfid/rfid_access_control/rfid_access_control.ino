#include <MFRC522.h>
#define GREEN_LED_PIN 2
#define RED_LED_PIN 3

MFRC522 rfid(10, 9);

String users[] = {"745e1adc"};
int usersSize = sizeof(users)/sizeof(String);

void setup(){
  SPI.begin();
  rfid.PCD_Init();
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop(){
  if(rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()){
    String uid = getUID();
    if(checkUID(uid)){
      blinkLed(GREEN_LED_PIN, 2000, 1);
    }else{
      blinkLed(RED_LED_PIN, 400, 2);
    }
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

bool checkUID(String uid){
  for(int i = 0; i < usersSize; i++){
    if(users[i] == uid){
      return true;
    }
  }
  return false;
}

void blinkLed(int led, int duration, int repeat){
  for(int i = 0; i < repeat; i++){
    digitalWrite(led, HIGH);
    delay(duration/2);
    digitalWrite(led, LOW);
    delay(duration/2);
  }
}
