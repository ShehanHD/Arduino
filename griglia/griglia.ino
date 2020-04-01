#include <IRremote.h>

int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

int tr[4]={A2,A3,A4,A5};
int led[9]={4,5,6,7,8,9,10,11,12};
int i;
int j;

void setup() {
  Serial.begin(9600);
  
  for(j=0; j<=3;j++){
  pinMode(tr[j],OUTPUT);}
  for(i=0; i<=9;i++){
  pinMode(led[i],OUTPUT);}
  
  irrecv.enableIRIn();
  Serial.println("IR Enabled");
}
void loop() {
 for(j=0; j<=3;j++){
    digitalWrite(tr[j],HIGH);
  for(i=0; i<=9;i++){
    digitalWrite(led[i],HIGH);
    delay(300);
    digitalWrite(led[i],LOW);
    }
    digitalWrite(tr[j],LOW);}
  
  for(i=0; i<=9;i++){
    digitalWrite(led[i],HIGH);
  for(j=0; j<=3;j++){
    digitalWrite(tr[j],HIGH);
    delay(300);
    digitalWrite(tr[j],LOW);
  }
    digitalWrite(led[i],LOW);
  }

  for(i=9; i>=0;i--){
    digitalWrite(led[i],HIGH);
  for(j=3; j>=0;j--){
    digitalWrite(tr[j],HIGH);
    delay(300);
    digitalWrite(tr[j],LOW);
  }
    digitalWrite(led[i],LOW);
  }
  for(i=0;i<=8;i++){
  for(j=0;j<=3;j++){
    digitalWrite(tr[j],HIGH);
    digitalWrite(led[j+i],HIGH);
    delay(300);
    digitalWrite(tr[j],LOW);
    digitalWrite(led[j+i],LOW);}}
  /*if (irrecv.decode(&results)) {
   Serial.println(results.value, HEX);
   irrecv.resume();  
   
      if(results.value==0x97483BFB||results.value==0x6627C7F7){
      for(j=1; j<=5;j++)
      {digitalWrite(tr[j],LOW);}
      for(i=0; i<=9;i++){
      digitalWrite(led[i],LOW);}
  }}
  
  while(results.value==0xE318261B)
  {prima();}
  
  while(results.value==0x511DBB||results.value==0xFF629D)
  {seconda();}

  }*/}

void prima(){
  for(j=1; j<=4;j++)
  {digitalWrite(tr[j],HIGH);}
  
  for(i=0; i<=9;i++){
  digitalWrite(led[i],HIGH);
  delay(200);
  digitalWrite(led[i],LOW);}
  for(i=9; i>=0;i--){
  digitalWrite(led[i],HIGH);
  delay(200);
  digitalWrite(led[i],LOW);
  }
  return;
  }

void seconda(){
  for(j=1; j<=4;j++)
  {digitalWrite(tr[j],HIGH);
  for(i=0; i<=9;i++){
  digitalWrite(led[i],HIGH);
  delay(200);
  digitalWrite(led[i],LOW);
  }
  digitalWrite(tr[j],LOW);
  }
  return;
  }

void terza(){
  for(j=1; j<=4;j++){
    digitalWrite(tr[j],HIGH);
  for(i=0; i<=9;i++){
    digitalWrite(led[i],HIGH);
    delay(100);
    digitalWrite(led[i],LOW);
    }
    digitalWrite(tr[j],LOW);}
  
  for(j=4; j<=1;j--){
    digitalWrite(tr[j],HIGH);
  for(i=9; i<=0;i--){
    digitalWrite(led[i],HIGH);
    delay(100);
    digitalWrite(led[i],LOW);
    }
    digitalWrite(tr[j],LOW);}
   
  
}
