#include "state_mach.h"

void switchState(String state) 
{
  if (state == "STOP") 
    stop_all();
  else if (state == "FORWARD")
    go_forward();
  else if (state == "BACKWARDS") 
    go_backwards();
  else if (state == "PIVOT_CW") 
      go_forward(); //pivot cw
  else if (state == "PIVOT_CCW")
      go_forward(); //pivot ccw
  else if (state == "RIGHT") 
      go_right();
  else if (state == "LEFT")
    go_left();

}