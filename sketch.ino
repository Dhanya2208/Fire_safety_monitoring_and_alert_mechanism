#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 15           // DHT22 connected to GPIO 15
#define DHTTYPE DHT22
#define GAS_SENSOR 34       // MQ2 AOUT connected to GPIO 34
#define LED_PIN 13          // LED for fire alert

const char* ssid = "Wokwi-GUEST";      // Wokwi virtual WiFi
const char* password = "";             // No password
const char* apiKey = "VA0CAOMQWO0GEJVY";   // 🔴 Replace with your ThingSpeak API key
const char* server = "http://api.thingspeak.com/update";

DHT dht(DHTPIN, DHTTYPE);
String location = "Chennai%2C%20India"; // Already URL encoded
String latitude = "13.067439";
String longitude = "80.237617";
void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(GAS_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Connect to WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void loop() {
  float temperature = dht.readTemperature();
  int gasValue = analogRead(GAS_SENSOR);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\tGas: ");
  Serial.println(gasValue);

  if (temperature > 45 && gasValue > 400) {
    Serial.println("🔥 FIRE DETECTED!");
    Serial.println("📍 Location: " + location);
    Serial.println("🌐 Coordinates: Latitude: " + latitude + ", Longitude: " + longitude);
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Send to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(server) + "?api_key=" + apiKey +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(gasValue)+
                 "&field3=" + location +
                 "&field4=" + latitude +
                 "&field5=" + longitude;
    Serial.println("Sending to URL: " + url);
    http.begin(url);
    int httpCode = http.GET();  // Send the request

    if (httpCode > 0) {
      Serial.println("📶 Data sent to ThingSpeak.");
    } else {
      Serial.print("❌ Error sending data: ");
      Serial.println(http.errorToString(httpCode).c_str());
    }
    http.end();
  }

  delay(20000); // ThingSpeak requires 15-20 seconds between updates
}
