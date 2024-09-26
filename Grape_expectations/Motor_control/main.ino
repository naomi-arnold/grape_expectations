#include "Motor_control.h"
#include "state_mach.h"
#include "server_comm.h"

// extern typedef enum States;

void setup() {
  
  // Motor control pins are outputs
  motor_setup();
  setup_server();

}

void loop() {

  String message = get_message();
  // TODO: Parse HERE

  switchState(message);


}