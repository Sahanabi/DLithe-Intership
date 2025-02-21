int touchsensor=14;

void setup(){
  pinMode(touchsensor,INPUT);
  Serial.begin(9600);
}
void loop(){
  int touchsensor_value=digitalRead(touchsensor);
  if(touchsensor_value==HIGH){
    Serial.println("Touch is detected");
    delay(1000);
  }
  else{
    Serial.println("Touch is not detected");
    delay(1000);
  }
}
