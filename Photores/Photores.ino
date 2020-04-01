#include <Servo.h>

Servo servobase;
Servo servolaterale;

int photores1 = A0;
int photores2 = A1;
int photores3 = A2;
int photores4 = A3;
int val1;
int val2;
int val3;
int val4;
int i=90;
int j=90;
void setup() {
  Serial.begin(9600);
  servobase.attach(9);
  servolaterale.attach(10);
  pinMode(photores1, INPUT);
  pinMode(photores2, INPUT);
  pinMode(photores3, INPUT);
  pinMode(photores4, INPUT);

  servobase.write(90);                  
  delay(15);
  servolaterale.write(90);                
  delay(15);
}

void loop() {
  val1=analogRead(photores1)-400;
  val2=analogRead(photores2)-400;
  val3=analogRead(photores3)-400;
  val4=analogRead(photores4)-400;
  
  Serial.print("Valore 1:");
  Serial.println(val1);
  Serial.print("     Valore 2:");
  Serial.println(val2);
  Serial.print("           Valore 3:");
  Serial.println(val3);
  Serial.print("               Valore 4:");
  Serial.println(val4);
  delay(2000);

if(val1>575&&val2>575){
  for(i=j; i<130; i++){
  servolaterale.write(i);                  
  delay(15);}
}
if(val3>575&&val4>575){
  for(j=i; j>50; j--){
  servolaterale.write(j);                  
  delay(15);}
}
if(val1>600&&val3>600){
  servobase.write(120);                  
  delay(15);
}  
}
