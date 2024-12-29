# The Monitor

---

## 🌟 Introduction

The Monitor is a **compact and versatile device** designed to monitor pulse, movement, and health-related events. It incorporates advanced sensors to measure heart rate and activity levels, making it highly useful for:

- **🏋️ Fitness Enthusiasts**
- **👴 Older Individuals**
- **❤️ People at Risk of Heart Conditions**

With the integration of an ECG sensor module (AD8232), crash detection mechanisms, and alert features, The Monitor provides proactive health tracking. It functions similarly to a **Holter monitor**, offering continuous monitoring in a portable format.

---

## 🔍 General Description

### 📜 Block Diagram

![Flowcharts](https://github.com/user-attachments/assets/6d024103-adf2-4b0b-b3ed-f9cdc99bb94f)
### AD8232 ESP32 Connection
![Blank diagram](https://github.com/user-attachments/assets/f2a88a64-946d-4a47-884b-bd35f8c5d4d3)

The Monitor combines lightweight, wearable hardware with intuitive software to:

- Collect
- Analyze
- Display health and activity data

### Benefits

| Beneficiary          | Benefit                              |
|----------------------|--------------------------------------|
| **Older Adults**     | Fall and irregular heart activity monitoring |
| **Heart Patients**   | Alerts for unsafe heart rate levels |
| **Fitness Enthusiasts** | Real-time activity tracking        |

---

## ⚙️ Hardware Design

### 📦 Components

| Component                   | Quantity | Purpose                                              |
|-----------------------------|----------|------------------------------------------------------|
| **RGB LED**                 | 1        | Indicates status|
| **ESP32**             | 1        | Microcontroller for data processing and system control |
| **ECG Sensor Module (AD8232)** | 1        | Captures real-time heart activity                   |
| **Accelerometer (MPU6050)** | 1        | Tracks motion to identify activity and falls         |
| **Display (LCD)**   | 1        | Shows heart rate, activity levels, and alerts       |
| **Push Button**             | 1        | Simple start/stop interface                         |
| **Buzzer**                  | 1        | Audible alerts for abnormal events                 |
| **Battery**    | 1        | Lightweight power source                            |
| **Resistors**               | 5        | Stabilizes circuit operation                       |
| **Capacitors**              | 3        | Filters noise and stabilizes power                 |
| **Breadboard or PCB**       | 1        | Compact circuit assembly                           |
| **Jumper Wires**            | 20       | Connects components                                |
| **3D-Printed Case**         | 1        | Protects components  s   |
| **SD Card Module**          | 1        | Logs data such as heart rate and events            |

### 🛠️ Assembly

- **Mount Components**: Secure components on a breadboard.
- **Optimize Placement**: Position ECG sensor and accelerometer for accurate readings.

---

## 💻 Software Design

Developed using **Arduino IDE**, leveraging libraries for sensor integration.

### Key Features

1. **Data Collection**: Reads real-time signals from ECG sensor and accelerometer.
2. **Signal Processing**: Filters noise for accurate readings.
3. **Threshold Detection**: Alerts for predefined heart rate limits.
4. **Fall Detection**: Identifies abrupt motion changes.
5. **User Interface**: Displays:
   - Heart rate
   - Alerts
   - Status messages

### 🚨 Alert System

| Condition           | Action                  |
|---------------------|-------------------------|
| **Low Heart Rate**  | Trigger buzzer tone     |
| **High Heart Rate** | Trigger distinct tone   |
| **Fall Detected**   | Continuous buzzer sound |

---

## 🩺 Medical Benefits

The Monitor’s **key health advantages**:

- **Proactive Heart Monitoring**: Alerts abnormalities, preventing complications.
- **Fall Detection**: Ensures timely emergency response.
- **Accessibility**: Simplifies health tracking for all ages.

---

## 📊 Results 

Placeholder for results

---

## 📅 Diary

Integrated project README
Switched to ESP32 for data handling via Ubidots for future project scaling

---

## 📂 Source Code and Misc

Placeholder for Source Code and Misc

---

## 📑 Additional Documentation



### 🔧 Detailed Hardware Functionality

RGB LED: Uses three digital pins (GPIO16, GPIO17, GPIO18) to control red, green, and blue channels. The LED will indicate the following states:
  - **Green**: Normal operation.
  - **Yellow**: Warning or abnormal conditions detected.
  - **Red**: Critical alert, such as a fall or dangerously low heart rate.

ECG Sensor (AD8232): Connected via analog pin (GPIO36) for heart rate detection.

Accelerometer (MPU6050): Connected via I2C (GPIO21 - SDA, GPIO22 - SCL) for motion analysis.

Display (LCD1602): Uses I2C (GPIO21 - SDA, GPIO22 - SCL) for real-time data visualization.

Buzzer: Controlled via digital pin (GPIO25) for alerts.

Button: Connected via digital pin (GPIO27) for start/stop functionality.

SD Card Module: Connected via SPI (GPIO5 - CS, GPIO23 - MOSI, GPIO19 - MISO, GPIO18 - SCK) to log real-time data such as heart rate, alerts, and motion activity.



| Component            | Pins Used            | Purpose                                   |
|----------------------|----------------------|-------------------------------------------|
| **RGB LED**          | GPIO16 (Red), GPIO17 (Green), GPIO18 (Blue) | Full-color status indication (normal, warning, alert) |
| **ECG Sensor**       | GPIO36 (VP)         | Reads analog heart rate signal           |
| **Accelerometer**    | GPIO21 (SDA), GPIO22 (SCL) | Motion detection via I2C communication   |
| **LCD1602 Display**  | GPIO21 (SDA), GPIO22 (SCL) | Displays real-time metrics via I2C       |
| **SD Card Module**   | GPIO5 (CS), GPIO23 (MOSI), GPIO19 (MISO), GPIO18 (SCK) | Logs real-time data                       |
| **Buzzer**           | GPIO25              | Triggers audio alerts                    |
| **Button**           | GPIO27              | Start/stop functionality                 |



---

## 📚 Bibliography and Resources

1. [Arduino IDE Documentation](https://www.arduino.cc/en/Guide)
2. [AD8232 ECG Sensor Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/ad8232.pdf)
3. [MPU6050 Accelerometer Module Datasheet](https://www.alldatasheet.com/view.jsp?Searchword=Mpu-6050%20datasheet&gad_source=1&gclid=CjwKCAiApY-7BhBjEiwAQMrrEeIHpV8Z8e906Y5OvtslpqZj430skJS8nmNGwVekbN71cOcSCk0sThoCq5sQAvD_BwE)
