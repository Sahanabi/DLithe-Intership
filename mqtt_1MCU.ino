#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SAHANA";
const char* password = "12345678";
const char* mqtt_server = "broker.hivemq.com";  // Free public broker

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    while (!client.connect("ESP32Publisher")) {
      delay(500);
    }
  }

  client.loop();

  client.publish("esp32/test", "Hello from ESP32-A!");
  delay(5000);  // Send every 5 seconds
}
