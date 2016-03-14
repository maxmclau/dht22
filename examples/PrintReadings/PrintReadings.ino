// Example testing sketch for DHT11 humidity/temperature sensor
// Written by ladyada, public domain
// Reduced to barebones by Christian Tamburilla for use in (MOA) @ BrunoAir
// Remember to connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

#include <DHT22.h>
#define DHTPIN 2

// Initialize DHT sensor.
DHT sensor(DHTPIN);

void setup() 
{
  Serial.begin(9600);
  sensor.init();
}

void loop() 
{
  delay(2000);
  
  float h = sensor.getHumidity();
  float t = sensor.getTemperatureC();
  float f = sensor.getTemperatureF();
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
