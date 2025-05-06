#include <WiFi.h>
#include <DHT.h>

const char* ssid = "SAHANA";
const char* password = "12345678";

WiFiServer server(80);

const int ledPin = 13;       
const int buzzerPin = 35;   
#define DHTPIN 10           
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client.");
    String request = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n') break;
      }
    }

    if (request.indexOf("/led/on") != -1) {
      digitalWrite(ledPin, HIGH);
    }
    if (request.indexOf("/led/off") != -1) {
      digitalWrite(ledPin, LOW);
    }
    if (request.indexOf("/buzzer/on") != -1) {
      digitalWrite(buzzerPin, HIGH);
    }
    if (request.indexOf("/buzzer/off") != -1) {
      digitalWrite(buzzerPin, LOW);
    }

    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<html><body><h1>ESP32 Control Panel</h1>");

    client.println("<h2>Temperature: " + String(temp) + " °C</h2>");
    client.println("<h2>Humidity: " + String(hum) + " %</h2>");

    client.println("<h2>LED Control</h2>");
    client.println("<a href=\"/led/on\"><button>LED ON</button></a>");
    client.println("<a href=\"/led/off\"><button>LED OFF</button></a>");

    client.println("<h2>Buzzer Control</h2>");
    client.println("<a href=\"/buzzer/on\"><button>Buzzer ON</button></a>");
    client.println("<a href=\"/buzzer/off\"><button>Buzzer OFF</button></a>");

    client.println("</body></html>");

    client.stop();
    Serial.println("Client Disconnected.");
  }
}
