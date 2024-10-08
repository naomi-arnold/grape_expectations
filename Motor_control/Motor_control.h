#ifndef _MOTORCONTROL_H
#define _MOTORCONTROL_H

void motor_setup();
void go_forward(int dist);
void go_backwards(int dist);
void go_right(int degrees);
void go_left(int degrees);
void stop_all();
void pivot_cw();
void pivot_ccw();

#endif _MOTORCONTROL_H