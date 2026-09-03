#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int PIN_PROBE = A0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Field Monitor");
}

void loop() {
  int raw = analogRead(PIN_PROBE);
  float v = raw * (5.0 / 1023.0);
  lcd.setCursor(0, 1);
  lcd.print("Probe ");
  lcd.print(v, 2);
  lcd.print("V   ");
  delay(500);
}
