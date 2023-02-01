#include <Arduino.h>

// Motor Driver Connections
#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5
#define button 4

// Joystick Connections
#define joyX A1
#define joyY A2

// Potentiometer Connections
#define pot_pin A0

// misc variables
int rot_direction {};
int button_pressed {};

// function prototypes
void setMotorsForward();
void setMotorsBackward();
void monitorPotentiometer();

int xVal = 0;
int yVal = 0;



void setup() {
    // pin setups
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(button, INPUT);
    

    // initial motor directions
    setMotorsForward();
    Serial.begin(9600);
}



void loop() {
    // // int pot_input {analogRead(pot_pin)};
    // // int pwm_output {map(pot_input, 0, 1023, 0, 255)}; 
    // analogWrite(enA, 125);
    // analogWrite(enB, 125);

    // potentiometer reading
    // monitorPotentiometer();
    
    //Joystick reading
    xVal = analogRead(joyX);
    yVal = analogRead(joyY);
    xVal = map(xVal, 0, 1023, 0, 255);
    yVal = map(yVal, 0, 1023, 0, 255);
    Serial.println(xVal);
    Serial.println(yVal);
    // delay(200);
    if (xVal == 121 && yVal == 129){
        analogWrite(enA, 0);
        analogWrite(enB, 0);
    }
    else if (yVal >= 120 && yVal <= 140){
        setMotorsForward();
        analogWrite(enA, ((xVal))); 
        analogWrite(enB, ((255-xVal)));
    }
    else if (yVal < 120){
        setMotorsForward();
        if (xVal >= 110 && xVal <= 130){
            analogWrite(enA, ((129-yVal))); //Set both motors to the same speed: Half maximum minus intensity
            analogWrite(enB, ((129-yVal)));
        }
        else{
            // analogWrite(enA, (2*(129-yVal)-3)*(1-(255-xVal)/255)); //If x = 255, right speed maximum. If x = 0, right speed = 0. 
            // analogWrite(enB, (2*(129-yVal)-3)*((255-xVal)/255)); //If x = 255, left speed = 0. If x = 0, left speed = maximum
            analogWrite(enA, 0);
            analogWrite(enB, 0);
        }
    }
    else if (yVal > 140){
        setMotorsBackward();
        if (xVal >= 110 && xVal <= 130){
            analogWrite(enA, ((yVal-129)));
            analogWrite(enB, ((yVal-129)));
        }
        else{
            // analogWrite(enA, ((2*(yVal-129)+3)*(1-(255-xVal)/255))); //If x = 255, right speed maximum. If x = 0, right speed = 0. 
            // analogWrite(enB, ((2*(yVal-129)+3)*((255-xVal)/255))); //If x = 255, left speed = 0. If x = 0, left speed = maximum
            analogWrite(enA, 0);
            analogWrite(enB, 0);    
        }
    }

    // If y > 128, backwards
    // if y < 128, fwd
    // if y = 128, turn in place
    // if x > 128, steer right
    // if x < 128, steer left
    // if x = 128, left speed = right speed
    // if x = y = 128, do nothing


    


    // // button reading w debouncing
    // if (digitalRead(button) == true) 
    // {
    //     button_pressed =! button_pressed;
    // }
    // while (digitalRead(button) == true);
    // delay(20);

    // // set motors accordingly
    // if (button_pressed == true && rot_direction == false) {
    //     setMotorsForward();
    //     delay(20);
    // } 
    // if (button_pressed == false && rot_direction == true) {
    //     setMotorsBackward();
    //     delay(20);
    // }
}


// void monitorPotentiometer() {
//     int pot_input {analogRead(pot_pin)};
//     int pwm_output {map(pot_input, 0, 1023, 0, 255)}; 
//     float pwm_range = pwm_output/255;
//     // analogWrite(enA, pwm_output);
//     // analogWrite(enB, pwm_output);
// }



void setMotorsForward() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    rot_direction = true;
}



void setMotorsBackward() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    rot_direction = false;
}
