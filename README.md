# SmartGate-with-Esp32

---
[Watch the Demo Video](https://drive.google.com/file/d/1Hyte0X9I13qH5gZYl592uKODJuCxJqe7/view?usp=drivesdk)
---

Automatic Gate System using ESP32

Overview

This project is an automatic gate system built using an ESP32 microcontroller, an HC-SR04 ultrasonic sensor, an IR obstacle sensor, a servo motor, and a 16x2 LCD display with an I²C interface.

The system detects approaching objects, automatically opens the gate, displays system information on the LCD, and closes the gate after a short delay.

This project was developed as one of my first hands-on embedded systems projects and provided practical experience with sensors, actuators, displays, voltage dividers, and microcontroller programming.

---

Features

- Automatic object detection
- Servo-controlled gate operation
- Distance measurement using HC-SR04
- LCD status display using I²C communication
- Safe voltage-level interfacing using a voltage divider
- Real-time system feedback

---

Components Used

- ESP32 NodeMCU (38-pin)
- HC-SR04 Ultrasonic Sensor
- Flying Fish IR Obstacle Sensor
- SG90 Servo Motor
- 16x2 LCD Display
- I²C LCD Module
- Breadboard
- Jumper Wires
- Resistors for Voltage Divider

---

Circuit Design

HC-SR04 Voltage Divider

The HC-SR04 Echo pin outputs a 5V signal, while the ESP32 operates at 3.3V logic levels.

To protect the ESP32 GPIO pin, a voltage divider was used to reduce the Echo signal to a safe voltage before connecting it to the microcontroller.

This project provided practical experience with voltage-level compatibility between electronic components.

I²C LCD Interface

The 16x2 LCD was connected through an I²C module, reducing the number of GPIO pins required and simplifying wiring.

The LCD displays system status messages and provides real-time feedback to the user.

---

How the System Works

1. The HC-SR04 continuously measures the distance to nearby objects.
2. When an object enters the configured detection range, the ESP32 processes the sensor data.
3. The LCD displays a detection message.
4. The servo motor rotates to open the gate.
5. After a short delay, the gate automatically closes.
6. The LCD updates the system status accordingly.
7. The IR sensor can be used as an additional detection and validation sensor.

---

Challenges Faced

1. Continuous Sensor Triggering

During initial testing, the gate repeatedly opened and closed without any object being present.

Cause

The sensitivity of the Flying Fish IR sensor was set too high.

Solution

The onboard potentiometer was adjusted until the sensor responded reliably and only detected actual objects.

---

2. Logic-Level Compatibility

The HC-SR04 Echo pin outputs 5V logic while the ESP32 is designed for 3.3V inputs.

Solution

A voltage divider circuit was added to safely reduce the Echo signal voltage before connecting it to the ESP32.

---

3. Multi-Component Integration

The project required multiple components to work together:

- Ultrasonic Sensor
- IR Sensor
- Servo Motor
- LCD Display
- ESP32

Successfully integrating all devices provided valuable experience in hardware interfacing and system design.

---

What I Learned

Through this project, I gained practical experience with:

- ESP32 programming
- Embedded systems development
- Ultrasonic distance sensing
- IR object detection
- Servo motor control
- LCD interfacing using I²C
- Voltage divider design
- Breadboard prototyping
- Sensor calibration
- Hardware troubleshooting
- System integration

---

Current Status

✅ Working Successfully

The system detects approaching objects, displays information on the LCD, automatically opens the gate, and closes it after a delay.

---

Future Improvements

- Build a realistic gate structure using cardboard or other materials.
- Add entry and exit detection logic.
- Improve LCD user interface.
- Add wireless monitoring using Wi-Fi.
- Create a custom PCB version.
- Add battery backup functionality.

---

Project Media

This repository contains:

- Source code
- Circuit photographs
- Demonstration videos
- Project documentation

---

Author

Engineering student exploring embedded systems, electronics, programming, and automation through hands-on projects.

---
