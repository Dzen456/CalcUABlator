from sympy.physics.mechanics import dynamicsymbols
from sympy import *
import numpy as np

PIXELS_PAPERX=780
PIXELS_PAPERY=1135

CM_PAPERX=21
CM_PAPERY=29.7
scale_factor_x= PIXELS_PAPERX/CM_PAPERX
scale_factor_y = PIXELS_PAPERY/CM_PAPERY

theta1, theta2 = dynamicsymbols('theta1 theta2')

def transform_coordinates(image_coordinates):
	y_robot = image_coordinates[0] / scale_factor_x #- 19
	x_robot = image_coordinates[1] /scale_factor_y #+ 28
	return x_robot, y_robot
	
def calculate_angles(x, y):
	L1=20
	L2=20
	eq1 = (L1 * cos(theta1) + L2 * cos(theta1 + theta2)) - x
	eq2 = (L1 * sin(theta1) + L2 * sin(theta1 + theta2)) - y

	try:
		q = nsolve((eq1, eq2), (theta1, theta2), (1,1), prec=5)
	  
	except Exception as e:
		print("Error:", str(e))
		q = [0, 0, 0, 0]

	q[0] = q[0] - round(q[0] / (np.pi * 2)) * 2 * np.pi
	q[1] = q[1] - round(q[1] / (np.pi * 2)) * 2 * np.pi

	q[0] = round(q[0] * 180 / np.pi,2)
	q[1] = round(q[1] * 180 / np.pi,2)

	return q
