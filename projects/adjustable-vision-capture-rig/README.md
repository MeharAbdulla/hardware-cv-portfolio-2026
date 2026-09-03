# Adjustable Vision Capture Rig

![prototype](media/prototype.jpg)

Lab-jack height platform for downward-facing camera capture — stable macro / document / CV dataset collection.

**Build window:** 3 Aug – 2 Sep 2026 (portfolio documentation)

## Features

- Prototype-faithful pin map and BOM
- Upwork-safe: no live Wi-Fi / MQTT credentials in the repo
- Example secrets template only (`secrets.example.h`)

## Bill of materials

- Lab jack / scissor lift
- Camera module or SBC camera
- Mounting plate
- HDMI / USB capture link

## Pin map

N/A (mechanical + host software)

## Flash / run

```bash
python src/capture_preview.py --source 0
```

## Safety

Never commit `secrets.h`. See the repo root [UPWORK-SHARE.md](../../UPWORK-SHARE.md).
