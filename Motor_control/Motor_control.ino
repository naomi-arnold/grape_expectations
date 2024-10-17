// #include "arduino_secrets.h"

#include "Motor_control.h"

// Motor A connections
const int enA = 3;  
const int in1 = 5;
const int in2 = 6;
 
// Motor B connections
const int enB = 11; 
const int in3 = 9;
const int in4 = 10;
 
// Set the speed (0 = off and 255 = max speed)
const int motorSpeed = 50;

volatile int state = 0;

void motor_setup() {
  Serial.println("in motor setup");
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
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

}
 
/*   
 *  Forwards, backwards, right, left, stop.
 */
void go_forward(int dist) {
  Serial.println("Forward");
  int driveTime = dist * 10;

  analogWrite(in1, motorSpeed);
  digitalWrite(in2, LOW);
  analogWrite(in3, motorSpeed);
  digitalWrite(in4, LOW);
  
  delay(driveTime);
  stop_all();
}

void go_backwards(int dist) {
  Serial.println("Backward");
  int driveTime = dist * 10;

  digitalWrite(in1, LOW);
  analogWrite(in2, motorSpeed);
  digitalWrite(in3, LOW);
  analogWrite(in4, motorSpeed);

  delay(driveTime);
  stop_all();
}

void go_right(int degrees) {
  Serial.println("Right");
  int pivotTime = degrees * 10;

  analogWrite(in1, motorSpeed);
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
  analogWrite(in3, motorSpeed);
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

  analogWrite(in1, motorSpeed); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  analogWrite(in4, motorSpeed);
}

void pivot_ccw() {
  Serial.println("Pivot CCW");
  digitalWrite(in1, LOW); 
  analogWrite(in2, motorSpeed);
  analogWrite(in3, motorSpeed); 
  digitalWrite(in4, LOW);
}
