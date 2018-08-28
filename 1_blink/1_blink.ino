const int ledPin = 16;
int d = 500;

void setup() {
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
}

void loop() {
  digitalWrite(ledPin,HIGH);
  delay(d);
  digitalWrite(ledPin,LOW);
  delay(d);  
}
