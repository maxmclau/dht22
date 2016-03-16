/* MIT license
 *
 * Written by Adafruit Industries
 *
 * Redesigned by Christian Tamburilla for use in (MOA) @ BrunoAir
 */

#ifndef _DHT_H_
#define _DHT_H_

#include "Arduino.h"
#include <Sensor.h>

// Define types of sensors.
#define DHT22 22


class DHT : public Sensor
{
  public:
  
		/*
     * @brief Constructor
     */
   DHT(uint8_t pin);
   ~DHT();
  
   void init(void);
  
		/*
     * @brief Default Readers
     *
     * boolean S == Scale.  True == Fahrenheit; False == Celcius
     */
   float readTemperature(bool S=false, bool force=false);
   float readHumidity(bool force=false);
  
   boolean read(bool force=false);
  
		/*
     * @brief Standard Algorithms
     */
   float convertCtoF(float);
   float convertFtoC(float);
  
   // Using both Rothfusz and Steadman's equations http://www.wpc.ncep.noaa.gov/html/heatindex_equation.shtml
   float computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit=true);

		/**
     * @brief Getters
     */
  uint8_t getTemperatureF();
  uint8_t getTemperatureC();
  uint8_t getHumidity();
  uint8_t getHeatIndex();
  
  /*
   * @brief Sensor.h enums for types
   */
  bool getEvent(sensors_event_t *event);
  void getSensor(sensor_t *sensor);
  
  
 private:
  
  uint8_t data[5];
  
  uint8_t _pin, _type;
  #ifdef __AVR
    // Use direct GPIO access on an 8-bit AVR so keep track of the port and bitmask
    // for the digital pin connected to the DHT.  Other platforms will use digitalRead.
    uint8_t _bit, _port;
  #endif
  
  uint32_t _lastreadtime, _maxcycles;
  bool _lastresult;

  uint32_t expectPulse(bool level);
  
  //Used in getEvent & getSensor
  int32_t _sensorID;
};

class InterruptLock 
{
  public:
   InterruptLock()
   {
    noInterrupts();
   }
   ~InterruptLock() 
   {
    interrupts();
   }

};



#endif
