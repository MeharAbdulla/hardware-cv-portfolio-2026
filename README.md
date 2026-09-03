# Hardware & CV Portfolio (Aug–Sep 2026)

Hands-on **ESP32 / IoT / embedded** builds and **YOLOv8 computer-vision** demos from a focused build window (**3 August – 2 September 2026**). Each folder is a standalone project with firmware or Python, a BOM-style README, and prototype photos.

**Author:** [MeharAbdulla](https://github.com/MeharAbdulla) · AI & Automation / Embedded

---

## Hardware & IoT

| Project | What it is |
|---|---|
| [esp32-nrf24-joystick-remote](projects/esp32-nrf24-joystick-remote) | Dual nRF24L01 long-range joystick remote with OLED status |
| [esp32-gas-flame-detector](projects/esp32-gas-flame-detector) | Portable gas & flame safety node with live mobile gauge |
| [esp32-fertilizer-spray-robot](projects/esp32-fertilizer-spray-robot) | Solar-assisted fertilizer spraying robot |
| [esp32-home-assistant-mqtt-monitor](projects/esp32-home-assistant-mqtt-monitor) | DHT sensing published over MQTT for Home Assistant dashboards |
| [ip66-field-monitor-node](projects/ip66-field-monitor-node) | Rugged IP66 enclosure monitor with local LCD |
| [rfid-biometric-attendance](projects/rfid-biometric-attendance) | RC522 RFID attendance kiosk with OLED prompts |
| [adjustable-vision-capture-rig](projects/adjustable-vision-capture-rig) | Height-adjustable camera capture platform |
| [smart-sleep-quality-monitor](projects/smart-sleep-quality-monitor) | Ambient sleep-quality tracker with OLED metrics + audio |
| [mechanical-2k23-desk-assistant](projects/mechanical-2k23-desk-assistant) | TFT desk assistant (time, climate, menus) |
| [vortex-esp32-devboard-firmware](projects/vortex-esp32-devboard-firmware) | Bring-up firmware for a Vortex-class ESP32 board |

## Computer vision

| Project | What it is |
|---|---|
| [yolo-sheep-counter](projects/yolo-sheep-counter) | YOLOv8 flock counting from video |
| [yolo-plant-disease-detector](projects/yolo-plant-disease-detector) | Leaf / plant disease detection with YOLOv8 |
| [yolo-potato-counter](projects/yolo-potato-counter) | Produce counting pipeline for potatoes |

---

## Quick start

```bash
git clone https://github.com/MeharAbdulla/hardware-cv-portfolio-2026.git
cd hardware-cv-portfolio-2026
```

- **Firmware projects:** open `projects/<name>/firmware` in PlatformIO or Arduino IDE. Copy `secrets.example.h` → `secrets.h` and fill local credentials (never commit `secrets.h`).
- **CV projects:** `cd projects/<name> && python -m venv .venv && pip install -r requirements.txt`.

## Upwork / sharing

See [UPWORK-SHARE.md](UPWORK-SHARE.md). No live secrets ship in this repo—only examples.

## License

MIT — see [LICENSE](LICENSE).
