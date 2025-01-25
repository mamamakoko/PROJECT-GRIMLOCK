# GRIMLOCK: A Multi Method Door Lock System for NAS Laboratory

A project designed to automate and secure the NAS Laboratory using an Arduino Uno, and a user identification display. This project enables users to automate attendance record, and unlock/lock the door when black-out, fire, earthquake is experienced.

---

## Features
- **Attendance Recording:** Automatically record attendance of the students
- **Attendance Monitoring:** Real-time updates of attendance.
- **Emergency response:** Automatically unlocks the door when seismic and smoke is detected.

---

## Components Used

### Hardware:
- Arduino Mega 2560
- Arduino Uno R3
- 2-Channel Relay Module
- Wiznet W5100 Ethernet Shield
- LED Bulbs (for demonstration)
- Smartphone (for app control)

### Software:
- Arduino IDE
- Visual Studio
- Libraries: `SPI.h`, `Ethernet.h`, `MFRC522.h`, `Keypad.h`, `Wire.h`, `LiquidCrystal_I2C.h`, `DYPlayerArduino.h`, `Adafruit_Sensor.h`, `Adafruit_ADXL345_U.h`

---

## Circuit Diagram
![Circuit Diagram](https://example.com/circuit_diagram.png)

Connect the relay module to the Arduino Uno, ensuring the following:
- **Relay IN1-IN4** connected to Arduino digital pins (e.g., D2-D5).
- **VCC and GND** of the relay to 5V and GND on Arduino.
- ESP8266 connections:
  - TX -> RX on Arduino (via voltage divider if necessary)
  - RX -> TX on Arduino
  - VCC and GND -> 3.3V and GND on Arduino.

---

## Installation

### 1. Set Up the Arduino IDE
1. Download and install [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the required libraries using the Library Manager:
   ```
   BlynkSimpleEsp8266
   ESP8266WiFi
   ```

### 2. Load the Code
1. Clone this repository or download the code file.
2. Open the `.ino` file in Arduino IDE.
3. Update the `WiFi` credentials and `Blynk` authentication token:
   ```cpp
   char auth[] = "YOUR_BLYNK_TOKEN";
   char ssid[] = "YOUR_WIFI_SSID";
   char pass[] = "YOUR_WIFI_PASSWORD";
   ```
4. Upload the code to your Arduino Uno.

### 3. Connect to Blynk App
1. Download the Blynk app from the [App Store](https://apps.apple.com) or [Google Play](https://play.google.com).
2. Create a new project, and add buttons for each relay channel.
3. Link the buttons to the correct virtual pins (e.g., V1-V4).

---

## Usage
1. Power up the Arduino and connected components.
2. Open the Blynk app, connect to the project, and control the appliances.
3. Monitor real-time appliance statuses on the app.

---

## Code Snippet
```cpp
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YOUR_BLYNK_TOKEN";
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(2, OUTPUT);  // Relay 1
  pinMode(3, OUTPUT);  // Relay 2
}

void loop() {
  Blynk.run();
}
```

---

## Challenges Faced
- Initial connection issues with the ESP8266 module.
- Overheating of the relay module during testing.

### Solutions
- Added a 10 µF capacitor to stabilize the power supply for the ESP8266.
- Ensured proper insulation for high-current connections.

---

## Future Improvements
- Add voice control integration (e.g., Alexa or Google Assistant).
- Implement energy monitoring for each appliance.
- Include a security feature for user authentication.

---

## Media
### Images:
![Project Setup](https://example.com/project_setup.png)

### Video Demo:
[Watch the demo on YouTube](https://youtube.com/example-demo)

---

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Contact
For questions or suggestions, feel free to contact me:
- **Email:** your_email@example.com
- **GitHub:** [Your GitHub Profile](https://github.com/yourusername)
