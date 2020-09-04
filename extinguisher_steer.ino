/*
    Name:       extinguisher_steer.ino
    Created:	2020-09-04 오전 11:38:34
    Author:     DESKTOP-QCUIDBD\Kimtaeyoon
*/

#include <Simpletimer.h>
#include <AccelStepper.h>
AccelStepper steer;
SimpleTimer thread1;

const int en_pin = 0;
const int step_pin = 0;
const int dir_pin = 0;


void setup(){
	pinMode(en_pin, OUTPUT);
	pinMode(step_pin, OUTPUT);
	pinMode(dir_pin, OUTPUT);
	
	digitalWrite(en_pin, LOW);
	steer.setSpeed(0);
	
	thread1.setInterval(CommandRefresher, 100);
}


void loop(){
	thread1.run();
	steer.runSpeed();

}
void CommandRefresher(){
	char command = 0;
	if(Serial.available()){
		command = Serial.read();
		switch (command){
		case 'l'://turn left (en -> low, dir correction)
			steer.setSpeed(-500);
			break;
		case 'r'://turn right
			steer.setSpeed(500);
			break;
		case 'e'://stop
			steer.setSpeed(0);
			break;
		}
	}
	command = 0;
}
