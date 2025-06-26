import serial

def send_result_to_arduino(motor1, motor2, result, port='/dev/ttyACM0', baud_rate=9600):
    data = f"{motor1},{motor2},{result}\ "
    with serial.Serial(port, baud_rate, timeout=1) as ser:
        ser.write(data.encode())
        print(f"Sent to Arduino: {data}")
