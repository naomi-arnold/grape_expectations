#ifndef COLOR_SENSING_H
#define COLOR_SENSING_H

class Color_sensing {
  public:
    Color_sensing();
    // void color_sensing_setup();
    void determine_color();

  private:
    // analog ports where voltage from color reflections is being read from
    int blue_signal = A0;
    int red_signal = A1;

    // values voltages from color reflections
    int blue_value = 0;
    int red_value = 0;
};
#endif