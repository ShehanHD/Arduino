#include DHT.h

int temp=A0;

void setup() {
  pinMode(temp,INPUT);
  delay(1000);
  Serial.begin(9600);

}

void loop() {
  int val= analogRead(temp);
  Serial.println(val);

}
