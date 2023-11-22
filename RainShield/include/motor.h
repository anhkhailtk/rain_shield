#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor
{
public:
    Motor(u8 pinA, u8 pinB);
    void run(bool dir, u8 speed);
    void stop();
private:
    u8 pinA;
    u8 pinB;
};

#endif