 //color sensor
int s2=5;
int s3=6;
unsigned int pinout=7;
int red;
int green;
int blue;

//ultra sonic
int trig=10;
int echo=11;
long duration;
int distance;

void setup() {
  Serial.begin(115200);
  //color sensor
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(pinout,INPUT);
  
  //ultra sonic
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);

}

void loop() {
  //calcolare la distanza
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;

  //per trovare colore rosso
  //s2 & s3 LOW
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  
  red=pulseIn(pinout,LOW);
  red=map(red, 50, 0, 0, 255);
  //per trovare colore verde
  //s2 & s3 HIGH
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  
  green=pulseIn(pinout,LOW);
  green=map(green, 70, 0, 0, 255);
  //per trovare colore blu
  //s2 LOW & s3 HIGH
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  
  blue=pulseIn(pinout,LOW);
  blue=map(blue, 50, 0, 0, 255);

  if(red>green && green>blue){
    red=255;
    green=green/2;
    blue=0;}
  if(red>blue && blue>green){
    red=255;
    green=0;
    blue=blue/2;}
  delay(150);
    
  if(green>red && red>blue){
    red=red/2;
    green=255;
    blue=0;}
  if(green>blue && blue>red){
    red=0;
    green=255;
    blue=blue/2;}
  delay(150);  
  if(blue>red && red>green){
    red=red/2;
    green=0;
    blue=255;}
  if(blue>green && green>red){
    red=0;
    green=green/2;
    blue=255;}
  delay(150);

  
  Serial.print(red);
  Serial.print(",");
  Serial.print(green);
  Serial.print(",");
  Serial.print(blue);
  Serial.print(",");
  Serial.println(distance);
  delay(150);

  

}
