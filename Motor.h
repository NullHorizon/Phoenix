#include "Arduino.h"

#define MAX_POWER 255
#define MIN_POWER 0

class Motor {
  public:
    Motor(int in_1, int in_2, int h_pwr);
    Motor();
    void setup();
    void setPower(int pwr);
    void setDirection(String dir);
  private:
    void updateMotor();
    int pin_H_bridge_input_1;
    int pin_H_bridge_input_2;
    int pin_H_bridge_power;
    int power;
    String direction;
};

