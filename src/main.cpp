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

    // Set motors forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    motorSpeedA = 200;
    motorSpeedB = 240;

    Serial.begin(9600);
    int radius = 25; // in

    int bodywidth = 9; // in
    int outer_radius = radius + bodywidth; //in
    float linear_speed = 14.5; // in/s
    float ci {2*PI*radius};
    float co {2*PI*outer_radius};
    float t_req {co / linear_speed};
    float vi_req {ci / t_req};
    float x {(vi_req + linear_speed) / (2 * linear_speed)};

    // float t_req2 {2 * PI * (radius + 0.5 * bodywidth) / linear_speed};

    Serial.println(t_req);

    float t_init = millis();
    float t_out = millis();
    // while ((t_out - t_init) < t_req * 1000 * 3 * 0.75)
    while ((t_out - t_init) < t_req * 1000 * 3 * 0.5)
    // while ((t_out - t_init) < t_req2 * 1000 * 3) 
    {
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

        analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
        analogWrite(enB, motorSpeedB); // Send PWM signal to motor B

        t_out = millis();
        Serial.println(t_out);
    }
    Serial.println("Out");
}

void loop() {
    // // Base Speed -> straight line 10ft/9s
    // motorSpeedA = 100;
    // motorSpeedB = 120;

    // Base Speed -> straight line 10ft/8.3s
    // motorSpeedA = 200;
    // motorSpeedB = 240;
    motorSpeedA = 0;
    motorSpeedB = 0;

    // int radius = 12; // in

    // int bodywidth = 9; // in
    // int outer_radius = radius + bodywidth; //in
    // float linear_speed = 14.5; // in/s
    // float ci {2*PI*radius};
    // float co {2*PI*outer_radius};
    // float t_req {co / linear_speed};
    // float vi_req {ci / t_req};
    // float x {(vi_req + linear_speed) / (2 * linear_speed)};

    // float t_interval = 500;

    // float t_start = millis();
    // float t = t_start;
    // while ((t - t_start) < t_interval * x)
    // {
    //     digitalWrite(in1, LOW);
    //     digitalWrite(in2, HIGH);
    //     digitalWrite(in3, HIGH);
    //     digitalWrite(in4, LOW);
    //     t = millis();
    // }

    // float t_start2 = millis();
    // t = t_start2;
    // while ((t - t_start2) < t_interval * (1 - x))
    // {
    //     digitalWrite(in1, HIGH);
    //     digitalWrite(in2, LOW);
    //     digitalWrite(in3, HIGH);
    //     digitalWrite(in4, LOW);
    //     t = millis();
    // }

    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}
