# Counting Sheep — project summary

**Source materials:** `Counting_Sheep_Research_Paper.docx`, demo video `output_sheeps2.mp4`  
**Build window:** Aug–Sep 2026 portfolio documentation

## Goal

Detect and count sheep in farm / pasture video using a single-stage object detector (YOLOv8-class pipeline), then aggregate per-frame counts into a stable flock estimate.

## Method (portfolio implementation)

1. Collect or sample video frames of sheep in outdoor scenes.
2. Train or fine-tune a YOLOv8 detection model on sheep-class labels (or use a domain-adapted checkpoint).
3. Run frame-wise inference; apply simple temporal smoothing (moving median) to reduce flicker.
4. Export annotated video and a CSV of timestamp → count.

## Outputs

- Annotated demo frames (see `media/demo-frame.jpg`)
- CLI script in `src/infer.py`
- Full-length demo video kept locally (available on request; not committed due to size)

## Notes

This folder ships a **runnable inference skeleton**. Swap `weights/best.pt` with your trained checkpoint for production accuracy.
