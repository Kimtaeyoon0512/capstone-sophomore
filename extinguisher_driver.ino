/*
    Name:       extinguisher_driver.ino
    Created:	2020-09-04 오후 12:27:09
    Author:     DESKTOP-QCUIDBD\Kimtaeyoon
*/
#include <SimpleTimer.h>
#include <AccelStepper.h>

const int en_pin = 0;
const int step_pin = 0;
const int dir_pin = 0;

SimpleTimer thread1;
AccelStepper driver(1, step_pin, dir_pin);

void setup(){
	Serial.begin(38400);
	pinMode(en_pin, OUTPUT);
	pinMode(step_pin, OUTPUT);
	pinMode(dir_pin, OUTPUT);
	
	digitalWrite(en_pin, LOW);
	driver.setSpeed(0);
}

void loop(){
	thread1.run();
	driver.runSpeed();

}

void CommandRefresher(){
	char command = 0;
	if(Serial.available()){
		command = Serial.read();
		switch (command){
		case 'g'://go
			driver.setSpeed(500);
			break;
		case 'b'://back
			driver.setSpeed(-500);
			break;
		case 'e'://stop
			driver.setSpeed(0);
			break;
		}
	}
	command = 0;
}
