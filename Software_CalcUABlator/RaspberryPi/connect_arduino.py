import serial

def send_result_to_arduino(value1, value2, port='/dev/ttyACM0', baud_rate=9600):
    data = f"{value1},{value2}"
    with serial.Serial(port, baud_rate, timeout=1) as ser:
        ser.write(data.encode())
        print(f"Sent to Arduino: {data}")