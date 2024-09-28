# RTC Synchronization with ESP32 using NTP and DS3231

This project demonstrates how to use an ESP32 microcontroller to synchronize a DS3231 Real-Time Clock (RTC) module with the current date and time obtained from a Network Time Protocol (NTP) server. The synchronized time is then displayed via the serial monitor, making it useful for applications where precise timing is essential.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Features](#features)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Code Walkthrough](#code-walkthrough)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Introduction

This project uses an ESP32 microcontroller to communicate with the DS3231 RTC module over the I2C protocol. It connects to a Wi-Fi network and retrieves the current time from an NTP server. The obtained time is then adjusted for a specific timezone offset and set on the DS3231 module, ensuring it always has the correct date and time.

## Hardware Requirements

- ESP32 Development Board
- DS3231 RTC Module
- Jumper Wires
- Breadboard (optional)

### Pin Connections

| **ESP32** | **DS3231** |
|-----------|------------|
| 3.3V      | VCC        |
| GND       | GND        |
| GPIO 21   | SDA        |
| GPIO 22   | SCL        |

## Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (version 1.8.10 or newer)
- ESP32 Board Package installed in Arduino IDE (Refer to [ESP32 Setup Guide](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/))
- `Wire` library (built-in with Arduino IDE)
- `DS3231` library (can be installed via Library Manager)
- `WiFi` library (built-in with ESP32 core)
- `time` library (built-in with ESP32 core)

## Features

- **Real-Time Clock Setup**: Sets the DS3231 RTC module's time using a network-based NTP server.
- **Wi-Fi Connectivity**: Connects to a Wi-Fi network to access the NTP server.
- **Time Zone Support**: Supports time zone adjustments with customizable offset.
- **Accurate Timekeeping**: Ensures precise timekeeping by using the DS3231's built-in temperature-compensated crystal oscillator.

## Circuit Diagram

Below is a basic circuit connection diagram:

![RTC Interfacing with ESP32](https://www.electronicwings.com/storage/PlatformSection/TopicContent/438/description/DS1307%20Interfacing%20with%20ESP32.jpg)

Ensure you connect the ESP32 to the DS3231 module correctly according to the above table.

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/ESP32-RTC-Sync.git
    cd ESP32-RTC-Sync
    ```

2. Open the project in the [Arduino IDE](https://www.arduino.cc/en/software).

3. Install the required libraries:
   - `DS3231` (Install via Library Manager)
   - `RTClib` (Install via Library Manager)

4. Connect your ESP32 board to your computer and select the appropriate board and COM port from the `Tools` menu in the Arduino IDE.

5. Upload the code to your ESP32.

## Usage

1. After uploading the code, open the Serial Monitor at a baud rate of 115200.
2. The ESP32 will attempt to connect to the configured Wi-Fi network.
3. Once connected, the device will retrieve time from the NTP server and set it on the DS3231 module.
4. The synchronized date and time will be printed on the Serial Monitor.

### Configuring Wi-Fi Credentials

Replace the `ssid` and `password` variables in the code with your Wi-Fi network's credentials:

```cpp
const char *ssid = "Your_SSID";
const char *password = "Your_PASSWORD";
```

### Adjusting Time Zone Offset

Modify the `offsetHours` and `offsetMinutes` variables to set your desired time zone offset. For example, GMT+5:30:

```cpp
int offsetHours = 5;    // Hour offset
int offsetMinutes = 30; // Minute offset
```

## Code Walkthrough

The main functions in the code are:

1. **`connectToWiFi()`**: This function initiates a connection to the Wi-Fi network using the provided SSID and password. It continuously checks for connection status and displays progress on the Serial Monitor.

2. **`setRTCFromNTP()`**: This function configures and connects to an NTP server (`time.nist.gov`) to obtain the current UTC time. It applies a time zone offset and sets the DS3231 RTC with the obtained time.

3. **`setup()`**: Initializes the serial communication, connects to Wi-Fi, and sets the RTC time.

4. **`loop()`**: Reads the current date and time from the DS3231 RTC and displays it on the Serial Monitor.

## Troubleshooting

- **Wi-Fi Connection Issues**: Ensure your SSID and password are correct. Check if the ESP32 is within range of the Wi-Fi network.
- **RTC Not Setting Time**: If the RTC module is not being set with the NTP time, verify the connections between the ESP32 and the DS3231. Ensure SDA and SCL pins are correctly connected.
- **Incorrect Time Display**: Check the time zone offset settings in the code. Adjust as necessary to match your local time zone.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to raise issues or submit pull requests if you find any bugs or want to contribute to the project!
```

This README provides comprehensive details, helping users to understand the project setup, usage, and code functionalities. Let me know if you'd like to add or modify any sections!
