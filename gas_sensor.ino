int gassensor=A0;

void setup(){
  pinMode(gassensor,INPUT);
  Serial.begin(9600);
}

void loop(){
  int gassensor_value=analogRead(gassensor);
  if(gassensor_value<500){
    Serial.println("gassensor value is below 500");
    delay(2000);
  }
  else{
    Serial.println("gassensor value is above 500");
    delay(2000);
    
  }
}