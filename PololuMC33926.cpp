#include "POLOLUMC33926.h"


MC33926::MC33926(int DIR1,int DIR2, int PWM, int SF)
{
DIR1_ = DIR1;
DIR2_ = DIR2;
PWM_ = PWM;
SF_ = SF;
}


void MC33926::init()
{
  pinMode(DIR1_,OUTPUT);
  pinMode(DIR2_,OUTPUT);
  pinMode(PWM_,OUTPUT);
  pinMode(SF_,INPUT);
}

void MC33926::set_pwm(int desired_pwm)
{
  if (desired_pwm < 0)
  {
    digitalWrite(DIR1_,LOW);
    digitalWrite(DIR2_,HIGH);
	if (desired_pwm < -255)
		desired_pwm = -255;
	analogWrite(PWM_,-1*desired_pwm);
  }

  else
  {
    digitalWrite(DIR2_,LOW);
    digitalWrite(DIR1_,HIGH);
	if (desired_pwm > 255)
		desired_pwm = 255;
	analogWrite(PWM_,desired_pwm);

  }
}

bool MC33926::fault()
{
  return !digitalRead(SF_); //Flip logic
}
