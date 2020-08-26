// 
/*
    Name:       detector_mcu.ino
    Created:	2020-08-26-수요일 오전 9:32:13
    Author:     DESKTOP-VLNP3AE\tae
*/
#pragma once
const int MQ2_pin = 0;//Flammability
const int MQ7_pin = 0;//CO
const int MQ9_pin = 0;//CO2

void detect(int sensor_pin);
void setup() {
	Serial.begin(9600);
	pinMode(MQ2_pin, INPUT);
	pinMode(MQ7_pin, INPUT);
	pinMode(MQ9_pin, INPUT);
	
}


void loop() {
	detect(2);
	delay(1000);
	detect(7);
	delay(1000);
	detect(8);
	delay(1000);
}
void detect(int sensor_pin){
	int value = analogRead(sensor_pin);
	if(value >= 1000){
		Serial.write(sensor_pin);	
	}
}