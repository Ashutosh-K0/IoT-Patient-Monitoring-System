# IoT Patient Monitoring System

## Overview
The IoT Patient Monitoring System is designed to monitor and track a patient's vital signs and environmental conditions. This project uses various sensors to collect real-time data and display it for monitoring purposes. The system is built using an **Arduino UNO** and a variety of sensors for temperature, heart rate, ECG, humidity, and air quality.

## Components Used
1. **Arduino UNO**: The main microcontroller that reads data from the sensors and processes it.
2. **DS18B20 Waterproof Temperature Sensor**: Used to measure the body temperature of the patient.
3. **AD8232 ECG Sensor**: Used to monitor the heart's electrical activity and generate ECG signals.
4. **DHT11 Sensor**: Measures the humidity and temperature of the surrounding environment.
5. **MQ135 Gas Sensor**: Measures the concentration of harmful gases like ammonia, carbon dioxide, and smoke in the environment.
6. **Heart Rate Sensor HW 827**: Measures the heart rate by detecting the changes in the patient's pulse.

## Features
- **Real-time monitoring** of vital parameters such as temperature, heart rate, and ECG.
- **Environmental monitoring** with temperature, humidity, and air quality measurements.
- **Easy-to-understand interface** for monitoring and alerting the user when any parameters fall outside the safe range.
- Data can be accessed in real-time for healthcare providers or caregivers to monitor patient conditions.

## Circuit Design
The system is connected using the following sensors:
- The **DS18B20** is connected to the Arduino using a 1-Wire interface.
- The **AD8232 ECG Sensor** is connected via analog pins to capture ECG signals.
- The **DHT11** sensor uses a digital pin to read temperature and humidity values.
- The **MQ135 Gas Sensor** connects to an analog pin for air quality measurement.
- The **HW 827 Heart Rate Sensor** uses a digital pin for heart rate readings.

## Installation
To set up this project:
1. Download the code from the GitHub repository.
2. Install the necessary libraries for the sensors, including:
   - OneWire library for DS18B20.
   - Adafruit Unified Sensor library.
   - DHT sensor library.
3. Connect the components as shown in the circuit diagram.
4. Upload the code to the Arduino using the Arduino IDE.

## Usage
1. **Start the system**: Once the Arduino is powered on, it will start receiving data from the sensors.
2. **Monitor data**: The sensor readings will be available in real-time on the Arduino IDE's serial monitor or any connected display.
3. **Alert mechanism**: If any value goes beyond the preset thresholds (for example, temperature too high, heart rate abnormal), an alert can be triggered.

## Future Enhancements
- Integration with cloud platforms like **ThingSpeak** to store and visualize data remotely.
- Adding more sensors to monitor additional vital signs such as blood oxygen levels and blood pressure.
- Sending alerts and notifications to healthcare providers or family members through an app or SMS.

## License
This project is open source and available under the [MIT License](LICENSE).

## Acknowledgements
- [Arduino](https://www.arduino.cc/) for providing the platform.
- Sensor manufacturers for creating accessible and affordable sensors for health monitoring.
