#include <Arduino.h>

// Motor Driver Connections
#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

int motorSpeedA = 0;
int motorSpeedB = 0;



void setup() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // Set motors forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    motorSpeedA = 200;
    motorSpeedB = 240;

    // User input
    // -------------------
    int radius = 12; // in
    // -------------------

    // Calculations
    int bodywidth = 9; // in
    int outer_radius = radius + bodywidth; //in
    float linear_speed = 14.5; // in/s
    float ci {2*PI*radius};
    float co {2*PI*outer_radius};
    float t_req {co / linear_speed};
    float vi_req {ci / t_req};
    float x {(vi_req + linear_speed) / (2 * linear_speed)};

    // Small delay before robot starts driving
    delay(3000);

    // Loop runs for calculated time required to complete three full revolutions, plus a n additional amount
    float t_init = millis();
    float t_out = millis();
    while ((t_out - t_init) < t_req * 1000 * 3 * 0.5 + 2000)
    {
        // Inner loop runs on x fraction of t_interval, moving forward for x*t_interval and backward for (1-x)*t_interval
        float t_interval = 250;

        float t_start = millis();
        float t = t_start;
        while ((t - t_start) < t_interval * x)
        {
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            t = millis();
        }

        float t_start2 = millis();
        t = t_start2;
        while ((t - t_start2) < t_interval * (1 - x))
        {
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            t = millis();
        }

        // Motor speed is constant, only modulating direction to adjust 'average speed'
        analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
        analogWrite(enB, motorSpeedB); // Send PWM signal to motor B

        t_out = millis();
    }
}

void loop() {
    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}
