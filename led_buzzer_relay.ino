const int LED=42;
const int BUZZER=6;
const int RELAY=5;
void setup(){
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(RELAY,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(LED,HIGH);
  digitalWrite(BUZZER,LOW);
  digitalWrite(RELAY,LOW);
  Serial.println("LED ON, BUZZER OFF, RELAY OFF");
  delay(1000);
  
  digitalWrite(LED,LOW);
  digitalWrite(BUZZER,HIGH);
  digitalWrite(RELAY,LOW);
  Serial.println("LED OFF, BUZZER ON, RELAY OFF");
  delay(1000);
}
