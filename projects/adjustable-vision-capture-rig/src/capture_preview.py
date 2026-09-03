"""Preview helper for the adjustable vision capture rig."""
import argparse
import cv2

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--source", default="0", help="camera index or video path")
    ap.add_argument("--out", default="media/sample_capture.jpg")
    args = ap.parse_args()
    src = int(args.source) if args.source.isdigit() else args.source
    cap = cv2.VideoCapture(src)
    if not cap.isOpened():
        raise SystemExit(f"Cannot open source: {args.source}")
    ok, frame = cap.read()
    cap.release()
    if not ok:
        raise SystemExit("Failed to grab frame")
    cv2.imwrite(args.out, frame)
    print(f"Wrote {args.out} shape={frame.shape}")

if __name__ == "__main__":
    main()
