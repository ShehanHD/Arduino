#include <LiquidCrystal.h>

int echo=13;
int trig=12;

long duration;
int distance;

LiquidCrystal LCD(10, 9, 5, 4, 3, 2);

void setup() {
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);

  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Dist. ");
  LCD.setCursor(9,2);
  LCD.print("cm");

 

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

 duration = pulseIn(echo,HIGH);
 distance = duration*0.034/2;

 Serial.print("Distanza: ");
 Serial.println(distance);

  LCD.clear();
  
  LCD.setCursor(7,0);
  LCD.print(distance);
  

}
