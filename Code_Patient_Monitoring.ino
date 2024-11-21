#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Pin Definitions
#define DHTPIN 9     // Data pin for DHT11 sensor
#define DHTTYPE DHT11  // DHT11 sensor type
#define ONE_WIRE_BUS 8  // Pin for DS18B20 sensor
const int heartRatePin = A0;  // Pin for Heart Rate sensor
const int MQ135Pin = A2;      // Pin for MQ135 gas sensor (connected to A2)

// Initialize Sensors
DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Heart Rate Sensor Variables
int sensorValueHR = 0;       // To store sensor readings from heart rate sensor
int lastSensorValueHR = 0;   // Last sensor value for comparison
int beatThreshold = 512;     // Threshold to detect a heartbeat (adjust this value based on your sensor)
unsigned long lastBeatTime = 0; // Time of last beat detection
unsigned long currentTime = 0;  // Current time for BPM calculation
unsigned long beatInterval = 0;  // Time interval between beats in milliseconds
int beatsPerMinute = 0;    // Heart rate (beats per minute)

// Other Sensor Variables
float humidity = 0;
float temperature = 0;
float Celsius = 0;
float Fahrenheit = 0;

void setup() {
  // Start Serial Communication
  Serial.begin(9600);

  // Initialize Sensors
  dht.begin();  // DHT11 sensor
  sensors.begin();  // DS18B20 sensor

  // Print headers for tabulated data
  Serial.println("Sensor\t\tValue");
}

void loop() {
  // Read DHT11 Sensor (Humidity and Temperature)
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Read DS18B20 Sensor (Temperature)
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);

  // Read Heart Rate Sensor (Analog value)
  sensorValueHR = analogRead(heartRatePin);

  // Detect Heartbeat (for BPM calculation)
  if (sensorValueHR > beatThreshold && lastSensorValueHR <= beatThreshold) {
    currentTime = millis();
    beatInterval = currentTime - lastBeatTime;

    if (beatInterval > 0) {
      beatsPerMinute = 60000 / beatInterval;
    }

    // Print Beat Detected message and BPM
    Serial.println("BEAT DETECTED");
    Serial.print("Heart Rate (BPM): ");
    Serial.println(beatsPerMinute);

    lastBeatTime = currentTime;
  } else {
    // No beat detected, send zero BPM value
    Serial.println("NO BEAT DETECTED");
    Serial.print("Heart Rate (BPM): ");
    Serial.println(0);
  }

  // Read MQ135 Gas Sensor (Analog value)
  int gasLevel = analogRead(MQ135Pin);

  // Print Sensor Values in a Clear Format
  // DS18B20 Body Temperature
  Serial.print("Body Temperature (C): ");
  Serial.println(Celsius);

  // DHT11 Room Temperature
  Serial.print("Room Temperature (C): ");
  Serial.println(temperature);

  // DHT11 Humidity
  Serial.print("Humidity (%): ");
  Serial.println(humidity);

  // MQ135 Gas Level with Air Quality Check
  Serial.print("Gas Level (Analog): ");
  Serial.println(gasLevel);
  if (gasLevel < 300) { // Example threshold for good air quality (adjust as needed)
    Serial.println("GOOD AIR QUALITY");
  }

  // Update the last sensor value for next comparison
  lastSensorValueHR = sensorValueHR;

  // Small delay to avoid too much serial output
  delay(2000);  // Adjust the delay as needed
}
