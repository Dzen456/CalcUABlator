
# Referencia: https://raspberrypi-guide.github.io/electronics/camera-positioning

import numpy as np

def calcdist(angle_of_view, plane_of_view):
    result = (plane_of_view / np.tan((angle_of_view * np.pi / 180) / 2)) / 2

    print("Distance to plane =", result)

# Plano y resultado en centímetros
calcdist(62.2, 45)              # 45 menos unos 6 cm para el motor y el eje del brazo
calcdist(48.8, 35)