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

void setup() {
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
    pinMode(enA,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
    pinMode(enB,OUTPUT);
    
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
 if(distance>15){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
 }
  else{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
}
