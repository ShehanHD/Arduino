int led1=13;
int led2=12;
int led3=11;
int led4=10;
int led5=9;
int led6=8;
int led7=7;
int led8=6;
int t=1000;
//int pote=A5;
//int readv;
//float t;

void setup() {
  Serial.begin(9600);
  //pinMode(pote,INPUT);
  pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
     pinMode(led4,OUTPUT);
      pinMode(led5,OUTPUT);
       pinMode(led6,OUTPUT);
        pinMode(led7,OUTPUT);
         pinMode(led8,OUTPUT);
}

void loop() {
//readv=analogRead(pote);
//t=map(readv,0,1023 ,0 ,1000);
//Serial.println(t);


  
  digitalWrite(led1,HIGH);
  delay(t);
  digitalWrite(led1,LOW);
  delay(t);
   digitalWrite(led2,HIGH);
  delay(t);
  digitalWrite(led2,LOW);
  delay(t);
   digitalWrite(led3,HIGH);
  delay(t);
  digitalWrite(led3,LOW);
  delay(t);
   digitalWrite(led4,HIGH);
  delay(t);
  digitalWrite(led4,LOW);
  delay(t);
   digitalWrite(led5,HIGH);
  delay(t);
  digitalWrite(led5,LOW);
  delay(t);
   digitalWrite(led6,HIGH);
  delay(t);
  digitalWrite(led6,LOW);
  delay(t);
   digitalWrite(led7,HIGH);
  delay(t);
  digitalWrite(led7,LOW);
  delay(t);
   digitalWrite(led8,HIGH);
  delay(t);
  digitalWrite(led8,LOW);
  delay(t);

}
