
# Reference: https://raspberrypi-guide.github.io/electronics/camera-positioning

import numpy as np

def calcdist(angle_of_view, plane_of_view):
    result = (plane_of_view / np.tan((angle_of_view * np.pi / 180) / 2)) / 2

    print("Distance to plane =", result)

# Plane and result in centimeters (cm)
calcdist(62.2, 45)              # 45 minus about 6 cm for the motor and arm shaft
calcdist(48.8, 35)