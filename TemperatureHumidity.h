#ifndef _TEMPERATURE_HUMIDITY_H
#define _TEMPERATURE_HUMIDITY_H
#include "OLED.h"
#include "Ultrasonic.h"
//#include <dht.h>
//#define dht_apin A1
//dht DHT;
class TemperatureHumidity {

    int _temperatureH;

  public:
    TemperatureHumidity(int temperatureH) {
      _temperatureH = temperatureH;
    }
    /*
    void Humidity() {
      DHT.read11(dht_apin);

      Serial.print("Current humidity = ");
      Serial.print(DHT.humidity);
      Serial.print("%  ");
      Serial.print("Current temperature = ");
      Serial.print(DHT.temperature);
      Serial.println("C  ");
      delay(5000);
    }
    */
};

#endif // _TEMPERATURE_HUMIDITY_H
