#ifndef POLOLU_MC33926_h
#define POLOLU_MC33926_h

#include <Arduino.h>

class MC33926
{
  public: 
    MC33926(int DIR1, int DIR2,int PWM, int SF); 
    void init(); 
    void set_pwm(int desired_pwm);
    bool fault();
    
  private:
    int DIR1_;
    int DIR2_;
    int PWM_;
    int SF_;
};

#endif
