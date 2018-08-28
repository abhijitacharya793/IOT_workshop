//const int D0 = 16;
int d = 500;

void setup() {
  pinMode(D0,OUTPUT);
  digitalWrite(D0,LOW);
}

void loop() {
  digitalWrite(D0,HIGH);
  delay(d);
  digitalWrite(D0,LOW);
  delay(d);  
}
