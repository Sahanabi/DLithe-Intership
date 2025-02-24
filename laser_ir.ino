int irsensor=12;
int laser=14;

void setup(){
  pinMode(irsensor,INPUT);
  pinMode(laser,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int irsensor_value=digitalRead(irsensor);
  if(irsensor_value==HIGH){
    digitalWrite(laser,HIGH);
    Serial.println("laser is detected");
    delay(2000);
  }
  else{
    digitalWrite(laser,LOW);
    Serial.println("laser is not detected");
    delay(2000);
  }
}