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
- MFRC522 Scanner
- 2-Channel Relay Module
- Wiznet W5100 Ethernet Shield
- MQ-2 Smoke and Gas Sensor
- ADXL345 Accelerometer
- Buzzer
- DY-HV20T Audio Player
- 12V Centralized Power Supply
- 12V to 9V buck converter

- Mini PC
- Display Monitor

### Software:
- Arduino IDE
- Visual Studio
- Visual Studio Code
- XAMPP
- Libraries: `SPI.h`, `Ethernet.h`, `MFRC522.h`, `Keypad.h`, `Wire.h`, `LiquidCrystal_I2C.h`, `DYPlayerArduino.h`, `Adafruit_Sensor.h`, `Adafruit_ADXL345_U.h`

---

## Installation

### 1. Set Up the Arduino IDE
1. Download and install [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the required libraries using the Library Manager:
   ```
   Ethernet
   Adafruit Sensor
   Adafruit ADXL345
   Keypad
   LiquidCrystal I2C
   MFRC522
   SoftwareWire
   ```

### 2. Load the Code
1. Clone this repository or download the code file.
2. Open the `.ino` file in Arduino IDE.
3. The `.ino` file named `GRIMLOCK_v4.1` containes the general code for the door lock. While the `GRIMLOCK_v4.1.1` containes the code for the accelerometer, and smoke sensor.
4. Update the `IP addresses` in the `GRIMLOCK_v4.1.ino`
   ```cpp
   byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // Mac address of the Arduino. It needs to be unique to the network.
   IPAddress ip(192, 168, 1, 179);   // Static IP address of Arduino
   IPAddress server(192, 168, 1, 103 );    // IP address of the server
   ```
   And also to the similar snippets below, or you can just click Ctrl+F and search for "Host"
   ```cpp
   if (client.connect(server, 80)) {
     client.print("GET /controller/insert_in_out.php?tag=");
     client.print(rfidTag);
     client.println(" HTTP/1.1");
     client.println("Host:  192.168.1.103");
     client.println("Connection: close");
     client.println();
   }
   ```
5. Upload the code to your Arduino Mega.
6. For the other controller, upload the `GRIMLOCK_v4.1.1`.

---

## Usage
1. Power up the Arduino and connected components.
2. Open the Serial Monitor for debugging purposes.
3. Monitor the API response

---

## Challenges Faced
- The network connection may not be stable sometimes.
- MFRC522 may not also be stable when the wire used is rusted.

### Solutions
- Added a external reset button for the micro controller to refresh-restart the connection.
- Ensured proper and good condition of wire used.

---

## Future Improvements
- Add proper wiring to the device.
- Instead of using MFRC522, use NFC reader instead and let the desktop application do the RFID card handling.

---

## Contact
For questions or suggestions, feel free to contact me:
- **Email:** jolomeda@my.cspc.edu.ph
- **GitHub:** [GitHub Profile](https://github.com/mamamakoko)
