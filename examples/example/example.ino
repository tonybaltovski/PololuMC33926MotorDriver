#include "POLOLUMC33926.h"

//
MC33926 left_motor(2,3,4,5);
MC33926 right_motor(12,11,10,9);

void setup()
{
  left_motor.init();
  right_motor.init();
}

void loop()
{
	if(!left_motor.fault()  || !right_motor.fault() )
		for (int x = 0; x < 256;x++)
		{
			left_motor.set_pwm(x);
			right_motor.set_pwm(-x);
			delay(25);
		}
	}
}
