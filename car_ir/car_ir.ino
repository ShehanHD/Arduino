#include <IRremote.h>
int tracingPin = 7;
int val;

int echo=3;
int trig=4;

long duration;
int distance;

int in1=9; //sinistra
int in2=10; //sinistra
int enA=5; //sinistra

int in3=11; //destra
int in4=12; //destra
int enB=6; //destra

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
Serial.begin(9600);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
    pinMode(enA,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
    pinMode(enB,OUTPUT);
    
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);

pinMode(tracingPin, INPUT);

  Serial.println("Attende");
  irrecv.enableIRIn();
  Serial.println("IR Enabled");
}

void loop() {  
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

    duration = pulseIn(echo,HIGH);
    distance = duration*0.034/2;

 Serial.print("Distanza: ");
 Serial.println(distance);

    analogWrite(enA, 255);
    analogWrite(enB, 255);

val = digitalRead(tracingPin);
if(val == HIGH)
{ 
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
}
    
if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    
/*if(results.value==0xE0E040BF||results.value==0xF4BA2988){  //avanti
  if(distance>15){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  else{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
}
}  */ 
if(results.value==0xC26BF044||results.value==0xE0E006F9){  //avanti
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW); 
}
if(results.value==0x8AF13528||results.value==0xE0E016E9){  //ferma
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
if(results.value==0x21E7B370||results.value==0xC4FFB646){   //dietro
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
if(results.value==0x758C9D82||results.value==0xE0E0A659){   //sinistra
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
if(results.value==0x53801EE8||results.value==0xE0E046B9){  //adestra
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
delay(100);
}
}
