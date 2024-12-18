#include "Motor_control.h"

// Motor A connections
const int in1 = 5;
const int in2 = 6;
 
// Motor B connections
const int in3 = 9;
const int in4 = 10;
 
// Set the speed (0 = off and 255 = max speed)
const int motorSpeed = 58;
volatile int state = 0;

void motor_setup() 
{

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
 

void go_forward() 
{
  analogWrite(in1, motorSpeed);
  digitalWrite(in2, LOW);
  analogWrite(in3, motorSpeed + 1);
  digitalWrite(in4, LOW);
}

void go_backwards() 
{
  digitalWrite(in1, LOW);
  analogWrite(in2, motorSpeed );
  digitalWrite(in3, LOW);
  analogWrite(in4, motorSpeed);
}

void go_right() 
{
  analogWrite(in1, motorSpeed + 5);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void go_left() 
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(in3, motorSpeed + 5);
  digitalWrite(in4, LOW);
}

void stop_all() 
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void pivot_cw() 
{
  analogWrite(in1, motorSpeed + 1); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  analogWrite(in4, motorSpeed + 1);
}

void pivot_ccw() 
{
  digitalWrite(in1, LOW); 
  analogWrite(in2, motorSpeed + 1);
  analogWrite(in3, motorSpeed + 1); 
  digitalWrite(in4, LOW);
}

