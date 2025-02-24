int flamesensor=13;

void setup()
{
  pinMode(flamesensor,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int flamesensor_value=digitalRead(flamesensor);
  if(flamesensor_value==HIGH)
  {
    Serial.println("flame is detected");
    delay(2000);
  }
  else
   {
    Serial.println("flame is not detected");
    delay(2000);
  }
}
