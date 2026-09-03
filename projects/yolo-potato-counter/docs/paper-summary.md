# Potato Counter — project summary

**Source materials:** `Potato_Counter_Paper.docx`, demo video `potato.mp4`  
**Build window:** Aug–Sep 2026 portfolio documentation

## Goal

Count potatoes on a conveyor / tray from video to automate yield sampling and packing QC.

## Method (portfolio implementation)

1. Detect individual potatoes with a YOLOv8 detector trained on produce imagery.
2. Optionally track IDs across frames (ByteTrack-style) to avoid double-counting on a moving belt.
3. Emit running totals and a final session count.
4. Export annotated preview for operator verification.

## Outputs

- Demo frame in `media/demo-frame.jpg`
- Inference + counting helpers in `src/infer.py`
- Full demo video available on request (not in git)

## Notes

Occlusion and overlapping produce are the main failure modes; the script exposes an IoU / confidence threshold for tuning.
