/*Q0.7 Pin 6 Timer 4 SERVO 1
Q1.0 Pin 8 Timer 4 SERVO 2
Q0.5 Pin 4 Timer 0
Q0.6 Pin 5 Timer 3 TBD SERVO 3?
Q1.1 Pin 10 Timer 2
Q1.2Pin 11 Timer 2
*/
#include <MegaServoPWM.h>

//for hobby servo range is  180° .. 0° (2500us to 500us)
#define MIN_MICROS 1400
#define MAX_MICROS 1600
//pin 2 Timer 3, channel B
//pin 3 Timer 3, channel C

//pin 6 Timer4, channel A
//pin 7 Timer4, channel B
//pin 8 Timer4, channel C

//pin 45 Timer5, channel B
//pin 46 Timer5, channel C

//MegaServoPWM myServo_2; //creating a servo object (any custom name could be used)
//MegaServoPWM myServo_3;
MegaServoPWM myServo_5;
MegaServoPWM myServo_6;
//MegaServoPWM myServo_7;
MegaServoPWM myServo_8;
//MegaServoPWM myServo_11;
//MegaServoPWM myServo_12;
//MegaServoPWM myServo_13;
//MegaServoPWM myServo_44;
//MegaServoPWM myServo_45;
//MegaServoPWM myServo_46;

uint32_t valueMicros = 0; //variable that contains the microseconds

void setup() {
	

	//myServo_2.attach(2); //attaches the servo to pin 2
	//myServo_3.attach(3);
	myServo_5.attach(5);
	myServo_6.attach(6);
	//myServo_7.attach(7);
	myServo_8.attach(8);
	//myServo_11.attach(11);
	//myServo_12.attach(12);
	//myServo_13.attach(13);
	//myServo_44.attach(44);
	//myServo_45.attach(45);
	//myServo_46.attach(46);
}

//=========================================
//
//=========================================
void setAll(uint32_t parMicros){
	
	//myServo_2.writeMicroseconds(parMicros);	//writes the value of valueMicros to the servo
	//myServo_3.writeMicroseconds(parMicros);
	//myServo_5.writeMicroseconds(parMicros);
	myServo_6.writeMicroseconds(parMicros);
	//myServo_7.writeMicroseconds(parMicros);
	myServo_8.writeMicroseconds(parMicros);
	//myServo_11.writeMicroseconds(parMicros);
	//myServo_12.writeMicroseconds(parMicros);
	//myServo_13.writeMicroseconds(parMicros);
	//myServo_44.writeMicroseconds(parMicros);
	//myServo_45.writeMicroseconds(parMicros);
	//myServo_46.writeMicroseconds(parMicros);
}
void loop() {
  for (valueMicros = MIN_MICROS; valueMicros < MAX_MICROS; valueMicros++){
   setAll(valueMicros); 
    delay(10);
  }
  for (valueMicros = MAX_MICROS; valueMicros > MIN_MICROS; valueMicros--){
   setAll(valueMicros);
    delay(10);
  }
  
  for (valueMicros = MIN_MICROS; valueMicros < MAX_MICROS; valueMicros+=20){
	  setAll(valueMicros);
	  delay(5000);
  }
  for (valueMicros = MAX_MICROS; valueMicros > MIN_MICROS; valueMicros-=50){
	  setAll(valueMicros);
	  delay(5000);
  }
}
