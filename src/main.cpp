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

void setup() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    Serial.begin(9600);

    motorSpeedA = 0;
    motorSpeedB = 0;

    // User input
    // -------------------
    int WallDist {9}; // in (optimal 9)
    bool direction {0}; // 0 for left, 1 for right    
    // -------------------

    float linear_speed {14.5}; //in/s
    float t_pullup {1.2 / linear_speed}; //
    float t_rot1 {.9 / linear_speed}; //
    float t_reverse {((WallDist-3) / linear_speed)}; //
    float t_rot2 {.8/ linear_speed};
    float t_turn {(PI/2)/linear_speed};
    
    delay(3000);
    int count = 0;

    //pull up to spot
    while(count <6){
        long unsigned int t {millis()};
        long unsigned int t_beg2 {millis()};
        t = t_beg2;
        while (t-t_beg2<t_pullup*1000){
            motorSpeedA = 200;
            motorSpeedB = 220;
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
    if (direction == true) {
      //rotate counterclockwise 90 degrees (right)
      while(count < 5){
          long unsigned int t {millis()};
          long unsigned int t_beg2 {millis()};
          t = t_beg2;
          while (t-t_beg2<t_rot1*1000){
              motorSpeedA = 200;
              motorSpeedB = 240;
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
    }
    else {
      //rotate clockwise 90 degrees (left)
      while(count < 5){
          long unsigned int t {millis()};
          long unsigned int t_beg2 {millis()};
          t = t_beg2;
          while (t-t_beg2<t_rot1*1000){
              motorSpeedA = 200;
              motorSpeedB = 240;
              digitalWrite(in1, LOW);
              digitalWrite(in2, HIGH);
              digitalWrite(in3, LOW);
              digitalWrite(in4, HIGH);
              t = millis();
              analogWrite(enA, motorSpeedA); 
              analogWrite(enB, motorSpeedB);
          }
          count = count+1;
          Serial.println(count);
      }
    }
    
    count = 0;
    //reverse into spot
    while(count < 1){
        long unsigned int t {millis()};
        long unsigned int t_beg2 {millis()};
        t = t_beg2;
        while (t-t_beg2<t_reverse*1000){
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
    if (direction == true) {
      //rotate clockwise 90 degreess (right)
      while(count < 6){
          long unsigned int t {millis()};
          long unsigned int t_beg2 {millis()};
          t = t_beg2;
          while (t-t_beg2<t_rot2*1000){
              motorSpeedA = 200;
              motorSpeedB = 220;
              digitalWrite(in1, LOW);
              digitalWrite(in2, HIGH);
              digitalWrite(in3, LOW);
              digitalWrite(in4, HIGH);
              t = millis();
              analogWrite(enA, motorSpeedA); 
              analogWrite(enB, motorSpeedB);
          }
          count = count+1;
          Serial.println(count);
      }
    }
    else{
      //rotate counterclockwise 90 degreess (left)
      while(count < 6){
          long unsigned int t {millis()};
          long unsigned int t_beg2 {millis()};
          t = t_beg2;
          while (t-t_beg2<t_rot2*1000){
              motorSpeedA = 200;
              motorSpeedB = 220;
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
    }
    
    motorSpeedA = 0;
    motorSpeedB = 0;
    analogWrite(enA, motorSpeedA);
    analogWrite(enB, motorSpeedB);
    }


void loop() {
    analogWrite(enA, 0);
    analogWrite(enB, 0);    
}
