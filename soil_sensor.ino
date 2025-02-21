int soilsensor=A0;
int buzzer=6;

void setup(){
  pinMode(soilsensor,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int soilsensor_value=analogRead(soilsensor);
  Serial.println(soilsensor_value);
  delay(1000);
  if(soilsensor_value<500){
    Serial.println("soil moisture is below 500");
    analogWrite(buzzer,HIGH);
    delay(1000);
  }
  else{
    analogWrite(buzzer,LOW);
    delay(1000);
  }
}