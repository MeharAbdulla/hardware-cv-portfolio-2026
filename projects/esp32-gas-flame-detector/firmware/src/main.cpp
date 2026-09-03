#include <WiFi.h>
#include <WebServer.h>
#include "secrets.example.h"

const int PIN_GAS = 34;
const int PIN_FLAME = 27;
const int PIN_LED = 2;
const int PIN_BUZZ = 25;
const int GAS_ALARM = 2500;
WebServer server(80);

String page(int gas, bool flame, bool alert) {
  String html = "<!DOCTYPE html><html><head><meta name=viewport content='width=device-width,initial-scale=1'>";
  html += "<title>ESP32 Detector</title><style>body{font-family:sans-serif;background:#111;color:#eee;padding:1rem}";
  html += ".alert{background:#664400;padding:12px;border-radius:8px;margin:8px 0}</style></head><body>";
  html += "<h2>ESP32 Detector</h2>";
  if (alert) html += "<div class=alert>Gas Alerted!</div>";
  html += "<p>Gas Value: <b>" + String(gas) + "</b> / 4095</p>";
  html += "<p>Flame: <b>" + String(flame ? "DETECTED" : "clear") + "</b></p>";
  html += "<meta http-equiv=refresh content=2></body></html>";
  return html;
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_FLAME, INPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZ, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { delay(400); Serial.print("."); }
  Serial.println(WiFi.localIP());
  server.on("/", []() {
    int gas = analogRead(PIN_GAS);
    bool flame = digitalRead(PIN_FLAME) == LOW;
    bool alert = gas > GAS_ALARM || flame;
    digitalWrite(PIN_LED, alert);
    digitalWrite(PIN_BUZZ, alert);
    server.send(200, "text/html", page(gas, flame, alert));
  });
  server.begin();
}

void loop() { server.handleClient(); }
