#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "secrets.example.h"

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient mqtt(espClient);

void reconnect() {
  while (!mqtt.connected()) {
    if (mqtt.connect("esp32-climate", MQTT_USER, MQTT_PASSWORD)) {
      mqtt.publish("home/esp32/status", "online", true);
    } else delay(2000);
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(400);
  mqtt.setServer(MQTT_HOST, MQTT_PORT);
}

void loop() {
  if (!mqtt.connected()) reconnect();
  mqtt.loop();
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (!isnan(t) && !isnan(h)) {
    char buf[32];
    dtostrf(t, 4, 1, buf); mqtt.publish("home/esp32/temperature", buf, true);
    dtostrf(h, 4, 1, buf); mqtt.publish("home/esp32/humidity", buf, true);
    Serial.printf("T=%.1f H=%.1f\n", t, h);
  }
  delay(5000);
}
