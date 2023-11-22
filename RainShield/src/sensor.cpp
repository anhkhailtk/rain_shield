#include "sensor.h"

Sensor::Sensor(u8 inputPin)
{
    this->inputPin = inputPin;
    pinMode(this->inputPin, INPUT_PULLUP);
}
bool Sensor::read()
{
    return digitalRead(this->inputPin);
}