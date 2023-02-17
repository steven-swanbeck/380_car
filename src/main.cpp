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

    motorSpeedA = 200;
    motorSpeedB = 240;

    // User input
    // -------------------
    int width {3}; // in
    int height {3}; // in
    // -------------------
    float linear_speed {14.5};
    float t_wid {width / linear_speed};
    float t_hgt {height / linear_speed};
    


    // initial motor directions
    // setMotorsForward();
    Serial.begin(9600);
}

void loop() {
    //Do things
    


}
