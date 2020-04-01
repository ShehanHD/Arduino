#include <IRremote.h>

int RECV_PIN = 11;
int led=4;
int led1=5;
int led2=6;
int i;
int n=0;
int m=0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

     if(results.value==0xE0E046B9){n++;
     Serial.println(n);
     if(n==1){digitalWrite(led,!digitalRead(led));}
     else {digitalWrite(led,LOW);}   
     if(n==2){digitalWrite(led1,!digitalRead(led1));} 
     else {digitalWrite(led1,LOW);} 
     if(n==3){digitalWrite(led2,!digitalRead(led2));}
     else {digitalWrite(led2,LOW);}}
  

    irrecv.resume(); // il prossimo valore
  }
  }
  
