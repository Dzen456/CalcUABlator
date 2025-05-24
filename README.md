# CalcUABlator

A robot capable of doing mathematical operations using Computer Vision.

This document contains instructions of the robot's functionality and usage, and the requeriments necessary for this code to work.

### About

CalcUABlator has the following directories:

Fritzing_CalcUABlator: This folder contains the blueprints for the fritzing of the robot, required for his correct construction. The diagram must be followed; otherwise, the robot likely won't work.

CoppeliaSim_CalcUABlator: This folder contains the CoppeliaSim of the robot, where you can simulate his behaviour and usage.

Software_CalcUABlator: This folder contains the function diagram of the robot, with all the variables and functions that the robot manages in the Raspberry Pi and Arduino modules.

Old version - 3D Model and ideas: This folder contains an old, unused version of the robot for researching purposes, with the dimensions, list of components, and a code for the camera. 

### Instalation

##### Hardware

Making this robot requieres all of the following components, or at least similar to:

-Arduino UNO Rev. 3
-Raspberry Pi 3 B+
-Source Power Supply Raspberry Pi 3 - 5V/2.5A
-Camera Raspberry Pi v2 - 8 Megapixels
-Motor NEMA 17 / 3.5Kg with conector and cable (two units)
-Motor Drivers step to step 3.5A (TB6600) (two units)
-Standar servo S3003, 360 Degrees
-ATX COOLBOX 500W

Also, it is required to have the following additional parts:

Arms Support: (estimated parameters: length - 18 cm / width - 5 cm / thickness - 0.25 cm)
Big Metal Axis: (estimated parameters: diameter - 2 cm / height - 12 cm)
Big Axis Wheel: (estimated parameters: wheel diameter - 3 cm / hole wheel diameter - 2 cm)
Small Metal Axis: (estimated parameters: diameter - 2 cm / height - 5 cm)
Smal Wheel Axis: (estimated parameters: wheel diameter - 3 cm / hole wheel diameter - 2 cm)
Screws: 20 screws of 1 cm, 4 screws of 3 cm
Pen Support Piece: (estimated parameters: length - 5 cm / width - 1 cm / square zone hole - 1x1 cm)
Wood Platform: (estimated parameters: length - 42 cm / width - 32 cm / thickness - 1 cm)
Raspberry Structure Support: (estimated parameters: length - 8 cm / width - 8 cm / height - 30 cm)
Raspberry Structure Superior Support: (estimated parameters: length - 30 cm / width - 8 cm / thickness - 2 cm)
2-4 brackets
Rubber Strap
Also some extra pieces between the arms and the axis supports.

##### Software

If you just want to run the simulation, only CoppeliaSim software + Jupiter Notebook is required to make it work. 

For the Arduino UNO Rev. 3, you will need Arduino IDE.

### Usage

For the simulation, you just have to open and run the CoppeliaSim_CalcUABlator.ttt file on the CoppeliaSim and then execute the CoppeliaSim_CalcUABlator_script.ipynb notebook to activate the demo of the robot. It is posible to change the test texture in the folder test_texture to test the robot capacities.

To run the robot's Arduino UNO Rev. 3, you'll have to connect the device to the arduino with a cable to be able to run the code correctly. You'll also need to build the robot using the components described above and the blueprints for the circuits and structure.

### Bibliography

https://raspberrypi-guide.github.io/electronics/camera-positioning
