from text_recognition import *
from move_robot import *
from connect_arduino import *

#Text Recognition
preprocess_image("test2.jpg", "processed_image.jpg")
expression, start_coordinates=extract_text("processed_image.jpg")
print(expression)
print(start_coordinates)
filtered_expression=filter_expression(expression)
print(filtered_expression)
answer=resolve_math_expression(filtered_expression)
print(answer)

#Robot Movement Calculations
x_robot, y_robot = transform_coordinates(start_coordinates[0])
print(x_robot, y_robot)
q = calculate_angles(x_robot, y_robot)
print(q)

send_result_to_arduino(q[0], q[1], answer)
