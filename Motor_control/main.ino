#include "Motor_control.h"
#include "state_mach.h"
#include "server_comm.h"
#include "color_sensing.h"

void setup() {
  Serial.begin(9600);
  Serial.println("in setup");
  // Motor control pins are outputs
  motor_setup();
  setup_server();
  Color_sensing sensor = Color_sensing();

  go_backwards(200);

}

void loop() {

  String message = get_message();
  // TODO: Parse HERE
  if (message.length() > 0)
  {
    Serial.println("Message: ");
    Serial.println(message);
  }

  // switchState(message, 0);
  // go_forward(50);
  //stop()

}