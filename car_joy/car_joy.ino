#include <IRremote.h>

const int in1=9;
const int in2=10;
const int in3=11;
const int in4=12;

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  

  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();

if(results.value==0xC26BF044||results.value==0xE0E006F9){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
if(results.value==0x8AF13528||results.value==0xE0E016E9){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
if(results.value==0x21E7B370||results.value==0xC4FFB646){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
if(results.value==0x758C9D82||results.value==0xE0E0A659){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
if(results.value==0x53801EE8||results.value==0xE0E046B9){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
}
  delay(100);
}
