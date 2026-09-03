// Vortex-class bring-up: blink status LEDs and read user button.
// Adjust GPIO numbers to match your board silkscreen / schematic.

const int LEDS[] = {2, 4, 5, 12, 13, 14, 15, 16, 17};
const int BTN = 0;

void setup() {
  Serial.begin(115200);
  for (int p : LEDS) pinMode(p, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  Serial.println("Vortex bring-up ready");
}

void loop() {
  bool pressed = digitalRead(BTN) == LOW;
  for (int i = 0; i < 9; i++) {
    digitalWrite(LEDS[i], pressed ? HIGH : ((millis() / 150 + i) % 2));
  }
  delay(30);
}
