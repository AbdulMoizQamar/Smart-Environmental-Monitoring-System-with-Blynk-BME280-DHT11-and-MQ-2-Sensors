#define BLYNK_TEMPLATE_ID "TMPL6NXazSoYL"  // Original Template ID
#define BLYNK_TEMPLATE_NAME "Blynkproject" // Original Template Name
#define BLYNK_AUTH_TOKEN "0oFz7qt-8IsidzmykEql4FgngAWWXQf5"  // Original Auth Token
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

// WiFi credentials
const char* ssid = "";        // Replace with your WiFi SSID
const char* pass = "";       // Replace with your WiFi password

#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // I2C

// DHT11 setup
#define DHTPIN 4         // GPIO pin for the DHT11 sensor
#define DHTTYPE DHT11    // DHT 11
DHT dht(DHTPIN, DHTTYPE);

// MQ-2 setup
#define MQ2_PIN 34       // Analog pin for MQ-2 sensor
#define BUZZER_PIN 5     // GPIO pin for the buzzer

void setup() {
  Serial.begin(9600);
  Serial.println(F("BME280, DHT11, and MQ-2 test"));

  // Connect to Wi-Fi and Blynk
  Blynk.begin(auth, ssid, pass);
  WiFi.mode(WIFI_STA);
  delay(2000);

  bool status;
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  dht.begin();  // Initialize DHT11 sensor
  pinMode(BUZZER_PIN, OUTPUT);  // Set the buzzer pin as an output
  digitalWrite(BUZZER_PIN, LOW); // Ensure the buzzer is off initially

}

// Function to control the buzzer via Blynk button
BLYNK_WRITE(V34) {
  int buttonState = param.asInt(); // Get the state of the button
  if (buttonState == 1) {
    digitalWrite(BUZZER_PIN, HIGH); // Turn the buzzer ON
  } else {
    digitalWrite(BUZZER_PIN, LOW);  // Turn the buzzer OFF
  }
}

void loop() {
  Blynk.run(); // Run Blynk

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float pressure = bme.readPressure() / 100.0F;
 
  // Read MQ-2 values and map them
  int mq2_value = analogRead(MQ2_PIN);
  int mapped_mq2_value = map(mq2_value, 460, 1100, 0, 100); // Adjust raw sensor values accordingly
  mapped_mq2_value = constrain(mapped_mq2_value, 0, 100);    // Ensure the values stay within the desired range

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Send data to Blynk
    Blynk.virtualWrite(V1, temperature);  // Send temperature to Virtual Pin V1
    Blynk.virtualWrite(V2, humidity);     // Send humidity to Virtual Pin V2
    Blynk.virtualWrite(V3, pressure);     // Send pressure to Virtual Pin V3
    Blynk.virtualWrite(V4, mapped_mq2_value); // Send MQ-2 value to Virtual Pin V4
    
    
    delay(5000);  // Send data every 5 seconds

    // Print data to Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" hPa");

    Serial.print("MQ-2 Gas Level: ");
    Serial.print(mapped_mq2_value);
    Serial.println(" %");
  }
}
