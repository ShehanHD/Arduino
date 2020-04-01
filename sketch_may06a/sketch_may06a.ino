int led[9]={4,5,6,7,8,9,10,11,12};
int tr[4]={2,3,A4,A5};
int i;
int j;
void setup() {
  for(i=0; i<10;i++){
  pinMode(led[i],OUTPUT);}
  for(j=0; j<5;j++){
  pinMode(tr[j],OUTPUT);}

}
void loop() {
  digitalWrite(led[0],HIGH);
  digitalWrite(tr[0],HIGH);
  }
