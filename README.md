# SmartGate-with-Esp32
Automatic Gate Using ESP32, HC-SR04 and IR Sensor

Overview

This project is an automatic gate system built using an ESP32, an HC-SR04 ultrasonic sensor, an IR obstacle sensor, and a servo motor.

The system detects approaching objects and automatically opens the gate. After a short delay, the gate closes again.

This project was built as one of my first hands-on ESP32 projects and served as an introduction to sensors, actuators, voltage dividers, and embedded programming.

---

Components Used

- ESP32 NodeMCU (38-pin)
- HC-SR04 Ultrasonic Sensor
- Flying Fish IR Obstacle Sensor
- Servo Motor
- Breadboard
- Jumper Wires
- Resistors for Voltage Divider
- Power Supply

---

Circuit Design Notes

The HC-SR04 Echo pin outputs a 5V signal, while ESP32 GPIO pins are designed for 3.3V logic.

To safely connect the Echo pin to the ESP32, a voltage divider was implemented using resistors to reduce the voltage to a safe level before it reached the microcontroller.

This project provided practical experience with signal-level compatibility between electronic components.

---

How It Works

1. The HC-SR04 measures the distance to nearby objects.
2. When an object enters the configured detection range, the ESP32 processes the sensor data.
3. The servo motor rotates to open the gate.
4. After a short delay, the servo returns to its original position, closing the gate.
5. The IR sensor can be used as an additional detection or validation sensor.

---

Challenges Faced

1. Sensor Sensitivity Issues

Initially, the IR sensor was triggering continuously, causing the gate to repeatedly open and close.

Solution

The onboard potentiometer of the Flying Fish sensor was adjusted until stable operation was achieved.

---

2. Safe Sensor Interfacing

The HC-SR04 uses 5V logic on the Echo pin, while the ESP32 operates at 3.3V logic levels.

Solution

A voltage divider circuit was added to safely reduce the Echo signal voltage before connecting it to the ESP32.

---

What I Learned

- ESP32 programming
- Ultrasonic distance measurement
- Servo motor control
- Breadboard prototyping
- Sensor calibration
- Voltage divider design
- 5V to 3.3V logic-level interfacing
- Hardware troubleshooting and debugging

---

Current Status

✅ Working Successfully

The system detects objects and automatically opens and closes the gate as intended.

---

Future Improvements

- Build a realistic gate structure using cardboard or other materials.
- Add a 16x2 LCD display to show system status.
- Improve cable management and presentation.
- Add more advanced gate control logic.

---

Project Media

This repository contains source code, photographs, and demonstration videos of the project.

---

Author

Engineering student exploring embedded systems, electronics, sensors, and programming through practical projects.
