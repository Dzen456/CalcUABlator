from text_recognition import *
from move_robot import *
from connect_arduino import *

#Text Recognition
preprocess_image("test2.jpg", "processed_image.jpg")
expression, start_coordinates=extract_text("processed_image.jpg")
print("Expressio identificada: ", expression)
print("Coordenades imatge: ", start_coordinates)
filtered_expression=filter_expression(expression)
print("Expressio filtrada: ", filtered_expression)
answer=resolve_math_expression(filtered_expression)
print("Solucio calculada: "answer)

#Robot Movement Calculations
x_robot, y_robot = transform_coordinates(start_coordinates[0])
print("Coordenades robot: ", x_robot, y_robot)
q = calculate_angles(x_robot, y_robot)
print("Angles calculats: ", q)

send_result_to_arduino(q[0], q[1], answer)
