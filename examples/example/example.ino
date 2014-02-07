#include "POLOLUMC33926.h"

MC33926 left_motor(2,3,4,5);

void setup()
{
  left_motor.init();
}

void loop()
{
  if(!left_motor.fault())
	left_motor.set_pwm(255);
}
