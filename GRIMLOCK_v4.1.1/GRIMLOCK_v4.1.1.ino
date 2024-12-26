#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
const float x_threshold = 5.0;
const float y_threshold = 15.0;
const float z_threshold = 6.0;

int relayPin1 = 6; // IN PIN for electromagnetic lock
int relayPin2 = 5; // IN PIN for electric lock
const int buzzer_pin = 3;

unsigned long relayActivatedTime = 0;
bool relayActive = false;
unsigned long startTime = 0;
bool earthquakeDetected = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();

  // Relay
  pinMode(relayPin1, OUTPUT);
  digitalWrite(relayPin1, LOW); // Initialize relay off (LOW)
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin2, LOW); // Initialize relay off (LOW)

  // Set the buzzer pin as an output
  pinMode(buzzer_pin, OUTPUT);

  if (!accel.begin()) {
    Serial.println("No ADXL345 detected");
    while (1);
  }

  accel.setRange(ADXL345_RANGE_16_G);
}

void loop() {
  // Check if the relay needs to be deactivated after 15 minutes (or in this case, 10 seconds)
  if (relayActive && millis() - relayActivatedTime >= 20000) {
    digitalWrite(relayPin1, LOW); // Turn relay off (lock the electromagnetic lock)
    relayActive = false;
  }

  // Continuously read data from the ADXL345
  sensors_event_t event;
  accel.getEvent(&event);

  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;

  // Print the X, Y, Z values to the Serial Monitor (Uncomment for debugging)
  // Serial.print("X: "); Serial.print(x); Serial.print(" ");
  // Serial.print("Y: "); Serial.print(y); Serial.print(" ");
  // Serial.print("Z: "); Serial.println(z);

  // Check if earthquake is detected based on threshold
  if (abs(x) > x_threshold || abs(y) > y_threshold || abs(z) > z_threshold) {
    if (!earthquakeDetected) {
      Serial.println("Earthquake detected!");
      earthquakeDetected = true;
      startTime = millis(); // Record the start time
      triggerEarthquakeResponse();
    }
  }

  // Check if the earthquake response should continue (5 minutes duration)
  if (earthquakeDetected && millis() - startTime < 5 * 60 * 1000) {
    playBuzzer();
  } else {
    noTone(buzzer_pin); // Stop the buzzer after the duration
    earthquakeDetected = false; // Reset earthquake detection
  }

  delay(100); // Small delay to avoid flooding Serial Monitor
}

void triggerEarthquakeResponse() {
  // Turn relay on (this will unlock the electromagnetic lock)
  digitalWrite(relayPin1, HIGH);
  relayActivatedTime = millis(); // Record the time when the relay was activated
  relayActive = true; // Set relay active state


  // Pulse relay 2 for 1 second
  digitalWrite(relayPin2, HIGH);
  delay(1000);
  digitalWrite(relayPin2, LOW);
}

void playBuzzer() {
  // Play a high-pitched tone for earthquake alert
  tone(buzzer_pin, 2000); // Play a 2000 Hz tone
  delay(500); // Hold the tone for 500 ms

  noTone(buzzer_pin); // Stop the tone
  delay(200); // Pause for 200 ms

  tone(buzzer_pin, 1500); // Play a 1500 Hz tone
  delay(500); // Hold the tone for 500 ms

  noTone(buzzer_pin); // Stop the tone
  delay(200); // Pause for 200 ms
}
