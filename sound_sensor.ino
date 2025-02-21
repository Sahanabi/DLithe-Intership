int soundsensor=A0;
int led=42;
void setup(){
  pinMode(soundsensor,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int soundsensor_value=analogRead(soundsensor);
    Serial.println(soundsensor_value);
    delay(1000);
    if(soundsensor_value>500){
      digitalWrite(led,HIGH);
      Serial.println("sound is above 500");
      delay(1000);
    }
    else{
      digitalWrite(led,LOW);
      Serial.println("sound is below 500");
      delay(1000);
    }
}