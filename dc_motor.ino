const int relay=5;

void setup(){
  pinMode(relay,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(relay,HIGH);
  Serial.println("DC motor turns ON");
  delay(5000);

  digitalWrite(relay,LOW);
  Serial.println("DC motor turns OFF");
  delay(5000);
}
