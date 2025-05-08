#include <WiFi.h>
#include <WiFiClient.h>
#include <DHT.h>
#include <ThingSpeak.h>

// WiFi credentials
const char* ssid = "SAHANA";
const char* password = "12345678";

// ThingSpeak settings
unsigned long channelID = 2951662;
const char* writeAPIKey = "GW7A0J410IG1SUH1";

// DHT setup
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Ultrasonic sensor setup
#define TRIG_PIN 5
#define ECHO_PIN 4

// IR sensor setup
#define IR_PIN 11  // Digital pin connected to IR sensor

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IR_PIN, INPUT);  // IR sensor as input

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Ultrasonic distance measurement
  long duration;
  float distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0343 / 2;

  // IR sensor reading
  int irValue = digitalRead(IR_PIN);  // 0 = object detected, 1 = no object

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C, Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Distance: ");
  Serial.print(distance);
  Serial.print(" cm, IR: ");
  Serial.println(irValue == 0 ? "Object Detected" : "Clear");

  // Send data to ThingSpeak
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, hum);
  ThingSpeak.setField(3, distance);
  ThingSpeak.setField(4, irValue); // Field 4: IR sensor value

  int status = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (status == 200) {
    Serial.println("Data pushed to ThingSpeak");
  } else {
    Serial.print("Push error: ");
    Serial.println(status);
  }

  delay(15000);  // 15s delay for ThingSpeak rate limit
}
