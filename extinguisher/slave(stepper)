const int step_pin = 4;

const int go_dir_pin = 5;
const int go_en_pin = 6;
const int turn_dir_pin = 7;
const int turn_en_pin = 8;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(step_pin, OUTPUT);

    pinMode(go_dir_pin, OUTPUT);
    pinMode(go_en_pin, OUTPUT);
    pinMode(turn_dir_pin, OUTPUT);
    pinMode(turn_en_pin, OUTPUT);
    digitalWrite(go_en_pin, HIGH);
    digitalWrite(turn_en_pin, HIGH);
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(step_pin, HIGH);
    delay(1);
    digitalWrite(step_pin, LOW);
    if(Serial.available()){
        char command = Serial.read();
        switch(command){
            case '1'://go
                digitalWrite(go_dir_pin, HIGH);
                digitalWrite(go_en_pin, LOW);
                delay(1);
                break;
            case '2'://back
                digitalWrite(go_dir_pin, LOW);
                digitalWrite(go_en_pin, LOW);
                break;
            case '3'://left
                digitalWrite(turn_dir_pin, HIGH);
                digitalWrite(turn_en_pin, LOW);
                break;
            case '4'://right
                digitalWrite(turn_dir_pin, LOW);
                digitalWrite(turn_en_pin, LOW);
                break;
            
            case '5':
                digitalWrite(go_en_pin, HIGH);
                break;
            case '6':
                digitalWrite(go_en_pin, HIGH);
                break;
            case '7':
                digitalWrite(turn_en_pin, HIGH);
                break;
            case '8':
                digitalWrite(turn_en_pin, HIGH);
                break;
        }
    }
    delay(1);
}
