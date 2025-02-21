#include <Ultrasonic.h>

int led=42;
int relay=5;
int buzzer=6;

void setup(){
  pinMode(led,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  #include <Ultrasonic.h>
int led=42;
int relay=5;
int buzzer=6;
Ultrasonic ultrasonic(12, 13);
int distance;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();
  if(distance<5){
  digitalWrite(led,HIGH);
  digitalWrite(relay,LOW);
  digitalWrite(buzzer,LOW);
  delay(2000);

  digitalWrite(led,LOW);
  digitalWrite(relay,HIGH);
  digitalWrite(buzzer,LOW);
  delay(2000);

  digitalWrite(led,LOW);
  digitalWrite(relay,LOW);
  digitalWrite(buzzer,HIGH);
  delay(2000);
  }
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(1000);
}

  