#include "color_sensing.h"
#include "Motor_control.h"

#define color_read_pin A2
#define blue_light_pin 13
#define red_light_pin 12
#define collision_read_pin A4

int pivotStepDelay = 240;

// Set up for color sensor and collision detection
void Color_sensing_setup() {
    Serial.begin(9600);          

    pinMode(color_read_pin, INPUT);

    pinMode(red_light_pin, OUTPUT);
    pinMode(blue_light_pin, OUTPUT);
    digitalWrite(blue_light_pin, LOW);
    digitalWrite(red_light_pin, LOW);

    pinMode(collision_read_pin, INPUT);
}

// Flashes red and blue LEDs, reads from a photoresistor
// Determines color bases on red and blue reflection range
String determine_color() 
{
    digitalWrite(blue_light_pin, HIGH);
    delay(50);
    float blue_value = analogRead(color_read_pin) * (5.0 / 1023.0);
    delay(50);
    digitalWrite(blue_light_pin, LOW);
    delay(50);

    digitalWrite(red_light_pin, HIGH);
    delay(50);
    float red_value = analogRead(color_read_pin) * (5.0 / 1023.0); // need to check AO
    delay(50);
    digitalWrite(red_light_pin, LOW);

    // print the red and blue values for debugging
    Serial.println(blue_value);  
    Serial.println(red_value);

    // Conditions for different colors - check range to determine Red, Blue, Yellow, or Black
    if (blue_value < 0.1 && red_value < 0.2) { // both blue and red reflection is small = black
      Serial.println("black");
      return "black";
    } else if (blue_value <= 0.3 && red_value <= 0.3) { // blue reflection is large = blue
      Serial.println("blue");
      return "blue";
    } else if (blue_value < 0.3 && red_value < 0.8) { // red reflection is large = red
      Serial.println("red");
      return "red";
    } else if (blue_value < 0.6 && red_value < 0.9) { // both blue and red reflection is large = yellow
      Serial.println("yellow");
      return "yellow";
    } else {
      Serial.println("other"); 
      return "other";
    }
}

// Turns IR sesnor and IR Led to detect infared reflection and determine 
// Collision based on value read
bool detect_collision() 
{
    float dist_value = analogRead(collision_read_pin);
    delay(50);

    // Print value for debugging
    Serial.println(dist_value); 

    // check ranges to determine if getting to close 
    // Stop all motors if potential collision
    if (dist_value > 850.0) {
      Serial.println("TOO CLOSE!");
      return true;
      stop_all();
    } else {
      Serial.println("All good!");
      return false;
    }

}

