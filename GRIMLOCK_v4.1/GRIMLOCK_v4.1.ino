/*
  Author: John Francis Lomeda
  Title: GRIMLOCK: A Multi-method Door Lock System for NAS Laboratory
  Team: UNO

  Documentation:
    1.  Upon powering on the device with stand alone mode, the microcontroller should be reseted/refresh to remove the bugs regarding the
        pincode getting stocked. In this project's case, the external wiring of push button for GND  and RESET pin are used.
*/


#include <SPI.h>
#include <Ethernet.h>
#include <MFRC522.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DYPlayerArduino.h" 

// Initialise the player, it defaults to using Serial.
// DY::Player player;  //  Used typically for Arduino Uno
DY::Player player(&Serial3);

// Initialize the LCD with I2C address (0x27 is the address in this project's case)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int relayPin1 = 6; // IN PIN for electromagnetic lock
int relayPin2 = 5; // IN PIN for electric lock

int smoke_pin = A8;
int smoke_thres = 300;
const int buzzer_pin = 47;

#define SS_PIN1 30    // RFID Reader 1 scanner inside the room
#define SS_PIN2 53    // RFID Reader 2 scanner outside the room
#define RST_PIN 4

MFRC522 rfid1(SS_PIN1, RST_PIN);
MFRC522 rfid2(SS_PIN2, RST_PIN);

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // Mac address ni Arduino. Dapat unique sa network.
IPAddress ip(192, 168, 1, 179);   // Static IP address of Arduino
IPAddress server(192, 168, 1, 103 );    // IP address of the server
// 192.168.1.103

EthernetClient client;

// Keypad setup
const byte ROWS = 4;  // Four rows 
const byte COLS = 3;  // Three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Connect keypad ROW pins to Arduino Mega
byte rowPins[ROWS] = {45, 43, 41, 39};

// Connect keypad COL pins to Arduino Mega
byte colPins[COLS] = {37, 35, 33};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String pincode = "";

unsigned long relayActivatedTime = 0;
bool relayActive = false;

void setup() {

  // Relay
  pinMode(relayPin1, OUTPUT);
  digitalWrite(relayPin1, LOW); // Initialize relay off (LOW)
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin2, LOW); // Initialize relay off (LOW)

  pinMode(22, OUTPUT);
  digitalWrite(22, LOW);

  Serial.begin(9600);
  SPI.begin();

  player.begin();
  player.setVolume(30); // 100% Volume
  
  rfid1.PCD_Init();
  rfid2.PCD_Init();

  // Set the buzzer pin as an output
  pinMode(buzzer_pin, OUTPUT);

  Ethernet.begin(mac, ip);
  delay(1000);
  Serial.println("Ethernet and RFID Initialized");

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.backlight(); // Turn on the LCD backlight

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan your ID...");
}

void loop() {
  // Handle the first RFID reader para sa time-out
  if (rfid1.PICC_IsNewCardPresent() && rfid1.PICC_ReadCardSerial()) {
    tone(buzzer_pin, 1000, 50);
    handleRFIDReader1();
  }

  // Handle the second RFID reader para sa magbubukas
  if (rfid2.PICC_IsNewCardPresent() && rfid2.PICC_ReadCardSerial()) {
    tone(buzzer_pin, 1000, 50);
    handleRFIDReader2();
  }

  // Check if the relay needs to be deactivated after 15 minutes
  if (relayActive && millis() - relayActivatedTime >= 10000) {
    digitalWrite(relayPin1, LOW); // Turn relay off (lock the electromagnetic lock)
    relayActive = false; // Reset the relay state
  }

  // Smoke alarm function
  //int smoke_value = analogRead(smoke_pin); // Read the smoke sensor value
  // Serial.print("Smoke Value: ");  // For smoke monitoring only. Uncomment if needed.
  // Serial.println(smoke_value); // Print the smoke sensor value to the serial monitor
  //checkSmokeLevel(smoke_value); // Call the function to check the smoke level
}

String getPincode() {
  String pincode = "";
  Serial.print("Enter pincode: ");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter pin code:"); // Display the message on the LCD

  // Wait for pincode entry
  while (pincode.length() < 6) {
    char key = keypad.getKey();
    if (key != NO_KEY) {
      if (isDigit(key)) {
        pincode += key;
        Serial.print(key);  // Echo the entered digit
        lcd.setCursor(pincode.length(), 1);
        lcd.print('*');  // Display '*' for each entered digit
      } else if (key == '#') {
        lcd.clear();
        lcd.print("Cancelled");
        delay(2000);
        return "";  // Return empty string on cancel
      } else if (key == '*') {
        pincode = "";  // Allow the user to clear the input
        lcd.clear();
        lcd.print("Cleared");
        delay(1000);
        lcd.clear();
        lcd.print("Enter pin code:");
      }
    }
  }
  
  Serial.println();  // Move to the next line after entering pincode

  // Optionally, validate length (ensure exactly 6 digits)
  if (pincode.length() != 6) {
    Serial.println("Invalid pincode length!");
    lcd.clear();
    lcd.print("Invalid pincode!");
    delay(2000);
    return "";  // Return empty string if invalid
  }

  return pincode;
}


void handleRFIDReader1() {
  Serial.println("Card detected by Reader 1");

  String rfidTag = "";
  for (byte i = 0; i < rfid1.uid.size; i++) {
    rfidTag += String(rfid1.uid.uidByte[i], HEX);
  }
  rfidTag.toUpperCase();
  Serial.println("RFID Tag (Reader 1): " + rfidTag);

   // Send the RFID tag and pincode to the server
  if (client.connect(server, 80)) {
    client.print("GET /controller/insert_in_out.php?tag=");
    client.print(rfidTag);
    client.println(" HTTP/1.1");
    client.println("Host:  192.168.1.103");
    client.println("Connection: close");
    client.println();

    // Read the server response
    while (client.connected()) {
      if (client.available()) {
        String response = client.readStringUntil('\n');
        response.trim();  // Remove any trailing whitespace or newline characters
        Serial.println("Server response: " + response);

        if (response == "Time-out recorded successfully.") {
          tone(buzzer_pin, 1000, 100);
          // Turn relay on (this will unlock the electromagnetic lock)
          digitalWrite(relayPin1, HIGH);
          relayActivatedTime = millis(); // Record the time when relay is activated
          relayActive = true; // Set relay active state
          digitalWrite(relayPin2, HIGH);
          delay(1000);
          digitalWrite(relayPin2, LOW);

        } else if (response == "Error updating time-out!") {
          tone(buzzer_pin, 1000, 100);
          delay(200);
          tone(buzzer_pin, 500, 100);
          Serial.print("Error updating time-out!");
        } else if (response == "Time-in recorded successfully!") {
          tone(buzzer_pin, 1000, 100);
          delay(200);
          tone(buzzer_pin, 1000, 100);
          Serial.println("Time-in recorded successfully!");
        } else if (response == "Error updating attendance record!") {
          tone(buzzer_pin, 1000, 100);
          delay(200);
          tone(buzzer_pin, 500, 100);
          Serial.println("Error updating attendance record!");
        } else if (response == "No matching schedule found for the provided RFID.") {
          tone(buzzer_pin, 1000, 100);
          delay(200);
          tone(buzzer_pin, 500, 100);
          Serial.println("No matching schedule found for the provided RFID.");
        } 
      }
    }
    client.stop();
  } else {
    Serial.println("Connection to server failed");
  }

  // Small delay before running the second PHP script
  delay(100);  // Optional: You may need a short delay between requests

  // Send the RFID tag to the second script
  if (client.connect(server, 80)) {
    client.print("GET /controller/insert_access.php?tag=");
    client.print(rfidTag);
    client.println(" HTTP/1.1");
    client.println("Host:  192.168.1.103");
    client.println("Connection: close");
    client.println();

    // Read the server response for the second script
    while (client.connected()) {
      if (client.available()) {
        String response = client.readStringUntil('\n');
        response.trim();  // Remove any trailing whitespace or newline characters
        Serial.println("Server response from insert_access.php: " + response);

        if (response == "Time-in log recorded!") {
          Serial.println("Time-in log recorded!");
        } else if (response == "Time-in log failed!") {
          Serial.println("Time-in log failed to record!");
        }
      }
    }
    client.stop();
  } else {
    Serial.println("Connection to server failed for insert_access.php");
  }
  
  rfid1.PICC_HaltA();  // Halt PICC for Reader 1
}

void handleRFIDReader2() {
  Serial.println("Card detected by Reader 2");

  String rfidTag = "";
  for (byte i = 0; i < rfid2.uid.size; i++) {
    rfidTag += String(rfid2.uid.uidByte[i], HEX);
  }
  rfidTag.toUpperCase();
  Serial.println("RFID Tag (Reader 2): " + rfidTag);

  if (pincode.length() == 0) {
    pincode = getPincode(); // Ask for pincode if not already entered
  }

  // Check if the pincode was entered before scanning the RFID
  if (pincode.length() > 0) {
    // Send the RFID tag and pincode to the server
    if (client.connect(server, 80)) {
      client.print("GET /controller/check_rfid_pincode.php?tag=");
      client.print(rfidTag);
      client.print("&pincode=");
      client.print(pincode);
      client.println(" HTTP/1.1");
      client.println("Host: 192.168.1.103");
      client.println("Connection: close");
      client.println();

      // Read the server response
      while (client.connected()) {
        if (client.available()) {
          String response = client.readStringUntil('\n');
          response.trim();  // Remove any trailing whitespace or newline characters
          Serial.println("Server response: " + response);

          if (response == "exists") {
            if (client.connect(server, 80)) {
              client.print("GET /controller/insert_staff_access.php?tag=");
              client.print(rfidTag);
              client.println(" HTTP/1.1");
              client.println("Host: 192.168.1.103");
              client.println("Connection: close");
              client.println();
              client.stop(); // Close the connection after request
              Serial.println("Access log recorded successfully.");
            } else {
              Serial.println("Failed to connect for access log.");
            }

            lcd.clear();
            lcd.setCursor(4, 0);
            lcd.print("WELCOME!");
            player.playSpecified(2);
            delay(3000);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Scan your ID...");
            
            // Turn relay on (this will unlock the electromagnetic lock)
            digitalWrite(relayPin1, HIGH);
            relayActivatedTime = millis(); // Record the time when relay is activated
            relayActive = true; // Set relay active state
            digitalWrite(relayPin2, HIGH);
            delay(1000);
            digitalWrite(relayPin2, LOW);

            Serial.println("RFID tag and pincode exist in the database.");

            // Send the RFID tag to insert_access.php
            client.stop(); // Ensure the first request is closed
            delay(10); // Small delay to ensure the server is ready for the next request

          } else if (response == "not found") {
            player.playSpecified(1);
            Serial.println("RFID tag or pincode not found in the database.");
            tone(buzzer_pin, 1000, 50);
            tone(buzzer_pin, 500, 50);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("ID or PINCODE");
            lcd.setCursor(0, 1);
            lcd.print("NOT FOUND!");
            delay(3000);
            lcd.clear();
            lcd.print("Scan your ID...");
          }
        }
      }
      
      client.stop();
    } else {
      Serial.println("Connection to server failed");
      player.playSpecified(1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("FAILED server");
      lcd.setCursor(0, 1);
      lcd.print("connection!");
      delay(5000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Scan your ID...");
    }
  }
  
  rfid2.PICC_HaltA();  // Halt PICC for Reader 2
  pincode = "";  // Reset pincode after successful scan
}

void checkSmokeLevel(int smoke_value) {
  if (smoke_value > smoke_thres) {
    unsigned long startTime = millis();  // Record the start time
    unsigned long duration = 10000;  // 5 minutes in milliseconds
    String Fire;
    String NAS;

    // Turn relay on (this will unlock the electromagnetic lock)
    digitalWrite(relayPin1, HIGH);
    relayActivatedTime = millis(); // Record the time when relay is activated
    relayActive = true; // Set relay active state
    digitalWrite(relayPin2, HIGH);
    delay(1000);
    digitalWrite(relayPin2, LOW);

    if (client.connect(server, 80)) {
      client.print("GET /controller/insert_emergency.php?type=");
      client.print(Fire);
      client.print("&laboratory=");
      client.print(NAS);
      client.println(" HTTP/1.1");
      client.println("Host: 192.168.1.103");
      client.println("Connection: close");
      client.println();

      // Read the server response
      while (client.connected()) {
        if (client.available()) {
          String response = client.readStringUntil('\n');
          response.trim();  // Remove any trailing whitespace or newline characters
          Serial.println("Server response: " + response);

          if (response == "Emergency log recorded!") {
            Serial.println("Emergency log recorded!");
          } else if (response == "error") {
            Serial.println("Emergency log failed to record!");
          }
        }
      }
      client.stop();
    } else {
      Serial.println("Connection to server failed for smoke.");
    }

    while (millis() - startTime < duration) {
      tone(buzzer_pin, 1000);  // Play the tone at 1000 Hz
      delay(100);              // Delay for 100 milliseconds
      noTone(buzzer_pin);      // Stop the tone
      delay(100);              // Pause between beeps
    }

    // Add any additional delay or logic if needed after the 5 minutes
    delay(10000);  // Wait for 10 seconds before checking again
  }
}