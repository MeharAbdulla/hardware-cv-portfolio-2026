# Plant Disease Detection (YOLOv8) — project summary

**Source materials:** `Plant_Disease_Detection_YOLOv8_Report.docx`, demo video `leaf detection.mp4`  
**Build window:** Aug–Sep 2026 portfolio documentation

## Goal

Classify / localize diseased leaf regions from camera or video input to support early agricultural intervention.

## Method (portfolio implementation)

1. Curate leaf imagery with disease-class labels (healthy vs common blight / spot classes as available).
2. Fine-tune YOLOv8 for detection or classification depending on annotation style.
3. Run inference on stills or video; draw boxes / labels for operator review.
4. Log confidence scores for threshold tuning in field conditions.

## Outputs

- Demo frame in `media/demo-frame.jpg`
- Inference CLI in `src/infer.py`
- Full demo video available on request (not in git)

## Notes

Lighting and leaf orientation dominate real-world accuracy—README covers basic preprocessing tips.
