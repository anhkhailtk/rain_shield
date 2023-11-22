#ifndef Sensor_h
#define Sensor_h

#include <Arduino.h>

class Sensor
{
public:
    Sensor(u8 inputPin);
    bool read();

private:
    u8 inputPin;
};

#endif