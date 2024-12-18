#include "Motor_control.h"
#include "server_comm.h"
#include "color_sensing.h"

bool new_state = true;
volatile int functionIndex = 0;
String desired_lane = "blue";
String desired_lane2 = "yellow";
int message_state;

// Always vcalled at the beginning 
// Setup individual components including motors, color sensor, collision detection, and serial communication
void setup() 
{
  Serial.begin(9600);
  motor_setup();
  setup_server();
  Color_sensing_setup();

}

// Call desired bot navigation function 
void loop()
{
  // bot1();
  // bot2();
}

// Bot 1 naviagtion
// Includes serial communications for joint track navigation
void bot1() {
  while(!detect_collision()) go_forward();

  go_backwards();
  delay(3000);
  // search for red lane
  while(determine_color() != "red") go_backwards();
  stop_all();

  // send red lane found to other team
  send_message("red lane found");

  go_right();
  delay(4200);
  stop_all();
  
  // follow red lane
  while(!detect_collision()) {
    follow_lane("red");
  }

  stop_all();

  go_left();
  delay(4000);
  stop_all();

  while(!handle_message2()) {;} // Wait until other team sends "blue lane found"
  // search for yellow lane 
  while(determine_color() != "yellow") go_forward();
  stop_all();

  go_left();
  delay(2500);
  stop_all();

  // follow yellow lane 
  while(!detect_collision()) {
    follow_lane("yellow");
  }

  stop_all();

  go_left();
  delay(3000);
  stop_all();

  while(!detect_collision()) go_forward();

  stop_all();
  send_message("returned");

}

// Bot 2 navigation
// Includes serial communications for joint track navigation
void bot2() 
{
  while(!handle_message2()) {;} // Wait until other team sends "red lane found"
  delay(4000);
  while(!detect_collision()) go_forward();

  go_backwards();
  delay(3500);
  // search for blue lane
  while(determine_color() != "blue") go_backwards();
  stop_all();
  send_message("blue lane found");

  go_left();
  delay(4000);
  stop_all();
  
  while(!detect_collision()) {
    follow_lane("blue");
  }

  stop_all();

  go_right();
  delay(3500);
  stop_all();

  while(!handle_message2()) {;} // Wait until other team sends "returned"
  while(determine_color() != "yellow") go_forward();
  stop_all();

  go_right();
  delay(2500);
  stop_all();

  while(!detect_collision()) {
    follow_lane("yellow");
  }

  stop_all();

  go_right();
  delay(3000);
  stop_all();

  while(!detect_collision()) go_forward();

  stop_all();
  delay(100000);

}

// Controls bot to follow lane of desired color
// Input: desired lane color to follow
void follow_lane(String desired_lane) {
  go_forward();
  String color = determine_color();
    if (color != desired_lane) {
      pivot_ccw();
      delay(pivotStepDelay);
      color = determine_color();
      if (color != desired_lane) {
          pivot_cw();
          delay(pivotStepDelay * 2);
          color = determine_color();
          if (color != desired_lane) {
            
              pivot_ccw();
              delay(pivotStepDelay * 4);
              color = determine_color();
              if (color != desired_lane) {

                  pivot_cw();
                  delay(pivotStepDelay * 8);
              }
          }
      }
    } else {
      go_forward();
    }
}

// Go-beyond Remote control
void remote_control() {
  int message_state = 0;
    String message = get_message();
    if (message.length() > 0)
    {
        message_state = handleMessage(message);
        if (message_state != -1)
            new_state = true;
            functionIndex = message_state;
    }

    if (new_state) {
        Serial.print("func index ");
        Serial.println(functionIndex);
        new_state = false;
        switch (functionIndex) {
            case 0: stop_all(); break;
            case 1: go_forward(); break;
            case 2: go_backwards(); break;
            case 3: pivot_cw(); break;
            case 4: pivot_ccw(); break;
            case 5: go_right(); break;
            case 6: go_left(); break;
        }
    }
}

// Handle message from partner team
bool handle_message2() 
{
  String message = get_message();
  if (message.length() > 0) {      
      char inputString[message.length() + 1];  
      message.toCharArray(inputString, sizeof(inputString));

      // Search for F392FC86D8D7 in the inputString
      if (strstr(inputString, "F392FC86D8D7") != NULL) {
        if (strstr(inputString, "blue lane found") != NULL) return true;
        if (strstr(inputString, "red lane found") != NULL) return true;
        if (strstr(inputString, "yellow lane found") != NULL) return true;
        if (strstr(inputString, "returned") != NULL) return true;
      }
  }
  return false; 
}

// Handles translating message from client into motor state
// Input: message sent by client
// Output: State to switch motors to based on inputted message
int handleMessage(String message) 
{
  char inputString[message.length() + 1];  
  message.toCharArray(inputString, sizeof(inputString));
  
  // Search for 89C87865077A in the inputString
  if (strstr(inputString, "89C87865077A") != NULL) {
    if (strstr(inputString, "stop") != NULL) {
        return 0;
    } else if (strstr(inputString, "forward") != NULL) {
        return 1; 
    } else if (strstr(inputString, "backward") != NULL) {
        return 2; 
    } else if (strstr(inputString, "ccw") != NULL) {
        return 4; 
    } else if (strstr(inputString, "cw") != NULL) {
        return 3; 
    } else if (strstr(inputString, "right") != NULL) {
        return 5; 
    } else if (strstr(inputString, "left") != NULL) {
        return 6; 
    } else {
      return -1;
    }
  }

}

