#include "motor.h"

Motor::Motor(u8 pinA, u8 pinB)
{
    this->pinA = pinA;
    this->pinB = pinB;
    pinMode(this->pinA, OUTPUT);
    pinMode(this->pinB, OUTPUT);
    digitalWrite(this->pinA, LOW);
    digitalWrite(this->pinB, LOW);
}
void Motor::run(bool dir, u8 speed)
{
    if (dir)
    {
        analogWrite(this->pinA, speed * 255 / 100);
        digitalWrite(this->pinB, LOW);
    }
    else
    {
        analogWrite(this->pinB, speed * 255 / 100);
        digitalWrite(this->pinA, LOW);
    }
}
void Motor::stop()
{
    digitalWrite(this->pinA, LOW);
    digitalWrite(this->pinB, LOW);
}