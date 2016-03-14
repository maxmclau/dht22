// Example testing sketch for DHT11 humidity/temperature sensor
// Written by ladyada, public domain
// Remember to connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
// Reduced to barebones by Christian Tamburilla for use in (MOA)

#include "DHT.h"

#define DHTPIN 2


// Initialize DHT sensor.
DHT sensor(DHTPIN, DHT22);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 Loading");
  sensor.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = sensor.readHumidity();
  // Read temperature as Celsius (the default)
  float t = sensor.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = sensor.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = sensor.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = sensor.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
}
