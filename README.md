# Smart SOS Emergency Alert System Using ESP32, GSM and GPS

A real-time emergency alert and location tracking system developed using ESP32, SIM800L GSM module, GY-GPS6MV2 GPS module, and I2C LCD display. The system is designed to send emergency SMS alerts with live GPS coordinates to predefined emergency contacts when panic buttons are pressed.

---

# 📌 Features

* Dual Panic Button Emergency System
* Real-Time GPS Location Tracking
* SMS Alert Sending using GSM
* Google Maps Location Link
* Emergency Group-Based Alerting
* I2C LCD Status Display
* Serial Monitor Debugging
* Default Backup Location if GPS Fails
* ESP32 Based Wireless Embedded System

---

# 🛠️ Components Used

| Component             | Quantity |
| --------------------- | -------- |
| ESP32 Dev Board       | 1        |
| SIM800L GSM Module    | 1        |
| GY-GPS6MV2 GPS Module | 1        |
| 16x2 I2C LCD Display  | 1        |
| Push Buttons          | 2        |
| Jumper Wires          | Required |
| Power Supply          | 4V–5V    |
| Breadboard            | 1        |

---

# ⚙️ System Working

## Button 1

When Button 1 is pressed:

* SMS alert is sent to:

  * Police
  * Forest Ranger
  * Hospital
  * Ambulance

## Button 2

When Button 2 is pressed:

* SMS alert is sent to:

  * Forest Ranger
  * Hospital
  * Ambulance

The SMS contains:

* Emergency message
* Latitude and Longitude
* Google Maps live location link

If GPS signal is unavailable, the system automatically sends a predefined backup location.

---

# 🔌 Circuit Connections

## GPS Module → ESP32

| GPS | ESP32  |
| --- | ------ |
| VCC | 3.3V   |
| GND | GND    |
| TX  | GPIO16 |
| RX  | GPIO17 |

---

## SIM800L → ESP32

| SIM800L | ESP32              |
| ------- | ------------------ |
| VCC     | External 4V Supply |
| GND     | GND                |
| TXD     | GPIO27             |
| RXD     | GPIO26             |

> ⚠️ SIM800L should not be powered directly from ESP32 3.3V pin.

---

## I2C LCD → ESP32

| LCD | ESP32  |
| --- | ------ |
| VCC | 5V     |
| GND | GND    |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

## Push Buttons

| Button   | ESP32 Pin |
| -------- | --------- |
| Button 1 | GPIO32    |
| Button 2 | GPIO33    |

---

# 💻 Software Requirements

* Arduino IDE
* ESP32 Board Package
* TinyGPS++ Library
* LiquidCrystal_I2C Library

---

# 📚 Required Libraries

Install the following libraries from Arduino Library Manager:

```cpp
TinyGPS++
LiquidCrystal_I2C
Wire
```

---

# 🚀 Upload Instructions

1. Install ESP32 board package in Arduino IDE
2. Connect ESP32 using USB cable
3. Select correct COM port
4. Select ESP32 Dev Module board
5. Install required libraries
6. Upload the code
7. Open Serial Monitor at 115200 baud rate

---

# 📱 Example SMS Alert

```text
EMERGENCY ALERT!
Need immediate help.

Location:
Lat:11.323078
Lon:77.674987

https://maps.google.com/?q=11.323078,77.674987
```

---

# 🧠 Applications

* Women Safety Systems
* Forest Safety Monitoring
* Emergency Rescue Devices
* Personal Safety Gadgets
* Elderly Emergency Assistance
* Smart IoT Safety Projects

---

# 📸 Project Output

* LCD displays alert status
* SMS received with GPS location
* Google Maps opens exact location
* Serial monitor shows debugging data

---

# 🔍 Future Improvements

* Mobile App Integration
* Cloud Database Logging
* Buzzer Alarm System
* Voice Calling Feature
* Rechargeable Battery Support
* IoT Dashboard Monitoring

---

# 👨‍💻 Developed Using

* Embedded Systems
* IoT Technology
* ESP32 Microcontroller
* GSM Communication
* GPS Tracking


This project is open-source and available for educational and research purposes.
