#ifndef POLOLU_MC33926_h
#define POLOLU_MC33926_h

#include <Arduino.h>

class MC33926
{
	public: 
	// Constructors
	#if defined(__MK20DX128__) || defined(__MK20DX256__) || defined(_SAM3XA_)
		//Teensy 3.X and Arduino Due analog pins cannot take 5V
		MC33926(int DIR1, int DIR2,int PWM, int SF); 
	#else
		MC33926(int DIR1, int DIR2,int PWM, int SF, int FB); 
	#endif		
	// Public functions
	void init(); // Initializes the pins
	void set_pwm(int desired_pwm);  //Sets the desired PWM value
	bool fault();  // Checks for an fault and returns true if there is one
	#if !defined(__MK20DX128__) || !defined(__MK20DX256__) || !defined(_SAM3XA_)
		float motor_current();
	#endif

	private:
	// Private variables
	int DIR1_;
	int DIR2_;
	int PWM_;
	int SF_;
	#if !defined(__MK20DX128__) || !defined(__MK20DX256__) || !defined(_SAM3XA_)
		int FB_;
	#endif
};

#endif
