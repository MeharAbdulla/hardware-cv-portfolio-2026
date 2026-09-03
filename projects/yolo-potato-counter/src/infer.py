"""YOLOv8 inference CLI for portfolio demos.

Usage:
  python src/infer.py --source media/demo-frame.jpg --weights yolov8n.pt
  python src/infer.py --source path/to/video.mp4 --weights weights/best.pt --save

Replace yolov8n.pt with your fine-tuned checkpoint for domain accuracy.
"""
from __future__ import annotations

import argparse
from pathlib import Path

from ultralytics import YOLO


def main() -> None:
    ap = argparse.ArgumentParser(description="Run YOLOv8 detection")
    ap.add_argument("--source", required=True, help="image, video, or folder")
    ap.add_argument("--weights", default="yolov8n.pt", help="model weights")
    ap.add_argument("--conf", type=float, default=0.35)
    ap.add_argument("--iou", type=float, default=0.45)
    ap.add_argument("--save", action="store_true", help="write annotated outputs")
    ap.add_argument("--project", default="runs/detect")
    ap.add_argument("--name", default="predict")
    ap.add_argument("--count-class", default=None, help="optional class name to count")
    args = ap.parse_args()

    model = YOLO(args.weights)
    results = model.predict(
        source=args.source,
        conf=args.conf,
        iou=args.iou,
        save=args.save,
        project=args.project,
        name=args.name,
        exist_ok=True,
    )

    total = 0
    for i, r in enumerate(results):
        n = len(r.boxes) if r.boxes is not None else 0
        if args.count_class and r.names:
            ids = [int(b.cls) for b in r.boxes] if r.boxes is not None else []
            n = sum(1 for c in ids if r.names.get(c, "").lower() == args.count_class.lower())
        total += n
        print(f"frame/item {i}: detections={n}")

    print(f"total_detections={total}")
    if args.save:
        out = Path(args.project) / args.name
        print(f"saved_under={out}")


if __name__ == "__main__":
    main()
