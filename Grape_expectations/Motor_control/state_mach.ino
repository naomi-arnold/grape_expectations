#include "state_mach.h"

void switchState(String state, int addt) 
{
  if (state == "STOP") 
    stop_all();
  else if (state == "FORWARD")
    go_forward(addt);
  else if (state == "BACKWARDS") 
    go_backwards(addt);
  else if (state == "PIVOT_CW") 
      pivot_cw(); //pivot cw
  else if (state == "PIVOT_CCW")
      pivot_ccw(); //pivot ccw
  else if (state == "RIGHT") 
      go_right(addt);
  else if (state == "LEFT")
    go_left(addt);

}