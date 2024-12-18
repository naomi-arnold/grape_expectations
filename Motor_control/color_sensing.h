#ifndef COLOR_SENSING_H
#define COLOR_SENSING_H

void Color_sensing_setup();
String determine_color(); 
void handle_LEDs();
void recoverLane(String desired_lane);
bool detect_collision();

#endif
