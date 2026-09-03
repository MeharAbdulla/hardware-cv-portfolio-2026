#include <TFT_eSPI.h>
#include <DHT.h>

TFT_eSPI tft = TFT_eSPI();
DHT dht(4, DHT11);

void drawHome(float t, float h) {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("MECHANICAL 2K23", 10, 10, 2);
  tft.drawString("HAVE A PRODUCTIVE DAY", 10, 50, 2);
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.drawString("TEMPERATURE " + String(t, 1) + " C", 10, 90, 2);
  tft.drawString("HUMIDITY " + String(h, 1) + "%", 10, 120, 2);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.drawString("ENGINE  SUBJECTS", 10, 180, 2);
  tft.drawString("WEATHER QUOTES", 10, 210, 2);
}

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t)) t = 0;
  if (isnan(h)) h = 0;
  drawHome(t, h);
  delay(2000);
}
