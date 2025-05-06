#include <WiFi.h>

const char* ssid = "SAHANA";
const char* password = "12345678";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("New Client.");
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    // Send webpage
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML><html>");
    client.println("<h1>Welcome to NEW WEBPAGE!</h1>");
    client.println("<p>This is a basic website hosted by ESP32.</p>");
    client.println("</html>");
    
    delay(10);
    client.stop();
    Serial.println("Client disconnected.");
  }
}
