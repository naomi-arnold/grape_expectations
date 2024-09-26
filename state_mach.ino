#include "state_mach.h"

void switchState(int state) {

  switch (state) {
    case 0: 
      stop_all();
      break;
    case 1: 
      go_forward();
      break;
    case 2: 
      go_backwards();
      break;
    case 3: 
      go_forward(); //pivot cw
      break;
    case 4: 
      go_forward(); //pivot ccw
      break;
    case 5: 
      go_right();
      break;
    case 6: 
      go_left();
      break;
  }

}