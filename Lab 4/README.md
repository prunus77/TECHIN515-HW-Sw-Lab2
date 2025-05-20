# TECHIN 515 - Hardware and Software Lab 2

This repository contains the lab assignments for TECHIN 515 Hardware and Software Lab 2. Each lab focuses on different aspects of embedded systems development and hardware-software integration.

## Lab Assignments

### Lab 1: Introduction to ESP32
- Basic ESP32 setup and configuration
- LED control and button input
- Serial communication

### Lab 2: Sensor Integration
- MPU6050 accelerometer/gyroscope integration
- Data collection and processing
- Real-time sensor data visualization

### Lab 3: Edge Computing
- Edge Impulse integration
- Machine learning model deployment
- Real-time inference on ESP32

### Lab 4: Gesture Recognition System
- Complete gesture recognition system implementation
- Data collection and processing
- Machine learning model training and deployment
- Real-time gesture recognition

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
- Required Python packages:
  ```
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