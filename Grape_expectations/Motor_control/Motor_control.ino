// #include "arduino_secrets.h"

#include "Motor_control.h"


// Motor A connections
const int enA = 11;  
const int in1 = 12;
const int in2 = 13;
 
// Motor B connections
const int enB = 6; 
const int in3 = 7;
const int in4 = 8;
 
// Set the speed (0 = off and 255 = max speed)
const int motorSpeed = 255;

volatile int state = 0;

void motor_setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
  // Set the motor speed
  analogWrite(enA, motorSpeed); 
  analogWrite(enB, motorSpeed); 
}
 
/*   
 *  Forwards, backwards, right, left, stop.
 */
void go_forward(int dist) {
  Serial.println("Forward");
  int driveTime = dist * 10;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(driveTime);
  stop_all();
}
void go_backwards(int dist) {
  Serial.println("Backward");
  int driveTime = dist * 10;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(driveTime);
  stop_all();
}
void go_right(int degrees) {
  Serial.println("Right");
  int pivotTime = degrees * 10;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(pivotTime);
  stop_all();
}
void go_left(int degrees) {
  Serial.println("Left");
  int pivotTime = degrees * 10;
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(pivotTime);
  stop_all();
}
void stop_all() {
  Serial.println("Stop All");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void pivot_cw() {
  Serial.println("Pivot CW");
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
}


void pivot_ccw() {
  Serial.println("Pivot CCW");
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW);
}
