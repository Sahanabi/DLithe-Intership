#include <WiFi.h>
#include <WiFiManager.h>  

void setup() {
  Serial.begin(115200);

  WiFiManager wifiManager;

 
  if (!wifiManager.autoConnect("ESP32_Config_AP")) {
    Serial.println("Failed to connect to WiFi, starting Wi-Fi manager portal...");
    delay(3000);
  
    ESP.restart();
  }


  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

}
