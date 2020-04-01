int photores = A0;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(photores, INPUT);

}

void loop() {
  val=analogRead(photores);

  Serial.println(photores);

}
