<a href=https://github.com/Dzen456/CalcUABlator>
<img src=https://github.com/user-attachments/assets/39da234b-853f-4b1a-8f35-447f2a2f937c />
</a>

<br>
<p style="text-align:center;">
A robot capable of doing mathematical operations using Computer Vision.

This document contains instructions of the robot's functionality and usage, and the requirements necessary for this code to work.
</p>
</br>

## Table of contents:

- [Directories](#Directories)
- [Installation](#Installation)
  - [Hardware](#Hardware)
      - [Fritzing](#Fritzing)
  - [Software](#Software)
- [Usage](#Usage)
- [Bibliography](#Bibliography)

## Directories:

CalcUABlator has the following directories:

- CoppeliaSim_CalcUABlator: This folder contains the CoppeliaSim of the robot, where you can simulate his behaviour and usage.
```cmd
CoppeliaSim_CalcUABlator/
├── test_texture/
│   └── test_texture.jpg
├── CoppeliaSim_CalcUABlator.ttt
├── CoppeliaSim_CalcUABlator_script.ipynb
├── remoteApi.dll
├── sim.py
└── simConst.py
```
- Fritzing_CalcUABlator: This folder contains the blueprints for the fritzing of the robot, required for his correct construction. The diagram must be followed; otherwise, the robot likely won't work.
```cmd
Fritzing_CalcUABlator/
├── calcUABlator-fritzing.fzz
├── calcUABlator-fritzing_bb.png
└── references.txt
```
- Old version - 3D Model and ideas: This folder contains an old, unused version of the robot for researching purposes, with the dimensions, list of components, and a code for the camera.
```cmd
Old version - 3D Model and ideas/
├── OLD_calcUABlator/
│   ├── background_test/
│   │   └── christmas_photo_studio_07_4k.exr
│   ├── Pen Holder/
│   │   │── Comment.txt
│   │   │── part1.png
│   │   │── part2.png
│   │   │── part3.png
│   │   │── part4.png
│   │   └── RLP_PenHolder.blend
│   ├── List of components (No Hardware) - 22-04-2025.pdf
│   ├── RLP_Robot_sketch2.blend
├── Measurement_Confirmation_Script.py
├── Raspberry_Structure_Measurements_Trigonometry (Comments in Spanish).pdf
└── Raspberry_Structure_Measurements.txt
```
- Software_CalcUABlator: This folder contains the function diagram of the robot, with all the variables and functions that the robot manages in the Raspberry Pi and Arduino modules. 
```cmd
Software_CalcUABlator/
└── SoftwareSchema.pdf
```

## Demo:

## Installation:

### Hardware

Making this robot requieres all of the following **hardware components**, or at least similar to:

| <a href=https://tienda.bricogeek.com/arduino-original/1845-arduino-uno-r4-wifi.html> Arduino UNO 4 WiFi </a>    | <a href=https://tienda.bricogeek.com/placas-raspberry-pi/1330-raspberry-pi-4-model-b-4-gb.html > Raspberry Pi 4 </a> |
| :------: | :------: |
| <a href=https://tienda.bricogeek.com/arduino-original/1845-arduino-uno-r4-wifi.html>![image](https://github.com/user-attachments/assets/319f562a-b377-4e2e-a5cc-2fa9d9563da1)</a> | <a href=https://tienda.bricogeek.com/placas-raspberry-pi/1330-raspberry-pi-4-model-b-4-gb.html >![image](https://github.com/user-attachments/assets/6b71e162-adc5-4c3e-9c91-6789f88d16bf)</a> |
| <a href=https://tienda.bricogeek.com/accesorios-raspberry-pi/822-camara-raspberry-pi-v2-8-megapixels.html> Raspberry Pi v2 Cam </a>    | <a href=https://tienda.bricogeek.com/fuentes-de-alimentacion/775-fuente-de-alimentacion-atx-coolbox-500w.html> Power Supply ATX 500W </a> |
| <a href=https://tienda.bricogeek.com/accesorios-raspberry-pi/822-camara-raspberry-pi-v2-8-megapixels.html>![image](https://github.com/user-attachments/assets/8f06ff10-a0f2-48ff-a093-9a3f29bd7f4a)</a> | <a href=https://tienda.bricogeek.com/fuentes-de-alimentacion/775-fuente-de-alimentacion-atx-coolbox-500w.html>![image](https://github.com/user-attachments/assets/61f52a2c-7b2e-433c-8eb5-70d17877f88c)</a> |
| <a href=https://tienda.bricogeek.com/motores-paso-a-paso/1360-motor-nema-17-35kg-con-conector-y-cable.html> Nema 17 stepper </a>    | <a href=https://tienda.bricogeek.com/controladores-motores/553-pololu-a4988-stepstick-prusa-reprap.html> Stepper Driver Pololu A4988 </a> |
| <a href=https://tienda.bricogeek.com/motores-paso-a-paso/1360-motor-nema-17-35kg-con-conector-y-cable.html>![image](https://github.com/user-attachments/assets/0a8c4144-cc1a-46a2-aa83-261d581e2d59)</a> | <a href=https://tienda.bricogeek.com/controladores-motores/553-pololu-a4988-stepstick-prusa-reprap.html>![image](https://github.com/user-attachments/assets/8382df22-a86d-49c8-97a7-4ca345caf88a)</a> |
| <a href=https://tienda.bricogeek.com/motores/118-servomotor-de-rotacion-continua-s3003-360-grados.html> Servo S3003 </a>    |  |
| <a href=https://tienda.bricogeek.com/motores/118-servomotor-de-rotacion-continua-s3003-360-grados.html>![image](https://github.com/user-attachments/assets/0f8dbdca-aa6d-44b3-a966-ff340985b0fa)</a> |  |

<!-- Source Power Supply for Raspberry Pi 4 - 5V/2.5A -->


#### Fritzing:
<img width="650px" style="padding-right:10px;" src="Hardware_CalcUABlator/Fritzing_CalcUABlator/calcUABlator-fritzing_bb.png" />

Also, it is required to have the following **additional pieces**:

- Arms Support: (estimated parameters: length - 18 cm / width - 5 cm / thickness - 0.25 cm)
- Big Metal Axis: (estimated parameters: diameter - 2 cm / height - 12 cm)
- Big Axis Wheel: (estimated parameters: wheel diameter - 3 cm / hole wheel diameter - 2 cm)
- Small Metal Axis: (estimated parameters: diameter - 2 cm / height - 5 cm)
- Smal Wheel Axis: (estimated parameters: wheel diameter - 3 cm / hole wheel diameter - 2 cm)
- Screws: 20 screws of 1 cm, 4 screws of 3 cm
- Pen Support Piece: (estimated parameters: length - 5 cm / width - 1 cm / square zone hole - 1x1 cm)
- Wood Platform: (estimated parameters: length - 42 cm / width - 32 cm / thickness - 1 cm)
- Raspberry Structure Support: (estimated parameters: length - 8 cm / width - 8 cm / height - 30 cm)
- Raspberry Structure Superior Support: (estimated parameters: length - 30 cm / width - 8 cm / thickness - 2 cm)
- 2-4 brackets
- Rubber Strap
- Also some extra pieces between the arms and the axis supports.

### Software

![image](https://github.com/user-attachments/assets/86c001aa-c612-41e7-9019-738179391035)

### Specs:

IDEs:
- Python (Pycharm, VS Code, Spyder,...)
- Jupyter Notebook 7+ (From the website or Anaconda)
- Arduino IDE (Web or desktop version)

Other software:
- Coppelia 4.7
- Blender 4.1
- Python 3.11?

### Requirements:
```shell
numpy
opencv-python
matplotlib
easyocr
sympy
```

If you just want to run the simulation, only CoppeliaSim software + Jupiter Notebook is required to make it work. 

For the Arduino UNO Rev. 3, you will need Arduino IDE.

## Simulation:

For the simulation, you just have to open and run the CoppeliaSim_CalcUABlator.ttt file on the CoppeliaSim and then execute the CoppeliaSim_CalcUABlator_script.ipynb notebook to activate the demo of the robot. It is possible to change the test texture in the folder test_texture to test the robot capacities.


<img src="CoppeliaSim_CalcUABlator/CoppeliaSim.gif" width="500">

## How to Use:

To run the robot's Arduino UNO Rev. 3, you'll have to connect the device to the arduino with a cable to be able to run the code correctly. You'll also need to build the robot using the components described above and the blueprints for the circuits and structure.

## Authors:

- Yanhao Lin
- Isaac Sánchez Amat
- Jofre Segura Montagut
- Raúl Velázquez Gómez
- David Zheng

## Bibliography:

- https://raspberrypi-guide.github.io/electronics/camera-positioning
- https://docs.arduino.cc/tutorials/uno-rev3/getting-started/
- https://www.youtube.com/watch?v=wcLeXXATCR4
- https://www.wexterhome.com/curso-arduino/sentencia-if-else
- Robótica, Llenguatge i Programació class notes.
