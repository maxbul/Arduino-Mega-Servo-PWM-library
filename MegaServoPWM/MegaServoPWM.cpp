#if defined(ARDUINO_AVR_MEGA2560)
#include <MegaServoPWM.h>

uint8_t usageCounterTimer1=0;
uint8_t usageCounterTimer3=0;
uint8_t usageCounterTimer4=0;
uint8_t usageCounterTimer5=0;

MegaServoPWM::MegaServoPWM()
{
	
}

//=========================================
//
//=========================================

void MegaServoPWM::_initTimer1(){
	if (usageCounterTimer1==0){
		//resetting the control register A and B:
		TCCR1A = 0x0;
		TCCR1B = 0x0;
	}
	usageCounterTimer1++;
	
	//setting the prescaler to 8 (2MHz):
	TCCR1B |= (1 << CS11);

	//==setting the waveform generation mode to 14 (TOP on ICR):
	TCCR1A |= (1 << WGM11);
	//==setting the waveform generation mode to 15:
	//TCCR1A |= (1 << WGM11) | (1 << WGM10);
	TCCR1B |= (1 << WGM12) | (1 << WGM13);

	//setting the the TOP value:
	//OCR1A = TIMER_TOP; //results in 50Hz at 2MHz Clock
	ICR1 = TIMER_TOP; //results in 50Hz at 2MHz Clock

}
//=========================================
//
//=========================================
void MegaServoPWM::_initTimer3(){
	if (usageCounterTimer3==0){
		//resetting the control register A and B:
		TCCR3A = 0x0;
		TCCR3B = 0x0;
	}
	usageCounterTimer3++;
	
	//setting the prescaler to 8 (2MHz):
	TCCR3B |= (1 << CS31);

	//==setting the waveform generation mode to 14 (TOP on ICR):
	TCCR3A |= (1 << WGM31);
	//==setting the waveform generation mode to 15:
	//TCCR3A |= (1 << WGM31) | (1 << WGM30);
	TCCR3B |= (1 << WGM32) | (1 << WGM33);

	//setting the the TOP value:
	//OCR3A = TIMER_TOP; //results in 50Hz at 2MHz Clock
	ICR3 = TIMER_TOP; //results in 50Hz at 2MHz Clock

}

//=========================================
//
//=========================================
void MegaServoPWM::_initTimer4(){
	if (usageCounterTimer4==0){
		//resetting the control register A and B:
		TCCR4A = 0x0;
		TCCR4B = 0x0;
	}
	usageCounterTimer4++;

	//setting the prescaler to 8 (2MHz):
	TCCR4B |= (1 << CS41);

	//setting the waveform generation mode to 14 (TOP on ICRx):
	TCCR4A |= (1 << WGM41);
	
	////setting the waveform generation mode to 15:
	//TCCR4A |= (1 << WGM41) | (1 << WGM40);
	TCCR4B |= (1 << WGM42) | (1 << WGM43);
	ICR4 = TIMER_TOP; //results in 50Hz at 2MHz Clock
	//OCR4A = TIMER_TOP; //results in 50Hz at 2MHz Clock
}

//=========================================
//
//=========================================
void MegaServoPWM::_initTimer5(){
	if (usageCounterTimer5==0){
		TCCR5A = 0x0;
		TCCR5B = 0x0;
	} 
	usageCounterTimer5++;
	//setting the prescaler to 8 (2MHz):
	TCCR5B |= (1 << CS51);

	//setting the waveform generation modes:
	//TCCR5A |= (1 << WGM51) | (1 << WGM50); //mode 15
	TCCR5A |= (1 << WGM51); //mode 14  (channel A, ICR on TOP)
	TCCR5B |= (1 << WGM52) | (1 << WGM53);

	//setting the the TOP value:
	//OCR5A = TIMER_TOP; //results in 50Hz at 2MHz Clock
	ICR5 = TIMER_TOP; //results in 50Hz at 2MHz Clock
}

void MegaServoPWM::_initialize(int parPin)
{
	switch (parPin)
	{
	case 2:
		_initTimer3();
		//setting the output to non inverted:
		TCCR3A |= (1 << COM3B1);
		OCR3B = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 3:
		_initTimer3();
		//setting the output to non inverted:
		TCCR3A |= (1 << COM3C1);
		OCR3C = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 5:
		_initTimer3();
		//setting the output to non inverted:
		TCCR3A |= (1 << COM3A1);
		OCR3A = INITIAL_PULSE_MICROS; //setting the pulse width
	break;
	
	case 6:
		_initTimer4();
		//setting the output to non inverted:
		TCCR4A |= (1 << COM4A1);
		OCR4A = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 7:
		_initTimer4();
		//setting the output to non inverted:
		TCCR4A |= (1 << COM4B1);
		OCR4B = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 8:	
		_initTimer4();
		//setting the output to non inverted:
		TCCR4A |= (1 << COM4C1);
		OCR4C = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 11:
		_initTimer1();
		//setting the output to non inverted:
		TCCR1A |= (1 << COM1A1);
		OCR1A = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 12:
		_initTimer1();
		//setting the output to non inverted:
		TCCR1A |= (1 << COM1B1);
		OCR1B = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 13:
		_initTimer1();
		//setting the output to non inverted:
		TCCR1A |= (1 << COM1C1);
		OCR1C = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 44:
		_initTimer5();
		//setting the output to non inverted:
		TCCR5A |= (1 << COM5C1);
		OCR5C = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 45:
		_initTimer5();
		//setting the output to non inverted:
		TCCR5A |= (1 << COM5B1);
		OCR5B = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	case 46:
		_initTimer5();
		//setting the output to non inverted:
		TCCR5A |= (1 << COM5A1);
		OCR5A = INITIAL_PULSE_MICROS; //setting the pulse width
		break;
	default:
		return; //any other pin cannot be used
	}//\ switch()
		
	pinMode(parPin, OUTPUT);
	myPin=parPin;
	attached =true;
}

void MegaServoPWM::detach()
{
 	pinMode(myPin, INPUT);
	attached=false;
}


void MegaServoPWM::writeMicroseconds(int parMicros)
{
	int value=parMicros*2;
	if (attached) {
		switch (myPin)
		{
		case 2:
			OCR3B = 0x0;
			OCR3B = value;
			break;
		case 3:
			OCR3C = 0x0;
			OCR3C = value;
			break;
		case 5:
			OCR3A = 0x0;
			OCR3A = value;
		break;
		case 6:
			OCR4A = 0x0;
			OCR4A = value;
			break;
		case 7:
			OCR4B = 0x0;
			OCR4B = value;
			break;
		case 8:
			OCR4C = 0x0;
			OCR4C = value;
			break;
		case 11:
			OCR1A = 0x0;
			OCR1A = value;
			break;
		case 12:
			OCR1B = 0x0;
			OCR1B = value;
			break;
		case 13:
			OCR1C = 0x0;
			OCR1C = value;
			break;
		case 44:
			OCR5C = 0x0;
			OCR5C = value;
			break;
		case 45:
			OCR5B = 0x0;
			OCR5B = value;
			break;	
		case 46:
			OCR5A = 0x0;
			OCR5A = value;
			break;
		default:
			return;
		}//\ switch()
	}//\if (attached) ...
}

void MegaServoPWM::attach(uint8_t parPin){
	_initialize(parPin);
}
#endif
