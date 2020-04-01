int led = 3;
int bot = 2;

int botState;

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(bot, INPUT);
}

void loop() {
  botState = digitalRead(bot);
  Serial.println(botState);

  /*if(botState==1){
    botState!=botState;
    digitalWrite(led,HIGH);
    }
    else{digitalWrite(led,LOW);}*/
}
