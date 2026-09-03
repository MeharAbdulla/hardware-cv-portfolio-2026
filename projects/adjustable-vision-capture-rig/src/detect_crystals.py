"""Raspberry Pi / host crystal detection with YOLOv8.

Usage:
  python src/detect_crystals.py --source media/prototype.jpg --weights yolov8n.pt --save
  python src/detect_crystals.py --source 0 --weights weights/best.pt --conf 0.35
"""
from __future__ import annotations

import argparse
from pathlib import Path

from ultralytics import YOLO


def main() -> None:
    ap = argparse.ArgumentParser(description="Detect crystals with YOLOv8 on Pi or PC")
    ap.add_argument("--source", required=True, help="image, video, folder, or camera index")
    ap.add_argument("--weights", default="yolov8n.pt", help="YOLO weights (use weights/best.pt after training)")
    ap.add_argument("--conf", type=float, default=0.35)
    ap.add_argument("--iou", type=float, default=0.45)
    ap.add_argument("--imgsz", type=int, default=640)
    ap.add_argument("--save", action="store_true")
    ap.add_argument("--project", default="runs/detect")
    ap.add_argument("--name", default="crystals")
    args = ap.parse_args()

    source = int(args.source) if str(args.source).isdigit() else args.source
    model = YOLO(args.weights)
    results = model.predict(
        source=source,
        conf=args.conf,
        iou=args.iou,
        imgsz=args.imgsz,
        save=args.save,
        project=args.project,
        name=args.name,
        exist_ok=True,
    )

    total = 0
    for i, r in enumerate(results):
        n = len(r.boxes) if r.boxes is not None else 0
        total += n
        print(f"frame {i}: crystals_detected={n}")
    print(f"total_detections={total}")
    if args.save:
        print(f"saved_under={Path(args.project) / args.name}")


if __name__ == "__main__":
    main()
