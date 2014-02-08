#ifndef POLOLU_MC33926_h
#define POLOLU_MC33926_h

#include <Arduino.h>

class MC33926
{
	public: 
	// Constructors
	MC33926(int DIR1, int DIR2,int PWM, int SF); 
	// Public functions
	void init(); // Initializes the pins
	void set_pwm(int desired_pwm);  //Sets the desired PWM value
	bool fault();  // Checks for an fault and returns true if there is one
    
	private:
	// Private variables
	int DIR1_;
	int DIR2_;
	int PWM_;
	int SF_;
};

#endif
