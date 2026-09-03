# YOLOv8 Plant Disease Detector

![demo](media/demo-frame.jpg)

Detect diseased leaf regions from stills or video to support early agricultural intervention.

**Build window:** 3 Aug – 2 Sep 2026 (portfolio documentation)  
**Paper notes:** see [docs/paper-summary.md](docs/paper-summary.md)

## Quick start

```bash
python -m venv .venv
# Windows: .venv\Scripts\activate
pip install -r requirements.txt
python src/infer.py --source media/demo-frame.jpg --weights yolov8n.pt --save
```

Place fine-tuned weights in `weights/best.pt` and pass `--weights weights/best.pt` for domain accuracy.

## Project layout

- `src/infer.py` — detection / counting CLI
- `media/demo-frame.jpg` — frame extracted from local demo video
- `docs/paper-summary.md` — method summary from source report
- `weights/` — put checkpoints here (ignored by git except `.gitkeep`)

## Notes

Fine-tune on your disease classes, then point `--weights` at `weights/best.pt`. Demo video available on request.

## Upwork-safe

No API keys or private datasets are included. See [UPWORK-SHARE.md](../../UPWORK-SHARE.md).
