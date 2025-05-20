# Gesture Recognition System

This project implements a gesture recognition system using an ESP32 microcontroller and machine learning. The system captures accelerometer data from gestures and processes it for training and inference.

## Project Structure

```
├── src/
│   ├── sketches/               # Arduino sketches and Edge Impulse exports
│   ├── python-scripts/         # Python scripts for data collection
│   └── dataset/                # Collected gesture dataset
├── docs/
│   └── report.pdf             # Final project report
├── media/
│   └── demo.mp4               # Demo video
└── enclosure/                 # Enclosure design files
    └── final-enclosure-images/
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
   git clone [repository-url]
   cd [repository-name]
   ```

2. Install Python dependencies:
   ```bash
   pip install -r requirements.txt
   ```

3. Open the Arduino sketch in `src/sketches/` using Arduino IDE
4. Install required Arduino libraries:
   - ESP32 board support
   - Edge Impulse Arduino library

### Usage

1. Data Collection:
   ```bash
   python src/python-scripts/process_gesture_data.py --gesture [gesture_name] --person [person_name]
   ```

2. Training:
   - Import collected data into Edge Impulse
   - Train the model
   - Export the trained model

3. Deployment:
   - Upload the trained model to ESP32
   - Test the gesture recognition

## Hardware Requirements

- ESP32 development board
- MPU6050 accelerometer/gyroscope
- Battery pack (3.7V LiPo recommended)
- Enclosure materials (see enclosure/notes.md)

## Contributing

Please read CONTRIBUTING.md for details on our code of conduct and the process for submitting pull requests.

## License

This project is licensed under the MIT License - see the LICENSE file for details. 