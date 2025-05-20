# Magic Wand - Gesture Recognition with Edge Impulse and ESP32

This project implements a smart "Magic Wand" using an ESP32 microcontroller, an MPU6050 accelerometer, Edge Impulse ML inference, and NeoPixel LED feedback. When a user performs a predefined gesture (e.g., "O", "V", or "Z"), the system captures accelerometer data, classifies the gesture using an Edge Impulse model, sends the result to a local server via WiFi, and lights up the NeoPixel with a corresponding color.

---

## 📦 Features

- **Gesture Capture** using MPU6050 IMU sensor
- **Real-time Inference** with Edge Impulse
- **Wireless Communication** to a local server via HTTP POST
- **LED Feedback** using NeoPixel
- **Physical Interaction** via button press

---

## 🔧 Hardware Requirements

- ESP32 Dev Board (e.g., XIAO ESP32-C3)
- MPU6050 Accelerometer/Gyroscope
- NeoPixel LED (WS2812)
- Pushbutton
- Breadboard & Jumper wires
- 3.3V Power Source or USB

---

## 🔌 Pin Connections

| Component     | ESP32 Pin        |
|---------------|------------------|
| MPU6050 SDA   | GPIO 6 (or D4)   |
| MPU6050 SCL   | GPIO 7 (or D5)   |
| NeoPixel Data | GPIO 4 (D3)      |
| Button        | GPIO 20 (D2)     |
| VCC/GND       | 3.3V / GND       |

---

## 🧠 Gestures and LED Mapping

| Gesture | LED Color |
|---------|-----------|
| `Z`     | 🔴 Red     |
| `O`     | 🔵 Blue    |
| `V`     | 🟢 Green   |

---

## 🌐 Server Integration

Gesture results are sent as a JSON payload to a local HTTP server:

### Example JSON Payload
```json
{
  "student_id": "YOUR_UWNETID",
  "gesture": "V",
  "confidence": 97.45
}
```

## Project Structure

Each lab folder contains:
```
├── src/
│   ├── sketches/               # Arduino sketches
│   ├── python-scripts/         # Python scripts for data processing
│   └── dataset/                # Collected data
├── docs/
│   └── report.pdf             # Lab report
├── media/                     # Images and videos
└── enclosure/                 # Hardware enclosure designs
```

## Setup Instructions

### Prerequisites

- Python 3.8 or higher
- Arduino IDE
- ESP32 development board

Required Python packages:
```bash
pip install pyserial numpy pandas
```

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/prunus77/TECHIN515-HW-Sw-Lab2.git
   cd TECHIN515-HW-Sw-Lab2
   ```

2. Install Python dependencies:
   ```bash
   pip install -r requirements.txt
   ```

3. Open the Arduino sketches in the respective lab's `src/sketches/` directory using Arduino IDE

4. Install required Arduino libraries:
   - ESP32 board support
   - Edge Impulse Arduino library (for Lab 3 and 4)

## Hardware Requirements
- ESP32 development board
- MPU6050 accelerometer/gyroscope (for Lab 2-4)
- LED and button (for Lab 1)
- Battery pack (3.7V LiPo recommended)
- Enclosure materials (see respective lab's enclosure directory)

## License
This project is licensed under the MIT License - see the LICENSE file for details.