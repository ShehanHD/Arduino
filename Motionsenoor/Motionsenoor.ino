int msen=9;
int led=4;
int val;
int msenState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(msen,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  val=digitalRead(msen);

  Serial.println(val);
  
if(val==1)
{ val==1;
  digitalWrite(led,HIGH);}
else
{digitalWrite(led,LOW);}
}
