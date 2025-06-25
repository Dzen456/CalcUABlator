import subprocess

def capture_image(output_path, width=1640, height=1232):
    subprocess.run(["libcamera-still", "-o", output_path, "--width", str(width), "--height", str(height)])
    print(f"Imagen capturada y guardada en: {output_path}")

capture_image("test2.jpg")
