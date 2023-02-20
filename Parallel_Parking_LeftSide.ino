#include <Arduino.h>

// Motor Driver Connections
#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5
#define button 4
// Definitions
int motorSpeedA = 0;
int motorSpeedB = 0;
int rot_direction {};
int button_pressed {};

// Joystick Connections
#define joyX A1
#define joyY A2

// Potentiometer Connections
#define pot_pin A0

void setup() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    Serial.begin(9600);

    motorSpeedA = 170;
    motorSpeedB = 240;

    // User input
    // -------------------
    int width {1}; // in
    int height {1}; // in
    // -------------------
    float linear_speed {14.5}; //in/s
    float t_wid {width / linear_speed}; //
    float t_hgt {height / linear_speed};
    float t_turn {((3.14159264354)/2)/linear_speed}; //I will not apologize for my approximation of pi :)
    delay(3000);
    int count = 0;
    //pull up to spot
    while(count < 7){
        long unsigned int t {millis()};
        long unsigned int t_beg2 {millis()};
        t = t_beg2;
        while (t-t_beg2<t_wid*1000){
            motorSpeedA = 200;
            motorSpeedB = 240;
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            t = millis();
            analogWrite(enA, motorSpeedA); 
            analogWrite(enB, motorSpeedB);
        }
        count = count+1;
        Serial.println(count);
    }
    count = 0;
    //pivot clockwise 90 degrees    
    while(count < 6){
        long unsigned int t {millis()};
        long unsigned int t_beg2 {millis()};
        t = t_beg2;
        while (t-t_beg2<t_turn*1000){
            motorSpeedA = 0;
            motorSpeedB = 240;
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            t = millis();
            analogWrite(enA, motorSpeedA); 
            analogWrite(enB, motorSpeedB);
        }
        count = count+1;
        Serial.println(count);
    }
    count = 0;
    //reverse into spot
    while(count < 1){
        long unsigned int t {millis()};
        long unsigned int t_beg2 {millis()};
        t = t_beg2;
        while (t-t_beg2<t_wid*1000){
            motorSpeedA = 200;
            motorSpeedB = 240;
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            t = millis();
            analogWrite(enA, motorSpeedA); 
            analogWrite(enB, motorSpeedB);
        }
        count = count+1;
        Serial.println(count);
    }
    count = 0;
    //rotate clockwise 90 degreess
    while(count < 6){
        long unsigned int t {millis()};
        long unsigned int t_beg2 {millis()};
        t = t_beg2;
        while (t-t_beg2<t_wid*1000){
            motorSpeedA = 150;
            motorSpeedB = 190;
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            t = millis();
            analogWrite(enA, motorSpeedA); 
            analogWrite(enB, motorSpeedB);
        }
        count = count+1;
        Serial.println(count);
    }
    //pivot clockwise 90 degrees
    // while(count < 6){
    //     long unsigned int t {millis()};
    //     long unsigned int t_beg2 {millis()};
    //     t = t_beg2;
    //     while (t-t_beg2<t_turn*1000){
    //         motorSpeedA = 0;
    //         motorSpeedB = 200;
    //         digitalWrite(in1, HIGH);
    //         digitalWrite(in2, LOW);
    //         digitalWrite(in3, LOW);
    //         digitalWrite(in4, HIGH);
    //         t = millis();
    //         analogWrite(enA, motorSpeedA); 
    //         analogWrite(enB, motorSpeedB);
    //     }
        
    //     count = count+1;
    //     Serial.println(count);
    // }
    //pull forward
    // count = 0;
    // while(count < 6){
    //     long unsigned int t {millis()};
    //     long unsigned int t_beg2 {millis()};
    //     t = t_beg2;
    //     while (t-t_beg2<t_wid*1000){
    //         motorSpeedA = 200;
    //         motorSpeedB = 240;
    //         digitalWrite(in1, LOW);
    //         digitalWrite(in2, HIGH);
    //         digitalWrite(in3, HIGH);
    //         digitalWrite(in4, LOW);
    //         t = millis();
    //         analogWrite(enA, motorSpeedA); 
    //         analogWrite(enB, motorSpeedB);
    //     }
    //     count = count+1;
    //     Serial.println(count);
    // }
    if (count>5){
        Serial.println("I'm here");
        motorSpeedA = 0;
        motorSpeedB = 0;
        analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
        analogWrite(enB, motorSpeedB);
    }
}

void loop() {
    //Do things
    // analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    // analogWrite(enB, motorSpeedB);
    // Serial.println("I am here");
    
}