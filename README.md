SMART WEARABLE ARDUINO-BASED STRESS MONITORING SYSTEM
Overview

The Smart Wearable Arduino-Based Stress Monitoring System is an IoT-based health monitoring project designed to detect a user's stress level by measuring physiological parameters in real time. The system uses an Arduino UNO, ESP8266 (ESP-01), and biometric sensors to collect data, process it, and display the results.

The project aims to provide a simple, affordable, and portable solution for continuous stress monitoring, making it useful for students, professionals, and healthcare applications.

Features
Real-time stress monitoring
Heart rate monitoring
Body temperature monitoring
Galvanic Skin Response (GSR) measurement
OLED display for live readings
Wi-Fi connectivity using ESP8266
Portable wearable design
Low-cost IoT implementation
Hardware Components
Component	Description
Arduino UNO	Main microcontroller
ESP8266 (ESP-01)	Wi-Fi module for IoT connectivity
Pulse Sensor	Measures heart rate (BPM)
GSR Sensor	Measures skin conductivity for stress detection
Temperature Sensor (LM35/DS18B20)	Measures body temperature
OLED Display (0.96" I2C)	Displays sensor readings
Breadboard & Jumper Wires	Circuit connections
Power Supply	USB/Power Bank
Software Requirements
Arduino IDE
Embedded C/C++
ESP8266 AT Firmware
Serial Monitor
Required Arduino Libraries:
Wire.h
Adafruit_GFX
Adafruit_SSD1306
ESP8266WiFi (if applicable)
Working Principle
The wearable device continuously collects physiological data.
The pulse sensor measures heart rate.
The GSR sensor detects changes in skin conductivity caused by sweating.
The temperature sensor records body temperature.
Arduino processes the collected sensor values.
Based on predefined threshold values, the system estimates the user's stress level.
The measured data is displayed on the OLED screen.
Through the ESP8266 module, the data can be transmitted to an IoT platform for remote monitoring.
System Architecture
           +------------------+
           | Pulse Sensor     |
           +------------------+
                    |
           +------------------+
           | GSR Sensor       |
           +------------------+
                    |
           +------------------+
           | Temperature      |
           | Sensor           |
           +------------------+
                    |
              Arduino UNO
                    |
        -----------------------
        |                     |
    OLED Display         ESP8266 Wi-Fi
        |                     |
   Live Readings        Cloud / IoT Dashboard
Folder Structure
Smart-Wearable-Stress-Monitoring/
│
├── Arduino_Code/
│   ├── stress_monitor.ino
│
├── Circuit_Diagram/
│   ├── circuit.png
│
├── Images/
│   ├── prototype.jpg
│   ├── working.jpg
│
├── Documentation/
│   ├── Project_Report.pdf
│
├── README.md
│
└── LICENSE
Installation
1. Clone the Repository
git clone https://github.com/yourusername/Smart-Wearable-Stress-Monitoring.git
2. Open Arduino IDE

Open the stress_monitor.ino file.

3. Install Required Libraries

Install:

Adafruit SSD1306
Adafruit GFX
Wire Library
4. Connect Hardware

Connect all sensors according to the circuit diagram.

5. Upload the Code

Select:

Board: Arduino UNO
Port: COM Port

Click Upload.

Sample Output
Heart Rate : 78 BPM

Temperature : 36.8 °C

GSR Value : 540

Stress Level : Moderate
Applications
Personal health monitoring
Workplace stress monitoring
Student wellness monitoring
Fitness and wellness tracking
Healthcare research
IoT-based remote patient monitoring
Future Enhancements
Machine Learning-based stress prediction
Mobile application integration
Cloud database for long-term health records
AI-powered health recommendations
GPS-based emergency alerts
Battery optimization for longer wearable usage
Technologies Used
Arduino UNO
ESP8266 (ESP-01)
IoT
Embedded C/C++
Arduino IDE
Sensor Integration
Wearable Technology
Project Highlights
Real-time physiological monitoring
Portable wearable design
Low-cost hardware implementation
IoT-enabled remote monitoring
User-friendly OLED interface
