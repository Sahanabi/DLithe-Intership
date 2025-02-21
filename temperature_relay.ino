#include <Bonezegei_DHT11.h>
Bonezegei_DHT11 dht(14);
int RELAY=5;
void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(RELAY,OUTPUT);
}

void loop() 
{

  if (dht.getData()) {                       
    float tempDeg = dht.getTemperature();     
    float tempFar = dht.getTemperature(true);  
    int hum = dht.getHumidity();               
    String str  = "Temperature: ";
           str += tempDeg;
           str += "°C  ";
           str += tempFar;
           str += "°F  Humidity:";
           str += hum;
    Serial.println(str.c_str());
  

  
  if(tempDeg<30)
  {
    digitalWrite(RELAY,HIGH);
    Serial.println("FAN is turn on");
    delay(2000);

  }
  else
  {
    digitalWrite(RELAY,LOW);
    Serial.println("FAN is turn off");
    delay(2000);


  }
  }  
}