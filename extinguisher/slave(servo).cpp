
#include <Servo.h>
Servo servo_1;
Servo servo_2;
int SERVO_1 = 9;
int SERVO_2 = 11;

void setup() {
  Serial.begin(9600);
  servo_1.attach(SERVO_1);
  servo_2.attach(SERVO_2);
  
}

void loop() {
  if(Serial.available()){
    char SerialReadVal_1 = Serial.read();
    if(SerialReadVal_1 == 'a'){
      servo_1.write(70);
      delay(200);
      servo_1.write(90);
    }
    else if(SerialReadVal_1 == 'd'){
      servo_1.write(120);
      delay(200);
      servo_1.write(90);
    }
 
    else if(SerialReadVal_1 == 'w'){
      servo_2.write(39);
      delay(200);
      servo_2.write(90);
    }
    else if(SerialReadVal_1 == 's'){
      servo_2.write(150);
      delay(200);
      servo_2.write(90);
    }
  }
}  
