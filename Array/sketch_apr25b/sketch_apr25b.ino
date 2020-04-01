int led[8]={13,12,11,10,9,8,7,6};
void setup() {
  pinMode(led,OUTPUT);

}

void loop() {
  for(int i=0;i<8;i++){
  digitalWrite(led[i],HIGH);
  delay(1000);
  digitalWrite(led[i],LOW);
  delay(1000);
  }

}
