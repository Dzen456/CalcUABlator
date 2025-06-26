#include <AccelStepper.h>
#include <Servo.h>

// Configuración del pin del servomotor
#define SERVO_PIN 6

// Crear un objeto Servo
Servo penServo;

// Configuración de los pines para los motores
#define MOTOR1_PIN_STEP 11
#define MOTOR1_PIN_DIR 12
#define MOTOR2_PIN_STEP 9
#define MOTOR2_PIN_DIR 8

const int width = 50, height = 50; // Ancho y alto del dígito

// Ángulo de rotación (en grados)
const float rotation_angle_degrees = -20.0; // Ajusta este valor según sea necesario
const float rotation_angle_radians = rotation_angle_degrees * PI / 180.0;

// Crear objetos AccelStepper para cada motor
AccelStepper stepper1(AccelStepper::DRIVER, MOTOR1_PIN_STEP, MOTOR1_PIN_DIR);
AccelStepper stepper2(AccelStepper::DRIVER, MOTOR2_PIN_STEP, MOTOR2_PIN_DIR);

bool stopRunning = false;
void setup() {
  Serial.begin(9600);  // Inicializar comunicación serial
  
  // Configurar velocidad máxima y aceleración para cada motor
  stepper1.setMaxSpeed(1000);
  stepper1.setAcceleration(500);
  
  stepper2.setMaxSpeed(1000);
  stepper2.setAcceleration(500);

  // Adjuntar el servomotor al pin especificado
  penServo.attach(SERVO_PIN);

  // Posición inicial (bolígrafo levantado)
  lift_pen(true);
}

void move_to_position_rotated(int x, int y, int centerX, int centerY) {
  int* rotatedCoords = rotate_point(x, y, centerX, centerY);
  int rotatedX = rotatedCoords[0];
  int rotatedY = rotatedCoords[1];

  // Mover los motores a las coordenadas rotadas
  stepper1.moveTo(rotatedX);
  stepper2.moveTo(rotatedY);

  while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) {
    stepper1.run();
    stepper2.run();
  }
}

int* rotate_point(int x, int y, int centerX, int centerY) {
  // Calcular las coordenadas relativas al centro
  int relativeX = x - centerX;
  int relativeY = y - centerY;

  // Aplicar la fórmula de rotación
  float rotatedX = relativeX * cos(rotation_angle_radians) - relativeY * sin(rotation_angle_radians);
  float rotatedY = relativeX * sin(rotation_angle_radians) + relativeY * cos(rotation_angle_radians);

  // Volver a la posición absoluta
  static int rotatedCoords[2];
  rotatedCoords[0] = round(rotatedX + centerX);
  rotatedCoords[1] = round(rotatedY + centerY);
  return rotatedCoords;
}

void write_number(int number) {
  // Levantar el bolígrafo antes de empezar
  lift_pen(true);

  // Obtener la posición actual del brazo
  int currentX = stepper1.currentPosition();
  int currentY = stepper2.currentPosition();

  // Mover al punto inicial relativo a la posición actual

  // Dibujar el número según el valor recibido
  switch (number) {
    case 0:
      draw_zero(currentX, currentY);
      break;
    case 1:
      draw_one(currentX, currentY);
      break;
    case 2:
      draw_two(currentX, currentY);
      break;
    case 3:
      draw_three(currentX, currentY);
      break;
    case 4:
      draw_four(currentX, currentY);
      break;
    case 5:
      draw_five(currentX, currentY);
      break;
    case 6:
      draw_six(currentX, currentY);
      break;
    case 7:
      draw_seven(currentX, currentY);
      break;
    case 8:
      draw_eight(currentX, currentY);
      break;
    case 9:
      draw_nine(currentX, currentY);
      break;
    default:
      Serial.println("Número no válido.");
      return;
  }

  // Levantar el bolígrafo después de terminar
  lift_pen(true);
}

void loop() {
  if (stopRunning == true) {
    return;
  }
  if (Serial.available() > 0) {
    String receivedData = Serial.readStringUntil('\n');  // Read until newline character
    receivedData.trim();  // Remove any extra whitespace or carriage returns

    // Split the string into three parts using the delimiter (comma)
    int firstCommaIndex = receivedData.indexOf(',');
    int secondCommaIndex = receivedData.indexOf(',', firstCommaIndex + 1);

    if (firstCommaIndex != -1 && secondCommaIndex != -1) {  // Ensure delimiters exist
      String value1Str = receivedData.substring(0, firstCommaIndex);
      String value2Str = receivedData.substring(firstCommaIndex + 1, secondCommaIndex);
      String value3Str = receivedData.substring(secondCommaIndex + 1);

      // Convertir a int
      int value1 = value1Str.toInt();
      int value2 = value2Str.toInt();
      int value3 = value3Str.toInt();

      Serial.print("Received Value 1: ");
      Serial.println(value1);
      Serial.print("Received Value 2: ");
      Serial.println(value2);
      Serial.print("Received Value 3: ");
      Serial.println(value3);
      
      stepper1.moveTo(value1 * (200.0 / 360.0) + 40);  // Convierte grados a pasos
      while (stepper1.distanceToGo() != 0) {
        stepper1.run(); 
      }
      delay(1000);  // Esperar 1 segundo

      stepper2.moveTo(value2 * (200.0 / 360.0) - 100);  // Convierte grados a pasos
      while (stepper2.distanceToGo() != 0) {
        stepper2.run();
      }
      delay(1000);

      write_number(value3);
      stopRunning = true;
      return;
      
    }
  }
  /*
  lift_pen(false);
  delay(1000);
  lift_pen(true);
  delay(1000);
  */
}

void draw_zero(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX, startY, startX, startY);                  // Punto inicial
  move_to_position_rotated(startX + width, startY, startX, startY);          // Línea horizontal superior
  move_to_position_rotated(startX + width, startY + height, startX, startY); // Línea vertical derecha
  move_to_position_rotated(startX, startY + height, startX, startY);         // Línea horizontal inferior
  move_to_position_rotated(startX, startY, startX, startY);                  // Línea vertical izquierda
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_one(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX + width / 2, startY, startX, startY);       // Punto inicial
  move_to_position_rotated(startX + width / 2, startY + height, startX, startY); // Línea vertical
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_two(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX, startY, startX, startY);                   // Punto inicial
  move_to_position_rotated(startX + width, startY, startX, startY);           // Línea horizontal superior
  move_to_position_rotated(startX + width, startY + height / 2, startX, startY); // Línea diagonal derecha
  move_to_position_rotated(startX, startY + height / 2, startX, startY);      // Línea horizontal central
  move_to_position_rotated(startX, startY + height, startX, startY);          // Línea vertical izquierda
  move_to_position_rotated(startX + width, startY + height, startX, startY);  // Línea horizontal inferior
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_three(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX, startY, startX, startY);                   // Punto inicial
  move_to_position_rotated(startX + width, startY, startX, startY);           // Línea horizontal superior
  move_to_position_rotated(startX + width, startY + height / 2, startX, startY); // Línea vertical derecha
  move_to_position_rotated(startX, startY + height / 2, startX, startY);      // Línea horizontal central
  move_to_position_rotated(startX + width, startY + height / 2, startX, startY); // Línea vertical derecha
  move_to_position_rotated(startX + width, startY + height, startX, startY);  // Línea horizontal inferior
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_four(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX, startY, startX, startY);                   // Punto inicial
  move_to_position_rotated(startX, startY + height / 2, startX, startY);      // Línea vertical izquierda
  move_to_position_rotated(startX + width, startY + height / 2, startX, startY); // Línea horizontal central
  move_to_position_rotated(startX + width, startY, startX, startY);           // Línea vertical derecha
  move_to_position_rotated(startX + width, startY + height, startX, startY);  // Línea vertical derecha
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_five(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX + width, startY, startX, startY);           // Punto inicial
  move_to_position_rotated(startX, startY, startX, startY);                   // Línea horizontal superior
  move_to_position_rotated(startX, startY + height / 2, startX, startY);      // Línea vertical izquierda
  move_to_position_rotated(startX + width, startY + height / 2, startX, startY); // Línea horizontal central
  move_to_position_rotated(startX + width, startY + height, startX, startY);  // Línea vertical derecha
  move_to_position_rotated(startX, startY + height, startX, startY);          // Línea horizontal inferior
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_six(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX + width, startY, startX, startY);           // Punto inicial
  move_to_position_rotated(startX, startY, startX, startY);                   // Línea horizontal superior
  move_to_position_rotated(startX, startY + height, startX, startY);          // Línea vertical izquierda
  move_to_position_rotated(startX + width, startY + height, startX, startY);  // Línea horizontal inferior
  move_to_position_rotated(startX + width, startY + height / 2, startX, startY); // Línea vertical derecha
  move_to_position_rotated(startX, startY + height / 2, startX, startY);      // Línea horizontal central
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_seven(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX, startY, startX, startY);                   // Punto inicial
  move_to_position_rotated(startX + width, startY, startX, startY);           // Línea horizontal superior
  move_to_position_rotated(startX + width / 2, startY + height, startX, startY); // Línea diagonal
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_eight(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX, startY, startX, startY);                   // Punto inicial
  move_to_position_rotated(startX + width, startY, startX, startY);           // Línea horizontal superior
  move_to_position_rotated(startX + width, startY + height, startX, startY);  // Línea vertical derecha
  move_to_position_rotated(startX, startY + height, startX, startY);          // Línea horizontal inferior
  move_to_position_rotated(startX, startY, startX, startY);                   // Línea vertical izquierda
  move_to_position_rotated(startX + width, startY + height / 2, startX, startY); // Línea horizontal central
  lift_pen(true);  // Levantar el bolígrafo
}

void draw_nine(int startX, int startY) {
  lift_pen(false);  // Bajar el bolígrafo
  move_to_position_rotated(startX + width, startY + height / 2, startX, startY); // Punto inicial
  move_to_position_rotated(startX, startY + height / 2, startX, startY);      // Línea horizontal central
  move_to_position_rotated(startX, startY, startX, startY);                   // Línea vertical izquierda
  move_to_position_rotated(startX + width, startY, startX, startY);           // Línea horizontal superior
  move_to_position_rotated(startX + width, startY + height, startX, startY);  // Línea vertical derecha
  lift_pen(true);  // Levantar el bolígrafo
}


void lift_pen(bool lift) {
  if (lift) {
    penServo.write(40);  // Ángulo para levantar el bolígrafo
    Serial.println("Bolígrafo levantado.");
  } else {
    penServo.write(-10);   // Ángulo para bajar el bolígrafo
    Serial.println("Bolígrafo bajado.");
  }
}