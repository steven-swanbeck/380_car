#include <Arduino.h>

// Motor Driver Connections
#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5
#define button 4

int motorSpeedA = 0;
int motorSpeedB = 0;

// Joystick Connections
#define joyX A1
#define joyY A2

// Potentiometer Connections
#define pot_pin A0

// misc variables
int rot_direction {};
int button_pressed {};

void setup() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // initial motor directions
    //   setMotorsForward();
    Serial.begin(9600);
}

void loop() {
    int xAxis = analogRead(A1); // Read Joysticks X-axis
    int yAxis = analogRead(A2); // Read Joysticks Y-axis
    Serial.println(xAxis);
    Serial.println(yAxis);


  // Y-axis used for forward and backward control
    if (yAxis > 530) {
    // Set Motor A backward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        // Set Motor B backward
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
        motorSpeedA = map(yAxis, 530, 1023, 0, 255);
        motorSpeedB = map(yAxis, 530, 1023, 0, 255);
    }
    else if (yAxis < 480) {
    // Set Motor A forward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        // Set Motor B forward
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
        motorSpeedA = map(yAxis, 480, 0, 0, 255);
        motorSpeedB = map(yAxis, 480, 0, 0, 255);
    }
  // If joystick stays in middle the motors are not moving
    else {
        motorSpeedA = 0;
        motorSpeedB = 0;
    }

  // X-axis used for left and right control
    if (xAxis < 480) {
        // Convert the declining X-axis readings from 470 to 0 into increasing 0 to 255 value
        int xMapped = map(xAxis, 480, 0, 0, 255);
        // Move to left - decrease left motor speed, increase right motor speed
        motorSpeedA = motorSpeedA - xMapped;
        motorSpeedB = motorSpeedB + xMapped;
        // Confine the range from 0 to 255
        if (motorSpeedA < 0) {
            motorSpeedA = 0;
        }
        if (motorSpeedB > 255) {
            motorSpeedB = 255;
        }
    }
    if (xAxis > 530) {
    // Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
        int xMapped = map(xAxis, 530, 1023, 0, 255);
        // Move right - decrease right motor speed, increase left motor speed
        motorSpeedA = motorSpeedA + xMapped;
        motorSpeedB = motorSpeedB - xMapped;
        // Confine the range from 0 to 255
        if (motorSpeedA > 255) {
            motorSpeedA = 255;
        }
        if (motorSpeedB < 0) {
            motorSpeedB = 0;
        }
    }
    // Prevent buzzing at low speeds (Adjust according to your motors. My motors couldn't start moving if PWM value was below value of 70)
    if (motorSpeedA < 70) {
        motorSpeedA = 0;
    }
    if (motorSpeedB < 70) {
        motorSpeedB = 0;
    }
    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}



