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
    int width {24}; // in
    int height {36}; // in
    // -------------------
    float linear_speed {14.5}; //in/s
    float t_wid {width / linear_speed};
    float t_hgt {height / linear_speed};
    float t_turn {(6*PI/2)/linear_speed};
    delay(3000);
    int count = 0;
    while(count < 6){

        long unsigned int t_beg1 {millis()};
        long unsigned int t {millis()};
        while (t-t_beg1<t_wid*1000){
            motorSpeedA = 210;
            motorSpeedB = 240;
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            t = millis();
            analogWrite(enA, motorSpeedA); 
            analogWrite(enB, motorSpeedB);
        }
        long unsigned int t_beg2 {millis()};
        t = t_beg2;
        while (t-t_beg2<t_turn*1000){
            motorSpeedA = 200;
            motorSpeedB = 0;
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            t = millis();
            analogWrite(enA, motorSpeedA); 
            analogWrite(enB, motorSpeedB);
        }
        long unsigned int t_beg3 {millis()};
        t = t_beg3;
        while (t-t_beg3<t_hgt*1000){
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
        long unsigned int t_beg4 {millis()};
        t = t_beg4;
        while (t-t_beg4<t_turn*1000){
            motorSpeedA = 200;
            motorSpeedB = 0;
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
    if (count>5){
        motorSpeedA = 0;
        motorSpeedB = 0;
        analogWrite(enA, motorSpeedA);
        analogWrite(enB, motorSpeedB);
    }
}

void loop() {
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}
