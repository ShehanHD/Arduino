int tracingPin = 7;
int val;

int in1=9; //sinistra
int in2=10; //sinistra
int enA=5; //sinistra

int in3=11; //destra
int in4=12; //destra
int enB=6; //destra
void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
    pinMode(enA,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
    pinMode(enB,OUTPUT);

  pinMode(tracingPin, INPUT);

}

void loop() {
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
if(val == LOW){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
}
