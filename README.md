# Smart-Environmental-Monitoring-System-with-Blynk-BME280-DHT11-and-MQ-2-Sensors
This project uses an ESP32 to monitor temperature, humidity, pressure, and gas levels with BME280, DHT11, and MQ-2 sensors. Data is sent to Blynk for real-time monitoring, with a remotely controlled buzzer for gas level alerts.


**Description**
This project uses the ESP32 microcontroller to monitor various environmental parameters such as temperature, humidity, pressure, and gas levels. The system integrates a BME280 sensor (for temperature, humidity, and pressure), a DHT11 sensor (for temperature and humidity), and an MQ-2 sensor (for detecting smoke and gases). Data from these sensors is sent to the Blynk IoT platform for real-time monitoring and control.

Additionally, a buzzer is incorporated to alert users when gas levels exceed a certain threshold. The buzzer can be controlled remotely via the Blynk app, offering enhanced safety and convenience.

**Features**
Real-time monitoring of temperature, humidity, pressure, and gas levels.
Blynk Integration for viewing sensor data and controlling the buzzer remotely.
Buzzer Control via the Blynk app for safety alerts.
WiFi Connectivity through ESP32 to enable cloud-based data access.

**Components Used**
ESP32: Microcontroller with built-in WiFi and Bluetooth.
BME280: Sensor for measuring temperature, humidity, and pressure.
DHT11: Temperature and humidity sensor.
MQ-2: Gas sensor to detect smoke, carbon monoxide, and other gases.
Buzzer: Alerting device triggered by the Blynk app.
WiFi: For cloud communication via Blynk.
Pin Configuration
DHT11 Sensor: GPIO 4
MQ-2 Sensor: Analog Pin 34
Buzzer: GPIO 5

**Libraries Required**
BlynkSimpleEsp32: For Blynk integration with ESP32.
Adafruit_Sensor: For interfacing with the BME280 sensor.
Adafruit_BME280: For BME280 sensor library.
DHT: For DHT11 sensor integration.

**Installation Instructions**
Install the Arduino IDE: Ensure you have the Arduino IDE installed on your computer.
Install ESP32 board support: In the Arduino IDE, go to Tools > Board > Board Manager, and install the ESP32 board.

**Install Libraries:**
Go to Sketch > Include Library > Manage Libraries and search for:
Blynk
Adafruit BME280
DHT sensor library
Install these libraries.
Setup WiFi: Replace the ssid and pass variables with your own WiFi credentials.
Upload the Code: Upload the code to your ESP32 board.

**How It Works**
The DHT11 sensor reads the temperature and humidity.
The BME280 sensor measures the temperature, humidity, and air pressure.
The MQ-2 sensor detects smoke and gases, and its data is mapped to a percentage.
The sensor data is sent to the Blynk app every 5 seconds, where you can view the information in real-time.
The Buzzer can be controlled through a button in the Blynk app. Pressing the button triggers the buzzer to turn on or off.

**Blynk App Configuration**
Create a Blynk project and get the Auth Token.
Use the following virtual pins in your Blynk app:
V1: Temperature (from DHT11)
V2: Humidity (from DHT11)
V3: Pressure (from BME280)
V4: MQ-2 Gas Level
Use a Button widget in the Blynk app connected to V34 to control the buzzer.
