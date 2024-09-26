#include "Motor_control.h"
#include "state_mach.h"
#include "server_comm.h"

void setup() {
  Serial.begin(9600);
  // Motor control pins are outputs
  void motor_setup();

  // attachInterrupt(digitalPinToInterrupt(3), switchState, RISING);
}

void loop() {


}