// Example testing sketch for DHT11 humidity/temperature sensor
// Written by ladyada, public domain
// Remember to connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
// Reduced to barebones by Christian Tamburilla for use in (MOA)

#include <DHT22.h>

#define DHTPIN 2


// Initialize DHT sensor.
DHT sensor(DHTPIN, DHT22);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 Loading");
  sensor.init();
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

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(sensor.computeHeatIndex(f, h));
  Serial.print(" *C ");
  Serial.print(sensor.computeHeatIndex(t, h, false));
  Serial.println(" *F");
}
