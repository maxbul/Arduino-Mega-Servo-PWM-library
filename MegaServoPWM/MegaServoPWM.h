#ifndef MegaServoPWM_h__
#define MegaServoPWM_h__

#if !defined(ARDUINO_AVR_MEGA2560)
#error "Only Mega2560 MCU supported."
#endif

#include <Arduino.h>
#define MIN_PULSE_MICROS       500	
#define MAX_PULSE_MICROS      2500	
#define INITIAL_PULSE_MICROS     0	//default value when servo is attached
#define TIMER_TOP		40000	//the timer TOP value (for creating 50Hz)

#define MAX_SERVOS_NUMER				6	//up to 6 servos supported

class MegaServoPWM
{
public:
	MegaServoPWM();
	void attach(uint8_t parPin);				
	void detach();						
	void writeMicroseconds(int value);	//write pulse width in microseconds 
private:
	void _initTimer1();
	void _initTimer3();
	void _initTimer4();
	void _initTimer5();
	
	void _initialize(int parPin);
	boolean attached = false;
	int myPin = 0;					
};

#endif // MegaServoPWM_h__


