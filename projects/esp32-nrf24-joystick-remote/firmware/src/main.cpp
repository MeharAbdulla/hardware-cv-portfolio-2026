#include <SPI.h>
#include <RF24.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "secrets.example.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);
RF24 radioA(4, 5);
RF24 radioB(16, 17);
const byte addr[6] = "CTRL1";

struct Packet {
  int16_t x;
  int16_t y;
  uint8_t btn;
  uint32_t seq;
};

uint32_t seq = 0;

void setup() {
  Serial.begin(115200);
  pinMode(32, INPUT_PULLUP);
  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  SPI.begin();
  radioA.begin();
  radioB.begin();
  radioA.setPALevel(RF24_PA_HIGH);
  radioB.setPALevel(RF24_PA_HIGH);
  radioA.openWritingPipe(addr);
  radioB.openWritingPipe(addr);
  radioA.stopListening();
  radioB.stopListening();
}

void loop() {
  Packet p;
  p.x = map(analogRead(34), 0, 4095, -100, 100);
  p.y = map(analogRead(35), 0, 4095, -100, 100);
  p.btn = digitalRead(32) == LOW;
  p.seq = ++seq;
  bool okA = radioA.write(&p, sizeof(p));
  bool okB = radioB.write(&p, sizeof(p));
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("nRF24 Remote");
  display.printf("X:%d Y:%d B:%u\n", p.x, p.y, p.btn);
  display.printf("TX A:%s B:%s\n", okA ? "OK" : "--", okB ? "OK" : "--");
  display.printf("seq %lu", (unsigned long)p.seq);
  display.display();
  delay(40);
}
