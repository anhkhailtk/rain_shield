#include <Arduino.h>
#include "motor.h"
#include "sensor.h"
#include "def.h"

// put function declarations here:
Motor *motor_1;
Motor *motor_2;
Sensor *end_stop_1_top;
Sensor *end_stop_1_bot;
Sensor *end_stop_2_top;
Sensor *end_stop_2_bot;
Sensor *rain_sensor;

void setup()
{
  // put your setup code here, to run once:
  motor_1 = new Motor(MOTOR_1_PIN_A, MOTOR_1_PIN_B);
  motor_2 = new Motor(MOTOR_2_PIN_A, MOTOR_2_PIN_B);
  end_stop_1_top = new Sensor(END_STOP_1_TOP_PIN);
  end_stop_1_bot = new Sensor(END_STOP_1_BOT_PIN);
  end_stop_2_top = new Sensor(END_STOP_2_TOP_PIN);
  end_stop_2_bot = new Sensor(END_STOP_2_BOT_PIN);
  rain_sensor = new Sensor(RAIN_SENSOR_PIN);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (!rain_sensor->read()) // it's raining
  {
    if (end_stop_1_top->read())
    {
      motor_1->run(SHIELD_CLOSE, 100);
    }
    else
    {
      motor_1->stop();
    }

    if (end_stop_2_top->read())
    {
      motor_2->run(SHIELD_CLOSE, 100);
    }
    else
    {
      motor_2->stop();
    }
  }
  else // it's not raining
  {
    if (end_stop_1_bot->read())
    {
      motor_1->run(SHIELD_OPEN, 100);
    }
    else
    {
      motor_1->stop();
    }

    if (end_stop_2_bot->read())
    {
      motor_2->run(SHIELD_OPEN, 100);
    }
    else
    {
      motor_2->stop();
    }
  }
}

// put function definitions here:
