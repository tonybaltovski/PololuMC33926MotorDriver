#ifndef POLOLU_MC33926_h
#define POLOLU_MC33926_h

#include <Arduino.h>

typedef unsigned char uchar;

class MC33926
{
	public: 
	// Constructors
	#if defined(__MK20DX128__) || defined(__MK20DX256__) || defined(_SAM3XA_)
	//Teensy 3.X and Arduino Due analog pins cannot take 5V
	MC33926(uchar DIR1, uchar DIR2,uchar PWM, uchar SF); 
	#else
	MC33926(uchar DIR1, uchar DIR2,uchar PWM, uchar SF, uchar FB); 
	#endif		
	// Public functions
	void init(); // Initializes the pins
	void set_pwm(int desired_pwm);  //Sets the desired PWM value
	bool fault();  // Checks for an fault and returns true if there is one
	#if !defined(__MK20DX128__) || !defined(__MK20DX256__) || !defined(_SAM3XA_)
	int motor_current();
	#endif

	private:
	// Private variables
	uchar DIR1_;
	uchar DIR2_;
	uchar PWM_;
	uchar SF_;
	#if !defined(__MK20DX128__) || !defined(__MK20DX256__) || !defined(_SAM3XA_)
	uchar FB_;
	#endif
};

#endif
