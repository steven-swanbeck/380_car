// #include <Arduino.h>

// // Motor Driver Connections
// #define enA 10
// #define in1 9
// #define in2 8
// #define in3 7
// #define in4 6
// #define enB 5
// #define button 4

// // Potentiometer Connections
// #define pot_pin A0

// // Joystick Connections
// #define joy1 A1
// #define joy2 A2

// // misc variables
// int rot_direction {};
// int button_pressed {};

// // function prototypes
// void setMotor1Forward();
// void setMotor2Forward();
// void setMotor1Backward();
// void setMotor2Backward();
// void monitorPotentiometer();



// void setup() {
//     // pin setups
//     pinMode(enA, OUTPUT);
//     pinMode(in1, OUTPUT);
//     pinMode(in2, OUTPUT);
//     pinMode(in3, OUTPUT);
//     pinMode(in4, OUTPUT);
//     pinMode(enB, OUTPUT);
//     pinMode(button, INPUT);

//     // initial motor directions
//     setMotor1Forward();
//     setMotor2Forward();
// }



// void loop() {
//     // potentiometer reading
//     monitorPotentiometer();

//     // button reading w debouncing
//     if (digitalRead(button) == true) 
//     {
//         button_pressed =! button_pressed;
//     }
//     while (digitalRead(button) == true);
//     delay(20);

//     // set motors accordingly
//     if (button_pressed == true && rot_direction == false) {
//         setMotor1Forward();
//         setMotor2Forward();
//         delay(20);
//     } 
//     if (button_pressed == false && rot_direction == true) {
//         setMotor1Backward();
//         setMotor2Backward();
//         delay(20);
//     }

//     int xAxis {analogRead(joy1)};
//     int yAxis {analogRead(joy2)};

//     if (yAxis < 470) {
//         setMotor1Backward();
//         setMotor2Forward();
//     }
// }



// void monitorPotentiometer() {
//     int pot_input {analogRead(pot_pin)};
//     int pwm_output {map(pot_input, 0, 1023, 0, 255)}; 
//     analogWrite(enA, pwm_output);
//     analogWrite(enB, pwm_output);
// }



// void setMotor1Forward() {
//     digitalWrite(in1, LOW);
//     digitalWrite(in2, HIGH);
//     rot_direction = true;
// }

// void setMotor2Forward() {
//     digitalWrite(in3, HIGH);
//     digitalWrite(in4, LOW);
//     rot_direction = true;
// }

// void setMotor1Backward() {
//     digitalWrite(in1, HIGH);
//     digitalWrite(in2, LOW);
//     rot_direction = false;
// }

// void setMotor2Backward() {
//     digitalWrite(in3, LOW);
//     digitalWrite(in4, HIGH);
//     rot_direction = false;
// }