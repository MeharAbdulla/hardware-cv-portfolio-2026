# Crystal detection notes

## Goal

Detect and count crystal-like objects from a top-down Raspberry Pi camera mounted on an adjustable lab-jack rig.

## Pipeline

1. Stabilize height with the scissor lift for consistent focus / scale.
2. Capture frames with OpenCV (`capture_preview.py`).
3. Run YOLOv8 on-device or on a host (`detect_crystals.py`).
4. Export annotated frames for QA and dataset review.

## Training tip

Label a small crystal dataset (Roboflow / CVAT), train YOLOv8n or YOLOv8s, place `best.pt` in `weights/`, then point `--weights weights/best.pt`.
