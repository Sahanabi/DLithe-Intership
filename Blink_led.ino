const int LED=42;
void setup()
{
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(LED,HIGH);
  Serial.println("LED is ON");
  delay(1000);
  digitalWrite(LED,LOW);
  Serial.println("LED is OFF");
  delay(2000);
}