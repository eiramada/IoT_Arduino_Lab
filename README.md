# Arduino Sketches for Microcontroller and IoT Experiments

## Overview

This repository contains various Arduino sketches created for experimenting with microcontrollers and IoT applications as part of my microdegree program at Tallinn University (TLU). These sketches are designed to work with the LOLIN(WEMOS) D1 R2 & mini board and utilize various components and sensors to demonstrate different functionalities.

## Contents

### 1. Blink
A basic sketch that blinks the built-in LED on the LOLIN(WEMOS) D1 R2 & mini board. This is a great starting point for beginners to understand how to control digital outputs.

**NB!** Wemos mini's built-in LED operates inversely to the commands. For more information, read [this discussion](https://forum.arduino.cc/t/wemos-d1-r1-built-in-led-problem/626168/3).

### 2. DiscoLED
A fun sketch that controls an LED to create a disco light effect. It demonstrates the use of loops and delays to create patterns with LEDs.

### 3. Display
This sketch interfaces with a display module to show text or graphics. It's useful for learning how to send data to a display and refresh its content.

- **Required Libraries**: 
  - `Adafruit GFX Library`
  - `Adafruit SSD1306`
  - `OneWire`

### 4. DisplayBitmap_Face
An advanced version of the display sketch that shows how to render bitmap images on a display. This example includes displaying a face graphic, teaching how to handle image data.

### 5. PIRSensor
This sketch reads data from a Passive Infrared (PIR) sensor to detect motion. It's ideal for creating simple motion-sensing projects.

### 6. RelaySwitch
A sketch that demonstrates how to control a relay switch using the microcontroller. This is useful for understanding how to interact with higher voltage circuits safely.

### 7. Sensor
A general sketch for interfacing with various sensors, such as temperature and humidity sensors. This sketch provides a template for reading sensor data and processing it for different applications.

- **Required Libraries**: 
  - `DHT sensor library`

### 8. SerialBlinkExample
A variation of the Blink sketch that adds serial communication. It allows you to control the blinking of the LED via commands sent over the serial port, illustrating basic serial communication.

### 9. DualLightSwitchClimateMonitor
A cloud-connected project that monitors temperature and humidity while enabling remote control of two light switches through the Arduino IoT Cloud. Features a configurable dashboard with real-time data updates and switch controls.

### 10. wemos_mini_MQTT
A pair of MQTT-based sketches for setting up communication between two Wemos D1 Mini ESP8266 boards.

wemos_mini_MQTT_publisher: Publishes temperature data from a DHT sensor and controls two relays, allowing remote relay control and data updates.
wemos_mini_MQTT_receiver: Displays the received temperature and relay states on an OLED screen, synchronizing with the publisher to mirror relay states.

## Getting Started

### Requirements
- LOLIN(WEMOS) D1 R2 & mini board
- Arduino IDE installed on your computer
- Basic understanding of Arduino programming and electronics

### Installation

1. Download the Arduino IDE from the [official website](https://www.arduino.cc/en/software).
2. Install the necessary libraries for each sketch. This can be done through the Arduino Library Manager in the Arduino IDE:
   - Go to **Sketch** > **Include Library** > **Manage Libraries...**
   - Search for the required library and click "Install".
3. Connect your LOLIN(WEMOS) D1 R2 & mini board to your computer via USB and select the correct board and port in the Arduino IDE (`BOARD: LOLIN(WEMOS) D1 R2 & mini`, `PORT: COM3`).
4. To add the LOLIN(WEMOS) D1 R2 & mini board to the Arduino IDE:
   - Open the **Arduino IDE**.
   - Go to **File** > **Preferences**.
   - In the "Additional Board Manager URLs" field, add `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
   - Go to **Tools** > **Board** > **Boards Manager...**.
   - Search for "ESP8266" and install the "ESP8266 by ESP8266 Community".
5. If you need a USB driver for your board, follow the instructions provided in this [Getting Started Guide](https://www.instructables.com/Wemos-ESP8266-Getting-Started-Guide-Wemos-101/).

### Running the Sketches

1. Open a sketch file in the Arduino IDE.
2. Compile and upload the sketch to your board.
3. Follow the specific instructions or setup for each sketch, which are detailed in the comments within the code.

## Course Information

These sketches are part of the course **HKC0239 - Mikrokontrollerid ja asjade internet IoT** offered from August 26, 2024, to September 14, 2024. More information about the course can be found [here](https://ois.tlu.ee/pls/portal/!tois.ois_public.draw_page?_page=26C55172C85FAFF3D6EB1F8D2FED4A6307BA759863366D72&p_id=C878A7E61823B732).
