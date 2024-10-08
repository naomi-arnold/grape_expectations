// Goal: have three different inputs: blue, red, and yellow voltage drops
// and use these drops to determine what color we are on in course.
// From here, we can determine whether to move forward, backward, sideways, etc

#include "color_sensing.h"

// cutoff values for determining which color is being reflected
#define BLUE_CUTOFF 0.5 
#define RED_CUTOFF 0.5

Color_sensing::Color_sensing() {
    Serial.begin(9600);          // opens serial port, sets data rate to 9600 bps
    pinMode(blue_signal,INPUT);  // initializes blue and red signals to input mode
    pinMode(red_signal,INPUT);
}

// void Color_sensing::color_sensing_setup() {
//     Serial.begin(9600);          // opens serial port, sets data rate to 9600 bps
//     pinMode(blue_signal,INPUT);  // initializes blue and red signals to input mode
//     pinMode(red_signal,INPUT);
// }


void Color_sensing::determine_color() {
    delay(500);
    blue_value = analogRead(blue_signal);  // read blue and red values
    red_value = analogRead(red_signal);

    Serial.println(blue_value);  // print the red and blue values
    Serial.println(red_value);

    delay(500);

  //Conditions for different colors
  if (blue_value < BLUE_CUTOFF && red_value < RED_CUTOFF) { // both blue and red reflection is small = black
    Serial.println("Black");
  }
   else if (blue_value < BLUE_CUTOFF && red_value > RED_CUTOFF) { // red reflection is large = red
    Serial.println("Red");
  }
  else if (blue_value > BLUE_CUTOFF && red_value < RED_CUTOFF) { // blue reflection is large = blue
    Serial.println("Blue");
  } 
   else if (blue_value > BLUE_CUTOFF && red_value > RED_CUTOFF) { // both blue and red reflection is large = yellow
    Serial.println("Yellow");
  } else {
    Serial.println("ERROR");
  }
}