#include <WiFi.h>
#include <WebServer.h>
#include "secrets.example.h"

const int M[4] = {26, 27, 14, 12};
const int PUMP = 25;
WebServer server(80);

void motors(int a, int b, int c, int d) {
  digitalWrite(M[0], a); digitalWrite(M[1], b);
  digitalWrite(M[2], c); digitalWrite(M[3], d);
}
void stopAll() { motors(LOW, LOW, LOW, LOW); digitalWrite(PUMP, LOW); }

void setup() {
  Serial.begin(115200);
  for (int p : M) pinMode(p, OUTPUT);
  pinMode(PUMP, OUTPUT);
  stopAll();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(400);
  server.on("/", []() {
    server.send(200, "text/html",
      "<h3>Spray Robot</h3>"
      "<a href=/fwd>Forward</a> | <a href=/stop>Stop</a> | <a href=/spray>Spray</a>");
  });
  server.on("/fwd", []() { motors(HIGH, LOW, HIGH, LOW); server.sendHeader("Location", "/"); server.send(302); });
  server.on("/stop", []() { stopAll(); server.sendHeader("Location", "/"); server.send(302); });
  server.on("/spray", []() { digitalWrite(PUMP, HIGH); delay(1500); digitalWrite(PUMP, LOW); server.sendHeader("Location", "/"); server.send(302); });
  server.begin();
  Serial.println(WiFi.localIP());
}
void loop() { server.handleClient(); }
