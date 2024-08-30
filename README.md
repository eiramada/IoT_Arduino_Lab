# Arduino Sketches for Microcontroller and IoT Experiments

## Overview

This repository contains various Arduino sketches created for experimenting with microcontrollers and IoT applications as part of my microdegree program at Tallinn University (TLU). These sketches are designed to work with the LOLIN(WEMOS) D1 R2 & mini board and utilize various components and sensors to demonstrate different functionalities.

## Contents

### 1. Blink
A basic sketch that blinks the built-in LED on the LOLIN(WEMOS) D1 R2 & mini board. This is a great starting point for beginners to understand how to control digital outputs.

### 2. DiscoLED
A fun sketch that controls an LED to create a disco light effect. It demonstrates the use of loops and delays to create patterns with LEDs.

### 3. Display
This sketch interfaces with a display module to show text or graphics. It's useful for learning how to send data to a display and refresh its content.

### 4. DisplayBitmap_Face
An advanced version of the display sketch that shows how to render bitmap images on a display. This example includes displaying a face graphic, teaching how to handle image data.

### 5. PIRSensor
This sketch reads data from a Passive Infrared (PIR) sensor to detect motion. It's ideal for creating simple motion-sensing projects.

### 6. RelaySwitch
A sketch that demonstrates how to control a relay switch using the microcontroller. This is useful for understanding how to interact with higher voltage circuits safely.

### 7. Sensor
A general sketch for interfacing with various sensors, example for temerature and humidity. This sketch provides a template for reading sensor data and processing it for different applications.

### 8. SerialBlinkExample
A variation of the Blink sketch that adds serial communication. It allows you to control the blinking of the LED via commands sent over the serial port, illustrating basic serial communication.

## Getting Started

### Requirements
- LOLIN(WEMOS) D1 R2 & mini board
- Arduino IDE installed on your computer
- Basic understanding of Arduino programming and electronics

### Installation
1. Download the Arduino IDE from the [official website](https://www.arduino.cc/en/software).
2. Install the necessary libraries for each sketch (if any are required).
3. Connect your LOLIN(WEMOS) D1 R2 & mini board to your computer via USB and select the correct board and port in the Arduino IDE (`BOARD: LOLIN(WEMOS) D1 R2 & mini`, `PORT: COM3`).

### Running the Sketches
1. Open a sketch file in the Arduino IDE.
2. Compile and upload the sketch to your board.
3. Follow the specific instructions or setup for each sketch, which are detailed in the comments within the code.
